#ifndef INTERVAL_H
#define INTERVAL_H

#include <Arduino.h>

class Interval {
public:
    unsigned long start;
    unsigned long end;
    String name;

    Interval();
    Interval(int _start, int _end, String _name);
    void print_description();

    bool operator != (const Interval& other) const {
        return !(start == other.start &&
            end == other.end &&
            name == other.name);
    }

    bool operator == (const Interval& other) const {
        return start == other.start &&
            end == other.end &&
            name == other.name;
    }
 
};

#endif
