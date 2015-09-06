int ledPin=9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i=0;i<=255;i++){
    analogWrite(ledPin, i);
    delay(80);
  }
  for(int i=255;i>=0;i--){
    analogWrite(ledPin, i);
    delay(80);
  }

}
