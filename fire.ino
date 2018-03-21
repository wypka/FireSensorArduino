#include <ArduinoJson.h>
#include "Bluetooth.h"

Bluetooth BTSerial(2,3,9600);
const String id = "hangyunhyun";
const String ack = "n";
const int temperaturePin=  A1; //온도센서가 연결된 핀
const int flamePin = A0; //포토트랜지스터가 연결된 아날로그핀
String jsonData = "";
void setup() {
  pinMode(flamePin,INPUT);    //포토트랜지스터 입력설정
  BTSerial.begin(9600);
  Serial.begin(9600);     //시리얼모니터 설정
}
 
void loop() {
  char flameChk;
  int readingFlame = analogRead(flamePin);  //포토트랜지스터에서 값을 읽어옴.
  int readingTemperature = analogRead(temperaturePin); //온도센서에서 값을 읽어온다.
  int temperatureValue = (5.0 * readingTemperature * 100.0)/1024;
  int flameValue = readingFlame;
          
  
  //Json 객체 만들기
  StaticJsonBuffer<300> fireSensorBuffer;
  JsonObject &fireSensor = fireSensorBuffer.createObject();
  fireSensor["memId"] = id;
  fireSensor["flame"] = flameValue;
  fireSensor["temperature"] = temperatureValue;
  fireSensor["flameAck"] =ack;
  fireSensor.printTo(jsonData);
  Serial.println(jsonData);
  BTSerial.println(jsonData);
  jsonData = "";
  delay(15000);
}


