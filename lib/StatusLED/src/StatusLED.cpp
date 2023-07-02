#include "StatusLED.h"

void StatusLED::init() {
  Serial.println("Status LED online");
  this->name = "StatusLED";
}

// void StatusLED::update() {
//   Serial.print(this->name);
//   Serial.println(" updated");
// }