 /* Projeto Nº 25 -> Simulação de servo motor + LEDs
  *  
  * Author: Thiago Santos Tassinari
  * Data: 06/10/2020
  
  * Descrição do Projeto:
  
  <!---------------------Simulação de transferidor com servo motor + LEDs----------------------------->
  	
    // Os LEDs acesos indicam o seguinte:
    // Verde, motor abriendo la valvula;
    // Vermelho, válvula de fechamento do motor;
    // Amarelo, motor em funcionamento.
    
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - 1 Arduino Uno;
  - 1 Protoboard;
  - 3 LEDs ;
  - 3 resistor de 470Ohms e 3 Resistor de 10KOhm;
  - 1 Servo motor CC;
  - 1 Acionador de motor de ponte H;
  - 1 Button;
  - 2 Interruptores deslizantes;
  - 1 Bateria de 9V;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/

// Variáveis:
// Pressione o botão para alterar o status:
int button = 0; // Pressione o botão para abrir ou fechar a válvula
int interrupt_open = 0;  // Chave limitadora de válvula aberta
int interrupt_close = 0;  // Chave de limite de válvula fechada
int estado_valv = 0; // Status da válvula, 0 inicial, 1 aberta e 2 fechada

// Integrado L293 que precisa de diodos de proteção ou o L293D que já os incorpora
// L293D pin 2 -> D8 -> LED vermelho fechar
// L293D pin 7 -> D9 -> LED verde abrir
// L293D pin 1 -> D10 -> LED amarelo funcionando o motor

void abrir(){
  digitalWrite(8, LOW);  // LED vermelho
  digitalWrite(9, HIGH); // LED verde
  digitalWrite(10, HIGH);  // LED amarelo
}

void fechar(){
  digitalWrite(8, HIGH);  // LED vermelho
  digitalWrite(9, LOW); // LED verde
  digitalWrite(10, HIGH);  // LED amarelo
}

void parar(){
  digitalWrite(8, LOW);  // LED vermelho
  digitalWrite(9, LOW); // Led verde 
  digitalWrite(10, LOW);  // Led amarelo
}

void setup()
   {
    Serial.begin(9600);
    for (int i = 8 ; i<11 ; i++) // Inicia-se os pinos de saída
    pinMode( i, OUTPUT);
    for (int j = 4 ; j<7 ; j++) // Inicia-se os pinos de entrada
    pinMode( j, INPUT);
   }

void loop()
  {
    button = digitalRead(4);  // Leitura digital do pin 4
    interrupt_open = digitalRead(5);  // Leitura digital do pin 5
    interrupt_close = digitalRead(6);  // Leitura digital do pin 6
    Serial.print("Estado da válvula: ");
    Serial.println(estado_valv);
    
    // Estado inicial 0
    if (estado_valv == 0){
      if (interrupt_close == LOW && interrupt_open == HIGH){  
        Serial.println("Valvula abierta en estado inicial, no hace nada");
        parar();
        estado_valv = 1;
      }
      if (interrupt_close == LOW && interrupt_open == LOW){
        Serial.println("Valvula a medio recorrido en estado inicial, debe abrirse");
        abrir();
        estado_valv = 1;
      }
      if (interrupt_open == LOW && interrupt_close == HIGH){
        Serial.println("Valvula cerrada en estado inicial, debe abrirse");
        abrir();
        estado_valv = 1;
      }
    }

    // Recibe orden de cambiar el estado
    if (button == HIGH){
      if (interrupt_open == HIGH && interrupt_close == LOW){
        Serial.println("Valvula abierta y recibe orden de fechar");
        fechar();
        estado_valv = 2;
      }
      if (interrupt_open == LOW && interrupt_close == HIGH){
        Serial.println("Valvula cerrada y recibe orden de abrir");
        abrir();
        estado_valv = 1;
      }
    }

    // Parar el motor cuando llegue al final de carrera
    if (estado_valv == 1 && interrupt_open == HIGH){
      parar(); 
    }
    
    // Parar el motor cuando llegue al final de carrera
    if (estado_valv == 2 && interrupt_close == HIGH){
      parar();        
    }
  }
