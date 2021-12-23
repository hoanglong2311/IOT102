#include <DHT.h>
 // ngay 13/10
 #define DHTPIN 3 
 #define DHTTYPE DHT11     // DHT 11
 float h = 0;
 float t = 0;
 DHT dht(DHTPIN, DHTTYPE);
 void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
}
 //cu
 void setup()
 { 
   Serial.begin(9600);
   dht.begin();
 }
 void loop()
 {
  sendSensor();
  Serial.print("H: ");
  Serial.println(h);
  delay(2000);
  Serial.print("T: ");
  Serial.println(t);
  delay(2000);
 }
