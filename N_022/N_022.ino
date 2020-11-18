 /* Projeto Nº 22 -> Simulação de um servo motor
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
int valor_pot = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  valor_pot = analogRead(A0);
  valor_pot += map(valor_pot, 0, 1023, 0, 180);
  analogWrite(9, valor_pot);
  delay(10);
}