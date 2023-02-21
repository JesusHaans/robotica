//Christian Alexander Tello Ruiz
//Jesus Haans Lopez Hernandez

void setup() {
  pinMode(2, INPUT);//pin para boton
  pinMode(3, OUTPUT);//pin para led

}

int prendido = 1;// para guardar el estado del  leed
void loop() {
  while(digitalRead(2)){// nos mantenemos vigilando el biooton 
    delay(50);
    if(!digitalRead(2)){//asi ebntramos en este iff para cambiar el estado del led
      digitalWrite(3, prendido);//prendemos o pagamos
      prendido = !prendido;//actualizamos estado
    }
  }
  
}