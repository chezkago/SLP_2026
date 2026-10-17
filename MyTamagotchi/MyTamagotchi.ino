/*
  Main file of Program
*/

//Libraries 
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <avr/pgmspace.h>
/*============================================================
  1. TO DO: Include the animation files (Order doesn't matter)
  ==========================================================*/
#include
#include
#include

//Pin defintions
#define TFT_CS   10
#define TFT_DC    7
#define TFT_RST   8

//Sensor Data
int CS = A0;
int soilMoisture = 0;

//Original Sprite Dimensions
const int IMG_W = 32;
const int IMG_H = 37;

//Creating LCD Object named tft (Represents the LCD screen)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


/*========================================== 
  Next Week: Create Imaging Scaling Function
  =========================================*/
void drawScaledImageFullScreen(const uint16_t *sprite) {
  // For next week but can also start early
}

void setup() {
  tft.init(240, 280); // Intialize Display with Width: 240 pixels and Height: 280 pixels
  tft.setRotation(0); // Orientation
  Serial.begin(9600); // Initialize serial communication
}

/*============================================
  2. TO-DO: Animation Set Up
    In the conditional, change the zeroes to 
    the correct value based on desired output
    We will add the actual animations later on!
  =============================================*/
void loop() {
  soilMoisture = analogRead(CS);
  Serial.print("Mositure: "); Serial.println(soilMoisture);
  if (soilMoisture > 0){
    //drySoilAnimation.h
  }
  else if (soilMoisture < 0){
    //wetSoilAnimation.h
  }
  else{
    //idealMoistureAnimation.h
  }

}




}
