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
  
    if (temp<80 && temp>0)
        return 1;
    else
        return 0;
};

bool battery_sensor::test_supply () {

    float v_sup = voltage_supply(value);

    if (v_sup>10)//4.3 //Batteria troppo scarica per eseguire un monitoraggio oppure dispositivo collegato all'alimentazione //(voltage_supply(pin_v_supply)<3.2) || 
        return 0; //Non esegue il monitoraggio
    else //Batteria sufficentemente carica per il monitoraggio
        return 1; //Esegue il monitoraggio
};
