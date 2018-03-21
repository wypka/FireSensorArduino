#include <Arduino.h>
#include "Bluetooth.h"

Bluetooth::Bluetooth(int rx, int tx, long boardrate) : SoftwareSerial(rx, tx){
  begin(boardrate);
}

String Bluetooth::readLine(){
  String message= "";
  while(available() ){
    char data = (char)read();
    if(data == '\n') break;

    message += data;

    delay(5);
  }
  return message;
}

