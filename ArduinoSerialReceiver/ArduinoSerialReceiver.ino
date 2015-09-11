/* ArduinoSerialReceiver ---------------------------------------------
author(s): Christian Rodriguez, Dominic Cox
Arduino Sketch meant to get wired and wireless (XBee)communication 
from a joystick to move 2 full rotation servos.
--------------------------------------------------------------------*/

#include <Servo.h>
Servo myservo1;
Servo myservo2;
int pos = 0;

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  Serial.begin(9600);
  
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(10); // attaches the servo on pin 10 to the servo object  
}

void loop()
{
  if (Serial.available())
  { // If data comes in from XBee, send it out to serial monitor
    ////Serial.write(XBee.read());
    //XBee.write(Serial.read());
    
    // Decode joyOutput from transmitter into multiple input commands
    int joyInput = Serial.read();
    
    int joyinput1 = joyInput / 10;
    int joyinput2 = joyInput % 10;
    
    
    
    static int temp1 = -1;
    
    if (temp1 != joyinput1) {
      temp1 = joyinput1;
      int comm1 = map(joyinput1, 0, 7, 0, 180);
      
      if (joyinput1 == 0) {
        myservo1.write(0);
      }
      if (joyinput1 == 1) {
        myservo1.write(70);
      }
      if (joyinput1 == 2) {
        myservo1.write(80);
      }
      if (joyinput1 == 3) {
        myservo1.write(90);
      }
      if (joyinput1 == 4) {
        myservo1.write(100);
      }
      if (joyinput1 == 5) {
        myservo1.write(110);
      }
      if (joyinput1 == 6) {
        myservo1.write(180);
      }
//      Serial.print("comm1: ");
//      Serial.print(comm1);
//      Serial.print(" ---- joyinput1: ");
//      Serial.println(joyinput1);


    }
    

    //int joyinput1 = Serial.read();
    static int temp2 = -1;
    
    //Serial.print("joyinput2: ");
    //Serial.println(joyinput2);
    
    if (temp2 != joyinput2) {
      temp2 = joyinput2;
      int comm2 = map(joyinput2, 0, 7, 0, 180);
      
      if (joyinput2 == 0) {
        myservo2.write(0);
      }
      if (joyinput2 == 1) {
        myservo2.write(70);
      }
      if (joyinput2 == 2) {
        myservo2.write(80);
      }
      if (joyinput2 == 3) {
        myservo2.write(90);
      }
      if (joyinput2 == 4) {
        myservo2.write(100);
      }
      if (joyinput2 == 5) {
        myservo2.write(110);
      }
      if (joyinput2 == 6) {
        myservo2.write(180);
      }

      //Serial.print("comm2: ");
      //Serial.print(comm2);
      //Serial.print(" ---- joyinput2: ");
      //Serial.println(joyinput2);
      
    }
    
    
  }
  //Serial.flush();
}

