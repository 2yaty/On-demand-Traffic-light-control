/*
 * dio.h
 *
 * Created: 21/07/2022 12:53:09 pm
 * Author: Mohamed Ali		
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../Utilities/dataTypes.h"

typedef enum pinState {LOW , HIGH , ERROR} pinState;
	
//macros

//direction definitions
#define IN 0
#define OUT 1

//values definitions
#define LOW 0
#define HIGH 1

#define PORTn_A 'A'
#define PORTn_B 'B'
#define PORTn_C 'C'
#define PORTn_D 'D'

// functions 
void DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction);
void DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value);
void DIO_toggle(uint8_t pinNumber , uint8_t portNumber );
pinState DIO_read(uint8_t pinNumber , uint8_t portNumber );
void enable_external_INT0(void);
void INT0_FUNC_CALL(void (*callback)(void));


#endif /* DIO_H_ */