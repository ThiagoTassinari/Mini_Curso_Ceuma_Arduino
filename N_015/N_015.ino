  /* Projeto Nº15
  *  
  * Author: Thiago Santos Tassinari
  * Data: 27/10/2020
  * Descrição do Projeto:
  
  <!----------------------------Projeto Tanque D'água----------------------------->
 /*
Criar um circuito utilizando arduino que ative uma bomba dagua para abastecimento de uma caixa dagua, 
sendo que o mesmo deve indicar em um display de LCD quando a caixa dagua estiver "vazia", "enchendo" 
e "cheia" e ao estar cheia desligar a bomba dagua. O mesmo tbm so pode acionar a bomba se houver 
pressao de agua na entrada da rede de abastecimento, caso contrario a bomba nao podera ser acionada e 
deverá aparecer a mensagem no display "sem rede externa".


<!-----------------------Componentes necessários------------------------------------->
  
  - Arduino Uno;
  - 1 Protoboard;
  - 2 Interruptores DIP DPST x 6
  - 1 LED
  - 1 LCD 16X2;
  - 1 resistor de 220Ohms ou 330Ohms
  - 1 resistor de 10K0hms
  - 1 Potenciômetro
  - 1 push bottom;
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(10, 9, 8, 7, 6, 5);

#define SENSOR1  A0
#define SENSOR2  A1
#define SENSOR3  A2
#define SENSOR4  A3
#define SENSOR5  A4
#define SENSOR6  A5
#define SENSOR7  0
#define SENSOR8  1
#define SENSOR9  2
#define SENSOR10 3
#define SENSOR11 11
#define RELE 4

int NIVEL;

void pisca()
{
digitalWrite(RELE,LOW);
delay(500);
digitalWrite(RELE,HIGH);
delay(500);
}

void setup()
{
  pinMode(SENSOR1, INPUT_PULLUP);
  pinMode(SENSOR2, INPUT_PULLUP);
  pinMode(SENSOR3, INPUT_PULLUP);
  pinMode(SENSOR4, INPUT_PULLUP);
  pinMode(SENSOR5, INPUT_PULLUP);
  pinMode(SENSOR6, INPUT_PULLUP);
  pinMode(SENSOR7, INPUT_PULLUP);
  pinMode(SENSOR8, INPUT_PULLUP);
  pinMode(SENSOR9, INPUT_PULLUP);
  pinMode(SENSOR10, INPUT_PULLUP);
  pinMode(SENSOR11, INPUT_PULLUP);
  pinMode(RELE, OUTPUT);

  lcd.begin(16, 2);
  
  lcd.setCursor(3, 0);
  lcd.print("Bem Vindo");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(4, 0);
  lcd.print("Projeto");
  lcd.setCursor(2, 1);
  lcd.print("Caixa D`agua");  
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("Thiago Santos");
  delay(3000);
  lcd.clear();
}

void loop(){
    
  if(digitalRead(SENSOR10) == LOW){lcd.print(" CHEIA");}
  else if(digitalRead(SENSOR9) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR8) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR7) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR6) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR5) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR4) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR3) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR2) == LOW){lcd.print(" SIM");}
  else if(digitalRead(SENSOR1) == LOW){lcd.print(" SIM");}
  else {lcd.print(" NAO  ");}
  
  if (digitalRead(SENSOR10) == LOW){NIVEL = 100;}
  else if (digitalRead(SENSOR9) == LOW){NIVEL = 90;}
  else if (digitalRead(SENSOR8) == LOW){NIVEL = 80;} 
  else if (digitalRead(SENSOR7) == LOW){NIVEL = 70;} 
  else if (digitalRead(SENSOR6) == LOW){NIVEL = 60;} 
  else if (digitalRead(SENSOR5) == LOW){NIVEL = 50;} 
  else if (digitalRead(SENSOR4) == LOW){NIVEL = 40;} 
  else if (digitalRead(SENSOR3) == LOW){NIVEL = 30;} 
  else if (digitalRead(SENSOR2) == LOW){NIVEL = 20;} 
  else if (digitalRead(SENSOR1) == LOW){NIVEL = 10;} 
  else {NIVEL=0; digitalWrite(RELE,HIGH);}
  
  lcd.setCursor(0,0);
  lcd.print("Nivel Caixa:");
  if(NIVEL<10) lcd.print("  ");
  else if(NIVEL<100) lcd.print(" ");
  lcd.print(NIVEL);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Enchendo:");
  
  
  /*
          
    if (NIVEL == 0){
    lcd.setCursor(0,0);
  	lcd.print("Nivel Caixa:");
	lcd.print(NIVEL);
  	lcd.print("%");
    delay(5000);
  	lcd.clear(); 
    lcd.setCursor(0, 1);
    lcd.print("Sem Fornecimento");
  }
  
  else if (NIVEL == 100){
    lcd.setCursor(0,0);
  	lcd.print("Nivel Caixa:");
	lcd.print(NIVEL);
  	lcd.print("%");
    delay(5000);
  	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Caixa da agua");
    lcd.setCursor(5, 1);
  	lcd.print("Cheia");
  }
  
  else {
    lcd.setCursor(0,0);
  	lcd.print("Nivel Caixa:");
	lcd.print(NIVEL);
  	lcd.print("%");
    delay(5000);
  	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enchendo");
    lcd.setCursor(0, 1);
  	lcd.print("Caixa da agua");
  }
  
  */
}