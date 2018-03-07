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

int sensorPin1 = A0;    // select the input pin for the potentiometer
int sensorPin2 = A1;    // select the input pin for the potentiometer
int ledPin1 = 11;      // select the pin for the LED
int ledPin2 = 10;
int ledPin3 = 9;      
int ledPin4 = 6;
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);


  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

int map1 = map(sensorValue1, 426, 509, 255, 0);
int map2 = map(sensorValue1, 512, 600, 0, 255);

int map3 = map(sensorValue2, 426, 512, 0, 255);
int map4 = map(sensorValue2, 514, 601, 255, 0);




  
  Serial.print("          ");
  Serial.print(sensorValue1);
  Serial.print(", ");
  Serial.println(sensorValue2);
  // turn the ledPin on

  if (sensorValue1 < 509){
    analogWrite(ledPin1, map1);
    digitalWrite(ledPin2, LOW);
  }
  else if (sensorValue1 > 513){
    analogWrite(ledPin2, map2);
    digitalWrite(ledPin1, LOW);
  }
  else if (sensorValue2 > 514){
    analogWrite(ledPin4, map3);
    digitalWrite(ledPin3, LOW);
  }
  else if (sensorValue2 < 512){
    analogWrite(ledPin3,map4);
    digitalWrite(ledPin4, LOW);
  }
  else if(sensorValue2 <= 514 && sensorValue2 >= 511 ){
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  else if(sensorValue1 <= 513 && sensorValue1 >= 509){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  else{
    
  }
}
