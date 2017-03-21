#ifndef __UM_SYSTEM_PPC_H
#define __UM_SYSTEM_PPC_H

#define pt_regs sys_pt_regs

#define _switch_to _ppc_switch_to

#include "asm/arch/system.h"

#undef _switch_to
 
#include "asm/system-generic.h"

#undef pt_regs

#endif
