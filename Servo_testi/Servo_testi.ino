#include <Servo.h>

int pos = 90;

Servo servo1;
Servo servo2;
Servo servo3;

void setup()
{
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
}

void loop()
{
  servo1.write(90);
  delay(150);

  servo2.write(130);
  delay(1500);
  
  servo2.write(0);
  delay(1500);

  servo3.write(90);
  delay(15);
  }
