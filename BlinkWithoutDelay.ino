/*
  @author Tommy Boonchuaysream
  - this code is used to continuously switch betwee red, green, and blue without using the delay function
*/

#include <analogWrite.h>

//the numbers of the RGB pins
const int redLED = 12;
const int greenLED = 27;
const int blueLED = 33;

//declaring value
long previousMillis = 0;
String currentLight = "red";

//time before switching
long interval = 1000;

void setup() {

  //initialize serial communication at 9600 bits per second
  Serial.begin(9600);

  //outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

}

void loop() {

  //declaring value
  unsigned long currentMillis = millis();

  //switch between the different colors
  //if it's current on one color, it will display that color then assign it to the next color
  if ((currentMillis - previousMillis > interval) && (currentLight == "red")) {

    previousMillis = currentMillis;

    analogWrite(redLED, 255);
    analogWrite(greenLED, 0);
    analogWrite(blueLED, 0);

    currentLight = "green";

  } else if ((currentMillis - previousMillis > interval) && (currentLight == "green")) {

    previousMillis = currentMillis;

    analogWrite(redLED, 0);
    analogWrite(greenLED, 255);
    analogWrite(blueLED, 0);

    currentLight = "blue";

  } else if ((currentMillis - previousMillis > interval) && (currentLight == "blue")) {

    previousMillis = currentMillis;

    analogWrite(redLED, 0);
    analogWrite(greenLED, 0);
    analogWrite(blueLED, 255);

    currentLight = "red";

  }

}
