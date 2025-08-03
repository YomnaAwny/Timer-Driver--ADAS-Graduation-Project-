/*
 * Ultrasonic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Yomna Awny Salh
 */
#include"Ultrasonic.h"


void UltraSonic_Pin_Init(void){
//ENABLE GPIO

	GPIO_PinConfig_t pincfg;
	pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP; //GPIO_MODE_INPUT_FLO or GPIO_MODE_OUTPUT_PP
	pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;

//-------------------------TRIG--------------------------------------//
	//PB5 TRIG	PIN IN US 1
	pincfg.GPIO_PinNumber = UltraSonic1_Trigger_Pin;
	MCAL_GPIOx_Init(UltraSonic1_Trigger_Port, &pincfg);
	//PA8 TRIG PIN IN US 2
	pincfg.GPIO_PinNumber = UltraSonic2_Trigger_Pin;
	MCAL_GPIOx_Init(UltraSonic2_Trigger_Port, &pincfg);
	//PA5 TRIG PIN IN US 3
	pincfg.GPIO_PinNumber = UltraSonic3_Trigger_Pin;
	MCAL_GPIOx_Init(UltraSonic3_Trigger_Port, &pincfg);
	//-------------------------ECHO-------------------------------------//
	//PA6 ECHO PIN IN US 1
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	pincfg.GPIO_PinNumber = UltraSonic1_Echo_Pin;
	MCAL_GPIOx_Init(UltraSonic1_Echo_Port, &pincfg);
	//PB9 ECHO PIN IN US 2
	pincfg.GPIO_PinNumber = UltraSonic2_Echo_Pin;
	MCAL_GPIOx_Init(UltraSonic2_Echo_Port, &pincfg);
	//PA1 ECHO PIN IN US 3
	pincfg.GPIO_PinNumber = UltraSonic3_Echo_Pin;
	MCAL_GPIOx_Init(UltraSonic3_Echo_Port, &pincfg);
//-----------------------------------------------------------------//

    //INIT ULTRASONIC to make sure the ports start at 0
	MCAL_GPIOx_WritePin(UltraSonic1_Trigger_Port, UltraSonic1_Trigger_Pin,0);
	MCAL_GPIOx_WritePin(UltraSonic2_Trigger_Port, UltraSonic2_Trigger_Pin,0);
	MCAL_GPIOx_WritePin(UltraSonic3_Trigger_Port, UltraSonic3_Trigger_Pin,0);

}

void UltraSonic_Init(void){
	MCAL_GPIOx_WritePin(UltraSonic1_Trigger_Port, UltraSonic1_Trigger_Pin,1);
	MCAL_GPIOx_WritePin(UltraSonic2_Trigger_Port, UltraSonic2_Trigger_Pin,1);
	MCAL_GPIOx_WritePin(UltraSonic3_Trigger_Port, UltraSonic3_Trigger_Pin,1);

	dus(10);

	MCAL_GPIOx_WritePin(UltraSonic1_Trigger_Port, UltraSonic1_Trigger_Pin,0);
	MCAL_GPIOx_WritePin(UltraSonic2_Trigger_Port, UltraSonic2_Trigger_Pin,0);
	MCAL_GPIOx_WritePin(UltraSonic3_Trigger_Port, UltraSonic3_Trigger_Pin,0);

	dms(1);
}

float calculateDistance(void) {
    // Calculate distance based on the time difference between rising and falling edges
	volatile uint32_t timeDifference ;
		if(fallingEdgeTime>risingEdgeTime){
    timeDifference = fallingEdgeTime - risingEdgeTime;}
		else{
	timeDifference = ((0xFFFF - risingEdgeTime)+fallingEdgeTime);
		}

    return ((((float)timeDifference) * 0.0343) / 2.0);// Distance in cm

}

float calculateDistance2(void) {
    // Calculate distance based on the time difference between rising and falling edges
	volatile uint32_t timeDifference2 ;
		if(fallingEdgeTime2>risingEdgeTime2){
    timeDifference2 = fallingEdgeTime2 - risingEdgeTime2;}
		else{
	timeDifference2 = ((0xFFFF - risingEdgeTime2)+fallingEdgeTime2);
		}
    return ((((float)timeDifference2) * 0.0343) / 2.0);// Distance in cm

}


float calculateDistance3(void) {
    // Calculate distance based on the time difference between rising and falling edges
	volatile uint32_t timeDifference3 ;
		if(fallingEdgeTime3>risingEdgeTime3){
    timeDifference3 = fallingEdgeTime3 - risingEdgeTime3;}
		else{
	timeDifference3 = ((0xFFFF - risingEdgeTime3)+fallingEdgeTime3);
		}
    return ((((float)timeDifference3) * 0.0343) / 2.0);
	/*} // Distance in cm
	 *
	 */
}




