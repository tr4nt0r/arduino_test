
int dualzahl;
float spannung;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

dualzahl = analogRead(A2);
spannung = dualzahl*5.0/1023;
Serial.println(spannung);

delay(100);

}
