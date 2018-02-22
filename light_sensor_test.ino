int anaVal;//analog value
int anaPin = 0;//analog pin
int ledPins[3] = {6,3,12};//led pins in an array


void setup() {
  Serial.begin(9600); 
  pinMode(ledPins[0], OUTPUT);//This says that the led in pin ~6 is going to be an output
  pinMode(ledPins[1], OUTPUT); //this says that the led in pin ~3 is going to be an output
  pinMode(ledPins[2], OUTPUT); //this says that the led in pin 12 is going to be an input. my goal is that it will know when the led in pin 12 is turned on, so that it only operates when that is on
}

void loop() {
  
  anaVal = analogRead(anaPin); 
  ledVal = digitalRead(ledPins[0]);
 //if the led in pin 12 is on then do the normal code, unfortunatly it did not work as planned  
 /*if (ledPins[2] == HIGH){ 
    //Serial.println(anaVal); this line is used to test if my light sensor is working
    //delay(1000); this was to slow down the results from my light sensoe
    lights(); //this is the function that senses where the light is 
    Serial.println("its on!"); //tells me that it reads pin 12 is on
 }*/
/* else {
  Serial.println("it's not on!"); //tells me that it reads pin 1''2 is not on
  digitalWrite(ledPins[0],LOW); //keeps the other led off 
  digitalWrite(ledPins[1], LOW); //keeps the other led off
  delay(1000); //keeps it from spamming me
 }*/
 //if the light is bright enough it will do something
 if (anaVal > 100 && anaVal < 600){
      Serial.println("Smile");//tells me that it reads the light
      //Serial.println(ledVal);
      digitalWrite(ledPins[0],HIGH); //tells led 6 to turn on
      digitalWrite(ledPins[1],LOW); //tells led 3 to turn off
      delay(1000);   //keeps it slow and readable
    }
    //if the light is too dark it will do the same thing as before, but it will turn on led 6 rather than led 3
    else if (anaVal < 100 && anaVal > 0){
      Serial.println("Frown"); 
      digitalWrite (ledPins[0], LOW); 
      digitalWrite(ledPins[1], HIGH); 
    
     delay(1000);
    }
    //this catches everything outside range so that i know if something weird happens it is because it is out of range
    else {
      Serial.println("Out of range"); 
    }
}
//function did not work as planned
/*void lights(){
  if (anaVal > 100 && anaVal < 600){
      Serial.println("Smile");
      //Serial.println(ledVal);
      digitalWrite(ledPins[0],HIGH); 
      digitalWrite(ledPins[1],LOW); 
      delay(1000);   
    }
    else if (anaVal < 100 && anaVal > 0){
      Serial.println("Frown"); 
      digitalWrite (ledPins[0], LOW); 
      digitalWrite(ledPins[1], HIGH); 
    
     delay(1000);
    }
    else {
      Serial.println("Out of range"); 
    }
}*/
  




