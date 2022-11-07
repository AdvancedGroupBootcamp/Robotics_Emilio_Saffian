#include <Wire.h>
int INTERVAL_MESSAGE1 = 2000;
int  INTERVAL_MESSAGE2 = 955;
int  INTERVAL_MESSAGE3 = 0; 


const int IN1 = 2;
const int IN2 = 3;

const int IN3 = 4;
const int IN4 = 5;

const int ENA = 9;
const int ENB = 10;

int speedControl = 127;
bool enable_a = true;
bool enable_b = false;
unsigned long time_now = 0;
void setup() 
{

  Serial.begin(115200);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
}

int      runs = 1;

void loop()
{

    while(millis() < INTERVAL_MESSAGE1*runs + INTERVAL_MESSAGE2*(runs-1)  ){
        Serial.println(1);
        
        spin(0, speedControl);

    }
    while(millis() < INTERVAL_MESSAGE1*runs + INTERVAL_MESSAGE2*(runs)   ){
        analogWrite(ENA, 100);
        analogWrite(ENB, 120); 
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    runs += 1;

}
void spin(int direction, int speed){
  //control speed 
  analogWrite(ENA, 255);
  analogWrite(ENB, 200); 
//control direction 1 means clockwise in our circuit
  if(direction == 1){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }
  else{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  }

}



