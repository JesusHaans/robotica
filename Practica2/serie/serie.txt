//Christian Alexander Tello Ruiz
//Jesus Haans Lopez Hernandez

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);

}
//funcion para ir de izquierda a derecha
void izq_der(){
  int i = 0;
  int prendido1 = 2;
  int prendido2 = 3;
  int prendido3 = 4;
  while(i < 10){
    int foco = 2; 
    while(foco < 11){
      if(foco == prendido1 || foco == prendido2 || foco == prendido3){
        digitalWrite(foco, HIGH);
        delay(15);
      }else{
        digitalWrite(foco, LOW);
        delay(15);
      }
      foco++;
    }
    i++;
    prendido1++;
    prendido2++;
    prendido3++;
  }
}
// funcion para prender de derecha a izquierda
void der_izq()
{
  int i = 0;
  int prendido1 = 8;
  int prendido2 = 9;
  int prendido3 = 10;
  while(i < 10){
    int foco = 10; 
    while(foco > 1){
      if(foco == prendido1 || foco == prendido2 || foco == prendido3){
        digitalWrite(foco, HIGH);
        delay(15);
      }else{
        digitalWrite(foco, LOW);
        delay(15);
      }
      foco--;
    }
    i++;
    prendido1--;
    prendido2--;
    prendido3--;
  }
}
//entero para decidir de donde a donde iremos
int direccion = 1;
void loop() {
  while(digitalRead(11)){
    delay(50);
    if(!digitalRead(11)){
      //digitalWrite(3, prendido);
      if(direccion){
        izq_der();
        //der_izq();
      }else{
        der_izq();
        //izq_der();
      }
      direccion = !direccion;
    }
  }
  
}
