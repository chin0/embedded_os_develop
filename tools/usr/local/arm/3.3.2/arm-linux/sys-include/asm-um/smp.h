#ifndef __UM_SMP_H
#define __UM_SMP_H

#ifdef __CONFIG_SMP

#include "linux/config.h"
#include "asm/current.h"

#ifdef CONFIG_SMP

#define smp_processor_id() (current->processor)

#define cpu_logical_map(n) (n)

extern int cpu_number_map[];

#define PROC_CHANGE_PENALTY	15 /* Pick a number, any number */

extern int hard_smp_processor_id(void);

#define NO_PROC_ID -1

#endif

#endif

#endif
