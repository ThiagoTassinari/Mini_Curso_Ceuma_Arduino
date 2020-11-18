  /* Projeto Nº 18 -> Sistema de Segurança
  *  
  * Author: Thiago Santos Tassinari
  * Data: 28/10/2020
  * Descrição do Projeto:
  
  <!----------------------------Sistema de Segurança----------------------------->
  
  Um circuito utilizando arduino UNO 

<!-----------------------Componentes necessários------------------------------------->
  
  - Arduino Uno;
  - 1 Protoboard;
  - 1 Sistema de proximidade(PIR);
  - 1 Potenciometro;
  - 1 Buzzer
  - 1 LCD 16x2
  - 1 Teclado 
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13,12,5,4,3,2);
int freq=1000; //potência em Hz no buzzer
int leitura=0; //variável para a leitura do sensor de movimento
const byte ROWS = 4;
const byte COLS = 4;
char tecla;
int teclasIgressadas=0, tentativas=0, tentativasR=5;
char* senha="1234";
int x=0;
boolean alarmeAtivado;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11,10,9,1};
byte colPins[COLS] = {0,A0,A1,A2};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
	pinMode(8,OUTPUT); //buzzer
	pinMode(7,INPUT); //sensor
  	pinMode(6,OUTPUT); //led externo
  	lcd.begin(16, 2); //iniciar LCD com 16 caracteres nas linhas
}
void loop(){
  leitura=digitalRead(7);
  if (leitura==HIGH && tentativas!=5){ //Se detecta movimento
    lcd.setCursor(0,0); //Pare na primeira linha do display
    lcd.print("ALARME ATIVADO"); //Imprime mensagem no LCD
    lcd.setCursor(0,1); //Pare na segunda linha do display
    lcd.print("DIGITE A SENHA."); //Imprime mensagem no LCD
    tone(8, freq); //toca
    digitalWrite(6, HIGH);
    x=0;//Essa linha nos permite inserir a SENHA somente quando o sensor parar de detectar movimento.
  	alarmeAtivado=true;
  }
    tecla=customKeypad.getKey(); //Obtém os digítos do teclado
  if(tecla){
  	teclasIgressadas++;
  }
  if(tecla==senha[x]){ //Se coincidir a senha com as teclas digitadas
     x++; //Aumentamos x: quantas vezes o pino corresponde aos dígitos que o usuário insere (do menor ao maior)
     lcd.setCursor(0,12);
     lcd.print("PORTA ABERTA");
  }
  if (x==4 || alarmeAtivado==false) {//Se coincidem a senha digitada
    digitalWrite(6, LOW); //deixe o led externo desligado
    	noTone(8); //desliga o buzzer
    	lcd.setCursor(0,0); // Pare na primeira linha do display
    	lcd.print("   PORTA FECHADA    "); //Imprime no LCD
    	lcd.setCursor(0,1); //Pare na segunda linha do display
    	lcd.print(" CASA SEGURA "); //Imprime mensagem no LCD
    	alarmeAtivado=false;
    	x=0;
    	teclasIgressadas=0;
    	tentativasR=5;
    	tentativas=0;
    }
  if(teclasIgressadas==4 && teclasIgressadas!=0 && x!=4 && alarmeAtivado==true){
    lcd.setCursor(0,0); //Pare na primeira linha do display
    lcd.print("ERRO A SENHA ! !"); //Imprime a mensagem no LCD
    lcd.setCursor(0,1); //Pare na segunda linha do display
    lcd.print(tentativasR-1);
    lcd.print(" TENTATIVAS FALHAS!!");//Imprime a mensagem no LCD
    if(x!=4)
    tentativasR--;
   	teclasIgressadas=0;
  }
  if(tentativas==5){
    tone(8, freq);
    lcd.setCursor(0,0); //Pare na primeira linha do display
    lcd.print("ALARMA ACTIVADA!"); //Imprime a mensagem no LCD
    lcd.setCursor(0,1); //Pare na segunda linha do display
    lcd.print("O BOP É CHAMADO!");//Imprime a mensagem no LCD
    digitalWrite(6, HIGH);
    delay(700);
    digitalWrite(6, LOW);
    delay(700);
    leitura==LOW;
    x=5;
    teclasIgressadas=5;
  }	
}