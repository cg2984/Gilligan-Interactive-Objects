#define COMMON_ANODE
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
//#include <Lights_and_Output.ino>
/////////////////////adafruit code/////////////////////////////////////////
/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);
////////////////adafruit code//////////////////////////////////////////////
int rgbLed[4] = {6,5,3}; //rgb pins for the rgb LED
int leds[4] = {13,12,8};  // the pins for each of the LED hearts

int pPin = 1; //the pin for the pulse sensor
int pVal; //the value of the pulse sensor (from analogRead)

int lim = 750; 

int nPin = 9 ;
unsigned long curMil;
unsigned long prevMil; 
unsigned long tPass; 


void setup() {
  Serial.begin(9600); 
  pinMode(rgbLed[0], OUTPUT); 
  pinMode(rgbLed[1], OUTPUT);
  pinMode(rgbLed[2], OUTPUT); 
  pinMode(pPin, INPUT); 
  pinMode(leds[0], OUTPUT); 
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(nPin, OUTPUT);
   
  
}

void loop(){
      pVal = analogRead(pPin); //reading the value of the pulse sensor
      

     curMil = millis();
     
      if (pVal > 800 && pVal < 950){
          tPass = (curMil - prevMil);
          Serial.println("tPass"); 
          Serial.println(tPass);
          Serial.println("pVal"); 
          Serial.println(pVal);    
          delay(400); 
          prevMil = curMil; 
      }
      else if (curMil - prevMil > 2000){
      state4(); 
      Serial.println("not near sensor"); 
     }
      else {
     // Serial.println("else"); 
      }
  heartBeat(); 
///////////////////////////////////adafruit code//////////////////////////////  
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
      /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
  
  float Pi = 3.14159;
  
  // Calculate the angle of the vector y,x
  float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
  
  // Normalize to 0-360
  if (heading < 0)
  {
    heading = 360 + heading;
  }
  //Serial.print("Compass Heading: ");
  //Serial.println(heading);
//adafruit code//////////////////////////////////////////////////////////////
   if(heading > 10 && heading < 45||heading  > 315 && heading < 350) {
    
    analogWrite(nPin, 25); 
  }
  else if(heading > 0 && heading < 10 || heading > 350 && heading < 360){
      analogWrite(nPin, 255);  
  }
  else if(heading > 45 && heading < 135){
    digitalWrite(nPin,LOW);  
  }
  else if (heading > 135 && heading < 225){
    digitalWrite(nPin,LOW);  
  }
  else if (heading > 225 && heading < 315){
    digitalWrite(nPin,LOW);  
  }
  else {
    //Serial.println("not in range");
    digitalWrite(nPin,LOW);   
  }
}


////////////////////////////functions of the different heart rate states. each of these is called depending on the function
void state1(){
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1],LOW);
  setColor(0,233,0);  
}
void state2(){
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], LOW);
    setColor(0,233,0);
}
void state3(){
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    setColor(0,233,0);
}
void state4(){
  digitalWrite(leds[0], LOW); 
  digitalWrite(leds[1], LOW); 
  setColor(0,233,125); 
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
 
void heartBeat(){ 
    if (tPass > 500 && tPass < 1000){ 
      state3();
      //Serial.println("NORMAL");
    }
    else if (tPass > 300 && tPass < 550){ 
      state2();
      //Serial.println("POST WORkOUT");
    }
    else if (tPass > 450  && tPass < 550){
      state1(); 
     // Serial.println("ACTIVE"); 
    }
    else {
      state4();
    }
}




