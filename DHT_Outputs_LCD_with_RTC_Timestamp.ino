//By Otobong Peter
//Standard DHT Libraries
#include <SimpleDHT.h>

//RTC Libraries
#include "RTClib.h"
RTC_DS1307 rtc;


//LCD Libraries
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
// for DHT22, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT22 = 2;
SimpleDHT22 dht22(pinDHT22);

void setup() {
  Serial.begin(9600);
  lcd.init(); // initialize the lcd 
  lcd.backlight();
  rtc.begin();

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
 
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT22...");

  DateTime time = rtc.now();
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err=");
    Serial.println(err);
    delay(2000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" RH%");
  

  if (dht22.read(&temperature, &humidity, NULL)>0) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
//    while (dht22.read(&temperature, &humidity, NULL)>0) {
     // display each character to the LCD
     lcd.print("Temp=");
     lcd.print((int)temperature);
     lcd.print("C");
      lcd.print(" ");
     lcd.print("RH=");
     lcd.print((int)humidity);
     lcd.print("%") ;
     lcd.setCursor(0,2);
     //Full Timestamp... Shows the time of Change of Parameters
     lcd.print(String("DateTime::TIMESTAMP_TIME:\t")+time.timestamp(DateTime::TIMESTAMP_TIME));

     //lcd.clear();
     delay(1000);
  }
  // DHT22 sampling rate is 0.5HZ.
  delay(1000);
}
