 /* Projeto Nº 24 -> Simulação de transferidor com servo motor + LEDs
  *  
  * Author: Thiago Santos Tassinari
  * Data: 01/10/2020
  
  * Descrição do Projeto:
  
  <!---------------------Simulação de transferidor com servo motor + LEDs----------------------------->
  	
    O projeto tem como funcionalidade utilizar um servo motor para simular um tranferidor
    em conjunto dos LEDs inseridos nas portas do Arduino Uno
    
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - 1 Arduino Uno;
  - 1 Protoboard;
  - 9 LEDs ;
  - 9 resistor de 220Ohms;
  - 1 Servo motor;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/
#include <Servo.h>

int grau = 0;

int i = 0;

int j = 0;

Servo servo_3;

void setup()
{
  servo_3.attach(3);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  grau = 0;
  for (grau = 0; grau <= 180; grau += 1) {
    servo_3.write(grau);
    delay(30); // Wait for 30 millisecond(s)
    if (grau == 0) {
      digitalWrite(4, HIGH);
    }
    if (grau == 20) {
      digitalWrite(5, HIGH);
    }
    if (grau == 40) {
      digitalWrite(6, HIGH);
    }
    if (grau == 60) {
      digitalWrite(7, HIGH);
    }
    if (grau == 80) {
      digitalWrite(8, HIGH);
    }
    if (grau == 100) {
      digitalWrite(9, HIGH);
    }
    if (grau == 120) {
      digitalWrite(10, HIGH);
    }
    if (grau == 140) {
      digitalWrite(11, HIGH);
    }
    if (grau == 160) {
      digitalWrite(12, HIGH);
    }
    if (grau == 180) {
      digitalWrite(13, HIGH);
    }
  }
  delay(1000);
 
  for (grau = 180; grau >= 0; grau -= 1) {
    servo_3.write(grau);
    delay(30);
    if (grau == 0) {
      digitalWrite(4, LOW);
    }
    if (grau == 20) {
      digitalWrite(5, LOW);
    }
    if (grau == 40) {
      digitalWrite(6, LOW);
    }
    if (grau == 60) {
      digitalWrite(7, LOW);
    }
    if (grau == 80) {
      digitalWrite(8, LOW);
    }
    if (grau == 100) {
      digitalWrite(9, LOW);
    }
    if (grau == 120) {
      digitalWrite(10, LOW);
    }
    if (grau == 140) {
      digitalWrite(11, LOW);
    }
    if (grau == 160) {
      digitalWrite(12, LOW);
    }
    if (grau == 180) {
      digitalWrite(13, LOW);
    }
  }
  delay(1000);
}