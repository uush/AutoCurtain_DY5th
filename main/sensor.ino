#include "sensor.h"
#include "pinnum.h"
#include <DHT.h>
#define DHTTYPE DHT11


void readSensor(int * cds, int * temp)
{
  * cds = analogRead(CDS); 
  * temp = dht.readTemperature(); 
}

bool Check_condition(int temp, int temp_th, bool tempMorethan, int cds, int cds_th, bool cdsMorethan, bool And)
//temp : 현재 온도, temp_th : 기준값, tempMorethan : 이상, 이하 , cds : 현재 광량, And : 광량 조건과 온도 조건이 And냐 or
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
