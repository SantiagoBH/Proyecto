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
  BT.begin(9600);
  
}

void loop(){
  if (Serial.available() > 0)
  {
    orden = Serial.read();
    Serial.write(orden);
  }
     
  if (BT.available() > 0)
  {
    orden = BT.read();
    Serial.write(orden);
  }
  
  switch(orden){
  case 'w':  //Adelante
  servoD.write(horario);
  servoI.write(antihorario);
  break;
  
  case 's': //Atras
  servoD.write(antihorario);
  servoI.write(horario);  
  break;

  case 'a':  //Girar izquierda 
  servoD.write(75);
  servoI.write(detener);  
  break;

  case 'd':  //Girar derecha
  servoD.write(detener);
  servoI.write(100);  
  break;

  case 'y':  //Detenerse
  servoD.write(detener);
  servoI.write(detener);  
  break;
  
  case 'j':  // Correr con curva 
  servoD.write(horario);
  servoI.write(antihorario); 
  delay(900);
  servoD.write(detener);
  servoI.write(100);
  break;
 
  case 'g': // correr en zic zac
  servoD.write(detener);
  servoI.write(100);
  delay(300); 
  servoD.write(horario);
  servoI.write(antihorario); 
  delay(600);
  servoD.write(0);
  servoI.write(detener);
  delay(300);
  break;

  case 'm': // Ruleta
  servoD.write(detener);
  servoI.write(100);
  delay(3500);
  servoD.write(horario);
  servoI.write(antihorario);
  delay(2000);
  break;

  default:
  servoD.write(detener);
  servoI.write(detener);  
  break;
  
}
}
