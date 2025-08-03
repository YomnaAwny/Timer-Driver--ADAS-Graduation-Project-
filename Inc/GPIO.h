/*
 * GPIO.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Assem Ayman
 */

#ifndef GPIO_H_
#define GPIO_H_

//-----------------------------
//Includes
//-----------------------------

#include "STM32F103C6.h"

//-----------------------------
//Config structure
//-----------------------------

typedef struct
{
	uint16_t GPIO_PinNumber;	// Specifies the GPIO pins to be configured
								// This parameter must be a value @ref GPIO_Pin_Define

	uint8_t	 GPIO_MODE;			// Specifies the operating mode for the selected pins.
								// This parameter must be a value @ref GPIO_Mode_define

	uint8_t	 GPIO_OUTPUT_SPEED;	// Specifies the speed for the selected pins.
								// This parameter must be a value @ref GPIO_SPEED_define
}GPIO_PinConfig_t;

//-----------------------------
//Configuration References Macros
//-----------------------------

//@ref GPIO_PINS_define
#define GPIO_PIN_0						(uint16_t)0x0001 /* Pin 0 selected */
#define GPIO_PIN_1						(uint16_t)0x0002 /* Pin 1 selected */
#define GPIO_PIN_2						(uint16_t)0x0004 /* Pin 2 selected */
#define GPIO_PIN_3						(uint16_t)0x0008 /* Pin 3 selected */
#define GPIO_PIN_4						(uint16_t)0x0010 /* Pin 4 selected */
#define GPIO_PIN_5						(uint16_t)0x0020 /* Pin 5 selected */
#define GPIO_PIN_6						(uint16_t)0x0040 /* Pin 6 selected */
#define GPIO_PIN_7						(uint16_t)0x0080 /* Pin 7 selected */
#define GPIO_PIN_8						(uint16_t)0x0100 /* Pin 8 selected */
#define GPIO_PIN_9						(uint16_t)0x0200 /* Pin 9 selected */
#define GPIO_PIN_10						(uint16_t)0x0400 /* Pin 10 selected */
#define GPIO_PIN_11						(uint16_t)0x0800 /* Pin 11 selected */
#define GPIO_PIN_12						(uint16_t)0x1000 /* Pin 12 selected */
#define GPIO_PIN_13						(uint16_t)0x2000 /* Pin 13 selected */
#define GPIO_PIN_14						(uint16_t)0x4000 /* Pin 14 selected */
#define GPIO_PIN_15						(uint16_t)0x8000 /* Pin 15 selected */
#define GPIO_PIN_ALL					(uint16_t)0xFFFF /* All pins selected */

#define GPIO_PIN_MASK					0x0000FFFFu /* PIN mask for assert test */

//@ref GPIO_Mode_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input
#define GPIO_MODE_ANALOG				(uint8_t)0x00 /* Analog mode */
#define GPIO_MODE_INPUT_FLO				(uint8_t)0x01 /* Floating input */
#define GPIO_MODE_INPUT_PU				(uint8_t)0x02 /* Input with pull-up */
#define GPIO_MODE_INPUT_PD				(uint8_t)0x03 /* Input with pull-down */
#define GPIO_MODE_OUTPUT_PP				(uint8_t)0x04 /* General purpose output push-pull */
#define GPIO_MODE_OUTPUT_OD				(uint8_t)0x05 /* General purpose output Open-drain */
#define GPIO_MODE_OUTPUT_AF_PP			(uint8_t)0x06 /* Alternate function output Push-pull */
#define GPIO_MODE_OUTPUT_AF_OD			(uint8_t)0x07 /* Alternate function output Open-drain */
#define GPIO_MODE_AF_INPUT				(uint8_t)0x08 /* Alternate function input */

//@ref GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M					(uint8_t)0x01u /* Output mode, max speed 10 MHz. */
#define GPIO_SPEED_2M					(uint8_t)0x02u /* Output mode, max speed 2 MHz. */
#define GPIO_SPEED_50M					(uint8_t)0x03u /* Output mode, max speed 50 MHz. */

//@ref GPIO_PIN_state
#define GPIO_PIN_SET  					1
#define GPIO_PIN_RESET  				0

//@ref GPIO_LOCK_RETURN
#define GPIO_LOCK_RETURN_Enabled 		1
#define GPIO_LOCK_RETURN_ERROR	 		0

/*
 * ===============================================
 * 	APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

extern void MCAL_GPIOx_Init (GPIOx_REG* GPIOx, GPIO_PinConfig_t* PinConfig);
extern void MCAL_GPIOx_DeInit(GPIOx_REG* GPIOx);

extern uint8_t MCAL_GPIOx_ReadPin(GPIOx_REG* GPIOx, uint16_t PinNumber);
extern uint16_t MCAL_GPIOx_ReadPort(GPIOx_REG* GPIOx);

extern void MCAL_GPIOx_WritePin(GPIOx_REG* GPIOx, uint16_t PinNumber, uint8_t Value);
extern void MCAL_GPIOx_WritePort(GPIOx_REG* GPIOx, uint16_t Value);

extern void MCAL_GPIOx_TogglePin(GPIOx_REG* GPIOx, uint16_t PinNumber);

extern uint8_t MCAL_GPIOx_LockPin(GPIOx_REG* GPIOx, uint16_t PinNumber);

#endif /* GPIO_H_ */
