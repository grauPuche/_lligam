# v02

The point of this version is to take the already working device and make it wireless. To do so I'm using the well known ESP8266. this is going to take the analog data from the joystick and send it to a node server. This is the main objective of this version.

The plan for the following is to have a client side for the mentioned information. And to do the first steps towards the creation of the final iteration of the controller and make the custom board I need for it.

## HARDWARE

**as of march 8th**, .ino code working, X & Y values are not showing properly. either a hardware.wiring problem, or a code/pinout issue.

### what I'm using

As mentioned; a [HUZZAH feather](https://www.adafruit.com/product/2821) with ESP8266 from Adafruit {INSERT LINK OF THIS DEVICE}. to run the basic operations needed before designing the PCB. Where I'll be using [this](https://www.adafruit.com/product/2491).

To set everything up, I've been following the [tutorials given by Adafruit](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266)

## SOFTWARE

A basic Server that get the analog data from the joystick.