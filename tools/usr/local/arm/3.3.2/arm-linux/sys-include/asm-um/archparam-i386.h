#ifndef __UM_ARCHPARAM_I386_H
#define __UM_ARCHPARAM_I386_H

/********* Bits for asm-um/elf.h ************/

#define ELF_PLATFORM "i586"

#define ELF_ET_DYN_BASE (2 * TASK_SIZE / 3)

typedef int elf_gregset_t;
typedef int elf_fpregset_t;

#define ELF_DATA        ELFDATA2LSB
#define ELF_ARCH        EM_386

/********* Bits for asm-um/delay.h **********/

typedef unsigned long um_udelay_t;

/********* Nothing for asm-um/hardirq.h **********/

/********* Nothing for asm-um/hw_irq.h **********/

/********* Nothing for asm-um/string.h **********/

#endif
