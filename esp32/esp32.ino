#include "DHT_S.h";

char buff[100];
int i=0;
int flagP=0;
int state=0;
float menu;
enum state_1{
  inicio=0, idle2, settings, process
};

//Creamos objeto de mi clase SensorDHT
SensorDHT sensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  flagP=1;
  state=inicio;
  delay(3000);
  sensor.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //leerserial();
  maquinaestados(state);
  delay(500);
}

void leerserial(){

  while (Serial.available()>0){
    char c=Serial.read();
    if (c == '\n'){
      buff[i]='\0';
      interpretar();
      i=0;
    }
    else{
      buff[i]=c;
      i++;
    }
  }
}
void interpretar(){
  if (strlen(buff)>=2){
    if(buff[0]=='M'){

      //Serial.println("Caso A");
       menu = atof(buff + 1);
       if (menu==0){
        state=inicio;
        flagP=1;
        Serial.println("Rebooting...");
        delay(1000);
        
       }else{
        Serial.println("OK" + (String)menu);
        
       }
      
  }else if (buff[0]=='S'){
    menu = atof(buff + 1);
    if (menu==1){
      state=process;
      flagP=1;
    }
    
  }

  }
}

void maquinaestados(int estado){
  if (estado == inicio ){
    if(flagP==1){
      
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(4,LOW);
      delay(200); 
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(4,LOW);
      delay(200);  
      Serial.println("JARVIS..");
      Serial.println("Booting...");
      delay(1000);//Realiza config parametros iniciales.
      Serial.println("Init complete..");

      state=idle2;
      //flagP=1;
    }
  }else if(estado== idle2){
        if(flagP==1){
          Serial.println("Waiting....");
          leerserial();
      //flagP=0;
    }
  }else if(estado== settings){
        if(flagP==1){

      flagP=0;
    }
  }else if(estado== process){
        if(flagP==1){
      Serial.println("% Humedad:"+(String)sensor.leerH());
      Serial.println("Tempd:"+(String)sensor.leerT());
      estado= idle2;
      flagP=0;
    }
  }
  
}
