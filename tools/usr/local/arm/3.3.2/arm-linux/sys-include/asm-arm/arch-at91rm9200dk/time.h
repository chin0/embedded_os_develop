/*
 *  linux/include/asm-arm/arch-at91rm9200dk/time.h
 *
 *  Copyright (C) 2002 ATMEL Rousset
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

extern unsigned long (*gettimeoffset)(void);

/*
 * Returns number of us since last clock interrupt.  Note that interrupts
 * will have been disabled by do_gettimeoffset()
 */
static unsigned long at91rm9200dk_gettimeoffset(void)
{
	/*
	 * Get the current number of ticks, reading the current real time register
	 * reset by the irq handler
	 */
	unsigned long timeoffset = (AT91C_VA_BASE_SYS->ST_CRTR * 1000 * 1000) / AT91C_SLOWCLOCK;

	return (timeoffset < (AT91C_SLOWCLOCK / HZ)) ? timeoffset : timeoffset - AT91C_SLOWCLOCK;
}

/*
 * IRQ handler for the timer
 */
static void at91rm9200dk_timer_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
	volatile int status;
	AT91PS_SYS pSys = (AT91PS_SYS)AT91C_VA_BASE_SYS;
	status = pSys->ST_SR;

	//Reset the current real time register
	pSys->ST_RTMR = 1;

	do_timer(regs);
	do_profile(regs);
}

/*
 * Set up timer interrupt, and return the current time in seconds.
 */
static inline void setup_timer(void)
{
	volatile int status;
	AT91PS_SYS pSys = (AT91PS_SYS)AT91C_VA_BASE_SYS;

	pSys->ST_IDR = AT91C_ST_PITS;			// Interrupt disable Register
	pSys->ST_PIMR = AT91C_SLOWCLOCK / HZ;   	// Period Interval Mode Register == timer interval = 1/HZ= 10ms

	status = pSys->ST_SR;

	pSys->ST_RTMR = 1;

	/*
	 * Make irqs happen for the system timer
	 */
	timer_irq.handler =  at91rm9200dk_timer_interrupt;
	timer_irq.flags = SA_SHIRQ;
	setup_arm_irq( AT91C_ID_SYS , &timer_irq);    // irq number for system timer is AT91C_ID_SYS
	gettimeoffset = at91rm9200dk_gettimeoffset;

	pSys->ST_IER =  AT91C_ST_PITS;                // Enable periodic interval interupt Register
}
