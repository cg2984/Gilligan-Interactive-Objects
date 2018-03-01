int switchPin = 2; 
int switchState; 
int ledPin = 13;
unsigned long i = 0; 
unsigned long 

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
    for(i = 0; i < 10000; i++){
      Serial.println(i);
      if (i > 200){
        digitalWrite(ledPin,HIGH); 
      } 
     
    } 
  }
  if (switchState == 0 && i > 400){
        digitalWrite(ledPin,LOW);
        Serial.println(switchState);
        i = 0; 
  }
}



