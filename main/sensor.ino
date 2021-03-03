#include "sensor.h"
#include "pinnum.h"
#include <DHT.h>
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE); //객체생성

void readSensor(int * cds, int * temp)
{
  * cds = analogRead(CDS); 
  * temp = dht.readTemperature(); 
}

bool Check_condition(int temp, int temp_th, bool tempMorethan, int cds, int cds_th, bool cdsMorethan, bool And)
{
  bool temp_condition;
  bool cds_condition;
  
  if(tempMorethan)
  {
    temp_condition = temp >= temp_th;
  }
  else
  {
    temp_condition = temp <= temp_th;
  }

  if(cdsMorethan)
  {
    cds_condition = cds >= cds_th;
  }
  else
  {
    cds_condition = cds <= cds_th;
  }
  
  if(And)
  {
    return temp_condition && cds_condition;
  }
  else
  {
    return temp_condition || cds_condition;
  }
}
