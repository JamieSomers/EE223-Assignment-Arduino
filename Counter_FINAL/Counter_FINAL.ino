// The 7-Segment Display Counter
// The Counting Programme - Counts 10-0 - Then records LDR and Temperature Sensor values.
int ldrPin = A0; // select the input pin A0 for the LDR input
int ldrValue = 0; // variable to store the value coming from the LDR
int TempPin = A5; // select the input pin A5 for the Temperature input
int TempValue = 0; // variable to store the value coming from the Temperature Sensor
int Warning = A4; // select the input pin A4 for the Warning LED
void setup() {
pinMode(ldrPin, INPUT); // Set up the LDR pin as an input pin
pinMode(TempPin, INPUT); // Set up the Temp Sensor pin as an input pin
pinMode(Warning, OUTPUT); // Set up the Warning LED pin as an output pin
Serial.begin(9600); // Set up the serial output at 9600 characters per second
// need to set up 9 pins for our two 7-segment displays - all as output pins
for(int i=2; i<=10; i++){ // pins 2 to 10 (i.e. 9 pins)
pinMode(i, OUTPUT);
}
}
// This displays the number 0-10 by calling the displaySegment() function and telling it
// which segments to light for the number 0..10. This is not the most efficient way to do this
// but it is the easiest to understand. Just use this code.
void display(int x){
switch(x){ // calls the correct display depending on which number is passed
case 0: displaySegment(1,1,1,1,1,1,0,0,0);
break;
case 1: displaySegment(0,1,1,0,0,0,0,0,0);
break;
case 2: displaySegment(1,1,0,1,1,0,1,0,0);
break;
case 3: displaySegment(1,1,1,1,0,0,1,0,0);
break;
case 4: displaySegment(0,1,1,0,0,1,1,0,0);
break;
case 5: displaySegment(1,0,1,1,0,1,1,0,0);
break;
case 6: displaySegment(0,0,1,1,1,1,1,0,0);
break;
case 7: displaySegment(1,1,1,0,0,0,0,0,0);
break;
case 8: displaySegment(1,1,1,1,1,1,1,0,0);
break;
case 9: displaySegment(1,1,1,1,0,1,1,0,0);
break;
case 10: displaySegment(1,1,1,1,1,1,0,1,1);
break;
}}
// This lights up the segments a-i which have been wired 2-10
void displaySegment(int a, int b, int c, int d, int e, int f, int g, int h, int i){
digitalWrite(2,a);
digitalWrite(3,b);
digitalWrite(4,c);
digitalWrite(5,d);
digitalWrite(6,e);
digitalWrite(7,f);
digitalWrite(8,g);
digitalWrite(9,h);
digitalWrite(10,i);
}
// The loop() function will be called over-and-over, forever!
void loop() {
// count from 10 to 0 each time the loop() function is called
for(int i=10; i>=0; i--){
display(i); // display 10, then 9, then 8... then 0.
delay(900.965); // wait almost 1 second between each count
}
ldrValue = analogRead(ldrPin); 
Serial.print("LDR V_out:"); // no 'ln' as I don't want a new line yet
Serial.println(ldrValue); // print out the LDR value

TempValue = analogRead(TempPin); 
int Temp = (((TempValue * 4.965 * 100.0)/1024)-273.15); // Calculation for converting sensor to Celsius
int TempK = (((TempValue * 4.965 * 100.0)/1024)); // Calculation for converting sensor to Kelvin
Serial.print("Temperature (°C):"); // no 'ln' as I don't want a new line yet
Serial.println(Temp); // print out the Celsius temperature reading
Serial.print("Temperature (K):"); // no 'ln' as I don't want a new line yet
Serial.println(TempK); // print out the Kelvin temperature reading

if (ldrValue <= 10 && TempValue == 1023){ 
digitalWrite(Warning, HIGH); // If my LDR value is 10 or below and my temp is 1023 my sensors are broken
Serial.println("LDR Failure Detected"); // tell the serial monitor my LDR is broken
Serial.println("Temp Sensor Failure Detected"); // tell the serial monitor my temp sensor is broken
}

else if (ldrValue <= 10){
digitalWrite(Warning, HIGH); // if my LDR value is 10 or below it is broken
Serial.println("LDR Failure Detected"); // tell the serial monitor my LDR is broken
}

else if (TempValue == 1023){
digitalWrite(Warning, HIGH); // if my temp sensor is giving a value of 1023 it is broken
Serial.println("Temp Sensor Failure Detected"); // tell the serial monitor my temp sensor is broken
}
else{
  digitalWrite(Warning,LOW); // if both are working fine the warning LED should be off
}
}
