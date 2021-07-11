#include "SoftwareSerial.h"

/*
1. 블루투스로부터 명령문자열(코드+값) 받아서 만들기 , 이름 get_data
2. 명령 문자열을 코드와 값으로 분리해주는 함수 만들기
3. 2번 사용해서 분리된 코드와 값으로 각 부품에게 명령을 내림, 이름 setting_data
*/

String get_data();  //1번 기능

void setting_data(); //2,3번 기능
