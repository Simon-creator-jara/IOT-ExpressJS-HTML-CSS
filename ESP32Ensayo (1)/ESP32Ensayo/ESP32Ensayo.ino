#include "DHT_S.h"


char buff[100];
int i = 0;
int flagP = 0;
int state = 0;
enum state_1{
  inicio = 0, idle1, settings, process 
};

float menu;


SensorDHT sensor; //Se crea objeto de clase SensorDHT

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  //Condiciones iniciales para máquina de estados
  flagP = 1;
  state = inicio;
  delay(3000);
  sensor.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  leerSerial();
  maquinaestados(state);
  delay(100);
  //Serial.println(".");
 

}

void leerSerial() {
  while (Serial.available() > 0) { //Mientras haya serial disponible
    char c = Serial.read(); //Caracteres que llegan
    if (c == '\n') {
      buff[i] = '\0';
      interpretar();
      i = 0;

    } else {
      buff[i] = c;
      i++;
    }
  }

}

void interpretar() {

  if(strlen(buff)>=2){
    if(buff[0]=='M'){
    
      menu = atof(buff+1); //Toma valores enteros 
      if(menu == 0){
        state = inicio;
        flagP = 1;
        Serial.println("Rebooting...");
        delay(1000);
      }else{
        Serial.println("OK " + (String)menu);
      }
    }else if (buff[0] == 'S'){
       menu = atof(buff+1); //Toma valores enteros 
        if(menu == 1){
        state = process;
        flagP = 1;
        
      }
     
    }      
    
  }
  /*
  switch (buff[0]) {
    case 'A':
      Serial.println("CASO A");

      break;
    case 'B':
      Serial.println("CASO B");

      break;
    case 'C':
      Serial.println("CASO C");

      break;

  }
  */
}

void maquinaestados(int estado){
  if(estado == inicio){
    if (flagP == 1){
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(4,LOW);
      delay(200);
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(4,LOW);
      delay(200);
      
      Serial.println("JARVIS...");
      Serial.println("Booting...");
      delay(1000);// Realizar configuración de parámetros iniciales(Conectarse a Wi-Fi, leer datos de EEPROM)
      Serial.println("Init complete... ");

      state = idle1;
      //flagP = 1;
    }
    
  }else if(estado == idle1)
    
    if (flagP == 1){
      Serial.println("Waiting...");

      leerSerial();
      //flagP = 1;
        
  }else if(estado == settings){
   
    if (flagP == 1){


      //flagP = 1;
    }
  }else if(estado == process){
    if (flagP == 1){
      Serial.println("% Humedad: " + (String)sensor.LeerH());
      Serial.println("% Temp: " + (String)sensor.LeerT());

      estado = idle1;

      flagP = 1;
    }
  }
}
