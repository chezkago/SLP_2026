/*Main File of Program*/

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <avr/pgmspace.h>
/*1. TO-DO: Animation Files
  Include the 3 .h animation files (order doesn't matter)
*/
#include
#include
#include


/* pin definitions lcd*/
#define TFT_CS   10
#define TFT_DC    7
#define TFT_RST   8
/*sensor data*/
int CS = A0;
int Dirt = 0;

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const int IMG_W = 32;
const int IMG_H = 37;


/* 2.TO-DO: Create Scaling Function
- need to fix
*/
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
  tft.init(240, 280); //size of lcd
  tft.setRotation(0); // orientation
  Serial.begin(9600);       // Initialize serial communication


}

/* 3. TO-DO: Animation set up 
    In the conditional, change the zeroes to the correct value based on desired output
    We will add the actual animations later on!
*/
void loop() {
  Dirt = analogRead(CS);
  Serial.print("Mositure: "); Serial.println(Dirt);
  if (Dirt > 0){
    //drySoilAnimation.h
  }
  else if (Dirt < 0){
    //wetSoilAnimation.h
  }
  else{
    //idealMoistureAnimation.h
  }






}
