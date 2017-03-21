#ifndef __S3C2410_POWER_H
#define __S3C2410_POWER_H

#define CR_M		(1 << 0)	/* MMU enable */
#define CR_C		(1 << 2) 	/* Dcache enable */
#define SELF_REFRESH 	(1 << 22)
#define EN_SCLK		(7 << 17)
#define DEFAULT_CLK	(0x7FFF0)
#define POWER_OFF_CLK	(DEFAULT_CLK + 0x8)

#ifndef __ASSEMBLY__
#include <linux/types.h>

extern void pwm_timer_update(void);
extern void clear_interrupt(void);
extern int  CPUSaveRegs(u32 *);
extern int  CPULoadRegs(u32 *);
extern void ConfigStopGPIO(void);
extern void ConfigMiscReg(void);
extern void CPULCDOff(void);
extern void CPUClearCS8900(void);
extern void CPUClearINT(void);

/* kapmd interface used in kapmd.c file */
extern void apmd_info_init(void *);
extern void apmd_create(void);
extern void apmd_destory(void);

#define APMD_MSG_EXIT 0
#define APMD_QUERY_RUNNING 1

extern int  apmd_config_status(int);

#endif	/* __ASSSEMBLY__ */

#endif  /*   __S3C2410_POWER_H */

