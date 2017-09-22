#include <Servo.h>

Servo Servo1;
int voltagePoti;
int angleServo1;

void setup() {
  // put your setup code here, to run once:
Servo1.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
voltagePoti = analogRead(A0);
angleServo1 = map(voltagePoti, 0, 1023, 0, 180);

Servo1.write(angleServo1);
Serial.println(angleServo1);
}
