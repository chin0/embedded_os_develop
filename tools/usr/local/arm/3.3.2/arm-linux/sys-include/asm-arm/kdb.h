#ifndef _ASM_KDB_H
#define _ASM_KDB_H

/*
 * Kernel Debugger Architecture Dependent Global Headers
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

	/*
	 * KDB_ENTER() is a macro which causes entry into the kernel
	 * debugger from any point in the kernel code stream.  If it
	 * is intended to be used from interrupt level, it must use
	 * a non-maskable entry method.
	 */
#define KDB_BREAK_BREAK 0x0000		/* BKPT 0 kdb breakpoint in kernel */
#define KDB_BREAK_ENTER 0x0001		/* BKPT 1 for KDB_ENTER() */
//#define KDB_ENTER2(b)	asm("\tBKPT "#b"\n")
#define KDB_ENTER2(b)	asm("\t mov r1, $129 \n mov r12, $127\n \tBKPT "#b"\n")
#define KDB_ENTER1(b)	KDB_ENTER2(b)
#define KDB_ENTER()	KDB_ENTER1(KDB_BREAK_ENTER)

	/*
	 * Needed for exported symbols.
	 */
typedef unsigned long kdb_machreg_t;

#define kdb_machreg_fmt		"0x%lx"
#define kdb_machreg_fmt0	"0x%08lx"
#define kdb_bfd_vma_fmt		"0x%lx"
#define kdb_bfd_vma_fmt0	"0x%08lx"
#define kdb_elfw_addr_fmt	"0x%x"
#define kdb_elfw_addr_fmt0	"0x%08x"

	/*
	 * Functions to safely read and write kernel areas.  The {to,from}_xxx
	 * addresses are not necessarily valid, these functions must check for
	 * validity.  If the arch already supports get and put routines with
	 * suitable validation and/or recovery on invalid addresses then use
	 * those routines, otherwise check it yourself.
	 */

	/*
	 * asm-ia64 uaccess.h supplies __copy_to_user which relies on MMU to
	 * trap invalid addresses in the _xxx fields.  Verify the other address
	 * of the pair is valid by accessing the first and last byte ourselves,
	 * then any access violations should only be caused by the _xxx
	 * addresses,
	 */

#include <asm/uaccess.h>

static inline int
__kdba_putarea_size(unsigned long to_xxx, void *from, size_t size)
{
	mm_segment_t oldfs = get_fs();
	int r;
	char c;
	c = *((volatile char *)from);
	c = *((volatile char *)from + size - 1);
#ifdef VPERNODE_BASE /* if present, the new CONFIG_NUMA code */
	if (to_xxx >= VPERNODE_BASE && to_xxx < VGLOBAL_BASE) {
		to_xxx = __imva(to_xxx);
	}
#endif
	set_fs(KERNEL_DS);
	r = __copy_to_user((void *)to_xxx, from, size);
	set_fs(oldfs);
	return r;
}

static inline int
__kdba_getarea_size(void *to, unsigned long from_xxx, size_t size)
{
	mm_segment_t oldfs = get_fs();
	int r;
	*((volatile char *)to) = '\0';
	*((volatile char *)to + size - 1) = '\0';
	set_fs(KERNEL_DS);
	r = __copy_to_user(to, (void *)from_xxx, size);
	set_fs(oldfs);
	return r;
}

/* For numa with replicated code/data, the platform must supply its own
 * kdba_putarea_size and kdba_getarea_size routines.  Without replication kdb
 * uses the standard architecture routines.
 */
#ifdef CONFIG_NUMA_REPLICATE
extern int kdba_putarea_size(unsigned long to_xxx, void *from, size_t size);
extern int kdba_getarea_size(void *to, unsigned long from_xxx, size_t size);
#else
#define kdba_putarea_size __kdba_putarea_size
#define kdba_getarea_size __kdba_getarea_size
#endif

static inline int
kdba_verify_rw(unsigned long addr, size_t size)
{
	unsigned char data[size];
	return(kdba_getarea_size(data, addr, size) || kdba_putarea_size(addr, data, size));
}

extern int kdb_dbg_exception(unsigned long addr, int error_code, struct pt_regs *regs, int fsr);

#endif	/* !_ASM_KDB_H */
