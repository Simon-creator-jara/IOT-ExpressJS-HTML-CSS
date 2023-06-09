#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT_S.h"
#include "MQ135_S.h"
SensorDHT sensor;
SensorMQ135 sensor_2;
const char* ssid = "Simon"; // * significa un puntero, es un espacio
// de memoria donde se guarda la direccion
const char* password = "simon1999*";

String Server = "http://192.168.20.24:3000";

int temp = 0;
int hum = 0;
int cal=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Conectando..");
  sensor.Init();
  sensor_2.Init();
  //Mientras conecta al WiFi
  while (WiFi.status() != WL_CONNECTED) { //Mientras el estado no sea Conectado
    delay(500);
    Serial.println(".");
  }
  Serial.println("Conectado");
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  //Get("/sens1");
  cal++;
  
  DATA(cal,sensor.LeerT(),sensor.LeerH());

  delay(500);
}

void Get(String PathIn) {
  String Path = Server + PathIn ;
  Serial.print("Server: ");
  Serial.println(Path);
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    //String Path = Server + PathIn ;
   // Serial.print("Server: ");
   // Serial.println(Path);
    http.begin(Path.c_str()); //Iniciamos conexion con el servidor
    int ResCode = http.GET(); //Guardo el codigo de respuesta de la peticion
    if (ResCode > 0) {
      Serial.print("Codigo de respuesta: ");
      Serial.println(ResCode);
      String payload = http.getString(); //Guardo el payload (lo que me interesa)
      Serial.print("Payload: ");
      Serial.println(payload);
    } else {
      Serial.println("Error");
    }
    http.end(); //Terminamos la conexion con el servidor
  } else {

  }
}

void Post(String PathIn, String DATA) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String Path = Server + PathIn ;
    http.begin(Path.c_str()); //Iniciamos conexion con el servidor
    http.addHeader("Content-Type", "application/json");
    int ResCode = http.POST(DATA); //Guardo el codigo de respuesta de la peticion
    if (ResCode > 0) {
      Serial.print("Codigo de respuesta: ");
      Serial.println(ResCode);
      String payload = http.getString(); //Guardo el payload (lo que me interesa)
      Serial.print("Respuesta: ");
      Serial.println(payload);
    } else {
      Serial.println("Error");
    }
    http.end(); //Terminamos la conexion con el servidor
  } else {

  }
}


void DATA(float Calidad, float temp1, float Hum1){
  String json = "{\"temp1\":\"" + (String)temp1 + "C\",\"Hum1\":\"" + (String)Hum1 + "%\",\"Calidad\":\"" + (String)Calidad +"PPM\"}";
  Serial.print("PayLoad: ");
  Serial.println(json);
  Post("/data",json);
}
