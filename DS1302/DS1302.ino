#include <Time.h>
#include <TimeLib.h>

// Timur Maksiomv 2014
//
// A quick demo of how to use DS1302-library to make a quick
// clock using a DS1302 and a 16x2 LCD.
//
// I assume you know how to connect the DS1302 and LCD.
// DS1302:  CE pin    -> Arduino Digital 10
//          I/O pin   -> Arduino Digital 9
//          SCLK pin  -> Arduino Digital 8
//          VCC pin   -> Arduino Digital 33
//          GND pin   -> Arduino Digital 35
//
// LCD:     DB7       -> Arduino Digital 7
//          DB6       -> Arduino Digital 6 
//          DB5       -> Arduino Digital 5
//          DB4       -> Arduino Digital 4
//          E         -> Arduino Digital 9
//          RS        -> Arduino Digital 8

#include <DS1302RTC.h>
#include <Time.h>

// Init the DS1302
// Set pins:  CE, IO,CLK
DS1302RTC RTC(8, 7, 6);

void setup()
{

  //digitalWrite(DS1302_VCC_PIN, HIGH);
  //pinMode(DS1302_VCC_PIN, OUTPUT);

  Serial.begin(9600);


  // Check clock oscillation  
  if (RTC.haltRTC())
    Serial.println("Clock stopped!");
  else
    Serial.println("Clock working.");

  // Check write-protection
  if (RTC.writeEN())
    Serial.println("Write allowed.");
  else
    Serial.println("Write protected.");

  delay ( 2000 );

  // Setup Time library  
  setSyncProvider(RTC.get); // the function to get the time from the RTC
  if(timeStatus() == timeSet)
    Serial.println(" Ok!");
  else
    Serial.println(" FAIL!");

  delay ( 2000 );
}

void loop()
{
  // Display time centered on the upper line
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());

  // Display abbreviated Day-of-Week in the lower left corner
  Serial.println(dayShortStr(weekday()));

  // Display date in the lower right corner
  Serial.print(day());
  Serial.print("-");
  Serial.print(month());
  Serial.print("-");
  Serial.println(year());

  // Warning!
  if(timeStatus() != timeSet) {
    Serial.println(F("RTC ERROR: SYNC!"));
  }

  delay ( 1000 ); // Wait approx 1 sec
}

