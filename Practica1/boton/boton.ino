void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4,OUTPUT);

}

void loop() {
  digitalWrite(4,HIGH);
  int opcion = digitalRead(2);
  if(opcion){
    digitalWrite(3, LOW);
  }else{
    digitalWrite(3, HIGH);
  }

}
