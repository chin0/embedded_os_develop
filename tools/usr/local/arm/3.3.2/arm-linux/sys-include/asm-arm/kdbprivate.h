#ifndef _ASM_KDBPRIVATE_H
#define _ASM_KDBPRIVATE_H

/*
 * Kernel Debugger Architecture Dependent Private Headers
 *
 * Copyright (C) 1999-2002 Silicon Graphics, Inc.  All Rights Reserved
 * Xscale (R) modifications copyright (C) 2003 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it would be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Further, this software is distributed without any warranty that it is
 * free of the rightful claim of any third person regarding infringement
 * or the like.  Any license provided herein, whether implied or
 * otherwise, applies only to this software file.  Patent licenses, if
 * any, provided herein do not apply to combinations of this program with
 * other software, or any other product whatsoever.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
 *
 * Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,
 * Mountain View, CA  94043, or:
 *
 * http://www.sgi.com
 *
 * For further information regarding this notice, see:
 *
 * http://oss.sgi.com/projects/GenInfo/NoticeExplan
 */

/*
 * Updated for Xscale (R) architecture support 
 * Edie Dong <edie.dong@intel.com> 8 Jan 03
 */

/* Definition of an machine instruction.
 * Takes care of VLIW processors like Itanium
 */

typedef struct {
	unsigned long inst[1];      // 2->1 by eddie
	} kdb_machinst_t;

	/*
	 * KDB_MAXBPT describes the total number of breakpoints
	 * supported by this architecure.
	 */
#define KDB_MAXBPT	16

	/*
	 * KDB_MAXHARDBPT describes the total number of hardware
	 * breakpoint registers that exist.
	 */
#define KDB_NUM_IBCR	 2
#define KDB_NUM_DBR	 2
#define KDB_MAXHARDBPT	 (KDB_NUM_IBCR+KDB_NUM_DBR)

	/*
	 * Platform specific environment entries
	 */
#define KDB_PLATFORM_ENV	"IDMODE=XScale", "BYTESPERWORD=4", "IDCOUNT=16"

	/*
	 * Define the direction that the stack grows
	 */
#define KDB_STACK_DIRECTION	(-1)	/* Stack grows down */

	/*
	 * Support for XScale debug registers
	 */

typedef struct _kdbhard_bp {
	kdb_machreg_t	bph_reg;	/* Register this breakpoint uses */

	unsigned int	bph_free:1;	/* Register available for use */
	unsigned int	bph_delay:1;	/* delay due to be used by single step */
	unsigned int	bph_b_inst:1;	/* BP type, IBP or not */
	unsigned int	bph_r_inst:1;	/* Register type, ibcr or dbr */
	// FIXME, b_inst & r_inst can be merged.

	unsigned int	bph_mode:2;	/* valid only in data breakpoint. 
	                                   0=disabled, 1=WO, 2=RW, 3=RO 
	                                   refer to DBCON_E_Type */
} kdbhard_bp_t;

extern kdbhard_bp_t	kdb_hardbreaks[/* KDB_MAXHARDBPT */];
				        // IBCR first, DBR 2nd

#define getprsregs(regs)        ((struct switch_stack *)regs -1)

extern struct switch_stack *kdb_sw[ /*NR_CPUS*/ ];

/*
 * Define certain specific instructions
 */
#define ARM_BREAK_INSTR           (unsigned long)((INST_AL << 28) | (0x12 << 20) | (7 << 4) | ((KDB_BREAK_BREAK >> 4) << 8) | (KDB_BREAK_BREAK&0xf))

#define KDB_HAVE_LONGJMP
#ifdef KDB_HAVE_LONGJMP
/*
 * Support for setjmp/longjmp
 */


#define _JBLEN  10
#define JB_r4    0
#define JB_r5    1
#define JB_r6    2
#define JB_r7    3
#define JB_r8    4
#define JB_r9    5
#define JB_r10   6
#define JB_r11   7
#define JB_SP    8
#define JB_LR    9

typedef struct __kdb_jmp_buf {
        unsigned long   __jmp_buf[_JBLEN];
} kdb_jmp_buf;

extern int kdba_setjmp(kdb_jmp_buf *);
extern void kdba_longjmp(kdb_jmp_buf *, int);

extern kdb_jmp_buf  kdbjmpbuf[];
#endif	/* KDB_HAVE_LONGJMP */


unsigned int  read_xsc_ibcr(int nr) ;
void  write_xsc_ibcr(int nr,unsigned int dat);
unsigned int  read_xsc_dcsr(void);
void write_xsc_dcsr(unsigned int dcsr);
void write_xsc_dcon(unsigned int dcon);
unsigned int  read_xsc_dcon(void);
unsigned int  read_xsc_dbr(int nr); 
void  write_xsc_dbr(int nr,unsigned int dat);


// bit definition of FSR
#define     FSR_STATUS_MASK 0xf
#define     FSR_DOMAIN_MASK (0xf<<4)
#define     FSR_DBG_BIT     (1<<9)


// bit definition of XScale debug unit
#define     DCSR_GE         (31)
#define     DCSR_H          (30)
#define     DCSR_TF         (23)
#define     DCSR_TI         (22)
#define     DCSR_TD         (20)
#define     DCSR_TA         (19)
#define     DCSR_TS         (18)
#define     DCSR_TU         (17)
#define     DCSR_TR         (16)
#define     DCSR_SA         (5)
#define     DCSR_MOE        (2)
#define     DCSR_M          (1)
#define     DCSR_E          (0)

#define     DCSR_MOE_MASK   (0x7UL<<DCSR_MOE)     // 3 bits
#define     DCSR_RSV_MASK   ((0x3fUL<<24) | (1UL<<21) | (0x3ffUL <<6))  // bits 29-24, 21, 15-6

#define    MOE_RST         0
#define    MOE_IBP         1        // Instruction Breakpoint
#define    MOE_DBP         2        // Data Breakpoint
#define    MOE_BKPT        3        // BKPT Instruction BP
#define    MOE_EXT         4        // External Debug Event
#define    MOE_VTRAP       5        // Vector Trap Occured
#define    MOE_TRACE       6        // Trace Buffer Full Break
#define    MOE_RSV         7        // reserved


// bit definition of XScale debug unit DBCON
#define     DBCON_E0        (0)
#define     DBCON_E1        (2)
#define     DBCON_M         (8)

typedef     enum _DBCON_E_Type {
    DBR_DISABLE=0,
    DBR_STORE_BRK=1,
    DBR_ACCESS_BRK=2,
    DBR_LOAD_BRK=3
} DBCON_E_Type;


#define     SS_IBCRN            1       // use IBCR1 for SW single step and one after BP
#define     IBCR_EN_MSK         1       // bit 0 of IBCRn

#endif	/* !_ASM_KDBPRIVATE_H */
