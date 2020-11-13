#include <Adafruit_NeoPixel.h>
#include "gyroAccel.h"
#include <Adafruit_TCS34725.h>
/**
 Defines for Neopixels
 */

#define NEO_RGB  ((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_KHZ800 0x0000 ///< 800 KHz data transmission

#define PIN 3

#define NUM_LEDS 10

#define BRIGHTNESS 10

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
	//	mpu6050.gyroStart();
	//	if (tcs.begin()) {
	//		Serial.println("Found sensor");
	//	} else {
	//		Serial.println("No TCS34725 found ... check your connections");
	//		while (1); // halt!
	//	}
}

void loop() {
	// put your main code here, to run repeatedly:
	//	float red, green, blue;
	//	int redSet = 0;
	//	int greenSet = 0;
	//	int blueSet = 0;
	int secretMessageLength = 10;
	uint8_t colorCodes[] =  {0 , 255, 0, 0};

	//	tcs.setInterrupt(false);  // turn on LED
	//
	//	delay(60);  // takes 50ms to read
	//
	//	tcs.getRGB(&red, &green, &blue);
	//
	//	tcs.setInterrupt(true);  // turn off LED


	//
	//	Serial.print("R:\t"); Serial.print(int(red));
	//	Serial.print("\tG:\t"); Serial.print(int(green));
	//	Serial.print("\tB:\t"); Serial.print(int(blue));
	//
	//
	//	//  Serial.print("\t");
	//	//  Serial.print((int)red, HEX); Serial.print((int)green, HEX); Serial.print((int)blue, HEX);
	//	Serial.print("\n");
	//
	//	mpu6050.getGyroValues();
	//	long x = mpu6050.acc_x;
	//Serial.println(x);
	//Serial.print("\n");

	//	smartBlock.clear();
	  for(long firstPixelHue = 8192; firstPixelHue < 65536; firstPixelHue += 8192) {
		  // For each pixel in strip...
	      // Offset pixel hue by an amount to make one full revolution of the
	      // color wheel (range of 65536) along the length of the strip
	      // (strip.numPixels() steps):
	      int pixelHue = firstPixelHue;
	      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
	      // optionally add saturation and value (brightness) (each 0 to 255).
	      // Here we're using just the single-argument hue variant. The result
	      // is passed through strip.gamma32() to provide 'truer' colors
	      // before assigning to each pixel:
	      smartBlock.setPixelColor(1, smartBlock.gamma32(smartBlock.ColorHSV(pixelHue)));

	      smartBlock.show(); // Update strip with new contents
	      delay(10);  // Pause for a moment
	      smartBlock.setPixelColor(1, 0, 0, 0);
	      smartBlock.show(); // Update strip with new contents
	      delay(100);  // Pause for a moment
	  }

}

//smartBlock.clear();
