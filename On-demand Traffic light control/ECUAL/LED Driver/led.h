/*
 * led.h
 *
 * Created: 25/07/2022 9:33:42 pm
 *  Author: moham
 */ 


#ifndef LED_H_
#define LED_H_
#include <stdint.h>
#include "../../MCAL/DIO Drivers/dio.h"


#define ON 1
#define OFF 0

typedef struct LED_t {	uint8_t ledPin , ledPort ;	}	LED;
	
void LED_init(uint8_t ledPort , uint8_t ledPin);
void LED_on (uint8_t ledPort , uint8_t ledPin);
void LED_off (uint8_t ledPort , uint8_t ledPin);
void LED_toggle (uint8_t ledPort , uint8_t ledPin);

/************************* same functions as above but for structs *******************************/


void LED_init_t(LED* led);
void LED_on_t (LED* led);
void LED_off_t (LED* led);
void LED_toggle_t (LED* led);

#endif /* LED_H_ */