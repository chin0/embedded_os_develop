/*
 *  linux/include/asm-arm/arch-s3c2410/timex.h
 *
 *  Copyright (C) 2002 SAMSUNG ELECTRONICS 
 *                           SW.LEE <hitchcar@sec.samsung.com>
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

#define CLOCK_TICK_RATE	 (PCLK/((SYS_TIMER234_PRESCALER +1)*(SYS_TIMER4_DIVIDER)))

/* TIP by SW.LEE
 *
 *  LATCH  == rTCNTB4 = (RESCHED_PERIOD/1000)*
 *	  (PCLK/((SYS_TIMER234_PRESCALER +1)*(SYS_TIMER4_DIVIDER))) 
 *  LATCH ==  ((CLOCK_TICK_RATE + HZ/2) / HZ)	
 *
 */
