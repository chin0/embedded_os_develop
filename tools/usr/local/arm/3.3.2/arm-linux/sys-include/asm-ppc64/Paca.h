#ifndef _PPC64_PACA_H
#define _PPC64_PACA_H

/*============================================================================
 *                                                         Header File Id
 * Name______________:	Paca.H
 *
 * Description_______:
 *
 * This control block defines the PACA which defines the processor 
 * specific data for each logical processor on the system.  
 * There are some pointers defined that are utilized by PLIC.
 *
 * C 2001 PPC 64 Team, IBM Corp
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */    
#include	<asm/types.h>

/*-----------------------------------------------------------------------------
 * Other Includes
 *-----------------------------------------------------------------------------
 */
#include	<asm/iSeries/ItLpPaca.h>
#include	<asm/iSeries/ItLpRegSave.h>
#include	<asm/iSeries/ItLpQueue.h>
#include	<asm/rtas.h>
#include	<asm/mmu.h>

/* A Paca entry is required for each logical processor.  On systems
 * that support hardware multi-threading, this is equal to twice the
 * number of physical processors.  On LPAR systems, we are required
 * to have space for the maximum number of logical processors we
 * could ever possibly have.  Currently, we are limited to allocating
 * 24 processors to a partition which gives 48 logical processors on
 * an HMT box.  Therefore, we reserve this many Paca entries.
 */
#define maxProcessors 24
#define maxPacas maxProcessors * 2

extern struct Paca   xPaca[];
extern struct Paca   *get_paca(void);

/*============================================================================
 * Name_______:	Paca
 *
 * Description:
 *
 *	Defines the layout of the Paca.  
 *
 *	This structure is not directly accessed by PLIC or the SP except
 *	for the first two pointers that point to the ItLpPaca area and the
 *	ItLpRegSave area for this processor.  Both the ItLpPaca and
 *	ItLpRegSave objects are currently contained within the
 *	PACA but they do not need to be.
 *
 *============================================================================
 */
struct Paca
{
/*===========================================================================
 * Following two fields are read by PLIC to find the LpPaca and LpRegSave area
 *===========================================================================
 */

  struct ItLpPaca * xLpPacaPtr;		/* Pointer to LpPaca for proc		0x00  */
  struct ItLpRegSave * xLpRegSavePtr;	/* Pointer to LpRegSave for proc	0x08 */

  u64		xCurrent;		/* Pointer to current			0x10 */
					/* The offset to xCurrent is hard coded
					 * in include/asm-ppc64/current.h which
					 * must be updated if this field moves
 					 */

  u64		xR21;			/* Savearea for GPR21			0x18 */
  u64		xR22;			/* Savearea for GPR22			0x20 */
  u64		xKsave;			/* Saved Kernel stack addr or zero	0x28 */
  
  u16		xPacaIndex;		/* Index into Paca array of this	0x30 */
  					/* Paca.  This is processor number	     */
  u16		xHwProcNum;		/* Actual Hardware Processor Number     0x32 */
  u32           xCCR;                   /* */
  u64		xSavedMsr;		/* old msr saved here by HvCall		0x38
  					 * and flush_hash_page
  					 * HvCall uses 64-bit registers
					 * so it must disable external
					 * interrupts to avoid the high
					 * half of the regs getting lost
					 * It can't stack a frame because
					 * some of the callers can't 
					 * tolerate hpt faults (which might
					 * occur on the stack)
 	 				 */
  u64		xSavedLr;		/* link register saved here by		0x40 */
  					/* flush_hash_page */
  u64		xThread;		/* Pointer to thread (current+THREAD)	0x48 */
  STAB          xStab_data;             /* Segment table information         */
					
  unsigned char	xSegments[STAB_CACHE_SIZE]; /* Cache of used stab entries    */
  u64		xTOC;			/* Kernel TOC address			0x70 */
  u64		xR1;			/* 					0x78 */

/*===========================================================================
 * CACHE_LINE_2-3 0x0080 - 0x017F
 *===========================================================================
 */

  struct ItLpQueue * lpQueuePtr;	/* LpQueue handled by this processor    0x80 */

  struct rtas_args xRtas;               /* Per processor RTAS struct            0x88 */

  u8		xProcStart;		/* At startup, processor spins until */
  					/* xProcStart becomes non-zero. */
  u8		rsvd4[3];
  u32		default_decr;		/* default decrementer value */	
  unsigned long next_jiffy_update_tb;	/* tb value for next jiffy update */
  u64		rsvd3[12];		/* To be used by Linux */

/*===========================================================================
 * CACHE_LINE_4-8  0x0180 - 0x03FF Contains ItLpPaca
 *===========================================================================
 */

  struct ItLpPaca xLpPaca;	/* Space for ItLpPaca		 */

/*===========================================================================
 * CACHE_LINE_9-16 0x0400 - 0x07FF Contains ItLpRegSave
 *=========================================================================== 
 */

  struct ItLpRegSave xRegSav;	/* Register save for proc	*/

/*===========================================================================
 * CACHE_LINE_17 0x0800 - 0x087F Contains former cpuinfo struct
 *=========================================================================== 
 */
  unsigned long pvr;
  unsigned long *pgd_cache;
  unsigned long *pmd_cache;
  unsigned long *pte_cache;
  unsigned long pgtable_cache_sz;
  unsigned int  prof_multiplier;
  unsigned int  prof_counter;
};

#endif /* _PPC64_PACA_H */
