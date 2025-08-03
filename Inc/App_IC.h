/*
 * Application.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Yomna Awny Salh
 */

#ifndef APP_IC_H_
#define APP_IC_H_

#include "Ultrasonic.h"

/* ================== Settings ===========================*/
#define Green_LED_Port  			GPIOB
#define Green_LED_Pin				GPIO_PIN_6
#define Yellow_LED_Port				GPIOA
#define Yellow_LED_Pin				GPIO_PIN_11
#define Red_LED_Port				GPIOA
#define Red_LED_Pin					GPIO_PIN_12
/*======================================================*/

extern volatile float distance;
extern volatile float distance2;
extern volatile float distance3;

void Emergency_Braking(void);

void Blind_spot_right(void);
void Blind_spot_left(void);

void Led_Init();
void Red_Led(u8 x);
void Yellow_Led(u8 x);
void Green_Led(u8 x);
void Built_Led(u8 x);


#endif /* APP_IC_H_ */
