/*
 * File Name --> SevenSegment_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> SevenSegment driver private info.
 * */

#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_PRIVATE_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_PRIVATE_H_

#define SEVEN_SEG_TOTAL_PINS	8

/*Pins representation has the following order
 * DP	G	F	E	D	C	B	A
 * */

#define	SEVEN_SEG_VAL_0		0b00111111
#define	SEVEN_SEG_VAL_1		0b00000110
#define	SEVEN_SEG_VAL_2		0b01011011
#define	SEVEN_SEG_VAL_3		0b01001111
#define	SEVEN_SEG_VAL_4		0b01100110
#define	SEVEN_SEG_VAL_5		0b01101101
#define	SEVEN_SEG_VAL_6		0b01111101
#define	SEVEN_SEG_VAL_7		0b00000111
#define	SEVEN_SEG_VAL_8		0b01111111
#define	SEVEN_SEG_VAL_9		0b01101111

#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_PRIVATE_H_ */
