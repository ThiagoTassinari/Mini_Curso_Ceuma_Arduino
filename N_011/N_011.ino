/* Projeto Nº 08 -> Soundtrack de Star Wars of War

   Author: Thiago Santos Tassinari
   Data: 19/10/2020

  Descrição do Projeto:
  <!-------------------------------------------Soundtrack de Star Wars of Wars-------------------------------------------------------->

  Este circuito toca as duas canções principais de Star Wars. As funcionalidades são definidas das seguinte formas:
  
  1) Quando você pressiona o botão 1, os LEDs vermelhos acendem e reproduz a Marcha Imperial na campainha piezoelétrica.
  2) Quando você pressiona o botão 2, ele acende os LEDs azuis e reproduz a música-tema principal de Star Wars na campainha piezoelétrica.
  3) Quando você pressiona o botão 1, ele desliga tudo. O estado padrão do programa é começar com tudo desligado.

  <---------------------------------------------------------------------------------->

  <!-----------------------Componentes necessários------------------------------------->

  - Arduino Uno;
  - 4 LED's
  - 3 buttons
  - 4 resistores de 330Ohm;
  - Piezo buzzer;
  - Jumpers

  <------------------------------------------------------------------------------------->

*/


#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define G4S 415
#define A4 440
#define A4S 466
#define B4 494
#define C5 523
#define C5S 554
#define D5 587
#define D5S 622 
#define E5 659 
#define F5 698 
#define F5S 740
#define G5 784  
#define G5S 830 
#define A5 880 

/*
THE STAR WARS WAR
*/
int pb1 = 8;
int pb2 = 9;
int pb3 = 10;
int buzzer = 7;
int rled1 = 2;
int rled2 = 3;
int bled1 = 0;
int bled2 = 1;
int bFlag = 0; 

int jediN[16] = {C4, G4, F4, E4, D4, C5, G4, F4, E4, D4, C5, G4, F4, E4, F4, D4};
int delayJ[16] = { 1000, 1000, 250, 250, 250, 1000, 500, 250, 250, 250, 1000, 500, 250, 250, 250, 2000};

int marchN[42] = {A4, A4, A4, F4, C5, A4, F4, C5, A4, E5, E5, E5, F5, C5, G4S, F4, C5, A4,// 1ST SECTION
A5, A4, A4, A5, G5S, G5, F5S, F5, F5S, A4S, D5S, D5, C5S, C5, B4, C5,// 2ND SECTION 

F4, G4S, F4, C5, A4, F4, C5, A4// END
};

int delayM[42] = { 520, 520, 501, 351, 151, 501, 351, 151, 1150, 520, 520, 501, 351, 151, 501, 351, 151, 1150,// 1ST SECTION

501, 321, 251, 501, 326, 176, 126, 126, 576, 251, 501, 326, 176, 126, 126, 601,//2ND SECTION
251, 501, 376, 126, 501, 376, 126, 1251//END
};

int space[42] = { 500, 500, 500, 350, 150, 500, 350, 150, 650, 500, 500, 500, 350, 150, 500, 350, 150, 650,// 1ST SECTION

500, 300, 150, 500, 325, 175, 125, 125, 250, 250, 500, 325, 175, 125, 125, 250,//2ND SECTION
250, 500, 375, 125, 500, 375, 125, 650//END

};

 

void setup() {
  pinMode(pb1, INPUT_PULLUP);  
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);  
  pinMode(buzzer, OUTPUT);
  pinMode(rled1, OUTPUT);
  pinMode(rled2, OUTPUT);
  pinMode(bled1, OUTPUT);
  pinMode(bled2, OUTPUT);

}

void bCheck()  // Checks if other buttons pressed
  {
   if ( digitalRead(pb1) == LOW)
   {
    bFlag = 1;
    }
    if ( digitalRead(pb2) == LOW)
   {
    bFlag = 2;
    }
    if ( digitalRead(pb3) == LOW)
   {
    bFlag = 3;
   }
  }
void march(){
digitalWrite(rled1, HIGH);
  digitalWrite(rled2, HIGH);
  digitalWrite(bled1, LOW);
  digitalWrite(bled2, LOW);

  for (int i=0; i < 42; i++){
    tone(buzzer,marchN[i],space[i]);
    delay(delayM[i]);
    bCheck();
    if (bFlag==3 || bFlag==2){
      i= 42;
    }
  }
    //noTone(buzzer);
    delay(20);
  
}

void jedi(){
  digitalWrite(bled1, HIGH);
  digitalWrite(bled2, HIGH);
  digitalWrite(rled1, LOW);
  digitalWrite(rled2, LOW);

  for (int i=0; i<16; i++){
    tone(buzzer,jediN[i]);
    delay(delayJ[i]);
    bCheck();
    if (bFlag==3 || bFlag==1){
      i=16;
    }
  }
    //noTone(buzzer);
    delay(20);
  

}

void loop() {
    
  bFlag = 0;
   bCheck();  
 if (bFlag == 1)
{
while (bFlag == 1)
{
  march();
  bCheck();
}
}
  
  
  
 if (bFlag == 2)
{
while (bFlag == 2)
{
  jedi();
  bCheck();
}
}
  
  
  if (bFlag == 3)
  {
  off();
  }
}



void off() {
  digitalWrite(bled1, LOW);
  digitalWrite(bled2, LOW);
  digitalWrite(rled1, LOW);
  digitalWrite(rled2, LOW);
  digitalWrite(buzzer, LOW);
  
}
