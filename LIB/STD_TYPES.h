/*
 * File Name --> STD_TYPES.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Standard types.
 * */
#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


/*
==================================================
  Start Section --> Defines
==================================================
*/
#ifndef NULL
#define NULL	((void *)0)
#endif

#define STD_MAX_DELAY 0xFFFFFFFF

/*
==================================================
  End   Section --> Defines
==================================================
*/


/*
==================================================
  Start Section --> Macro Functions
==================================================
*/
#define STD_CONCATENATE(x, y) x##y
/*
==================================================
  End   Section --> Macro Functions
==================================================
*/


/*
==================================================
  Start Section --> Data Type Declaration
==================================================
*/
typedef unsigned char 			u8;
typedef unsigned short int 		u16;
typedef unsigned long int 		u32;
typedef unsigned long long int 	u64;


typedef signed char 			s8;
typedef signed short int 		s16;
typedef signed long int 		s32;
typedef signed long long int 	s64;

typedef double					f32;
typedef double					f64;

typedef enum{
	STD_LOW,
	STD_HIGH
}EBool;

typedef enum{
	STD_FALSE,
	STD_TRUE
}Bool;


typedef enum{
	STD_DIASBLE,
	STD_ENABLE
}En;

typedef enum{
	STD_NoTimeOutError,
	STD_TimeOutError
}TimeOutError;

typedef enum{
	STD_LittleEndian,
	STD_BigEndian,
}STD_EndianType;

/* Masked pins */
#define			PIN_0_MASK	             (1<<0)
#define 		PIN_1_MASK	             (1<<1)
#define 		PIN_2_MASK	             (1<<2)
#define 		PIN_3_MASK	             (1<<3)
#define 		PIN_4_MASK	             (1<<4)
#define 		PIN_5_MASK	             (1<<5)
#define 		PIN_6_MASK	             (1<<6)
#define 		PIN_7_MASK	             (1<<7)
#define 		PIN_8_MASK	             (1<<8)
#define 		PIN_9_MASK	             (1<<9)
#define 		PIN_10_MASK	             (1<<10)
#define 		PIN_11_MASK	             (1<<11)
#define 		PIN_12_MASK	             (1<<12)
#define			PIN_13_MASK	             (1<<13)
#define 		PIN_14_MASK	             (1<<14)
#define 		PIN_15_MASK	             (1<<15)
#define			PIN_16_MASK	             (1<<16)
#define 		PORT_MASK	             0xFFFF

/* Pins */
#define			PIN_0		           	0
#define			PIN_1		           	1
#define			PIN_2		           	2
#define			PIN_3		           	3
#define			PIN_4		           	4
#define			PIN_5		           	5
#define			PIN_6		           	6
#define			PIN_7		           	7
#define			PIN_8		           	8
#define			PIN_9		           	9
#define			PIN_10		           	10
#define			PIN_11		           	11
#define			PIN_12		           	12
#define			PIN_13		           	13
#define			PIN_14		           	14
#define			PIN_15		           	15

/*
==================================================
  End   Section --> Data Type Declaration
==================================================
*/


Bool EXTI_CheckInterruptAndClear_Bool(u8 Arg_PinNumber_u8);

#endif /* LIB_STD_TYPES_H_ */
