//Cat feeder integrated code
#include <ParallaxLCD.h>

#define ROWS 2
#define COLS 16

//Assign each pin a name 
const int ultrasonicTrig = 2;
const int ultrasonicEcho = 3;
const int watersensor = 4;
const int pumprelay = 5;
const int mistrelay = 6;
const int LCDpin = 7;

//ultrasonic variables
long duration;
float distance;

//water sensor variables
int waterState;

//LCD setup
ParallaxLCD lcd(LCDpin,ROWS,COLS); // desired pin, rows, cols

void setup() 
{
  //input/sensor pins
  pinMode(ultrasonicEcho,INPUT);
  pinMode(watersensor,INPUT);

  //output pins
  pinMode(pumprelay,OUTPUT);
  pinMode(mistrelay,OUTPUT);
  pinMode(ultrasonicTrig,OUTPUT);

  //LCD setup
  lcd.setup();
  delay(1000);
  lcd.backLightOn();
  lcd.empty();
  lcd.at(0,3,"Hello Kitty!");

}

void loop() 
{
  //check if there's water
  waterState = digitalRead(watersensor);

  //if there's water, start the whole loop
  if(waterState == 1)
  {
    //mist on by default
    digitalWrite(mistrelay,HIGH);
    digitalWrite(pumprelay,LOW);
    //untrasonc sensor starts
    // Clears the untrasonicTrig
    digitalWrite(ultrasonicTrig, LOW);
    delayMicroseconds(2);
    // Sets the untrasonicTrig on HIGH state for 10 micro seconds
    digitalWrite(ultrasonicTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonicTrig, LOW);
    // Reads the ultrasonicEcho, returns the sound wave travel time in microseconds
    duration = pulseIn(ultrasonicEcho, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; 

    if(distance > 30.00)//mist on when no cat is around

    {
      digitalWrite(pumprelay,LOW);
      digitalWrite(mistrelay,HIGH);
      lcd.empty();
      lcd.at(0,3,"Hello Kitty!");

    }

    else if(distance <= 30.00)//Pump on when cat is closed
    {
      digitalWrite(mistrelay,LOW);
      digitalWrite(pumprelay,HIGH);
      lcd.empty();
      lcd.at(0,1,"Drinking Time"); 
      delay(20000);
      digitalWrite(pumprelay,LOW);

    }

  }

  else if(waterState == 0)//NO water
  {
    digitalWrite(mistrelay,LOW);
    digitalWrite(pumprelay,LOW);
    lcd.empty();
    //lcd.print("Music Maestro!\0");
    lcd.at(0,3,"NO WATER!");
    lcd.playTone(213, 216, 223);
    lcd.playTone(213, 216, 223);
    lcd.playTone(214, 216, 227);
    lcd.playTone(210, 217, 220);
    lcd.playTone(210, 217, 222);
    lcd.playTone(210, 217, 224);
    lcd.playTone(210, 217, 226);
    delay(3000);


  }

}
