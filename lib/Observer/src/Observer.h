#ifndef OBSERVER_H
#define OBSERVER_H
#include <Arduino.h>
#include <Interval.h>

class Observer {

public:
    String name;
    void init(String name);
    virtual void update(Interval _interval);
};

#endif