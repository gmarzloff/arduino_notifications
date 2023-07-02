# Arduino Notifications

In this example firmware using platformIO, I created an easy way to manage timing of hardware sensors (e.g. `StatusLED`) and outputs on their own clocks without using `delay()`.  The `Cycle` class manages the overall clock, and when a timepoint is reached, it sends a notification to all objects that are in the `observers` array. 