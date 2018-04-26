#define COMMON_ANODE

int rgbLed[4] = {6,5,3}; //rgb pins for the rgb LED
int leds[4] = {13,12,8};  // the pins for each of the LED hearts

int pPin = 0; //the pin for the pulse sensor
int pVal; //the value of the pulse sensor (from analogRead)

int tmpPin = 3; //the pin for the temperature sensor
int tmpVal; //the value of the temperature sensor (from analogRead)
int tmpRange; //the mapped value of the temperature sensor

unsigned long curMil;
unsigned long prevMil; 
unsigned long tPass; 
  

void setup() {
  Serial.begin(9600); 
  pinMode(rgbLed[0], OUTPUT); 
  pinMode(rgbLed[1], OUTPUT);
  pinMode(rgbLed[2], OUTPUT);
  pinMode(tmpPin, INPUT); 
  pinMode(pPin, INPUT); 
  pinMode(leds[0], OUTPUT); 
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  
}

void loop() {
     pVal = analogRead(pPin); //reading the value of the pulse sensor
     tmpVal = analogRead(tmpPin); 
     Serial.println(tmpVal); 
 
     curMil = millis(); 
     if (pVal > 750 && pVal < 2000){
      Serial.println("PrevMilA");
      Serial.println(prevMil); 
      Serial.println("CurMilA"); 
      Serial.println(curMil); 
      tPass = (curMil - prevMil);
      delay(500);
      Serial.println("TimePassed");
      Serial.println(tPass);
      prevMil = curMil;
      Serial.println("Prevb");
      Serial.println(prevMil); 
      Serial.println("CurB"); 
      Serial.println(curMil);
      Serial.println("    ");   
    }
    else {
      //Serial.println("else"); 
    }

    tempChange();
    heartBeat();
}


////////////////////////////functions of the different hart rate states. each of these is called depending on the function
void state1(){
  digitalWrite(leds[0], HIGH); 
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
}
void state2(){
  digitalWrite(leds[0], HIGH); 
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], LOW);
}
void state3(){
  digitalWrite(leds[0], HIGH); 
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);
} 


////////////////////////function for changing the color of the RGB LED from Adafuit
void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(rgbLed[0], red);
  analogWrite(rgbLed[1], green);
  analogWrite(rgbLed[2], blue);  
}


/////////////////////////The function to change the color based on the temperature
void tempChange(){
  if (tmpVal > 160 && tmpVal < 165 ){
    setColor(0,0,255); 
  }
  else if (tmpVal > 165 && tmpVal < 176){
    setColor(75,255,0);
  }
  else if (tmpVal > 176 && tmpVal < 180 ){
    setColor(255,0,0); 
  }
  else {
   // Serial.println("not working"); 
  }
}

void heartBeat(){
  if (tPass > 600 && tPass < 1500){ 
      state3();
      Serial.println("NORMAL");
   }
    else if (tPass > 550 && tPass < 600){ 
      state2();
      Serial.println("POST WORKOUT");
    }
    else if (tPass > 100 && tPass < 550){
      state1(); 
      Serial.println("ACTIVE"); 
    }
    else {
      Serial.println("not an option"); 
      digitalWrite(leds[0], LOW); 
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
    }
}




