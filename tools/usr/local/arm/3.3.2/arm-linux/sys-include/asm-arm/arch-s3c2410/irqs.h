/*
 *  linux/include/asm-arm/arch-s3c2410/irqs.h
 *
 *  Copyright (C) 2002 SAMSUNG ELECTRONIS  
 *                        SW.LEE (hitchcar@sec.samsung.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __S3C2410_irqs_h
#define __S3C2410_irqs_h                        1

/*
 * If You want to change this value 
 * Have a good look at s3c2410.h
 */ 

#define BIT_SHIFT_EINT0      (0)
#define BIT_SHIFT_EINT1      (1)
#define BIT_SHIFT_EINT2      (2)
#define BIT_SHIFT_EINT3      (3)
#define BIT_SHIFT_EINT4_7    (4)
#define BIT_SHIFT_EINT8_23   (5)
#define BIT_SHIFT_NOTUSED6   (6)
#define BIT_SHIFT_BAT_FLT    (7)
#define BIT_SHIFT_TICK       (8)
#define BIT_SHIFT_WDT        (9)
#define BIT_SHIFT_TIMER0     (10)
#define BIT_SHIFT_TIMER1     (11)
#define BIT_SHIFT_TIMER2     (12)
#define BIT_SHIFT_TIMER3     (13)
#define BIT_SHIFT_TIMER4     (14)
#define BIT_SHIFT_UART2      (15)
#define BIT_SHIFT_LCD        (16)
#define BIT_SHIFT_DMA0       (17)
#define BIT_SHIFT_DMA1       (18)
#define BIT_SHIFT_DMA2       (19)
#define BIT_SHIFT_DMA3       (20)
#define BIT_SHIFT_SDI        (21)
#define BIT_SHIFT_SPI0       (22)
#define BIT_SHIFT_UART1      (23)
#define BIT_SHIFT_NOTUSED24  (24)
#define BIT_SHIFT_USBD       (25)
#define BIT_SHIFT_USBH       (26)
#define BIT_SHIFT_IIC        (27)
#define BIT_SHIFT_UART0      (28)
#define BIT_SHIFT_SPI1       (29)
#define BIT_SHIFT_RTC        (30)
#define BIT_SHIFT_ADC        (31)

#define IRQ_EINT0       BIT_SHIFT_EINT0
#define IRQ_EINT1       BIT_SHIFT_EINT1
#define IRQ_EINT2       BIT_SHIFT_EINT2
#define IRQ_EINT3       BIT_SHIFT_EINT3
#define IRQ_EINT4_7     BIT_SHIFT_EINT4_7
#define IRQ_EINT8_23    BIT_SHIFT_EINT8_23
#define IRQ_NOTUSED6    BIT_SHIFT_NOTUSED6
#define IRQ_BAT_FLT     BIT_SHIFT_BAT_FLT
#define IRQ_TICK        BIT_SHIFT_TICK
#define IRQ_WDT         BIT_SHIFT_WDT
#define IRQ_TIMER0      BIT_SHIFT_TIMER0
#define IRQ_TIMER1      BIT_SHIFT_TIMER1
#define IRQ_TIMER2      BIT_SHIFT_TIMER2
#define IRQ_TIMER3      BIT_SHIFT_TIMER3
#define IRQ_TIMER4      BIT_SHIFT_TIMER4
#define IRQ_UART2       BIT_SHIFT_UART2
#define IRQ_LCD         BIT_SHIFT_LCD
#define IRQ_DMA0        BIT_SHIFT_DMA0
#define IRQ_DMA1        BIT_SHIFT_DMA1
#define IRQ_DMA2        BIT_SHIFT_DMA2
#define IRQ_DMA3        BIT_SHIFT_DMA3
#define IRQ_SDI         BIT_SHIFT_SDI
#define IRQ_SPI0        BIT_SHIFT_SPI0
#define IRQ_UART1       BIT_SHIFT_UART1
#define IRQ_NOTUSED24   BIT_SHIFT_NOTUSED24
#define IRQ_USBD        BIT_SHIFT_USBD
#define IRQ_USBH        BIT_SHIFT_USBH
#define IRQ_IIC         BIT_SHIFT_IIC
#define IRQ_UART0       BIT_SHIFT_UART0
#define IRQ_SPI1        BIT_SHIFT_SPI1
#define IRQ_RTC         BIT_SHIFT_RTC
#define IRQ_ADC         BIT_SHIFT_ADC

#define NoIntBase        32  /* Normal Interrupt Base */
/****************   This External IRQ **********/
#define IRQ_EINT4       (NoIntBase+0)
#define IRQ_EINT5       (NoIntBase+1)
#define IRQ_EINT6       (NoIntBase+2)
#define IRQ_EINT7       (NoIntBase+3)
#define IRQ_EINT8       (NoIntBase+4)
#define IRQ_EINT9       (NoIntBase+5)
#define IRQ_EINT10      (NoIntBase+6)
#define IRQ_EINT11      (NoIntBase+7)
#define IRQ_EINT12      (NoIntBase+8)
#define IRQ_EINT13      (NoIntBase+9) 
#define IRQ_EINT14      (NoIntBase+10)
#define IRQ_EINT15      (NoIntBase+11)
#define IRQ_EINT16      (NoIntBase+12) 
#define IRQ_EINT17      (NoIntBase+13) 
#define IRQ_EINT18      (NoIntBase+14) /* SD Detect Interrupt */
#define IRQ_EINT19      (NoIntBase+15) 
#define IRQ_EINT20      (NoIntBase+16) 
#define IRQ_EINT21      (NoIntBase+17) 
#define IRQ_EINT22      (NoIntBase+18) 
#define IRQ_EINT23      (NoIntBase+19)
/*************************************************/

#define IRQ_RXD0        (NoIntBase+20)
#define IRQ_TXD0        (NoIntBase+21)
#define IRQ_ERR0        (NoIntBase+22)
#define IRQ_RXD1        (NoIntBase+23)
#define IRQ_TXD1        (NoIntBase+24) 
#define IRQ_ERR1        (NoIntBase+25)
#define IRQ_RXD2        (NoIntBase+26)
#define IRQ_TXD2        (NoIntBase+27)
#define IRQ_ERR2        (NoIntBase+28) 
#define IRQ_TC          (NoIntBase+29)  
#define IRQ_ADCDone     (NoIntBase+30)  /* 62 */
#define IRQ_DUMMY       (NoIntBase+31)
#define NR_IRQS         ((NoIntBase+30)+1)

                    /* Speed UP  */
#define OS_TIMER        IRQ_TIMER4
                    /* Used in irq.c */


#endif /* End of __irqs_h */
