#include "leerserial_S.h"
#include "Arduino.h"

  char buff[100];
  int i = 0;

  int estado = 0;


void LEER::Init(){
 
  Serial.println("Leer inicializando... ");
  delay(500);
}

char* LEER::leer() {

  while (Serial.available() > 0) { //Mientras haya serial disponible
    char c = Serial.read(); //Caracteres que llegan
    if (c == '\n') {
      buff[i] = '\0';


      i = 0;

    } else {
      buff[i] = c;
      i++;
    }
  }
  
    
   return buff; 
}
