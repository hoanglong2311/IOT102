void setup() {
  // put your setup code here, to run once:
  pinMode ( 13, OUTPUT);  //  red led  to set the OUTPUT mode of pin number 13.  
  pinMode ( 7, OUTPUT);  //  yellow led to set the OUTPUT mode of pin number 7.  
}

void loop() {
  // put your main code here, to run repeatedly:
  //den do sang xong tat 1 lan
  digitalWrite (13, HIGH); 
  delay(1000);
  digitalWrite (13, LOW);
  delay(1000); 
  //den do va den vang sang xong tat 1 lan
  digitalWrite (13, HIGH); 
  digitalWrite (7, HIGH);
  delay(1000); 
  digitalWrite (13, LOW);
  digitalWrite (7, LOW); 
  delay(1000);
  // 2 den tat trong 1 phut
  delay(4000);  // 1 second = 1 x 1000 milliseconds 
  //den do nhay 5 lan roi tat
   for (int i = 0; i < 5; i++) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  delay(1000);
  //den do nhay tiep 5 lan
  for (int i = 0; i < 5; i++) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  //den vang nhay tiep 2 lan
  for (int i = 0; i < 2; i++) {
    delay(1000);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    delay(1000);
  }
}
