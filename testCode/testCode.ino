// Code to control individually adressable neopixels throught the use of an infared sensor and a remote. WS2812 lights
// Running on 5V from an arduino uno board
// Will need to install adafruit neopixel library and IRRemote library
// Author: Fork

// Include the infared sensor library
#include <IRremote.h>

// Recieve pin for the infared sensor
int RECV_PIN = 11;

int firstIRValue = 0;
int secondIRValue = 0;

// Set up the system
void setup() {
  Serial.begin(9600); // Begin the serial monitor
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the IR reciever
  attachInterrupt(0, IrRecInterrupt, RISING);
}

void loop() {
  
}

//Function to do nothing while waiting for an IR command
void decodeIRCommand(){
  noInterrupts();
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
  if(IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    if (secondIRValue == 0){
      Serial.println("Second value = 0");
      secondIRValue = firstIRValue;
      firstIRValue = IrReceiver.decodedIRData.command;
    }
    // If the ISR has been called enough times that both numbers are assigned values
    else {
      firstIRValue = 0;
      secondIRValue = 0;
    }
    IrReceiver.resume();
  }
  
  
}


// Interrupt vector for all IR inputs
void IrRecInterrupt(){
  decodeIRCommand();
}
