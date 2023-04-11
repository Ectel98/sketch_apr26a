#pragma once

#include "Arduino.h"
#include "sdkconfig.h"


#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UUID da cambiare
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

extern bool status_connection;
extern bool message_recived;
extern String recived_value;

void setup_ble();

void start_advertising();

void stop_advertising();

void send_message_to_app(String);

void stop_ble();

void start_ble();
