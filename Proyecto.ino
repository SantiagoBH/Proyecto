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
<<<<<<< HEAD
=======

}
>>>>>>> bdceecae66f6cf44c928bc6b40461d9cee9c3cba
  
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
  case 'j'  // Esquivar oponente hacia la derecha
  servoD.write(horario);
  servoI.write(antiorario); 
  delay(2000);
  servoD.write(100);
  servoI.write(75);
  case 'g'  // Esquivar oponente hacia la izquierda
  servoD.write(horario);
  servoI.write(antiorario); 
  delay(2000);
  servoD.write(75);
  servoI.write(100);
  
<<<<<<< HEAD
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
=======
  default:
  ServoD.write(detener);
  ServoI.write(detener);
  break;
>>>>>>> bdceecae66f6cf44c928bc6b40461d9cee9c3cba
}

