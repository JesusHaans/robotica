// Equipo
// López Hernández Jesús Haans
// Tello Ruiz Christian Alexander

void setup() {
  pinMode(2, OUTPUT);//Led a Prender
  pinMode(3,OUTPUT);//Led para reconocer cuando entra y sale del while
  
}

void loop() {
int i = 0;
  digitalWrite(3,HIGH);//Prendemos por que entramos a while
  while(i < 1000){//queremos que se detenga en 1000 para hacerlo aproximadamente en 5 segundos 
    digitalWrite(2, HIGH);// prendemos con un delay de i
    delay(i);
    digitalWrite(2, LOW);// apagamos con un delay de i
    delay(i);
    i= i + 250;//aumentamos el delay en 250 ms
  }
  digitalWrite(3,LOW);//Apagamos por que entramos a otro while
  while(i > 0){
    digitalWrite(2, HIGH);// Prendemos con un delay de i
    delay(i);
    digitalWrite(2, LOW);//Apagamos con un delay de i
    delay(i);
    i= i - 250;// desminuimos el delay en 250 ms
  }


  


}
