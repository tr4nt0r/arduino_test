
int voltagePoti;
int ledActive;
void setup() {
  // put your setup code here, to run once:

pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

voltagePoti = analogRead(A0);

ledActive = map(voltagePoti, 0, 1023, 1, 5);

switch(ledActive){
  case 1:
    digitalWrite(13, HIGH);
    break;
  case 2:
    digitalWrite(12, HIGH);
    break;
  case 3:
    digitalWrite(11, HIGH);
    break;
  case 4:
    digitalWrite(10, HIGH);
    break;
  case 5:
    digitalWrite(9, HIGH);
    break;  
}




}
