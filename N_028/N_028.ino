 /* Projeto Nº 28 -> Verificação de um sinal de pulso com osciloscópio
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
  - 1 Potenciômetro;
  - 1 Resistor de 0.2kOhm;
  - 1 LED;
  - 1 Osciloscópio;
  - 1 Multímetro
  - Jumpers
  
<------------------------------------------------------------------------------------->  

!5V-->1023  (resolução de 10bits)
Vref=5V (Escolha padrão)
Sensor conectado a A0
Demonstração de sinal PWM 
O brilho do led depende do valor médio

em seus terminais Vdmoy = r * 5V com r = Ton / T ciclo de trabalho
0<=r<=1
 
*/

int sensorValue = 0;

void setup()
{ //Saída PWM no pino 5
  pinMode(5,OUTPUT);
}

void loop()
{
  // Ler e converter a tensão em A0
  sensorValue = analogRead(A0);
  // Divida este valor por 4 para trazê-lo de volta para o intervalo 0-255
  // Divisão por 4 é equivalente a fazer dois turnos para a esquerda
  // 10 bits (0 à 1023) deslocado para a esquerda, obtemos 8 bits (0 à 255)
  analogWrite(5,(sensorValue>>2));
}