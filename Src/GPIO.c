/*
 * GPIO.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Assem Ayman
 */


#include "GPIO.h"

static uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;

	default:
		return 0;
		break;
	}
}

/**================================================================
 * @Fn				- MCAL_GPIOx_Init
 * @brief			- Initializes the GPIOx PINy according to the specified parameters in PinConfig
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinConfig pointer to a GPIO_PinConfig_t structure that contains
 * 					  the configuration information for the specified GPIO PIN.
 * @retval 			- None
 * Note				- Stm32F103C6 MCU has GPIO A, B, C, D, E Modules
 * 					  But LQFP48 Package has only GPIO A, B, PART of C/D exported as external PINs from the Module
 */

void MCAL_GPIOx_Init (GPIOx_REG* GPIOx, GPIO_PinConfig_t* PinConfig){

	//Enable clock for gpio ports

	if(GPIOx == GPIOA)
		GPIOx_CLK_EN('A');
	else if (GPIOx == GPIOB)
		GPIOx_CLK_EN('B');
	else if (GPIOx == GPIOC)
		GPIOx_CLK_EN('C');

	//Port configuration register low (GPIOx_CRL)  0 >>> 7
	//Port configuration register high (GPIOx_CRH) 8 >>> 15
	vuint32_t* config_reg = NULL;
	uint8_t CNF_MODE = 0;

	config_reg = PinConfig->GPIO_PinNumber < GPIO_PIN_8 ? &GPIOx->CRL : &GPIOx->CRH;

	//clear CNFx[1:0] MODEx[1:0]
	*config_reg &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if pin is output
	if(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP){
		//set CNFx[1:0] MODEx[1:0]
		CNF_MODE = (PinConfig->GPIO_MODE - 4)<<2 | PinConfig->GPIO_OUTPUT_SPEED ;
	}
	//if pin is input
	else{
		if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO || PinConfig->GPIO_MODE == GPIO_MODE_ANALOG){
			//set CNFx[1:0] MODE[1:0] = 00 (reset state)
			CNF_MODE = PinConfig->GPIO_MODE << 2 ;
		}else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT){ //Consider it as input floating
			CNF_MODE = GPIO_MODE_INPUT_FLO << 2 ;
			// if pin PU PD Input
		}else{
			//if PU
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){
				CNF_MODE = GPIO_MODE_INPUT_PU << 2;
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}else{ // if PD
				CNF_MODE = (GPIO_MODE_INPUT_PD-1) << 2;
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	*config_reg |= CNF_MODE << Get_CRLH_Position(PinConfig->GPIO_PinNumber);
}
/**================================================================
 * @Fn				- MCAL_GPIOx_DeInit
 * @brief			- Reset all the GPIO Registers
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval 			- None
 * Note				- None
 */
void MCAL_GPIOx_DeInit(GPIOx_REG* GPIOx){
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2); //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3); //Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4); //Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5); //Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}
#ifndef LQFP48
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6); //Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}
#endif
}

/**================================================================
 * @Fn				- MCAL_GPIOx_ReadPin
 * @brief			- Read Specific PIN
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port pin to read @ref GPIO_PINS_define
 * @retval 			- The input pin value (two values based on @ref GPIO_PIN_state)
 * Note				- None
 */
uint8_t MCAL_GPIOx_ReadPin(GPIOx_REG* GPIOx, uint16_t PinNumber){
	if((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET)
		return (uint8_t)GPIO_PIN_SET;
	else return (uint8_t)GPIO_PIN_RESET;
}

/**================================================================
 * @Fn				- MCAL_GPIOx_ReadPort
 * @brief			- Read Specific PORT
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval 			- The input port value
 * Note				- None
 */
uint16_t MCAL_GPIOx_ReadPort(GPIOx_REG* GPIOx){
	return (uint16_t)GPIOx->IDR;
}

/**================================================================
 * @Fn				- MCAL_GPIOx_WritePin
 * @brief			- Write on Specific pin
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bit to write @ref GPIO_PINS_define
 * @param [in] 		- Value: Pin value
 * @retval 			- None
 * Note				- None
 */
void MCAL_GPIOx_WritePin(GPIOx_REG* GPIOx, uint16_t PinNumber, uint8_t Value){
	if(Value == GPIO_PIN_SET)
		GPIOx->BSRR = (uint32_t)PinNumber;
	else
		GPIOx->BRR = (uint32_t)PinNumber;
}

/**================================================================
 * @Fn				- MCAL_GPIOx_WritePort
 * @brief			- Write on Specific PORT
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- Value: Port value
 * @retval 			- None
 * Note				- None
 */
void MCAL_GPIOx_WritePort(GPIOx_REG* GPIOx, uint16_t Value){
	GPIOx->ODR = Value;
}

/**================================================================
 * @Fn				- MCAL_GPIOx_TogglePin
 * @brief			- Toggles Specific GPIO pin
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bit to toggle @ref GPIO_PINS_define
 * @retval 			- None
 * Note				- None
 */
void MCAL_GPIOx_TogglePin(GPIOx_REG* GPIOx, uint16_t PinNumber){
	GPIOx->ODR ^= PinNumber;
}

/**================================================================
 * @Fn				- MCAL_GPIOx_LockPin
 * @brief			- The locking mechanism allow the IO configuration to be frozen
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 		- PinNumber: specifies the port bit to lock @ref GPIO_PINS_define
 * @retval 			- OK if pin configure is locked Or ERROR if pin is not locked (OK & ERROR are defined @ref GPIO_LOCK_RETURN)
 * Note				- None
 */
uint8_t MCAL_GPIOx_LockPin(GPIOx_REG* GPIOx, uint16_t PinNumber){
	//Set LCKy
	GPIOx->LCKR |= PinNumber;
	//Set LCKK[16]
	GPIOx->LCKR |= 1<<16;
	//Clear LCKK[16]
	GPIOx->LCKR &= ~(1<<16);
	//Set LCKK[16]
	GPIOx->LCKR |= 1<<16;
	//Read LCKK[16]
	if(((GPIOx->LCKR) & 1<<16)>>16 == 1)
		return GPIO_LOCK_RETURN_Enabled;
	else
		return GPIO_LOCK_RETURN_ERROR;
}
