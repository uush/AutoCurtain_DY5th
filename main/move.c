#include <Arduino.h>
void main() 
{
    int pos_i = extern count
}

void loop()
{
    direct = (position-pos_i>0) ? HIGH : LOW;
    digitalWrite(dirpin, direct); //방향지정 positive steps : Cw, negative steps : CCW
    steps = abs(position-pos_i);
    for (int i = 0; i < steps; i++) //이동 정도 지정_steps에 저장된 만큼 이동함
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
    }    
}