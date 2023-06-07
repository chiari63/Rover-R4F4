#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN A4
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial bluetooth(0, 1);

int ldrPin = A0; 
int ldr = 0;
long int count = 0;

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
float h = 0;
float t = 0;
int   valor_o;

float LUX = 0;

void setup () 
{
 Serial.begin(9600);
 bluetooth.begin(115200);
 dht.begin();
 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
}

void loop () 
{  
  char serial = Serial.read ();
  switch (serial)
  {
// ANDAR PARA FRENTE

    case 'w':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    break;
    
// ANDAR PARA TRAS

   case 's':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    break;
    case 'z':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    break;
    
// ANDAR PARA ESQUERDA

    case 'a':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    break;
    case 'x':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    break;
    
// ANDAR PARA DIREITA

    case 'd':
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    break;
    case 'y':
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    break;
// STOP COM ROLLING STONES 

    case 'q':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    break;

    h = dht.readHumidity();
    t = dht.readTemperature();
    ldr = analogRead (A3);
    
    case 'v':
      h = dht.readHumidity();
      t = dht.readTemperature();
      ldr = analogRead (A3);
      
      Serial.print("Temperatura: ");
      Serial.println(t);
      Serial.print("Umidade: ");
      Serial.println(h);
      Serial.print("Luminosidade: ");
      Serial.println(ldr);
    break;
  }
}

  

