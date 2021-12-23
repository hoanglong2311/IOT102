#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (9, 8, 7, 6, 5, 4);
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys [ ROWS ] [ COLS ]={
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'},
  }; 
  byte rowPins[ROWS] = {3, 2, 19, 18};

  byte colPins[COLS] = {17, 16, 15, 14}; 
  Keypad customKeypad = Keypad (makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
  const int LED_RED = 10;
  const int LED_GREEN = 11;
  const int RELAY = 12; 
  char keycount = 0;
  char code[4];

void setup() {
  // put your setup code here, to run once:
  pinMode (LED_RED, OUTPUT);
  pinMode (LED_GREEN, OUTPUT);
  pinMode (RELAY, OUTPUT);

  lcd.begin (16,2);
  lcd.clear();
  lcd.print("Password access:");
  lcd.setCursor(0,1);
  lcd.cursor();

  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
  digitalWrite(RELAY, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  if ( customKey && (keycount<4) && (customKey!='=') && (customKey!='C')){
    lcd.print('*');
    code [keycount] = customKey;
    keycount++;
  }
  if (customKey == 'C'){
    Lock();
  }
  if(customKey == '=')
  {
    if( (code[0] =='1') && (code[1] =='2')&& (code[2] =='3') && (code[3] =='4')) 
    {
      //default pass 1234 
       digitalWrite(LED_GREEN, LOW); 
       digitalWrite(LED_RED, HIGH); 
       digitalWrite(RELAY, HIGH);
       lcd.setCursor(0,1);
       lcd.print ("Door open     ");
       delay(4000);
       Lock();
    }else 
    {
      lcd.setCursor(0,1);
      lcd.print("Invalid Password");
      delay(1500);
      Lock();
     }
  }    
}

void Lock()
{
  lcd.setCursor(0,1);
  lcd.print("Door Locked");
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.setCursor(0,1);
  keycount = 0;
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
  digitalWrite(RELAY, LOW);
}
