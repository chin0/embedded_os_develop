/*
 *
 * Definitions for H3800 Handheld Computer
 *
 * Copyright 2001 Compaq Computer Corporation.
 *
 * Use consistent with the GNU GPL is permitted,
 * provided that this copyright notice is
 * preserved in its entirety in all copies and derived works.
 *
 * COMPAQ COMPUTER CORPORATION MAKES NO WARRANTIES, EXPRESSED OR IMPLIED,
 * AS TO THE USEFULNESS OR CORRECTNESS OF THIS CODE OR ITS
 * FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 * Author: Andrew Christian
 *
 */

#ifndef IPAQ_ASIC3_H
#define IPAQ_ASIC3_H

/****************************************************/
/* H3900, ASIC #3, replaces ASIC #1 */

#define H1900_ASIC3_VIRT	     H3900_ASIC3_VIRT

#define _H3900_ASIC3_Base            (H3900_ASIC3_VIRT)
#define H3900_ASIC3_OFFSET(s,x,y)   \
     (*((volatile s *) (_H3900_ASIC3_Base + _H3900_ASIC3_ ## x ## _Base + (_H3900_ASIC3_ ## x ## _ ## y))))
#define H3900_ASIC3_NOFFSET(s,x,y,z)   \
     (*((volatile s *) (_H3900_ASIC3_Base + _H3900_ASIC3_ ## x ## _ ## y ## _Base + (_H3900_ASIC3_ ## x ## _ ## z))))

#define H3900_ASIC3_GPIO_OFFSET(s,x,y)   \
     (*((volatile s *) (_H3900_ASIC3_Base + _H3900_ASIC3_GPIO_ ## x ## _Base + (_H3900_ASIC3_GPIO_ ## y))))

#define _H3900_ASIC3_GPIO_A_Base      0x0000
#define _H3900_ASIC3_GPIO_B_Base      0x0100
#define _H3900_ASIC3_GPIO_C_Base      0x0200
#define _H3900_ASIC3_GPIO_D_Base      0x0300

#define _H3900_ASIC3_GPIO_Mask          0x00    /* R/W 0:don't mask, 1:mask interrupt */
#define _H3900_ASIC3_GPIO_Direction     0x04    /* R/W 0:input, 1:output              */
#define _H3900_ASIC3_GPIO_Out           0x08    /* R/W 0:output low, 1:output high    */
#define _H3900_ASIC3_GPIO_TriggerType   0x0c    /* R/W 0:level, 1:edge                */
#define _H3900_ASIC3_GPIO_EdgeTrigger   0x10    /* R/W 0:falling, 1:rising            */
#define _H3900_ASIC3_GPIO_LevelTrigger  0x14    /* R/W 0:low, 1:high level detect     */
#define _H3900_ASIC3_GPIO_SleepMask     0x18    /* R/W 0:don't mask, 1:mask trigger in sleep mode  */
#define _H3900_ASIC3_GPIO_SleepOut      0x1c    /* R/W level 0:low, 1:high in sleep mode           */
#define _H3900_ASIC3_GPIO_BattFaultOut  0x20    /* R/W level 0:low, 1:high in batt_fault           */
#define _H3900_ASIC3_GPIO_IntStatus     0x24    /* R/W 0:none, 1:detect               */
/* no 0x28 */
#define _H3900_ASIC3_GPIO_SleepConf     0x2c    /* R/W bit 1: autosleep 0: disable gposlpout in normal mode, enable gposlpout in sleep mode */
#define _H3900_ASIC3_GPIO_Status        0x30    /* R   Pin status                                  */

/* Not connected */
#define H3900_ASIC3_GPIO_A_MASK            H3900_ASIC3_GPIO_OFFSET( u16, A, Mask )
#define H3900_ASIC3_GPIO_A_DIR             H3900_ASIC3_GPIO_OFFSET( u16, A, Direction )       
#define H3900_ASIC3_GPIO_A_OUT             H3900_ASIC3_GPIO_OFFSET( u16, A, Out )    
#define H3900_ASIC3_GPIO_A_LEVELTRI        H3900_ASIC3_GPIO_OFFSET( u16, A, TriggerType )
#define H3900_ASIC3_GPIO_A_RISING          H3900_ASIC3_GPIO_OFFSET( u16, A, EdgeTrigger )
#define H3900_ASIC3_GPIO_A_LEVEL           H3900_ASIC3_GPIO_OFFSET( u16, A, LevelTrigger )
#define H3900_ASIC3_GPIO_A_SLEEP_MASK      H3900_ASIC3_GPIO_OFFSET( u16, A, SleepMask )
#define H3900_ASIC3_GPIO_A_SLEEP_OUT       H3900_ASIC3_GPIO_OFFSET( u16, A, SleepOut )
#define H3900_ASIC3_GPIO_A_BATT_FAULT_OUT  H3900_ASIC3_GPIO_OFFSET( u16, A, BattFaultOut )
#define H3900_ASIC3_GPIO_A_INT_STATUS      H3900_ASIC3_GPIO_OFFSET( u16, A, IntStatus )
#define H3900_ASIC3_GPIO_A_SLEEP_CONF      H3900_ASIC3_GPIO_OFFSET( u16, A, SleepConf )
#define H3900_ASIC3_GPIO_A_STATUS          H3900_ASIC3_GPIO_OFFSET( u16, A, Status )

/* Connected on H3900 */
#define H3900_ASIC3_GPIO_B_MASK            H3900_ASIC3_GPIO_OFFSET( u16, B, Mask )
#define H3900_ASIC3_GPIO_B_DIR             H3900_ASIC3_GPIO_OFFSET( u16, B, Direction )       
#define H3900_ASIC3_GPIO_B_OUT             H3900_ASIC3_GPIO_OFFSET( u16, B, Out )    
#define H3900_ASIC3_GPIO_B_LEVELTRI        H3900_ASIC3_GPIO_OFFSET( u16, B, TriggerType )
#define H3900_ASIC3_GPIO_B_RISING          H3900_ASIC3_GPIO_OFFSET( u16, B, EdgeTrigger )
#define H3900_ASIC3_GPIO_B_LEVEL           H3900_ASIC3_GPIO_OFFSET( u16, B, LevelTrigger )
#define H3900_ASIC3_GPIO_B_SLEEP_MASK      H3900_ASIC3_GPIO_OFFSET( u16, B, SleepMask )
#define H3900_ASIC3_GPIO_B_SLEEP_OUT       H3900_ASIC3_GPIO_OFFSET( u16, B, SleepOut )
#define H3900_ASIC3_GPIO_B_BATT_FAULT_OUT  H3900_ASIC3_GPIO_OFFSET( u16, B, BattFaultOut )
#define H3900_ASIC3_GPIO_B_INT_STATUS      H3900_ASIC3_GPIO_OFFSET( u16, B, IntStatus )
#define H3900_ASIC3_GPIO_B_SLEEP_CONF      H3900_ASIC3_GPIO_OFFSET( u16, B, SleepConf )
#define H3900_ASIC3_GPIO_B_STATUS          H3900_ASIC3_GPIO_OFFSET( u16, B, Status )

/* Not connected */
#define H3900_ASIC3_GPIO_C_MASK            H3900_ASIC3_GPIO_OFFSET( u16, C, Mask )
#define H3900_ASIC3_GPIO_C_DIR             H3900_ASIC3_GPIO_OFFSET( u16, C, Direction )       
#define H3900_ASIC3_GPIO_C_OUT             H3900_ASIC3_GPIO_OFFSET( u16, C, Out )    
#define H3900_ASIC3_GPIO_C_LEVELTRI        H3900_ASIC3_GPIO_OFFSET( u16, C, TriggerType )
#define H3900_ASIC3_GPIO_C_RISING          H3900_ASIC3_GPIO_OFFSET( u16, C, EdgeTrigger )
#define H3900_ASIC3_GPIO_C_LEVEL           H3900_ASIC3_GPIO_OFFSET( u16, C, LevelTrigger )
#define H3900_ASIC3_GPIO_C_SLEEP_MASK      H3900_ASIC3_GPIO_OFFSET( u16, C, SleepMask )
#define H3900_ASIC3_GPIO_C_SLEEP_OUT       H3900_ASIC3_GPIO_OFFSET( u16, C, SleepOut )
#define H3900_ASIC3_GPIO_C_BATT_FAULT_OUT  H3900_ASIC3_GPIO_OFFSET( u16, C, BattFaultOut )
#define H3900_ASIC3_GPIO_C_INT_STATUS      H3900_ASIC3_GPIO_OFFSET( u16, C, IntStatus )
#define H3900_ASIC3_GPIO_C_SLEEP_CONF      H3900_ASIC3_GPIO_OFFSET( u16, C, SleepConf )
#define H3900_ASIC3_GPIO_C_STATUS          H3900_ASIC3_GPIO_OFFSET( u16, C, Status )

/* Connected on H1900 */
#define H3900_ASIC3_GPIO_D_MASK            H3900_ASIC3_GPIO_OFFSET( u16, D, Mask )
#define H3900_ASIC3_GPIO_D_DIR             H3900_ASIC3_GPIO_OFFSET( u16, D, Direction )       
#define H3900_ASIC3_GPIO_D_OUT             H3900_ASIC3_GPIO_OFFSET( u16, D, Out )    
#define H3900_ASIC3_GPIO_D_LEVELTRI        H3900_ASIC3_GPIO_OFFSET( u16, D, TriggerType )
#define H3900_ASIC3_GPIO_D_RISING          H3900_ASIC3_GPIO_OFFSET( u16, D, EdgeTrigger )
#define H3900_ASIC3_GPIO_D_LEVEL           H3900_ASIC3_GPIO_OFFSET( u16, D, LevelTrigger )
#define H3900_ASIC3_GPIO_D_SLEEP_MASK      H3900_ASIC3_GPIO_OFFSET( u16, D, SleepMask )
#define H3900_ASIC3_GPIO_D_SLEEP_OUT       H3900_ASIC3_GPIO_OFFSET( u16, D, SleepOut )
#define H3900_ASIC3_GPIO_D_BATT_FAULT_OUT  H3900_ASIC3_GPIO_OFFSET( u16, D, BattFaultOut )
#define H3900_ASIC3_GPIO_D_INT_STATUS      H3900_ASIC3_GPIO_OFFSET( u16, D, IntStatus )
#define H3900_ASIC3_GPIO_D_SLEEP_CONF      H3900_ASIC3_GPIO_OFFSET( u16, D, SleepConf )
#define H3900_ASIC3_GPIO_D_STATUS          H3900_ASIC3_GPIO_OFFSET( u16, D, Status )

/* LED on the h1910 asic3 seems to be exactly the same as asic2, 
 * with the notable differences that there are only two LEDs,
 * and that they're at different bases. Also, autostopcount actually
 * should work. YMMV however.
 */

#define _H3900_ASIC3_LED_0_Base                0x0700
#define _H3900_ASIC3_LED_1_Base                0x0800
#define _H3900_ASIC3_LED_TimeBase              0x0000    /* R/W  7 bits */
#define _H3900_ASIC3_LED_PeriodTime            0x0004    /* R/W 12 bits */
#define _H3900_ASIC3_LED_DutyTime              0x0008    /* R/W 12 bits */
#define _H3900_ASIC3_LED_AutoStopCount         0x000c    /* R/W 16 bits */

#define H3900_ASIC3_LED_0_TimeBase          H3900_ASIC3_NOFFSET(  u8, LED, 0, TimeBase )
#define H3900_ASIC3_LED_0_PeriodTime        H3900_ASIC3_NOFFSET( u16, LED, 0, PeriodTime )
#define H3900_ASIC3_LED_0_DutyTime          H3900_ASIC3_NOFFSET( u16, LED, 0, DutyTime )
#define H3900_ASIC3_LED_0_AutoStopCount     H3900_ASIC3_NOFFSET( u16, LED, 0, AutoStopCount )

#define H3900_ASIC3_LED_1_TimeBase          H3900_ASIC3_NOFFSET(  u8, LED, 1, TimeBase )
#define H3900_ASIC3_LED_1_PeriodTime        H3900_ASIC3_NOFFSET( u16, LED, 1, PeriodTime )
#define H3900_ASIC3_LED_1_DutyTime          H3900_ASIC3_NOFFSET( u16, LED, 1, DutyTime )
#define H3900_ASIC3_LED_1_AutoStopCount     H3900_ASIC3_NOFFSET( u16, LED, 1, AutoStopCount )

#define H3900_ASIC3_LED_TimeBase(x)         H3900_ASIC3_NOFFSET(  u8, LED, x, TimeBase )
#define H3900_ASIC3_LED_PeriodTime(x)       H3900_ASIC3_NOFFSET( u16, LED, x, PeriodTime )
#define H3900_ASIC3_LED_DutyTime(x)         H3900_ASIC3_NOFFSET( u16, LED, x, DutyTime )
#define H3900_ASIC3_LED_AutoStopCount(x)    H3900_ASIC3_NOFFSET( u16, LED, x, AutoStopCount )

/* for LEDTBS definitions. */
#include <asm/hardware/ipaq-asic-led.h>

#define _H3900_ASIC3_CLOCK_Base		0x0A00
#define _H3900_ASIC3_CLOCK_CDEX           0x00
#define _H3900_ASIC3_CLOCK_SEL            0x04

#define H3900_ASIC3_CLOCK_CDEX         H3900_ASIC3_OFFSET( u16, CLOCK, CDEX )
#define H3900_ASIC3_CLOCK_SEL          H3900_ASIC3_OFFSET( u16, CLOCK, SEL )

#define CLOCK_CDEX_SD_HOST      (1 << 9)   /* R/W: SD host clock source 24.576M/12.288M) */
#define CLOCK_CDEX_SD_BUS       (1 << 10)  /* R/W: SD bus clock source control 24.576M/12.288M */
#define CLOCK_CDEX_EX0          (1 << 13)  /* R/W: 32.768 kHz crystal */
#define CLOCK_CDEX_EX1          (1 << 14)  /* R/W: 24.576 MHz crystal */

#define CLOCK_SEL_SD_HCLK_SEL   (1 << 0)   /* R/W: SDIO host clock select  -  1: 24.576 Mhz, 0: 12.288 MHz */
#define CLOCK_SEL_SD_BCLK_SEL   (1 << 1)   /* R/W: SDIO bus clock select -  1: 24.576 MHz, 0: 12.288 MHz */
#define CLOCK_SEL_CX            (1 << 2)   /* R/W: INT clock source control (32.768 kHz) */


#define _H3900_ASIC3_INTR_Base		0x0B00

#define _H3900_ASIC3_INTR_IntMask       0x00  /* Interrupt mask control */
#define _H3900_ASIC3_INTR_PIntStat      0x04  /* Peripheral interrupt status */
#define _H3900_ASIC3_INTR_IntCPS        0x08  /* Interrupt timer clock pre-scale */
#define _H3900_ASIC3_INTR_IntTBS        0x0c  /* Interrupt timer set */

#define H3900_ASIC3_INTR_IntMask       H3900_ASIC3_OFFSET( u8, INTR, IntMask )
#define H3900_ASIC3_INTR_PIntStat      H3900_ASIC3_OFFSET( u8, INTR, PIntStat )
#define H3900_ASIC3_INTR_IntCPS        H3900_ASIC3_OFFSET( u8, INTR, IntCPS )
#define H3900_ASIC3_INTR_IntTBS        H3900_ASIC3_OFFSET( u16, INTR, IntTBS )

#define ASIC3_INTMASK_GINTMASK    (1 << 0)  /* Global interrupt mask 1:enable */
#define ASIC3_INTMASK_GINTEL      (1 << 1)  /* 1: rising edge, 0: hi level */

#define ASIC3_INTR_PERIPHERAL_A   (1 << 0)
#define ASIC3_INTR_PERIPHERAL_B   (1 << 1)
#define ASIC3_INTR_PERIPHERAL_C   (1 << 2)
#define ASIC3_INTR_PERIPHERAL_D   (1 << 3)

#define ASIC3_INTR_CPS(x)         ((x)&0x0f)    /* 4 bits, max 14 */
#define ASIC3_INTR_CPS_SET        ( 1 << 4 )    /* Time base enable */


/* Basic control of the SD ASIC */
#define _H3900_ASIC3_SDHWCTRL_Base	0x0E00

#define _H3900_ASIC3_SDHWCTRL_SDConf    0x00
#define H3900_ASIC3_SDHWCTRL_SDConf    H3900_ASIC3_OFFSET( u8, SDHWCTRL, SDConf )

#define ASIC3_SDHWCTRL_SUSPEND    (1 << 0)  /* 1=suspend all SD operations */
#define ASIC3_SDHWCTRL_CLKSEL     (1 << 1)  /* 1=SDICK, 0=HCLK */
#define ASIC3_SDHWCTRL_PCLR       (1 << 2)  /* All registers of SDIO cleared */
#define ASIC3_SDHWCTRL_LEVCD      (1 << 3)  /* Level of SD card detection: 1:high, 0:low */
#define ASIC3_SDHWCTRL_LEVWP      (1 << 4)  /* Level of SD card write protection: 1=low, 0=high */
#define ASIC3_SDHWCTRL_SDLED      (1 << 5)  /* SD card LED signal 1=enable, 0=disable */
#define ASIC3_SDHWCTRL_SDPWR      (1 << 6)  /* SD card power supply control 1=enable */


/* This is a pointer to an array of 12 u32 values - but only the lower 2 bytes matter */
/* Use it as "H3900_ASIC3_HWPROTECT_ARRAY[x]" */

#define _H3900_ASIC3_HWPROTECT_Base	0x1000
#define H3900_ASIC3_HWPROTECT_ARRAY  ((volatile u32*)(_H3900_ASIC3_Base + _H3900_ASIC3_HWPROTECT_Base))
#define HWPROTECT_ARRAY_LEN 12
#define HWPROTECT_ARRAY_VALUES {0x4854,0x432d,0x5344,0x494f,0x2050,0x2f4e,0x3a33,0x3048,0x3830,0x3032,0x382d,0x3030}


#define _H3900_ASIC3_EXTCF_Base		0x1100

#define _H3900_ASIC3_EXTCF_Select         0x00
#define _H3900_ASIC3_EXTCF_Reset          0x04

#define H3900_ASIC3_EXTCF_Select    H3900_ASIC3_OFFSET( u16, EXTCF, Select )
#define H3900_ASIC3_EXTCF_Reset     H3900_ASIC3_OFFSET( u16, EXTCF, Reset )

#define ASIC3_EXTCF_SD_MEM_ENABLE         (1 << 14)

/*****************************************************************************
 *  The SD configuration registers are at a completely different location
 *  in memory.  They are divided into three sets of registers:
 *
 *  SD_CONFIG         Core configuration register
 *  SD_CTRL           Control registers for SD operations
 *  SDIO_CTRL         Control registers for SDIO operations
 *
 *****************************************************************************/

#define H3900_ASIC3_SD_CONFIG(s,x)   \
     (*((volatile s *) (H3900_ASIC3_SD_VIRT + _H3900_ASIC3_SD_CONFIG_Base + (_H3900_ASIC3_SD_CONFIG_ ## x))))

#define _H3900_ASIC3_SD_CONFIG_Base            0x0400    // Assumes 32 bit addressing

#define _H3900_ASIC3_SD_CONFIG_Command           0x04   /* R/W: Command */
#define _H3900_ASIC3_SD_CONFIG_Addr0             0x10   /* [9:31] SD Control Register Base Address */
#define _H3900_ASIC3_SD_CONFIG_Addr1             0x12   /* [9:31] SD Control Register Base Address */
#define _H3900_ASIC3_SD_CONFIG_IntPin            0x3c   /* R/O: interrupt assigned to pin */
#define _H3900_ASIC3_SD_CONFIG_ClkStop           0x40   /* Set to 0x1f to clock SD controller, 0 otherwise */
#define _H3900_ASIC3_SD_CONFIG_ClockMode         0x42   /* Control clock of SD controller */
#define _H3900_ASIC3_SD_CONFIG_SDHC_PinStatus    0x44   /* R/0: read status of SD pins */
#define _H3900_ASIC3_SD_CONFIG_SDHC_Power1       0x48   /* Power2 is at 0x49 */
#define _H3900_ASIC3_SD_CONFIG_SDHC_Power3       0x4a   /* */
#define _H3900_ASIC3_SD_CONFIG_SDHC_CardDetect   0x4c   /* */
#define _H3900_ASIC3_SD_CONFIG_SDHC_Slot         0x50   /* R/O: define support slot number */
#define _H3900_ASIC3_SD_CONFIG_SDHC_ExtGateClk1  0xF0   /* Could be used for gated clock (don't use) */
#define _H3900_ASIC3_SD_CONFIG_SDHC_ExtGateClk2  0xF1   /* Could be used for gated clock (don't use) */
#define _H3900_ASIC3_SD_CONFIG_SDHC_ExtGateClk3  0xF8   /* Bit 1: double buffer/single buffer */
 
#define H3900_ASIC3_SD_CONFIG_Command           H3900_ASIC3_SD_CONFIG( u16, Command )
#define H3900_ASIC3_SD_CONFIG_Addr0             H3900_ASIC3_SD_CONFIG( u16, Addr0 )
#define H3900_ASIC3_SD_CONFIG_Addr1             H3900_ASIC3_SD_CONFIG( u16, Addr1 )
#define H3900_ASIC3_SD_CONFIG_IntPin            H3900_ASIC3_SD_CONFIG( u8, IntPin )
#define H3900_ASIC3_SD_CONFIG_ClkStop           H3900_ASIC3_SD_CONFIG( u8, ClkStop )
#define H3900_ASIC3_SD_CONFIG_ClockMode         H3900_ASIC3_SD_CONFIG( u8, ClockMode )
#define H3900_ASIC3_SD_CONFIG_SDHC_PinStatus    H3900_ASIC3_SD_CONFIG( u16, SDHC_PinStatus )
#define H3900_ASIC3_SD_CONFIG_SDHC_Power1       H3900_ASIC3_SD_CONFIG( u16, SDHC_Power1 )
#define H3900_ASIC3_SD_CONFIG_SDHC_Power3       H3900_ASIC3_SD_CONFIG( u16, SDHC_Power3 )
#define H3900_ASIC3_SD_CONFIG_SDHC_CardDetect   H3900_ASIC3_SD_CONFIG( u16, SDHC_CardDetect )
#define H3900_ASIC3_SD_CONFIG_SDHC_Slot         H3900_ASIC3_SD_CONFIG( u16, SDHC_Slot )
#define H3900_ASIC3_SD_CONFIG_SDHC_ExtGateClk1  H3900_ASIC3_SD_CONFIG( u16, SDHC_ExtGateClk1 )
#define H3900_ASIC3_SD_CONFIG_SDHC_ExtGateClk3  H3900_ASIC3_SD_CONFIG( u16, SDHC_ExtGateClk3 )

#define SD_CONFIG_

#define SD_CONFIG_COMMAND_MAE                (1<<1)    /* Memory access enable (set to 1 to access SD Controller) */

#define SD_CONFIG_CLK_ENABLE_ALL             0x1f

#define SD_CONFIG_POWER1_PC_33V              0x0200    /* Set for 3.3 volts */
#define SD_CONFIG_POWER1_PC_OFF              0x0000    /* Turn off power */



#define _H3900_ASIC3_SD_CTRL_Base            0x1000

#define H3900_ASIC3_SD_OFFSET(s,x)   \
     (*((volatile s *) (H3900_ASIC3_SD_VIRT + _H3900_ASIC3_SD_CTRL_Base + (_H3900_ASIC3_SD_CTRL_ ## x))))

#define _H3900_ASIC3_SD_CTRL_Cmd                  0x00  /* RW */
#define _H3900_ASIC3_SD_CTRL_Arg0                 0x04
#define _H3900_ASIC3_SD_CTRL_Arg1                 0x06
#define _H3900_ASIC3_SD_CTRL_StopInternal         0x08
#define _H3900_ASIC3_SD_CTRL_TransferSectorCount  0x0a
#define _H3900_ASIC3_SD_CTRL_Response0            0x0c
#define _H3900_ASIC3_SD_CTRL_Response1            0x0e
#define _H3900_ASIC3_SD_CTRL_Response2            0x10
#define _H3900_ASIC3_SD_CTRL_Response3            0x12
#define _H3900_ASIC3_SD_CTRL_Response4            0x14
#define _H3900_ASIC3_SD_CTRL_Response5            0x16
#define _H3900_ASIC3_SD_CTRL_Response6            0x18
#define _H3900_ASIC3_SD_CTRL_Response7            0x1a
#define _H3900_ASIC3_SD_CTRL_CardStatus           0x1c
#define _H3900_ASIC3_SD_CTRL_BufferCtrl           0x1e
#define _H3900_ASIC3_SD_CTRL_IntMask0             0x20
#define _H3900_ASIC3_SD_CTRL_IntMask1             0x22
#define _H3900_ASIC3_SD_CTRL_CardClockCtrl        0x24
#define _H3900_ASIC3_SD_CTRL_MemCardXferDataLen   0x26
#define _H3900_ASIC3_SD_CTRL_MemCardOptionSetup   0x28
#define _H3900_ASIC3_SD_CTRL_ErrorStatus0         0x2c
#define _H3900_ASIC3_SD_CTRL_ErrorStatus1         0x2e
#define _H3900_ASIC3_SD_CTRL_DataPort             0x30
#define _H3900_ASIC3_SD_CTRL_TransactionCtrl      0x34
#define _H3900_ASIC3_SD_CTRL_SoftwareReset        0xe0

#define H3900_ASIC3_SD_CTRL_Cmd                  H3900_ASIC3_SD_OFFSET( u16, Cmd )   /* */
#define H3900_ASIC3_SD_CTRL_Arg0                 H3900_ASIC3_SD_OFFSET( u16, Arg0 )   /* */
#define H3900_ASIC3_SD_CTRL_Arg1                 H3900_ASIC3_SD_OFFSET( u16, Arg1 )   /* */
#define H3900_ASIC3_SD_CTRL_StopInternal         H3900_ASIC3_SD_OFFSET( u16, StopInternal )   /* */
#define H3900_ASIC3_SD_CTRL_TransferSectorCount  H3900_ASIC3_SD_OFFSET( u16, TransferSectorCount )   /* */
#define H3900_ASIC3_SD_CTRL_Response0            H3900_ASIC3_SD_OFFSET( u16, Response0 )   /* */
#define H3900_ASIC3_SD_CTRL_Response1            H3900_ASIC3_SD_OFFSET( u16, Response1 )   /* */
#define H3900_ASIC3_SD_CTRL_Response2            H3900_ASIC3_SD_OFFSET( u16, Response2 )   /* */
#define H3900_ASIC3_SD_CTRL_Response3            H3900_ASIC3_SD_OFFSET( u16, Response3 )   /* */
#define H3900_ASIC3_SD_CTRL_Response4            H3900_ASIC3_SD_OFFSET( u16, Response4 )   /* */
#define H3900_ASIC3_SD_CTRL_Response5            H3900_ASIC3_SD_OFFSET( u16, Response5 )   /* */
#define H3900_ASIC3_SD_CTRL_Response6            H3900_ASIC3_SD_OFFSET( u16, Response6 )   /* */
#define H3900_ASIC3_SD_CTRL_Response7            H3900_ASIC3_SD_OFFSET( u16, Response7 )   /* */
#define H3900_ASIC3_SD_CTRL_CardStatus           H3900_ASIC3_SD_OFFSET( u16, CardStatus )   /* */
#define H3900_ASIC3_SD_CTRL_BufferCtrl           H3900_ASIC3_SD_OFFSET( u16, BufferCtrl )   /* and error status*/
#define H3900_ASIC3_SD_CTRL_IntMask0             H3900_ASIC3_SD_OFFSET( u16, IntMask0 )   /* */
#define H3900_ASIC3_SD_CTRL_IntMask1             H3900_ASIC3_SD_OFFSET( u16, IntMask1 )   /* */
#define H3900_ASIC3_SD_CTRL_CardClockCtrl        H3900_ASIC3_SD_OFFSET( u16, CardClockCtrl )   /* */
#define H3900_ASIC3_SD_CTRL_MemCardXferDataLen   H3900_ASIC3_SD_OFFSET( u16, MemCardXferDataLen )   /* */
#define H3900_ASIC3_SD_CTRL_MemCardOptionSetup   H3900_ASIC3_SD_OFFSET( u16, MemCardOptionSetup )   /* */
#define H3900_ASIC3_SD_CTRL_ErrorStatus0         H3900_ASIC3_SD_OFFSET( u16, ErrorStatus0 )   /* */
#define H3900_ASIC3_SD_CTRL_ErrorStatus1         H3900_ASIC3_SD_OFFSET( u16, ErrorStatus1 )   /* */
#define H3900_ASIC3_SD_CTRL_DataPort             H3900_ASIC3_SD_OFFSET( u16, DataPort )   /* */
#define H3900_ASIC3_SD_CTRL_TransactionCtrl      H3900_ASIC3_SD_OFFSET( u16, TransactionCtrl )   /* */
#define H3900_ASIC3_SD_CTRL_SoftwareReset        H3900_ASIC3_SD_OFFSET( u16, SoftwareReset )   /* */

#define SD_CTRL_SOFTWARE_RESET_CLEAR            (1<<0)

#define SD_CTRL_COMMAND_INDEX(x)                   ((x)&0x3f)           /* 0=CMD0, 1=CMD1, ..., 63=CMD63 */
#define SD_CTRL_COMMAND_TYPE_CMD                   (0 << 6)
#define SD_CTRL_COMMAND_TYPE_ACMD                  (1 << 6)
#define SD_CTRL_COMMAND_TYPE_AUTHENTICATION        (2 << 6)
#define SD_CTRL_COMMAND_RESPONSE_TYPE_NORMAL       (0 << 8)
#define SD_CTRL_COMMAND_RESPONSE_TYPE_EXT_R1       (4 << 8)
#define SD_CTRL_COMMAND_RESPONSE_TYPE_EXT_R1B      (5 << 8)
#define SD_CTRL_COMMAND_RESPONSE_TYPE_EXT_R2       (6 << 8)
#define SD_CTRL_COMMAND_RESPONSE_TYPE_EXT_R3       (7 << 8)
#define SD_CTRL_COMMAND_DATA_PRESENT               (1 << 11)
#define SD_CTRL_COMMAND_TRANSFER_READ              (1 << 12)
#define SD_CTRL_COMMAND_TRANSFER_WRITE             (0 << 12)
#define SD_CTRL_COMMAND_MULTI_BLOCK                (1 << 13)
#define SD_CTRL_COMMAND_SECURITY_CMD               (1 << 14)

#define SD_CTRL_STOP_INTERNAL_ISSSUE_CMD12         (1 << 0)
#define SD_CTRL_STOP_INTERNAL_AUTO_ISSUE_CMD12     (1 << 8)

#define SD_CTRL_CARDSTATUS_RESPONSE_END            (1 << 0)
#define SD_CTRL_CARDSTATUS_RW_END                  (1 << 2)
#define SD_CTRL_CARDSTATUS_CARD_REMOVED_0          (1 << 3)
#define SD_CTRL_CARDSTATUS_CARD_INSERTED_0         (1 << 4)
#define SD_CTRL_CARDSTATUS_SIGNAL_STATE_PRESENT_0  (1 << 5)
#define SD_CTRL_CARDSTATUS_WRITE_PROTECT           (1 << 7)
#define SD_CTRL_CARDSTATUS_CARD_REMOVED_3          (1 << 8)
#define SD_CTRL_CARDSTATUS_CARD_INSERTED_3         (1 << 9)
#define SD_CTRL_CARDSTATUS_SIGNAL_STATE_PRESENT_3  (1 << 10)

#define MEM_CARD_OPTION_REQUIRED                   0x000e
#define MEM_CARD_OPTION_DATA_RESPONSE_TIMEOUT(x)   (((x)&0x0f)<<4)      /* Four bits */
#define MEM_CARD_OPTION_C2_MODULE_NOT_PRESENT      (1<<14)
#define MEM_CARD_OPTION_DATA_XFR_WIDTH_1           (1<<15)
#define MEM_CARD_OPTION_DATA_XFR_WIDTH_4           (0<<15)



#define _H3900_ASIC3_SDIO_CTRL_Base          0x1100

#define H3900_ASIC3_SDIO_OFFSET(s,x)   \
     (*((volatile s *) (H3900_ASIC3_SD_VIRT + _H3900_ASIC3_SDIO_CTRL_Base + (_H3900_ASIC3_SDIO_CTRL_ ## x))))

#define _H3900_ASIC3_SDIO_CTRL_Cmd                  0x00
#define _H3900_ASIC3_SDIO_CTRL_CardPortSel          0x02
#define _H3900_ASIC3_SDIO_CTRL_Arg0                 0x04
#define _H3900_ASIC3_SDIO_CTRL_Arg1                 0x06
#define _H3900_ASIC3_SDIO_CTRL_TransferBlockCount   0x0a
#define _H3900_ASIC3_SDIO_CTRL_Response0            0x0c
#define _H3900_ASIC3_SDIO_CTRL_Response1            0x0e
#define _H3900_ASIC3_SDIO_CTRL_Response2            0x10
#define _H3900_ASIC3_SDIO_CTRL_Response3            0x12
#define _H3900_ASIC3_SDIO_CTRL_Response4            0x14
#define _H3900_ASIC3_SDIO_CTRL_Response5            0x16
#define _H3900_ASIC3_SDIO_CTRL_Response6            0x18
#define _H3900_ASIC3_SDIO_CTRL_Response7            0x1a
#define _H3900_ASIC3_SDIO_CTRL_CardStatus           0x1c
#define _H3900_ASIC3_SDIO_CTRL_BufferCtrl           0x1e
#define _H3900_ASIC3_SDIO_CTRL_IntMask0             0x20
#define _H3900_ASIC3_SDIO_CTRL_IntMask1             0x22
#define _H3900_ASIC3_SDIO_CTRL_CardXferDataLen      0x26
#define _H3900_ASIC3_SDIO_CTRL_CardOptionSetup      0x28
#define _H3900_ASIC3_SDIO_CTRL_ErrorStatus0         0x2c
#define _H3900_ASIC3_SDIO_CTRL_ErrorStatus1         0x2e
#define _H3900_ASIC3_SDIO_CTRL_DataPort             0x30
#define _H3900_ASIC3_SDIO_CTRL_TransactionCtrl      0x34
#define _H3900_ASIC3_SDIO_CTRL_CardIntCtrl          0x36
#define _H3900_ASIC3_SDIO_CTRL_ClocknWaitCtrl       0x38
#define _H3900_ASIC3_SDIO_CTRL_HostInformation      0x3a
#define _H3900_ASIC3_SDIO_CTRL_ErrorCtrl            0x3c
#define _H3900_ASIC3_SDIO_CTRL_LEDCtrl              0x3e
#define _H3900_ASIC3_SDIO_CTRL_SoftwareReset        0xe0

#define H3900_ASIC3_SDIO_CTRL_Cmd                  H3900_ASIC3_SDIO_OFFSET( u16, Cmd )   /* */
#define H3900_ASIC3_SDIO_CTRL_CardPortSel          H3900_ASIC3_SDIO_OFFSET( u16, CardPortSel )   /* */
#define H3900_ASIC3_SDIO_CTRL_Arg0                 H3900_ASIC3_SDIO_OFFSET( u16, Arg0 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Arg1                 H3900_ASIC3_SDIO_OFFSET( u16, Arg1 )   /* */
#define H3900_ASIC3_SDIO_CTRL_TransferBlockCount   H3900_ASIC3_SDIO_OFFSET( u16, TransferBlockCount )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response0            H3900_ASIC3_SDIO_OFFSET( u16, Response0 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response1            H3900_ASIC3_SDIO_OFFSET( u16, Response1 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response2            H3900_ASIC3_SDIO_OFFSET( u16, Response2 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response3            H3900_ASIC3_SDIO_OFFSET( u16, Response3 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response4            H3900_ASIC3_SDIO_OFFSET( u16, Response4 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response5            H3900_ASIC3_SDIO_OFFSET( u16, Response5 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response6            H3900_ASIC3_SDIO_OFFSET( u16, Response6 )   /* */
#define H3900_ASIC3_SDIO_CTRL_Response7            H3900_ASIC3_SDIO_OFFSET( u16, Response7 )   /* */
#define H3900_ASIC3_SDIO_CTRL_CardStatus           H3900_ASIC3_SDIO_OFFSET( u16, CardStatus )   /* */
#define H3900_ASIC3_SDIO_CTRL_BufferCtrl           H3900_ASIC3_SDIO_OFFSET( u16, BufferCtrl )   /* and error status*/
#define H3900_ASIC3_SDIO_CTRL_IntMask0             H3900_ASIC3_SDIO_OFFSET( u16, IntMask0 )   /* */
#define H3900_ASIC3_SDIO_CTRL_IntMask1             H3900_ASIC3_SDIO_OFFSET( u16, IntMask1 )   /* */
#define H3900_ASIC3_SDIO_CTRL_CardXferDataLen      H3900_ASIC3_SDIO_OFFSET( u16, CardXferDataLen )   /* */
#define H3900_ASIC3_SDIO_CTRL_CardOptionSetup      H3900_ASIC3_SDIO_OFFSET( u16, CardOptionSetup )   /* */
#define H3900_ASIC3_SDIO_CTRL_ErrorStatus0         H3900_ASIC3_SDIO_OFFSET( u16, ErrorStatus0 )   /* */
#define H3900_ASIC3_SDIO_CTRL_ErrorStatus1         H3900_ASIC3_SDIO_OFFSET( u16, ErrorStatus1 )   /* */
#define H3900_ASIC3_SDIO_CTRL_DataPort             H3900_ASIC3_SDIO_OFFSET( u16, DataPort )   /* */
#define H3900_ASIC3_SDIO_CTRL_TransactionCtrl      H3900_ASIC3_SDIO_OFFSET( u16, TransactionCtrl )   /* */
#define H3900_ASIC3_SDIO_CTRL_CardIntCtrl          H3900_ASIC3_SDIO_OFFSET( u16, CardIntCtrl )   /* */
#define H3900_ASIC3_SDIO_CTRL_ClocknWaitCtrl       H3900_ASIC3_SDIO_OFFSET( u16, ClocknWaitCtrl )   /* */
#define H3900_ASIC3_SDIO_CTRL_HostInformation      H3900_ASIC3_SDIO_OFFSET( u16, HostInformation )   /* */
#define H3900_ASIC3_SDIO_CTRL_ErrorCtrl            H3900_ASIC3_SDIO_OFFSET( u16, ErrorCtrl )   /* */
#define H3900_ASIC3_SDIO_CTRL_LEDCtrl              H3900_ASIC3_SDIO_OFFSET( u16, LEDCtrl )   /* */
#define H3900_ASIC3_SDIO_CTRL_SoftwareReset        H3900_ASIC3_SDIO_OFFSET( u16, SoftwareReset )   /* */

#endif
