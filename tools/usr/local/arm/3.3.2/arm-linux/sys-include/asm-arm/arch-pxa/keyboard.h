/*
 *  linux/include/asm-arm/arch-pxa/keyboard.h
 *
 *  This file contains the architecture specific keyboard definitions
 */

#ifndef _PXA_KEYBOARD_H
#define _PXA_KEYBOARD_H

#include <linux/config.h>
#include <asm/mach-types.h>
#include <asm/hardware.h>

extern struct kbd_ops_struct *kbd_ops;

extern void h3600_kbd_init_hw(void);

#define kbd_disable_irq()	do { } while(0);
#define kbd_enable_irq()	do { } while(0);

extern int sa1111_kbd_init_hw(void);

static inline void kbd_init_hw(void)
{
	if (machine_is_lubbock())
		sa1111_kbd_init_hw();
#ifdef CONFIG_IPAQ_HANDHELD
	if (machine_is_ipaq())
		h3600_kbd_init_hw();
#endif
#ifdef CONFIG_ARCH_AXIM
	if (machine_is_axim())
		h3600_kbd_init_hw(); // will have to move it to axim_key.c
#endif

}


#endif  /* _PXA_KEYBOARD_H */

