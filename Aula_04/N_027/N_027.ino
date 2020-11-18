 /* Projeto Nº 27 -> Verificação de um sinal de pulso com osciloscópio
  *  
  * Author: Thiago Santos Tassinari
  * Data: 09/10/2020
  
  * Descrição do Projeto:
  
  <!-----------------------Verificação de um sinal de pulso com osciloscópio --------------------------->
  	
    O projeto tem como funcionalidade utilizar um arduino uno + osciloscópio para simular
    um sinal de pulso usando a porta PWM. A variação da onda quadrática será controlado por
    um potenciômetro.
    
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - 1 Arduino Uno;
  - 1 Protoboard;
  - 1 Potenciômetro;
  - 1 resistor de 100Ohm;
  - 1 LED;
  - 1 Osciloscópio;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/

int velocidade = A0;
unsigned int PIN_PULSO = 8;

void setup() {
  
  pinMode(PIN_PULSO, OUTPUT);
}
  
void loop() {    
  
  float vel = analogRead(velocidade)+100;
  
    for (int x = 0; x < vel; x ++) {
     digitalWrite        (PIN_PULSO, HIGH);
    }
    
    for (int x = 0; x < vel; x ++) {
     digitalWrite         (PIN_PULSO, LOW); 
    }
  }
     