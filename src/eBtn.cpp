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
  _event=0;

  if(_prevStatus != _status) {
    if(_status == 0 ) {            // button pressed 
        _event = 1;
        _startPress = millis();
    } else  {                   // button released
        if(millis()-_startPress>_pressThrsld){
          _event = 2;
        }else{
          _event = 3;  
        }
        _startPress = 0;
    }
  }
    

  if(_event == 1)_press();
  if(_event == 2)_long();
  if(_event == 3)_release();
}

void eBtn::on(String eventName, callBack cb){  
  if(eventName=="press")_press = cb;
  if(eventName=="release")_release = cb;
  if(eventName=="long")_long = cb;
  
}

void eBtn::setThreshold(int t){
  _pressThrsld = t;
}

