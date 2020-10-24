/*
Author: Thiago Santos Tassinari
Data: 21
/10/2020
*/

/* Descrição do projeto:
<!------------------------------Sensor de temperatura------------------------------------------->

Desenvolver um programa que leia o valor analógico da tensão de saída do
potenciômetro e indique a tensão no display de 7 segmentos. O programa deve mostrar
no display apenas o valor inteiro da tensão. (Ex: Se valor lido no multímetro for 3,95V
indicar apenas o 3 no display). Além disso, indique na serial, com precisão de duas casas
decimais, o valor da tensão lida pelo potenciômetro.

<!--------------------------------------------------------------------------------------------->

<!----------------------------Componenetes necessários----------------------------------------->
  - Arduino UNO;
  - Protoboard;
  - Visor de 7 Segmentos;
  - Multímetro;
  - Jumpers;
  - Potenciômetro (ou registor variável);
  - Resistor: 150Ohm
<!--------------------------------------------------------------------------------------------->
*/

// Varíaveis de entrada nas portas

int AN = A0;
int MOTOR = 3;

int DA = 9;
int DB = 10;
int DC = 13;
int DD = 12;
int DE = 11;
int DF = 8;
int DG = 7;

// Variáveis para entrada analógica do sensor de temperatura TMP36
int16_t analogica = 0;
double tensao = 0;
uint8_t i = 0;

// Varíavel para guardar os bytecodes necessários para registrar a saída do sinal para o potenciômetro
byte display[16] = 
{  0b01111110,// = Digito 0
   0b00110000,// = Digito 1 
   0b01101101,// = Digito 2 
   0b01111001,// = Digito 3
   0b00110011,// = Digito 4
   0b01011011,// = Digito 5
   0b01011111,// = Digito 6
   0b01110000,// = Digito 7 
   0b01111111,// = Digito 8 
   0b01110011,// = Digito 9 
   0b01110111,// = Digito A
   0b00011111,// = Digito B
   0b01001110,// = Digito C
   0b00111101,// = Digito D 
   0b01001111,// = Digito E 
   0b01000111}; // = Digito F

void setup() {
	Serial.begin(115200);
   
   for(i = 7; i <= 13; i++) pinMode(i , 1); // Configura pinos como saidas 
}

void atualiza_display(byte t) {
   bool status = 0;
   
   status = display[t] & 0b01000000;
   digitalWrite(DA, status);
   
   status = display[t] & 0b00100000;
   digitalWrite(DB, status);
   
   status = display[t] & 0b00010000;
   digitalWrite(DC, status);
   
   status = display[t] & 0b00001000;
   digitalWrite(DD, status);
   
   status = display[t] & 0b00000100;
   digitalWrite(DE, status);
   
   status = display[t] & 0b00000010;
   digitalWrite(DF, status);
   
   status = display[t] & 0b00000001;
   digitalWrite(DG, status);
}

void loop() {
	analogica = analogRead(AN); // Lê entrada anoliga de 10 bits e atribui à variável 'anlógica'.
   
   tensao = (double) analogica / 1023 * 5;
   
   // Imprime na serial
	Serial.print("AN = ");
	Serial.println((double) tensao, 3); // Para que o arredondamento não interfira, ex 1,99 = 2.00 , mostra 1 no display e 2 na serial 
   
   atualiza_display(tensao); // apenas inteiro de 0 a 5; 
	
	delay(25); // Para não travar o TinkerCad
}