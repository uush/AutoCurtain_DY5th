#include "communication.h"
#include "pinnum.h"

SoftwareSerial BTSerial(TX_PIN, RX_PIN);

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

void setting_data(String ctrl_str)
{
}