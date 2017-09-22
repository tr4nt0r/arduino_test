


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float spannung = analogRead(A2) * 5.0 / 1023;
float spannungA0 = analogRead(A0) * 5.0 / 1023;
float spannungA1 = analogRead(A1) * 5.0 / 1023;

  Serial.println();

  Serial.print("Spannung an Diode: ");
  Serial.print(spannung - spannungA0);
  Serial.print(" Strom: ");
  Serial.print(spannungA1/4.9);
  Serial.println(" A");
  delay(1000);

}
