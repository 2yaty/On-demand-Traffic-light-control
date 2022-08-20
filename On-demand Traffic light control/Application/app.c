/*
 * app.c
 *
 * Created: 10/08/2022 8:37:10 am
 *  Author: moham
 */ 

#include "app.h"

#define F_CPU 4000000

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../MCAL/TIMER 0 Driver/timer_0.h"
#include "../ECUAL/LED Driver/led.h"
#include "../MCAL/DIO Drivers/dio.h"


LED cars_traffic_lights [] = {{0 ,PORTn_C} , {1,PORTn_C} , {2,PORTn_C}, {1,PORTn_C}};
LED pedestrian_traffic_lights [] = {{0,PORTn_A} , {1,PORTn_A} , {2,PORTn_A}, {1,PORTn_A}};

uint8_t current_light = 0 , last_light = 0;

uint8_t volatile counter =0;



void app_Start (void){
	
	initialize_leds();

	TIMER_FUNC_CALL(traffic_orgnization);
	INT0_FUNC_CALL(pedestrian_mode);
	
	enable_external_INT0();
	TIMER0_init();
	
	traffic_orgnization();
	
	while(1){
		change_turn();
	}
	
}



void traffic_orgnization (void) {
	

	
	if (current_light ==1 || current_light ==3 )
	{
		
		LED_toggle_t(&cars_traffic_lights [ current_light ]);
		LED_on_t(&cars_traffic_lights[last_light]);
		
		LED_toggle_t(&pedestrian_traffic_lights [ current_light ]);
		LED_on_t(&pedestrian_traffic_lights[last_light]);
	}
	else {
		turn_all_leds_off();
		LED_on_t(&cars_traffic_lights [ current_light ]);
		LED_on_t(&pedestrian_traffic_lights [ current_light ]);
	}
	
	
	counter ++;
	
}

void change_turn (void){
	
	if (counter == 5)
	{
		last_light = current_light;
		current_light ++;
		current_light %= 4;

		counter = 0;
	}
	
}



void initialize_leds (void){
	
	for (int i=0 ; i < 4 ; i++)
	{
		LED_init_t(&cars_traffic_lights [i]);
		LED_init_t(&pedestrian_traffic_lights[i]);
	}
	
	
}

void turn_all_leds_off(void){
	
	for (int i=0 ; i < 4 ; i++){
		
		LED_off_t(&cars_traffic_lights [i]);
		LED_off_t(&pedestrian_traffic_lights[i]);
	}
}


void pedestrian_mode(void){
	
	if (current_light == 0)
	{
		current_light = 1;
		last_light = 0;
		counter = 0;
		
	}
	
}



