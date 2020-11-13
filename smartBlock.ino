#include "Arduino.h"

#include "gyroAccel.h"
#include <Adafruit_TCS34725.h>


//	Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
//	Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
	Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_16X);

//The setup function is called once at startup of the sketch
void setup()
{

	Serial.begin(9600);

	if (tcs.begin()) {
		Serial.println("Found sensor");
	} else {
		Serial.println("No TCS34725 found ... check your connections");
	while (1);
	}

}

// The loop function is called in an endless loop
void loop(){

	  uint16_t r, g, b, c, colorTemp, lux;

	  tcs.getRawData(&r, &g, &b, &c);
	  // colorTemp = tcs.calculateColorTemperature(r, g, b);
	  //colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
	  //lux = tcs.calculateLux(r, g, b);

	  Serial.print(b, DEC); Serial.print(" ");
	  Serial.print(r, DEC); Serial.print(" ");
	  Serial.print(g, DEC); Serial.println(" ");

//	  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
//	  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
//	  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
//	  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
//	  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
//	  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
//	  Serial.println(" ");
}
