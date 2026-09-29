// sensor de estacionamento

const int led1 = 4;
const int led2 = 5;
const int echoPin = 2;
const int trigPin = 3;
const int buzzerPin = 6;

// distância limite para ativar o alerta
const int threshold = 30;

// armazenar o tempo de ida e volta 
unsigned long nDuration;

// armazenar a distancia calculada em centimetros
float nDistance;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // garante que o trig comece desligado
  digitalWrite(trigPin, LOW);
  
  Serial.begin(9600);
  Serial.println("Iniciando sensor ultrassônico...");
}

void loop()
{
  // 1. envio de pulso ultrassonico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 2. medicao do tempo de retorno
  nDuration = pulseIn(echoPin, HIGH, 30000);
  
  // 3. verificacao da leitura
  // nenhum retorno foi identificado
  if (nDuration == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    
    Serial.println("Sem leitura valida.");
    delay(200);
    
    return;
  }  

  // 4. calculo da distancia
  // converter tempo (micro segundos) em distancia (cm)
  nDistance = nDuration * 0.0343 / 2;
  
  // 5. exibicao da distancia
  Serial.print("Distancia: ");
  Serial.print(nDistance, 1);
  Serial.println(" cm");
  
  // 6. verificar se a distancia é menor que 30 cm
  if (nDistance < threshold)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzerPin, 2000);
    delay(400);
    noTone(buzzerPin);
    digitalWrite(led2, LOW);
    delay(300);  
  }
  // 7. distancia for igual ou maior a 30 cm
  else 
  {
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    digitalWrite(led1, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    delay(300);
  }
}
