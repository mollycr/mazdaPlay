//for illustrative purposes - this will not work

//requires Adafruit_TCS34725 library
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

//array of 4 color sensors (0-3)
const int sensorPins[4][3] = {
  {13, 12, 11}, //sensor 0
  {10, 9, 8},   //sensor 1
  {7, 6, 5},    //sensor 2
  {4, 3, 2}     //sensor 3
};

//array of 8 possible car colors
const int colors[8][3] = {
  //red, green, blue
  {255, 0, 0},    //red - car 0
  {0, 255, 0},    //green - car 1
  {0, 0, 255},    //blue - car 2
  {0, 255, 255},  //cyan - car 3
  {255, 0, 255},  //magenta - car 4
  {255, 255, 0},  //yellow - car 5
  {0, 0, 0},      //black - car 6
  {255, 255, 255} //white - car 7
};

void setup() {
  // put your setup code here, to run once:
  
  //set up sensors
  tcs.begin();
  //connect bluetooth
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //watch for any sensor to register a car (have to debounce)
  int sensor = 0;
  for tcs in tcss{
    int r, g, b, c;
    tcs.getRawData(&r, &g, &b, &c);
    if(/*there's something there*/){
      //color = index of appropriate color value
      //send sensor number and car number
      Serial.println(sensor + " " + color);
      sensor++;
    }
  }
}
