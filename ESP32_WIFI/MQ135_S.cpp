#include "MQ135_S.h"
//#include "WiFi.h"

MQ135 mq135_sensor(PIN_MQ135);

void SensorMQ135::Init(){

  Serial.println("MQ135 inicializando... ");
  delay(500);
}

float SensorMQ135::LeerPPM(){
  float PPM = mq135_sensor.getPPM();;
  return PPM;
}
