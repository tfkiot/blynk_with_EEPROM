#define BLYNK_TEMPLATE_ID "TMPLKZgGEGjx"
#define BLYNK_DEVICE_NAME "EEpRom"
#define BLYNK_AUTH_TOKEN "EBKxv4hfzKaK9HA6Ia-W6YiVRcRLJxqG"

#define BLYNK_PRINT Serial

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define led1 D2
#define led2 D6

int load1, load2;

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "HaveFun";
char pass[] = "";

void setup()
{
  EEPROM.begin(512);
  Serial.begin(115200);
  
  load1 = EEPROM.read(1);
  load2 = EEPROM.read(2);
  
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  updateLed();
  
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
}

  BLYNK_WRITE(V0){
  load1 = param.asInt();
  updateLed();
  }

  BLYNK_WRITE(V1){
  load2 = param.asInt();
  updateLed();
  }
  
void updateLed(){
digitalWrite(led1, load1);
digitalWrite(led2, load2);
updateEEPROM();
}

void updateEEPROM(){
  EEPROM.put(1, load1);
  EEPROM.put(2, load2);
  EEPROM.commit(); 
}
