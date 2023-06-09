#include "DHT_S.h"
#include "Arduino.h"

DHT dht(DHTPIN, DHTTYPE);

void SensorDHT::Init(){
  dht.begin();
  Serial.println("DHT inicializando... ");
  delay(500);
}

float LeerT(){
  float t = dht.readTemperature();
  return t;
}

float LeerH(){
  float h = dht.readHumidity();
  return h;
}
