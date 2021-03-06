/*
 * linux/include/asm-arm/arch-pxa/pcmcia.h
 *
 * Author:	George Davis
 * Created:	Jan 10, 2002
 * Copyright:	MontaVista Software Inc.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *
 * Originally based upon linux/include/asm-arm/arch-sa1100/pcmcia.h
 *
 */

#ifndef _ASM_ARCH_PCMCIA
#define _ASM_ARCH_PCMCIA


/* Ideally, we'd support up to MAX_SOCK sockets, but PXA250 only
 * provides support for a maximum of two.
 */
#define PXA_PCMCIA_MAX_SOCK   (2)


#ifndef __ASSEMBLY__

struct pcmcia_init {
  void (*handler)(int irq, void *dev, struct pt_regs *regs);
};

struct pcmcia_state {
  unsigned detect: 1,
            ready: 1,
             bvd1: 1,
             bvd2: 1,
           wrprot: 1,
            vs_3v: 1,
            vs_Xv: 1;
};

struct pcmcia_state_array {
  unsigned int size;
  struct pcmcia_state *state;
};

struct pcmcia_irq_info {
  unsigned int sock;
  unsigned int irq;
};

struct pcmcia_low_level {
  int (*init)(struct pcmcia_init *);
  int (*shutdown)(void);
  int (*socket_state)(struct pcmcia_state_array *);
  int (*get_irq_info)(struct pcmcia_irq_info *);
  int (*configure_socket)(unsigned int, socket_state_t *);

  /*
   * Enable card status IRQs on (re-)initialisation.  This can
   * be called at initialisation, power management event, or
   * pcmcia event.
   */
  int (*socket_init)(int sock);

  /*
   * Disable card status IRQs and PCMCIA bus on suspend.
   */
  int (*socket_suspend)(int sock);

  /*
   * Calculate MECR timing clock wait states
   */
  int (*socket_get_timing)(unsigned int sock, unsigned int cpu_speed,
                           unsigned int cmd_time );
};

extern struct pcmcia_low_level *pcmcia_low_level;

#endif  /* __ASSEMBLY__ */

#endif
