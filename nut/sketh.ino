#include <Servo.h>


// Create servo objects t
Servo servo1;

// Variables to store the servo positions
int posLeft = 0;
int posRight = 180;
int deg = 90;


void servo(int deg) {
  Serial.print("Called servo in C ");
  Serial.println(deg);
  servo1.write(deg);

  // for (int i = 0; i <= deg; i += 1) { 
  //   servo1.write(i);             // Moves 0 to 180;   // Moves 180 to 0
  //   delay(15);                   // Wait 15ms for the servos to reach the position
  // }  
}

void setup() {
  Serial.begin(9600); 
  servo1.attach(6);  
  servo1.write(0);
  Bridge.begin();
  // Allow Python to call 
  Bridge.provide("servo", servo);
  
}

void loop() {

}