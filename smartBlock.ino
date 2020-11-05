#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "gyroAccel.h"

/**
 Defines for Neopixels
 */

#define NEO_RGB  ((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_KHZ800 0x0000 ///< 800 KHz data transmission

#define PIN 3

#define NUM_LEDS 6

#define BRIGHTNESS 30

Adafruit_NeoPixel smartBlock = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);
GyroAccel mpu6050;


void setup() {
  // put your setup code here, to run once:
  smartBlock.setBrightness(BRIGHTNESS);
  smartBlock.begin();
  smartBlock.clear();
  smartBlock.show(); //initializes
  Serial.begin(9600);
  mpu6050.gyroStart();
}

void loop() {
  // put your main code here, to run repeatedly:


	mpu6050.getGyroValues();
	long x = mpu6050.acc_x;
	Serial.println(x);

  if(x > 0){
	  smartBlock.setPixelColor(2, smartBlock.Color(0, 255, 0));
	  smartBlock.setPixelColor(1, smartBlock.Color(255, 0, 0));
	  smartBlock.show(); //initializes
	  //smartBlock.clear();
  }
  else{
	  smartBlock.setPixelColor(2, smartBlock.Color(255, 0, 0));
	  smartBlock.setPixelColor(1, smartBlock.Color(0, 255, 0));
	  smartBlock.show(); //initializes
	  //smartBlock.clear();
  }

}
