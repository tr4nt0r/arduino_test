#include <DHT.h>
#include <DHT_U.h>




#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {

delay(2000);

float Luftfeuchtigkeit = dht.readHumidity();

float Temperatur = dht.readTemperature();

Serial.print("Luftfeuchtigkeit: ");
Serial.print(Luftfeuchtigkeit);
Serial.println(" %");

Serial.print("Temperatur: ");
Serial.print(Temperatur);
Serial.println("° C");

}
