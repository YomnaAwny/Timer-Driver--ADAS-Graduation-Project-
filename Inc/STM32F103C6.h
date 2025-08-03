/*
 * STM32F103C6.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Assem Ayman
 */

#ifndef STM32F103C6_H_
#define STM32F103C6_H_
#define LQFP48
//-----------------------------
//Includes
//-----------------------------
#include "Platform_Types.h"
#include <stdlib.h>
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE 	0x08000000UL
#define SYS_MEMORY_BASE 	0x1FFFF000UL
#define SRAM_MEMORY_BASE 	0x20000000UL
//----------------------------
//NVIC Register Map
//---------------------------
#define NVIC_Base			0xE000E100UL
#define NVIC_ISER0			*(vuint32_t*)(NVIC_Base + 0x0)
#define NVIC_ISER1			*(vuint32_t*)(NVIC_Base + 0x4)
#define NVIC_ISER2			*(vuint32_t*)(NVIC_Base + 0x8)
#define NVIC_ICER0			*(vuint32_t*)(NVIC_Base + 0x80)
#define NVIC_ICER1			*(vuint32_t*)(NVIC_Base + 0x84)
#define NVIC_ICER2			*(vuint32_t*)(NVIC_Base + 0x88)
//-----------------------------
//Base addresses for  AHB BUS Peripherals
//-----------------------------
#define RCC_BASE 0x40021000
//-----------------------------
//Base addresses for  APB1 BUS Peripherals
//-----------------------------
#define USART2_BASE 	0x40004400UL
#define USART3_BASE 	0x40004800UL
#define SPI2_BASE		0x40003800UL
#define I2C1_BASE		0x40005400UL
#define I2C2_BASE		0x40005800UL
#define TIMER1_BASE		0x40012C00UL
#define TIMER2_BASE		0x40000000UL
#define TIMER3_BASE		0x40000400UL
#define TIMER4_BASE     0x40000800UL
//-----------------------------
//Base addresses for  APB2 BUS Peripherals
//-----------------------------
#define GPIOA_BASE  0x40010800UL
#define GPIOB_BASE  0x40010C00UL
#define GPIOC_BASE  0x40011000UL
#define GPIOD_BASE  0x40011400UL
#ifndef LQFP48
#define GPIOE_BASE  0x40011800UL
#endif
#define EXTI_BASE   0x40010400UL
#define AFIO_BASE   0x40010000UL
#define USART1_BASE 0x40013800UL
#define SPI1_BASE	0x40013000UL
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32_t CRL;
	vuint32_t CRH;
	vuint32_t IDR;
	vuint32_t ODR;
	vuint32_t BSRR;
	vuint32_t BRR;
	vuint32_t LCKR;
}GPIOx_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32_t EVCR;
	vuint32_t MAPR;
	vuint32_t EXTICR[4];
	uint32_t RESERVED;
	vuint32_t MAPR2;
}AFIO_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32_t IMR;
	vuint32_t EMR;
	vuint32_t RTSR;
	vuint32_t FTSR;
	vuint32_t SWIER;
	vuint32_t PR;
}EXTI_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	vuint32_t CR;
	vuint32_t CFGR;
	vuint32_t CIR;
	vuint32_t APB2RSTR;
	vuint32_t APB1RSTR;
	vuint32_t AHBENR;
	vuint32_t APB2ENR;
	vuint32_t APB1ENR;
	vuint32_t BDCR;
	vuint32_t CSR;
}RCC_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	vuint32_t SR;
	vuint32_t DR;
	vuint32_t BRR;
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t CR3;
	vuint32_t GTPR;
}USARTx_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t SR;
	vuint32_t DR;
	vuint32_t CRCPR;
	vuint32_t RXCRCR;
	vuint32_t TXCRCR;
	vuint32_t I2SCFGR;
	vuint32_t I2SPR;
}SPIx_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: I2C
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t OAR1;
	vuint32_t OAR2;
	vuint32_t DR;
	vuint32_t SR1;
	vuint32_t SR2;
	vuint32_t CCR;
	vuint32_t TRISE;
}I2Cx_REG;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: TIMER2 To TIMER5
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t SMCR;
	vuint32_t DIER;
	vuint32_t SR;
	vuint32_t EGR;
	vuint32_t CCMR1;
	vuint32_t CCMR2;
	vuint32_t CCER;
	vuint32_t CNT;
	vuint32_t PSC;
	vuint32_t ARR;
	uint32_t RESERVED1;
	vuint32_t CCR[4];
	uint32_t RESERVED2;
	vuint32_t DCR;
	vuint32_t DMAR;
}TIMERx_REG;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA		((GPIOx_REG *) GPIOA_BASE)
#define GPIOB		((GPIOx_REG *) GPIOB_BASE)
#define GPIOC		((GPIOx_REG *) GPIOC_BASE)
#define GPIOD		((GPIOx_REG *) GPIOD_BASE)
#define AFIO		((AFIO_REG  *) AFIO_BASE)
#ifndef LQFP48
#define GPIOE		((GPIOx_REG *) GPIOD_BASE)
#endif
#define RCC   		((RCC_REG   *) RCC_BASE)
#define EXTI	    ((EXTI_REG  *) EXTI_BASE)
#define USART1		((USARTx_REG*) USART1_BASE)
#define USART2		((USARTx_REG*) USART2_BASE)
#define USART3		((USARTx_REG*) USART3_BASE)
#define SPI1		((SPIx_REG  *) SPI1_BASE)
#define SPI2		((SPIx_REG  *) SPI2_BASE)
#define I2C1		((I2Cx_REG  *)I2C1_BASE)
#define I2C2		((I2Cx_REG  *)I2C2_BASE)
#define TIMER1		((TIMERx_REG *)(TIMER1_BASE))
#define TIMER2		((TIMERx_REG *)(TIMER2_BASE))
#define TIMER3		((TIMERx_REG *)(TIMER3_BASE))
#define TIMER4		((TIMERx_REG *)(TIMER4_BASE))
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOx_CLK_EN(x)  RCC->APB2ENR |= 1<<(x-63)  //x is either 'A' or 'B' or 'C' .....
#define AFIO_CLK_EN()    RCC->APB2ENR |= 1<<0
#define USART1_CLK_EN()  RCC->APB2ENR |= 1<<14
#define USART2_CLK_EN()  RCC->APB1ENR |= 1<<17
#define USART3_CLK_EN()  RCC->APB1ENR |= 1<<18
#define SPI1_CLK_EN()    RCC->APB2ENR |= 1<<12
#define SPI2_CLK_EN()    RCC->APB1ENR |= 1<<14
#define I2C1_CLK_EN()	 RCC->APB1ENR |= 1<<21
#define I2C2_CLK_EN()	 RCC->APB1ENR |= 1<<22
#define TIMER1_CLK_EN()  RCC->APB2ENR |= 1<<11
#define TIMER2_CLK_EN()  RCC->APB1ENR |= 1<<0
#define TIMER3_CLK_EN()  RCC->APB1ENR |= 1<<1
#define TIMER4_CLK_EN()  RCC->APB1ENR |= 1<<2
//-*-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-
//Enable EXTIx IRQ
#define NVIC_IRQ6_EXTI0_Enable()		NVIC_ISER0 |=1<<6
#define NVIC_IRQ7_EXTI1_Enable()		NVIC_ISER0 |=1<<7
#define NVIC_IRQ8_EXTI2_Enable()		NVIC_ISER0 |=1<<8
#define NVIC_IRQ9_EXTI3_Enable()		NVIC_ISER0 |=1<<9
#define NVIC_IRQ10_EXTI4_Enable()		NVIC_ISER0 |=1<<10
#define NVIC_IRQ23_EXTI5_9_Enable()		NVIC_ISER0 |=1<<23
#define NVIC_IRQ40_EXTI10_15_Enable()	NVIC_ISER1 |=1<<8
//Enable UARTx IRQ
#define NVIC_IRQ37_USART1_Enable()		NVIC_ISER1 |=1<<5
#define NVIC_IRQ38_USART2_Enable()		NVIC_ISER1 |=1<<6
#define NVIC_IRQ39_USART3_Enable()		NVIC_ISER1 |=1<<7

//Disable EXTIx IRQ
#define NVIC_IRQ6_EXTI0_Disable()		NVIC_ICER0 |=1<<6
#define NVIC_IRQ7_EXTI1_Disable()		NVIC_ICER0 |=1<<7
#define NVIC_IRQ8_EXTI2_Disable()		NVIC_ICER0 |=1<<8
#define NVIC_IRQ9_EXTI3_Disable()		NVIC_ICER0 |=1<<9
#define NVIC_IRQ10_EXTI4_Disable()		NVIC_ICER0 |=1<<10
#define NVIC_IRQ23_EXTI5_9_Disable()	NVIC_ICER0 |=1<<23
#define NVIC_IRQ40_EXTI10_15_Disable()	NVIC_ICER1 |=1<<8
//Disable USARTx IRQ
#define NVIC_IRQ37_USART1_Disable()		NVIC_ICER1 |=1<<5
#define NVIC_IRQ38_USART2_Disable()		NVIC_ICER1 |=1<<6
#define NVIC_IRQ39_USART3_Disable()		NVIC_ICER1 |=1<<7

//Enable SPIx IRQ
#define NVIC_IRQ35_SPI1_Enable()		NVIC_ISER1 |=1<<3
#define NVIC_IRQ36_SPI2_Enable()		NVIC_ISER1 |=1<<4
//Disable SPIx IRQ
#define NVIC_IRQ35_SPI1_Disable()		NVIC_ICER1 |=1<<3
#define NVIC_IRQ36_SPI2_Disable()		NVIC_ICER1 |=1<<4

//Enable I2Cx IRQ
#define NVIC_IRQ31_I2C1_EV_Enable()		NVIC_ISER0 |=1<<31
#define NVIC_IRQ32_I2C1_ER_Enable()		NVIC_ISER1 |=1<<0
#define NVIC_IRQ33_I2C2_EV_Enable()		NVIC_ISER1 |=1<<1
#define NVIC_IRQ34_I2C2_ER_Enable()		NVIC_ISER1 |=1<<2
//Disable I2Cx IRQ
#define NVIC_IRQ31_I2C1_EV_Disable()	NVIC_ICER0 |=1<<31
#define NVIC_IRQ32_I2C1_ER_Disable()	NVIC_ICER1 |=1<<0
#define NVIC_IRQ33_I2C2_EV_Disable()	NVIC_ICER1 |=1<<1
#define NVIC_IRQ34_I2C2_ER_Disable()	NVIC_ICER1 |=1<<2

//Enable TIMERx IRQ
#define NVIC_IRQ28_TIMER2_Enable()		NVIC_ISER0 |=1<<28
#define NVIC_IRQ29_TIMER3_Enable()		NVIC_ISER0 |=1<<29
#define NVIC_IRQ30_TIMER4_Enable()		NVIC_ISER0 |=1<<30
//Disable TIMERx IRQ
#define NVIC_IRQ28_TIMER2_Disable()		NVIC_ICER0 |=1<<28
#define NVIC_IRQ29_TIMER3_Disable()		NVIC_ICER0 |=1<<29
#endif /* STM32F103C6_H_ */
