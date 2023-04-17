#include "battery_control.h"
#include "Arduino.h"

void battery_sensor::set_pin(char pin_v) {
  pin = pin_v;
  value = analogRead(pin);
  time3=millis();
};

void battery_sensor::updates() {
  
  if (count >=10) {
    value = (float)average/count;
    count = 0;
    average = 0;
  }
  
  if (millis()-time3>1000) {
    average += analogRead(pin);
    time3 = millis();
    count++;
  }
  
};


bool battery_sensor::temperature() {

    float temp = battery_temp(value);

    //Serial.print("Temp:");
    //Serial.println(temp);
  
    if (temp<60 && temp>0) 
        return 1;
    else                    //La temperatura è fuori dal range oppure il dispositivo è alimentato dalla micro-usb
        return 0;
};

bool battery_sensor::test_supply () {

    float v_sup = voltage_supply(value);

    //Serial.print("Voltg:");
    //Serial.println(v_sup);

    if (v_sup<3.2)//                //Batteria troppo scarica per eseguire un monitoraggio
        return 0;                   //Non esegue il monitoraggio
    else                            //Batteria sufficentemente carica per il monitoraggio
        return 1;                   //Esegue il monitoraggio
};
