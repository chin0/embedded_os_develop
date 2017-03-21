/*
 *  include/asm-i386/bugs.h
 *
 *  Copyright (C) 1994  Linus Torvalds
 *  Copyright (C) 2000  SuSE
 *
 * This is included by init/main.c to check for architecture-dependent bugs.
 *
 * Needs:
 *	void check_bugs(void);
 */

#include <linux/config.h>
#include <asm/processor.h>
#include <asm/i387.h>
#include <asm/msr.h>
#include <asm/pda.h>

static inline void test_swapgs(void)
{
	unsigned long flags; 
	unsigned long v,o1,o2,o3;
	const unsigned long 
		testval1 =  1,
		testval2 = 0x0000010000000000,
		testval3 = 0xfffff10000000000; 

	__save_flags(flags); 
	__cli(); 

	rdmsrl(MSR_GS_BASE,o1);					
	rdmsrl(MSR_FS_BASE,o2);					
	rdmsrl(MSR_KERNEL_GS_BASE,o3);					

	wrmsrl(MSR_GS_BASE, testval2); 
	wrmsrl(MSR_FS_BASE, testval3); 
	wrmsrl(MSR_KERNEL_GS_BASE, testval1); 
	rdmsrl(MSR_KERNEL_GS_BASE,v); 
	if (v != testval1) panic("swapgs does not seem work #1 (v=%lx)\n",v); 

	asm volatile("    .byte 0x0f,0x01,0xf8 "); 
	rdmsrl(MSR_GS_BASE,v); 
	if (v != testval1) panic("swapgs does not seem work #2 (v=%lx)\n",v); 
	rdmsrl(MSR_KERNEL_GS_BASE,v);
	if (v != testval2) panic("swapgs does not seem work #3 (v=%lx)\n",v); 

	asm	volatile("    .byte 0x0f,0x01,0xf8 "); 
	rdmsrl(MSR_GS_BASE,v); 
	if (v != testval2) panic("swapgs does not seem work #4 (v=%lx)\n",v); 
	rdmsrl(MSR_KERNEL_GS_BASE,v)
	if (v != testval1) panic("swapgs does not seem work #5 (v=%lx)\n",v); 

	rdmsrl(MSR_FS_BASE,v); 
	if (v != testval3) panic("fs corrupted v=%lx\n", v);

	{ 
		unsigned long x[2],v;
		x[1] = 0x1234;
		wrmsrl(MSR_GS_BASE,x); 
		asm volatile("movq %%gs:8,%0" : "=r" (v)); 
		if (v != x[1]) 
			panic("\ngs access: %lx expected %lx\n", v, x[1]); 
	} 

#if 0 /* this overflow the stack silenty, corrupts memory and crashes later
	 in check_disk_change because bdev->check_media_change doesn't
         point any longer in ide_check_media_change() */
	{
		struct x8664_pda x;
		x.kernelstack = 0x1234; 
		x.pcurrent=(void *) testval1; 	       
		wrmsrl(MSR_GS_BASE, &x); 
		if ((v = read_pda(pcurrent)) != x.pcurrent) { 
			rdmsrl(MSR_GS_BASE, v2); 
			panic("\n%p: gs access does not work #6: %lx exp:%lx/%lx, gs: %lx exp:%p\n",
			      current_text_addr(), v,testval1,x.pcurrent,v2,&x);
		} 
		asm volatile("movq $0,%%gs:0":::"memory");  
		asm volatile("addq $1,%%gs:0":::"memory"); 
		if (((unsigned long *)&x)[0] != 1) { 
			panic("%p: gs access: %lx instead of 1\n", current_text_addr() , 
			      ((unsigned long *)&x)[0]);
		}
		printk("%%gs access seems to be ok\n"); 
	}
#endif




	wrmsrl(MSR_GS_BASE,o1);
	wrmsrl(MSR_FS_BASE,o2);
	wrmsrl(MSR_KERNEL_GS_BASE,o3);

	__restore_flags(flags); 
} 


static inline void test_star(void)
{ 
	extern void system_call(void); 
	unsigned long v;

	rdmsrl(MSR_LSTAR, v);
	if (v != (unsigned long)system_call) 
		panic("lstar wrong: %lx expected %p\n", v, system_call); 
} 

static inline void check_fpu(void)
{
	extern void __bad_fxsave_alignment(void);
	if (offsetof(struct task_struct, thread.i387.fxsave) & 15)
		__bad_fxsave_alignment();
	printk(KERN_INFO "Enabling fast FPU save and restore... ");
	set_in_cr4(X86_CR4_OSFXSR);
	printk("done.\n");
	printk(KERN_INFO "Enabling unmasked SIMD FPU exception support... ");
	set_in_cr4(X86_CR4_OSXMMEXCPT);
	printk("done.\n");
}

/*
 * If we configured ourselves for FXSR, we'd better have it.
 */

static void __init check_bugs(void)
{
	identify_cpu(&boot_cpu_data);
	test_swapgs(); 
	test_star(); 
	check_fpu();
#if !defined(CONFIG_SMP) && !defined(MINIKERNEL) 
	printk("CPU: ");
	print_cpu_info(&boot_cpu_data);
#endif
}
