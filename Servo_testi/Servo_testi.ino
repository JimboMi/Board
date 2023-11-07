#include <Servo.h> //include server library

Servo servo1;
Servo servo2;
Servo servo3;

  //here we create servo objects to control a servo

int pos = 90; //initial position of servos

char val; //initial value of input
char t; //another parameter for values

void setup(){
  Serial.begin(9600); //serial comm begin at 9600bps

  servo1.attach(9); //servo connected to pin 9 
  servo2.attach(10); //servo connected to pin 10
  servo3.attach(11); //servo connected to pin 11
}

void loop(){

  if(Serial.available()){ //if serial value is available
    val = Serial.read(); //then read the serial value
    if(val == 'w'){ //if value input is d
        t = Serial.read(); //read the serial value after FWD or BWD movement
        pos += 90; //servo position increases by 20 (CCW)
        servo1.write(pos); //servo moves according to position
        delay(15); //delay for the servo to get into the position
        if(t == 'a'){
        servo2.write(pos);
        delay(15);
        }
        if(t == 'd'){
        servo3.write(pos);
        delay(15);
        }
    }
    if(val == 's'){
        t = Serial.read(); //get the value of left or right
        pos -= 90; //servo position decreases by 20 (CCW)
        servo1.write(pos); //servo moves according to position
        delay(15); //delay for the servo to get into the position
        if(t == 'a'){
        servo2.write(pos);
        delay(15);
        }
        if(t == 'd'){
        servo3.write(pos);
        delay(15);
        }
    }
  }
}

