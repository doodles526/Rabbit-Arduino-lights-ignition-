#include <Password.h>

/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int led = 2;
Password password = Password("12345");


int sensorValue = 0;        // value read from the pot


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  if(sensorValue > 0)  {
    digitalWrite(led, HIGH);
  }
  else  {
    digitalWrite(led, LOW);
  }
  // change the analog out value:

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.println(keyval(sensorValue));      
  

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}

char keyval(int val)  {
  if (val < 5)
    return 'N';
  if(val < 60)  
    return 'A';
  if(val < 90)  
    return 'B';
  if(val < 110)
    return 'C';
  if(val < 130)
    return '3';
  if (val < 170)
    return '6';
  if(val < 200)
    return 'D';
  if(val < 230)
    return '9';
  if(val < 280)
    return '2';
  if(val < 330)
    return '5';
  if(val < 360)
    return '#';
  if(val < 450)
    return '8';
  if(val < 525)
    return '1';
  if(val < 575)
    return '0';
  if(val < 650)
    return '4';
  if(val < 750)
    return '7';
  return '*';
}
  
    
    
