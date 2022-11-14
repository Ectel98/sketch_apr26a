#include "my_leds.h"
#include "Arduino.h"


void led::led_blink() {  //Pin relativo al led, tempo on, tempo off, numero di lampeggi
    
    if(numb>=0) {
        if(millis()-time2>time_off) {
            digitalWrite(led_pin,LOW);
            if(millis()-time2>(time_on + time_off)) {
               digitalWrite(led_pin,HIGH);
               time2 = millis();
               numb--;
            }
        }
    }
    
};

void led::set_led(char pin,int t_on,int t_off,int n) {

    led_pin = pin;
    time_on = t_on;
    time_off = t_off;
    numb = n; 

}

void led::setup_led(char pin) {
    
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
    time2 = millis();
    this->set_led(pin,0,0,0);

};

void led::set_led(int t_on,int t_off,int n) {

    time_on = t_on;
    time_off = t_off;
    numb = n; 

}

void led::led_updates() {

    led_blink();

}
