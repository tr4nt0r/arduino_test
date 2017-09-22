#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

Adafruit_BMP085 bmp;
LiquidCrystal_I2C lcd_anzeige(LCD_ADDRESS, LCD_COLS, LCD_ROWS);


void setup() {

  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
  lcd_anzeige.begin();
  lcd_anzeige.setCursor(0, 0);
  lcd_anzeige.print("Initializing...");
  delay(2000);
}

void loop() {
  lcd_anzeige.clear();
  lcd_anzeige.setCursor(0, 0);
  lcd_anzeige.print("Temperature");
  lcd_anzeige.setCursor(0, 1);
  lcd_anzeige.print(bmp.readTemperature());
  lcd_anzeige.print(" *C");
  delay(2000);
  lcd_anzeige.clear();
  lcd_anzeige.setCursor(0, 0);
  lcd_anzeige.print("Pressure");
  lcd_anzeige.setCursor(0, 1);
  lcd_anzeige.print(bmp.readPressure());
  lcd_anzeige.print(" Pa");
  delay(2000);
  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  lcd_anzeige.clear();
  lcd_anzeige.setCursor(0, 0);
  lcd_anzeige.print("Altitude");
  lcd_anzeige.setCursor(0, 1);
  lcd_anzeige.print(bmp.readAltitude());
  lcd_anzeige.print(" meters");
  delay(2000);




  lcd_anzeige.clear();
  lcd_anzeige.setCursor(0, 1);
  lcd_anzeige.print(bmp.readSealevelPressure());
  lcd_anzeige.print(" Pa");

  String sealevelPressureTxt = "Pressure at sealevel (calculated)";
  size_t  scrollDigits = sealevelPressureTxt.length() - 16;

  for (size_t positionCounter = 0; positionCounter <= scrollDigits; positionCounter++) {
    //lcd_anzeige.scrollDisplayLeft();
    lcd_anzeige.setCursor(0, 0);
    lcd_anzeige.print(sealevelPressureTxt.substring(positionCounter));
    delay(150);
  }


  delay(2000);
  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
  lcd_anzeige.clear();
  lcd_anzeige.setCursor(0, 0);
  lcd_anzeige.print("Real altitude");
  lcd_anzeige.setCursor(0, 1);
  lcd_anzeige.print(bmp.readAltitude(101500));
  lcd_anzeige.print(" meters");

  //lcd_anzeige.print(bmp.readPressure());

  //Serial.println();
  delay(2000);
}

class myLiquidCrystal : LiquidCrystal_I2C {
  public:
    void setText(const String text[], int duration, bool scrollEnabled = true) {

      clear();
      //first print all text
      for (size_t i = 0; i < LCD_ROWS; i++) {
        this->setCursor(0, i);
        this->print(text[i]);
      }

      size_t scrollDigits = this->maxStringLength(text);

      //then scroll the rows that are longer than display
      for (size_t positionCounter = 0; positionCounter <= scrollDigits; positionCounter++) {
        for (size_t i = 0; i < LCD_ROWS; i++) {
          if (text[positionCounter].length() > LCD_COLS) {
            this->setCursor(0, i);
            this->print(text[positionCounter].substring(positionCounter));
          }
        }
        delay(150);
      }


      delay(duration);
    }

    private:
      size_t maxStringLength(const String text[]) {
        size_t maxLength = 0;
        for (size_t i =0; i < sizeof(text) - 1; i++) {
          maxLength = (text[i].length() > maxLength) ? text[i].length() : maxLength;
        }
        return maxLength;
      }

};

