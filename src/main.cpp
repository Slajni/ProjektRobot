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

int getLowerDifference()
{

    if(valstart > 511)
        return 1023-valstart;
    else
        return valstart;

}

void getDirection(int value)
{

    if(value < valstart + 10 && value > valstart - 10)
        direction = 0;
    else if(value > valstart + 10)
        direction = 1;
    else if(value < valstart - 10)
        direction = -1;

}

int giveMappedValueSpeed(int value)
{
    if(valstart > 511)
        return map(value,valstart-difference,valstart,0,255);
    else if(valstart <= 511)
        return map(value,0,valstart,0,255);if(value > valstart + 10)

    return 0;
}


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
    //myServo.attach(10);
    Serial.begin(9600);
    pinMode(A0,INPUT);
    //myServo.write(90);
    valstart = 533;//analogRead(A0);
    difference = getLowerDifference();
}

void loop() {

    
    val = analogRead(A0);
    speed = giveMappedValueSpeed(val);
    getDirection(val);
    move(direction,speed);
    Serial.println(val);
    
    delay(50);


}
