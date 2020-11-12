#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "gyroAccel.h"
#include <Adafruit_TCS34725.h>
/**
 Defines for Neopixels
 */

#define NEO_RGB  ((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_KHZ800 0x0000 ///< 800 KHz data transmission

#define PIN 3

#define NUM_LEDS 10

#define BRIGHTNESS 30

Adafruit_NeoPixel smartBlock = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
GyroAccel mpu6050;


void setup() {
	// put your setup code here, to run once:
	smartBlock.setBrightness(BRIGHTNESS);
	smartBlock.begin();
	smartBlock.clear();
	smartBlock.show(); //initializes
	Serial.begin(9600);
	mpu6050.gyroStart();
	if (tcs.begin()) {
		Serial.println("Found sensor");
	} else {
		Serial.println("No TCS34725 found ... check your connections");
		while (1); // halt!
	}
}

void loop() {
	// put your main code here, to run repeatedly:
	float red, green, blue;
	int redSet = 0;
	int greenSet = 0;
	int blueSet = 0;
	String secretMessage = "";

	tcs.setInterrupt(false);  // turn on LED

	delay(60);  // takes 50ms to read

	tcs.getRGB(&red, &green, &blue);

	tcs.setInterrupt(true);  // turn off LED
//
	Serial.print("R:\t"); Serial.print(int(red));
	Serial.print("\tG:\t"); Serial.print(int(green));
	Serial.print("\tB:\t"); Serial.print(int(blue));

	if(int(red) >= 175){
		redSet = 255;
	}
	else if(int(red) < 100 && int(red) >= 50){
		redSet = int(red);
	}
	else{
		redSet = 0;
	}

	if(int(green) >= 175){
		greenSet = 255;
	}
	else if(int(green) < 100 && int(green) >= 50 ){
		greenSet = int(green);
	}
	else{
		greenSet = 0;
	}
	if(int(blue) >= 175){
		blueSet = 255;	}
	else if(int(blue) < 100 && int(blue) >= 50 ){
		blueSet = int(blue);
	}
	else{
		blueSet = 0;
	}

	//  Serial.print("\t");
	//  Serial.print((int)red, HEX); Serial.print((int)green, HEX); Serial.print((int)blue, HEX);
	Serial.print("\n");

	mpu6050.getGyroValues();
	long x = mpu6050.acc_x;
	//Serial.println(x);
	//Serial.print("\n");

//	for(int i = 1; i <= 3; i++){
//		switch (i){
//		case 1:
//			smartBlock.setPixelColor(0, smartBlock.Color(255, 0, 0));
//			smartBlock.show(); //initializes
//			Serial.println(secretMessage);
//			delay(500);
//
//			break;
//		case 2:
//			smartBlock.setPixelColor(0, smartBlock.Color(0, 255, 0));
//			smartBlock.show(); //initializes
//			Serial.println(secretMessage);
//			delay(500);
//
//			break;
//		case 3:
//			smartBlock.setPixelColor(0, smartBlock.Color(0, 0, 255));
//			smartBlock.show(); //initializes
//			Serial.println(secretMessage);
//			delay(500);
//			break;
//		}

//	}
	smartBlock.setPixelColor(5, smartBlock.Color(redSet, greenSet, blueSet));
	//smartBlock.clear();

}
