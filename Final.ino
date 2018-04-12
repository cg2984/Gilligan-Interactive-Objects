int leds1 = 13; 
int leds2 = 10;
int leds3 = 7;
int leds4 = 4;
int pressPin = 3; 
int pressVal; 
int pRange;
int tmpPin = 0;
int tmpVal;
int tRange;  
void setup() {
  Serial.begin(9600); 
//  digitalWrite(leds1, LOW); 
//  digitalWrite(leds2, LOW);
//  digitalWrite(leds3, LOW);
//  digitalWrite(leds4, LOW);
}

void loop() {
  pinMode(leds1, OUTPUT); 
  pinMode(leds2, OUTPUT);
  pinMode(leds3, OUTPUT);
  pinMode(leds4, OUTPUT);
  pressVal = analogRead(pressPin); 
  tmpVal = analogRead(tmpPin); 
  Serial.println(tmpVal); 
  delay(30); 
  tRange = map(tmpVal, 120, 170, 0, 50); 
  Serial.println(tRange); 
  pRange = map(pressVal, 0 ,1032, 0, 100); 
//  Serial.println(range); 
  
  /////////VERSION A/////////////////////////////////////////////////////////////////////////////
//  if (range > 0 && range < 25){
//    state4(); 
//    Serial.println("RESTING"); 
//  }
//  else if (range > 25 && range< 50){
//    state3();
//    Serial.println("NORMAL");
//  }
//  else if (range > 50 && range < 75){
//    state2(); 
//    Serial.println("POST WORKOUT"); 
//  }
//  else if (range > 75 && range < 100  ){
//    state1(); 
//    Serial.println("ACTIVE");
//  }
//  else {
//    Serial.println("not an option"); 
//    digitalWrite(leds1, LOW); 
//    digitalWrite(leds2, LOW);
//    digitalWrite(leds3, LOW);
//    digitalWrite(leds4, LOW);
//  }
  
  ////////////////VERSION B//////////////////////////////////////////////////////////////////////////
//  if (range > 0 && range < 33){
//    state3(); 
//    Serial.println("RESTING"); 
//  }
//  else if (range > 33 && range < 66){
//    state2();
//    Serial.println("POST WORKOUT");
//  }
//  else if (range > 66 && range < 100){
//    state1(); 
//    Serial.println("ACTIVE"); 
//  }
//  else {
//    Serial.println("not an option"); 
//    digitalWrite(leds1, LOW); 
//    digitalWrite(leds2, LOW);
//    digitalWrite(leds3, LOW);
//    digitalWrite(leds4, LOW);
//  }
}

///////VERSION A
//void state1(){
//  digitalWrite(leds1, HIGH); 
//  digitalWrite(leds2, LOW);
//  digitalWrite(leds3, LOW);
//  digitalWrite(leds4, LOW);
//}
//
//void state2(){
//  digitalWrite(leds1, HIGH); 
//  digitalWrite(leds2, HIGH);
//  digitalWrite(leds3, LOW);
//  digitalWrite(leds4, LOW);
//}
//void state3(){
//  digitalWrite(leds1, HIGH); 
//  digitalWrite(leds2, HIGH);
//  digitalWrite(leds3, HIGH);
//  digitalWrite(leds4, LOW  );
//}
//void state4(){
//  digitalWrite(leds1, HIGH); 
//  digitalWrite(leds2, HIGH);
//  digitalWrite(leds3, HIGH);
//  digitalWrite(leds4, HIGH);
//}

/////////VERSION B
void state1(){
  digitalWrite(leds1, HIGH); 
  digitalWrite(leds2, LOW);
  digitalWrite(leds3, LOW);
  digitalWrite(leds4, LOW);
}

void state2(){
  digitalWrite(leds1, HIGH); 
  digitalWrite(leds2, HIGH);
  digitalWrite(leds3, LOW);
  digitalWrite(leds4, LOW);
}
void state3(){
  digitalWrite(leds1, HIGH); 
  digitalWrite(leds2, HIGH);
  digitalWrite(leds3, HIGH);
  digitalWrite(leds4, LOW  );
} 

