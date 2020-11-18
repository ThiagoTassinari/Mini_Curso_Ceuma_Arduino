  /* Projeto Nº 20
  
  *  
  * Author: Thiago Santos Tassinari
  * Data: 02/11/2020
  * Descrição do Projeto:
  
  <!----------------------------Josytick Game----------------------------->
  
  É um simples jogo de controle que ao apertar o botão mostrará uma sequência de Leds
  piscando, o ultimo LED a piscar será o botão que terá que apertar para dar sequência
  ao jogo.

<!-----------------------Componentes necessários------------------------------------->

  - 1 Arduino UNO;
  - 1 Protoboard;
  - 4 Leds;
  - 4 Resistores 10KOhms;
  - 4 Resistor 220Ohm;
  - 4 Buttons;
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

#define B_UP 13
#define B_DOWN 12
#define B_RIGHT 11
#define B_LEFT 10

#define L_UP 0
#define L_DOWN 2
#define L_RIGHT 3
#define L_LEFT 1

void setup()
{
  
  pinMode(B_UP, INPUT);
  pinMode(B_DOWN, INPUT);
  pinMode(B_LEFT, INPUT);
  pinMode(B_RIGHT, INPUT);
  
  pinMode(L_UP, OUTPUT);
  pinMode(L_DOWN, OUTPUT);
  pinMode(L_LEFT, OUTPUT);
  pinMode(L_RIGHT, OUTPUT);

}

int buttonState[4] = { 0 };
int randomValue = 0;

void loop()
{
  
  digitalWrite(randomValue, LOW);
  randomValue = rand() % 4;
  digitalWrite(randomValue, HIGH);
    
  for (int i = 0; i < 250; i++){
  
    buttonState[L_UP] = digitalRead(B_UP);
    buttonState[L_DOWN] = digitalRead(B_DOWN);
    buttonState[L_LEFT] = digitalRead(B_LEFT);
    buttonState[L_RIGHT] = digitalRead(B_RIGHT);

    if (buttonState[randomValue] == HIGH){
        digitalWrite(randomValue, LOW);
        delay(200);
        digitalWrite(randomValue, HIGH);
        delay(200);
        digitalWrite(randomValue, LOW);
        delay(200);
        digitalWrite((randomValue+1)%4, HIGH);
        delay(200);
        digitalWrite((randomValue+1)%4, LOW);
        delay(200);
        digitalWrite((randomValue+2)%4, HIGH);
        delay(200);
        digitalWrite((randomValue+2)%4, LOW);
        delay(200);
        digitalWrite((randomValue+3)%4, HIGH);
        delay(200);
        digitalWrite((randomValue+3)%4, LOW);
        delay(200);
      break;
    }else{
    	delay(20);
    }
   }
}