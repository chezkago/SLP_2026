/*
  Main file of Program
*/

//Libraries 
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
// #include <SPI.h>
#include <avr/pgmspace.h>

#include "idealMoistureAnimation.h"
#include "wetSoilAnimation.h"
#include "drySoilAnimation.h"

//Pin defintions
#define TFT_CS   10
#define TFT_DC    7
#define TFT_RST   8

//Sensor Data
int CS = A0;
int soilMoisture = 0;

//Original Sprite Dimensions
const int IMG_W = 32;
const int IMG_H = 32;

//Creating LCD Object named tft (Represents the LCD screen)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void drawScaledImageFullScreen(const uint16_t *sprite) {
  for (int y = 0; y < 280; y++) {
    int srcY = (y * IMG_H) / 280;

    for (int x = 0; x < 240; x++) {
      int srcX = (x * IMG_W) / 240;
      uint16_t color = pgm_read_word(&sprite[srcY * IMG_W + srcX]);
      tft.drawPixel(x, y, color);
    }
  }
}

void setup() {
  tft.init(240, 280); // Intialize Display with Width: 240 pixels and Height: 280 pixels
  tft.setRotation(0); // Orientation
}

void loop() {
  soilMoisture = analogRead(CS);
  Serial.print("Mositure: "); Serial.println(soilMoisture);
  if (soilMoisture > 744){      // dry soil (> 710 at 0%): 710-(710-600)(0%)
    //drySoilAnimation.h
    drawScaledImageFullScreen(drySoilAnimation1);
    drawScaledImageFullScreen(drySoilAnimation2);
  }
  else if (soilMoisture < 677){     //wet soil (< 600 at 30%): 710-(710-600)(30%)
    //wetSoilAnimation.h
    drawScaledImageFullScreen(wetSoilAnimation1);
    drawScaledImageFullScreen(wetSoilAnimation2);
    drawScaledImageFullScreen(wetSoilAnimation3);
  }
  else{
    //idealMoistureAnimation.h
    drawScaledImageFullScreen(idealMoistureAnimation1);
    drawScaledImageFullScreen(idealMoistureAnimation2);
    drawScaledImageFullScreen(idealMoistureAnimation3);
  
  }

}
