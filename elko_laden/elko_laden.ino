

float spannung;
int i = 0;
const int ROT = 3;
const int GRUEN = 5;
const int BLAU = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(0, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  while (i <= 650) {
//    spannung = analogRead(A1);
//    spannung = spannung / 1023.0 * 5.0;
//
//    Serial.print(5);
//    Serial.print(" ");
//    Serial.println(spannung);
//
//    delay(10);
//    i++;
//  }


switch(i) {
  case 0:
    analogWrite(ROT, 255);
    break;
  case 1:
    analogWrite(GRUEN, 255);
    break;
  case 2:
    analogWrite(BLAU, 255);
    break;
   }
   
  delay(1000);
  analogWrite(ROT, 0);
  analogWrite(GRUEN, 0);
  analogWrite(BLAU, 0);

  i = (i==2) ? 0 : i+1;
}
