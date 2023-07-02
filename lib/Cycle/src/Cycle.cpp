#include <Cycle.h>

Cycle::Cycle() {

}

void Cycle::init(){
    // Sequence markers
    this->tiltback_warning = Interval(
        0, 
        1000 * 5,// 8 seconds
        "Tilt Back Warning Mode"
    ); 

    this->tiltback_hold = Interval(
        tiltback_warning.end + 1, 
        //tiltback_warning.end + 1 + 1000 * 60 * 2 // 2 min
        tiltback_warning.end + 1 + 1000 * 5, // 10 sec
        "Tilt Back Pressure Relief Hold" 
    ); 

    this->tiltforward_warning = Interval( 
        tiltback_hold.end + 1, 
        tiltback_hold.end + 1 + 1000 * 5, // 8 seconds
         "Tilt Forward Warning Mode"
    );

    this->tiltforward_hold = Interval(
        tiltforward_warning.end + 1, 
        //tiltforward_warning.end + 1 + 1000 * 60 * 15 // 15 min
        tiltforward_warning.end + 1 + 1000 * 5, // 15 sec
        "Tilt Forward to Upright Hold" 
    );

    this->current_interval = this->tiltback_warning;
    this->start_time = millis();
    this->counter = 1;

    Serial.println("0.0s Cycle 1 Clock Started");
}

void Cycle::interval_changed(){
    Serial.print("New Interval: ");
    Serial.println(this->current_interval.name);
    this->notifyObservers();

}

Interval Cycle::get_current_interval() const {
    return this->current_interval;
}

void Cycle::addObserver(Observer* observer, unsigned int position){
   this->observers[position] = observer;
   Serial.print("Added Observer ");
   Serial.print(this->observers[position]->name);
   Serial.print(" ");
   Serial.println(position);

}

void Cycle::notifyObservers(){
    unsigned int count = sizeof(this->observers)/sizeof(this->observers[0]);
    for (unsigned int i = 0; i < count; ++i) {
        this->observers[i]->update(this->current_interval);
    }
}

void Cycle::reset_clock(){
    this->start_time = millis();
    float uptime_sec = this->start_time / 1000;
    this->counter++;
    Serial.print(uptime_sec);
    Serial.print("s Cycle ");
    Serial.println(this->counter);
}

void Cycle::analyze_clock(){

    unsigned long current_millis = millis();
    unsigned long relative_millis = current_millis - this->start_time;
    Interval identified_interval;

    if(relative_millis >= this->tiltback_warning.start && 
    relative_millis <= this->tiltback_warning.end){
        identified_interval = this->tiltback_warning;
    } 
    else if(relative_millis >= this->tiltback_hold.start && 
    relative_millis <= this->tiltback_hold.end){
        identified_interval = this->tiltback_hold;
    }
    else if(relative_millis >= this->tiltforward_warning.start && 
    relative_millis <= this->tiltforward_warning.end){
        identified_interval = this->tiltforward_warning;
    }
    else if(relative_millis >= this->tiltforward_hold.start && 
    relative_millis <= this->tiltforward_hold.end){
        identified_interval = this->tiltforward_hold;

    } else if(relative_millis >=this->tiltforward_hold.end){
        identified_interval = this->tiltback_warning;
        this->reset_clock();
    }

    if(identified_interval != this->current_interval){
        this->current_interval = identified_interval;
        this->interval_changed();
    }
}