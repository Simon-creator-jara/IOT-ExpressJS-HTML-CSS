#include "leerserial_S.h"
#include "Arduino.h"
#include "interpretar.h"


  int menu = 0;

  int state = 0;
LEER comandoss;
void INTERPRETAR::Init(){
 
  Serial.println("Leer inicializando... ");
  delay(500);
}




int INTERPRETAR::interp() {
if (Serial.available() > 0){
  if(strlen(comandoss.leer())>=2){
    if(comandoss.leer()[0]=='M'){
    
      menu = atof(comandoss.leer()+1); //Toma valores enteros 
      if(menu == 0){
        state = 1;
 
        Serial.println("Rebooting...");
        delay(1000);
      }else{
        Serial.println("OK " + (String)menu);
      }
    }else if (comandoss.leer()[0] == 'S'){
       menu = atof(comandoss.leer()+1); //Toma valores enteros 
        if(menu == 1){
        state = 3;

        
      }
     
    }      
    
  }}else{
    state=1;
  }
  return state;
}
