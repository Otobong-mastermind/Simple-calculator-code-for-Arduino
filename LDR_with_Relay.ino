const int LDR = A0;
const int Beeper = 8;

int beepState = 0;
void setup() {
  // put your setup code here, to run once:
   // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  pinMode(Beeper,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 beepState = analogRead(LDR);

  if(beepState>13){
    digitalWrite(Beeper,HIGH);
    }else{
      digitalWrite(Beeper,LOW);
      }
Serial.print("The light intensity is = ");
Serial.println(beepState);
delay(1000);
}
