/*========================================================================================================================

  È­ÀÏ¸í : entry.S
  ¼³  ¸í : ·¥ »ó¿¡ Á¸ÀçÇÏ´Â ezBootÀÇ ¸ÞÀÎ C ÇÔ¼öÀÇ mainÀ» È£ÃâÇÏ±â À§ÇÑ ·çÆ¾ÀÌ´Ù.
  
  ÀÛ¼ºÀÚ : (ÁÖ)Á¦ÀÌ´åµð¾ØÆ¼  À¯¿µÃ¢
  ÀÛ¼ºÀÏ : 2001³â 10¿ù 8ÀÏ
  
  ºñ  °í :  
==========================================================================================================================*/
.global _ram_entry
_ram_entry:
	bl	kernel_init	   // C ÇÔ¼öÀÇ mainÇÔ¼ö¸¦ È£ÃâÇÑ´Ù. 	
	b	_ram_entry // main ÇÔ¼öÀÇ È£ÃâÀÌ ³¡³µ´Ù¸é Àç È£ÃâÇÑ´Ù. 
    b   chinoOS_swiHandler
    b   chinoOS_irqHandler

#define svc_stack 0xa0300000
#define irq_stack 0xa0380000
#define sys_stack 0xa0400000

.global kernel_init
kernel_init:
    msr cpsr_c,#0xc0|0x13 //Svc mode
    ldr r0,=svc_stack
    sub sp,r0,#4

    msr cpsr_c,#0xc0|0x12 //IRQ mode
    ldr r0,=irq_stack
    sub sp,r0,#4

    msr cpsr_c, #0xc0|0x1f //System mode
    ldr r0,=sys_stack
    sub sp,r0,#4 

    msr cpsr_c,#0xc0|0x13

    bl main
    b _ram_entry

.global chinoOS_swiHandler
chinoOS_swiHandler:
    stmfd   sp!,{r0-r12,r14}
    mrs     r1,spsr
    stmfd   sp!,{r1}
    ldr     r10,[lr,#-4]
    bic     r10,r10,#0xff000000
    mov     r0,r10
    bl      swiHandler
    ldmfd   sp!,{r1}
    msr     spsr_cxsf,r1 
    ldmfd sp!,{r0-r12,pc}^

.global chinoOS_irqHandler
chinoOS_irqHandler:
    msr cpsr_c, #0xc0|0x12 //disable irq (prevent interrupt nesting)

    /* Task context backup code. */
    //chinoOS_current: global pointer that points current task's TCB
    ldr sp, =chinoOS_current //get current process's TCP address
    ldr sp, [sp] 
    /*in IRQ, we can't freely use register.
    (because, User mode and IRQ mode share 
    all registers except lr and sp. and lr contains
    ISR return address. therefore, we can freely use only sp.)
    
    sub lr,lr,#4 //because of pipeline
    add sp,sp,#4 //sp points context array's first element.
    stmia sp!,{r0-r12}^ //backup register
    stmia sp!,{sp,lr}^ //backup user mode's sp,lr
    stmia sp!,{lr} //backup irq mode's register

    sub sp,sp,#68 //points current tcb's context_spsr
    mrs r1,spsr 
    stmia sp!,{r1} //backup spsr register

    /* restore stack pointer */
    ldr sp,=irq_stack

    bl irqHandler

    /* tesk context restore */
    ldr sp, =chinoOS_next
    ldr sp, [sp]

    ldmia sp!,{r1}
    msr spsr_cxsf,r1
    ldmia sp!,{r0-r12}^
    ldmia sp!, {r13,r14}^

    ldmfd sp!,{pc}^
