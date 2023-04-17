#include "my_ble.h"
#include "Arduino.h"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool status_connection = false;
bool message_recived = false;
String recived_value = "";

class MyServerCallbacks: public BLEServerCallbacks {

    void onConnect(BLEServer* pServer) {
      status_connection = true;
    };

    void onDisconnect(BLEServer* pServer) {
      status_connection = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {

      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        for (int i = 0; i < rxValue.length(); i++) {
          recived_value+=rxValue[i];
        }
        Serial.print("Ricevuto: ");
        Serial.println(recived_value);
        message_recived = true;
      }
    }
};

void setup_ble() {
    BLEDevice::init("UART Service");
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());
    BLEService *pService = pServer->createService(SERVICE_UUID);
    pTxCharacteristic = pService->createCharacteristic( CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
									);
                     
    pTxCharacteristic->addDescriptor(new BLE2902());
    BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
											 CHARACTERISTIC_UUID_RX,
											BLECharacteristic::PROPERTY_WRITE
										);

    pRxCharacteristic->setCallbacks(new MyCallbacks());
    pService->start();
    pServer->getAdvertising()->start();
}


void start_advertising() {
  pServer->startAdvertising(); 
}

void stop_advertising() {
  pServer->getAdvertising()->stop(); 
}


void send_message_to_app(String message) {
  
    int n = message.length();
    char value[n];
    
    message.toCharArray(value, n+1); 

    Serial.print("Inviato: ");
    Serial.println(value);
    
    pTxCharacteristic->setValue(value);
    pTxCharacteristic->notify();
}

void start_ble() {
  btStart();
}
void stop_ble() {
  btStop();
}
