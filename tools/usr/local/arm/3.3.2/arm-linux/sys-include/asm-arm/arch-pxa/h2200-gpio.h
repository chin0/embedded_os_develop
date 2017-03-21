#ifndef _H5200_GPIO_H_
#define _H5200_GPIO_H_

#define GET_H2200_GPIO(gpio) \
	(GPLR(GPIO_NR_H2200_ ## gpio) & GPIO_bit(GPIO_NR_H2200_ ## gpio))

#define SET_H2200_GPIO(gpio, setp) \
do { \
if (setp) \
	GPSR(GPIO_NR_H2200_ ## gpio) = GPIO_bit(GPIO_NR_H2200_ ## gpio); \
else \
	GPCR(GPIO_NR_H2200_ ## gpio) = GPIO_bit(GPIO_NR_H2200_ ## gpio); \
} while (0)

#define SET_H2200_GPIO_N(gpio, setp) \
do { \
if (setp) \
	GPCR(GPIO_NR_H2200_ ## gpio) = GPIO_bit(GPIO_NR_H2200_ ## gpio); \
else \
	GPSR(GPIO_NR_H2200_ ## gpio) = GPIO_bit(GPIO_NR_H2200_ ## gpio); \
} while (0)

#define GPIO_NR_H2200_POWER_BUTTON_N	0
#define GPIO_NR_H2200_RESET_BUTTON_N	1
#define GPIO_NR_H2200_BATT_DOOR_N	2
#define GPIO_NR_H2200_USB_DETECT_N	3
#define GPIO_NR_H2200_RS232_DCD		4
#define GPIO_NR_H2200_ASIC_INT_N	5 
#define GPIO_NR_H2200_CIR_SIR_N		6 /* high for 512Mb nand flash, low for 256Mb NAND flash */
#define GPIO_NR_H2200_CF_INT_N		7
#define GPIO_NR_H2200_SD_DETECT_N	8
#define GPIO_NR_H2200_CF_DETECT_N	9
#define GPIO_NR_H2200_BT_WAKE		10 /* wakeup signal to bluetooth module */
/* 11 ? */
#define GPIO_NR_H2200_AC_IN_N		12 /* AC adapter inserted */
#define GPIO_NR_H2200_POWER_ON_N	13 /* power on key signal input ? */
#define GPIO_NR_H2200_LCD_IRQ_N		14 /* interrupt request from mq11xx */
/* 15 is CS1# */
/* 16 ?? */
#define GPIO_NR_H2200_BACKLIGHT_ON	17
/* 18 is pcmcia ready */
#define GPIO_NR_H2200_CPU_200MHZ	19
/* 20 is dreq0 */
#define GPIO_NR_H2200_CHG_EN		21
/* 22 */
#define GPIO_NR_H2200_CF_RESET		23
#define GPIO_NR_H2200_RS232_CIR_N	24 /* rs232 or CIR control signal selection: 1->RS232, 0->CIR */
#define GPIO_NR_H2200_CF_ADD_EN_N	25 /* enable address to be driven to CF bus */
#define GPIO_NR_H2200_CF_POWER_EN	26 /* enable power to CF device */
#define GPIO_NR_H2200_CPU_400MHZ	27 /* see table below */
/* 
 * GPIO19	GPIO27	CPUSPEED
 * 0		0	300MHz
 * 1		0	400MHz
 * 0		1	200MHz
 * 1		1	reserved
 */

#define GPIO_NR_H2200_USB_PULL_UP_N	33

#define GPIO_NR_H2200_SD_POWER_EN	61
#define GPIO_NR_H2200_BOOTLOADER_DETECT_N 62 /* boot loader detect input */
#define GPIO_NR_H2200_CF_BUFF_EN	63 /* enable CF buffers */
#define GPIO_NR_H2200_IR_ON_N		64
#define GPIO_NR_H2200_TDA_MODE		65 /* speaker mode control */
#define GPIO_NR_H2200_MIC_ON_N		66
#define GPIO_NR_H2200_LCD_POWER_ON	67
#define GPIO_NR_H2200_LCD_RESET_N	68
#define GPIO_NR_H2200_SPEAKER_ON	69
#define GPIO_NR_H2200_CODEC_ON		70
#define GPIO_NR_H2200_CODEC_RESET	71
#define GPIO_NR_H2200_CIR_RESET		72
#define GPIO_NR_H2200_CIR_POWER_ON	73 /* consumer IR power on */
#define GPIO_NR_H2200_BT_RESET_N	74 /* bluetooth module reset */
#define GPIO_NR_H2200_BT_IDENT		75 /* 0 -> SMART, 1->zeevo module */
#define GPIO_NR_H2200_BT_POWER_ON	76
#define GPIO_NR_H2200_BT_IRQ		77 /* wakeup signal from bluetooth to cpu */
/* 78 is CS2# */
#define GPIO_NR_H2200_SDRAM_128MB_N	79 /* 0 -> 128Mbit, 1 -> 256Mbit */
#define GPIO_NR_H2200_RS232_ON		80

#endif /* _H2200_GPIO_H */
