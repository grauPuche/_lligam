/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int yPin = A0;
int xPin = A1;
int kPin = 7;

int yValue = 0;  
int xValue = 0;
int kValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  yValue = analogRead(yPin);
  xValue = analogRead(xPin);

//int map1 = map(sensorValue1, 426, 509, 255, 0);
//int map2 = map(sensorValue1, 512, 600, 0, 255);
//
//int map3 = map(sensorValue2, 426, 512, 0, 255);
//int map4 = map(sensorValue2, 514, 601, 255, 0);

  Serial.print(yValue);
  Serial.print(", ");
  Serial.println(xValue);
}
