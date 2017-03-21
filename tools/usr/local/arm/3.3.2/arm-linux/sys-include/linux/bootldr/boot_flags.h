#ifndef BOOT_FLAGS_H_INCLUDED
#define BOOT_FLAGS_H_INCLUDED

/*
 * these bits control the boot flow.
 * They are stored initially in the PWER register.
 * Then, once RAM is running, they are stored in RAM
 * The current location is pointed to by Boot_flags_ptr.
 */

#define	BF_SQUELCH_SERIAL	(1<<0)
#define	BF_SLEEP_RESET		(1<<1)
#define	BF_NORMAL_BOOT		(1<<2)
#define BF_ACTION_BUTTON        (1<<3)
#define BF_BUTTON_CHECKED       (1<<4)

#define	BF_JORNADA56X		(1<<16) /* for checking in boot-sa1100.s */
#define BF_H3800                (1<<17)
#define BF_H3900                (1<<18)
#define BF_H5400                (1<<19)
#define BF_H1900		(1<<20)
#define BF_AXIM			(1<<21)

#ifndef __ASSEMBLY__
extern unsigned long*	boot_flags_ptr;
#endif

#define	squelch_serial()	((*boot_flags_ptr) & BF_SQUELCH_SERIAL)
#define	clr_squelch_serial()    (*boot_flags_ptr &= ~BF_SQUELCH_SERIAL)
#define	set_squelch_serial()    (*boot_flags_ptr |=  BF_SQUELCH_SERIAL)

#define	tst_sleep_reset()	((*boot_flags_ptr) & BF_SLEEP_RESET)
#define	clr_sleep_reset()	(*boot_flags_ptr &= ~BF_SLEEP_RESET)
#define	set_sleep_reset()	(*boot_flags_ptr |=  BF_SLEEP_RESET)

#define	normal_boot()		((*boot_flags_ptr) & BF_NORMAL_BOOT)
#define	clr_normal_boot()	(*boot_flags_ptr &= ~BF_NORMAL_BOOT)
#define	set_normal_boot()	(*boot_flags_ptr |=  BF_NORMAL_BOOT)



#if defined(CONFIG_MACH_IPAQ)
#define BL_SIG		"BTSY"
#elif defined(CONFIG_MACH_BALLOON)
#define BL_SIG		"LOON"
#elif defined(CONFIG_MACH_SKIFF)
#define BL_SIG		"SKIF"
#elif defined(CONFIG_MACH_ASSABET)
#define BL_SIG		"ASBT"
#elif defined(CONFIG_NEPONSET)
#define BL_SIG		"NEPO"
#elif defined(CONFIG_MACH_JORNADA720) || defined(CONFIG_MACH_JORNADA56X)
#define BL_SIG		"JRND"
#elif defined(CONFIG_MACH_H3900)
#define BL_SIG		"3900"
#elif defined(CONFIG_MACH_H5400)
#define BL_SIG		"IPQ3"
#elif defined(CONFIG_PXA1)
#define BL_SIG		"PXA1"
#else
#define BL_SIG          "UNKN"
#endif

#define BL_SIG_OFFSET	0x34
#if defined(CONFIG_MACH_BALLOON)
#define DO_SPLASH	0
#define CHECK_FOR_FUNC_BUTTONS	0
#elif defined(CONFIG_MACH_IPAQ) || defined(CONFIG_MACH_JORNADA56X)
#define DO_SPLASH	1
#define CHECK_FOR_FUNC_BUTTONS	1
#elif defined(CONFIG_MACH_ASSABET)
#define DO_SPLASH	1
#define CHECK_FOR_FUNC_BUTTONS	0
#elif defined(CONFIG_MACH_SPOT) || defined(CONFIG_MACH_GATOR)
#define DO_SPLASH	0
#define CHECK_FOR_FUNC_BUTTONS	0
#elif defined(CONFIG_MACH_JORNADA720)
#define DO_SPLASH	0
#define CHECK_FOR_FUNC_BUTTONS	0
#elif defined(CONFIG_MACH_H3900) || defined(CONFIG_MACH_IPAQ3)
#define DO_SPLASH	1
#define CHECK_FOR_FUNC_BUTTONS	1
#elif defined(CONFIG_PXA1)
#define DO_SPLASH	1
#define CHECK_FOR_FUNC_BUTTONS	0
#endif

#endif
