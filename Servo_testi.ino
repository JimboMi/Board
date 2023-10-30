#include <Servo.h> //include server library

Servo servo1;
Servo servo2;
Servo servo3;

  //here we create servo objects to control a servo

int pos = 90; //initial position of servos

char val; //initial value of input

void setup(){
  Serial.begin(9600); //serial comm begin at 9600bps

  servo1.attach(9); //servo connected to pin 9 
  servo2.attach(10); //servo connected to pin 10
  servo3.attach(11); //servo connected to pin 11
}

void loop(){

  if(Serial.available()){ //if serial value is available
    val = Serial.read(); //then read the serial value
    if(val == 'd'){ //if value input is d
        pos += 20; //servo position increases by 20 (CCW)
        servo1.write(pos); //servo moves according to position
        delay(15); //delay for the servo to get into the position

        servo2.write(pos);
        delay(15);
        
        servo3.write(pos);
        delay(15);
    }
    if(val == 'a'){
        pos -= 20; //servo position decreases by 20 (CCW)
        servo1.write(pos); //servo moves according to position
        delay(15); //delay for the servo to get into the position

        servo2.write(pos);
        delay(15);
        
        servo3.write(pos);
        delay(15);
    }
  }
}

