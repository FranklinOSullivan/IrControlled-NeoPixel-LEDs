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
int randPixel = 0;
int randValue = 0;

void setup() {
  // put your setup code here, to run once:
  strip.begin(); // Start the strip
  strip.setBrightness(strip_brightness); // Set the brightness
}

void loop() {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 100) { // change time
    for(int i=0; i<strip.numPixels()+2000; i++) { // velocity
      int pixelHue = firstPixelHue + (i * 65536L / (strip.numPixels()*20)); // length
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(10);  // Pause for a moment
  }
}
