/*
 * linux/include/asm-arm/arch-sa1100/dma-backpaq.h
 * 
 * 06/30/03 Fae Ghodrat - This file is a copy of dma.h.  
 *                        It's used by backpaq-uda1341 which does 
 *                        not have dma access.  This emulates a dma device.
 *
 * Copyright (C) 2000 Nicolas Pitre
 *
 */

#ifndef __ASM_ARCH_DMA_BACKPAQ_H
#define __ASM_ARCH_DMA_BACKPAQ_H

#include <linux/config.h>
#include "hardware.h"
#include <asm/arch/backpaq.h>

/*
 * This is the maximum DMA address that can be DMAd to.
 */
#define MAX_DMA_ADDRESS		0xffffffff

#define MAX_DMA_CHANNELS	0

#define BACKPAQ_DMA_CHANNELS	2

/*
 * Maximum physical DMA buffer size
 */
#define MAX_DMA_SIZE		0x1fff
#define CUT_DMA_SIZE		0x1000

/* from SA1100.h */
#define DCSR_RUN	0x00000001	/* DMA RUNing                      */
#define DCSR_IE 	0x00000002	/* DMA Interrupt Enable            */
#define DCSR_ERROR	0x00000004	/* DMA ERROR                       */
#define DCSR_DONEA	0x00000008	/* DONE DMA transfer buffer A      */
#define DCSR_STRTA	0x00000010	/* STaRTed DMA transfer buffer A   */
#define DCSR_BIU	0x00000080	/* DMA Buffer In Use               */


/* use a major and minor address
   i.e. major = BACKPAQ_FPGA, minor=large number
   ???? */
#define FAKE_DMA_RD (_BackpaqBase)+H3600_BACKPAQ_AUDIO_DEV+0x1000
#define FAKE_DMA_WR FAKE_DMA_RD+1
// + H3600_BACKPAQ_AUDIO_DEV

/*
 * All possible backpaq devices a DMA channel can be attached to.
 */
typedef enum {
  DMA_RD  = FAKE_DMA_RD, 
  DMA_WR  = FAKE_DMA_WR
} dma_device_t;

typedef struct {
  volatile u_long DDAR;     // dma device addresss register
  volatile u_long DCSR;     // dma status register
  volatile dma_addr_t DBSA; // dma start address register
  volatile u_long DBTA;     // dma size register - transfer count
} dma_regs_t;

typedef void (*dma_callback_t)(void *data);

/*
 * DMA function prototypes
 */

extern int backpaq_request_dma( dma_device_t device, const char *device_id,
			       dma_callback_t callback, void *data,
			       dma_regs_t **regs );
extern void backpaq_free_dma( dma_regs_t *regs );
extern int backpaq_start_dma( dma_regs_t *regs, dma_addr_t dma_ptr, u_int size );
extern dma_addr_t backpaq_get_dma_pos(dma_regs_t *regs);
extern void backpaq_reset_dma(dma_regs_t *regs);


#define backpaq_stop_dma(regs)  ((regs)->DCSR &= ~(DCSR_IE|DCSR_RUN))

#define backpaq_resume_dma(regs) ((regs)->DCSR |= (DCSR_IE|DCSR_RUN))

#define backpaq_clear_dma(regs)	((regs)->DCSR &= ~(DCSR_IE|DCSR_RUN|DCSR_STRTA))


#endif /* _ASM_ARCH_DMA_BACKPAQ_H */
