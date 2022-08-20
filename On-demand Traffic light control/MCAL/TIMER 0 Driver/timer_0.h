/*
 * timer_0.h
 *
 * Created: 11/08/2022 8:02:14 pm
 *  Author: moham
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_


/* TIMER0_init

** Needed 1 sec for every interrupt.
** Made the calculations to calculate the initial value in the timer register TCNT0 and how many overflows that I need to get the timing I want.                                                                     
** Setting the interrupt bit of timer0 and the global interrupt.
** set the prescaler to be 1024 and start the timer.

*/

void TIMER0_init(void);



/* TIMER_FUNC_CALL

** set the function that will be executed when the timer flag bit is set.
*/

void TIMER_FUNC_CALL(void (*callback)(void));



#endif /* TIMER_0_H_ */