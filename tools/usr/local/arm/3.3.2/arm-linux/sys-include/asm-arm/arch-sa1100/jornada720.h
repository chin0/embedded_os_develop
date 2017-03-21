/*
 * linux/include/asm-arm/arch-sa1100/jornada720.h
 *
 * Created 2000/11/29 by John Ankcorn <jca@lcs.mit.edu>
 *
 * This file contains the hardware specific definitions for HP Jornada 720
 *
 */

#ifndef __ASM_ARCH_HARDWARE_H
#error "include <asm/hardware.h> instead"
#endif

#define JORNADA720_SA1111_BASE		(0x40000000)

#define GPIO_JORNADA720_KEYBOARD	GPIO_GPIO(0)
#define GPIO_JORNADA720_MOUSE		GPIO_GPIO(9)

#define GPIO_JORNADA720_KEYBOARD_IRQ	IRQ_GPIO0
#define GPIO_JORNADA720_MOUSE_IRQ		IRQ_GPIO9

#define JORNADA720_SA1111_GPIO		IRQ_GPIO1	/* The interrupt for the SA1111 */

/* Epson 1356 LCD controller parameters */
#define REGISTER_OFFSET	((unsigned char *) 0xf0000000) /* SED1356 registers */
#define DISP_MEM_OFFSET	((unsigned char *) 0xf1000000) /* display buffer */
#define DISP_MEM_OFFSET_PHYS ((unsigned char *)0x48200000) /* display buffer */
#define ALLOCATED_FB_MEM_SIZE 0x80000 /* display memory size (512kb) */

#define MAX_BPP		16
#define MAX_XRES	640
#define MAX_YRES	240
#define MIN_XRES	64
#define MIN_YRES	64

#ifndef __ASSEMBLY__

void jornada720_mcu_init(void);
void jornada_contrast(int arg_contrast);
int jornada_brightness(int arg_brightness);
void jornada720_battery(void);
int jornada720_getkey(unsigned char *data, int size);
int jornada720_gettouch(int *arg_x, int *arg_y);
#endif
