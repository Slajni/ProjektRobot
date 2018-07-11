#include <Arduino.h>
#include <Servo.h>
#include <math.h>


int val = 0;
Servo myServo;
int angle;
int direction = 0;
int valstart = 0;
int difference = 0;
int speed = 0;




// 3,4 - engines, 6 - pwl for engines
void move(int direction, int speed)
{

    switch(direction)
    {
        case 0:
        {
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
        }
        case -1:
        {
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            analogWrite(6, speed);
        }
        case 1:
        {
            digitalWrite(4, LOW);
            digitalWrite(3, HIGH);
            analogWrite(6,speed);   
        }
    }


}

void setup() {

    pinMode(3,OUTPUT); // engine
    pinMode(4,OUTPUT); // engine
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    pinMode(6,OUTPUT); // pwl engine
    pinMode(10,OUTPUT); // serwo
 
    Serial.begin(9600);
    pinMode(A0,INPUT);

    speed=200;
}

void loop() {

    
    val = analogRead(A0);
    
    if(val>550) 
    {
         digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            analogWrite(6, speed);
    }
    else if(val<500) {
        
         digitalWrite(4, LOW);
            digitalWrite(3, HIGH);
            analogWrite(6, speed);
    }
    else if (val>500 && val<550) {
         digitalWrite(3, LOW);
            digitalWrite(4, 0);
            analogWrite(6, 0);
    }

   // move(direction,speed);
    Serial.println(val);
    
    delay(50);


}
