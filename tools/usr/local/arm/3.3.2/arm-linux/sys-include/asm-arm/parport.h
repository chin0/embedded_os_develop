/*
 *  linux/include/asm-arm/parport.h: ARM-specific parport initialisation
 *
 *  Copyright (C) 1999, 2000  Tim Waugh <tim@cyberelk.demon.co.uk>
 *
 * This file should only be included by drivers/parport/parport_pc.c.
 */

#ifndef __ASMARM_PARPORT_H
#define __ASMARM_PARPORT_H

static int __devinit parport_pc_find_isa_ports (int autoirq, int autodma);
static int __devinit parport_pc_find_nonpci_ports (int autoirq, int autodma)
{
#ifdef CONFIG_ISA
	return parport_pc_find_isa_ports (autoirq, autodma);
#else
        return 1;
#endif
}

#endif /* !(_ASMARM_PARPORT_H) */
