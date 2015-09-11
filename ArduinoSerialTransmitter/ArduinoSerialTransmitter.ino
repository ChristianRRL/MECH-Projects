/* ArduinoSerialTransmitter ------------------------------------------
author(s): Christian Rodriguez, Dominic Cox
Arduino Sketch meant to get wired and wireless (XBee)communication 
from a joystick to move 2 full rotation servos.
--------------------------------------------------------------------*/

#include <Servo.h>
//#include<string>

const int servo1 = 9;       // first servo
const int servo2 = 10;       // second servo
const int joy1 = 3;        // first joystick 
const int joy2 = 4;        // second joystick 
// Adjusting for the variance of joy input
int joy_max = 680;
int joy_min = 0;

int joyVal1;           // variable to read the value from the analog pin
int joyVal2;

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo



void setup() {

  // Servo  
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo

  // Inizialize Serial
  Serial.begin(9600);
}


void loop(){

    // Display Joystick input values using the serial monitor
    //inputJoystick();

    // Read the horizontal joystick value  (value between 0 and joy_max)
    joyVal1 = analogRead(joy1);
    joyVal1 = map(joyVal1, joy_min, joy_max, 0, 7);     // scale it to use it with the servo (result  between 70 and 180)
    //Serial.write(joyVal1);
    //myservo1.write(servoVal1);                         // sets the servo position according to the scaled value    


    // Read the horizontal joystick value  (value between 0 and joy_max)
    joyVal2 = analogRead(joy2);           
    joyVal2 = map(joyVal2, joy_min, joy_max, 0, 7);     // scale it to use it with the servo (result between 70 and 180)    
    //Serial.write(joyVal2);
    //myservo2.write(servoVal2);                           // sets the servo position according to the scaled value
    
    // Encode joyVal1 and joyVal2 into single string for output
    int joyOutput = joyVal1*10 + joyVal2;
    Serial.write(joyOutput);
    
    /*
    int joyinput1 = joyOutput / 10;
    int joyinput2 = joyOutput % 10;
    
    Serial.print("joyinput1: ");
    Serial.print(joyinput1);
    Serial.print(" --- joyinput2: ");
    Serial.println(joyinput2);
    */
    
    //Serial.println(joyOutput);
    
    delay(15);                                       // waits for the servo to get there
    
    // Display Joystick output values using the serial monitor    
    //outputJoystick();
}


//Display joystick input values
void inputJoystick(){
    Serial.print(analogRead(joy1));
    Serial.print ("-joystick_one-----"); 
    Serial.print(analogRead(joy2));
    Serial.println ("-joystick_two-------------");
}

//Display joystick output values
void outputJoystick() {
    Serial.print("joyVal1: ");
    Serial.print(joyVal1);
    Serial.print(" ---- joyVal2: ");
    Serial.println(joyVal2);

}

