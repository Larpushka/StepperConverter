/*
 Script written by Larpushka on May 8th, 2020
 Visit my Youtube Channel 'Larpushka' for all things related to extreme forms of virtual reality escapism 
 */

#include <Keyboard.h>

//pre-defining a timer for each sensor
unsigned long TimeNine;
unsigned long TimeEight;
unsigned long TimeSeven;
unsigned long TimeSix;
unsigned long TimeFive;
unsigned long TimeFour;
unsigned long CurrentTime;


//preparing each sensor with its own variable
int PinNine = 0;
int PinEight = 0;
int PinSeven = 0;
int PinSix = 0;
int PinFive = 0;
int PinFour = 0;



int MoveDelay = 250; //The amount of time in ms it presses 'w'
int MoveDelayEdge = 350; //The amount of time in ms it presses 'w' when it reaches the uppermost and lowestmost sensor

//This boolean is essentially like a switch the keeps track whether the sensor is being pressed and released, it's used in the algorithm so it knows when to press and when to release
bool ReactivatedNine;
bool ReactivatedEight;
bool ReactivatedSeven;
bool ReactivatedSix;
bool ReactivatedFive;
bool ReactivatedFour;



void setup() {
  // defining the pins to the outputs
Serial.begin(9600);
Keyboard.begin();
pinMode(9, INPUT);
pinMode(8, INPUT);
pinMode(7, INPUT);
pinMode(6, INPUT);
pinMode(5, INPUT);
pinMode(4, INPUT);


}


void loop() {
  // Checking the value in each loop
  PinNine = digitalRead(9);
Serial.println(PinEight);
   PinEight = digitalRead(8);
Serial.println(PinSeven);
  PinSeven = digitalRead(7);
Serial.println(PinSix);
  PinSix = digitalRead(6);
Serial.println(PinFive);
  PinFive = digitalRead(5);
Serial.println(PinFour);
  PinFour = digitalRead(4);
Serial.println(PinFour);

//presses 'w' for the amount defined in MoveDelayEdge and MoveDelay every time the sensor is hit with a white stripe
if (PinNine == 1 && ReactivatedNine == true)
{
  Keyboard.press('w');
    delay(MoveDelayEdge);
  ReactivatedNine = false;
  TimeNine = millis(); 
}

if (PinEight == 1 && ReactivatedEight == true)
{
  Keyboard.press('w');
  delay(MoveDelay);
  ReactivatedEight = false;
  TimeEight = millis();
}
if (PinSeven == 1 && ReactivatedSeven == true)
{
  Keyboard.press('w');
    delay(MoveDelay);
  ReactivatedSeven = false;
  TimeSeven = millis(); 
}
if (PinSix == 1 && ReactivatedSix == true)
{
  Keyboard.press('w');
    delay(MoveDelay);
  ReactivatedSix = false;
  TimeSix = millis(); 
}
if (PinFive == 1 && ReactivatedFive == true)
{
  Keyboard.press('w');
    delay(MoveDelay);
  ReactivatedFive = false;
  TimeFive = millis(); 
}
if (PinFour == 1 && ReactivatedFour == true)
{
  Keyboard.press('w');
    delay(MoveDelayEdge);
  ReactivatedFour = false;
  TimeFive = millis(); 
}


//making sure the sensor is reactivate (ready to press 'w' again) once it shuts down
if (PinNine == 0)
{
  ReactivatedNine = true;
}
if (PinEight == 0)
{
  ReactivatedEight = true;
}
if (PinSeven == 0)
{
  ReactivatedSeven = true;
}
if (PinSix == 0)
{
  ReactivatedSix = true;
}
if (PinFive == 0)
{
  ReactivatedFive = true;
}
if (PinFour == 0)
{
  ReactivatedFour = true;
}


//Officially stops pressing 'w' if no movement is detected that is higher than what's defined in MoveDelay and MoveDelayEdge 
CurrentTime = millis();

if (CurrentTime-MoveDelay>TimeFive)
{
Keyboard.release('w');
}
if (CurrentTime-MoveDelay>TimeSix)
{
Keyboard.release('w');
}
if (CurrentTime-MoveDelay>TimeSeven)
{
Keyboard.release('w');
}

if (CurrentTime-MoveDelay>TimeEight)
{
Keyboard.release('w');
}

if (CurrentTime-MoveDelayEdge>TimeFour)
{
Keyboard.release('w');
}
if (CurrentTime-MoveDelayEdge>TimeNine)
{
Keyboard.release('w');
}


}
