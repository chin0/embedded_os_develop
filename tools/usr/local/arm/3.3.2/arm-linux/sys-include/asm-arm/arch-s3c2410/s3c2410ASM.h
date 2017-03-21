/*
 *  linux/include/asm-arm/arch-s3c2410/s3c2410.h
 *
 *  Copyright (C) 2002 SAMSUNG ELECTORNICS 
 *                         SW.LEE (hitchcar@sec.samsung.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __S3C2410_ASM_H
#define __S3C2410_ASM_H
#if LANGUAGE == Assembly 

// Memory control 
#define BWSCON    ((VA_MEM_CTR_BASE+0x00)) //Bus width & wait status
#define BANKCON0  ((VA_MEM_CTR_BASE+0x04)) //Boot ROM control
#define BANKCON1  ((VA_MEM_CTR_BASE+0x08)) //BANK1 control
#define BANKCON2  ((VA_MEM_CTR_BASE+0x0c)) //BANK2 cControl
#define BANKCON3  ((VA_MEM_CTR_BASE+0x10)) //BANK3 control
#define BANKCON4  ((VA_MEM_CTR_BASE+0x14)) //BANK4 control
#define BANKCON5  ((VA_MEM_CTR_BASE+0x18)) //BANK5 control
#define BANKCON6  ((VA_MEM_CTR_BASE+0x1c)) //BANK6 control
#define BANKCON7  ((VA_MEM_CTR_BASE+0x20)) //BANK7 control
#define REFRESH   ((VA_MEM_CTR_BASE+0x24)) //DRAM/SDRAM refresh
#define BANKSIZE  ((VA_MEM_CTR_BASE+0x28)) //Flexible Bank Size
#define MRSRB6    ((VA_MEM_CTR_BASE+0x2c)) //Mode register set for SDRAM
#define MRSRB7    ((VA_MEM_CTR_BASE+0x30)) //Mode register set for SDRAM

// INTERRUPT
#define SRCPND     ((VA_INT_BASE+0x00)) //Interrupt request status
#define INTMOD     ((VA_INT_BASE+0x04)) //Interrupt mode control
#define INTMSK     ((VA_INT_BASE+0x08)) //Interrupt mask control
#define PRIORITY   ((VA_INT_BASE+0x0a)) //IRQ priority control
#define INTPND     ((VA_INT_BASE+0x10)) //Interrupt request status
#define INTOFFSET  ((VA_INT_BASE+0x14)) //Interruot request source offset
#define SUBSRCPND  ((VA_INT_BASE+0x18)) //Sub source pending
#define INTSUBMSK  ((VA_INT_BASE+0x1c)) //Interrupt sub mask

// CLOCK & POWER MANAGEMENT
#define LOCKTIME   ((VA_CKPO_BASE+0x00))//PLL lock time counter
#define MPLLCON    ((VA_CKPO_BASE+0x04)) //MPLL Control
#define UPLLCON    ((VA_CKPO_BASE+0x08)) //UPLL Control
#define CLKCON     ((VA_CKPO_BASE+0x0c)) //Clock generator control
#define CLKSLOW    ((VA_CKPO_BASE+0x10)) //Slow clock control
#define CLKDIVN    ((VA_CKPO_BASE+0x14)) //Clock divider control


// UART
#define ULCON0     ((VA_UART_BASE+0x00)) //UART 0 Line control
#define UCON0      ((VA_UART_BASE+0x04)) //UART 0 Control
#define UFCON0     ((VA_UART_BASE+0x08)) //UART 0 FIFO control
#define UMCON0     ((VA_UART_BASE+0x0c)) //UART 0 Modem control
#define UTRSTAT0   ((VA_UART_BASE+0x10)) //UART 0 Tx/Rx status
#define UERSTAT0   ((VA_UART_BASE+0x14)) //UART 0 Rx error status
#define UFSTAT0    ((VA_UART_BASE+0x18)) //UART 0 FIFO status
#define UMSTAT0    ((VA_UART_BASE+0x1c)) //UART 0 Modem status
#define UBRDIV0    ((VA_UART_BASE+0x28)) //UART 0 Baud rate divisor

#define ULCON1     ((VA_UART_BASE+0x4000)) //UART 1 Line control
#define UCON1      ((VA_UART_BASE+0x4004)) //UART 1 Control
#define UFCON1     ((VA_UART_BASE+0x4008)) //UART 1 FIFO control
#define UMCON1     ((VA_UART_BASE+0x400c)) //UART 1 Modem control
#define UTRSTAT1   ((VA_UART_BASE+0x4010)) //UART 1 Tx/Rx status
#define UERSTAT1   ((VA_UART_BASE+0x4014)) //UART 1 Rx error status
#define UFSTAT1    ((VA_UART_BASE+0x4018)) //UART 1 FIFO status
#define UMSTAT1    ((VA_UART_BASE+0x401c)) //UART 1 Modem status
#define UBRDIV1    ((VA_UART_BASE+0x4028)) //UART 1 Baud rate divisor

#define ULCON2     ((VA_UART_BASE+0x8000)) //UART 2 Line control
#define UCON2      ((VA_UART_BASE+0x8004)) //UART 2 Control
#define UFCON2     ((VA_UART_BASE+0x8008)) //UART 2 FIFO control
#define UMCON2     ((VA_UART_BASE+0x800c)) //UART 2 Modem control
#define UTRSTAT2   ((VA_UART_BASE+0x8010)) //UART 2 Tx/Rx status
#define UERSTAT2   ((VA_UART_BASE+0x8014)) //UART 2 Rx error status
#define UFSTAT2    ((VA_UART_BASE+0x8018)) //UART 2 FIFO status
#define UMSTAT2    ((VA_UART_BASE+0x801c)) //UART 2 Modem status
#define UBRDIV2    ((VA_UART_BASE+0x8028)) //UART 2 Baud rate divisor

#define UTXH0       (VA_UART_BASE+0x20)    //Byte_access address by DMA
#define URXH0       (VA_UART_BASE+0x24)
#define UTXH1       (VA_UART_BASE+0x4020)
#define URXH1       (VA_UART_BASE+0x4024)
#define UTXH2       (VA_UART_BASE+0x8020)
#define URXH2       (VA_UART_BASE+0x8024)


// PWM TIMER
#define TCFG0  ((VA_TIMER_BASE+0x00)) //Timer 0 configuration
#define TCFG1  ((VA_TIMER_BASE+0x04)) //Timer 1 configuration
#define TCON   ((VA_TIMER_BASE+0x08)) //Timer control
#define TCNTB0 ((VA_TIMER_BASE+0x0c)) //Timer count buffer 0
#define TCMPB0 ((VA_TIMER_BASE+0x10)) //Timer compare buffer 0
#define TCNTO0 ((VA_TIMER_BASE+0x14)) //Timer count observation 0
#define TCNTB1 ((VA_TIMER_BASE+0x18)) //Timer count buffer 1
#define TCMPB1 ((VA_TIMER_BASE+0x1c)) //Timer compare buffer 1
#define TCNTO1 ((VA_TIMER_BASE+0x20)) //Timer count observation 1
#define TCNTB2 ((VA_TIMER_BASE+0x24)) //Timer count buffer 2
#define TCMPB2 ((VA_TIMER_BASE+0x28)) //Timer compare buffer 2
#define TCNTO2 ((VA_TIMER_BASE+0x2c)) //Timer count observation 2
#define TCNTB3 ((VA_TIMER_BASE+0x30)) //Timer count buffer 3
#define TCMPB3 ((VA_TIMER_BASE+0x34)) //Timer compare buffer 3
#define TCNTO3 ((VA_TIMER_BASE+0x38)) //Timer count observation 3
#define TCNTB4 ((VA_TIMER_BASE+0x3c)) //Timer count buffer 4
#define TCNTO4 ((VA_TIMER_BASE+0x40)) //Timer count observation 4

// WATCH DOG TIMER
#define WTCON   ((VA_WD_BASE+0x00)) //Watch-dog timer mode
#define WTDAT   ((VA_WD_BASE+0x04)) //Watch-dog timer data
#define WTCNT   ((VA_WD_BASE+0x08)) //Eatch-dog timer count


// I/O PORT 
#define GPACON    ((VA_IO_PORT_BASE+0x00)) //Port A control
#define GPADAT    ((VA_IO_PORT_BASE+0x04)) //Port A data
                        
#define GPBCON    ((VA_IO_PORT_BASE+0x10)) //Port B control
#define GPBDAT    ((VA_IO_PORT_BASE+0x14)) //Port B data
#define GPBUP     ((VA_IO_PORT_BASE+0x18)) //Pull-up control B
                        
#define GPCCON    ((VA_IO_PORT_BASE+0x20)) //Port C control
#define GPCDAT    ((VA_IO_PORT_BASE+0x24)) //Port C data
#define GPCUP     ((VA_IO_PORT_BASE+0x28)) //Pull-up control C
                        
#define GPDCON    ((VA_IO_PORT_BASE+0x30)) //Port D control
#define GPDDAT    ((VA_IO_PORT_BASE+0x34)) //Port D data
#define GPDUP     ((VA_IO_PORT_BASE+0x38)) //Pull-up control D
                        
#define GPECON    ((VA_IO_PORT_BASE+0x40)) //Port E control
#define GPEDAT    ((VA_IO_PORT_BASE+0x44)) //Port E data
#define GPEUP     ((VA_IO_PORT_BASE+0x48)) //Pull-up control E
                        
#define GPFCON    ((VA_IO_PORT_BASE+0x50)) //Port F control
#define GPFDAT    ((VA_IO_PORT_BASE+0x54)) //Port F data
#define GPFUP     ((VA_IO_PORT_BASE+0x58)) //Pull-up control F
                        
#define GPGCON    ((VA_IO_PORT_BASE+0x60)) //Port G control
#define GPGDAT    ((VA_IO_PORT_BASE+0x64)) //Port G data
#define GPGUP     ((VA_IO_PORT_BASE+0x68)) //Pull-up control G
                        
#define GPHCON    ((VA_IO_PORT_BASE+0x70)) //Port H control
#define GPHDAT    ((VA_IO_PORT_BASE+0x74)) //Port H data
#define GPHUP     ((VA_IO_PORT_BASE+0x78)) //Pull-up control H
                        
#define MISCCR    ((VA_IO_PORT_BASE+0x80)) //Miscellaneous control
#define DCLKCON   ((VA_IO_PORT_BASE+0x84)) //DCLK0/1 control
#define EXTINT0   ((VA_IO_PORT_BASE+0x88)) //External interrupt control register 0
#define EXTINT1   ((VA_IO_PORT_BASE+0x8c)) //External interrupt control register 1
#define EXTINT2   ((VA_IO_PORT_BASE+0x90)) //External interrupt control register 2
#define EINTFLT0  ((VA_IO_PORT_BASE+0x94)) //Reserved
#define EINTFLT1  ((VA_IO_PORT_BASE+0x98)) //Reserved
#define EINTFLT2  ((VA_IO_PORT_BASE+0x9c)) //External interrupt filter control register 2
#define EINTFLT3  ((VA_IO_PORT_BASE+0xa0)) //External interrupt filter control register 3
#define EINTMSK  ((VA_IO_PORT_BASE+0xa4)) //External interrupt mask
#define EINTPND  ((VA_IO_PORT_BASE+0xa8)) //External interrupt pending
#define GSTATUS0  ((VA_IO_PORT_BASE+0xac)) //External pin status
#define GSTATUS1  ((VA_IO_PORT_BASE+0xb0)) //Chip ID(0x32410000)
#define GSTATUS2  ((VA_IO_PORT_BASE+0xb4)) //Reset type
#define GSTATUS3  ((VA_IO_PORT_BASE+0xb8)) //Saved data0(32-bit) before entering POWER_OFF mode 
#define GSTATUS4  ((VA_IO_PORT_BASE+0xbc)) //Saved data0(32-bit) before entering POWER_OFF mode 



#endif /* LANGUAGE == Assembly */
#endif /* __S3C2410_ASM_H */
