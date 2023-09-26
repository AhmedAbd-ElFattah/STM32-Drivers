/*
 * File Name --> TFTLCD_cmds.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> TFT Commands.
 * */
#ifndef HAL_TFTLCD_TFTLCD_CMDS_H_
#define HAL_TFTLCD_TFTLCD_CMDS_H_



/*
==================================================
  Start Section --> Commands
==================================================
*/
#define		TFT_CMD_NO_OPERATIONS										0x00
#define		TFT_CMD_SW_RESET											0x01
#define		TFT_CMD_READ_DISPLAY_ID										0x04
#define		TFT_CMD_DATA_RGB565											0x05
#define		TFT_CMD_READ_DISPLAY_STATUS									0x09
#define 	TFT_CMD_READ_DISPLAY_POWER_MODE								0x0A
#define 	TFT_CMD_READ_DISPLAY_MADCTL									0x0B
#define 	TFT_CMD_READ_DISPLAY_PIXEL_FORMAT							0x0C
#define 	TFT_CMD_READ_DISPLAY_IMAGE_MODE								0x0D
#define 	TFT_CMD_READ_DISPLAY_SIGNAL_MODE							0x0E
#define		TFT_CMD_READ_DISPLAY_READ_DISPLAY_SELF_DIAGNOSTIC_RESULT	0x0F
#define		TFT_CMD_SLEEPIN												0x10
#define		TFT_CMD_SLEEPOUT											0x11
#define		TFT_CMD_PARTIAL_MODE_ON										0x12
#define		TFT_CMD_PARTIAL_MODE_OFF									0x13
#define		TFT_CMD_DISPLAY_INVERSION_OFF								0x20
#define		TFT_CMD_DISPLAY_INVERSION_ON								0x21
#define		TFT_CMD_DISPLAY_GAMMA_CURVE_SELECT							0x26
#define		TFT_CMD_DISPLAY_OFF											0x28
#define		TFT_CMD_DISPLAY_ON											0x29
#define		TFT_CMD_COLUMN_ADDRESS_SET									0x2A
#define		TFT_CMD_ROW_ADDRESS_SET										0x2B
#define 	TFT_CMD_MEMORY_WRITE										0x2C
#define		TFT_CMD_READ_DATA											0x2E
#define		TFT_CMD_PARTIAL_START_END_ADDRESS_SET						0x30
#define		TFT_CMD_SCROLL_AREA_SET										0x33
#define		TFT_CMD_COLOR_MODE											0x34
#define		TFT_CMD_MEMORY_DATA_ACCESS_CONTROL							0x36
#define		TFT_CMD_SCROLL_START_ADDRESS_OF_RAM							0x37
#define		TFT_CMD_IDLE_MODE_OFF										0x38
#define		TFT_CMD_IDLE_MODE_ON										0x39
#define		TFT_CMD_INTERFACE_PIXEL_FORMAT								0x3A
#define		TFT_CMD_READ_ID1											0xDA
#define		TFT_CMD_READ_ID2											0xDB
#define		TFT_CMD_READ_ID3											0xDC


/*
==================================================
  End   Section --> Commands
==================================================
*/

#endif /* HAL_TFTLCD_TFTLCD_CMDS_H_ */
