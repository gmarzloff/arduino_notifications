#include "Observer.h"


void Observer::init(String _name){
    this->name = _name;
}

void Observer::update(Interval _interval){
    Serial.print("Observer ");
    Serial.print(this->name);
    Serial.println(" updated.");
}


