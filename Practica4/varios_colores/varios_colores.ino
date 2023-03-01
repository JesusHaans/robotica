int azul = 9;
int verde = 10;
int rojo = 11;


void setup() {
  pinMode(azul, OUTPUT);//azul
  pinMode(verde, OUTPUT);//verde
  pinMode(rojo, OUTPUT);//rojo
}

void trans(int pin, int var){
  if(var!=1){
    for(int k = 0; k < 256; k = k + 1){
      analogWrite(pin, k);
      delay(10);
    }

  }else{
    for(int k = 256; k > 0; k = k - 1){
      analogWrite(pin, k);
      delay(10);
    }
  }
}

void trans2(int pin1, int pin2, int var){
  if(var!=1){
    for(int k = 0; k < 256; k = k + 1){
      analogWrite(pin1, k);
      analogWrite(pin2, k);
      delay(10);
    }

  }else{
    for(int k = 256; k > 0; k = k - 1){
      analogWrite(pin1, k);
      analogWrite(pin2, k);
      delay(10);
    }
  }
}

void trans3(int pin1, int pin2, int pin3, int var){
  if(var!=1){
    for(int k = 0; k < 256; k = k + 1){
      analogWrite(pin1, k);
      analogWrite(pin2, k);
      analogWrite(pin3, k);
      delay(10);
    }

  }else{
    for(int k = 256; k > 0; k = k - 1){
      analogWrite(pin1, k);
      analogWrite(pin2, k);
      analogWrite(pin3, k);
      delay(10);
    }
  }
}

void loop() {
  trans2(azul,rojo,0);
  trans(rojo,1);
  trans(verde,0);
  trans(azul,1);
  trans(rojo,0);
  trans(verde,1);
  trans2(azul,verde,0);
  trans3(azul,rojo,verde,1);
  trans(azul,0);
  analogWrite(azul,0);ssssssssss
  trans(verde,0);
  analogWrite(verde,0);
  trans(rojo,0);
  analogWrite(rojo,0);
}
