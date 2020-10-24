/* Descrição do Projeto
 * 
 * O objetivo deste projeto é acionar um buzzer utilizando as funções tone e noTone. O buzzer é um dispositivo que permite a geração de sinais 
 * sonoros (bipes) como aqueles encontrados em computadores. Para produzir o som, um buzzer vibra por meio de um oscilador. Essa oscilação é determinada 
 * por uma frequência que, por sua vez, define um som específico. 
 */

 /* Componentes necessários
  *  
  *  • 1 Arduino; 
  *  • 1 buzzer; 
  *  • 1 resistor de 220 ohms (vermelho, vermelho, marrom) ou de 330 ohms (laranja, laranja, marrom); 
  *  • 1 protoboard; 
  *  • jumper cable. 
  */
  
int BUZZER = 8; // Pino ao qual o buzzer está conectado
int numNotas = 10;

// Vetor de inteiros contendo diversas frequências
int notas[] = { 261, 277, 294, 311, 330, 349, 370, 392, 415, 440 };
// Notas    C  #C    D   #D    E    F    #F   G    #G   A
void setup()
{
  pinMode(BUZZER, OUTPUT);
}

void loop(){
  for (int i = 0; i < numNotas; i++) {
    tone(BUZZER, notas[i]);
    delay(500);
  }
  noTone(BUZZER);
}
