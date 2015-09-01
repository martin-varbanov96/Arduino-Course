int pinRed=9;
int pinYellow=8;
int count=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinRed,OUTPUT);
  pinMode(pinYellow, OUTPUT);    
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(pinYellow, HIGH);
 delay(125);
 
 for(int var=1;var<=3;var++){
    digitalWrite(pinRed, HIGH);
    delay(125);

    digitalWrite(pinRed, LOW);
    delay(125);
  }
  digitalWrite(pinYellow, LOW);
  delay(125);
}
