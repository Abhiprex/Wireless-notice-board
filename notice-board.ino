#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"

#define DISPLAYS_WIDE 1
#define DISPLAYS_HIGH 1
DMD dmd(DISPLAYS_WIDE, DISPLAYS_HIGH);

char message[100];
int counter = 0;

void ScanDMD() { 
  dmd.scanDisplayBySPI();
}

void setup() {
  Serial.begin(9600);
  
  Timer1.initialize(5000);           
  Timer1.attachInterrupt(ScanDMD);   
  dmd.clearScreen(true);
  
  strcpy(message, "Welcome to MIT ADT");
}

void loop() {
  // Check for incoming Bluetooth serial data
  if (Serial.available() > 0) {
    counter = 0;
    delay(100); // Wait for the complete string buffer to arrive
    
    while (Serial.available() > 0 && counter < 99) {
      message[counter] = Serial.read();
      counter++;
    }
    message[counter] = '\0'; // Terminate the string array safely
    dmd.clearScreen(true);
  }

  // Scroll the text message continuously across the P10 panel
  dmd.selectFont(SystemFont5x7);
  dmd.drawMarquee(message, strlen(message), (32 * DISPLAYS_WIDE) - 1, 0);
  
  long start = millis();
  long tim = start;
  while (tim - start < 2000) {
    dmd.stepMarquee(-1, 0);
    delay(30);
    tim = millis();
  }
}
