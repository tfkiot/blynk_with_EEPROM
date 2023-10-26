#define BLYNK_TEMPLATE_ID "TMPLKZgGEGjx"
#define BLYNK_DEVICE_NAME "EEpRom"
#define BLYNK_AUTH_TOKEN "Your AUTH token"

#define BLYNK_PRINT Serial

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define led1 D1
#define led2 D2
#define led3 D3
#define led4 D4
#define led5 D5
#define led6 D6
#define led7 D7
#define led8 D8

int load1, load1;
int load2, load2;
int load3, load3;
int load4, load4;
int load5, load5;
int load6, load6;
int load7, load7;
int load8, load8;

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "HaveFun";
char pass[] = "";

void setup()
{
  EEPROM.begin(512);
  Serial.begin(115200);
  
  load1 = EEPROM.read(1);
  load2 = EEPROM.read(2);
  load3 = EEPROM.read(3);
  load4 = EEPROM.read(4);
  load5 = EEPROM.read(5);
  load6 = EEPROM.read(6);
  load7 = EEPROM.read(7);
  load8 = EEPROM.read(8);
  
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);




  updateLed();
  
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
}

  BLYNK_WRITE(V1){
  load1 = param.asInt();
  updateLed();
  }

  BLYNK_WRITE(V2){
  load2 = param.asInt();
  updateLed();
  }
BLYNK_WRITE(V3){
  load3 = param.asInt();
  updateLed();
  }

  BLYNK_WRITE(V4){
  load4 = param.asInt();
  updateLed();
  }
BLYNK_WRITE(V5){
  load5 = param.asInt();
  updateLed();
  }

  BLYNK_WRITE(V6){
  load6 = param.asInt();
  updateLed();
  }
BLYNK_WRITE(V7){
  load7 = param.asInt();
  updateLed();
  }

  BLYNK_WRITE(V8){
  load8 = param.asInt();
  updateLed();
  }


void updateLed(){
digitalWrite(led1, load1);
digitalWrite(led2, load2);
digitalWrite(led3, load3);
digitalWrite(led4, load4);  
digitalWrite(led5, load5);
digitalWrite(led6, load6);
digitalWrite(led7, load7);
digitalWrite(led8, load8);  
updateEEPROM();
}

void updateEEPROM(){
  EEPROM.put(1, load1);
  EEPROM.put(2, load2);
  EEPROM.put(3, load3);
  EEPROM.put(4, load4);
  EEPROM.put(5, load5);
  EEPROM.put(6, load6);
  EEPROM.put(7, load7);
  EEPROM.put(8, load8);
  EEPROM.commit(); 
}
