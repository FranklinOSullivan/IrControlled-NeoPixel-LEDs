//Include the adafruit neopixel library
#include <Adafruit_NeoPixel.h>

// Onput pin for the LEDS
#define PIN       6
// Set the amount of LED in the strip
#define N_LEDS  144

// Set the brightness of the strip to 70%
int strip_brightness = 200;

// Initiate the neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  strip.begin(); // Start the strip
  strip.setBrightness(strip_brightness); // Set the brightness
}

void loop() {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<(strip.numPixels()*200); a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / (strip.numPixels()*3);
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(50);                 // Pause for a moment
      firstPixelHue += 65536 / 200; // One cycle of color wheel over 90 frames
    }
  }
}
