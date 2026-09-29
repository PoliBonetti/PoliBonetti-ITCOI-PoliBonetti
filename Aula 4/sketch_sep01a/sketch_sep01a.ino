// C++ code
//
const int carroVermelho = 1;
const int carroAmarelo = 2;
const int carroVerde = 3;
const int pedVermelho = 4;
const int pedVerde = 5;

void setup() {
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
}

void loop() {
  digitalWrite(carroVerde, HIGH);
  digitalWrite(pedVermelho, HIGH);
  delay(5000); 

  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);
  delay(3000);
  
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, HIGH);
  
  digitalWrite(pedVermelho, LOW);
  digitalWrite(pedVerde, HIGH);
  delay(5000); 

  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  
  digitalWrite(pedVerde, LOW);
  for (int i = 0; i<5; i++) {
    digitalWrite(pedVermelho, HIGH);
    delay(550);
    digitalWrite(pedVermelho, LOW);
    delay(500);
  }
}
