  /* Projeto Nº 16 -> Sensor de fumaça
  *  
  * Author: Thiago Santos Tassinari
  * Data: 27/10/2020
  * Descrição do Projeto:
  
  <!----------------------------Projeto Sensor de fumaça----------------------------->
  
  Um circuito utilizando arduino que por um sensor de fumaça é ativado quando as condições
estabelecidas pelo local da fumaça está localizado.

<!-----------------------Componentes necessários------------------------------------->
  
  - Arduino Uno;
  - 1 Protoboard;
  - 5 LED
  - Sensor de gás;
  - 5 resistor de 220Ohms
  - 1 resistor de 4.7K0hms
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

#define PIN_LED_1 	6
#define PIN_LED_2 	5
#define PIN_LED_3 	4
#define PIN_LED_4 	3
#define PIN_LED_5 	2
#define PIN_GAS 	A3

void setup() 
{
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
  pinMode(PIN_LED_5, OUTPUT);
  pinMode(A3,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = map(analogRead(PIN_GAS), 300, 750, 0, 100);
  digitalWrite(PIN_LED_1, value >= 20 ? HIGH : LOW);
  digitalWrite(PIN_LED_2, value >= 30 ? HIGH : LOW);
  digitalWrite(PIN_LED_3, value >= 40 ? HIGH : LOW);
  digitalWrite(PIN_LED_4, value >= 60 ? HIGH : LOW);
  digitalWrite(PIN_LED_5, value >= 80 ? HIGH : LOW);
  Serial.println(value);
  delay(10);
}