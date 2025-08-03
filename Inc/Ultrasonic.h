/*
 * Ultransonic.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Yomna Awny Salh
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "Tim2to5_Interface.h"

/* =========================  Settings =======================*/
//Trigger
#define UltraSonic1_Trigger_Port			GPIOB
#define UltraSonic1_Trigger_Pin				GPIO_PIN_5
#define UltraSonic2_Trigger_Port			GPIOA
#define UltraSonic2_Trigger_Pin				GPIO_PIN_8
#define UltraSonic3_Trigger_Port			GPIOA
#define UltraSonic3_Trigger_Pin				GPIO_PIN_5
//Echo
#define UltraSonic1_Echo_Port				GPIOA
#define UltraSonic1_Echo_Pin				GPIO_PIN_6
#define UltraSonic2_Echo_Port				GPIOB
#define UltraSonic2_Echo_Pin				GPIO_PIN_9
#define UltraSonic3_Echo_Port				GPIOA
#define UltraSonic3_Echo_Pin				GPIO_PIN_1
/*===========================================================*/

extern volatile u32 risingEdgeTime; // Time captured on the rising edge
extern volatile u32 fallingEdgeTime; // Time captured on the falling edge
extern volatile u8 captureState; // 0 for rising edge, 1 for falling edge
extern volatile float distance;

extern volatile u32 risingEdgeTime2;
extern volatile u32 fallingEdgeTime2;
extern volatile u8 captureState2;
extern volatile float distance2;

extern volatile u32 risingEdgeTime3;
extern volatile u32 fallingEdgeTime3;
extern volatile u8 captureState3;
extern volatile float distance3;

/*===========================================================*/

extern void UltraSonic_Pin_Init(void);
extern void UltraSonic_Init(void);

extern float calculateDistance(void);
extern float calculateDistance2(void);
extern float calculateDistance3(void);

#endif /* ULTRASONIC_H_ */
