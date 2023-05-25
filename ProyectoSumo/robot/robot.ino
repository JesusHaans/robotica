const int Trigger = 4;  //Pin digital 2 para el Trigger del sensor
const int Echo = 2;     //Pin digital 3 para el Echo del sensor
int motor1D = 10;
int motor2D = 5;
int motor1I = 11;
int motor2I = 6;
int inicio = 1;


void setup() {
  Serial.begin(9600);  //iniciailzamos la comunicación
  pinMode(motor1D, OUTPUT);
  pinMode(motor1I, OUTPUT);
  pinMode(motor2D, OUTPUT);
  pinMode(motor2I, OUTPUT);
  pinMode(Trigger, OUTPUT);    //pin como salida
  pinMode(Echo, INPUT);        //pin como entrada
  pinMode(A5, INPUT);          //Frontal Derecho
  pinMode(A6, INPUT);          //Frontal Izquierdo
  pinMode(A7, INPUT);          //Trasero central
  digitalWrite(Trigger, LOW);  //Inicializamos el pin con 0
}

void loop() {
  
  if(inicio){
    //delay(5000);
    inicio = 0;
  }

                long t;  //timepo que demora en llegar el eco
              long d;  //distancia en centimetros

              digitalWrite(Trigger, HIGH);
              delayMicroseconds(10);  //Enviamos un pulso de 10us
              digitalWrite(Trigger, LOW);

              t = pulseIn(Echo, HIGH);  //obtenemos el ancho del pulso
              d = t / 59;               //escalamos el tiempo a una distancia en cm
              if (d < 80) {
                Serial.println("Encontramos al enemigo");
                avanzar();
                
              }else{
                girarDerecha();
                
              }

  if (analogRead(A5) < 30 && analogRead(A6) < 30) {
    Serial.println("Nos empujan hacia en frente Vamos a retroceder");
     retroceder();
     delay(500);
  } else {
    if (analogRead(A5) < 30 && analogRead(A7) < 30) {
      Serial.println("estamos al borde atras y derecha, giramos enfrente e izquierda");
      girarDerecha();
      delay(200);
      retroceder();
    } else {
      if (analogRead(A6) < 30 && analogRead(A7) < 30) {
        Serial.println("estamos al borde atras e izquierda, giramos enfrente y derecha");
        girarIzquierda();
        delay(200);
        retroceder();
      } else {
        if (analogRead(A5) < 30) {
          Serial.println("FD Estamos en blanco");
          girarIzquierda();
        } else {
          if (analogRead(A6) < 30) {
            Serial.println("FI Estamos en blanco");
            girarDerecha();
          } else {
            if (analogRead(A7) < 30) {
              Serial.println("TC Estamos en blanco");
              avanzar();
              //delay(1000);
              //avanzar();
            } 
          }
        }
      }
    }
  }
}

void retrocederDerecho() {
  digitalWrite(motor2D, LOW);
  digitalWrite(motor1D, HIGH);
}
void avanzarDerecho() {
  digitalWrite(motor1D, LOW);
  digitalWrite(motor2D, HIGH);
}

void retrocederIzquierdo() {
  digitalWrite(motor2I, LOW);
  digitalWrite(motor1I, HIGH);
}
void avanzarIzquierdo() {
  digitalWrite(motor1I, LOW);
  digitalWrite(motor2I, HIGH);
}

void frenarDerecho() {
  digitalWrite(motor1D, LOW);
  digitalWrite(motor2D, LOW);
}

void frenarIzquierdo() {
  digitalWrite(motor1I, LOW);
  digitalWrite(motor2I, LOW);
}

void girarDerecha() {
  retrocederDerecho();
  avanzarIzquierdo();
}

void girarIzquierda() {
  retrocederIzquierdo();
  avanzarDerecho();
}

void avanzar() {
  avanzarDerecho();
  avanzarIzquierdo();
}

void retroceder(){
  retrocederDerecho();
  retrocederIzquierdo();
}