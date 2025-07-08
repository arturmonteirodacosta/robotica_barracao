// Definição dos pinos
const int trigPin = 9;  // Pino TRIG do HC-SR04
const int echoPin = 10; // Pino ECHO do HC-SR04
const int ledPin = 13;  // LED embutido no Arduino Nano

// Variáveis
long duracao;
float distancia;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  // Configura os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // Configura o pino do LED como saída
}

void loop() {
  // Limpa o pino TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Envia um pulso de 10µs no pino TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o tempo de retorno no pino ECHO
  duracao = pulseIn(echoPin, HIGH);
  
  // Calcula a distância (em cm)
  distancia = (duracao * 0.034) / 2;
  
  // Exibe a distância no Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Controla o LED: acende se distância < 10 cm, apaga caso contrário
  if (distancia < 10.0 && distancia > 0) {
    digitalWrite(ledPin, HIGH); // Acende o LED
  } else {
    digitalWrite(ledPin, LOW);  // Apaga o LED
  }
  
  // Aguarda antes de nova leitura
  delay(500);
}