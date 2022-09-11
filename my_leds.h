#pragma once

#include "Arduino.h"

#define pin_led_error 25
#define pin_led_ble 26
#define pin_led_state 27


void setup_leds();
void leds_updates();

class led {

    public:

        void set_led(char,int,int,int);
        void set_led(int,int,int);
        void led_updates();
        void setup_led(char);

    private:
    
        unsigned long time2;
        int counter;
        
        char led_pin;
        int time_on;
        int time_off;
        int numb;              //Numero di lampeggi

        void led_blink();

};
