#include <Blynk.h>
#include <DHT.h>
#include <BlynkSimpleStream.h>
#include <SoftwareSerial.h>

SoftwareSerial SwSerial(10, 11);

 //dWrFfClsVvPhlsThpOxkg82y8Ep4qvYA
 char auth[] = "_SMKLwTUmUmLEqSAx9r6fA9Qoyehi6ev";

 
 // ngay 13/10
 
 #define DHTPIN 3 
 #define BLYNK_PRINT SwSerial
 // What digital pin we're connected to
 #define DHTTYPE DHT11     // DHT 11

 float h = 0;
 float t = 0;
 
 DHT dht(DHTPIN, DHTTYPE);
 BlynkTimer timer;

 
 void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    SwSerial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, h);
    Blynk.virtualWrite(V1, t);
}


 //cu
 void setup()
 {
   //SwSerial.begin(115200);
   
   Serial.begin(9600);
   
   Blynk.begin(auth, Serial);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);

   //Ngay 13/10
   dht.begin();
   //1000L
   timer.setInterval(2000, sendSensor);
 }
 
 BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1){
    digitalWrite(11, HIGH);
  }else{
    digitalWrite(11, LOW);
  }
}
 
 void loop()
 {
  Blynk.run();
  timer.run();
  sendSensor();
//  Blynk.virtualWrite(V0, h);
//  Blynk.virtualWrite(V1, t);
  
//  Serial.print("H: ");
//  Serial.println(h);
//  delay(2000);
//  Serial.print("T: ");
//  Serial.println(t);
//  delay(2000);
 }
