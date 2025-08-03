/*
 * TIM2to5_Interface.h
 *
 *  Created on: Oct 11, 2024
 *      Author: Yomna Awny Salh
 */

#ifndef TIM2TO5_INTERFACE_H_
#define TIM2TO5_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "STM32F103C6.h"

extern void TIM2TO5_Init_InputCaptureMode(void);
void delayTimer_Init(void);

extern void dus(int us);
extern void dms(int ms);

/* =========================  Configuration =======================*/

/*Timer for each component*/
#define TIM_US_1  TIMER3
#define TIM_US_2  TIMER4
#define TIM_US_3  TIMER2
//#define TIM_DELAY TIMER1
//#define TIMER_PWM   TIMER2


/*IMP BITS*/
/*BITS THAT ENABLE CAPTURE MODE*/
#define CC1E 0     //Enable for CC1S
#define CC2E 4     //Enable for CC2S
#define CC3E 8     //Enable for CC3S
#define CC4E 12    //Enable for CC4S


/*BITS THAT MAP TIX ON ICX*/
#define CC1S_TI1 0  //Map TI1 ON IC1
#define CC1S_TI2 1  //Map TI2 on IC1
#define CC2S_TI1 9  //Map TI1 ON IC2
#define CC2S_TI2 8  //Map TI2 on IC2
#define CC3S_TI3 0  //Map TI3 ON IC3
#define CC3S_TI4 1  //Map TI4 on IC3
#define CC4S_TI3 9  //Map TI3 ON IC4
#define CC4S_TI4 8  //Map TI4 on IC4


/*BITS That filter the entering signal*/
#define IC1F1 4
#define IC1F2 5
#define IC1F3 6
#define IC1F4 7

#define IC2F1 12
#define IC2F2 13
#define IC2F3 14
#define IC2F4 15

#define IC3F1 4
#define IC3F2 5
#define IC3F3 6
#define IC3F4 7

#define IC4F1 12
#define IC4F2 13
#define IC4F3 14
#define IC4F4 15

/*Bits for Prescaler*/

#define IC1P1 2
#define IC1P2 3

#define IC2P1 10
#define IC2P2 11

#define IC3P1 2
#define IC3P2 3

#define IC4P1 10
#define IC4P2 11

/*BITS FOR TRIGGER*/
#define CC1P 1   //IC1 TRIGGER, 0 FOR RISING EDGE AND 1 FOR FALLING EDGE
#define CC2P 5   //IC2
#define CC3P 9   //IC3
#define CC4P 13  //IC4

/*BITS FOR ENABLING INTERRUPTS*/
#define UIE 0    //Update Interrupt enable
#define CC1IE 1  //IC1 INTERRUPT ENABLE
#define CC2IE 2  //IC2 INTERRUPT ENABLE
#define CC3IE 3  //IC3 INTERRUPT ENABLE
#define CC4IE 4  //IC4 INTERRUPT ENABLE

/*FLAG BITS*/
#define UIF   0
#define CC1IF 1
#define CC2IF 2
#define CC3IF 3
#define CC4IF 4
#define CC1OF 9
#define CC2OF 10
#define CC3OF 11
#define CC4OF 12

/* PINS FOR EACH ULTRASONIC PIN*/
/*#define ULTRASONIC_1_TRIG PB5
#define ULTRASONIC_1_ECHO PB4 //TIM3_CH1

#define ULTRASONIC_2_TRIG PB8
#define ULTRASONIC_2_ECHO PB9 //TIM4_CH4

#define ULTRASONIC_3_TRIG PA15
#define ULTRASONIC_3_ECHO PB3 //TIM2_CH2 */


/*
 * c6--------------------------- VS-- c8---------------------------
 * Timer 2
PA0 (TIM2_CH1):  channel 1       VS  +PA15

PA1 (TIM2_CH2):  channel 2       VS  PB3+PB5 We are using PB3 as ECHO

PA2 (TIM2_CH3):  channel 3

PA3 (TIM2_CH4):  channel 4  BIG NO

Timer 3
PA6 (TIM3_CH1): Channel 1         VS +PB4 We are using PB4

PA7 (TIM3_CH2): Channel 2

PB0 (TIM3_CH3): Channel 3

PB1 (TIM3_CH4): Channel 4

Timer 4
PB6 (TIM4_CH1): Channel 1

PB7 (TIM4_CH2): Channel 2

PB8 (TIM4_CH3): Channel 3

PB9 (TIM4_CH4): Channel 4


*/




#endif /* TIM2TO5_INTERFACE_H_ */
