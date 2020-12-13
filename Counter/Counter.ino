// The 7-Segment Display Counter
// The Counting Programme - Counts 0-9 - DM.
void setup() {
// need to set up 7 pins for our 7-segment display - all as output pins
for(int i=1; i<=9; i++){ // pins 1 to 9 (i.e. 9 pins)
pinMode(i, OUTPUT);
}
}
// This displays the number 0-9 by calling the displaySegment() function and telling it
// which segments to light for the number 0..9. This is not the most efficient way to do this
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
// This lights up the segments a-g which have been wired 2-8
void displaySegment(int a, int b, int c, int d, int e, int f, int g, int h, int i){
digitalWrite(1,a);
digitalWrite(2,b);
digitalWrite(3,c);
digitalWrite(4,d);
digitalWrite(5,e);
digitalWrite(6,f);
digitalWrite(7,g);
digitalWrite(8,h);
digitalWrite(9,i);
}
// The loop() function will be called over-and-over, forever!
void loop() {
// count from 0 to 9 each time the loop() function is called
for(int i=10; i>=0; i--){
display(i); // display 0, then 1, then 2... then 9.
delay(1000); // wait 1 second between each count
}

}
