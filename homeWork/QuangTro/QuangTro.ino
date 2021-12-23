  const int ledPin = 13;
  const int LDRPin = A0;
  void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(LDRPin, INPUT);
  }
  void loop() {
  
    int ldrStatus = analogRead(LDRPin);
    
    if (ldrStatus <= 700) {
    
    digitalWrite(ledPin, HIGH);
    delay(1000);
    Serial.print(" LIGHT ON : ");
    
    Serial.println(ldrStatus);
  
    } else {
    
      digitalWrite(ledPin, LOW);
      delay(1000);
      Serial.print("LIGHT OFF: ");
      
      Serial.println(ldrStatus);
    }   
}
