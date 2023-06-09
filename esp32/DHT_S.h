#ifndef DHT_S
#define DHT_S
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class SensorDHT
{
  public:
  SensorDHT();
  void Init();
  float leerT();
  float leerH();


  private:
  #define DHTPIN 10//GPIO del ESP32
  #define DHTTYPE DHT11


  
};
#endif;
