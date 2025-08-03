/*
 * TIM2to5_Program.c
 *
 *  Created on: Oct 11, 2024
 *      Author: Yomna Awny Salh
 */

#include "TIM2TO5_Interface.h"
#include "App_IC.h"

volatile u32 risingEdgeTime = 0; // Time captured on the rising edge
volatile u32 fallingEdgeTime = 0; // Time captured on the falling edge
volatile u8 captureState = 0; // 0 for rising edge, 1 for falling edge
volatile float distance;

volatile u32 risingEdgeTime2 = 0;
volatile u32 fallingEdgeTime2 = 0;
volatile u8 captureState2 = 0;
volatile float distance2;

volatile u32 risingEdgeTime3 = 0;
volatile u32 fallingEdgeTime3 = 0;
volatile u8 captureState3 = 0;
volatile float distance3;


void TIM2TO5_Init_InputCaptureMode(void){
	//Enable Timers
	TIMER2_CLK_EN();
	TIMER3_CLK_EN();
	TIMER4_CLK_EN();

	//Choose the mapping of ICx on TIx (TI2 on IC1).
	//Important to miss with CCxS before setting CCxE
	TIM_US_1->CCMR1 |=(1<<CC1S_TI1);
	TIM_US_2->CCMR2 |=(1<<CC4S_TI4);
	TIM_US_3->CCMR1 |=(1<<CC2S_TI2);


	TIM_US_1->CCMR1 &=~(1<<CC1S_TI2);
	TIM_US_2->CCMR2 &=~(1<<CC4S_TI3);
	TIM_US_3->CCMR1 &=~(1<<CC2S_TI1);

	//Enable Input Capture Mode
	TIM_US_1->CCER |=(1<<CC1E);
	TIM_US_2->CCER |=(1<<CC4E);
	TIM_US_3->CCER |=(1<<CC2E);


	//Enable Counters
	TIM_US_1->CR1 |=(1<<0);
	TIM_US_2->CR1 |=(1<<0);
	TIM_US_3->CR1 |=(1<<0);



	//Choose the filter (No filter)
	TIM_US_1->CCMR1 &=~(1<<IC1F1);
	TIM_US_1->CCMR1 &=~(1<<IC1F2);
	TIM_US_1->CCMR1 &=~(1<<IC1F3);
	TIM_US_1->CCMR1 &=~(1<<IC1F4);

	TIM_US_2->CCMR1 &=~(1<<IC4F1);
	TIM_US_2->CCMR1 &=~(1<<IC4F2);
	TIM_US_2->CCMR1 &=~(1<<IC4F3);
	TIM_US_2->CCMR1 &=~(1<<IC4F4);

	TIM_US_3->CCMR1 &=~(1<<IC2F1);
	TIM_US_3->CCMR1 &=~(1<<IC2F2);
	TIM_US_3->CCMR1 &=~(1<<IC2F3);
	TIM_US_3->CCMR1 &=~(1<<IC2F4);



	//Choose prescaler (none)
	TIM_US_1->CCMR1 &=~(1<<IC1P1);
	TIM_US_1->CCMR1 &=~(1<<IC1P2);

	TIM_US_2->CCMR1 &=~(1<<IC4P1);
	TIM_US_2->CCMR1 &=~(1<<IC4P2);

	TIM_US_3->CCMR1 &=~(1<<IC2P1);
	TIM_US_3->CCMR1 &=~(1<<IC2P2);


	TIM_US_1->PSC = 7;
	TIM_US_1->ARR = 0xFFFF;

	TIM_US_2->PSC = 7;
    TIM_US_2->ARR = 0xFFFF;

    TIM_US_3->PSC = 7;
    TIM_US_3->ARR = 0xFFFF;


	//Define trigger
	TIM_US_1->CCER &=~(1<<CC1P);
	TIM_US_2->CCER &=~(1<<CC4P);
	TIM_US_3->CCER &=~(1<<CC2P);


	//Enable Interrupt(for IC1)
	TIM_US_1->DIER |=(1<<CC1IE);
	NVIC_IRQ29_TIMER3_Enable();

	TIM_US_2->DIER |=(1<<CC4IE);
	NVIC_IRQ30_TIMER4_Enable();

	TIM_US_2->DIER |=(1<<CC2IE);
	NVIC_IRQ28_TIMER2_Enable();



}

void TIM2_IRQHandler(void){

	 if (captureState3 == 0) {
	            risingEdgeTime3 = US_3->CCR[1];  // Read the captured value for the rising edge
	            US_3->CCER |= (1<<CC2P);   // Set to capture falling edge next
	            captureState3 = 1;               // Change state to falling edge
	        } else {
	            fallingEdgeTime3 = US_3->CCR[1];  // Read the captured value for the falling edge
	            US_3->CCER &=~ (1<<CC2P);  // Set to capture rising edge next
	            captureState3 = 0;               // Change state to rising edge
	            Blind_spot_left();
	        }

        CLR_BIT(US_3->SR,CC2IF); // Clear the interrupt flag

}


void TIM3_IRQHandler(void){

            if (captureState == 0) {
            risingEdgeTime = TIM_US_1->CCR[0];  // Read the captured value for the rising edge
            TIM_US_1->CCER |= (1<<CC1P);   // Set to capture falling edge next
            captureState = 1;               // Change state to falling edge
        } else {
            fallingEdgeTime = TIM_US_1->CCR[0];  // Read the captured value for the falling edge
            TIM_US_1->CCER &=~ (1<<CC1P);  // Set to capture rising edge next
            captureState = 0;               // Change state to rising edge
            Emergency_Braking();
        }

        CLR_BIT(TIM_US_1->SR,CC1IF); // Clear the interrupt flag

}


void TIM4_IRQHandler(void){

        if (captureState2 == 0) {
            risingEdgeTime2 = TIM_US_2->CCR[3];  // Read the captured value for the rising edge
            TIM_US_2->CCER |= (1<<CC4P);   // Set to capture falling edge next
            captureState2 = 1;               // Change state to falling edge
        } else {
            fallingEdgeTime2 = TIM_US_2->CCR[3];  // Read the captured value for the falling edge
            TIM_US_2->CCER &=~ (1<<CC4P);  // Set to capture rising edge next
            captureState2 = 0;               // Change state to rising edge
            Blind_spot_right();
        }

        CLR_BIT(TIM_US_2->SR,CC4IF); // Clear the interrupt flag

}


void delayTimer_Init(void)
{
	TIMER1_CLK_EN();  			 //Enable CLK for TIMER2

	TIMER1->PSC = 7;            //Clk_input=(8M/(7+1))=1MHZ
	TIMER1->ARR = 0xC350;        //to make interrupt after 50000 tick(50000*10^-6)= 0.05s
	TIMER1->CR1 |=(1<<0);		//Enable timer

}

void dus(int us)
{
	TIMER1->CNT=0;
	while((TIMER1->CNT)<us);
}

void dms(int ms)
{
	int i=0;
	for(i=0;i<ms;i++)
	{
		dus(1000);
	}
}





