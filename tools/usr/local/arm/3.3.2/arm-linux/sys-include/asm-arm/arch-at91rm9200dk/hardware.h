/*
 *  linux/include/asm-arm/arch-at91rm9200dk/hardware.h
 *
 *  This file contains the hardware definitions of the At91rm9200dk.
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
#ifndef __ASM_ARCH_HARDWARE_H
#define __ASM_ARCH_HARDWARE_H

#include <asm/sizes.h>
#include <asm/arch/platform.h>

/* ARM asynchronous clock */
#define AT91C_MASTER_CLK	60000000

#ifndef __ASSEMBLY__
#include <asm/arch/AT91RM9200.h>
#define AT91C_VA_BASE_SYS	((AT91PS_SYS) AT91C_BASE_SYS) // (SYS) Virtual Base Address

#else
#include <asm/arch/AT91RM9200_inc.h>
#define AT91C_VA_BASE_SYS	(AT91C_BASE_SYS) // (SYS) Virtual Base Address
#define AT91C_VA_BASE_RTC	(AT91C_VA_BASE_SYS + 0xE00) // (RTC)  Virtual Base Address
#define AT91C_VA_BASE_ST	(AT91C_VA_BASE_SYS + 0xD00) // (ST)   Virtual Base Address
#define AT91C_VA_BASE_DBGU	(AT91C_VA_BASE_SYS + 0x200) // (DBGU) Virtual Base Address
#define AT91C_VA_BASE_AIC	(AT91C_VA_BASE_SYS + 0x000) // (AIC)  Virtual Base Address

#endif // __ASSEMBLY

/* macro to get at IO space when running virtually */
#define IO_ADDRESS(x)		(x)

#endif // __ASM_ARCH_HARDWARE_H
