//Include the adafruit neopixel library
#include <Adafruit_NeoPixel.h>

// Onput pin for the LEDS
#define PIN       6
// Set the amount of LED in the strip
#define N_LEDS  14

// Set the brightness of the strip to 70%
int strip_brightness = 10;

// Initiate the neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int cRed = 0;
int cGreen = 0;
int cBlue = 0;
int randPixel = 0;
int randValue = 0;

void setup() {
  // put your setup code here, to run once:
  strip.begin(); // Start the strip
  strip.setBrightness(strip_brightness); // Set the brightness
}

void loop() {
  // put your main code here, to run repeatedly:
  randPixel = random(0, strip.numPixels());
  cRed = random(180, 255);
  cGreen = random(180, 255);
  cBlue = random(180, 255);

  randValue = random(0, 10);
  if (randValue < 8){
    cRed = 0;
    cBlue = 0;
    cGreen = 0;
  }
  strip.setPixelColor(randPixel, strip.Color(cRed, cGreen, cBlue));
  delay(200);
  strip.show();
}
