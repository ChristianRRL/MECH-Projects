/* ArduinoSerialReceiver ---------------------------------------------
author(s): Christian Rodriguez, Dominic Cox
Arduino Sketch meant to get wired and wireless (XBee)communication 
from a joystick to move 2 full rotation servos.
--------------------------------------------------------------------*/


int pos = 0;

int joyinput2;

const int motorA = 12;
const int brakeA = 9;
const int motorB = 13;
const int brakeB = 8;

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  
  // Initialize Serial
  Serial.begin(9600);
  
  //Setup Channel A
  pinMode(motorA,OUTPUT); //Initiates Motor Channel A pin
  pinMode(brakeA,OUTPUT);  //Initiates Brake Channel A pin
  
  //Setup Channel B
  pinMode(motorB,OUTPUT); //Initiates Motor Channel B pin
  pinMode(brakeB,OUTPUT);  //Initiates Brake Channel B pin
}

void loop()
{
  
  if (Serial.available())
  { // If data comes in from XBee, send it out to serial monitor
    ////Serial.write(XBee.read());
    //XBee.write(Serial.read());
        
    // Decode joyOutput from transmitter into multiple input commands
    int joyInput = Serial.read();
    
    joyinput2 = joyInput / 10;
    joyinput3 = joyInput % 10;
    
//    inputJoystick();
    
    static int temp1 = -1;
    
    if (temp1 != joyinput2) {
      temp1 = joyinput2;
      //int comm1 = map(joyinput3, 0, 7, 0, 180); //for testing only
      
      // Motor moving forward
      if (joyinput2 == 0) {
        digitalWrite(12,HIGH); //Establishes forward direction of Channel A
        digitalWrite(9,LOW);   //Disengage the Brake for Channel A
        analogWrite(3,250);    //Spins the motor on Channel A at full speed
      }
      
      // Motor breaking
      if (joyinput2 == 3) {
        digitalWrite(9, HIGH); //Engage the Brake for Channel A
      }
      
      // Motor moving backward
      if (joyinput2 == 6) {
        digitalWrite(12,LOW); //Establishes backward direction of Channel A
        digitalWrite(9,LOW);   //Disengage the Brake for Channel A
        analogWrite(3,250);    //Spins the motor on Channel A at full speed
      }
//      Serial.print("comm1: ");
//      Serial.print(comm1);
//      Serial.print(" ---- joyinput3: ");
//      Serial.println(joyinput3);


    }
    

    //int joyinput3 = Serial.read();
    static int temp2 = -1;
    
    //Serial.print("joyinput3: ");
    //Serial.println(joyinput3);
    
    if (temp2 != joyinput3) {
      temp2 = joyinput3;
      //int comm2 = map(joyinput3, 0, 7, 0, 180);
      
      // Motor moving backward
      if (joyinput3 == 0) {
        digitalWrite(13,HIGH); //Establishes forward direction of Channel A
        digitalWrite(8,LOW);   //Disengage the Brake for Channel A
        analogWrite(11,150);    //Spins the motor on Channel A at full speed
      }
      
      // Motor breaking
      if (joyinput3 == 3) {
        digitalWrite(8, HIGH); //Engage the Brake for Channel A
      }
      
      // Motor moving backward
      if (joyinput3 == 6) {
        digitalWrite(13,LOW); //Establishes backward direction of Channel A
        digitalWrite(8,LOW);   //Disengage the Brake for Channel A
        analogWrite(11,250);    //Spins the motor on Channel A at full speed
      }

      //Serial.print("comm2: ");
      //Serial.print(comm2);
      //Serial.print(" ---- joyinput3: ");
      //Serial.println(joyinput3);
      
    }
    
    
  }
  Serial.flush();
}

//Display joystick input values
void inputJoystick(){
    Serial.print(joyinput2);
    Serial.print ("-joystick_one-----"); 
    Serial.print(joyinput3);
    Serial.println ("-joystick_two-------------");
}


