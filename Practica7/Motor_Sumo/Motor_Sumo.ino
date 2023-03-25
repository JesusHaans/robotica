//Christian Alexander Tello Ruiz
//Jesus Haans Lopez Hernandez


//asignaciones 
//Pines del SensorInfrarrojo
int sensorLuz = A0;
//valor del sensorInfrarrojo
int valorLuz;
// valor de luz esperado
int blanco=50;
int negro=600;
//Pines de los Motores
int motorDerechaHigh = 2;
int motorDerechaEnable = 3;
int motorDerechaLow = 4;
int motorIzquierdaHigh = 12;
int motorIzquierdaEnable = 11;
int motorIzquierdaLow = 13;
//pines del Sensor Ultrasonico
int sensorUltrasonicoEcho = 8;
int sensorUltrasonicoTrigger = 7;
// variable para el sensorUltrasonico
long tiempo;
//tiempo que queremos cuando un objeto este a 20 cm
long tiempoObjetivo=20*58;
// timeOut para desechar cosas que esten mas alla del rango del nuestro sensor
long timeOut=400*58;




void setup() {
  // put your setup code here, to run once:
  pinMode(sensorLuz, INPUT);
  pinMode(motorDerechaHigh, OUTPUT);
  pinMode(motorDerechaLow, OUTPUT);
  pinMode(motorDerechaEnable, OUTPUT);
  pinMode(motorIzquierdaHigh, OUTPUT);
  pinMode(motorIzquierdaLow, OUTPUT);
  pinMode(motorIzquierdaEnable, OUTPUT);
  pinMode(sensorUltrasonicoEcho, INPUT);
  pinMode(sensorUltrasonicoTrigger, OUTPUT);
  //lo apagamos para asegurarnos que esta apagado
  digitalWrite(sensorUltrasonicoTrigger,LOW);
  Serial.begin(9600);
}

void loop() {
  //funcionamiento del sensor segun el datasheet
  digitalWrite(sensorUltrasonicoTrigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorUltrasonicoTrigger,LOW);
  // lectura del objeto actual
  tiempo=pulseIn(sensorUltrasonicoEcho,HIGH);
  //Leemos el valor que nos da el sensor infrarojo
  valorLuz = analogRead(sensorLuz);
  //el valor se lo pasamos al Enable de ambos motores
  analogWrite(motorDerechaEnable, 60);
  analogWrite(motorIzquierdaEnable, 60);
  //los pines de los motores los iniciamos para que den vuelta como se debe 
  //Este es el giro en contra de las manecillas del relojViendo el motor de frente(retrosediendo)
  //digitalWrite(motorDerechaHigh,HIGH);
  //digitalWrite(motorDerechaLow,LOW);
  //digitalWrite(motorIzquierdaHigh,HIGH);
  //digitalWrite(motorIzquierdaLow,LOW);
  Serial.println(tiempo);
  if(valorLuz <= blanco && tiempo >= tiempoObjetivo){
    analogWrite(motorDerechaEnable, 60);
    analogWrite(motorIzquierdaEnable, 60);
    digitalWrite(motorDerechaHigh,HIGH);
    digitalWrite(motorDerechaLow,LOW);
    digitalWrite(motorIzquierdaHigh,LOW);
    digitalWrite(motorIzquierdaLow,HIGH);
  }
  if(valorLuz <= negro && tiempo <= tiempoObjetivo){
    analogWrite(motorDerechaEnable, 60);
    analogWrite(motorIzquierdaEnable, 60);
    digitalWrite(motorDerechaHigh,LOW);
    digitalWrite(motorDerechaLow,HIGH);
    digitalWrite(motorIzquierdaHigh,LOW);
    digitalWrite(motorIzquierdaLow,HIGH);
  }
  if(valorLuz <= negro && tiempo >= tiempoObjetivo){
    digitalWrite(motorDerechaHigh,HIGH);
    digitalWrite(motorDerechaLow,LOW);
    analogWrite(motorIzquierdaEnable, 0);
  }
  if(valorLuz <= blanco && tiempo <= tiempoObjetivo){
    analogWrite(motorDerechaEnable, 0);
    analogWrite(motorIzquierdaEnable, 0);
  }
}