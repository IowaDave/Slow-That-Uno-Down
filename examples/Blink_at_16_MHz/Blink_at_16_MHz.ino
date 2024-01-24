/*
 * The default System Clock speed of 
 * an Arduino Uno (through Rev 3) or a Nano
 * is equal to the 16 MHz frequency of the external
 * crystal oscillator mounted on the board.
 * 
 * A program running at 16 MHz draws nearly 10 mA of power
 * through the ATmega328P microprocessor.
 * 
 * This code is due to the "Blink" example
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
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
