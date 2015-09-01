int pinRed=9;
int pinYellow=8;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
}

void loop() {
  digitalWrite(pinRed, HIGH);
  delay(125);

  digitalWrite(pinRed, LOW);
  delay(125);

  digitalWrite(pinYellow, HIGH);
  delay(125);

  digitalWrite(pinYellow, LOW);
  delay(125);

}
