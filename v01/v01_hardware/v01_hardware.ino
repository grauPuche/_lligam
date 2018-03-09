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
