// Code to control individually adressable neopixels throught the use of an infared sensor and a remote. WS2812 lights
// Running on 5V from an arduino uno board
// Will need to install adafruit neopixel library and IRRemote library
// Author: Fork

// Include the infared sensor library
#include <IRremote.h>

// Recieve pin for the infared sensor
int RECV_PIN = 11;

// Set up the system
void setup() {
  Serial.begin(9600); // Begin the serial monitor
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the IR reciever
  attachInterrupt(0, IrRecInterrupt, RISING);
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
  // If there is input to the sensor
  if(IrReceiver.decode()){

    // Print the code to the output
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume(); // Resume searching for values
  } 
}


void IrRecInterrupt(){
  Serial.println("Interrupt triggered");
  delay(1000);
}
