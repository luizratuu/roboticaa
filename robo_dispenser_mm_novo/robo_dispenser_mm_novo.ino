#include "VarSpeedServo.h"
#include <Ultrasonic.h>

const int echoPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 8; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA) 
 
VarSpeedServo servo1;

static int s1 = 0;

int distancia; //CRIA UMA VARIÁVEL CHAMADA "distancia" DO TIPO INTEIRO

int repetir;

Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS

void setup()
{

  Serial.begin(9600);
  servo1.attach(11);
 
  servo1.write(0);

pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAÍDA (ENVIA)

}
void loop()
{

 if (distancia <=20) {
  
delay(100);

for (s1 = 80; s1 >= 0; s1 -=1) {
  servo1.write(s1);
  delay(5);
}

delay(500);

for (s1 = 0; s1 <=80; s1 +=1) {
  servo1.write(s1);
  delay(5);
}

  }
  
distancia = (ultrasonic.Ranging(CM)); // VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
delay(100); 

}
