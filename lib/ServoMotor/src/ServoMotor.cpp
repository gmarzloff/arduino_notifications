#include <ServoMotor.h>

void ServoMotor::init() {
    Serial.println("ServoMotor online");
    this->name = "ServoMotor";
}

void ServoMotor::update(Interval _interval) {
    Serial.print(this->name);
    Serial.print(" notified about new Interval: ");
    Serial.println(_interval.name);
}