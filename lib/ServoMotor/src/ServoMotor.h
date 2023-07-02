#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H
#include <Observer.h>

class ServoMotor : public Observer {
public:
    void init();
    void update(Interval _interval) override;

}; 

#endif