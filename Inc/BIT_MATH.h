/*
 * BIT_MATH.h
 *
 *  Created on: May 7, 2024
 *      Author: Yomna Awny Salh
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define No_of_bits 8
#define SET_BIT(reg,bitN) (reg|= (1<<bitN))
#define CLR_BIT(reg,bitN) (reg&= ~(1<<bitN))
#define TOG_BIT(reg,bitN) (reg^= (1<<bitN))
#define GET_BIT(reg,bitN) ((reg>>bitN) &0X01)
#define SET_BYTE(reg,value) (reg= value)
#define ROT_LEFT(reg,bitN) ((reg<<bitN) | (reg>>(No_of_bits - bitN))
#define ROT_RIGHT(reg,bitN) ((reg>>bitN) | (reg<<(No_of_bits - bitN))


#endif /* BIT_MATH_H_ */
