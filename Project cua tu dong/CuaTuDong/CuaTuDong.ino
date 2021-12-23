
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define PIR_sensor 14

#define m11 0

#define m12

void setup()

{

   lcd.begin(20, 4);
  
  lcd.clear ();
  
  pinMode(m11, OUTPUT);
  
  pinMode(m12, OUTPUT);
  
  pinMode(PIR_sensor, INPUT);
  
  lcd.print("INTELLEGENT DOOR");
  
  lcd.setCursor(0,1);
  
  lcd.print("ELECTRONIFY.ORG");
  
  delay(1000);

   //initialize visitor counter as int visitor =0

}

void loop()

{

if(digitalRead(PIR_sensor))

{

lcd.setCursor(0,2);

lcd.print("Movement Detected");

lcd.setCursor(0, 3);

lcd.print("    Gate Opened    ");

digitalWrite(m11, HIGH);         // gate opening

digitalWrite(m12, LOW);

delay(1000);

digitalWrite(m11, LOW);          // gate stop for a while

digitalWrite(m12, LOW);

delay(1000);

lcd.setCursor(0, 3);

lcd.print("   Gate Closed    ");

digitalWrite(m11, LOW);           // gate closing

digitalWrite(m12, HIGH);

delay(1000);

digitalWrite(m11, LOW);            // gate closed

digitalWrite(m12, LOW);

delay(1000);

//display visitor count to seven segment display

//please increase visitor count ++

}

else

{

lcd.setCursor(0,2);

lcd.print("   No Movement   ");

lcd.setCursor(0,3);

lcd.print("   Gate Closed   ");

digitalWrite(m11, LOW);

digitalWrite(m12, LOW);

}

}
