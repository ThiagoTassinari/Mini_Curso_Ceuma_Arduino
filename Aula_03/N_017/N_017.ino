  /* Projeto Nº 17
  
  *  
  * Author: Thiago Santos Tassinari
  * Data: 02/11/2020
  * Descrição do Projeto:
  
  <!----------------------------Sensor de estacionamento----------------------------->
  
	O buzzer vai tocar na hora que a distância do carro estiver no local proximo
    ao estacionamento

<!-----------------------Componentes necessários------------------------------------->

  - 1 Arduino UNO;
  - 1 Protoboard;
  - 1 sensor PIR (HC-SR04)
  - 1 Buzzer
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

// Declarando variáveis 
int inEcho = 4;
int inTrig = 7;
int piezzo = 2;
float dist, temp;

void setup()
{
	Serial.begin(9600);
  	pinMode(2, OUTPUT);
  	pinMode(4, INPUT);
  	pinMode(7, OUTPUT);
}

void loop() 
{
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(7, LOW);
  temp = pulseIn(4, HIGH);
  dist = temp * 0.01715;

if(dist >= 150)
{
  digitalWrite(2, 1);
  delay(1000);
  digitalWrite(2, 0);
  delay(1000);
}

else if(dist <= 149 && dist > 120) 
{
  digitalWrite(2, 1);
  delay(1000);
  digitalWrite(2, 0);
  delay(1000);
}

else if(dist <= 119 && dist > 100) 
{
  digitalWrite(2, 1);
  delay(500);
  digitalWrite(2, 0);
  delay(500);
}

else if(dist <= 99 && dist > 60) 
{
  digitalWrite(2, 1);
  delay(250);
  digitalWrite(2, 0);
  delay(250);
}

else if(dist <= 59 && dist > 40) 
{
  digitalWrite(2, 1);
  delay(5);
  digitalWrite(2, 0);
  delay(5);
}

  Serial.println(dist);
}