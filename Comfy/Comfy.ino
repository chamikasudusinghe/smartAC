#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "DHT.h"

// set firebase database.
#define FIREBASE_HOST "nodemcu-ac-b2937.firebaseio.com"
#define FIREBASE_AUTH "Qb9fBykJCEDANrs6ZESJuva65HVhrluR9eYh2Xia"
#define WIFI_SSID "AIM"
#define WIFI_PASSWORD "chamikaishan55"
#define node "/ac/"

#define DHTPIN 2 //// Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

const uint16_t kIrLed = 4; //D2
IRsend irsend(kIrLed);


void setup() {
  
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  irsend.begin();
  dht.begin();
  delay(200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("connecting");
  while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
  }
  Serial.println("connected: ");
  delay(1000);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("connection established");
  delay(1000);

}

void loop() {

}


float humidity(){
  float h = dht.readHumidity();
  return h;
}

float temperature(){
  float t = dht.readTemperature();
  return t;
}
 

void on(){
    irsend.sendCOOLIX(0xB2BFC8, kCoolixBits, 1);
}

void off(){
    irsend.sendCOOLIX(0xB27BE0, kCoolixBits, 1);
}

void clean(){
    irsend.sendCOOLIX(0xB5F5AA, kCoolixBits, 1);
}

void led(){
    irsend.sendCOOLIX(0xB5F5A5, kCoolixBits, 1);
}

void turbo(){
    irsend.sendCOOLIX(0xB5F5A2, kCoolixBits, 1);
}

void sleep(){
      irsend.sendCOOLIX(0xB2E003, kCoolixBits, 1);
}

void swing(){
      irsend.sendCOOLIX(0xB26BE0, kCoolixBits, 1);
}


void on24(){
    irsend.sendCOOLIX(0xB21F48, kCoolixBits, 1);
}

void on23(){
    irsend.sendCOOLIX(0xB21F58, kCoolixBits, 1);
}

void on22(){
    irsend.sendCOOLIX(0xB21F78, kCoolixBits, 1);
}

void on21(){
    irsend.sendCOOLIX(0xB21F68, kCoolixBits, 1);
}

void on20(){
    irsend.sendCOOLIX(0xB21F28, kCoolixBits, 1);
}

void on19(){
    irsend.sendCOOLIX(0xB21F38, kCoolixBits, 1);
}

void on18(){
    irsend.sendCOOLIX(0xB21F18, kCoolixBits, 1);
}

void on17(){
    irsend.sendCOOLIX(0xB21F08, kCoolixBits, 1);
}

void on24(){
    irsend.sendCOOLIX(0xB21F48, kCoolixBits, 1);
}

void on26(){
    irsend.sendCOOLIX(0xB21FD8, kCoolixBits, 1);
}

void on27(){
    irsend.sendCOOLIX(0xB21F98, kCoolixBits, 1);
}

void on28(){
    irsend.sendCOOLIX(0xB21F88, kCoolixBits, 1);
}

void on29(){
    irsend.sendCOOLIX(0xB21FA8, kCoolixBits, 1);
}

void on30(){
    irsend.sendCOOLIX(0xB21FB8, kCoolixBits, 1);
}
