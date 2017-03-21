#ifndef __UM_CURRENT_H
#define __UM_CURRENT_H

#ifndef __ASSEMBLY__

#include "linux/config.h"

struct task_struct;

#ifdef CONFIG_SMP
extern struct task_struct *current_task[];

#define CURRENT_TASK(dummy) (((unsigned long) &dummy) & (PAGE_MASK << 2))

#define current ({ int dummy; (struct task_struct *) CURRENT_TASK(dummy); })

#else

extern struct task_struct *current_task;
#define current current_task

#endif

#endif /* __ASSEMBLY__ */

#endif
