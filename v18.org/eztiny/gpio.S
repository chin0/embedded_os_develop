/*=======================================================================================

  ȭ�ϸ� : gpio.S
  ��  �� : EZ-X5 �� GPIO�� ���� �ϴ� ��ƾ�̴�.
  
  �ۼ��� : (��)���̴���Ƽ  Ǫ��
  �ۼ��� : 2003�� 4�� 21��
  
  ��  �� :  

=========================================================================================*/

#include 	<ez_x5.h>
		
.text

//-----------------------------------------------------------------------------------------		
//
//  gpio �ʱ�ȭ
//
//-----------------------------------------------------------------------------------------		
.globl gpio_init
gpio_init:
		// GPIO Alternate function
		ldr	r0, =PXA_REG_GP_BASE

		ldr	r1, =GAFR0_L_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GAFR0_L]
		ldr	r1, =GAFR0_U_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GAFR0_U]
			
		ldr	r1, =GAFR1_L_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GAFR1_L]
		ldr	r1, =GAFR1_U_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GAFR1_U]

		ldr	r1, =GAFR2_L_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GAFR2_L]
		ldr	r1, =GAFR2_U_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GAFR2_U]

		ldr	r1, =GPDR0_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GPDR0]
		ldr	r1, =GPDR1_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GPDR1]
		ldr	r1, =GPDR2_VALUE
		str	r1, [r0, #PXA_REG_OFFSET_GPDR2]

		// PSSR ���� - GPIO �Է� Ȱ��ȭ
		ldr	r0, =PXA_REG_PSSR
		ldr	r1, =PSSR_VALUE
		str	r1, [r0]

		// debug led off
		ldr	r0, =PXA_REG_GP_BASE
		mov	r1, #(_LED_3|_LED_2|_LED_1|_LED_0)
		str	r1, [r0, #PXA_REG_OFFSET_GPSR0]

		mov	pc, lr

//-----------------------------------------------------------------------------------------		
//
//   debug LED �� �Ѱų� ����
//
//	r5 : ���°��� �Ѿ�´�
//
//-----------------------------------------------------------------------------------------		
.globl led_out
led_out:
		ldr	r0, =PXA_REG_GP_BASE
		
		// led 0,1,2 off
		mov	r1, #(_LED_2|_LED_1|_LED_0)
		str	r1, [r0, #PXA_REG_OFFSET_GPSR0]

		// state on
		mov	r1, #0
		
		and	r4, r5, #0x4
		cmp	r4, #0
		beq	10f
		orr	r1, r1, #_LED_2

10:		and	r4, r5, #0x2
		cmp	r4, #0
		beq	20f
		orr	r1, r1, #_LED_1

20:		and	r4, r5, #0x1
		cmp	r4, #0
		beq	30f
		orr	r1, r1, #_LED_0		

30:		str	r1, [r0, #PXA_REG_OFFSET_GPCR0]
		
		mov	pc, lr

//-----------------------------------------------------------------------------------------		
//
//  LED�� ���� ��Ų��. �� ��ƾ�� ���� ��ƾ���� ������. 
//
//-----------------------------------------------------------------------------------------		
.globl error_loop
error_loop:           

		ldr	r0, =PXA_REG_GP_BASE
		mov	r1, #ERROR_LED
		
10:		str	r1, [r0, #PXA_REG_OFFSET_GPCR0]

		mov	r4, #0x800000
20:		nop
		nop
		subs	r4, r4, #1
		bne	20b

		str	r1, [r0, #PXA_REG_OFFSET_GPSR0]
		
		mov	r4, #0x800000
30:		nop
		nop
		subs	r4, r4, #1
		bne	30b
		
		b	10b