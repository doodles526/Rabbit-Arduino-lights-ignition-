/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

//blinker inputs
int leftBlinkIn = 9;
int rightBlinkIn = 8;

//blinker output
int leftBlinkOut = 7;
int rightBlinkOut = 6;

//ignition on output
int ignition = 5;

//engine power on output
int engineOn = 4;

//error blinker light
int error_light = 3;

//ignition code and starter off of keypad, also the off press
int keypad = A0;

//power password
int pass[10] = {7, 6, 6, 5, 3, 9, 3, 3, 8, 1};

int passIndex = 0;
int keyPressed = 0;

unsigned long blinktime = micros();
unsigned long errortime = micros();
int errorblinks = 0;
int error_set = 0;

//**************************************************************************
//**************************************************************************
void setup() {                
  //init output pins
  pinMode(leftBlinkOut, OUTPUT);
  pinMode(rightBlinkOut, OUTPUT);
  pinMode(ignition, OUTPUT);
  pinMode(engineOn, OUTPUT);
  pinMode(error_light, OUTPUT);
  
  //init input pins
  pinMode(leftBlinkIn, INPUT);
  pinMode(rightBlinkIn, INPUT);
  pinMode(keypad, INPUT);
  
}
//***************************************************************************
//***************************************************************************

//***************************************************************************
//***************************************************************************
void loop() {
  if(digitalRead(leftBlinkIn))  
    blinker(leftBlinkOut);
  
  if(digitalRead(rightBlinkIn))
    blinker(rightBlinkOut);
  
  if(error_set)  
    error_blink();
  
  int current_val = key_from_analog(analogRead(keypad));
  
  if(keyPressed && current_val == -1)  {
    keyPressed = 0;
    digitalWrite(ignition, LOW);
  }
  
  if(current_val != -1 || current_val - 9 > 0)  {
    iterate_pass_val(current_val);
  }

  if(current_val == 10)  {
    digitalWrite(engineOn, LOW);
  }
  
  if(current_val == 11 && digitalRead(engineOn))  {
    digitalWrite(ignition, HIGH);
  }
}
//*************************************************************************
//*************************************************************************
//*************************************************************************


//manage the password state machine
void iterate_pass_val(int passkey)  {
  if(passkey == pass[passIndex])  {
    passIndex++;
    if(passIndex >= (sizeof(pass) / sizeof(int)))  {
      //have green LED wired in line to the relay here
      digitalWrite(engineOn, HIGH);
    }
  }
  else  {
    passIndex = 0;
    error_set = 1;
  }
}



//NEED TO WRITE AFTER CONSTRUCTING KEYPAD
int key_from_analog(int key_val)  {
  return 1;
}


void error_blink()  {
  if(micros() - errortime > 350)  {
    digitalWrite(error_light, !digitalRead(error_light));
    errorblinks++;
    errortime = micros();
  }
  if(errorblinks >= 8)
    error_set = 0;
}
    

void blinker(int side)  {
  if(micros() - blinktime > 500)  {
    digitalWrite(side, !digitalRead(side));
    blinktime = micros() ;
 }
}
