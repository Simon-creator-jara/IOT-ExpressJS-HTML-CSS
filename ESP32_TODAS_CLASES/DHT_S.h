#ifndef DHT_S
#define DHT_S

#include "DHT.h"



class SensorDHT

{
  public:
  void Init();
  float LeerT();
  float LeerH();


  private:
  #define DHTPIN 2 //GPIO del EPS32
  #define DHTTYPE DHT11
  
}; 

#endif
