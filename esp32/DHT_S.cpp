#include "DHT_S.h"
#include "Arduino.h"

DHT dht(DHTPIN, DHTTYPE);


void SensorDHT::Init(){
  dht.begin();
  Serial.println("DHT Inicializado...");
  delay(500);
}
float SensorDHT::leerT(){
  float t= dht.readTemperature();
  return t;
}
float SensorDHT::leerH(){
  float h= dht.readHumidity();
  return h;
}
