#ifndef __UM_PTRACE_H
#define __UM_PTRACE_H

#ifndef __ASSEMBLY__

#include "asm/current.h"

#define pt_regs pt_regs_subarch

#include "asm/arch/ptrace.h"

#undef pt_regs
#undef user_mode
#undef instruction_pointer

#include "../../arch/um/include/sysdep/ptrace.h"

struct pt_regs { int user_mode; };

#define user_mode(regs) ((regs)->user_mode)

struct task_struct;

extern int putreg(struct task_struct *child, unsigned long regno, 
	      unsigned long value);
unsigned long getreg(struct task_struct *child, unsigned long regno);

#define INIT_TASK_SIZE (4 * PAGE_SIZE)

#endif

#endif
