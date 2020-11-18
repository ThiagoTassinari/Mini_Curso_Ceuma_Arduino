 /* Projeto Nº 23 -> Simulação de um servo motor
  *  
  * Author: Thiago Santos Tassinari
  * Data: 30/10/2020
  
  * Descrição do Projeto:
  
  <!---------------------Simulação de um servo motor----------------------------->
  	
    O projeto tem como funcionalidade utilizar um servo motor para simular sua funcionalidade
    por meio do acionamento de dois botões. O motor recebe as funções de acionar o giro para
    frente ou para trás recebendo interrupção dos relés ao pressionar o botão desejado. 
    
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - 1 Arduino Uno;
  - 1 Protoboard;
  - 1 Potenciômetro;
  - 1 Servo motor;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/
void setup() {
  
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
void loop() {

  
  if(digitalRead(9)==HIGH){
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  }
  
  else if (digitalRead(8)==HIGH){
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  }
  
  else {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
}