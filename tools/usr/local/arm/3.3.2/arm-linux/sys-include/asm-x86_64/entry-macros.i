
OLDABI = 1 	

	;;; size of frame pushed by SAVE_ARGS 
ARGS_FRAME_SIZE = 56

	.macro SAVE_ARGS	
	cld	
	pushq %rdi
	pushq %rsi
	pushq %rdx
	pushq %rcx
	pushq %rbx
	pushq %rax
	pushq %r8
	pushq %r9
	.endm

	.macro RESTORE_ARGS restoreax=1
	popq %r9
	popq %r8
	.if \restoreax
	popq %rax
	.else
	popq %rdi 
	.endif 	
	popq %rbx	
	popq %rcx	
	popq %rdx	
	popq %rsi	
	popq %rdi	
	.endm	

	.macro LOAD_ARGS offset
	movq \offset(%rsp),%r9
	movq \offset+8(%rsp),%r8
	movq \offset+16(%rsp),%rax
	movq \offset+24(%rsp),%rbx
	movq \offset+32(%rsp),%rcx
	movq \offset+40(%rsp),%rdx
	movq \offset+48(%rsp),%rsi
	movq \offset+56(%rsp),%rdi
	.endm
			
	.macro SAVE_REST
	pushq %rbp
	pushq %r10
	pushq %r11  
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	.endm		

	.macro RESTORE_REST
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %r11
	popq %r10
	popq %rbp
	addq $8,%rsp
	.endm
		
	.macro SAVE_ALL
	SAVE_ARGS
	SAVE_REST
	.endm
		
	.macro RESTORE_ALL restoreax=1
	RESTORE_REST
	RESTORE_ARGS \restoreax	
	.endm

	.macro CONDITIONAL_SWAPGS
	;;; ADDME.
	.endm

	.if \OLDABI 
	.macro SETUP_IRQ_ARGS 
	subq $56,%rsp
	.endm

	.macro CLEANUP_IRQ_ARGS
	addq $56,%rsp
	.endm

	.else
	;; new ABI: 
 
	.macro SETUP_IRQ_ARGS
	movq 7*8(%rsp),%rbx
	leaq -56(%rsp),%rcx
	.endm

	.macro CLEANUP_IRQ_ARGS
	.endm

	.endif

	.macro IRQ_ENTER 
	SAVE_ARGS
	CONDITIONAL_SWAPGS 
	SETUP_ARGS
	movq ARGS_FRAME_SIZE(%rsp),%rbx
	.endm

	.macro IRQ_EXIT
	CLEANUP_ARGS
	jmp ret_from_intr
	.endmA