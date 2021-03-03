#include <DHT.h>
#include "sensor.h"
#include "pinnum.h"
#include "communication.h"

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

int cdsValue;
int tem;

void setup() {
  BTSerial.begin(9600);
}

void loop() {
  readSensor(&cdsValue, &tem);//&변수의 주소를 반환하는 연산자
}
