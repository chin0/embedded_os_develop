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
    msr cpsr_c, #0xc0|0x12 //¿¿¿¿¿ ¿¿¿¿¿¿ IRQ¿ ¿¿¿¿(¿¿¿¿¿ ¿¿¿ ¿¿¿¿¿ ¿ ¿¿¿ ¿¿¿ ¿¿¿¿¿)

    /**********************************************
    ¿¿ ¿¿¿¿ ¿¿¿ ¿¿¿¿¿¿¿¿¿
    ISR¿¿¿¿ ¿¿ ¿ ¿¿¿ ¿¿¿¿¿ ¿¿¿¿¿
    ¿¿¿¿ ¿¿¿¿ (ISR¿ ¿¿¿ ¿¿¿ ¿¿¿¿
    ¿ ¿¿¿¿¿¿)
    ***********************************************/

    /* ¿¿¿¿ ¿¿ ¿¿ */
    //chinoOS_current: ¿¿ ¿¿ ¿¿ ¿¿¿¿ TCB¿ ¿¿¿¿ ¿¿ ¿¿ ¿¿¿ ¿¿
    ldr sp, =chinoOS_current 
    ldr sp, [sp] //IRQ¿¿¿¿ ¿¿¿¿ ¿¿¿¿ ¿¿ ¿¿¿¿¿ SP¿¿ ¿¿¿¿¿ ¿¿¿¿ ¿¿

    sub lr,lr,#4
    add sp,sp,#4 //sp¿ TCB¿ context ¿¿¿ ¿¿¿
    stmia sp!,{r0-r12}^
    stmia sp!,{sp,lr}^ //user¿¿¿ sp,lr¿¿
    stmia sp!,{lr} //irq¿¿¿ ¿¿ ¿¿¿¿ ¿¿

    sub sp,sp,#68 //context_spsr¿ ¿¿
    mrs r1,spsr 
    stmia sp!,{r1} //¿¿

    /* IRQ ¿¿¿ ¿¿ */
    ldr sp,=irq_stack

    bl irqHandler

    /* ¿¿¿ ¿¿¿¿ ¿¿ */
    ldr sp, =chinoOS_next
    ldr sp, [sp]

    ldmia sp!,{r1}
    msr spsr_cxsf,r1
    ldmia sp!,{r0-r12}^
    ldmia sp!, {r13,r14}^

    ldmfd sp!,{pc}^

    bl irqHandler
