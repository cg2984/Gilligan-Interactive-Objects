int enablePin = 9;

int motorPin1 = 5;
int motorPin2 = 6;

int buttonPin = 2;
int buttonPin2 = 13; 

int ledPin =  12;
int ledPin2 = 11; 

int buttonState; 
int buttonState2; 

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT); 
  
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT); 

  pinMode(motorPin1,INPUT); 
  pinMode(motorPin2, INPUT); 

  pinMode(enablePin, LOW); 

}

void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  
//forward
  if(buttonState == 1 && buttonState2 == 0){
    digitalWrite(enablePin, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(enablePin, HIGH); 
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW); 
   Serial.println("forward"); 
  }
//backwards
 else if(buttonState == 0 && buttonState2 == 1){
    digitalWrite(enablePin, LOW); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(enablePin, HIGH); 
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH); 
   Serial.println("backwards"); 
  }
//stop
  else if (buttonState == 0 && buttonState2 == 0) {
    digitalWrite(enablePin, LOW); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW); 
    digitalWrite(ledPin, LOW); 
    digitalWrite(ledPin2, LOW);
   Serial.println("stopping"); 
  }
}
