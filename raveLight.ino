//Include the adafruit neopixel library
#include <Adafruit_NeoPixel.h>

// Onput pin for the LEDS
#define PIN       6
// Set the amount of LED in the strip
#define N_LEDS  144

// Set the brightness of the strip to 70%
int strip_brightness = 70;

// Initiate the neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int cRed = 0;
int cGreen = 0;
int cBlue = 0;

void setup() {
  // put your setup code here, to run once:
  strip.begin(); // Start the strip
  strip.setBrightness(strip_brightness); // Set the brightness
}

void loop() {
  // put your main code here, to run repeatedly:
  cRed = random(0,255);
  cGreen = random(0, 255);
  cBlue = random(0, 255);
  /*for (uint32_t i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, strip.Color(cRed, cGreen, cBlue));
    strip.show();
  }*/
  strip.fill(strip.Color(cRed, cGreen, cBlue));
  strip.show();
  delay(200);
}
