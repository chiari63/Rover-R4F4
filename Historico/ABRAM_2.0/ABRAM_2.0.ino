#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN A4
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
int ldrPin = A0; 
int ldrValor = 0;

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
float h = 0;
float t = 0;
float hic = 0;
byte  val_c;
byte  val_d;
byte  val_u;
byte  val_dc;
byte  val_cm;
int   valor_o;

float LUX = 0;

void setup () 
{
 Serial.begin(9600);
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

    case 'v':          //Manda sensores
    h = dht.readHumidity();
    t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
      return;}
    hic = dht.computeHeatIndex(t, h, false);

    valor_o = hic * 10;
    val_c = valor_o / 1000;
    valor_o = valor_o - val_c * 1000;
    val_d = valor_o / 100;
    valor_o = valor_o - val_d * 100;
    val_u = valor_o / 10;
    valor_o = valor_o - val_u * 10;
    val_dc = valor_o / 1;

    Serial.print(val_c);
    Serial.print(val_d);
    Serial.print(val_u);
    Serial.print(val_dc);

    valor_o = h * 10;
    val_c = valor_o / 1000;
    valor_o = valor_o - val_c * 1000;
    val_d = valor_o / 100;
    valor_o = valor_o - val_d * 100;
    val_u = valor_o / 10;
    valor_o = valor_o - val_u * 10;
    val_dc = valor_o / 1;

    Serial.print(val_c);
    Serial.print(val_d);
    Serial.print(val_u);
    Serial.print(val_dc);


    LUX = analogRead(A3);
    LUX = LUX*100;
    LUX = LUX/680;
    LUX = 100 - LUX;

    valor_o = LUX * 10;
    val_c = valor_o / 1000;
    valor_o = valor_o - val_c * 1000;
    val_d = valor_o / 100;
    valor_o = valor_o - val_d * 100;
    val_u = valor_o / 10;
    valor_o = valor_o - val_u * 10;
    val_dc = valor_o / 1;

    Serial.print(val_c);
    Serial.print(val_d);
    Serial.print(val_u);
    Serial.print(val_dc);
    break;

  }
 
}

