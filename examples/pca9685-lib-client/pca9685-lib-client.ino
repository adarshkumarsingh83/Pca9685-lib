#include "Pca9685Board.h"

#define NO_OF_BOARDS 3

int MAX_PINS = 0;

Pca9685Board pca9685Board;
void setup() {
  Serial.begin(9600);
  pca9685Board.initPca9685Boards(NO_OF_BOARDS);

  MAX_PINS = NO_OF_BOARDS * 16;
  for (int i = 1; i <= MAX_PINS; i++) {
    pca9685Board.setSwitchRange(i, 1200, 1800);
  }
}

void loop() {
  delay(1000);

  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  pca9685Board.throwSwitch(pinNo);
  pca9685Board.displayPinState();
  delay(1000);
  pca9685Board.closeSwitch(pinNo);
  pca9685Board.displayPinState();
  delay(1000);
}
