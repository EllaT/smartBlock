#include <Adafruit_NeoPixel.h>

/**
 Defines for Neopixels
 */

#define NEO_RGB  ((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_KHZ800 0x0000 ///< 800 KHz data transmission

#define PIN 3

#define NUM_LEDS 5

#define BRIGHTNESS 30

Adafruit_NeoPixel smartBlock = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  smartBlock.setBrightness(BRIGHTNESS);
  smartBlock.begin();
  smartBlock.show(); //initializes
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < 5; i++){
  smartBlock.setPixelColor(i, smartBlock.Color(0, 255, 255));
  smartBlock.show(); //initializes
  smartBlock.clear();
  delay(500);
  smartBlock.setPixelColor(i, smartBlock.Color(255, 0, 0));
  smartBlock.show(); //initializes
  smartBlock.clear();
  delay(500);
  }

}
