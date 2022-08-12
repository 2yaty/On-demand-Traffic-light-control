/*
 * timer_0.c
 *
 * Created: 11/08/2022 8:01:50 pm
 *  Author: moham
 */ 

#include "timer_0.h"
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

uint8_t i = 0;

void static (*TIMER0_callback)(void);

void TIMER0_init(void){
	
	TCNT0 = 0;
	TIMSK = 0x01;
	sei();
	
	TCCR0 = 0x05;
	
}
void TIMER_FUNC_CALL(void (*callback)(void)){

		TIMER0_callback = callback;
}

ISR(TIMER0_OVF_vect)
{
	 if (i == 16)
	 {
		 TIMER0_callback();
	 }

	i %= 16;
	
	i++;
}