/*THIS TUTORIAL USED GSM SIM900A MINI V3.9.2
 
  Connect 5VT to D9 and 5VR to D10
  Feed GSM SIM900A with Arduino's 5V

  Code by OTOBONG FRIDAY
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
String  msg = "";
const int led = 7;
String nmsg = "";

void setup()
{
  pinMode(led, OUTPUT);
  
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM900A BEGIN");
 
  delay(100);

  mySerial.println("AT+CMGF=1\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  
  mySerial.println("AT+CNMI=2,2,0,0,0\r"); // AT Command to recieve a live SMS
 
  delay(1000);
  digitalWrite(led , HIGH);
  delay(1000);
  digitalWrite(led , LOW);
  delay(1000);
  digitalWrite(led , HIGH);
  delay(1000);
  digitalWrite(led , LOW);
  delay(1000);
}

void loop(){  
    
  if (mySerial.available()>0) {
  msg = mySerial.readString();
 
 Serial.print(msg);
 //Serial.print(nmsg);
  }
 
 if(msg.indexOf("ON")>= 0){
  digitalWrite(led , HIGH);
   }
   
  if(msg.indexOf("OFF")>= 0){
  digitalWrite(led , LOW);
 }

} 
