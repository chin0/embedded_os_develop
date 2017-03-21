#ifndef __UM_SIGNAL_H
#define __UM_SIGNAL_H

#include "sysdep/ptrace.h"
#include "asm/arch/signal.h"

struct signal_context {
	struct sys_pt_regs regs;
	sigset_t sigs;
	int repeat;
	struct signal_context *prev;
};

#endif
