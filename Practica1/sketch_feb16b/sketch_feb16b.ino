void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);

}

void loop() {
  int opcion = digitalRead(2);

  int prendido = 0;
  while(opcion){
    opcion = digitalRead(2);
    if(prendido && !opcion){
      digitalWrite(3, LOW);
      prendido = 0;
    }else{
      if(!prendido && !opcion){
        digitalWrite(3, HIGH);
        prendido = 1;
      }
    }
    //opcion = digitalRead(2);
  }
  
}