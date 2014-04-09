// Sensor de ultrasonidos HR-SC04 con leds
// David Ortega Cuadrado - dorcu.com
// 6 de Abril de 2014
// hola@dorcu.com

// Definimos los pines que vamos a usar
#define trigPin 7
#define echoPin 8
#define led 11
#define led2 10

int dis = 10; // Establecemos la distancia en cm para la comprobacion

// Librerias necesarias para el funcionamiento
#include "Ultrasonic.h"

// Declaramos el sensor ultrasonido en los pines digitales elegidos
Ultrasonic ultrasonido(trigPin,echoPin); 

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); // Establecemos el pin trig como salida
  pinMode(echoPin, INPUT); // Establecemos el pin echo como entrada
  pinMode(led, OUTPUT); // Establecemos el led verde como salida
  pinMode(led2, OUTPUT); // Establecemos el rojo verde como salida
}

void loop() {
  int distancia;

  distancia = ultrasonido.Ranging(CM);

  if (distancia < dis){
    digitalWrite(led,LOW); // Apagamos el led verde
    digitalWrite(led2,HIGH); // Encendemos el led rojo
    Serial.print("Led rojo - Distancia: ");
    Serial.print(ultrasonido.Ranging(CM)); 
    Serial.println(" cm");
  } else {
    digitalWrite(led,HIGH); // Encendemos el led verde
    digitalWrite(led2,LOW); // Apagamos el led rojo
    Serial.print("Led verde - Distancia: ");
    Serial.print(ultrasonido.Ranging(CM)); 
    Serial.println(" cm");
  }

  delay(500);
}
