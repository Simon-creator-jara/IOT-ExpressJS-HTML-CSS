#include "leerserial_S.h"
#include "Arduino.h"

  char buff[100];
  int i = 0;
  int menu = 0;
  int estado = 0;
  int state = 0;
  float hum1;
  float temp1;

void simonCareChimba::Init(){
 
  Serial.println("Leer inicializando... ");
  delay(500);
}

int simonCareChimba::leer() {
  if (Serial.available() > 0){
  while (Serial.available() > 0) { //Mientras haya serial disponible
    char c = Serial.read(); //Caracteres que llegan
    if (c == '\n') {
      buff[i] = '\0';
      estado=interpretar();

      i = 0;

    } else {
      buff[i] = c;
      i++;
    }
  }
  }else{
    estado=1;
  }
    
   return estado; 
}


int simonCareChimba::interpretar() {

  if(strlen(buff)>=2){

   if (buff[0] == 'H'){

        temp1= atof(buff+1);
        state=1;
        
     
     
    }else if(buff[0]=='T'){
      hum1=atof(buff+1);  
      state=1;          
    }
    
  }
  return state;
}
