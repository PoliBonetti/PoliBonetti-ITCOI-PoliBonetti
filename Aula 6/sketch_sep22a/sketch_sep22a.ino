// C++ code
//
#include <Servo.h>

Servo meuServo;
int botao = 7;

void setup()
{
  //define o botao como entrada
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  meuServo.attach(9);
  if (digitalRead (botao) == LOW)
  {
    //Aumenta o angulo do Servo ate chegar em 180 graus
    for(int angulo = 0; angulo <= 180; angulo++)
    {
      meuServo.write(angulo);
      delay(10);
    }
    delay(10);
    
    //Diminui o angulo do Servo
    for (int angulo = 180; angulo >= 0; angulo--)
    {
      meuServo.write(angulo);
      delay(10);
    }
  }
  meuServo.detach();
}
