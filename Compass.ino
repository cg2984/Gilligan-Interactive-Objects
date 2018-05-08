int ledPin = 11;

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
//#include <Lights_and_Output.ino>
/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);
 
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Magnetometer Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  pinMode(ledPin, OUTPUT);  
}
 
void loop(void) 
{
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
  Serial.print("Compass Heading: ");
  //Serial.println(heading);
//my code//////////////////////////////////////////////////////////////
   if(heading > 10 && heading < 45||heading  > 315 && heading < 350) {
    Serial.println("North");
    analogWrite(ledPin, 25); 
  }
  else if(heading > 0 && heading < 10 || heading > 350 && heading < 360){
      analogWrite(ledPin, 255); 
      Serial.println("tru north"); 
  }
  else if(heading > 45 && heading < 135){
    Serial.println("East"); 
    digitalWrite(ledPin,LOW);  
  }
  else if (heading > 135 && heading < 225){
    Serial.println("South");
    digitalWrite(ledPin,LOW);  
  }
  else if (heading > 225 && heading < 315){
    Serial.println("West"); 
    digitalWrite(ledPin,LOW);  
  }
  else {
    Serial.println("not in range");
    digitalWrite(ledPin,LOW);   
  }
//my code//////////////////////////////////////////////////////////////
  delay(500);
}
