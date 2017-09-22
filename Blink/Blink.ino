/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

const int pinLED = 11;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pinLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("LED: An");
  delay(1000);              // wait for a second
  digitalWrite(pinLED, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("LED: Aus");
  delay(1000);              // wait for a second
}
