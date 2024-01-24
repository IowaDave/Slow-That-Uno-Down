/*
 * Instruct the System Clock Prescaler
 * of the ATmega328P microcontroller
 * to divide the source clock frequency by 16.
 * An Arduino Uno or Nano having a 16 MHz external
 * crystal oscillator will then operate at a
 * System Clock speed of 1 MHz. 
 * 
 * A program running at 1 MHz draws about 1 mA of power
 * through the ATmega328P microprocessor.
 * 
 * Copyright (c) 2024 by David G. Sparks. All rights reserved.
 * 
 * This code is adapted from the "Blink" example
 * provided with the Arduino IDE. 
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should find a copy of the GNU Lesser General Public License
 * in the Github repository along with this program. If not, write to the
 * Free Software Foundation, Inc., 
 * 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

void setup()
{
  GPIOR0 = SREG;   // preserve system status
  cli();           // disable interrupts globally
  CLKPR = 0x80;    // enable changing clock prescale register
  CLKPR = 0b0100;  // divide by 16 gives 1 MHz system clock
  SREG = GPIOR0;   // restore prior system status
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  /*
   * Note that the delay() procedure supplied in
   * the Arduino IDE core library assumes a 16 MHz clock.
   * With a 1 MHz clock, delay(1000) would pause for 16 seconds!
   * Dividing the delay() argument by 16 gives a pause
   * approximating what the undivided argument would give at 16 MHz.
   */
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000 / 16);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000 / 16);
}
