//Include the adafruit neopixel library
#include <Adafruit_NeoPixel.h>

// Onput pin for the LEDS
#define PIN       6
// Set the amount of LED in the strip
#define N_LEDS  14

// Set the brightness of the strip to 70%
int strip_brightness = 70;

// Initiate the neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int cRed = 0;
int cGreen = 0;
int cBlue = 0;
int randValue = 0;

void setup() {
  // put your setup code here, to run once:
  strip.begin(); // Start the strip
  strip.setBrightness(strip_brightness); // Set the brightness
}

void loop() {
  // put your main code here, to run repeatedly:
    for (int i=0; i<strip.numPixels(); i++) {
    cRed = 255;
    cGreen = 180;
    cBlue = 0;
    
      randValue = random(0, 10);
      if (randValue < 7){
        cRed = 0;
        cBlue = 0;
        cGreen = 0;
      }
      strip.setPixelColor(i, strip.Color(cRed, cGreen, cBlue));
      delay(200);
      strip.show();
    }
}
