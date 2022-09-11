#include "my_ble.h"
#include "fir_filter.h"
#include "EEPROM.h"
#include "esp_timer.h"
#include "my_leds.h"
#include "battery_control.h"

#include <math.h>

#define pin_ecg_signal 36
#define pin_temp_battery 14
#define pin_lead_p 35
#define pin_lead_n 34
#define pin_enable_ecg_sensor 32


int peak_detecntion(double);
int rr_extraction();
void message_ble();
void monitoring();
void real_time();
void testing();
void end_monitoring();

void setup_battery_sensors();
void setup_leds();

void battery_sensors_updates();
void leds_updates();

double ecg_signal = 0;
int errors_in_extraction = 0;

bool sensor_flag = false;
bool first_time = true;
bool start_timer_flag = false; //Serve ad avviare il timer una volta sola se sono disconnesso

String state_monitoring = "ended";
String state_real_time = "ended";

void IRAM_ATTR Timer() { //Campionamento
  ecg_signal=analogRead(pin_ecg_signal);
  sensor_flag = true;
}


void IRAM_ATTR Timer2() { //Campionamento
  start_adversiting();
}


esp_timer_handle_t timer;
esp_timer_handle_t timer2; //Inizilizzazione timer

const esp_timer_create_args_t timerParameters = { .callback = reinterpret_cast<esp_timer_cb_t>(&Timer) };
const esp_timer_create_args_t timerParameters2 = { .callback = reinterpret_cast<esp_timer_cb_t>(&Timer2) }; 

led led_ble;
led led_error;
led led_state;

battery_sensor temp_sensor;
battery_sensor supply_sensor;

void setup() {

  pinMode(pin_ecg_signal,INPUT);                //Definizione dei pin
  pinMode(pin_temp_battery,INPUT);
  pinMode(pin_lead_p,INPUT);
  pinMode(pin_lead_n,INPUT);  
  pinMode(pin_enable_ecg_sensor,OUTPUT);

  esp_timer_create(&timerParameters, &timer);   //Creazione timer 
  esp_timer_create(&timerParameters2, &timer2);
  
  setup_leds();
  setup_ble();
  setup_battery_sensors();
  
  Serial.begin(115200);

  digitalWrite(pin_enable_ecg_sensor,LOW);    //Spengo il sensore dell'ecg

}


void loop() {

  leds_updates();
  battery_sensors_updates();


  if (status_connection) {         //se sono connesso al telefono
    esp_timer_stop(timer2);        //spengo il timer del ble
    start_timer_flag = false;
  }
  else {
    led_ble.set_led(500,500,1);
    state_monitoring == "ended";
    end_monitoring();
  }
  
  if (start_timer_flag == false && !status_connection) {              //se sono disconesso e il timer del ble è spento
      esp_timer_start_periodic(timer2, 1000000);     // accendo il tiemr del ble
      start_timer_flag = true;
  }


  

  if (message_recived) {         //Se ho ricevuto un messaggio
    led_state.set_led(500,500,1);
    message_ble();               
    recived_value = "";
    message_recived = false;
  }
  
 
  if (state_monitoring=="started") {
    if (control()) {
      if (first_time) {                             //Se non ho ancora avviato il timer
        esp_timer_start_periodic(timer, 2000);      //Avvio timer
        first_time = false;
      }
      if (sensor_flag) {                           //Se ho campionato dal sensore ecg e se non ci sono errori    
        monitoring();                                        
        sensor_flag = false;
      }
    }
  }


  if (state_real_time=="started") {
    digitalWrite(pin_enable_ecg_sensor,HIGH);   //Accendo il sensore ecg
    esp_timer_start_periodic(timer, 5000);      //Avvio timer
    if (sensor_flag) {
      real_time();
      sensor_flag = false;
    }
  }

}

void end_monitoring() {
    digitalWrite(pin_enable_ecg_sensor,LOW);   //Spengo il sensore ecg
    esp_timer_stop(timer);                     //Spengo il timer 
}

bool control() {
  
  //!digitalRead(pin_lead_n) && !digitalRead(pin_lead_p) &&
  if (temp_sensor.temperature() && supply_sensor.test_supply()) { // Se gli elettrodi sono collegati, la temepratura e la carica della batteria sono adeguate 
      return 1;
  }
  
  
  else if (digitalRead(pin_lead_n) || digitalRead(pin_lead_p)) {
      led_error.set_led(1000,200,10);
      send_message_to_app("Error: ld"); 
  }
  
  
  else if (!temp_sensor.temperature()) {
      led_error.set_led(300,300,20);
      send_message_to_app("Error: temp");
  }
  
  else if (!supply_sensor.test_supply()) {
      led_error.set_led(500,100,10);
      send_message_to_app("Error: sup");
  }

  end_monitoring();
  state_monitoring=="ended";
  return 0;

  
}

int rr_extraction() {

  double high_pass_result;
  double low_pass_result;
  double derivetion_result;     
  double squaring_result;       
  double mowing_windows_result; 

  static double der_vector[4];
  static int derivetion_counter = 0;

  high_pass_result = high_pass_filter(ecg_signal);  // Filtraggio passa altro del segnale

  low_pass_result = low_pass_filter(high_pass_result);    // Filtraggio passa basso del segnale

  if (derivetion_counter<4) {
    der_vector[derivetion_counter] = low_pass_result;
    derivetion_counter++;
    return -1;
  }

  derivetion_result = (low_pass_result-der_vector[0])/5;

  for(int e = 0;e<3;e++)                                                 
    der_vector[e]=der_vector[e+1];                                     
  der_vector[3]=derivetion_result;  

  squaring_result = sq(low_pass_result);       // Squadratura del segnale  

  mowing_windows_result = mowing_windows_average_filter(squaring_result); // Filtro a media mobile
 
  return peak_detection(mowing_windows_result);
  
}

int peak_detection(double mowing_windows_result) {

  static double noise_level = 0;   //livello del rumore
  static double signal_level = 0;  //livello del segnale
  static int soglia_counter = 0;   //2000 campioni -> 4s
  static double thresholds = 0;    //soglia

  
  static byte peak_counter=0;
  static double peak_vector[2]={0};
  static byte counter_p = 0;

  int time_pico_result = 0;
  static unsigned long int last_time_pico_result = 0;
  int time_rr_result = 0;

  static bool flag_ts = 0;
  static double max_valuet = 0;
  static unsigned long int max_times = 0;

    //-----------------------rilevazione picchi--------------------------

  if (soglia_counter < 2000) { //Ignoro i primi 2000 valori ricevuti in quanto i vettori che fanno da "storico" ai filtri non sono ancora atati inizializzati
    soglia_counter++;
    return -1;
  }

  if (soglia_counter >= 2000 && soglia_counter < 4000) { //1000 campioni in 2s   // Inizializzo livelli di rumore, segnaale e soglia
    noise_level = noise_level + (double)mowing_windows_result/2000;              //
    signal_level = max(signal_level,(double)mowing_windows_result*0.875);        //
    soglia_counter++;                                                            //
    return -1;                                                                   //
  }                                                                              //
                                                                                 //
                                                                                 //
                                                                                 //
  thresholds = noise_level + (double)0.25*(signal_level-noise_level);            //


  if (peak_counter<3){                                                   // Inizializzo il vettore peak_vector e lo shifto
    peak_vector[peak_counter] = mowing_windows_result;                   //
    peak_counter++;                                                      //
    return -1;                                                           //
  }                                                                      //
                                                                         //
                                                                         //
  for(int e = 0;e<2;e++)                                                 //
    peak_vector[e]=peak_vector[e+1];                                     //
  peak_vector[2]=mowing_windows_result;                                  //


  if ( round(peak_vector[1]*100)/100>round(peak_vector[2]*100)/100 && round(peak_vector[1]*100)/100>round(peak_vector[0])*100/100) {  // Rileva i picchi
    
    if (round(peak_vector[1])>thresholds) {                                                                                           // Pichi maggiori della soglia 
      
      max_valuet = max(peak_vector[1],max_valuet);                                                                                    // Cerca e il picco con ampiezza maggiore, salva questa e il momento in cui è stato rilevato
      if (max_valuet==peak_vector[1])
        max_times = millis();         
        
      signal_level = 0.125*max_valuet+0.875*signal_level;

      flag_ts = 1;
      
    }
    
    else                                                                                                                              // Quando rilevo un pico sotto la soglia
      noise_level = 0.125*peak_vector[1]+0.875*noise_level;
  }

  if (round(peak_vector[1])<=thresholds) {                                                                                            // Qunado il segnale scende sotto la soglia            
    
    if (flag_ts == 1) {                                                                                                               // Appena scende sotto la soglia

      //signal_level = 0.125*max_valuet+0.875*signal_level;
      
      time_pico_result = max_times;  
        
      max_valuet = 0;
      max_times = 0;

      time_rr_result = time_pico_result - last_time_pico_result;                                                                       // Calcolare l'intervallo R-R
      last_time_pico_result = time_pico_result;

      flag_ts = 0;

    }
  }
  
  if (time_rr_result > 1500 || time_rr_result<300) {
    return -1;
    errors_in_extraction++;
  }
  else 
    return time_rr_result;

}

void monitoring() {

  int rr_intervall;

  rr_intervall = rr_extraction();

  if (rr_intervall>0) {
    send_message_to_app(String(rr_intervall)); //valurare se inviare ad ogni messaggio o no
  }
 
}

void real_time() {

  double high_pass_result;
  double low_pass_result;

  high_pass_result = high_pass_filter(ecg_signal);

  low_pass_result = low_pass_filter(high_pass_result);

  send_message_to_app(String(low_pass_result));
  
}

void message_ble() { //Gestisce i messaggi ricevuti dall'App
  
  if (recived_value == "start_monitoring") {
    digitalWrite(pin_enable_ecg_sensor,HIGH);   //Accendo il sensore ecg
    if (control()) {
      state_monitoring="started";
      send_message_to_app("started");
    }
    //led
  }

  else if (recived_value == "end_monitoring") {
    state_monitoring="ended";
    end_monitoring();
    first_time = true;
    send_message_to_app("ended");
    //led
  }

  else if (recived_value == "stato") {
    send_message_to_app(state_monitoring);
  }

  else if (recived_value == "real_time_start") {
    state_real_time="started";
    send_message_to_app(state_real_time);
    //led
  }

  else if (recived_value == "real_time_end") {
    state_monitoring="ended";
    esp_timer_stop(timer);
    send_message_to_app(state_real_time);
    //led
  }
  
}


void leds_updates() {
    led_ble.led_updates();
    led_error.led_updates();
    led_state.led_updates();
}

void battery_sensors_updates() {
    temp_sensor.updates();
    supply_sensor.updates();
}

void setup_leds() {
    led_ble.setup_led(pin_led_ble);
    led_error.setup_led(pin_led_error);
    led_state.setup_led(pin_led_state);
}

void setup_battery_sensors() {
    temp_sensor.set_pin(pin_temp);
    supply_sensor.set_pin(pin_v_supply);
}
