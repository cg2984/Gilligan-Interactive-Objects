int inputPin = 0; 
int inputVal;

//https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/ this is the library I used
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>


//setting up the LCD pins to connect to the i2c. this code was from https://www.brainy-bits.com/connect-a-character-lcd-using-the-i2c-bus/
#define I2C_ADDR 0x27  // Add your address here.
#define Rs_pin 0
#define Rw_pin 1
#define En_pin 2
#define BACKLIGHT_PIN 3
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); 
// end of others code

void setup() {
Serial.begin(9600);
//setting up the LCD others code
lcd.begin(16,2); 

// LCD Backlight ON others code
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);

lcd.home (); // go home on LCD others code
lcd.print("LCD HOME");
}

void loop() {
  lcd.setCursor (0,1);
  lcd.print("working"); 
//inputVal = analogRead(inputPin); 
// //Serial.println(inputVal); 
//
//// this was meant to be a pause before the fortune was told, but it didnt work out
////   for (int i = 0; i++; i < 100){
////    Serial.println("Thinking..."); 
////   }
//
//   if (inputVal < 70){
//      lcd.setCursor (0,1); 
//      lcd.print(":)");
//      Serial.println(":)"); 
//   }
//   else if (inputVal > 70 && inputVal < 95){
//      lcd.setCursor (0,1); 
//      lcd.print(":(");
//   }
//   else {
//    lcd.setCursor (0,1); 
//      lcd.print(":|");
//   }

}
