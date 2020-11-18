/* Projeto Nº 26 -> Simulação de 2 servo motor controlador pro remote control IR
  *  
  * Author: Thiago Santos Tassinari
  * Data: 08/10/2020
  
  * Descrição do Projeto:
  
  <!---------------------Simulação de 2 servo motor controlador pro remote control IR----------------------------->
  	
    Esse projeto faz a simulação do acionamento de dois motores em via do controle remoto e o sensor 
    infravermelho.
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - 1 Arduino Uno;
  - 1 Protoboard;
  - 1 Remote control IR ;
  - 2 Motor de engrenagem;
  - 1 Acionador de motor de ponte H;
  - Sensor infravermelho
  - 1 Bateria de 9V;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
//first Motor
int LeftMotor1 = 2;
int LeftMotor2 = 3;
int RightMotor1 = 4;
int RightMotor2 = 5;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void trunRight() {
  digitalWrite(LeftMotor1, HIGH);
  digitalWrite(LeftMotor2, LOW );
  digitalWrite(RightMotor1, LOW);
  digitalWrite(RightMotor2, HIGH);
}
void trunLeft() {
  digitalWrite(LeftMotor1, LOW);
  digitalWrite(LeftMotor2, HIGH );
  digitalWrite(RightMotor1, HIGH);
  digitalWrite(RightMotor2, LOW);
}
void Forward() {
  digitalWrite(LeftMotor1, HIGH);
  digitalWrite(LeftMotor2, LOW );
  digitalWrite(RightMotor1, HIGH);
  digitalWrite(RightMotor2, LOW);
}

void Backward() { 
  digitalWrite(LeftMotor1, LOW);
  digitalWrite(LeftMotor2, HIGH );
  digitalWrite(RightMotor1, LOW);
  digitalWrite(RightMotor2, HIGH);
  
}

//Forward 0xFD50AF
//Backward 0xFD10EF
//Right 0xFD609F
//LEFT 0xFD20DF

void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receba o próximo valor
  }
  delay(100);

  switch(results.value){
    case 0xFD50AF:Forward();break;
    case 0xFD10EF:Backward();break;
    case 0xFD609F:trunRight();break;
    case 0xFD20DF:trunLeft();break;
    }
}