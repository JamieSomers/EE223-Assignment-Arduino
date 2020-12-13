# EE223-Assignment-Arduino
Included is all versions of the Arduino code I made for my electronics module assignment.

Counter:
This file is the initial code used to make two 7-Segment display's count down from 10 to 0 with a delay of 1 second between each value.

Counter_V1:
Changed the counter code to be from pin 2 to pin 10, since I found that pin 1 would give a constant output, most likely due to its multifunctionality as a TX pin. Updated delay time to be 900.965 miliseconds, instead of 1 second.

Counter_V2:
Included support for LDR and Temperature Sensor located in pins A0 and A5 respectively. These values are printed to the serial monitor once the timer reaches 0.

Counter_V3:
Updated Temperature Sensor output to be the calculated temperature of the room in degrees celsius and kelvin.

Counter_V4:
Included support for an LED warning light which activates if either sensor is determined to be non-functioning. If the V_0 value reaches below 10 or the Temperature sensor reads a value of 1023. This includes a warning to the serial monitor that a failure was detected.

Counter_V5:
Fixed an issue where the serial monitor issue would only warn that a failure was detected for the LDR if both sensors failed. The warning light now also deactives if the sensors are fixed before the counter reaches 0, without the need for a manual reset.

Counter_FINAL:
In this version the circuit is working exactly how I had intended it to, and I finally added proper comments.
