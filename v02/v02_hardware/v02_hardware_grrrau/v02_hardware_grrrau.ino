
//libraries

#include <ESP8266WiFi.h>

//connection info

const char* ssid     = "itpsandbox";
const char* password = "NYU+s0a!+P?";
 
const char* host = "wifitest.adafruit.com";

//AnalogRead variables

int yPin = 2;
int xPin = 5;
int kPin = 4;

int yValue = 0;  
int xValue = 0;
int kValue = 0;

//setup
 
void setup() {
  Serial.begin(115200);
  delay(100);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//loop

void loop() {
  yValue = analogRead(yPin);
  xValue = analogRead(xPin);

  Serial.print(yValue);
  Serial.print(", ");
  Serial.println(xValue);
}
