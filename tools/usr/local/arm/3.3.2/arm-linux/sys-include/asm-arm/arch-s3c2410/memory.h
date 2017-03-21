/*
 * linux/include/asm-arm/arch-s3c2410/memory.h
 *
 * Copyright (C) 2002 SAMSUNG ELECTRONICS 
 *             SW.LEE <hitchcar@sec.samsung.com>
 */

#ifndef __ASM_ARCH_MEMORY_H
#define __ASM_ARCH_MEMORY_H

#include <linux/config.h>

/*
 * Task size: 3GB
 */
#define TASK_SIZE	(0xc0000000UL)
#define TASK_SIZE_26	(0x04000000UL)

/*
 * This decides where the kernel will search for a free chunk of vm
 * space during mmap's.
 */
#define TASK_UNMAPPED_BASE (TASK_SIZE / 3)

/*
 * Page offset: 3GB
 */
#define PAGE_OFFSET	(0xC0000000UL)

/*
 * Physical SDRAM offset is 0x30000000 on the S3C2410 
 */
#define PHYS_OFFSET	(0x30000000UL)

/*
 * We take advantage of the fact that physical and virtual address can be the
 * same.  The NUMA code is handling the large holes that might exist between
 * all memory banks.
 */
#define __virt_to_phys__is_a_macro
#define __phys_to_virt__is_a_macro

/* Modified by SW.LEE */
#define __virt_to_phys(x)	( ((x)- PAGE_OFFSET)+PHYS_OFFSET )
#define __phys_to_virt(x)	( ((x)- PHYS_OFFSET)+PAGE_OFFSET )

/*
 * Virtual view <-> DMA view memory address translations
 * virt_to_bus: Used to translate the virtual address to an
 *		address suitable to be passed to set_dma_addr
 * bus_to_virt: Used to convert an address for DMA operations
 *		to an address that the kernel can use.
 *
 *
 */
#define __Distance_PA_VA 0x90000000
#define __virt_to_bus__is_a_macro
#define __bus_to_virt__is_a_macro
#define __virt_to_bus(x)	((x - __Distance_PA_VA))
#define __bus_to_virt(x)	((x + __Distance_PA_VA))


#define PHYS_TO_NID(addr)	(0)  /* node  0  */
#define NR_NODES	1
          /*  used in fucntion bootmem_init  arch/arm/mm/init.c  */



#endif /*  __ASM_ARCH_MEMORY_H */





