// Code to control individually adressable neopixels throught the use of an infared sensor and a remote. WS2812 lights
// Running on 5V from an arduino uno board
// Will need to install adafruit neopixel library and IRRemote library
// Author: Fork

//Include the adafruit neopixel library
#include <Adafruit_NeoPixel.h>
// Include the infared sensor library
#include <IRremote.h>



// Onput pin for the LEDS
#define PIN       6
// Set the amount of LED in the strip
#define N_LEDS  144

// Set the brightness of the strip to 70%
int strip_brightness = 70;

// Initiate the neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);




// Recieve pin for the infared sensor
int RECV_PIN = 11;

// Set a variable for the decoded results
//decode_results results;




// Variables for each of the colour values
int cRed = 0;
int cGreen = 0;
int cBlue = 0;
int redL = 0;
int redH = 0;
int greenL = 0;
int greenH = 0;
int blueL = 0;
int blueH = 0;

// Set a variable to be used to select random pixels
int randPixel = 0;
int randValue = 0;

// Set variable to pick the right option
int firstValue = 0;

// Set a variable for the commands
byte command = 0x0;


// Set up the system
void setup() {
  strip.begin(); // Start the strip
  strip.setBrightness(strip_brightness); // Set the brightness
  Serial.begin(9600); // Begin the serial monitor
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the IR reciever
}

void loop() {
  // Franklins number values
  // 1: 0xC
  // 2: 0x18
  // 3: 0x5E
  // 4: 0x8
  // 5: 0x1C
  // 6: 0x5A
  // 7: 0x42
  // 8: 0x52
  // 9: 0x4A

  // Ezy's number values
  // 1:
  // 2:
  // 3:
  // 4: 
  // 5:
  // 6:
  // 7:
  // 8:
  // 9:

  // If there is input to the sensor
  if(IrReceiver.decode()){

    // Print the code to the output
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    // Set the command variable equal to the code
    command = IrReceiver.decodedIRData.command;


    // if the command is x and first value was 1
    if (command == 0xC && firstValue == 1){ // One
      firstValue = 0; // Set the first value back to 0 so it can be used again
      setColour(strip.Color(255, 0, 0)); // Call to the wanted function with the wanted input
    }
    else if (command == 0x18 && firstValue == 1){ // Two
      firstValue = 0;
      setColour(strip.Color(255, 128, 0));// Orange
    }
    else if (command == 0x5E && firstValue == 1){ // Three
      firstValue = 0;
      setColour(strip.Color(255, 255, 0));// Yellow
    }
    else if (command == 0x8 && firstValue == 1){ // Four
      firstValue = 0;
      setColour(strip.Color(0, 255, 0));// Green
    }
    else if (command == 0x1C && firstValue == 1){ // Five
      firstValue = 0;
      setColour(strip.Color(0, 255, 128));// Turquoise
    }
    else if (command == 0x5A && firstValue == 1){ // Six
      firstValue = 0;
      setColour(strip.Color(0, 255, 255));// Cyan
    }
    else if (command == 0x42 && firstValue == 1){ // Seven
      firstValue = 0;
      setColour(strip.Color(0, 0, 255));// Blue
    }
    else if (command == 0x52 && firstValue == 1){ // Eight
      firstValue = 0;
      setColour(strip.Color(128, 0, 255));// Purple
    }
    else if (command == 0x4A && firstValue == 1){ // Nine
      firstValue = 0;
      setColour(strip.Color(128, 0, 255));// Pink
    }
    // Values starting with 2
    //
    //
    // If the command is x and the first value was 2
    else if (command == 0xC && firstValue == 2){ // One
      firstValue = 0;
      waveringColoursFunction(200, 255, 0, 50, 0 ,0); // Requires more inputs of a different type
    }
    else if (command == 0x18 && firstValue == 2){ // Two
      firstValue = 0;
      waveringColoursFunction(200, 255, 73, 128, 0, 0);// Orange
    }
    else if (command == 0x5E && firstValue == 2){ // Three
      firstValue = 0;
      waveringColoursFunction(200, 255, 193, 255, 0, 0);// Yellow
    }
    else if (command == 0x8 && firstValue == 2){ // Four
      firstValue = 0;
      waveringColoursFunction(0, 100, 220, 255, 0, 150);// Green
    }
    else if (command == 0x1C && firstValue == 2){ // Five
      firstValue = 0;
      waveringColoursFunction(0, 10, 128, 255, 0, 128);// Turquoise
    }
    else if (command == 0x5A && firstValue == 2){ // Six
      firstValue = 0;
      waveringColoursFunction(0, 10, 180, 255, 200, 255);// Cyan
    }
    else if (command == 0x42 && firstValue == 2){ // Seven
      firstValue = 0;
      waveringColoursFunction(0, 70, 0, 70, 180, 255);// Blue
    }
    else if (command == 0x52 && firstValue == 2){ // Eight
      firstValue = 0;
      waveringColoursFunction(100, 200, 0, 60, 180, 255);// Purple
    }
    else if (command == 0x4A && firstValue == 2){ // Nine
      firstValue = 0;
      waveringColoursFunction(180, 255, 0, 40, 100, 255);// Pink
    }

    // Special values
    //
    // If the command is x and the first value was 9
    else if (command == 0xC && firstValue == 9){ // One
      firstValue = 0;
      starsFunction(); // Requires no inputs
    }
    else if (command == 0x18 && firstValue == 9){ // Two
      firstValue = 0;
      randomFlashingFunction();
    }
    else if (command == 0x5E && firstValue == 9){ // Three
      firstValue = 0;
      rainbowSteppedFunction();
    }
    else if (command == 0x8 && firstValue == 9){ // Four
      firstValue = 0;
      fairyLightsFunction();
    }
    else if (command == 0x1C && firstValue == 9){ // Five
      firstValue = 0;
      flowingRainbowFunction();
    }



    // If the command was 1
    else if (command == 0xC){
      setColour(strip.Color(250, 250,250)); // Set the strip to white
      firstValue = 1; // Set the first value to 1
      Serial.println("1"); // Print 1 to the serial monitor
    }
    else if (command == 0x18){
      setColour(strip.Color(250, 250,250));
      firstValue = 2;
      Serial.println("2");
    }
    else if( command == 0x4A){
      setColour(strip.Color(250, 250,250));
      firstValue = 9;
      Serial.println("9");
    }



    
    IrReceiver.resume(); // Resume searching for values
    delay(100); // Delay for 100ms
  } 
}




// Function to set the colour of the strip
static void setColour(uint32_t colour){ // Takes input of a strip.Color
  for (uint32_t i = 0; i < strip.numPixels(); i++){ // i starts at 0 (beginning of the strip) and keeps increasing till it is the length of the strip then stops
    strip.setPixelColor(i, colour); // Set pixel i to the input colour
    strip.show(); // Update the strip
  }
}


// Function to do the moving colours
static void waveringColoursFunction(uint32_t redL, uint32_t redH, uint32_t greenL, uint32_t greenH, uint32_t blueL, uint32_t blueH){ // Takes multiple number inputs
  delay(100); // Delay 100ms 
  IrReceiver.resume(); // Resume searching for inputs
  while (true) { // Loop this portion
    randPixel = random(0, strip.numPixels()); // Choose a random pixel within the length of the strip
    cRed = random(redL, redH); // Set a random value for the red between the numbers given
    cGreen = random(greenL, greenH);
    cBlue = random(blueL, blueH);

    // Choose a random number between 0 and 10
    randValue = random(0, 10);
    if (randValue < 2){ // If the number is smaller than 2
      cRed = 0; // Set all of the colours to 0 (None)
      cBlue = 0;
      cGreen = 0;
    }
    // Set the colour of the random pixel to the colours chosen
    strip.setPixelColor(randPixel, strip.Color(cRed, cGreen, cBlue));
    delay(10); // Delay 10ms
    strip.show(); // Update the strip
    if(IrReceiver.decode()){ // If the sensor gets an input
          break; // Break out of the loop back to the first one
    }
  }
}

// Function for lights that act like stars
static void starsFunction(){
  delay(100); // Delay 100ms
  IrReceiver.resume(); // Resume searching for inputs
  strip.setBrightness(10); // Set the brightness of the strip to 10
  while (true){ // Loop
    randPixel = random(0, strip.numPixels()); // Pick a random pixel with random values as seen
    cRed = random(180, 255);
    cGreen = random(180, 255);
    cBlue = random(180, 255);
  
    randValue = random(0, 10);
    if (randValue < 8){ // If the random value is less than 8 all to 0
      cRed = 0;
      cBlue = 0;
      cGreen = 0;
    }
    // Set the colour of the pixel
    strip.setPixelColor(randPixel, strip.Color(cRed, cGreen, cBlue));
    delay(200);
    strip.show();
    if(IrReceiver.decode()){ // If input is received
          strip.setBrightness(strip_brightness); // Set the brightness back to normal
          break;
    }
  }
}


// Function to act as a rave light
static void randomFlashingFunction(){
  delay(100);
  IrReceiver.resume();
  while(true){ // Pick a random colour
    cRed = random(0,255);
    cGreen = random(0, 255);
    cBlue = random(0, 255);
    // Fill the strip with the chosen colour
    strip.fill(strip.Color(cRed, cGreen, cBlue));
    strip.show();
    delay(200);
    if(IrReceiver.decode()){
          break;
    }
  }
}


// Function to act as a rainbow rave
// I won't lie I don't really understand this one yet :)
static void rainbowSteppedFunction(){
  delay(100);
  IrReceiver.resume();
  while (true){
    int firstPixelHue = 0;     // First pixel starts at red (hue 0)
    for(int a=0; a<(strip.numPixels()*200); a++) {  
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
        if(IrReceiver.decode()){
          break;
        }
      }
    }
  }
}

static void flowingRainbowFunction(){
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 100) { // change time
    for(int i=0; i<strip.numPixels()+2000; i++) { // velocity
      int pixelHue = firstPixelHue + (i * 65536L / (strip.numPixels()*20)); // length
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(10);  // Pause for a moment
  }
}


// Function to make fairy lights
static void fairyLightsFunction(){
  delay(100);
  while(true){
    // Loop through pixel by pixel (Edit them 1 by 1)
    for (int i=0; i<strip.numPixels()-38; i++) { // Some reason it goes exactly 38 over idk
      cRed = 255; // Set colours
      cGreen = 180;
      cBlue = 0;
      
      randValue = random(0, 10);
      if (randValue < 7){ // If less than 7
        cRed = 0;
        cBlue = 0;
        cGreen = 0;
      }
      strip.setPixelColor(i, strip.Color(cRed, cGreen, cBlue)); // Set the pixel i to this colour
      delay(100);
      strip.show();
    }
  }
}
