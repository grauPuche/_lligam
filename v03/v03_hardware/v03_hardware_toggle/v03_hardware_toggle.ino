#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <WebSocketsClient.h>

#include <Hash.h>

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;

#define USE_SERIAL Serial

//boolean isConnected = false;

int sendState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

  switch (type) {
    case WStype_DISCONNECTED:
      USE_SERIAL.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED: {
        USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

        // send message to server when Connected
        webSocket.sendTXT("~CTRL~"); // showing undefined on node console
        //        isConnected = true;

      }
      break;
    case WStype_TEXT:
      USE_SERIAL.printf("[WSc] get text: %s\n", payload);

      // send message to server
      // webSocket.sendTXT("message here");
      break;
    case WStype_BIN:
      USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
      hexdump(payload, length);

      // send data to server
      // webSocket.sendBIN(payload, length);
      break;
  }

}

const int yPin = A0;
const int xPin = 5;
const int kPin = 4;

int yValue = 0;
int xValue = 0;
int kValue = 0;

const int sendPin = 13;
const int ledPin = 12;      // the number of the LED pin



void setup() {

  pinMode(sendPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(kPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(xPin, INPUT);

  digitalWrite(ledPin, sendState);

  // USE_SERIAL.begin(921600);
  USE_SERIAL.begin(115200);

  //Serial.setDebugOutput(true);
  USE_SERIAL.setDebugOutput(true);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  WiFiMulti.addAP("itpsandbox", "NYU+s0a!+P?");
  WiFiMulti.addAP("lacueva", "monsterGr4u");

  //WiFi.disconnect();
  while (WiFiMulti.run() != WL_CONNECTED) {
    delay(100);
  }

  // server address, port and URL
  webSocket.begin("mitjons.grrrau.co", 80, "/");

  // event handler
  //  while (!isConnected) {


  webSocket.onEvent(webSocketEvent);

  // use HTTP Basic Authorization this is optional remove if not needed
  //webSocket.setAuthorization("user", "Password");

  // try ever 5000 again if connection has failed
  webSocket.setReconnectInterval(5000);

  //  }
}

void loop() {



  int sendReading = digitalRead(sendPin);
  if (sendReading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (sendReading != buttonState) {
      buttonState = sendReading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        sendState = !sendState;
      }
    }
  }

//  Serial.println(sendState);

  lastButtonState = sendReading;

  yValue = analogRead(yPin);
  kValue = digitalRead(kPin);

  if (sendState == 1) {
    String coma = ",";
    webSocket.sendTXT(yValue + coma + kValue);
    // delay(200);
    
  }

  digitalWrite(ledPin, sendState);

  webSocket.loop();
  delay(50);
}
