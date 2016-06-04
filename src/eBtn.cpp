#include "Arduino.h"
#include "eBtn.h"

typedef void (*callBack) ();

// Initialize the button on the specified pin
eBtn::eBtn(int pin){  
  _pin=pin;
  digitalWrite(_pin,LOW);
  pinMode(_pin, INPUT);
  _status = digitalRead(pin);
  _pressThrsld = PressThrsld;
};


//check the status of the button, this function must be called inside a loop() or inside an interrupt
void eBtn::handle(){  

  _prevStatus = _status;
  _status = digitalRead(_pin);
  _event="";

  if(_prevStatus != _status) {
    if(_status == 0 ) {            // button pressed 
        _event="press";
        _startPress = millis();
    } else  {                   // button released
        if(millis()-_startPress>_pressThrsld){
          _event="long";
          _startPress = 0;
        }else{
          _event="release";  
          _startPress = 0;
        }
        _startPress = 0;
    }
  }
    

  if(_event=="press")_press();
  if(_event=="release")_release();
  if(_event=="long")_long();
}

void eBtn::on(String eventName, callBack cb){  
  if(eventName=="press")_press = cb;
  if(eventName=="release")_release = cb;
  if(eventName=="long")_long = cb;
  
}

void eBtn::setThreshold(int t){
  _pressThrsld = t;
}

