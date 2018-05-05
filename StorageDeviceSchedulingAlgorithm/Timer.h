#ifndef TIMER_H
#define TIMER_H

#include <ctime>

struct Timer{
private:
  clock_t Start;
public:
  Timer(){
    Start = clock();
  }
  unsigned long long GetElapsedTime(){ return (clock() - Start); }
  unsigned long long GetStartTime(){ return Start - 0; }
};


#endif // TIMER_H
