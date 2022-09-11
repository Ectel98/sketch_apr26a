#pragma once

#include "Arduino.h"

#define pin_temp 14
#define pin_v_supply 33  

#define battery_temp(pin) 25  // ((float)1/(float)((float)log((float)((float)(5-(((float)a_pin/(float)1023)*5))/(float)((((float)a_pin/(float)1023)*5)/100000))/(float)10000)/(float)3977 + (float)1/(float)298))-273
#define voltage_supply(value) ((float)((float)(value)/4096)*3.3*2.2)


class battery_sensor {
  
  public:

    void set_pin(char);
    void updates();
    bool temperature();
    bool test_supply();
    int value;
    
  private:
  
    char pin; 
    unsigned long time3;
    int average;
    char count;
  
};
