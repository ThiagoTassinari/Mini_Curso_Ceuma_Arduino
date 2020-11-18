 /* Projeto Nº 21 -> Simulação de um servo motor
  *  
  * Author: Thiago Santos Tassinari
  * Data: 30/10/2020
  
  * Descrição do Projeto:
  
  <!---------------------Simulação de um servo motor----------------------------->
  	
    O projeto tem como funcionalidade utilizar um servo motor para simular sua funcionalidade
    por meio de um potenciômetro para calibrar seu movimento de ida e volta a posição original.
    
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - 1 Arduino Uno;
  - 1 Protoboard;
  - 1 Potenciômetro;
  - 1 Servo motor;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/

#include <Servo.h>
#include <SoftwareSerial.h>

int pos = 0;
int sensorValue = 0;
int i = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop()
{

   sensorValue = analogRead(A0);
   pos = map(sensorValue,0,1023,0,180);
  
  Serial.print("sensorValue ");
  Serial.println(sensorValue);
  Serial.print("pos ");
  Serial.println(pos); 
  
  for (i = 0; i <= pos; i++) {
                      
    // Diga ao servo para ir para a posição na variável 'pos'
    servo_9.write(i);
    delay(15); // espere 15 ms para que o servo alcance a posição
  }
  for (i= pos; i >= 0; i --) {
    // Diga ao servo para ir para a posição na variável 'pos'
    servo_9.write(i);
    // espere 15 ms para que o servo alcance a posição
    delay(15); // espere por 15 ms
  }
}