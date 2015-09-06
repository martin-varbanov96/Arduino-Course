int buttonPinYes=12;
int buttonPinNo=11;
int ledPinYes=2;
int ledPinNo=4;


int count=0;
int buttonCondition;
int lastCondition=LOW;
long lastDebounce=0;
long debouncePeriod=50;

int isYes=LOW;
int isNo=LOW;

int turn=2;
int randNum;

String questionsArr[10]={" Massimo Banzi dropped out of college because it was too boring for him.", "((5/3)>(6/4))||((2^6)>(3^7))||(TRUE))", "In 2011 there were 300,000 Arduinos.", "Arduino is a C based language", "A 3D printer can be created with Arduino", "All Arduino boards are created in China", "Simeon Yanchev created his phone with Arduino", "((Math.sqrt(2,3))>1,1233)&&(4*6=12*2)&&FALSE)", "Japan have recently created military ships with Arduino", "Arduino is the Matrix that will destroy us all"};

int questionNumberArray[10]={2,5,3,6,0,8,9,1,4,7};

int playerOnePoints=0;
int playerTwoPoints=0;


void setup() {
  pinMode(ledPinYes, OUTPUT);
  pinMode(ledPinNo, OUTPUT);
  pinMode(buttonPinYes, INPUT);
  pinMode(buttonPinNo, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  Serial.println("Let the game begin!!");
  
  for(int i=0;i<10;i++){
    //ASKING QUESTION
    Serial.println();
    Serial.println();
    Serial.println(questionsArr[questionNumberArray[i]]);
    
    //Waiting in vein
    while((isYes==LOW)&&(isNo==LOW)){
      isYes=bounce(buttonPinYes);
      isNo=bounce(buttonPinNo);
      if((isYes==HIGH)||(isNo==HIGH)){
        delay(300);
      }

      //answering and pointing
      if((turn%2)==0){
         playerOnePoints+=checkAnswer(isYes, isNo, questionNumberArray[i]);
      }else{
        playerTwoPoints+=checkAnswer(isYes, isNo, questionNumberArray[i]);
      
      }
      
    }
    showScore(playerOnePoints, playerTwoPoints);
    turn++;
    digitalWrite(ledPinNo,LOW);
    digitalWrite(ledPinYes,LOW);
    isYes=LOW;
    isNo=LOW;
    
  }
  //ending game
  if(playerOnePoints>playerTwoPoints){
    Serial.println("Player 1 wins!!!");
  }else if(playerOnePoints<playerTwoPoints){
    Serial.println("Player 2 wins!!!");
  }else{
    Serial.println("The game is draw!");
  }
  while(buttonPinYes>buttonPinNo){
    Serial.println();
    Serial.println("Press the restart key to play again");
    Serial.println();
    delay(5000);
  }
}
void showScore(int a, int b){
  Serial.println();
  Serial.println();
  Serial.println("-----------------------------------");
  Serial.print("| Player 1: ");
  Serial.print(a);
  Serial.print(" points | player 2: ");
  Serial.print(b);
  Serial.println(" points |");
  Serial.println("-----------------------------------");
  Serial.println();
  Serial.println();
}

int bounce(int pin){
   int result=digitalRead(pin);

  if(result!=lastCondition){
    lastDebounce=millis();    
  }
  if(result!=buttonCondition){
    buttonCondition=result;
    if(buttonCondition==HIGH){
      return HIGH;
    }
  }
  lastCondition=result;
  return LOW;
}

int checkAnswer(int isTRUE, int isFALSE, int questionNumber){
  //tempaskldsajdasdjas;ldkasdkaskd;a;kdlsa

  //tempaslkdnasdsadasdjlaskdaskdaslkdasjdksajdkasdjka;sdsa
   if((isTRUE==HIGH)&&(questionNumber>4)){
      Serial.println("MISTAKE" );
      digitalWrite(ledPinNo, HIGH);
      delay(200);

        Serial.println(isTRUE);
     Serial.println(isFALSE);
  Serial.println(questionNumber);

      
      return 0;
   }else if((isTRUE==HIGH)&&(questionNumber>=0)){
      Serial.println("Congratz, 1 point for you");
      digitalWrite(ledPinYes, HIGH);
      delay(200);




        Serial.println(isTRUE);
  Serial.println(isFALSE);
  Serial.println(questionNumber);




  
      return 1;
   }else if((isFALSE==HIGH)&&(questionNumber>4)){
      Serial.println("Congrats, 1 point for you");
      digitalWrite(ledPinYes, HIGH);
      delay(200);




        Serial.println(isTRUE);
  Serial.println(isFALSE);
  Serial.println(questionNumber);



  
      return 1;
   }else if((isFALSE==HIGH)&&(questionNumber>0)){
      Serial.println("MISTAKE" );      
      digitalWrite(ledPinNo, HIGH);
      delay(200);



        Serial.println(isTRUE);
  Serial.println(isFALSE);
  Serial.println(questionNumber);


  
      return 0;
   }
   return 0;
}
