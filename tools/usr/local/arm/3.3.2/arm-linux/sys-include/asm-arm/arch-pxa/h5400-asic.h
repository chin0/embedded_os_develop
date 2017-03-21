/*
 *
 * Definitions for HP iPAQ3 Handheld Computer
 *
 * Copyright 2002 Hewlett-Packard Company.
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

#ifndef _INCLUDE_H5400_ASIC_H_ 
#define _INCLUDE_H5400_ASIC_H_

#include <asm/arch-sa1100/h3600.h>

/* Define mappings to switch between physical and virtual space */

#if 0
#define asic_p2v(x) ((((u32)(x))&(0x00ffffff)) | H5400_ASIC_VIRT)
#define asic_v2p(x) ((((u32)(x))&(0x00ffffff)) | H5400_ASIC_PHYS)
#endif

#define H5400_ASIC_SET_BIT(_register, bit)				\
	do {								\
	unsigned long value = h5400_asic_read_register (_register);	\
	value |= bit;							\
	h5400_asic_write_register (_register, value);			\
	} while (0)

#define H5400_ASIC_CLEAR_BIT(_register, bit)				\
	do {								\
	unsigned long value = h5400_asic_read_register (_register);	\
	value &= ~bit;							\
	h5400_asic_write_register (_register, value);			\
	} while (0)

#define H5400_ASIC_REGISTER(s,x,y)   \
     ((_H5400_ASIC_Base + _H5400_ASIC_ ## x ## _Base + (_H5400_ASIC_ ## x ## _ ## y)))

#define GET_H5400_ASIC_BIT(x,y,b) ((H5400_ASIC_ ## x ## _ ## y)&(_H5400_ASIC_ ## x ## _ ## y ## _ ## b))

#define SET_H5400_ASIC_GPIO(gpx, gpio, setp) \
do { \
if (setp) \
	H5400_ASIC_SET_BIT (H5400_ASIC_GPIO_ ## gpx ## _DAT, H5400_ASIC_GPIO_ ## gpx ## _ ## gpio); \
else \
	H5400_ASIC_CLEAR_BIT (H5400_ASIC_GPIO_ ## gpx ## _DAT, H5400_ASIC_GPIO_ ## gpx ## _ ## gpio); \
} while (0)

#define SET_H5400_ASIC_GPIO_N(gpx, gpio, setp) \
do { \
if (setp) \
	H5400_ASIC_CLEAR_BIT (H5400_ASIC_GPIO_ ## gpx ## _DAT, H5400_ASIC_GPIO_ ## gpx ## _ ## gpio); \
else \
	H5400_ASIC_SET_BIT (H5400_ASIC_GPIO_ ## gpx ## _DAT, H5400_ASIC_GPIO_ ## gpx ## _ ## gpio); \
} while (0)


#define _H5400_ASIC_Base                      H5400_ASIC_VIRT

#define _H5400_ASIC_SRAM_Base                 0x00000
#define H5400_ASIC_SRAM_PHYSBASE              (H5400_ASIC_PHYS + _H5400_ASIC_SRAM_Base)
#define H5400_ASIC_SRAM_BASE                  (_H5400_ASIC_Base + _H5400_ASIC_SRAM_Base)
#define H5400_ASIC_SRAM_SIZE                  32768
#define _H5400_ASIC_USBHOST_Base              0x20000
#define H5400_ASIC_USBHOST_BASE               (_H5400_ASIC_Base + _H5400_ASIC_USBHOST_Base)

#define _H5400_ASIC_IC_Base                   0x30000

#define _H5400_ASIC_IC_SRCPND                 0x00000
#define _H5400_ASIC_IC_INTMSK                 0x00008
#define _H5400_ASIC_IC_PRIORITY               0x0000c
#define _H5400_ASIC_IC_INTPND                 0x00010
#define _H5400_ASIC_IC_DREQ                   0x00018

#define H5400_ASIC_IC_SRCPND		H5400_ASIC_REGISTER( u32, IC, SRCPND ) /* raw pending interrupts */
#define H5400_ASIC_IC_INTMSK		H5400_ASIC_REGISTER( u32, IC, INTMSK ) /* interrupt mask */
#define H5400_ASIC_IC_PRIORITY		H5400_ASIC_REGISTER( u32, IC, PRIORITY ) /* interrupt priority control */
#define H5400_ASIC_IC_INTPND		H5400_ASIC_REGISTER( u32, IC, INTPND ) /* pending interrupts, accounting for mask */
#define H5400_ASIC_IC_DREQ		H5400_ASIC_REGISTER( u32, IC, DREQ )   /* DREQ control */

#define _H5400_ASIC_IC_INT_GPIO    	25       
#define _H5400_ASIC_IC_INT_WAKEUP3  	24       
#define _H5400_ASIC_IC_INT_ADC  		23       
#define _H5400_ASIC_IC_INT_ADCTS		22
#define _H5400_ASIC_IC_INT_UTXD1		21
#define _H5400_ASIC_IC_INT_UTXD0		20
#define _H5400_ASIC_IC_INT_WAKEUP2	19
#define _H5400_ASIC_IC_INT_ACCEL		18
#define _H5400_ASIC_IC_INT_USBH		17
#define _H5400_ASIC_IC_INT_URXD1		16
#define _H5400_ASIC_IC_INT_URXD0		15
#define _H5400_ASIC_IC_INT_WAKEUP1	14
#define _H5400_ASIC_IC_INT_SD_WAKEUP	13
#define _H5400_ASIC_IC_INT_SD		12
#define _H5400_ASIC_IC_INT_DMA1		11
#define _H5400_ASIC_IC_INT_DMA0		10
#define _H5400_ASIC_IC_INT_UERR1		 9
#define _H5400_ASIC_IC_INT_UERR0		 8
#define _H5400_ASIC_IC_INT_ONEWIRE	 7
#define _H5400_ASIC_IC_INT_FCD		 6
#define _H5400_ASIC_IC_INT_PCMCIA	 5
#define _H5400_ASIC_IC_INT_RECORD	 4
#define _H5400_ASIC_IC_INT_APPBUTTON4	 3
#define _H5400_ASIC_IC_INT_APPBUTTON3	 2
#define _H5400_ASIC_IC_INT_APPBUTTON2	 1
#define _H5400_ASIC_IC_INT_APPBUTTON1	 0

#define IRQ_H5400_ASIC_BUTTON_MASK ((1 << _H5400_ASIC_IC_INT_APPBUTTON1)|(1 << _H5400_ASIC_IC_INT_APPBUTTON2)\
				   |(1 << _H5400_ASIC_IC_INT_APPBUTTON3)|(1 << _H5400_ASIC_IC_INT_APPBUTTON4)\
				   |(1 << _H5400_ASIC_IC_INT_RECORD))
#define IRQ_H5400_ASIC_PCMCIA_MASK (1 << _H5400_ASIC_IC_INT_PCMCIA)
#define IRQ_H5400_ASIC_FCD_MASK    (1 << _H5400_ASIC_IC_INT_FCD)
#define IRQ_H5400_ASIC_ONEWIRE_MASK (1 << _H5400_ASIC_IC_INT_ONEWIRE)
#define IRQ_H5400_ASIC_UERR_MASK ((1 << _H5400_ASIC_IC_INT_UERR0)|(1 << _H5400_ASIC_IC_INT_UERR1))
#define IRQ_H5400_ASIC_DMA_MASK   ((1 << _H5400_ASIC_IC_INT_DMA0)|(1 << _H5400_ASIC_IC_INT_DMA1))
#define IRQ_H5400_ASIC_SD_MASK   ((1 << _H5400_ASIC_IC_INT_SD)|(1 << _H5400_ASIC_IC_INT_SD_WAKEUP))
#define IRQ_H5400_ASIC_URXD_MASK ((1 << _H5400_ASIC_IC_INT_URXD0)|(1 << _H5400_ASIC_IC_INT_URXD1))
#define IRQ_H5400_ASIC_USBH_MASK (1 << _H5400_ASIC_IC_INT_USBH)
#define IRQ_H5400_ASIC_ACCEL_MASK (1 << _H5400_ASIC_IC_INT_ACCEL)
#define IRQ_H5400_ASIC_WAKEUP_MASK ((1 << _H5400_ASIC_IC_INT_WAKEUP2)|(1 << _H5400_ASIC_IC_INT_WAKEUP3))
#define IRQ_H5400_ASIC_UTXD_MASK ((1 << _H5400_ASIC_IC_INT_UTXD0)|(1 << _H5400_ASIC_IC_INT_UTXD1))
#define IRQ_H5400_ASIC_ADCTS_MASK (1 << _H5400_ASIC_IC_INT_ADCTS)
#define IRQ_H5400_ASIC_ADC_MASK (1 << _H5400_ASIC_IC_INT_ADC)
#define IRQ_H5400_ASIC_GPIO_MASK (1 << _H5400_ASIC_IC_INT_GPIO)

#define _H5400_ASIC_DMAC_Base                 0x40000

/********* Clock and Power Management **********/

#define _H5400_ASIC_CPM_Base                  0x50000
#define _H5400_ASIC_CPM_LockTime              0x00000 /* defaults to 0x0fff */
#define _H5400_ASIC_CPM_PllControl            0x00004 /* defaults to 0x00028080 */
#define _H5400_ASIC_CPM_ClockControl          0x00008 /* defaults to 0x0ffe */
#define _H5400_ASIC_CPM_ClockSleep            0x0000c

#define H5400_ASIC_CPM_LockTime		H5400_ASIC_REGISTER( u16, CPM, LockTime )
#define H5400_ASIC_CPM_PllControl	H5400_ASIC_REGISTER( u32, CPM, PllControl )
#define H5400_ASIC_CPM_ClockControl	H5400_ASIC_REGISTER( u16, CPM, ClockControl )
#define H5400_ASIC_CPM_ClockSleep	H5400_ASIC_REGISTER( u16, CPM, ClockSleep )

/* upll lock time count value for uclk, ltime > 150us */
#define H5400_ASIC_CPM_LOCKTIME_MASK    ((1 << 11) -1) 
#define H5400_ASIC_CPM_PLLCON_MDIV_SHIFT 12 /* main divider control */
#define H5400_ASIC_CPM_PLLCON_MDIV_WIDTH 8
#define H5400_ASIC_CPM_PLLCON_PDIV_SHIFT 4 /* pre-divider control */
#define H5400_ASIC_CPM_PLLCON_PDIV_WIDTH 6
#define H5400_ASIC_CPM_PLLCON_SDIV_SHIFT 0 /* post divider control */
#define H5400_ASIC_CPM_PLLCON_SDIV_WIDTH 2

#define H5400_ASIC_CPM_CLKCON_1WIRE_CLKEN	(1 << 11)
#define H5400_ASIC_CPM_CLKCON_MISC_CLKEN	(1 << 10)
#define H5400_ASIC_CPM_CLKCON_LED_CLKEN		(1 << 9)
#define H5400_ASIC_CPM_CLKCON_UART1_CLKEN	(1 << 8)
#define H5400_ASIC_CPM_CLKCON_UART2_CLKEN	(1 << 7)
#define H5400_ASIC_CPM_CLKCON_ADC_CLKEN		(1 << 6)
#define H5400_ASIC_CPM_CLKCON_SD_CLKEN		(1 << 5)
#define H5400_ASIC_CPM_CLKCON_FCD_CLKEN		(1 << 4)
#define H5400_ASIC_CPM_CLKCON_GPIO_CLKEN	(1 << 3)
#define H5400_ASIC_CPM_CLKCON_DMAC_CLKEN	(1 << 2)
#define H5400_ASIC_CPM_CLKCON_USBHOST_CLKEN	(1 << 1)
#define H5400_ASIC_CPM_CLKCON_UCLK_EN		(1 << 0)

#define H5400_ASIC_CPM_CLKSLEEP_UCLK_ON		(1 << 2)
#define H5400_ASIC_CPM_CLKSLEEP_HALF_CLK	(1 << 1)
#define H5400_ASIC_CPM_CLKSLEEP_SLEEP		(1 << 0)

/********* ADC **********/
#define _H5400_ASIC_ADC_Base                  0x80000
#define _H5400_ASIC_ADC_Control               0x00000 /* resets to 0x3fc4 */
#define _H5400_ASIC_ADC_TouchScreenControl    0x00004 /* resets to 0x58 */
#define _H5400_ASIC_ADC_Delay                 0x00008 /* initializes to 0xff */
#define _H5400_ASIC_ADC_Data0                 0x0000c /* xp conversion data register */
#define _H5400_ASIC_ADC_Data1                 0x00010 /* yp conversion data register */

#define H5400_ASIC_ADC_Control			H5400_ASIC_REGISTER(  u16, ADC, Control )
#define H5400_ASIC_ADC_TouchScreenControl	H5400_ASIC_REGISTER(  u8, ADC, TouchScreenControl )
#define H5400_ASIC_ADC_Delay			H5400_ASIC_REGISTER( u16, ADC, Delay )
#define H5400_ASIC_ADC_Data0			H5400_ASIC_REGISTER( u16, ADC, Data0 )
#define H5400_ASIC_ADC_Data1			H5400_ASIC_REGISTER( u16, ADC, Data1 )

#define H5400_ASIC_ADC_CONTROL_FORCE_START	(1 << 0) /* enables conversion start, bit cleared on start */
#define H5400_ASIC_ADC_CONTROL_READ_START	(1 << 1) /* enable start by read operation */
#define H5400_ASIC_ADC_CONTROL_STANDBY		(1 << 2)

#define H5400_ASIC_ADC_CONTROL_SEL_AIN0		(0 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_AIN1		(1 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_AIN2		(2 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_AIN3		(3 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_YM		(4 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_YP		(5 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_XM		(6 << 3)
#define H5400_ASIC_ADC_CONTROL_SEL_XP		(7 << 3)

#define H5400_ASIC_ADC_CONTROL_PRESCALER_SHIFT	6  
#define H5400_ASIC_ADC_CONTROL_PRESCALER_WIDTH  8	  
#define H5400_ASIC_ADC_CONTROL_PRESCALER_ENABLE	(1 << 14)
#define H5400_ASIC_ADC_CONTROL_CONVERSION_END	(1 << 15) /* read only */ 

/* touch screen measurement mode */
#define H5400_ASIC_ADC_TSC_XYPST_NONE		(0 << 0)
#define H5400_ASIC_ADC_TSC_XYPST_XPOS		(1 << 0)
#define H5400_ASIC_ADC_TSC_XYPST_YPOS		(2 << 0)
#define H5400_ASIC_ADC_TSC_XYPST_INTERRUPT	(3 << 0)
#define H5400_ASIC_ADC_TSC_AUTO_MODE		(1 << 2) /* enable auto mode */
#define H5400_ASIC_ADC_TSC_PULL_UP		(1 << 3) /* xp pullup disable */
#define H5400_ASIC_ADC_TSC_XP_SEN		(1 << 4) /* xp output driver disable */
#define H5400_ASIC_ADC_TSC_XM_SEN		(1 << 5) /* xm output driver disable */
#define H5400_ASIC_ADC_TSC_YP_SEN		(1 << 6) /* yp output driver disable */
#define H5400_ASIC_ADC_TSC_YM_SEN		(1 << 7) /* ym output driver disable */

#define H5400_ASIC_ADC_DATA0_XPDATA		((1 << 10) - 1)
#define H5400_ASIC_ADC_DATA0_XYPST_NONE		(0 << 12)
#define H5400_ASIC_ADC_DATA0_XYPST_XPOS		(1 << 12)
#define H5400_ASIC_ADC_DATA0_XYPST_YPOS		(2 << 12)
#define H5400_ASIC_ADC_DATA0_XYPST_INTERRUPT	(3 << 12)
#define H5400_ASIC_ADC_DATA0_AUTO_MODE		(1 << 14)
#define H5400_ASIC_ADC_DATA0_PEN_UP		(1 << 15) /* stylus up */ 


/********* UART **********/
#define _H5400_ASIC_UART_Base                 0x90000

/********* MISC **********/
#define _H5400_ASIC_MISC_Base                 0xa0000

/********* FSI (Fingerprint Scanner Interface) **********/
#define _H5400_ASIC_FSI_Base                 0xb0000
#define _H5400_ASIC_FSI_Control               0x0000    /* R/W 9 bits command register */
#define _H5400_ASIC_FSI_Prescaler             0x0004    /* R/W 8 bits prescaler register */
#define _H5400_ASIC_FSI_DMI                   0x0008    /* R/W 8 bits dummy integration time count register */
#define _H5400_ASIC_FSI_FIFO                  0x000c    /* R/W 8 bits fifo control register */
#define _H5400_ASIC_FSI_Status                0x0010    /* R/W 13 bits status register */
#define _H5400_ASIC_FSI_Data                  0x0014    /* R/W 32 bits data register */

#define H5400_ASIC_FSI_Control            H5400_ASIC_REGISTER( u16, FSI, Control )
#define H5400_ASIC_FSI_Prescaler          H5400_ASIC_REGISTER( u16, FSI, Prescaler )
#define H5400_ASIC_FSI_DMI                H5400_ASIC_REGISTER( u16, FSI, DMI )
#define H5400_ASIC_FSI_FIFO               H5400_ASIC_REGISTER( u16, FSI, FIFO )
#define H5400_ASIC_FSI_Status             H5400_ASIC_REGISTER( u16, FSI, Status )
#define H5400_ASIC_FSI_Data               H5400_ASIC_REGISTER( u16, FSI, Data )

/********* OWM **********/
#define _H5400_ASIC_OWM_Base                  0xa0100
#define _H5400_ASIC_OWM_Command                0x0000    /* R/W 4 bits command register */
#define _H5400_ASIC_OWM_Data                   0x0004    /* R/W 8 bits, transmit / receive buffer */
#define _H5400_ASIC_OWM_Interrupt              0x0008    /* R/W Command register */
#define _H5400_ASIC_OWM_InterruptEnable        0x000c    /* R/W Command register */
#define _H5400_ASIC_OWM_ClockDivisor           0x0010    /* R/W 5 bits of divisor and pre-scale */

#define H5400_ASIC_OWM_Command            H5400_ASIC_REGISTER( u8, OWM, Command )
#define H5400_ASIC_OWM_Data               H5400_ASIC_REGISTER( u8, OWM, Data )
#define H5400_ASIC_OWM_Interrupt          H5400_ASIC_REGISTER( u8, OWM, Interrupt )
#define H5400_ASIC_OWM_InterruptEnable    H5400_ASIC_REGISTER( u8, OWM, InterruptEnable )
#define H5400_ASIC_OWM_ClockDivisor       H5400_ASIC_REGISTER( u8, OWM, ClockDivisor )

#define OWM_CMD_ONE_WIRE_RESET ( 1 << 0 )    /* Set to force reset on 1-wire bus */
#define OWM_CMD_SRA            ( 1 << 1 )    /* Set to switch to Search ROM accelerator mode */
#define OWM_CMD_DQ_OUTPUT      ( 1 << 2 )    /* Write only - forces bus low */
#define OWM_CMD_DQ_INPUT       ( 1 << 3 )    /* Read only - reflects state of bus */

#define OWM_INT_PD             ( 1 << 0 )    /* Presence detect */
#define OWM_INT_PDR            ( 1 << 1 )    /* Presence detect result */
#define OWM_INT_TBE            ( 1 << 2 )    /* Transmit buffer empty */
#define OWM_INT_TEMT           ( 1 << 3 )    /* Transmit shift register empty */
#define OWM_INT_RBF            ( 1 << 4 )    /* Receive buffer full */

#define OWM_INTEN_EPD          ( 1 << 0 )    /* Enable presence detect interrupt */
#define OWM_INTEN_IAS          ( 1 << 1 )    /* INTR active state */
#define OWM_INTEN_ETBE         ( 1 << 2 )    /* Enable transmit buffer empty interrupt */
#define OWM_INTEN_ETMT         ( 1 << 3 )    /* Enable transmit shift register empty interrupt */
#define OWM_INTEN_ERBF         ( 1 << 4 )    /* Enable receive buffer full interrupt */

/********* Secure Digital Interface **********/
#define _H5400_ASIC_SDI_Base                  0xb0000



/********* GPIO **********/
#define _H5400_ASIC_GPIO_Base                 0xc0000

#define _H5400_ASIC_GPIO_GPA_CON1	0x0000 /* reset value is 0xaaaaaaaa */
#define _H5400_ASIC_GPIO_GPA_CON2	0x0004 /* reset value is 0x0000002a */
#define _H5400_ASIC_GPIO_GPA_DAT	0x0008 /* gpio A data register, reset value is 0x00000000 */
#define _H5400_ASIC_GPIO_GPA_PUP	0x000c /* pull up disable register, reset value is 0x00080000 */

#define H5400_ASIC_GPIO_GPA_CON1	H5400_ASIC_REGISTER( u32, GPIO, GPA_CON1 )
#define H5400_ASIC_GPIO_GPA_CON2	H5400_ASIC_REGISTER( u32, GPIO, GPA_CON2 )
#define H5400_ASIC_GPIO_GPA_DAT		H5400_ASIC_REGISTER( u32, GPIO, GPA_DAT ) /* gpio A data register */
#define H5400_ASIC_GPIO_GPA_PUP		H5400_ASIC_REGISTER( u32, GPIO, GPA_PUP ) /* pull up disable register */

#define _H5400_ASIC_GPIO_GPB_CON	0x0010
#define _H5400_ASIC_GPIO_GPB_DAT	0x0014 
#define _H5400_ASIC_GPIO_GPB_PUP	0x0018

#define H5400_ASIC_GPIO_GPB_CON		H5400_ASIC_REGISTER( u32, GPIO, GPB_CON )
#define H5400_ASIC_GPIO_GPB_DAT		H5400_ASIC_REGISTER( u32, GPIO, GPB_DAT ) /* gpio B data register */
#define H5400_ASIC_GPIO_GPB_PUP		H5400_ASIC_REGISTER( u32, GPIO, GPB_PUP ) /* gpio B pull up disable register */

#define _H5400_ASIC_GPIO_GPC_CON	0x001c
#define _H5400_ASIC_GPIO_GPC_DAT	0x0020 
#define _H5400_ASIC_GPIO_GPC_PUP	0x0024

#define H5400_ASIC_GPIO_GPC_CON		H5400_ASIC_REGISTER( u32, GPIO, GPC_CON )
#define H5400_ASIC_GPIO_GPC_DAT		H5400_ASIC_REGISTER( u32, GPIO, GPC_DAT ) /* gpio C data register */
#define H5400_ASIC_GPIO_GPC_PUP		H5400_ASIC_REGISTER( u32, GPIO, GPC_PUP ) /* gpio C pull up disable register */

#define _H5400_ASIC_GPIO_GPD_CON	0x0028
#define _H5400_ASIC_GPIO_GPD_DAT	0x002c 
#define _H5400_ASIC_GPIO_GPD_PUP	0x0030

#define H5400_ASIC_GPIO_GPD_CON		H5400_ASIC_REGISTER( u32, GPIO, GPD_CON )
#define H5400_ASIC_GPIO_GPD_DAT		H5400_ASIC_REGISTER( u32, GPIO, GPD_DAT ) /* gpio D data register */
#define H5400_ASIC_GPIO_GPD_PUP		H5400_ASIC_REGISTER( u32, GPIO, GPD_PUP ) /* gpio D pull up disable register */

#define _H5400_ASIC_GPIO_GPE_CON	0x0034
#define _H5400_ASIC_GPIO_GPE_DAT	0x0038 

#define H5400_ASIC_GPIO_GPE_CON		H5400_ASIC_REGISTER( u32, GPIO, GPE_CON )
#define H5400_ASIC_GPIO_GPE_DAT		H5400_ASIC_REGISTER( u32, GPIO, GPE_DAT ) /* gpio E data register */

#define _H5400_ASIC_GPIO_CK8MCON	0x003c
#define _H5400_ASIC_GPIO_SPCR		0x0040
#define _H5400_ASIC_GPIO_INT1		0x0044
#define _H5400_ASIC_GPIO_INT2		0x0048
#define _H5400_ASIC_GPIO_INT3		0x004c
#define _H5400_ASIC_GPIO_FLTCONFIG1	0x0050 /* clock select and appbutton1 */
#define _H5400_ASIC_GPIO_FLTCONFIG2	0x0054 /* appbutton2 and appbutton3 */
#define _H5400_ASIC_GPIO_FLTCONFIG3	0x0058 /* appbutton4 and joystick1 */
#define _H5400_ASIC_GPIO_FLTCONFIG4	0x005c /* joystick2 and joystick3 */
#define _H5400_ASIC_GPIO_FLTCONFIG5	0x0060 /* joystick4 and joystick5 */
#define _H5400_ASIC_GPIO_FLTCONFIG6	0x0064 /* toggle up and down */
#define _H5400_ASIC_GPIO_FLTCONFIG7	0x0068 /* reset button and sd wakeup */
#define _H5400_ASIC_GPIO_MON		0x006c /* value of signals after filtering, interrupt controlled by enint1 */
#define _H5400_ASIC_GPIO_ENINT1		0x0070
#define _H5400_ASIC_GPIO_ENINT2		0x0074
#define _H5400_ASIC_GPIO_INTPND		0x0078 /* same bits as enabled in enint2 */

#define H5400_ASIC_GPIO_CK8MCON		H5400_ASIC_REGISTER( u32, GPIO, CK8MCON )
#define H5400_ASIC_GPIO_SPCR		H5400_ASIC_REGISTER( u32, GPIO, SPCR )
#define H5400_ASIC_GPIO_INT1		H5400_ASIC_REGISTER( u32, GPIO, INT1 ) /* gpio interrupt config 1 */
#define H5400_ASIC_GPIO_INT2		H5400_ASIC_REGISTER( u32, GPIO, INT2 ) /* gpio interrupt config 2 */
#define H5400_ASIC_GPIO_INT3		H5400_ASIC_REGISTER( u32, GPIO, INT3 ) /* gpio interrupt config 3 */
#define H5400_ASIC_GPIO_FLTCONFIG1	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG1 ) /* gpio filter config 1 */
#define H5400_ASIC_GPIO_FLTCONFIG2	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG2 ) /* gpio filter config 2 */
#define H5400_ASIC_GPIO_FLTCONFIG3	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG3 ) /* gpio filter config 3 */
#define H5400_ASIC_GPIO_FLTCONFIG4	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG4 ) /* gpio filter config 4 */
#define H5400_ASIC_GPIO_FLTCONFIG5	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG5 ) /* gpio filter config 5 */
#define H5400_ASIC_GPIO_FLTCONFIG6	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG6 ) /* gpio filter config 6 */
#define H5400_ASIC_GPIO_FLTCONFIG7	H5400_ASIC_REGISTER( u32, GPIO, FLTCONFIG7 ) /* gpio filter config 7 */
#define H5400_ASIC_GPIO_FLTDAT		H5400_ASIC_REGISTER( u32, GPIO, FLTDAT ) 	/* gpio filtered gpio level */
#define H5400_ASIC_GPIO_ENINT1		H5400_ASIC_REGISTER( u32, GPIO, ENINT1 ) /* gpio interrupt enable 1 */
#define H5400_ASIC_GPIO_ENINT2		H5400_ASIC_REGISTER( u32, GPIO, ENINT2 ) /* gpio interrupt enable 2 */
#define H5400_ASIC_GPIO_INTPND		H5400_ASIC_REGISTER( u32, GPIO, INTPND ) /* gpio interrupt pending */


#define H5400_ASIC_GPIO_GPA_APPBUTTON1			(1 << 0)
#define H5400_ASIC_GPIO_GPA_APPBUTTON2			(1 << 1)
#define H5400_ASIC_GPIO_GPA_APPBUTTON3			(1 << 2)
#define H5400_ASIC_GPIO_GPA_APPBUTTON4			(1 << 3)
#define H5400_ASIC_GPIO_GPA_JOYSTICK1			(1 << 4)
#define H5400_ASIC_GPIO_GPA_JOYSTICK2			(1 << 5)
#define H5400_ASIC_GPIO_GPA_JOYSTICK3			(1 << 6)
#define H5400_ASIC_GPIO_GPA_JOYSTICK4			(1 << 7)
#define H5400_ASIC_GPIO_GPA_JOYSTICK5			(1 << 8)
#define H5400_ASIC_GPIO_GPA_TOGGLEUP_N			(1 << 9)
#define H5400_ASIC_GPIO_GPA_TOGGLEDOWN_N		(1 << 10)
#define H5400_ASIC_GPIO_GPA_RESET_BUTTON_N		(1 << 11)
#define H5400_ASIC_GPIO_GPA_RECORD_N			(1 << 12)
#define H5400_ASIC_GPIO_GPA_MCHG_EN			(1 << 13)
#define H5400_ASIC_GPIO_GPA_USB_DETECT			(1 << 14)
#define H5400_ASIC_GPIO_GPA_ADP_IN_STATUS		(1 << 15)
#define H5400_ASIC_GPIO_GPA_SD_DETECT_N			(1 << 16)
#define H5400_ASIC_GPIO_GPA_OPT_ON_N			(1 << 17)
#define H5400_ASIC_GPIO_GPA_OPT_RESET			(1 << 18)
#define H5400_ASIC_GPIO_GPA_UART_CLK			(1 << 19)

#define H5400_ASIC_GPIO_GPB_CODEC_POWER_ON		(1 << 0)
#define H5400_ASIC_GPIO_GPB_RF_POWER_ON			(1 << 1)
#define H5400_ASIC_GPIO_GPB_AUDIO_POWER_ON		(1 << 2)
#define H5400_ASIC_GPIO_GPB_WLAN_POWER_ON		(1 << 3) /* to 802.11 module */
#define H5400_ASIC_GPIO_GPB_MQ_POWER_ON			(1 << 4)
#define H5400_ASIC_GPIO_GPB_BLUETOOTH_3V0_ON		(1 << 5)
#define H5400_ASIC_GPIO_GPB_BACKLIGHT_POWER_ON		(1 << 6)
#define H5400_ASIC_GPIO_GPB_LCD_EN			(1 << 7)
#define H5400_ASIC_GPIO_GPB_CLK16M			(1 << 8) /* output, not connected */
#define H5400_ASIC_GPIO_GPB_CLK48M			(1 << 9) /* output, not connected */
#define H5400_ASIC_GPIO_GPB_RF_CTS			(1 << 10) /* input */
#define H5400_ASIC_GPIO_GPB_RF_RTS			(1 << 11) /* output */
#define H5400_ASIC_GPIO_GPB_MDL_WAKE			(1 << 12)
#define H5400_ASIC_GPIO_GPB_RESET_P_DN_N
#define H5400_ASIC_GPIO_GPB_HOST_WAKE_STATUS_N
#define H5400_ASIC_GPIO_GPB_MODEM_RESET_STATUS_N

#define H5400_ASIC_GPIO_GPC_FLASH_VPEN			(1 << 0) /* unused. */
#define H5400_ASIC_GPIO_GPC_FLASH_WE_N			(1 << 1) /* unused ? */

#define H5400_ASIC_GPIO_GPD_FCD_DATA0			(1 << 0)
#define H5400_ASIC_GPIO_GPD_FCD_DATA1			(1 << 1)
#define H5400_ASIC_GPIO_GPD_FCD_DATA2			(1 << 2)
#define H5400_ASIC_GPIO_GPD_FCD_DATA3			(1 << 3)
#define H5400_ASIC_GPIO_GPD_FCD_DATA4			(1 << 4)
#define H5400_ASIC_GPIO_GPD_FCD_DATA5			(1 << 5)
#define H5400_ASIC_GPIO_GPD_FCD_DATA6			(1 << 6)
#define H5400_ASIC_GPIO_GPD_FCD_DATA7			(1 << 7)

#define H5400_ASIC_GPIO_GPE_FCD_RESET			(1 << 0)
#define H5400_ASIC_GPIO_GPE_FCD_PCLK			(1 << 1)
#define H5400_ASIC_GPIO_GPE_FCD_TPE			(1 << 2)

#define H5400_ASIC_GPIO_ENINT1_APPB1                   (1 << 0)
#define H5400_ASIC_GPIO_ENINT1_APPB2                   (1 << 1)
#define H5400_ASIC_GPIO_ENINT1_APPB3                   (1 << 2)
#define H5400_ASIC_GPIO_ENINT1_APPB4                   (1 << 3)
#define H5400_ASIC_GPIO_ENINT1_RECORD                  (1 << 4)
#define H5400_ASIC_GPIO_ENINT1_WAKEUP1                 (1 << 5)
#define H5400_ASIC_GPIO_ENINT1_WAKEUP2                 (1 << 6)
#define H5400_ASIC_GPIO_ENINT1_WAKEUP3                 (1 << 7)
#define H5400_ASIC_GPIO_ENINT1_SDWAKE                  (1 << 8)

#define H5400_ASIC_GPIO_ENINT2_JOYSTICK1               (1 << 0)
#define H5400_ASIC_GPIO_ENINT2_JOYSTICK2               (1 << 1)
#define H5400_ASIC_GPIO_ENINT2_JOYSTICK3               (1 << 2)
#define H5400_ASIC_GPIO_ENINT2_JOYSTICK4               (1 << 3)
#define H5400_ASIC_GPIO_ENINT2_JOYSTICK5               (1 << 4)
#define H5400_ASIC_GPIO_ENINT2_TOGGLEUP                (1 << 5)
#define H5400_ASIC_GPIO_ENINT2_TOGGLEDOWN              (1 << 6)
#define H5400_ASIC_GPIO_ENINT2_RESETBUTTON             (1 << 7)
#define H5400_ASIC_GPIO_ENINT2_OPT_RESET               (1 << 8)
#define H5400_ASIC_GPIO_ENINT2_WAN1                    (1 << 9)
#define H5400_ASIC_GPIO_ENINT2_WAN2                    (1 << 10)
#define H5400_ASIC_GPIO_ENINT2_WAN3                    (1 << 11)
#define H5400_ASIC_GPIO_ENINT2_WAN4                    (1 << 12)
#define H5400_ASIC_GPIO_ENINT2_WAN5                    (1 << 13)



#define _H5400_ASIC_LED_Base				0xc1000
#define _H5400_ASIC_LED_LEDCON0				0x00000
#define _H5400_ASIC_LED_LEDCON1				0x00004
#define _H5400_ASIC_LED_LEDCON2				0x00008
#define _H5400_ASIC_LED_LEDCON3				0x0000c
#define _H5400_ASIC_LED_LEDCON4				0x00010
#define _H5400_ASIC_LED_LEDPS				0x00014

#define H5400_ASIC_LED_CONTROL(_n)	H5400_ASIC_REGISTER(  u16, LED, LEDCON0 + (4 * (_n)))
#define H5400_ASIC_LED_LEDCON0		H5400_ASIC_REGISTER(  u16, LED, LEDCON0 )
#define H5400_ASIC_LED_LEDCON1		H5400_ASIC_REGISTER(  u16, LED, LEDCON1 )
#define H5400_ASIC_LED_LEDCON2		H5400_ASIC_REGISTER(  u16, LED, LEDCON2 )
#define H5400_ASIC_LED_LEDCON3		H5400_ASIC_REGISTER(  u16, LED, LEDCON3 )
#define H5400_ASIC_LED_LEDCON4		H5400_ASIC_REGISTER(  u16, LED, LEDCON4 )
#define H5400_ASIC_LED_LEDPS		H5400_ASIC_REGISTER(  u32, LED, LEDPS )

/********* PCMCIA and Expansion Pack Interface **********/
#define _H5400_ASIC_PCMCIA_Base               0xd0000
#define _H5400_ASIC_PCMCIA_TDW                0x00000 /* data width, defaults to 0x01 */
#define _H5400_ASIC_PCMCIA_EPS                0x00004 /* status, defaults to 0x00 */
#define _H5400_ASIC_PCMCIA_CC                 0x00008 /* control, defaults to 0 */
#define _H5400_ASIC_PCMCIA_IC                 0x0000c /* interrupt enable, defaults to 0 */
#define _H5400_ASIC_PCMCIA_IM                 0x00010 /* interrupt edge config, defaults to 0x25a5 */
#define _H5400_ASIC_PCMCIA_IP                 0x00014 /* interrupt pending */
#define _H5400_ASIC_PCMCIA_MISC               0x00018 /* usb mask, defaults to 1 */ 

#define H5400_ASIC_PCMCIA_TDW		H5400_ASIC_REGISTER(  u8, PCMCIA, TDW )
#define H5400_ASIC_PCMCIA_EPS		H5400_ASIC_REGISTER(  u8, PCMCIA, EPS )
#define H5400_ASIC_PCMCIA_CC		H5400_ASIC_REGISTER(  u8, PCMCIA, CC )
#define H5400_ASIC_PCMCIA_IC		H5400_ASIC_REGISTER(  u8, PCMCIA, IC )
#define H5400_ASIC_PCMCIA_IM		H5400_ASIC_REGISTER( u16, PCMCIA, IM )
#define H5400_ASIC_PCMCIA_IP		H5400_ASIC_REGISTER(  u8, PCMCIA, IP )

#define H5400_ASIC_PCMCIA_TDW_CS23_16BIT	(1 << 0)
#define H5400_ASIC_PCMCIA_TDW_CS4_16BIT		(1 << 1)
#define H5400_ASIC_PCMCIA_TDW_BIG_ENDIAN	(1 << 2)

#define H5400_ASIC_PCMCIA_EPS_CD0_N             (1 << 0) /* cd0 interrupt */	 
#define H5400_ASIC_PCMCIA_EPS_CD1_N             (1 << 1) /* cd1 interrupt */	 
#define H5400_ASIC_PCMCIA_EPS_IRQ0_N            (1 << 2) /* irq0 interrupt */	 
#define H5400_ASIC_PCMCIA_EPS_IRQ1_N            (1 << 3) /* irq1 interrupt */	 
#define H5400_ASIC_PCMCIA_EPS_ODET0_N          	(1 << 4) /* odet0 interrupt */	 
#define H5400_ASIC_PCMCIA_EPS_ODET1_N          	(1 << 5) /* odet1 interrupt */	 
#define H5400_ASIC_PCMCIA_EPS_BATT_FLT		(1 << 6) /* batt_flt interrupt */ 

#define H5400_ASIC_PCMCIA_CC_RESET		(1 << 0)

/* shift left by twice the interrupt number */
#define H5400_ASIC_PCMCIA_IM_NONE    0
#define H5400_ASIC_PCMCIA_IM_FALLING 1
#define H5400_ASIC_PCMCIA_IM_RISING  2
#define H5400_ASIC_PCMCIA_IM_BOTH    3

#define H5400_ASIC_PCMCIA_MISC_USB_MASK   0 /* enables usb host master address masking when 1 */

extern void h5400_asic_clock_enable (u32 bit, int state);

extern void h5400_asic_write_register (unsigned long address, unsigned long value);
extern unsigned long h5400_asic_read_register (unsigned long address);

#endif /* _INCLUDE_H5400_ASIC_H_ */
