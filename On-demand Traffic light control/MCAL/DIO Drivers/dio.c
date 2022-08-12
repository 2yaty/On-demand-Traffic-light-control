/*
 * dio.c
 *
 * Created: 21/07/2022 12:52:56 pm
 * Author: Mohamed Ali
 */ 
#include "dio.h"
void static (*INT0_callback)(void);

void DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction){
	
	switch(portNumber){
		
		case PORTn_A :
			
			if (direction == OUT)
			 {
				DDRA |= (1<<pinNumber) ;
			}
			else if (direction == IN)
			{
				DDRA &= ~(1<<pinNumber);
			}
			else{
				//error handling
			}
			break;
			
		
		case PORTn_B :
		
			if (direction == OUT)
			{
				DDRB |= (1<<pinNumber) ;
			}
			else if (direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
			else{
				//error handling
			}
			break;
		
		
		case PORTn_C :
		
		if (direction == OUT)
		{
			DDRC |= (1<<pinNumber) ;
		}
		else if (direction == IN)
		{
			DDRC &= ~(1<<pinNumber);
		}
		else{
			//error handling
		}
		break;
		
		
		case PORTn_D :
		
		if (direction == OUT)
		{
			DDRD |= (1<<pinNumber) ;
		}
		else if (direction == IN)
		{
			DDRD &= ~(1<<pinNumber);
		}
		else{
			//error handling
		}
		break;
	}
	
}
void DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value){
	
	switch(portNumber){
	
		case PORTn_A :
	
		if (value == HIGH)
		{
			PORTA |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTA &= ~(1<<pinNumber);
		}
		else{
			//error handling
		}
		break;
	
	
		case PORTn_B :
	
		if (value == HIGH)
		{
			PORTB |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTB &= ~(1<<pinNumber);
		}
		else{
			//error handling
		}
		break;
	
	
		case PORTn_C :
	
		if (value == HIGH)
		{
			PORTC |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTC &= ~(1<<pinNumber);
		}
		else{
			//error handling
		}
		break;
	
	
		case PORTn_D :
	
		if (value == HIGH)
		{
			PORTD |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTD &= ~(1<<pinNumber);
		}
		else{
			//error handling
		}
		break;
	}
}

void DIO_toggle(uint8_t pinNumber , uint8_t portNumber ){
	
		switch(portNumber){
			
			case PORTn_A :
			
				PORTA ^= (1<<pinNumber);
			break;
			
			
			case PORTn_B :
			
				PORTB ^= (1<<pinNumber);
			break;
			
			
			case PORTn_C :
			
				PORTC ^= (1<<pinNumber);
			break;
			
			
			case PORTn_D :
			
				PORTD ^= (1<<pinNumber);
			break;
		}
}

pinState DIO_read(uint8_t pinNumber , uint8_t portNumber ){
	
	switch(portNumber){
		
		case PORTn_A :
			return (PINA & (1<<pinNumber))>>pinNumber; 
		
		case PORTn_B :
			return (PINB & (1<<pinNumber))>>pinNumber; 
		
		case PORTn_C :
			return (PINC & (1<<pinNumber))>>pinNumber; 
		
		
		case PORTn_D :
			return (PIND & (1<<pinNumber))>>pinNumber;
			
		default:
		return ERROR; 
	}
}

void enable_external_INT0(void){
	
	PORTD |=(1<<2) ;
	
	GICR = 1<<INT0;
	
	MCUCR |= (1<<ISC01);
	MCUCR |= (1<<ISC00);
	sei();
}
void INT0_FUNC_CALL(void (*callback)(void)){
	
	INT0_callback = callback;
}

ISR (INT0_vect){
	
	INT0_callback();
}
