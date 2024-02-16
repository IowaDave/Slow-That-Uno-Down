/*
 * Cycle Frequencies
 * 
 * Alternate between 16 MHz and 1 MHz System Clock
 * at 10-second intervals.
 * 
 * Must clear bit 6 in the low fuse byte beforehand
 * to output System Clock onto pin PB0 (Arduino Uno 8).
 * 
 */

#include "powerStuff.h"

 /*
  * Arduino, 16 MHz : 54
  * Arduino,  1 MHz : 41
  * 
  * My measurements vary for the bare '328
  * 328 16 MHz : 10.0 to 15.0   
  * 328  1 MHz :  1.5 to  2.0
  */



void setup() {

  minimizePower();
  
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
}

void loop() {
  static uint8_t count = 0;

  /* 16 MHz clock */
  GPIOR0 = SREG;
  cli();
  CLKPR = 0x80;
  CLKPR = 0;
  SREG = GPIOR0;

  while ( count < 5 )
  {
    digitalWrite(11, HIGH);
    delay(1024);
    digitalWrite(11, LOW);
    delay(1024);
    count += 1;
  }

  /* 1 MHz clock */
  GPIOR0 = SREG;
  cli();
  CLKPR = 0x80;
  CLKPR = 4;
  SREG = GPIOR0;

  count = 40;

  while (count > 0)
  {
    digitalWrite(11, HIGH);
    delay(8);
    digitalWrite(11, LOW);
    delay(8);
    count -= 1;
  }
  
}
