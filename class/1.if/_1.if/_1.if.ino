int pinYellow13=13;
int pinGreen12=12;
int pinRed=11;
int pinGreen10=8;
int pinYellow=9;
int shift=A0;
int result;

void setup() {
    pinMode(pinYellow13, OUTPUT);
    pinMode(pinGreen12, OUTPUT);
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen10, OUTPUT);
    pinMode(pinYellow, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
  result=analogRead(shift);

  if(result<200){
    digitalWrite(pinYellow13, LOW);
    digitalWrite(pinGreen12, LOW);
    digitalWrite(pinRed, LOW);
    digitalWrite(pinGreen10, LOW);
    digitalWrite(pinYellow, LOW);
  }else if(result<400){
    digitalWrite(pinYellow13, HIGH);
    digitalWrite(pinGreen12, LOW);
    digitalWrite(pinRed, LOW);
    digitalWrite(pinGreen10, LOW);
    digitalWrite(pinYellow, LOW);
  }else if(result<600){
    digitalWrite(pinYellow13, HIGH);
    digitalWrite(pinGreen12, HIGH);
    digitalWrite(pinRed, LOW);
    digitalWrite(pinGreen10, LOW);
    digitalWrite(pinYellow, LOW);
    }else if(result<800){
    digitalWrite(pinYellow13, HIGH);
    digitalWrite(pinGreen12, HIGH);
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinGreen10, LOW);
    digitalWrite(pinYellow, LOW);
    }else if(result<1000){
    digitalWrite(pinYellow13, HIGH);
    digitalWrite(pinGreen12, HIGH);
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinGreen10, HIGH);
    digitalWrite(pinYellow, LOW);
    }else{
    digitalWrite(pinYellow13, HIGH);
    digitalWrite(pinGreen12, HIGH);
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinGreen10, HIGH);
    digitalWrite(pinYellow, HIGH);
    }
  

}
