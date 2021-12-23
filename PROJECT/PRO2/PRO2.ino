
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

//alarm
int buzzer_pin= 13;
//fire sensor
int fireSensor = 8;
//motor
int motorRain = 7;
int motorGas = 3;

int rainSensor = 6; // Chân tín hiệu cảm biến mưa ở chân digital 6 (arduino)
//GAS sensor
int Gas = 9;
int redLed = 4;
int greenLed = 5;
//den gara
const int ledPin = 11;
const int LDRPin = A0;

void setup() 
{
  Serial.begin(9600);// Khởi động Serial ở baudrate 9600
  lcd.init();
  lcd.backlight();
  
  pinMode(Gas , INPUT);
  pinMode(fireSensor , INPUT);
  pinMode(rainSensor,INPUT);// Đặt chân cảm biến mưa là INPUT, vì tín hiệu sẽ được truyền đến cho Arduino
  
  pinMode(motorGas,OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(motorRain,OUTPUT);
  
  //den gara
  pinMode(ledPin, OUTPUT);
  pinMode(LDRPin, INPUT);
  //den gara

  
  lcd.setCursor(0,0);
  lcd.println("xin chao");
}

void loop() {
  // iterate over the notes of the melody:
  
  int rain = digitalRead(rainSensor);//Đọc tín hiệu cảm biến mưa
  if (rain == HIGH) 
  {
    lcd.setCursor(0,0);
    lcd.print("Rain");
    digitalWrite(motorRain,HIGH);
  } 
  else 
  {
    lcd.setCursor(0,0);
    lcd.print(" Not rain");
    digitalWrite(motorRain,LOW);
  }
  
  //GAS SENSOR
   if(digitalRead(Gas) == HIGH){
    digitalWrite(redLed , HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(motorGas,HIGH);
  }
  else{
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed ,LOW);
  digitalWrite(motorGas,LOW);
  }
  //fire sensor
  if(digitalRead(fireSensor) == HIGH){
    digitalWrite(buzzer_pin , HIGH);
//    digitalWrite(greenLed, LOW);
//    digitalWrite(motorGas,HIGH);
  }
  else{
//  digitalWrite(greenLed, HIGH);
  digitalWrite(buzzer_pin ,LOW);
//  digitalWrite(motorGas,LOW);
  }
  
  delay(1000); 
  
  //den gara
  
  int ldrStatus = analogRead(LDRPin);
  if (ldrStatus <= 700) {
  digitalWrite(ledPin, HIGH);
  } else {
  digitalWrite(ledPin, LOW);
 
  }
}
