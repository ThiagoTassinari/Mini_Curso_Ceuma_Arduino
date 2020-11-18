/* CONCEITO IMPORTANTE
 *  
 * O arduino possui capacidade de comunicacão serial. Dessa forma, é possível enviar e receber dados em um sketch. 
 * Assim, os projetos criados podem interagir com outros dispositivos de hardware.
 */

 /* Projeto Nº 03 -> Enviando dados para a saída serial
  * Descrição do Projeto:
  * 
  * O objetivo deste projeto é enviar um valor, colocado em uma entrada analógica por meio de um potenciômetro, pela porta 
  * de comunicação serial do Arduino. Em seguida, demonstraremos como utilizar a opcção Monitor Serial, disponível no ambiente 
  * de desenvolvimento do Arduino, para visualizar os valores enviados.
  */ 

 /* Componentes necessários 
  *
  *   • 1 Arduino; 
  *   • 1 potenciômetro; 
  *   • 1 resistor de 220 ohms (vermelho, vermelho, marrom) ou de 330 ohms (laranja,laranja, marrom); 
  *   • 1 LED;
  *   • 1 protoboard;
  *   • jumper cable.
  */

  // Controla a intensidade luminosa de um LED através do uso de um potenciômetro conectado a uma entrada analógica

  // Pino analógico do arduino ao qual será ligado o potenciômetro 
  int POT = A1;

  // Pino do arduino ao qual será conectado o LED
  int LED = 9;
  int valor = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  valor = analogRead(POT);
  if(valor > 0) {
    //Acende o LED com inrtensidade proporcional ao valor obtido
    analogWrite(LED, valor/4);

    // Exibie no Serial Monitor o valor ontido do potenciômetro
    Serial.println(valor);
    Serial.print(", ");
  }
}
