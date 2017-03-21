/*
 *
 * Definitions for H3600 Handheld Computer
 *
 * Copyright 2000 Compaq Computer Corporation.
 *
 * Use consistent with the GNU GPL is permitted,
 * provided that this copyright notice is
 * preserved in its entirety in all copies and derived works.
 *
 * COMPAQ COMPUTER CORPORATION MAKES NO WARRANTIES, EXPRESSED OR IMPLIED,
 * AS TO THE USEFULNESS OR CORRECTNESS OF THIS CODE OR ITS
 * FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 * Author: Jamey Hicks.
 *
 * History:
 *
 * 2001-10-??   Andrew Christian   Added support for iPAQ H3800
 *
 */

#ifndef _INCLUDE_H3600_H_ 
#define _INCLUDE_H3600_H_

#include <asm/ptrace.h>

/* generalized support for HP iPAQ Handheld Computers */
#define machine_is_ipaq() (machine_is_h3100() || machine_is_h3600() || machine_is_h3800() || machine_is_h3900() || machine_is_h5400() || machine_is_h1900() || machine_is_h2200())

#define machine_has_rosella() (machine_is_h3800() || machine_is_h3900())

/* Physical memory regions corresponding to chip selects */
#ifdef CONFIG_ARCH_SA1100
#define H3600_EGPIO_PHYS     0x49000000
#define H3600_BANK_2_PHYS    0x10000000
#define H3600_BANK_4_PHYS    0x40000000
#else /* pxa */
#define H3600_BANK_2_PHYS    0x08000000
#define H3600_BANK_4_PHYS    0x10000000
#define H3600_BANK_5_PHYS    0x14000000
#define H3900_ASIC3_SD_PHYS  0x14000000
#define H3900_ASIC3_PHYS     0x14800000

#define H1900_ASIC3_PHYS     0x0C000000

#define H5400_ASIC_PHYS      0x14000000 /* CS#5 + 0x00000000 */
#endif

/* Virtual memory regions corresponding to chip selects 2 & 4 (used on sleeves) */
#ifdef CONFIG_ARCH_SA1100
#define H3600_EGPIO_VIRT     0xf0000000
#define H3600_BANK_2_VIRT    0xf1000000
#define H3600_BANK_4_VIRT    0xf3800000
#define H3800_ASIC2_VIRT     0xf0000000 /* CS#5 + 0x01000000, same as EGPIO */
#else /* pxa */
#define H3600_BANK_2_VIRT    0xf0000000
#define H3600_BANK_4_VIRT    0xf2800000
#define H3600_BANK_5_VIRT    0xf3000000
#define H3900_ASIC3_SD_VIRT  0xf3000000 /* CS#5 + 0x00000000 */
#define H3900_ASIC3_VIRT     0xf3800000 /* CS#5 + 0x00800000 */
#define H5400_ASIC_VIRT      0xf3000000 /* CS#5 + 0x00000000 */
#define H3800_ASIC2_VIRT     0xf4000000 /* CS#5 + 0x01000000 */
#endif

/* 
   Machine-independent GPIO definitions 
   --- these are common across all current iPAQ platforms 
*/

#ifdef CONFIG_ARCH_SA1100

#define GPIO_H3600_NPOWER_BUTTON	GPIO_GPIO (0)   /* Also known as the "off button"  */

#define GPIO_H3600_PCMCIA_CD1		GPIO_GPIO (10)
#define GPIO_H3600_PCMCIA_IRQ1		GPIO_GPIO (11)

/* UDA1341 L3 Interface */
#define GPIO_H3600_L3_DATA		GPIO_GPIO (14)
#define GPIO_H3600_L3_MODE		GPIO_GPIO (15)
#define GPIO_H3600_L3_CLOCK		GPIO_GPIO (16)

#define GPIO_H3600_PCMCIA_CD0		GPIO_GPIO (17)
#define GPIO_H3600_SYS_CLK		GPIO_GPIO (19)
#define GPIO_H3600_PCMCIA_IRQ0		GPIO_GPIO (21)

#define GPIO_H3600_COM_DCD		GPIO_GPIO (23)
#define GPIO_H3600_OPT_IRQ		GPIO_GPIO (24)
#define GPIO_H3600_COM_CTS		GPIO_GPIO (25)
#define GPIO_H3600_COM_RTS		GPIO_GPIO (26)

#define IRQ_GPIO_H3600_NPOWER_BUTTON    IRQ_GPIO0
#define IRQ_GPIO_H3600_PCMCIA_CD1	IRQ_GPIO10
#define IRQ_GPIO_H3600_PCMCIA_IRQ1	IRQ_GPIO11
#define IRQ_GPIO_H3600_PCMCIA_CD0	IRQ_GPIO17
#define IRQ_GPIO_H3600_PCMCIA_IRQ0	IRQ_GPIO21
#define IRQ_GPIO_H3600_COM_DCD          IRQ_GPIO23
#define IRQ_GPIO_H3600_OPT_IRQ		IRQ_GPIO24
#define IRQ_GPIO_H3600_COM_CTS          IRQ_GPIO25

#endif

#ifndef __ASSEMBLY__

enum led_color {
	BLUE_LED,
	GREEN_LED,
	YELLOW_LED,
	RED_LED
};

#define ipaq_led_on(color)  \
        ipaq_set_led(color, 4, 4)

#define ipaq_led_off(color)  \
        ipaq_set_led(color, 0, 0)

#define ipaq_led_blink(color,rate, pts)  \
        ipaq_set_led(color, rate, pts)

extern void ipaq_set_led (enum led_color color, int cycle_time, int duty_time);

enum ipaq_egpio_type {
	IPAQ_EGPIO_LCD_POWER,     /* Power to the LCD panel */
	IPAQ_EGPIO_CODEC_NRESET,  /* Clear to reset the audio codec (remember to return high) */
	IPAQ_EGPIO_AUDIO_ON,      /* Audio power */
	IPAQ_EGPIO_QMUTE,         /* Audio muting */
	IPAQ_EGPIO_OPT_NVRAM_ON,  /* Non-volatile RAM on extension sleeves (SPI interface) */
	IPAQ_EGPIO_OPT_ON,        /* Power to extension sleeves */
	IPAQ_EGPIO_CARD_RESET,    /* Reset PCMCIA cards on extension sleeve (???) */
	IPAQ_EGPIO_OPT_RESET,     /* Reset option pack (???) */
	IPAQ_EGPIO_IR_ON,         /* IR sensor/emitter power */
	IPAQ_EGPIO_IR_FSEL,       /* IR speed selection 1->fast, 0->slow */
	IPAQ_EGPIO_RS232_ON,      /* Maxim RS232 chip power */
	IPAQ_EGPIO_VPP_ON,        /* Turn on power to flash programming */
	IPAQ_EGPIO_LCD_ENABLE,    /* Enable/disable LCD controller */
	IPAQ_EGPIO_PCMCIA_CD0_N,  /* pcmcia socket 0 card detect (read-only) */
	IPAQ_EGPIO_PCMCIA_CD1_N,  /* pcmcia socket 1 card detect (read-only) */
	IPAQ_EGPIO_PCMCIA_IRQ0,   /* pcmcia socket 0 card irq (read-only) */
	IPAQ_EGPIO_PCMCIA_IRQ1,   /* pcmcia socket 1 card irq (read-only) */
	IPAQ_EGPIO_BLUETOOTH_ON,  /* Bluetooth module power */
};

struct ipaq_model_ops {
	const char     *generic_name;
	void          (*control)(enum ipaq_egpio_type, int);
	unsigned long (*read)(enum ipaq_egpio_type);
	void          (*blank_callback)(int blank);
	int           (*pm_callback)(int req);      /* Primary model callback */
	int           (*pm_callback_aux)(int req);  /* Secondary callback (used by HAL modules) */
	int	      (*irq_number)( enum ipaq_egpio_type egpio_nr ); /* converts egpio number to cpu irq number */
	/* Data to be stashed at wakeup */
	u32           gedr;
	u32           icpr;

	void	      (*set_led)(enum led_color color, int duty_time, int cycle_time);
	void	      (*backlight_power)(int on);
};

extern struct ipaq_model_ops ipaq_model_ops;

static __inline__ const char * h3600_generic_name( void ) {
	return ipaq_model_ops.generic_name;
}

static __inline__ void assign_h3600_egpio( enum ipaq_egpio_type x, int level ) {
	if (ipaq_model_ops.control)
		ipaq_model_ops.control(x,level); 
}

static __inline__ void clr_h3600_egpio( enum ipaq_egpio_type x ) { 
	if (ipaq_model_ops.control)
		ipaq_model_ops.control(x,0); 
}

static __inline__ void set_h3600_egpio( enum ipaq_egpio_type x ) { 
	if (ipaq_model_ops.control)
		ipaq_model_ops.control(x,1); 
}

static __inline__ unsigned long read_h3600_egpio( enum ipaq_egpio_type x ) {
	if (ipaq_model_ops.read)
		return ipaq_model_ops.read(x);
	return 0;
}

static __inline__ int  h3600_register_blank_callback( void (*f)(int) ) {
	ipaq_model_ops.blank_callback = f;
	return 0;
}

static __inline__ void h3600_unregister_blank_callback( void (*f)(int) ) {
	ipaq_model_ops.blank_callback = NULL;
}


static __inline__ int  h3600_register_pm_callback( int (*f)(int) ) {
	ipaq_model_ops.pm_callback_aux = f;
	return 0;
}

static __inline__ void h3600_unregister_pm_callback( int (*f)(int) ) {
	ipaq_model_ops.pm_callback_aux = NULL;
}

static __inline__ int h3600_power_management( int req ) {
	if ( ipaq_model_ops.pm_callback )
		return ipaq_model_ops.pm_callback(req);
	return 0;
}

static __inline__ int h3600_egpio_irq_number( enum ipaq_egpio_type egpio_number ) {
	if ( ipaq_model_ops.irq_number )
		return ipaq_model_ops.irq_number(egpio_number);
	return 0;
}

#ifndef IRQT_NOEDGE
#define IRQT_NOEDGE     0
#define IRQT_RISING	GPIO_RISING_EDGE
#define IRQT_FALLING	GPIO_FALLING_EDGE
#define IRQT_BOTHEDGE	GPIO_BOTH_EDGES
#endif

extern int h3600_egpio_set_irq_type(enum ipaq_egpio_type egpio_number, unsigned int type);
extern int h3600_egpio_request_irq(enum ipaq_egpio_type egpio_number,
				   void (*handler)(int, void *, struct pt_regs *),
				   unsigned long flags, const char *name, void *data);
extern void h3600_egpio_free_irq(enum ipaq_egpio_type egpio_number, void *data);


#endif /* ASSEMBLY */

#endif /* _INCLUDE_H3600_H_ */
