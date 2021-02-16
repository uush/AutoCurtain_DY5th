#include <DHT.h>
#include "sensor.h"
#define CDS A0
#define DHTPIN 9
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

int cdsValue;
int tem;

void setup() {
  
}

void loop() {
  readSensor(&cdsValue, &tem);//&변수의 주소를 반환하는 연산자

  if(Check_condition(tem, temp_th, ))//앱 인벤터가 필요
}
