#ifndef _X86_64_PAGE_H
#define _X86_64_PAGE_H

/* PAGE_SHIFT determines the page size */
#define PAGE_SHIFT	12
#ifdef __ASSEMBLY__
#define PAGE_SIZE	(0x1 << PAGE_SHIFT)
#else
#define PAGE_SIZE	(1UL << PAGE_SHIFT)
#endif
#define PAGE_MASK	(~(PAGE_SIZE-1))
#define THREAD_SIZE (2*PAGE_SIZE)
#define CURRENT_MASK (~(THREAD_SIZE-1))

#ifdef __KERNEL__
#ifndef __ASSEMBLY__

#include <linux/config.h>

#ifdef CONFIG_X86_USE_3DNOW

#include <asm/mmx.h>

#define clear_page(page)	mmx_clear_page((void *)(page))
#define copy_page(to,from)	mmx_copy_page(to,from)

#else

/*
 *	On older X86 processors its not a win to use MMX here it seems.
 *	Maybe the K6-III ?
 */

#define clear_page(page)	memset((void *)(page), 0, PAGE_SIZE)

#define copy_page(to,from)	memcpy((void *)(to), (void *)(from), PAGE_SIZE)

#endif

#define clear_user_page(page, vaddr)	clear_page(page)
#define copy_user_page(to, from, vaddr)	copy_page(to, from)

/*
 * These are used to make use of C type-checking..
 */
typedef struct { unsigned long pte; } pte_t;
typedef struct { unsigned long pmd; } pmd_t;
typedef struct { unsigned long pgd; } pgd_t;
typedef struct { unsigned long level4; } level4_t;
#define PTE_MASK	PAGE_MASK

typedef struct { unsigned long pgprot; } pgprot_t;

#define pte_val(x)	((x).pte)
#define pmd_val(x)	((x).pmd)
#define pgd_val(x)	((x).pgd)
#define level4_val(x)	((x).level4)
#define pgprot_val(x)	((x).pgprot)

#define __pte(x) ((pte_t) { (x) } )
#define __pmd(x) ((pmd_t) { (x) } )
#define __pgd(x) ((pgd_t) { (x) } )
#define __level4(x) ((level4_t) { (x) } )
#define __pgprot(x)	((pgprot_t) { (x) } )

#endif /* !__ASSEMBLY__ */

/* to align the pointer to the (next) page boundary */
#define PAGE_ALIGN(addr)	(((addr)+PAGE_SIZE-1)&PAGE_MASK)


/* Hmm, stuff is not as easy with amd expanding address space in
   future. For now, assume we have 12bits base + 3*9 for 3level page
   tables (4level pages are too interesting). That's 39bits of virtual
   space. We keep it all for userland.
   --pavel
*/

#ifndef MINIKERNEL
#define __START_KERNEL		0xffffffff80100000
#define __START_KERNEL_map	0xffffffff80000000
#define __PAGE_OFFSET           0xffff800000000000
#else
#define __START_KERNEL		0x100000
#define __START_KERNEL_map	0x0
#define __PAGE_OFFSET		0x0
#endif

#ifndef __ASSEMBLY__

/*
 * Tell the user there is some problem. Beep too, so we can
 * see^H^H^Hhear bugs in early bootup as well!
 */

#ifdef CONFIG_DEBUG_BUGVERBOSE
extern void do_BUG(const char *file, int line);
/* FIXME: use inline assembly for do_BUG. The normal calling conventions
   in x86-64 destroy too many registers in the printk. */ 
#define BUG() do {                                    \
       do_BUG(__FILE__, __LINE__);                     \
       __asm__ __volatile__("ud2");                    \
} while (0)
#else
#define BUG() __asm__ __volatile__(".byte 0x0f,0x0b")
#endif

#define PAGE_BUG(page) do { \
	BUG(); \
} while (0)

/* Pure 2^n version of get_order */
extern __inline__ int get_order(unsigned long size)
{
	int order;

	size = (size-1) >> (PAGE_SHIFT-1);
	order = -1;
	do {
		size >>= 1;
		order++;
	} while (size);
	return order;
}

static unsigned long start_kernel_map __attribute__((unused)) = __START_KERNEL_map; /* FIXME: workaround gcc bug */

#endif /* __ASSEMBLY__ */

#define PAGE_OFFSET		((unsigned long)__PAGE_OFFSET)
#define __pa(x)			(((unsigned long)(x)>=start_kernel_map)?(unsigned long)(x) - (unsigned long)start_kernel_map:(unsigned long)(x) - PAGE_OFFSET)
#define __va(x)			((void *)((unsigned long)(x)+PAGE_OFFSET))
#define virt_to_page(kaddr)	(mem_map + (__pa(kaddr) >> PAGE_SHIFT))
#define VALID_PAGE(page)	((page - mem_map) < max_mapnr)


#endif /* __KERNEL__ */

#endif /* _X86_64_PAGE_H */
