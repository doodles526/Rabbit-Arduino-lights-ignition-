#include <Password.h>



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
  
    
    
