#include "maquinaestados.h"
#include "Arduino.h"
#include "DHT_S.h"
#include "leerserial_S.h"
#include "interpretar.h"
enum state_1{
 inicio = 0, idle1, settings, process 
};
int estadoss=1;
SensorDHT sensor_1;
LEER comandos;
INTERPRETAR entender;
void Maquina::Init(){
 
  Serial.println("Leer inicializando... ");
  delay(500);
}

int Maquina::estados() {

  if(estadoss == inicio){

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

      estadoss = idle1;
      //flagP = 1;
 
    
  }else if(estadoss == idle1){
    Serial.println("YA");
    estadoss =entender.interp();

  }else if(estadoss == process){

      Serial.println("% Humedad: " + (String)sensor_1.LeerH());
      Serial.println("% Temp: " + (String)sensor_1.LeerT());
      Serial.println("Lectura");
      estadoss = idle1;


  }

}

  
