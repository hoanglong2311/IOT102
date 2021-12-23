#include <Wire.h>
#include <Servo.h>            // Thư viện servo
#include <LiquidCrystal_I2C.h>  // thư viện lcd_i2c
LiquidCrystal_I2C lcd(0x27,16,2);   // khai báo lcd 16 x2 nếu các bạn sử dụng loại 20 thì thay 16 bằng 20
#define sensor 2                    // khai báo sử dụng chân số 2 làm chân cảm biến
Servo servo1;    

int  mysensor;                      // biến lưu trạng thái chân sensor 1 hoặc 0 
int  lastsensor;                    // biến lưu trạng thái chân lúc sau
int  led = 12;
void setup()
{
  lcd.init();                         // khởi tạo LCD
  lcd.backlight();                     // BẬT ĐÈN NỀN LCD
  lcd.setCursor(0,0);                  // ĐƯA CON TRỎ TỚI CỘT 0 HÀNG 0
  lcd.setCursor(2,1);                  // ĐƯA CON TRỎ TỚI CỘT 3 HÀNG 1
  lcd.print("xin chao ");
  delay(1000);
  pinMode(sensor,INPUT);              // khai báo chân sensor input
  pinMode(led, OUTPUT);
  servo1.attach(4);                   // khai báo sử dụng chân số 4 làm chân servo
  }
  void loop()
  {
    mysensor = digitalRead(sensor);   // đọc trạng thái chân sensor và lưu vào biến mysensor
    if(mysensor!=lastsensor && mysensor==1)
    {
      digitalWrite(led, HIGH);
      lcd.clear();
      lcd.setCursor(2,1);
      lcd.print("co vat can");
      servo1.write(0);
      delay(1000);
      servo1.write(90);
      //delay(1000);
      //servo1.write(90);
      }
      lastsensor = mysensor;
      lcd.clear();   
   }
