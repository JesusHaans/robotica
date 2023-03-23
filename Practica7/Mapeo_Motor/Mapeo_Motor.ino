//Christian Alexander Tello Ruiz
//Jesus Haans Lopez Hernandez


//asignaciones 
//Pines del SensorInfrarrojo
int sensorLuz = A0;
//valor del sensorInfrarrojo
long valorLuz;
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

}

void loop() {
  // put your main code here, to run repeatedly:
  valorLuz = analogRead(sensorLuz);
  valorLuz = map(valorLuz, 0, 1023, 0, 255);
  analogWrite(motorDerechaEnable, valorLuz);
  analogWrite(motorIzquierdaEnable, valorLuz);
  digitalWrite(motorDerechaHigh,HIGH);
  digitalWrite(motorDerechaLow,LOW);
  digitalWrite(motorIzquierdaHigh,HIGH);
  digitalWrite(motorIzquierdaLow,LOW);
}
