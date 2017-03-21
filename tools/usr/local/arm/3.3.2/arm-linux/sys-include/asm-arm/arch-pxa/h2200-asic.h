/*
 *
 * Definitions for HP iPAQ H22xx Handheld Computer
 *
 * Copyright 2003 Hewlett-Packard Company.
 *
 * Use consistent with the GNU GPL is permitted,
 * provided that this copyright notice is
 * preserved in its entirety in all copies and derived works.
 *
 * COMPAQ COMPUTER CORPORATION MAKES NO WARRANTIES, EXPRESSED OR IMPLIED,
 * AS TO THE USEFULNESS OR CORRECTNESS OF THIS CODE OR ITS
 * FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 * Author: Jamey Hicks
 *
 */

#ifndef _INCLUDE_H2200_ASIC_H_ 
#define _INCLUDE_H2200_ASIC_H_

#define H2200_ASIC_REGISTER(s,x,y)   \
     (*((volatile s *) (_H2200_ASIC_Base + _H2200_ASIC_ ## x ## _Base + (_H2200_ASIC_ ## x ## _ ## y))))

#define GET_H2200_ASIC_BIT(x,y,b) ((H2200_ASIC_ ## x ## _ ## y)&(_H2200_ASIC_ ## x ## _ ## y ## _ ## b))

#define SET_H2200_ASIC_GPIO(gpx, gpio, setp) \
do { \
if (setp) \
	H2200_ASIC_GPIO_ ## gpx ## _DAT |= H2200_ASIC_GPIO_ ## gpx ## _ ## gpio; \
else \
	H2200_ASIC_GPIO_ ## gpx ## _DAT &= ~(H2200_ASIC_GPIO_ ## gpx ## _ ## gpio); \
} while (0)

#define SET_H2200_ASIC_GPIO_N(gpx, gpio, setp) \
do { \
if (setp) \
	H2200_ASIC_GPIO_ ## gpx ## _DAT &= ~(H2200_ASIC_GPIO_ ## gpx ## _ ## gpio); \
else \
	H2200_ASIC_GPIO_ ## gpx ## _DAT |= H2200_ASIC_GPIO_ ## gpx ## _ ## gpio; \
} while (0)


#define _H2200_ASIC_Base                      H2200_ASIC_VIRT

#define _H2200_ASIC_SRAM_Base                 0x00000
#define H2200_ASIC_SRAM_PHYSBASE              (H2200_ASIC_PHYS + _H2200_ASIC_SRAM_Base)
#define H2200_ASIC_SRAM_BASE                  (_H2200_ASIC_Base + _H2200_ASIC_SRAM_Base)
#define H2200_ASIC_SRAM_SIZE                  16384

/* CPU Interface Control */
#define _H2200_ASIC_CIF_Base                 0x04000
#define _H2200_ASIC_CIF_IFMODE                0x0000
#define _H2200_ASIC_CIF_BOOTMODE              0x0002

/********* Interrupt Controller **********/
#define _H2200_ASIC_IC_Base                  0x04800
#define _H2200_ASIC_IC_SRCPND0                0x0000
#define _H2200_ASIC_IC_SRCPND1                0x0004
#define _H2200_ASIC_IC_INTMSK0                0x0008
#define _H2200_ASIC_IC_INTMSK1                0x000c
#define _H2200_ASIC_IC_PRIORITY0              0x0010
#define _H2200_ASIC_IC_PRIORITY1              0x0014
#define _H2200_ASIC_IC_INTPND0                0x0018
#define _H2200_ASIC_IC_INTPND1                0x001c
#define _H2200_ASIC_IC_DREQCTL                0x0020

/********* DMA **********/

#define _H2200_ASIC_DMA_Base                  0x04400
#define _H2200_ASIC_DMA_DISRC0                 0x0000
#define _H2200_ASIC_DMA_DISRC1                 0x0004
#define _H2200_ASIC_DMA_DIDST0                 0x0008
#define _H2200_ASIC_DMA_DIDST1                 0x000c
#define _H2200_ASIC_DMA_DCON0                  0x0010
#define _H2200_ASIC_DMA_DCON1                  0x0014
#define _H2200_ASIC_DMA_DSTAT0                 0x0018
#define _H2200_ASIC_DMA_DSTAT1                 0x001c
#define _H2200_ASIC_DMA_DCSRC                  0x0020
#define _H2200_ASIC_DMA_DCDST                  0x0024
#define _H2200_ASIC_DMA_DMASKTRIG              0x0028

/********* GPIO **********/
#define _H2200_ASIC_GPIO_Base                 0x07000

#define _H2200_ASIC_GPIO_GPA_CON	0x0000 /* reset value is 0x8000 */
#define _H2200_ASIC_GPIO_GPA_DAT	0x0004 /* gpio A data register, reset value is 0x0000 */
#define _H2200_ASIC_GPIO_GPA_PUP	0x0008 /* pull up disable register, reset value is 0x0000 */

#define H2200_ASIC_GPIO_GPA_CON 	H2200_ASIC_REGISTER( u16, GPIO, GPA_CON1 )
#define H2200_ASIC_GPIO_GPA_DAT		H2200_ASIC_REGISTER( u8, GPIO, GPA_DAT ) /* gpio A data register */
#define H2200_ASIC_GPIO_GPA_PUP		H2200_ASIC_REGISTER( u8, GPIO, GPA_PUP ) /* pull up disable register */

#define _H2200_ASIC_GPIO_GPB_CON	0x0010
#define _H2200_ASIC_GPIO_GPB_DAT	0x0014 
#define _H2200_ASIC_GPIO_GPB_PUP	0x0018

#define H2200_ASIC_GPIO_GPB_CON		H2200_ASIC_REGISTER( u16, GPIO, GPB_CON ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB_DAT		H2200_ASIC_REGISTER( u8, GPIO, GPB_DAT ) /* gpio B data register */
#define H2200_ASIC_GPIO_GPB_PUP		H2200_ASIC_REGISTER( u8, GPIO, GPB_PUP ) /* gpio B pull up disable register */

#define _H2200_ASIC_GPIO_GPC_CON	0x0020
#define _H2200_ASIC_GPIO_GPC_DAT	0x0024 
#define _H2200_ASIC_GPIO_GPC_PUP	0x0028

#define H2200_ASIC_GPIO_GPC_CON		H2200_ASIC_REGISTER( u16, GPIO, GPC_CON ) /* reset: 0xAAAA */
#define H2200_ASIC_GPIO_GPC_DAT		H2200_ASIC_REGISTER( u8, GPIO, GPC_DAT ) /* gpio C data register */
#define H2200_ASIC_GPIO_GPC_PUP		H2200_ASIC_REGISTER( u8, GPIO, GPC_PUP ) /* gpio C pull up disable register */

#define _H2200_ASIC_GPIO_GPD_CON	0x0030
#define _H2200_ASIC_GPIO_GPD_DAT	0x0034 
#define _H2200_ASIC_GPIO_GPD_PUP	0x0038

#define H2200_ASIC_GPIO_GPD_CON		H2200_ASIC_REGISTER( u16, GPIO, GPD_CON ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPD_DAT		H2200_ASIC_REGISTER( u8, GPIO, GPD_DAT ) /* gpio D data register */
#define H2200_ASIC_GPIO_GPD_PUP		H2200_ASIC_REGISTER( u8, GPIO, GPD_PUP ) /* gpio D pull up disable register */

#define _H2200_ASIC_GPIO_CLKOUTCON	0x0040
#define H2200_ASIC_GPIO_CLKOUTCON	H2200_ASIC_REGISTER( u8, GPIO, CLKOUTCON ) /* reset: 0x0000 */

#define _H2200_ASIC_GPIO_GPA_INT0	0x0050
#define _H2200_ASIC_GPIO_GPA_INT0	0x0054
#define _H2200_ASIC_GPIO_GPB_INT0	0x0058
#define _H2200_ASIC_GPIO_GPB_INT0	0x005c

#define _H2200_ASIC_GPIO_GPA0_FLT0	0x0060
#define _H2200_ASIC_GPIO_GPA0_FLT1	0x0064
#define _H2200_ASIC_GPIO_GPA1_FLT0	0x0068
#define _H2200_ASIC_GPIO_GPA1_FLT1	0x006c
#define _H2200_ASIC_GPIO_GPA2_FLT0	0x0070
#define _H2200_ASIC_GPIO_GPA2_FLT1	0x0074
#define _H2200_ASIC_GPIO_GPA3_FLT0	0x0078
#define _H2200_ASIC_GPIO_GPA3_FLT1	0x007c
#define _H2200_ASIC_GPIO_GPA4_FLT0	0x0080
#define _H2200_ASIC_GPIO_GPA4_FLT1	0x0084
#define _H2200_ASIC_GPIO_GPA5_FLT0	0x0088
#define _H2200_ASIC_GPIO_GPA5_FLT1	0x008c
#define _H2200_ASIC_GPIO_GPA6_FLT0	0x0090
#define _H2200_ASIC_GPIO_GPA6_FLT1	0x0094
#define _H2200_ASIC_GPIO_GPA7_FLT0	0x0098
#define _H2200_ASIC_GPIO_GPA7_FLT1	0x009c

#define H2200_ASIC_GPIO_GPA0_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA0_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA0_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA0_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA1_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA1_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA1_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA1_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA2_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA2_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA2_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA2_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA3_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA3_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA3_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA3_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA4_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA4_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA4_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA4_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA5_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA5_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA5_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA5_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA6_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA6_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA6_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA6_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA7_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPA7_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPA7_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPA7_FLT1 ) /* reset: 0x0000 */

#define _H2200_ASIC_GPIO_GPB0_FLT0	0x00a0
#define _H2200_ASIC_GPIO_GPB0_FLT1	0x00a4
#define _H2200_ASIC_GPIO_GPB1_FLT0	0x00a8
#define _H2200_ASIC_GPIO_GPB1_FLT1	0x00ac
#define _H2200_ASIC_GPIO_GPB2_FLT0	0x00b0
#define _H2200_ASIC_GPIO_GPB2_FLT1	0x00b4
#define _H2200_ASIC_GPIO_GPB3_FLT0	0x00b8
#define _H2200_ASIC_GPIO_GPB3_FLT1	0x00bc
#define _H2200_ASIC_GPIO_GPB4_FLT0	0x00c0
#define _H2200_ASIC_GPIO_GPB4_FLT1	0x00c4
#define _H2200_ASIC_GPIO_GPB5_FLT0	0x00c8
#define _H2200_ASIC_GPIO_GPB5_FLT1	0x00cc
#define _H2200_ASIC_GPIO_GPB6_FLT0	0x00d0
#define _H2200_ASIC_GPIO_GPB6_FLT1	0x00d4
#define _H2200_ASIC_GPIO_GPB7_FLT0	0x00d8
#define _H2200_ASIC_GPIO_GPB7_FLT1	0x00dc

#define H2200_ASIC_GPIO_GPB0_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB0_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB0_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB0_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB1_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB1_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB1_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB1_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB2_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB2_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB2_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB2_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB3_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB3_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB3_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB3_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB4_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB4_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB4_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB4_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB5_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB5_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB5_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB5_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB6_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB6_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB6_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB6_FLT1 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB7_FLT0	H2200_ASIC_REGISTER( u16, GPIO, GPB7_FLT0 ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_GPB7_FLT1	H2200_ASIC_REGISTER( u16, GPIO, GPB7_FLT1 ) /* reset: 0x0000 */

#define _H2200_ASIC_GPIO_MON    	0x00e0
#define _H2200_ASIC_GPIO_SPUCR    	0x00e4
#define H2200_ASIC_GPIO_MON	        H2200_ASIC_REGISTER( u16, GPIO, MON ) /* reset: 0x0000 */
#define H2200_ASIC_GPIO_SPUCR	        H2200_ASIC_REGISTER( u16, GPIO, MON ) /* reset: 0x0000 */

/********* NAND Flash Controller **********/

#define _H2200_ASIC_NF_Base    	       0x05000

#define _H2200_ASIC_NF_CONF0            0x0000
#define _H2200_ASIC_NF_CONT0            0x0008
#define _H2200_ASIC_NF_CONT1            0x000c
#define _H2200_ASIC_NF_CMMD             0x0010
#define _H2200_ASIC_NF_ADDR0            0x0014
#define _H2200_ASIC_NF_DATA             0x001c
#define _H2200_ASIC_NF_ECCL0            0x0020
#define _H2200_ASIC_NF_ECCL1            0x0024
#define _H2200_ASIC_NF_ECCH0            0x0028
#define _H2200_ASIC_NF_ECCH1            0x002c
#define _H2200_ASIC_NF_STAT0            0x0030 /* reserved */
#define _H2200_ASIC_NF_STAT1            0x0034
#define _H2200_ASIC_NF_SBLK0            0x0038
#define _H2200_ASIC_NF_SBLK1            0x003c

#define H2200_ASIC_NF_CONF0             H2200_ASIC_REGISTER( u16, NF, CONF0 )
#define H2200_ASIC_NF_CONT0             H2200_ASIC_REGISTER( u16, NF, CONT0 )
#define H2200_ASIC_NF_CONT1             H2200_ASIC_REGISTER( u16, NF, CONT1 )
#define H2200_ASIC_NF_CMMD              H2200_ASIC_REGISTER( u16, NF, CMMD )
#define H2200_ASIC_NF_ADDR0             H2200_ASIC_REGISTER( u16, NF, ADDR0 )
#define H2200_ASIC_NF_DATA              H2200_ASIC_REGISTER( u16, NF, DATA )
#define H2200_ASIC_NF_ECCL0             H2200_ASIC_REGISTER( u16, NF, ECCL0 )
#define H2200_ASIC_NF_ECCL1             H2200_ASIC_REGISTER( u16, NF, ECCL1 )
#define H2200_ASIC_NF_ECCH0             H2200_ASIC_REGISTER( u16, NF, ECCH0 )
#define H2200_ASIC_NF_ECCH1             H2200_ASIC_REGISTER( u16, NF, ECCH1 )
#define H2200_ASIC_NF_STAT0             H2200_ASIC_REGISTER( u16, NF, STAT0 )
#define H2200_ASIC_NF_STAT1             H2200_ASIC_REGISTER( u16, NF, STAT1 )
#define H2200_ASIC_NF_SBLK0             H2200_ASIC_REGISTER( u16, NF, SBLK0 )
#define H2200_ASIC_NF_SBLK1             H2200_ASIC_REGISTER( u16, NF, SBLK1 )

/********* ADC **********/
/* looks same as h5400 */
#define _H2200_ASIC_ADC_Base                  0x07800
#define _H2200_ASIC_ADC_Control               0x00000 /* resets to 0x3fc4 */
#define _H2200_ASIC_ADC_TouchScreenControl    0x00004 /* resets to 0x58 */
#define _H2200_ASIC_ADC_Delay                 0x00008 /* initializes to 0xff */
#define _H2200_ASIC_ADC_Data0                 0x0000c /* xp conversion data register */
#define _H2200_ASIC_ADC_Data1                 0x00010 /* yp conversion data register */

#define H2200_ASIC_ADC_Control			H2200_ASIC_REGISTER(  u16, ADC, Control )
#define H2200_ASIC_ADC_TouchScreenControl	H2200_ASIC_REGISTER(  u8, ADC, TouchScreenControl )
#define H2200_ASIC_ADC_Delay			H2200_ASIC_REGISTER( u16, ADC, Delay )
#define H2200_ASIC_ADC_Data0			H2200_ASIC_REGISTER( u16, ADC, Data0 )
#define H2200_ASIC_ADC_Data1			H2200_ASIC_REGISTER( u16, ADC, Data1 )

#define H2200_ASIC_ADC_CONTROL_FORCE_START	(1 << 0) /* enables conversion start, bit cleared on start */
#define H2200_ASIC_ADC_CONTROL_READ_START	(1 << 1) /* enable start by read operation */
#define H2200_ASIC_ADC_CONTROL_STANDBY		(1 << 2)

#define H2200_ASIC_ADC_CONTROL_SEL_AIN0		(0 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_AIN1		(1 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_AIN2		(2 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_AIN3		(3 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_YM		(4 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_YP		(5 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_XM		(6 << 3)
#define H2200_ASIC_ADC_CONTROL_SEL_XP		(7 << 3)

#define H2200_ASIC_ADC_CONTROL_PRESCALER_SHIFT	6  
#define H2200_ASIC_ADC_CONTROL_PRESCALER_WIDTH  8	  
#define H2200_ASIC_ADC_CONTROL_PRESCALER_ENABLE	(1 << 14)
#define H2200_ASIC_ADC_CONTROL_CONVERSION_END	(1 << 15) /* read only */ 

/* touch screen measurement mode */
#define H2200_ASIC_ADC_TSC_XYPST_NONE		(0 << 0)
#define H2200_ASIC_ADC_TSC_XYPST_XPOS		(1 << 0)
#define H2200_ASIC_ADC_TSC_XYPST_YPOS		(2 << 0)
#define H2200_ASIC_ADC_TSC_XYPST_INTERRUPT	(3 << 0)
#define H2200_ASIC_ADC_TSC_AUTO_MODE		(1 << 2) /* enable auto mode */
#define H2200_ASIC_ADC_TSC_PULL_UP		(1 << 3) /* xp pullup disable */
#define H2200_ASIC_ADC_TSC_XP_SEN		(1 << 4) /* xp output driver disable */
#define H2200_ASIC_ADC_TSC_XM_SEN		(1 << 5) /* xm output driver disable */
#define H2200_ASIC_ADC_TSC_YP_SEN		(1 << 6) /* yp output driver disable */
#define H2200_ASIC_ADC_TSC_YM_SEN		(1 << 7) /* ym output driver disable */

#define H2200_ASIC_ADC_DATA0_XPDATA		((1 << 10) - 1)
#define H2200_ASIC_ADC_DATA0_XYPST_NONE		(0 << 12)
#define H2200_ASIC_ADC_DATA0_XYPST_XPOS		(1 << 12)
#define H2200_ASIC_ADC_DATA0_XYPST_YPOS		(2 << 12)
#define H2200_ASIC_ADC_DATA0_XYPST_INTERRUPT	(3 << 12)
#define H2200_ASIC_ADC_DATA0_AUTO_MODE		(1 << 14)
#define H2200_ASIC_ADC_DATA0_PEN_UP		(1 << 15) /* stylus up */ 

/********* Watchdog Timer **********/

#define _H2200_ASIC_WT_Base                   0x06000
#define _H2200_ASIC_WT_Control                0x00000
#define _H2200_ASIC_WT_Data                   0x00004
#define _H2200_ASIC_WT_Count                  0x00008

#define H2200_ASIC_WT_Control          H2200_ASIC_REGISTER( u16, WT, Control )
#define H2200_ASIC_WT_Data             H2200_ASIC_REGISTER( u16, WT, Data )
#define H2200_ASIC_WT_Count            H2200_ASIC_REGISTER( u16, WT, Count )

/********* OWM **********/
#define _H2200_ASIC_OWM_Base                  0x06800
#define _H2200_ASIC_OWM_Command                0x0000    /* R/W 4 bits command register */
#define _H2200_ASIC_OWM_Data                   0x0004    /* R/W 8 bits, transmit / receive buffer */
#define _H2200_ASIC_OWM_Interrupt              0x0008    /* R/W Command register */
#define _H2200_ASIC_OWM_InterruptEnable        0x000c    /* R/W Command register */
#define _H2200_ASIC_OWM_ClockDivisor           0x0010    /* R/W 5 bits of divisor and pre-scale */

#define H2200_ASIC_OWM_Command            H2200_ASIC_REGISTER( u8, OWM, Command )
#define H2200_ASIC_OWM_Data               H2200_ASIC_REGISTER( u8, OWM, Data )
#define H2200_ASIC_OWM_Interrupt          H2200_ASIC_REGISTER( u8, OWM, Interrupt )
#define H2200_ASIC_OWM_InterruptEnable    H2200_ASIC_REGISTER( u8, OWM, InterruptEnable )
#define H2200_ASIC_OWM_ClockDivisor       H2200_ASIC_REGISTER( u8, OWM, ClockDivisor )

/********* RTC **********/
#define _H2200_ASIC_RTC_Base                  0x06400

/* standard RTC core? */

/********* LED **********/

#define _H2200_ASIC_LED_Base				0x07200

/********* Keypad **********/

#define _H2200_ASIC_KEYPAD_Base				0x07400

/********* Clock and Power Management **********/

#define _H2200_ASIC_CPM_Base                  0x04c00
#define _H2200_ASIC_CPM_LockTime              0x00000 /* defaults to 0x0fff */
#define _H2200_ASIC_CPM_PllControl            0x00004 /* defaults to 0x00028080 */
#define _H2200_ASIC_CPM_ClockControl          0x00008 /* defaults to 0x0ffe */
#define _H2200_ASIC_CPM_ClockSleep            0x0000c

#define H2200_ASIC_CPM_LockTime		H2200_ASIC_REGISTER( u16, CPM, LockTime )
#define H2200_ASIC_CPM_PllControl	H2200_ASIC_REGISTER( u16, CPM, PllControl )
#define H2200_ASIC_CPM_ClockControl	H2200_ASIC_REGISTER( u16, CPM, ClockControl )
#define H2200_ASIC_CPM_ClockSleep	H2200_ASIC_REGISTER( u16, CPM, ClockSleep )

#endif /*  _INCLUDE_H2200_ASIC_H_ */
