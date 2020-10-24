int trig = 7;
int echo = 6;

float distance;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);	// Monitorar           
}
               
void loop(){
	
  digitalWrite(trig, LOW);	// Desligado
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);	//Acionar o trigger
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  distance = pulseIn(echo, HIGH);	// Captura da duração de um pulso em um pino
  distance = distance/58;
    
  Serial.println(distance);
  
}
