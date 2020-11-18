  /* Projeto Nº 19
  
  *  
  * Author: Thiago Santos Tassinari
  * Data: 30/10/2020
  * Descrição do Projeto:
  
  <!----------------------------Game Genius----------------------------->
  
  Um circuito utilizando arduino UNO para simulação de um semáforo acionado para parar
  ao pedestre querer atravessar a rua. Apenas precisa apertar o botão para mudar a 
  função dos LEDs.

<!-----------------------Componentes necessários------------------------------------->

  - 1 USB
  - 1 Protoboard;
  - 4 Leds;
  - 4 Buttons;
  - 1 ATTiny;
  - 1 Piezo;
  - 5 Resistores de 2.2KOhm
  - 4 Resistor de 220Ohm
  - Jumpers
  
<------------------------------------------------------------------------------------->  
*/

// Definindo os pinos
#define PIN_LED_BUTTON_1  0   // Button 0 input/LED output
#define PIN_LED_BUTTON_2  1   // Button 1 input/LED output
#define PIN_LED_BUTTON_3  2   // Button 2 input/LED output
#define PIN_LED_BUTTON_4  3   // Button 3 input/LED output
#define PIN_PIEZO         4   // Piezo buzzer output

#define LED_BUTTON_COUNT  4   // Number of LEDs & buttons

static int buttonLookup[LED_BUTTON_COUNT] = { PIN_LED_BUTTON_1, PIN_LED_BUTTON_2, PIN_LED_BUTTON_3, PIN_LED_BUTTON_4 };
static long gameSeed;

// Retorna o período em microssegundos do tom de meio ciclo para cada botão.
int ledButtonHalfPeriod(int button) {
  switch (button) {
    case PIN_LED_BUTTON_1:
      return 1911;
    case PIN_LED_BUTTON_2:
      return 1703;
    case PIN_LED_BUTTON_3:
      return 1517;
    case PIN_LED_BUTTON_4:
      return 1432;
  }
  return 3822;
}

bool checkButtonPush(int button) {
  bool resultado = false;
  pinMode(button, INPUT);   // Definir botão como entrada
  digitalWrite(button, HIGH); // Enable pullup
  
  int halfPeriod = ledButtonHalfPeriod(button);
  
  while (digitalRead(button) == LOW) {
    // O botão está sendo pressionado
    resultado = true;
    digitalWrite(PIN_PIEZO, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(PIN_PIEZO, LOW);
    delayMicroseconds(halfPeriod);
  }
  return resultado;
}

int getButtonPush(void) {
  for (int i = 0; i < LED_BUTTON_COUNT; ++i) {
    if (checkButtonPush(buttonLookup[i])) {
      return i;
    }
  }
  return -1;
}

void displayLightAndSound(int led, int duration) {
  if (led >= 0) {
    pinMode(led, OUTPUT);   // Definir pino de cátodo led como saída
    digitalWrite(led, LOW);   // e dirigir baixo (para ligar o LED).
  }
  
  int halfPeriod = ledButtonHalfPeriod(led);
  long cycleCount = (long)duration * 500;
  cycleCount /= halfPeriod;
  for (; cycleCount > 0; --cycleCount) {
    digitalWrite(PIN_PIEZO, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(PIN_PIEZO, LOW);
    delayMicroseconds(halfPeriod);
  }
  
  if (led >= 0) {
    pinMode(led, INPUT);      // Definir pino de cátodo led como entrada
    digitalWrite(led, HIGH);  // e puxe para cima (para desligar o LED).
  }
}

void startUpLightsAndSound(void) {
  // Luzes e som de inicialização
  displayLightAndSound(PIN_LED_BUTTON_1, 100);
  displayLightAndSound(PIN_LED_BUTTON_2, 100);
  displayLightAndSound(PIN_LED_BUTTON_3, 100);
  displayLightAndSound(PIN_LED_BUTTON_4, 100);

  // Aguarde até que o botão seja pressionado para continuar
  while (getButtonPush() < 0) {
    delay(100);
  }
  
  // Atrase um pouco antes de começar
  delay(500);
}


// A rotina de configuração é executada uma vez quando você pressiona reset:
void setup() {
  // Definir pinos de botão como entrada
  pinMode(PIN_LED_BUTTON_1, INPUT);
  pinMode(PIN_LED_BUTTON_2, INPUT);
  pinMode(PIN_LED_BUTTON_3, INPUT);
  pinMode(PIN_LED_BUTTON_4, INPUT);
  
  // Defina o pino piezo como saída
  pinMode(PIN_PIEZO, OUTPUT);

  // Luzes e som de inicialização
  startUpLightsAndSound();

  // Randomize o primeiro jogo
  gameSeed = micros();
}

void loop() {
  static int sequenceLength = 1;
  int i;
  
  // Exibir sequência atual
  randomSeed(gameSeed);
  for (i = sequenceLength; i > 0; --i) {
    displayLightAndSound(buttonLookup[random(LED_BUTTON_COUNT)], 250);
    delay(250);
  }
  
  randomSeed(gameSeed);
  for (int matches = 0; matches < sequenceLength; ++matches) {
    int button = -1;
    int timeout;
    // Espere até que o jogador pressione um botão (com tempo limite de 3 segundos)
    for (button = -1, timeout = 30; timeout && button < 0; --timeout) {
      button = getButtonPush();
      delay(100);
    }
  
    // Verifique se o botão correto foi pressionado
    if (button != random(LED_BUTTON_COUNT)) {
      // Toque um som triste e comece um novo jogo
      displayLightAndSound(-1, 1000);
      gameSeed = micros();
      delay(1000);
      sequenceLength = 0;
      startUpLightsAndSound();
    }
  }
  ++sequenceLength;
  delay(1000);
}