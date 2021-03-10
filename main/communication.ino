#include "communication.h"
#include "pinnum.h"
#include "sensor.h"

SoftwareSerial BTSerial(TX_PIN, RX_PIN);
extern boolean Auto_mode;
extern int temp_th;
extern int cds_th;
extern bool tempMorethan;
extern bool cdsMorethan;
extern bool And;


String get_data()
{
    String result = ""; //return할 명령 문자열
    while(BTSerial.available())
    {
        char read_data = BTSerial.read();
        if(read_data == 'Z') //엔드코드 'Z'일 경우 *이슈
            return result;  // 지금까지 저장한 문자열 반환(명령문자열 완성)
        else                // 엔드코드 'Z'가 아닌 경우
            result = result + read_data;    // 읽어 온 문자를 문자열 뒤에 붙인다.
        
    }  
}


void setting_data()
{
    while (BTSerial.available())
    {
        String ctrl_str = get_data();
        if(ctrl_str.length()>1)
        {
            char start_code = ctrl_str[0];   //명령 문자열 중 앞에 두 자리를 start code로 분류
            int value = ctrl_str.substring(1).toInt();  //나머지 값은 value로 저장
            switch (start_code) 
            {
                case 'A' :
                    Auto_mode = (boolean)value;
                    break;

                case 'L' :
                    cds_th = value;
                    break;

                case 'T' :
                    temp_th = value;
                    break;

                case 'O' :
                    And = (boolean)value;
                    break;

                case 'U' :
                    cdsMorethan = value;
                    break;

                case 'W' :
                    tempMorethan = value;
                    break;

            }
    
        }
    }
}

/* 
A = 자동모드(1), 수동모드(0) 전환
L = 광량기준치
T = 온도기준치
O = And(1) 또는 Or(0)
U = 광량 이상(1) 이하(0)
W = 온도 이상(1) 이하(0)
*/