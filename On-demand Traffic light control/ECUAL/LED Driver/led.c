/*
 * led.c
 *
 * Created: 25/07/2022 9:33:23 pm
 * Author: Mohamed Ali
 */ 

#include "led.h"
void LED_init(uint8_t ledPort , uint8_t ledPin){
	
	DIO_init(ledPin , ledPort , OUT);
}


void LED_on (uint8_t ledPort , uint8_t ledPin){
	
	DIO_write(ledPin , ledPort , HIGH);
}


void LED_off (uint8_t ledPort , uint8_t ledPin){
	
	DIO_write(ledPin , ledPort , LOW);
}


void LED_toggle (uint8_t ledPort , uint8_t ledPin){
	
	DIO_toggle(ledPin , ledPort);
}

/************************* same functions as above but for structs *******************************/

void LED_init_t(LED* led){
	DIO_init(led->ledPin , led->ledPort , OUT);
}


void LED_on_t (LED* led){
	DIO_write(led->ledPin , led->ledPort , HIGH);
}


void LED_off_t (LED* led){
	DIO_write(led->ledPin , led->ledPort , LOW);
}


void LED_toggle_t (LED* led){
	DIO_toggle(led->ledPin , led->ledPort);
}