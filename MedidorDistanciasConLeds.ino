// Sensor de ultrasonidos HR-SC04 con leds
// David Ortega Cuadrado - dorcu.com
// 6 de Abril de 2014
// hola@dorcu.com

#define trigPin 7
#define echoPin 8
#define led 11
#define led2 10

int dis = 10;

// Librerias necesarias para el funcionamiento
#include "Ultrasonic.h"

// Declaramos el sensor ultrasonido en los pines digitales elegidos
Ultrasonic ultrasonido(trigPin,echoPin); 

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int distancia;
  
  distancia = ultrasonido.Ranging(CM);
  
  if (distancia < dis){
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    Serial.print("Encender LED rojo ")+Serial.println(ultrasonido.Ranging(CM));
  } else {
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
    Serial.print("Encender LED verde ")+Serial.println(ultrasonido.Ranging(CM));
  }
  
  delay(500);
}