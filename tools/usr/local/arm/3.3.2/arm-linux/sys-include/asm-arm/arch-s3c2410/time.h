/*
 *  linux/include/asm-arm/arch-s3c2410/time.h
 *
 *  Copyright (C) SAMSUNG ELECTRONICS 
 *                      SW.LEE <hitchcar@sec.samsung.com>
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
#include <asm/system.h>
#include <asm/leds.h>

extern unsigned long (*gettimeoffset)(void);

/*
 * If rTCNTB4 can be changed
 * a few of routine must be done so.
 */
static unsigned long  NowTCNTB4;

/***
 * Returns microsecond  since last clock interrupt.  Note that interrupts
 * will have been disabled by do_gettimeoffset()
 * IRQs are disabled before entering here from do_gettimeofday() 
 */
static unsigned long s3c2410_gettimeoffset (void)
{
        unsigned long elapsed,usec;
	/*
	 *!!!! VERY IMPORTANT 
	 * If rTCNTB4 would changed ,this code must be changed 
         *
	 */

	/*
	 * tick is microsecond unit
	 * long tick = (1000000 + HZ/2) / HZ;	 timer interrupt period 
	 * kernel/timer.c 
	 */

	elapsed = NowTCNTB4 - rTCNTO4;
	
	/*
	 *  A SIMPLE RATIO 
	 * (elapsed / rTCNTB4) =  ( usec / tick )
	 */
 
	/*
	 * IF YOU WANT TO  USE LATCH 
         * SEE arch-s3c2410/timex.h
         * it gave me troubles  
         */

	usec = (elapsed*tick)/NowTCNTB4 ;
        return usec;
}


/*
 * IRQ handler for the timer
 */
static void s3c2410_timer_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
	long flags;

	do_leds();
	save_flags_cli( flags );
	do_timer(regs);
	restore_flags( flags );     
	do_set_rtc();
	do_profile(regs);
	
}

/*
 * Set up timer interrupt, and return the current time in seconds.
 */

void pwm_timer_update(void)
{
        rTCFG0 = (rTCFG0& ~(0xff<<8))|(SYS_TIMER234_PRESCALER<<8); 
	rTCFG1 = (rTCFG1& ~(0xf<<16))|(SYS_TIMER4_MUX <<16);
        NowTCNTB4  = (RESCHED_PERIOD*PCLK)/
	  ((SYS_TIMER234_PRESCALER +1)*(SYS_TIMER4_DIVIDER)*1000);
	rTCNTB4 = NowTCNTB4;
        rTCON = (rTCON& ~(7<<20))|(6<<20);
	/* interval mode(auto reload), update TCNTB4, stop */
	rTCON = (rTCON& ~(7<<20))|(5<<20);
	/* interval mode, no operation, start for Timer 4 */
}

static inline void setup_timer (void)
{

	gettimeoffset = s3c2410_gettimeoffset;
/*  	set_rtc = s3c2410_set_rtc; */
/*  	xtime.tv_sec = s3c2410_get_rtc_time(); */
	timer_irq.handler = s3c2410_timer_interrupt;

/*
        rTCFG0 = (rTCFG0& ~(0xff<<8))|(SYS_TIMER234_PRESCALER<<8); 
	rTCFG1 = (rTCFG1& ~(0xf<<16))|(SYS_TIMER4_MUX <<16);
*/
	/*  be cautious, TCNTB4 be below 2^16=65535 [15:0] */
/*        NowTCNTB4  = (RESCHED_PERIOD*PCLK)/
	  ((SYS_TIMER234_PRESCALER +1)*(SYS_TIMER4_DIVIDER)*1000);
*/
	/* rTCNTB4  =  X second * (frequency/second ) */
//	rTCNTB4 = NowTCNTB4;

 //       rTCON = (rTCON& ~(7<<20))|(6<<20);
	/* interval mode(auto reload), update TCNTB4, stop */

	setup_arm_irq(IRQ_TIMER4, &timer_irq);
	pwm_timer_update();
//	rTCON = (rTCON& ~(7<<20))|(5<<20);
	/* interval mode, no operation, start for Timer 4 */
}

