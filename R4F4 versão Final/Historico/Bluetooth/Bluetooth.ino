int IN1 = 4;
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
  char serial = Serial.read ();

// ANDAR PARA FRENTE
    if(serial=='W')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
// ANDAR PARA TRAS
    if(serial=='S')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }   
// ANDAR PARA ESQUERDA
    if(serial=='A')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    } 
// ANDAR PARA DIREITA
    if(serial=='D')
    {
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }  
// STOP COM ROLLING STONES 
    if(serial=='Q')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }  


 
}

