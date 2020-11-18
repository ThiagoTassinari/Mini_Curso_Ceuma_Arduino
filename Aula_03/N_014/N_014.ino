  /* Projeto Nº 14
  *  
  * Author: Thiago Santos Tassinari
  * Data: 28/10/2020
  * Descrição do Projeto:
  
  <!----------------------------Semáforo com pedestre----------------------------->
  
  Um circuito utilizando arduino UNO para simulação de um semáforo acionado para parar
  ao pedestre querer atravessar a rua. Apenas precisa apertar o botão para mudar a 
  função dos LEDs.

<!-----------------------Componentes necessários------------------------------------->
  
  - Arduino Uno;
  - 1 Protoboard;
  - 5 Leds;
  - 5 Resistores de 100Ohm
  - 1 Resistor de 10KOhm
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

int pinVermelho = 13;         /* Variaveis dos Leds (semáforo) e seus pinos correspondentes. */
int pinAmarelo = 12;           
int pinVerde = 8;
int pinBotao = 7;
int pinPedestreVerde = 4;
int pinPedestreVermelho = 2;

int faseSemaforo;   /* Varivel que saberá a sequencia na qual o botão está sendo acionado*/

int estadoBotao;   /* Variavel que lerá quando o botão for acionado*/
int estadoAnteriorBotao;

int tempoPisca;  // Tempo que o pisca do pedestre ficará piscando
int estadoPisca; // Definir se o Pisca será ligado ou desligado

void setup()
{
 pinMode(pinVerde, OUTPUT);                     
 pinMode(pinAmarelo, OUTPUT);
 pinMode(pinVermelho, OUTPUT);       /* Todas as variaveis dentro de Pinmode indica o que cada componente do circuito é se é entrada(INPUT) ou Saída(OUTPUT).*/
 pinMode(pinPedestreVerde, OUTPUT);
 pinMode(pinPedestreVermelho, OUTPUT);
 pinMode(pinBotao, INPUT);
  
 faseSemaforo = 1;  /* Mostra em qual fase começará (qual led acenderá primeiro), neste caso a fase 1 led verde).*/

 estadoAnteriorBotao = digitalRead(pinBotao); 
  
 tempoPisca = 0;
 estadoPisca = HIGH;
}

void loop()
{
  estadoBotao = digitalRead(pinBotao);  /* Indica o que a variavel estadoBotao deve fazer, que é ler o pino digital que estiver dentro da variavel pinBotao. */
  
  if((estadoBotao == LOW) && (estadoAnteriorBotao == HIGH)) {     /* Se o pino digital que esta na variavel estadoBotao for igual a ligado... */
    
    if(faseSemaforo < 4){       /* E se a fase do semáforo for não for a fase 3... */
     faseSemaforo = faseSemaforo + 1;  /* Então muda a fase do semaforo para a seguinte, */
   } else
     faseSemaforo = 1;          /* Mas se a fase for a 3 então muda de volta para a fase 1. */
 }
  estadoAnteriorBotao = estadoBotao;
    
    
  if(faseSemaforo == 1) {           // SEMAFORO VERDE, PEDESTRE FECHADO           
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);       
    
    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
   }
  
  if(faseSemaforo == 2){             // SEMAFORO AMARELO, PEDESTRE FECHADO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);   
    digitalWrite(pinVermelho, LOW);
    
    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
   }              
  if(faseSemaforo == 3){            // SEMAFORO VERMELHO, PEDESTRE ABERTO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
   
    digitalWrite(pinPedestreVerde, HIGH);
    digitalWrite(pinPedestreVermelho, LOW);
   }
  
   if(faseSemaforo == 4){            // PEDESTRE PISCANDO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
   
    tempoPisca = tempoPisca + 1;
     if(tempoPisca == 400) {
       estadoPisca = !estadoPisca;
       tempoPisca = 0;
     }
    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, estadoPisca);
   }
  delay(1);
}                