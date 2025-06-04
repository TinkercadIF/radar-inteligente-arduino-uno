const int sensor1 = 11;
const int sensor2 = 9;
const int ledVermelho = 8;
const int ledVerde = 12;
unsigned long tempoInicio = 0;
unsigned long tempoFinal = 0;
const int conta = 0;
int carrosVerdes = 0;
int carrosVermelhos = 0;

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  if (digitalRead(sensor1) == HIGH) {
    tempoInicio = millis();
  	}

  if (digitalRead(sensor2) == HIGH) {
    tempoFinal = millis();
    
     if ((tempoFinal - tempoInicio)  < 2000) {
        digitalWrite(ledVermelho, HIGH);
        delay(1000);
        digitalWrite(ledVermelho, LOW);
      	carrosVermelhos++;
     }
      else {
        digitalWrite(ledVerde, HIGH);
        delay(1000);
        digitalWrite(ledVerde, LOW);
        carrosVerdes++;
      }
  }
    
  	Serial.print("Conta: ");
  	Serial.print(tempoFinal - tempoInicio);
    Serial.print(" - TEMPO INICIAL:");
  	Serial.print(tempoInicio);
  	Serial.print(" - TEMPO FINAL:");
  	Serial.print(tempoFinal);
    Serial.print(" - Carros verdes: ");
    Serial.print(carrosVerdes);
    Serial.print(" - Carros vermelhos: ");
    Serial.println(carrosVermelhos);
    delay(1000);
  }
