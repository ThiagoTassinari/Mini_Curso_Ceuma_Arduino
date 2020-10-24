
 /* Projeto Nº 07 -> Sensor de distância ultrassônico 
  * Descrição do Projeto:
      Utilizando o sensor SC-SR04 enviar um sinal de pulso com o trigger e receber esse sinal com o echo para poder
      medir a distância do sensor do objeto localizado.
*/

/*      
  * Author: Thiago Santos Tassinari
  * Data: 17/10/2020
*/

/* Componentes necessários
  
  - Arduino Uno;
  - Sensor de distância HC-SR04
  - Jumpers
  
*/

int trig = 7;
int echo = 6;

float distance;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);	// Monitorar
}

void loop() {

  digitalWrite(trig, LOW);	// Desligado
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);	//Acionar o trigger
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  distance = pulseIn(echo, HIGH);	// Captura da duração de um pulso em um pino
  distance = distance / 58;

  Serial.println(distance);

}
