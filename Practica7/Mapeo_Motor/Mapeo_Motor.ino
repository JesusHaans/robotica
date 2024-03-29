//Christian Alexander Tello Ruiz
//Jesus Haans Lopez Hernandez


//asignaciones 
//Pines del SensorInfrarrojo
int sensorLuz = A0;
//valor del sensorInfrarrojo
int valorLuz;
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
  pinMode(A0, INPUT);
  pinMode(motorDerechaHigh, OUTPUT);
  pinMode(motorDerechaLow, OUTPUT);
  pinMode(motorDerechaEnable, OUTPUT);
  pinMode(motorIzquierdaHigh, OUTPUT);
  pinMode(motorIzquierdaLow, OUTPUT);
  pinMode(motorIzquierdaEnable, OUTPUT);
  pinMode(sensorUltrasonicoEcho, INPUT);
  pinMode(sensorUltrasonicoTrigger, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorLuz = 0;
  //Leemos el valor que nos da el sensor infrarojo
  valorLuz = analogRead(A0);
  //lo imprimimos para ver cual es
  Serial.println(valorLuz);
  //lo mapeamos con los valores del map de un pin pwm
  valorLuz = map(valorLuz, 0, 1023, 0, 255);
  //el valor se lo pasamos al Enable de ambos motores
  analogWrite(motorDerechaEnable, valorLuz);
  analogWrite(motorIzquierdaEnable, valorLuz);
  //los pines de los motores los iniciamos para que den vuelta como se debe 
  digitalWrite(motorDerechaHigh,HIGH);
  digitalWrite(motorDerechaLow,LOW);
  digitalWrite(motorIzquierdaHigh,HIGH);
  digitalWrite(motorIzquierdaLow,LOW);
}
