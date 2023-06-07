
#define sensor_lum A1
#define sensor_temp A0
#define sensor_uhm A0

;int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup () 
{
 Serial.begin(9600);
 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
}

void loop () 
{
  int leitura_lum = 0;
  int leitura_temp = 0;
  int leitura_uhm = 0;
  
  leitura_lum = analogRead(sensor_lum);
  leitura_temp = analogRead(sensor_temp);
  leitura_uhm = analogRead(sensor_uhm);
  
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

  }
 
}

