//cds, DHT11
#include "DHT.h"
#include "DHT_U.h"
#include "Stepper.h"
#include "Adafruit_Sensor.h"

#define DHTPIN 6
#define DHTTYPE DHT11
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3); //SoftwareSerial(RX,TX)

DHT dht(DHTPIN, DHTTYPE);
//cds 핀 A0 설정
int cds = A0;
int light = 0;
int flag = 0;
int tem = 0;
int hum = 0;
int BT;
int cdsValue;
char data;


void setup() {
  Serial.begin(9600); 
  BTSerial.begin(9600);
  dht.begin();
  //아날로그 입력값을 0(어두울 때)~100(밝을 때)로 범위 다시 변경.
  light = map(cdsValue, 8,765, 100, 0);
  if(light<=30){flag=0;}  //밝기가 30%이하일 때 'flag=0'으로 설정 **여기가 좀 걸린다. flag설정해 둬도 괜찮나?
  else if(light>30){flag=1;}
}

void loop() {
  //**여기 loop 맨 처음에 if (BT.available())이 필요할 것 같아요** 
//available()함수는 데이터가 발생하였을때 1을 반환하는 함수에요.
//만약 저 조건문이 참이라면 BT.read()함수를 사용하여 발생한 데이터의 값을 읽을 수 있어요. 
//스마트폰 앱에서 발생한 데이터는 문자형(char)일 것이고, read()함수는 정수형을 반환하는 함수에요. 
//따라서 그 사이트에서는 char형으로 강제 형변환을 하고 있어요. (char)BT.read() <-- 이런식으로

  
  if(BTSerial.available()){ //데이터가 발생하였을 때 1을 반환하는 함수 
    //어플에서 1(자동모드 버튼), 2(수동모드 버튼)을 눌렀을 시 그 버튼에 맞는 숫자(char형)가 전송
    if((char)BTSerial.read()=='1'){//참일 경우에 발생한 데이터의 값을 읽어오기. read()는 정수형 반환
      Serial.println("Auto Mode");  //자동모드로 전환
      while(1){
        data = BTSerial.available();  //
        Sensing();
        Auto_Mode();  //자동 모드 함수 가져오기
        if(data == '2')break; //수동 모드 눌렀을 때의 값 = '2', 수동모드를 누루면 자동모드 해제 
      }
      }
    }
    else if((char)BTSerial.read()=='2'){
      Serial.println("Hand Mode");  //수동모드로 전환
      while(1){
        data = BTSerial.available();
        Sensing();
        Hand_Mode();
        if(data == '1')break; //자동모드를 눌렀을 때, 수동모드 해제
      }
    }
}

//센서 작동
void Sensing(){
  //온도와 습도를 측정후, 각각 tem, hum 변수에 저장.
  int tem = dht.readTemperature();
  int hum = dht.readHumidity();

  Serial.print("temperature : ");
  Serial.println(tem);
  Serial.print("humidity : ");
  Serial.println(hum);
  Serial.println("");
  delay(1000);

  cdsValue = analogRead(cds);//cds 셀로 부터 아날로그 값을 읽어서 cdsValue변수에 저장.  
  Serial.print("cds : ");
  Serial.println(cdsValue);
  Serial.print("light : ");
  Serial.println(light);
  delay(1000);
}

void Auto_Mode(){ //함수 정의 
  if(light<=30 && flag == 1){ //저녁에 커튼을 닫는다.
    curtain_close();
    flag = 0;
  }
  if(tem<21 && flag == 1){  //외부 온도가 21도 보다 낮을 때 커튼을 닫는다.(보온효과)
    curtain_close();
    flag = 0;
  }
  if(hum>50 && flag ==0){ //외부 습도가 50%보다 높을 때 커튼을 연다.
    curtain_open();
    flag = 1;
  }
}
void Hand_Mode(){
  if(BTSerial.available()){//블루투스 데이터가 수신될 경우
    BT=BTSerial.read();
    if(BT == 'd' && flag ==0){//BT에 저장된 값이 'd'이고 flag가 0일 경우
      curtain_on();
      flag = 1; //열렸으니까 '1'인 상태를 플래그에 저장
    }
    else if(BT == 'u' && flag ==1){ //BT에 저장된 값이 'u'이고 flag가 1일 경우
      curtain_close();
      flag=0; //flag reset
    }
  }
}
//커튼 열기, 모터 작동 코드
void curtain_open(){
  for(){
    }
}

//커튼 닫기
void curtain_close(){
  for(){
  }
}

// flag를 0,1로 설정하면 50, 70, 100를...어떻게 결정하죠? 모두 flag = 1로 하기에는 flag 1일 때 모두 모터가 돌아가는 값이 같지 않나요?
// 상황1) 아침이라 판단하고 커튼을 연다 - 사용자가 오후에 수동으로 커튼을 닫았다. - 조도가 값을 계속 측정해서 커튼을 다시 열어버린다.
// 상황2) 사용자가 커튼을 수동으로 열고 잤는데, 온도가 내려가서 자동으로 커튼을 닫을 수 있도록 해야 함.
