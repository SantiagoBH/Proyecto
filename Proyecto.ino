#include <Servo.h>

Servo servo1, servo2;

void setup() 
{
  servo1.attach(9,600,2400);
  servo2.attach(13,600,2400);
  Serial.begin(9600);
}

void loop() { 

  servo1.write (0);
  servo2.write (0);
  delay(2000);
  servo1.write(70);
  servo2.write(70);
  delay(2000);

}
