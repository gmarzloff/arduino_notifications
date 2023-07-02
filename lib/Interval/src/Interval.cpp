#include <Interval.h>

Interval::Interval(){

}

Interval::Interval(int _start, int _end, String _name){
    this->start = _start;
    this->end = _end;
    this->name = _name;
}

void Interval::print_description() {
    Serial.print(this->name);
    Serial.print(" ");
    Serial.print(this->start);
    Serial.print("s -> ");
    Serial.print(this->end);
    Serial.println("ms");
}