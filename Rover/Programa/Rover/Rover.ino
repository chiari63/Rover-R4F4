#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(0, 1);
Servo servo;

int IN1 = 5;
int IN2 = 6;
int IN3 = 10;
int IN4 = 11;

void setup () 
{
 Serial.begin(9600);
 bluetooth.begin(115200);
 servo.attach(12);
 servo.write(90);
 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);

}

void loop () 
{  
  char serial = Serial.read ();

  switch (serial){
   //esquerda
    case 'L':
      servo.write(120);
    break;
    
    //direita
    case 'R':
      servo.write(60);
    break;

    //frente
    case 'F':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      servo.write(90);
    break;

    //esquerda frente
    case 'G':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      servo.write(120);
    break;
    case 'I':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      servo.write(60);
    break;

    //tras
    case 'B':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      servo.write(90);
    break;

    //tras esquerda
    case 'H':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      servo.write(120);
    break;

    // tras direita
    case 'J':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      servo.write(90);
    break;

    // parado
    case 'S':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    break;
  }
}

  
