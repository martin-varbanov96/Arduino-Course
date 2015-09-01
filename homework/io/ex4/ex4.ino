int potentmeter=A0;
int pinYellow=9;
int pinRed=10;
double value=0;
double POTENTMAX=1023;
double PINMAX=243;
double percent;

void setup() {
  Serial.begin(9600);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinRed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(potentmeter);
  percent=100*value/POTENTMAX;
  value= percent/100*PINMAX; 
  Serial.println(value);
  analogWrite(pinYellow, value);
  analogWrite(pinRed, (243-value));
}
