#ifndef __UM_IRQ_H
#define __UM_IRQ_H

#include "asm/arch/irq.h"
#include "asm/ptrace.h"

#undef NR_IRQS


#define TIMER_IRQ	0
#define UMN_IRQ		1
#define CONSOLE_IRQ	2
#define UBD_IRQ		3
#define UM_ETH_IRQ	4
#define SSL_IRQ		5
#define ACCEPT_IRQ	6
#define MCONSOLE_IRQ	7

#define LAST_IRQ MCONSOLE_IRQ
#define NR_IRQS (LAST_IRQ + 1)

extern int um_request_irq(unsigned int irq, int fd,
			  void (*handler)(int, void *, struct pt_regs *),
			  unsigned long irqflags,  const char * devname,
			  void *dev_id);

#endif
