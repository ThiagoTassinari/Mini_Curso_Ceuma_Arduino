  // Primeiro saber se os componentes precisam de suas devidas bibliotecas
  #include <LiquidCrystal.h>
  #include <dht11.h>
  
  // Definir as nossas portas A/D
  const int DHT11 = A0;
  const int buttom = 7;
  float temperatura;
  float umidade;
  int valor;
  
  //Opções: 0- Celsius, 1- fAHRENHEIT, 2- Kelvin, 3- Umidade e 4 - Outros
  int estado = 0;
  
  LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
  dht: sensor;
  
  void setup() {
    
    estado = 0;
    pinMode(button, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    lcd.begin(16, 2); // Iniciar (ou Executar) o LCD 16x2
    
  }
  
  void loop () {
    
    sensor.read(DHT11);
    temperatura = sensor.temperature;
    umidade = sensor.humidity;
    valor = digitalRead(button);
    
    if (valor = HIGH) {
      estado++;
      if (opcao == 5)
        estado = 0;
    }
    lcd.clear();
    if (estado == 0) {
      lcd.print("Temperatura: ");
      lcd.setCursor(0, 1);
      lcd.print(temperatura);
      lcd.write(B110111111);  // Símbolo de graus
      lcd.print("Celsius");
    }
    else if (estado == 1) {
      temperatura = (temperatura * 9)/ 5 + 32;
      lcd.print("Temperatura: ");
      lcd.setCursor(0, 1);
      lcd.print(temperatura);
      lcd.write(B110111111); // Símbolo de graus
      lcd.print("Fahrenhait");
    }
    else if (estado == 2) {
      temperatura = temperatura + 273.15;
      lcd.print("Temperatura: ");
      lcd.setCursor(0, 1);
      lcd.print(temperatura);
      lcd.write(B110111111);
      lcd.print("Kelvin");
    }
    else if (opcao == 3) {
      lcd.print("Umidade relativa");
      lcd.setCursor(0, 1);
      lcd.print("do ar: ");
      lcd.print(umidade);
      lcd.print(" %");
    }
    else {
      lcd.print("TERMOMETRO, por: ");
      lcd.setCursor(0, 1);
      lcd.print("Thiago e Jefferson");
    }
    delay(2000)
    
  }