//int inputPin = 12; 
//int inputVal;
//tutorial  https://www.brainy-bits.com/connect-a-character-lcd-using-the-i2c-bus/
//https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/ this is the library I used
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>


//this code is setting out the pin numbers in the LCD screen, and telling the code that whenever there is the letter name replace it with the number. https://www.brainy-bits.com/connect-a-character-lcd-using-the-i2c-bus/
#define I2C_ADDR  0x27  // Add your address here.
#define VSS_pin 1
#define VDD_pin 2
#define VL_pin 3
#define Rs_pin 4
#define Rw_pin 5
#define En_pin 6
#define D0_pin 7
#define D1_pin 8
#define D2_pin 9
#define D3_pin 10
#define BACKLIGHT_pin 15

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D0_pin,D1_pin,D2_pin,D3_pin); 
// end of others code

void setup() { 
Serial.begin(9600);
lcd.begin(16,2); 

lcd.home (); //this prints the text on the first line, first character
lcd.print("working");
}

void loop() {
 

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
