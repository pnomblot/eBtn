#ifndef eBtn_h
#define eBtn_h

typedef void (*callBack) ();
#define PressThrsld 1000

class eBtn{
public:
  eBtn(int pin);
  void handle();
  void setThreshold(int t);
  void on(String eventName, callBack cb);
private:
  int _pin,_status,_prevStatus, _pressThrsld;
  long _startPress;  
  int _event;
  callBack _press, _release, _hold, _long;
};

#endif
