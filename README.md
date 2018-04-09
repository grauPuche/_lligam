# v02

The point of this version is to take the already working device and make it wireless. To do so I'm using the well known ESP8266. this is going to take the analog data from the joystick and send it to a node server. This is the main objective of this version.

The plan for the following is to have a client side for the mentioned information. And to do the first steps towards the creation of the final iteration of the controller and make the custom board I need for it.

---

## HARDWARE

**As of april 8th**, the webSocket enabled joystick is completely functional, *.ino* is sending data properly and server is displaying it at [lligam.grrau.co](http://lligam.grrrau.co). There are still some things to be adjusted and others to be added, but the core functionality is working exactly as intended. At this point the next step is building the multiplexer to have both axis of the joystick read by one pin.

![](https://static.notion-static.com/6812e997-ee5b-4b37-aa53-9a4b963ff894/joys-3.png)

![](https://static.notion-static.com/2e56c2ae-e222-451f-9873-0ece64be786d/joys-4.png)

---

**As of march 8th**, *.ino* code working, X & Y values are not showing properly. either a hardware.wiring problem, or a code/pinout issue. the issue is that I was dumb enough to switch the meaning of analog with PWD. and feather only has one analogRead Pin. Wiring has to be UPDATED.

![](https://static.notion-static.com/7db2e467-a7f2-4076-a627-61ad68bbf68f/joys-1.png)

![](https://static.notion-static.com/d6072bca-7b39-4750-beec-39a423d45730/joys-2.png)

---

## what I'm using

As mentioned; a [HUZZAH feather](https://www.adafruit.com/product/2821)  with ESP8266 from Adafruit. to run the basic operations needed before designing the PCB. Where I'll be using [this](https://www.adafruit.com/product/2491).

To set everything up, I've been following the [tutorials given by Adafruit](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266)

---

## SOFTWARE

**As of march 8th** the third version of the software is up and running. This v. is the first step to completion. At this point there are two servers running through *grrrau.co*, one is a **webSocket** server (called *mitjons*) and the other on is a simple **express** server (called *lligam*). *Mitjons* is getting the data from the *esp8266* and sending it to *lligam* which interprets and displays it. The next step in software is to instead of displaying this information is using it to read the patterns and use it to link it to the required movements from the joystick.