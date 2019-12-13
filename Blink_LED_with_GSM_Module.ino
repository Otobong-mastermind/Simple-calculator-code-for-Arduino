
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10); // RX, TX
char inchar;
const int LED = 4;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LED,OUTPUT);
  mySerial.println("AT+CMGF=1");
  delay(200);
  mySerial.println("AT+CNMI=3,3,0,0");
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(mySerial.available() > 0){
        delay(100);
        inchar=mySerial.read();
      if(inchar=='a')
       {
        if(inchar=='0')
        {
          digitalWrite(LED,LOW);
        }
        else if(inchar=='1'){
          digitalWrite(LED,HIGH);
          }
          delay(10);
          delay(10);
      }
      mySerial.println("AT+CMGD=1,4");
   }
}
