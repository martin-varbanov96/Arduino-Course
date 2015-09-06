int ledPin=6;
int buttonPin=12;
int buttonResult;
int shift=A0;
int switchVal;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  analogWrite(ledPin, 500);
  delay(3000);
  
  switchVal=analogRead(shift);
  buttonResult=digitalRead(buttonPin);

  if(switchVal>600){
    digitalWrite(ledPin, HIGH);
    while(buttonResult==HIGH){
      digitalWrite(ledPin, HIGH);
      delay(500);

      digitalWrite(ledPin, LOW);
      delay(500);

      buttonResult=digitalRead(buttonPin);
    }
  }else{
    digitalWrite(ledPin, LOW);
  }
  
}
