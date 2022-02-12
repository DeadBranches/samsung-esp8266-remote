#include <Arduino.h>

#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Samsung.h>

  const uint16_t kSendPin = 4;  // GPIO with IR LED
  const int kTransmissionDelay = 100;   // Delay duration after IR command
  
  char serial_input; // Stores serial input

IRsend irsend(kSendPin);
  
void setup() {
  Serial.begin(74880);  // todo: try Serial.begin(115200, SERIAL_8N1);
  irsend.begin();
}

void loop() {
  if (Serial.available() > 0) { // Serial input recieved

    serial_input = Serial.read();

    // TO DO: Create a function to reduce code duplication.
    //
    if (serial_input == 'p') {
      Serial.println("transmitting command for off");
      irsend.sendSAMSUNG(0xE0E019E6, 32, 1); // off
      delay(kTransmissionDelay);
    } else if (serial_input == 'o') {
      // menu
      irsend.sendSAMSUNG(0xE0E09966, 32, 1); // on
      delay(kTransmissionDelay);
      Serial.println("sent: on");
    } else if (serial_input == 'l') {
      // menu
      irsend.sendSAMSUNG(0xE0E0807F, 32, 1); // source
      delay(kTransmissionDelay);
      Serial.println("sent: source");
    } else if (serial_input == 'm') {
      // menu
      irsend.sendSAMSUNG(0xE0E058A7, 32, 1); // menu
      delay(kTransmissionDelay);
      Serial.println("sent: menu");
    } else if (serial_input == 'e') {
      // menu
      irsend.sendSAMSUNG(0xE0E016E9, 32, 1); // enter
      delay(kTransmissionDelay);
      Serial.println("sent: enter");
    } else if (serial_input == 'r') {
      // menu
      irsend.sendSAMSUNG(0xE0E01AE5, 32, 1); // return
      delay(kTransmissionDelay);
      Serial.println("sent: return");
    } else if (serial_input == 'q') {
      // menu
      irsend.sendSAMSUNG(0xE0E0B44B, 32, 1); // exit
      delay(kTransmissionDelay);
      Serial.println("sent: exit");
    } else if (serial_input == 'w') {
      // menu
      irsend.sendSAMSUNG(0xE0E006F9, 32, 1); // up
      delay(kTransmissionDelay);
      Serial.println("sent: up");
    } else if (serial_input == 'a') {
      // menu
      irsend.sendSAMSUNG(0xE0E0A659, 32, 1); // left
      delay(kTransmissionDelay);
      Serial.println("sent: left");
    } else if (serial_input == 's') {
      // menu
      irsend.sendSAMSUNG(0xE0E08679, 32, 1); // down
      delay(kTransmissionDelay);
      Serial.println("sent: down");
    } else if (serial_input == 'd') {
      // menu
      irsend.sendSAMSUNG(0xE0E046B9, 32, 1); // right
      delay(kTransmissionDelay);
      Serial.println("sent: right");
    } 
    
  } // end: if Serial.available()
} // end: void loop
