//
// Equipo
// López Hernández Jesús Haans
// Tello Ruiz Christian Alexander
void setup() {
  //inicializamos los 10 leds que ocuparemos
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  int i = 0; //indice para ir subiendo
  int prendido1 = 2;//Focos a prender
  int prendido2 = 3;
  int prendido3 = 4;
  while(i < 10){
    int foco = 2; //foco que iremos apagando
    while(foco < 12){
      if(foco == prendido1 || foco == prendido2 || foco == prendido3){
        digitalWrite(foco, HIGH); //prendemos pos focos
        delay(15);
      }else{
        digitalWrite(foco, LOW);//vamos apagando si no es de los que debemos tener prendido
        delay(15);
      }
      foco++;//Incrementamos  el foco que queremos
    }
    i++;//incrementamos el ciclo
    prendido1++;//incrementamos los focos que queremos
    prendido2++;
    prendido3++;
  }
//aqui hacemos el inverso para hacer el efecto de regreso
  i = 0;
  prendido1 = 9;
  prendido2 = 10;
  prendido3 = 11;
  while(i < 10){
    int foco = 11; 
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
