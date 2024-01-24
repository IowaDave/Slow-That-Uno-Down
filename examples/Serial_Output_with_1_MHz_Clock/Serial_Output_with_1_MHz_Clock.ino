/*
 * Serial Output with a 1 MHz System Clock
 * Copyright 2024 by David G. Sparks. All rights reserved.
 * 
 * Demonstrates setting the System Clock
 * to a speed of 1 MHz, then adjusting the 
 * Baud Rate Generator of the USART peripheral
 * for Serial communications at 9600 Baud.
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
 *
 */



void setup()
{
  GPIOR0 = SREG;      // preserve status register
  cli();              // disable interrupts globally
  CLKPR = 0x80;       // enable changing clock prescale register
  CLKPR = 0b0100;     // divide by 16 gives 1 MHz system clock
  SREG = GPIOR0;      // restore status register
  
  Serial.begin(9600);
  UBRR0H = 0;         // configure UBBR0 for 9600 baud
  UBRR0L = 12;        // with a 1 MHz system clock
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Hello, World, at 1 MHz!");
  delay(1000 / 16);
}
