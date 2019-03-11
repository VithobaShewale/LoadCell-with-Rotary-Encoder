#include "HX711.h"
//..............................................................................................//
const int  buttonPin = 4;    // the pin that the pushbutton is attached to
int x=0;
int DT_Pin=3;
int SCK_Pin=2;
//...............................................................................................//
// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
void set_gain(byte gain = 128); // channel A of HX771 can be set for a 128 
//...............................................................................................//
HX711 cell(DT_Pin,SCK_Pin);  // initilization of hx711 module
//...............................................................................................//
void setup() {
  Serial.begin(38400);                        // Serial communication 
  pinMode(buttonPin, INPUT);                   // initialize the button pin as a input
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Step,Val");  
}
//................................................................................................//
long val=0; 
float count=0;
//................................................................................................//
void loop() {
  buttonState = digitalRead(buttonPin);                        // read the pushbutton input pin:
  if (buttonState != lastButtonState) {                        // compare the buttonState to its previous state
    if (buttonState == HIGH) {                                 // if the state has changed, increment the counter
        buttonPushCounter++;                                   // if the current state is HIGH then the button went from off to on
          for (int i=1; i<=1;i=i+1) {
              Serial.print("DATA,TIME,");                      // for Serial Print to identifiy tag
              Serial.print(buttonPushCounter);                 // push button counter
              Serial.print(",");
              Serial.println((double(-cell.read()+98952)/40330.00));  // Reading data from load cell
              }
    } else {
                                                               // if the current state is LOW then the button went from on to off
    }
                                                               // Delay a little bit to avoid bouncing
  }
  lastButtonState = buttonState;                               // save the current state as the last state, for next time through the loop

}
//...................................................................................................//
