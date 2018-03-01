int switchPin = 2; 
int switchState; 
unsigned long curMil; 
unsigned long prevMil = 0; 
int ledPin = 13;
int seconds = 3000; 

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);   
}

void loop() {
  //tells me if the button is on or off
  switchState = digitalRead(switchPin); 
  Serial.println(switchState); 
  //if the button is on, and if three seconds has passed, then light the LED
  if (switchState == 0){
    curMil = millis();//holds the current milliseconds
    Serial.println(curMil);//prints the current milliseconds
    if ((unsigned long)(curMil-prevMil > 3000 && switchState == 0)){//says if the current time minus the last time i made an action is greater than 3000 than do the action
      digitalWrite(ledPin, HIGH); 
      prevMil = curMil; // this tells it to remeber when the last action was. it remebers because the last action occured during the time of this if statement, so it will be close to the same time as this line. 
    }
    else if ((unsigned long)(curMil-prevMil > 5000 && switchState == 0)){
     digitalWrite(ledPin, LOW); 
      prevMil = curMil;
    }
    //this is if the button isnt pressed or if it hasn't reached 3000
    else {
      Serial.println("too soon or button not pressed"); 
      //digitalWrite(ledPin, LOW); 
    }
  }
}

/*void ledON (){
  for (int i=0; i<6000; i++){
    digitalWrite(ledPin, HIGH); 
  }
}*/

