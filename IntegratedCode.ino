//Cat feeder integrated code
#include <ParallaxLCD.h>

#define ROWS 2
#define COLS 16

//Assign each pin a name 
int untrasonic = 2;
int watersensor = 3;
int pumprelay = 4;
int mistrealy = 5;


void setup() 
{
  //input/sensor pins
  pinMode(untrasonic,INPUT);
  pinMode(watersensor,INPUT);

  //output pins
  pinMode(pumprelay,OUTPUT);
  pinMode(mistrelay,OUTPUT);
  


}

void loop() 
{
  // put your main code here, to run repeatedly:

}
