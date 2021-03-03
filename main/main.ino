#include <DHT.h>
#include "sensor.h"
#include "pinnum.h"
#include "communication.h"

int cdsValue;
int tem;

extern SoftwareSerial BTSerial;

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  readSensor(&cdsValue, &tem);//&변수의 주소를 반환하는 연산자
  String read = get_data();

  Serial.print("cds value : ");
  Serial.print(cdsValue);
  Serial.print("temperautre : ");
  Serial.print(tem);
  Serial.print("BTread : ");
  Serial.println(read);

  delay(10);
}
