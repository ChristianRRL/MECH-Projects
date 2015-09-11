const int motorA = 12;
const int brakeA = 9;
const int motorB = 13;
const int brakeB = 8;

const int joy2 = 2;        // first joystick 
const int joyMax = 680;
const int joyMin = 0;

int joyVal2;
void setup()
{  
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
  // Reading single joystick
  joyVal2 = analogRead(joy2);
  // Mapping joystick data to 0-7 values
  joyVal2 = map(joyVal2, joyMin, joyMax, 0, 7);
  
  // Output data to Receiver XBee
  int joyOutput = joyVal2;
  Serial.write(joyOutput);
}

