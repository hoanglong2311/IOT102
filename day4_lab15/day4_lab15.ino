void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pins:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // do something different depending on the character received.
    // The switch statement expects single number values for each case; in this
    // example, though, you're using single quotes to tell the controller to get
    // the ASCII value for the character. For example 'a' = 97, 'b' = 98,
    // and so forth:

    switch (inByte) {
      case 'a':
        digitalWrite(2, HIGH);
        Serial.print("led: ");
        Serial.println(inByte);
        break;
      case 'b':
        digitalWrite(3, HIGH);
         Serial.print("led: ");
        Serial.println(inByte);
        break;
      case 'c':
        digitalWrite(4, HIGH);
         Serial.print("led: ");
        Serial.println(inByte);
        break;
      case 'd':
        digitalWrite(5, HIGH);
         Serial.print("led: ");
        Serial.println(inByte);
        break;
      case 'e':
        digitalWrite(6, HIGH);
         Serial.print("led: ");
        Serial.println(inByte);
        break;
      default:
        // turn all the LEDs off:
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}
