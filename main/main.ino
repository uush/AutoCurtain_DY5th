#include <DHT.h>
#include "sensor.h"
#include "pinnum.h"
#include "communication.h"

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
extern SoftwareSerial BTSerial;

boolean Auto_mode = false;

int cdsValue;
int temp;
int temp_th;
int cds_th;
bool tempMorethan;
bool cdsMorethan;
bool And;


void setup() 
{
  BTSerial.begin(9600);
  dht.begin(9600);
}

void loop() 
{
  setting_data();
  readSensor(&cdsValue, &temp);
  if(Auto_mode)
  {
    //자동모드
    boolean open_condition = Check_condition(temp, temp_th, tempMorethan, cdsValue, cds_th, cdsMorethan, And);
    if(open_condition)
    {
      //커튼 연다.
    }
    else
    {
      //커튼을 닫는다.
    }
  }
  else
  {
    //수동모드
  }
}

