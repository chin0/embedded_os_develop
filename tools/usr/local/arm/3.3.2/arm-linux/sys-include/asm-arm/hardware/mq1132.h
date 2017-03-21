/*
 * linux/include/asm-arm/hardware/mediaq.h
 *
 * Copyright (C) 2003
 *
 * This file contains definitions for the MediaQ.
 * (Structure and naming borrowed from SA-1101.h, by Peter Danielsson.)
 *
 * 
 */

#ifndef _ASM_ARCH_MEDIAQ
#define _ASM_ARCH_MEDIAQ

#include <asm/arch/bitfield.h>

extern unsigned long *mq1132_map;

#define MEDIAQ_BASE		0x14040000
#define _MEDIAQ(x)		(*(mq1132_map+(x/4)))

#define CC00R			_MEDIAQ(0x000)
#define CC01R			_MEDIAQ(0x004)
#define CC02R			_MEDIAQ(0x008)
#define CC03R			_MEDIAQ(0x00C)
#define IN00R			_MEDIAQ(0x100)
#define IN01R			_MEDIAQ(0x104)
#define IN01R_GPIO2		(1<<7)

#define IN02R			_MEDIAQ(0x108)
#define SP08R			_MEDIAQ(0x320)


#endif  /* _ASM_ARCH_MEDIAQ */
