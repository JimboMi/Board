#include <Servo.h>

Servo servoW;
Servo servoA;
Servo servoD;

int servoPinW = 9;  // Connect the servoW signal wire to digital pin 9
int servoPinA = 10; // Connect the servoA signal wire to digital pin 10
int servoPinD = 11; // Connect the servoD signal wire to digital pin 11

int keyWState = 0;  // Variable to store the 'W' key state
int keyAState = 0;  // Variable to store the 'A' key state
int keyDState = 0;  // Variable to store the 'D' key state

void setup() {
  servoW.attach(servoPinW);
  servoA.attach(servoPinA);
  servoD.attach(servoPinD);

  Serial.begin(9600);
}

void loop() {
  // Check if a key is pressed
  if (Serial.available() > 0) {
    char key = Serial.read();

    if (key == 'W' || key == 'w'{
      if (keyWState == 0) {
        // 'W' key is pressed, turn the servoW to a specific angle (adjust as needed)
        servoW.write(90);
        keyWState = 1;
      }
    } else if (key == 'A' || key == 'a') {
      if (keyWState == 1 && keyAState == 0) {
        // 'A' key is pressed while 'W' is held down, turn the servoA to a specific angle in the opposite direction (adjust as needed)
        servoA.write(180);  // Set the servo angle in the opposite direction (adjust as needed)
        keyAState = 1;
      }
    } else if (key == 'D' || key == 'd') {
      if (keyWState == 1 && keyDState == 0) {
        // 'D' key is pressed while 'W' is held down, turn the servoD to a specific angle in the opposite direction (adjust as needed)
        servoD.write(180);  // Set the servo angle in the opposite direction (adjust as needed)
        keyDState = 1;
      }
    } else {
      // Key is released, reset states accordingly
      if (keyWState == 1) {
        servoW.write(0);
        keyWState = 0;
      }
      if (keyAState == 1) {
        servoA.write(90);
        keyAState = 0;
      }
      if (keyDState == 1) {
        servoD.write(90);
        keyDState = 0;
      }
    }
  }
}
