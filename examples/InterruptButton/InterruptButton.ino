/*
	InterruptButton

	Simple sketch to control a button on pin 0 using
	the eBtn library and Interrupt

	The circuit:
	pushButton attached on pin 2

	Created 11 May 2016
	By Davide Andreazzini

  Minor fixes and  changes  by Patrick Nomblot June 2016
  
	https://github.com/david1983/eBtn

*/
#include <eBtn.h>

float t;

#define btnPin  2
eBtn btn = eBtn(btnPin);


void setup() {
	Serial.begin(115200);	
  Serial.println("starting...");
  
	// Here events are defined
	btn.on("press",pressFunc);
	btn.on("release",releaseFunc);
	btn.on("long",longPressFunc);
	//setting the interrupt on btn pin to react on change state
	attachInterrupt(digitalPinToInterrupt(btnPin), pin_ISR, CHANGE);	
}

//function to handle the interrupt event
void pin_ISR(){
	btn.handle();
}


//callbacks functions
void pressFunc(){
	t = millis();
	Serial.println("Btn pressed");
}

void releaseFunc(){	
	Serial.println("Btn released after " + String((millis()-t) /1000) + " seconds");
}

void longPressFunc(){
  Serial.println("Btn released after a long press of " + String((millis()-t) /1000) + " seconds");	
}


void loop() {
    delay(1000);
    Serial.println("Hello from main loop");
}
