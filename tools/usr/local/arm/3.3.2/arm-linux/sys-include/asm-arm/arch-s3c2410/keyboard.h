/*
 *  linux/include/asm-arm/arch/keyboard.h
 *
 *  Copyright (C) 2002 SAMSUNG ELECTRONICS 
 *                     SW.LEE <hitchcar@sec.samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __S3C2410_KEYB_h
#define __S3C2410_KEYB_h 

#include <linux/config.h>
#include <asm/mach-types.h>
#include <asm/hardware.h>

extern struct kbd_ops_struct *kbd_ops;
extern int s3c2410_kbd_init (void);

#define kbd_disable_irq()	do  { }while (0)
#define kbd_enable_irq()	do  { }while (0)

#ifdef CONFIG_S3C2410_KEYB
#define kbd_init_hw()           s3c2410_kbd_init()
#else
#define kbd_init_hw()           do  { }while (0)
#endif

struct kbd_info {
	u_int			base;
	u_int			irq;
	u_char			divisor;
	u_char			type;
	u_char			state;
	u_char			prev_rx;
	u_char			last_tx;
	u_char			resend_count;
	u_short			res;
	u_char			present;
	wait_queue_head_t	wait_q;
	void			(*rx)(struct kbd_info *, u_int val,
				      struct pt_regs *regs);
};

#define KMI_KEYBOARD		0
#define KMI_MOUSE		1


#define KK_NONE		0x7f
#define KK_ESC		0x00
#define KK_F1		0x01
#define KK_F2		0x02
#define KK_F3		0x03
#define KK_F4		0x04
#define KK_F5		0x05
#define KK_F6		0x06
#define KK_F7		0x07
#define KK_F8		0x08
#define KK_F9		0x09
#define KK_F10		0x0a
#define KK_F11		0x0b
#define KK_F12		0x0c
#define KK_PRNT		0x0d
#define KK_SCRL		0x0e
#define KK_BRK		0x0f
#define KK_AGR		0x10
#define KK_1		0x11
#define KK_2		0x12
#define KK_3		0x13
#define KK_4		0x14
#define KK_5		0x15
#define KK_6		0x16
#define KK_7		0x17
#define KK_8		0x18
#define KK_9		0x19
#define KK_0		0x1a
#define KK_MINS		0x1b
#define KK_EQLS		0x1c
#define KK_BKSP		0x1e
#define KK_INS		0x1f
#define KK_HOME		0x20
#define KK_PGUP		0x21
#define KK_NUML		0x22
#define KP_SLH		0x23
#define KP_STR		0x24
#define KP_MNS		0x3a
#define KK_TAB		0x26
#define KK_Q		0x27
#define KK_W		0x28
#define KK_E		0x29
#define KK_R		0x2a
#define KK_T		0x2b
#define KK_Y		0x2c
#define KK_U		0x2d
#define KK_I		0x2e
#define KK_O		0x2f
#define KK_P		0x30
#define KK_LSBK		0x31
#define KK_RSBK		0x32
#define KK_ENTR		0x47
#define KK_DEL		0x34
#define KK_END		0x35
#define KK_PGDN		0x36
#define KP_7		0x37
#define KP_8		0x38
#define KP_9		0x39
#define KP_PLS		0x4b
#define KK_CAPS		0x5d
#define KK_A		0x3c
#define KK_S		0x3d
#define KK_D		0x3e
#define KK_F		0x3f
#define KK_G		0x40
#define KK_H		0x41
#define KK_J		0x42
#define KK_K		0x43
#define KK_L		0x44
#define KK_SEMI		0x45
#define KK_SQOT		0x46
#define KK_HASH		0x1d
#define KP_4		0x48
#define KP_5		0x49
#define KP_6		0x4a
#define KK_LSFT		0x4c
#define KK_BSLH		0x33
#define KK_Z		0x4e
#define KK_X		0x4f
#define KK_C		0x50
#define KK_V		0x51
#define KK_B		0x52
#define KK_N		0x53
#define KK_M		0x54
#define KK_COMA		0x55
#define KK_DOT		0x56
#define KK_FSLH		0x57
#define KK_RSFT		0x58
#define KK_UP		0x59
#define KP_1		0x5a
#define KP_2		0x5b
#define KP_3		0x5c
#define KP_ENT		0x67
#define KK_LCTL		0x3b
#define KK_LALT		0x5e
#define KK_SPCE		0x5f
#define KK_RALT		0x60
#define KK_RCTL		0x61
#define KK_LEFT		0x62
#define KK_DOWN		0x63
#define KK_RGHT		0x64
#define KP_0		0x65
#define KP_DOT		0x66

static char kbmap[128] = {
KK_NONE, KK_LALT, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_AGR,  KK_BSLH, KK_TAB,  KK_Z,    KK_A,    KK_X,    KK_NONE,
KK_NONE, KK_NONE, KK_LSFT, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_LCTL, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, 0x21,   KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_ESC,  KK_DEL,  KK_Q,    KK_CAPS, KK_S,    KK_C,    KK_3,
KK_NONE, KK_1,    KK_NONE, KK_W,    KK_NONE, KK_D,    KK_V,    KK_4,
KK_NONE, KK_2,    KK_T,    KK_E,    KK_NONE, KK_F,    KK_B,    KK_5, 
KK_NONE, KK_9,    KK_Y,    KK_R,    KK_K,    KK_G,    KK_N,    KK_6,
KK_NONE, KK_0,    KK_U,    KK_O,    KK_L,    KK_H,    KK_M,    KK_7,
KK_NONE, KK_MINS, KK_I,    KK_P,    KK_SEMI, KK_J,    KK_COMA, KK_8,
KK_NONE, KK_EQLS, KK_ENTR, KK_LSBK, KK_BSLH, KK_FSLH, KK_DOT,  KK_NONE,
KK_NONE, KK_NONE, KK_RSFT, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_BKSP, KK_DOWN, KK_RSBK, KK_UP,   KK_LEFT, KK_SPCE, KK_RGHT,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE};

static char kbmapFN[128] = {
KK_NONE, KK_LALT, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_LSFT, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_LCTL, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE,   0x21, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_F3,
KK_NONE, KK_F1,   KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_F4,
KK_NONE, KK_F2,   KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_F5,
KK_NONE, KK_F9,   KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_F6,
KK_NONE, KK_F10,  KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_F7,
KK_NONE, KK_NUML, KK_NONE, KK_INS,  KK_PRNT, KK_NONE, KK_NONE, KK_F8,
KK_NONE, KK_BRK,  KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_RSFT, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_PGDN, KK_SCRL, KK_PGUP, KK_HOME, KK_NONE, KK_END,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE};

static char kbmapNL[128] = {
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KP_9,   KK_NONE, KK_NONE, KP_2,   KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KP_STR, KP_4,   KP_6,   KP_3,   KK_NONE, KP_0,   KP_7,
KK_NONE, KK_NONE, KP_5,   KP_MNS, KP_PLS, KP_1,   KK_NONE, KP_8,
KK_NONE, KK_NONE, KP_ENT, KK_NONE, KK_NONE, KP_SLH, KP_DOT, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE,
KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE, KK_NONE};



#endif /*  END OF __S3C2410_KEYB_h  */
