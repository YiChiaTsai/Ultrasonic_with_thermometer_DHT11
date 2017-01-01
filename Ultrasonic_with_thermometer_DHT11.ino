/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */

#include <dht.h>  
//#include "pitches.h"
#define NOTE_A3  220

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
#define dht_dpin A0 //no ; here. Set equal to channel sensor is on   
  
dht DHT;   

// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
int red=0, green=0, blue=0;

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

const int piezoPin = 9;

void setup() {
  Serial.begin (9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
  DHT.read11(dht_dpin);
     
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 //Cair = (331.3 + 0.606 * temperatures) m/s
 float cAir = 331.3 + 0.606 * DHT.temperature;
 float cAirForUltrasonic = 2 * (1000000 / (cAir*100));
  
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/cAirForUltrasonic;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.print(distance);
 Serial.print(" CM ");
 Serial.print(DHT.temperature);
 Serial.println("C "); 
 
 digitalWrite(LEDPin, LOW); 

  if(distance <= 10){
    red=255-255; green=255-0; blue=255-0;
    tone(piezoPin, NOTE_A3, 250);
    delay(100);
    noTone(piezoPin);
    tone(piezoPin, NOTE_A3, 250);
    delay(100);
    noTone(piezoPin);
    tone(piezoPin, NOTE_A3, 250);
    delay(100);
    noTone(piezoPin);
    tone(piezoPin, NOTE_A3, 250);
    delay(100);
    noTone(piezoPin);
  }
  else if(distance > 10 && distance <=30){
    red=255-255; green=255-255; blue=255-0;
    tone(piezoPin, NOTE_A3, 500);
    delay(500);
    noTone(piezoPin);
    tone(piezoPin, NOTE_A3, 500);
    delay(500);
    noTone(piezoPin);
  }
  else{
    red=255-0; green=255-255; blue=255-0;
  }
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
 
 //Delay 50ms before next reading.
 delay(50);
}
