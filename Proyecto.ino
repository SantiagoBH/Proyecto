#include <Servo.h>
#include <SoftwareSerial.h>
#define horario 0
#define antihorario 180
#define detener 90
#define TXbluetooth 3
#define RXbluetooth 2

Servo servoD, servoI;

char orden;
SoftwareSerial BT(RXbluetooth,TXbluetooth);

void setup() 
{
  servoD.attach(9);
  servoI.attach(13);
  Serial.begin(9600);
  BT.begin(38400);
  
}

void loop() {
  if (BT.available() > 0)
  orden = BT.read();
  
  switch(orden){
  case 'w':  //Adelante
  servoD.write(horario);
  servoI.write(antihorario);
  break;
  
  case 's': //Atras
  servoD.write(antihorario);
  servoI.write(horario);  
  break;

  case 'a':  //Girar izquiera 
  servoD.write(detener);
  servoI.write(75);  
  break;

  case 'd':  //Girar derecha
  servoD.write(100);
  servoI.write(detener);  
  break;

  case ' ':  //Detenerse
  servoD.write(detener);
  servoI.write(detener);  
  break;
  
  
}
}
