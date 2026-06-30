#include <Servo.h>
#include <Arduino_Modulino.h>
 
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

ModulinoBuzzer buzzer;
ModulinoDistance distance;

int frequency = 440;  // Frequency of the tone in Hz
int duration = 1000;  // Duration of the tone in milliseconds

void watergatec(int deg){
   

  if (deg == 90){ // found
     myservo.write(deg); 
    Serial.println("CLOSE GATE FOUND BLACK");
            buzzer.tone(frequency, duration);  // Generate the tone
      delay(500);   
          buzzer.tone(frequency, duration);  // Generate the tone
      delay(500);   
          buzzer.tone(frequency, duration);  // Generate the tone
      delay(500); 
  }
  else { // not found
     
     
    if (distance.available()){
      int measure = distance.get();
      
        if (measure < 91 ){
            myservo.write(90); 
          Serial.println("CLOSE GATE DISTANCE");

        }
      else {
        Serial.println("OPEN GATE not FOUND BLACK");
        myservo.write(deg); 
      }
      
    }
    
  }

 

}

void setup() {
  Bridge.begin();
  Bridge.provide("watergatec", watergatec);
  myservo.attach(6);  // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);
  
  Modulino.begin();
  distance.begin();
  
  Serial.println("Water Level");
  Serial.println("===================");
  Modulino.begin();
  buzzer.begin();
}



 
void loop() {
  /*
  if (distance.available()) {
    int measure = distance.get();
    if (measure < 91 ){
      openWater();
        buzzer.tone(frequency, duration);  // Generate the tone
        delay(1000);  // Wait for 1 second
    }
    else {
      closeWater();

    }
  }
  delay(100);  // Update 10 times per second
*/
}