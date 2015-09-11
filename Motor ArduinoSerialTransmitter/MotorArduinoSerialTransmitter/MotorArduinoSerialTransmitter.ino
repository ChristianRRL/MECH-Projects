/* MotorArduinoSerialTransmitter -------------------------------------
author(s): Christian Rodriguez, Dominic Cox
Arduino Sketch meant to get wired and wireless (XBee)communication 
from a joystick to move 2 motors
--------------------------------------------------------------------*/

const int joy2 = 2;        // first joystick 
const int joy3 = 3;        // second joystick 
// Adjusting for the variance of joy input
int joyMax = 680;
int joyMin = 0;

int joyVal2;           // variable to read the value from the analog pin
int joyVal3;


void setup() {
  // Inizialize Serial
  Serial.begin(9600);
}


void loop(){

  //inputJoystick();
  
  joyVal2 = analogRead(joy2);
  joyVal2 = map(joyVal2, joyMin, joyMax, 0, 7);
  
  joyVal3 = analogRead(joy3);
  joyVal3 = map(joyVal3, joyMin, joyMax, 0, 7);
  
  int joyOutput = joyVal2*10 + joyVal3;
  Serial.write(joyOutput);
  //Serial.println(joyOutput);
  
  //outputJoystick();
  
  delay(15);
}


//Display joystick input values
void inputJoystick(){
    Serial.print(analogRead(joy2));
    Serial.print ("-joystick_one-----"); 
    Serial.print(analogRead(joy3));
    Serial.println ("-joystick_two-------------");
}

//Display joystick output values
void outputJoystick() {
    Serial.print("joyVal2: ");
    Serial.print(joyVal2);
    Serial.print(" ---- joyVal3: ");
    Serial.println(joyVal3);
}

