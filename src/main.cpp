#include <Arduino.h>
#include <Servo.h>

void setup() {
    pinMode(13,OUTPUT);
    Servo myServo;
    myServo.attach(10);
}

void loop() {
    
}
