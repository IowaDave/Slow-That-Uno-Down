


#include "powerStuff.h"

/*
 * Assembly code adapted from example given in the datasheet
 */
void __WDT_off ()
{  asm volatile
  (
    ".equ ASM_SREG, 0x3f \r\n"
    ".equ ASM_MCUSR, 0x34 \r\n"
    ".equ ASM_WDTCSR, 0x60 \r\n"
    // Preserve SREG and r16
    "push r16 \r\n"
    "in r16, ASM_SREG \r\n"
    "push r16 \r\n"
    // Turn off global interrupt
    "cli \r\n"
    // Reset Watchdog Timer
    "wdr \r\n"
    // Clear WDRF in MCUSR
    "in r16, ASM_MCUSR \r\n"
    "andi r16, 0b00000111 \r\n"
    "out ASM_MCUSR, r16 \r\n"
    // Write logical onr to WDCE and WDE
    // Keeping old prescaler to prevent unintended time-out
    "lds r16, ASM_WDTCSR \r\n"
    "ori r16, 0b00011000 \r\n"
    "sts ASM_WDTCSR, r16 \r\n"
    // Turn off WDT
    "ldi r16, 0b10000000 \r\n"
    "sts ASM_WDTCSR, r16 \r\n"
     // Restore global interupt
    "sei \r\n"
    // recover SREG and r16
    "pop r16 \r\n"
    "out ASM_SREG, r16 \r\n"
    "pop r16 \r\n"
  );
}

/* 
 *  Note: BOD is turned on in the fuses by Arduino IDE
 *  It draws about 25 uA of current.
 */

void minimizePower ()
{
  /* Turn off what we can to minimize power consumption */
  /* Disable and turn off power to unused peripherals */
  ADCSRA = 0;       // Disable the Analog-to_Digital Converter
  PRR = 0b11001111; // TWI, TIM2, - , TIM1, SPI, USART, ADC
  ACSR |= (1<<ACD); // Analog Comparator Disable
  // Internal Bandgap Reference turns off when ADC and AC off
  // BOD is on in the fuses; leave it be
  /* WDTON fuse bit is unprogrammed. Stop WDT now. */
//  MCUSR &= ~(1<<WDRF);  // clear WDRF bit first, then...
//  WDTCSR &= ~( (1<<WDE) | (1<<WDIE)); // ... WDIE and WDE bits
  __WDT_off();
  
  /* Input-Pullup minimizes power usage by unattached I/O pins */
  DIDR1 = 0b11; // disable digital input buffers of AIN1 and AIN0 pins
  DIDR0 = 0b00111111; // disable digital input buffers of the analog pins
  DDRB = 0;   // input
  PORTB = 0xff;  // pull-up
  DDRC = 0;   // input
  PORTC = 0x7f;  // pullup
  DDRD = 0;   // input
  PORTD = 0xff;  // pullup
}
