// C++ code
//
#include <Servo.h> 

Servo servo1;

int potenciometroPino0 = 0;
int valorDoPotenciometro = 0;

void setup (){
    
  servo1.attach(9);
  
  
}

void loop(){

  valorDoPotenciometro = analogRead(potenciometroPino0);
  valorDoPotenciometro = map(valorDoPotenciometro, 0, 1023, 0, 179);
  servo1.write(valorDoPotenciometro);
  
  delay(15);
  
  
}
