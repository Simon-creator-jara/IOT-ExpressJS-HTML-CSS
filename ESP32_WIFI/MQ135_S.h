#ifndef MQ135_S
#define MQ135_S

#include <MQ135.h>



class SensorMQ135

{
  public:
  void Init();
  float LeerPPM();



  private:
  #define PIN_MQ135 0 //GPIO del EPS32
  
  
}; 

#endif
