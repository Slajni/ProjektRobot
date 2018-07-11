#include <Arduino.h>
#include <Servo.h>
#include <math.h>


int val = 0;
Servo myServo;
int angle;

void setup() {

   // pinMode(13,OUTPUT);
    myServo.attach(10);
    Serial.begin(9600);
    pinMode(A0,INPUT);
    myServo.write(90);
}

void loop() {

    val = analogRead(A0);
    val = map(val, 0, 1023, 0, 180);
    
    myServo.write(val);
    Serial.println(val);
    
    delay(50);


}
