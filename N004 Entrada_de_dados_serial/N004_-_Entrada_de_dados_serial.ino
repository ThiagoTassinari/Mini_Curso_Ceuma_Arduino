/* Descrição do Projeto
 *
 * Além de enviar dados pela porta serial, o Arduino também poderá recebê-los. A partir de um dado recebido 
 * pela entrada serial, vamos determinar se o LED deverá ser ligado ou desligado.
 */

/*  Componentes necessários

 *  • 1 Arduino; 
 *  • 1 resistor de 220 ohms (vermelho, vermelho, marrom) ou de 330 ohms (laranja, laranja, marrom); 
 *  • 1LED; 
 *  • 1 protoboard; 
 *  • jumper cable. 
 */

int LED = 13;
int input = 0;

void setup() {
  // Inicializar e definir a velocidade de comunicação da porta serial.
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Digite 1 para acendere o LED ou 0 para apagar");
}

void loop() {
  // Determinar se há bytes na entrada serial aguardando para serem lidos.
  if (Serial.available() > 0) {
    // Se o retorno do valor for maior que 0, então ler o byte que está na entrada serial
    input = Serial.read();

    //Informar o valor que foi recebido
    Serial.print("Recebido - Valor com caractere: ");
    Serial.print((char) input);
    Serial.print(", valor numérico: ");
    Serial.println(input, DEC);

    // Acender ou apagar o LED de acordo com o valor recebido na entrada serial
    if (input == '0')
      digitalWrite(LED, LOW);
    else if (input == '1')
      digitalWrite(LED, HIGH);
    else
      Serial.println("Por favor, digite apenas 0 ou 1!");
  }
}
