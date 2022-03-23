#include <Servo.h>
Servo servo;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "trQ85defPbQMO2Rn4Xi1hcHpeGrLt9W3";
char ssid[] = "V2022";
char pass[] = "jenni321";
BLYNK_WRITE(V0) {
   servo.write(param.asInt());
  }
void setup() {
  pinMode(D1,INPUT);
   servo.attach(D2);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  
 int i =digitalRead(D1);
 Serial.println(i);
 Blynk.run();
  if(i==1){
  Blynk.virtualWrite(V1,1);
  }
  else{
    Blynk.virtualWrite(V1,LOW);
    }
}
