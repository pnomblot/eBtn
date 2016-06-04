# eBtn
An Arduino library to create buttons and handle events using callbacks.
The library handle the following events:

- press
- release
- longPress

**Usage**
    
    eBtn btn = eBtn(btnPin);
    
    btn.on("press",pressFunc);
	btn.on("release",releaseFunc);
	btn.on("long",longPressFunc);

...

    void pressFunc(){
      //do something here
    }
    void releaseFunc(){
      //do something else here
    }
    void longPressFunc(){
      //do something usefull here
    }
    
    // Note that not all input Pins can handle interrupt, check model.
    // Pins 2 and 3 are availables for that on Arduino Nano and Pro Micro.
    


