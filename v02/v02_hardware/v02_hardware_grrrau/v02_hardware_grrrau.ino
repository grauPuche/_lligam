
// //libraries

// #include <ESP8266WiFi.h>

// //connection info

// const char* ssid     = "itpsandbox";
// const char* password = "NYU+s0a!+P?";
 
// const char* host = "lligam.grrrau.co";

// //AnalogRead variables

// int yPin = A0;
// int xPin = 5;
// int kPin = 4;

// int yValue = 0;  
// int xValue = 0;
// int kValue = 0;

// //setup
 
// void setup() {
//   Serial.begin(115200);
//   delay(100);
 
//   // We start by connecting to a WiFi network
 
//   Serial.println();
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
  
//   WiFi.begin(ssid, password);
  
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
 
//   Serial.println("");
//   Serial.println("WiFi connected");  
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// //loop

// void loop() {
//   yValue = analogRead(yPin);
//   xValue = analogRead(xPin);

//   //Serial.print(yValue);
//   //Serial.print(", ");
//   //Serial.println(xValue);
// }

/*
 *  Simple HTTP get webclient test
 */
 
#include <ESP8266WiFi.h>

const char* ssid       = "lacueva";
const char* password   = "monsterGr4u";

//const char* ssid     = "itpsandbox";
//const char* password = "NYU+s0a!+P?";
 
const char* host = "lligam.grrrau.co";
 
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
 
int value = 0;
 
void loop() {
  delay(5000);
  ++value;
 
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println();
  Serial.println("closing connection");
}
