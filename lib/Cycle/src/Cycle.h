#ifndef CYCLE_H
#define CYCLE_H
#include <Arduino.h>
#include <Observer.h>
#include <Interval.h>

class Cycle {

public:
    unsigned long start_time;
    int counter;

    Interval tiltback_warning;
    Interval tiltback_hold;
    Interval tiltforward_warning;
    Interval tiltforward_hold;
    
    Cycle();
    void init();
    void analyze_clock();
    void reset_clock();
    void addObserver(Observer* observer, unsigned int index);
    void notifyObservers();
    Interval get_current_interval() const;
    
private:
    void interval_changed();
    Interval current_interval;
    Observer* observers[2];


};

#endif