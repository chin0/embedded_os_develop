/*
*
* Keyboard scancode definitions for the iPAQ H3600
*
* Copyright 2002 Compaq Computer Corporation.
*
* Use consistent with the GNU GPL is permitted,
* provided that this copyright notice is
* preserved in its entirety in all copies and derived works.
*
* COMPAQ COMPUTER CORPORATION MAKES NO WARRANTIES, EXPRESSED OR IMPLIED,
* AS TO THE USEFULNESS OR CORRECTNESS OF THIS CODE OR ITS
* FITNESS FOR ANY PARTICULAR PURPOSE.
*
* This file serves as a common repository for keyboard scancodes
* on the iPAQ.  The kernel does a one-to-one mapping between scancodes and
* keycodes by default, so these are also keycodes.
*
* Author: Andrew Christian
*/


#ifndef __H3600_KEYBOARD_H__
#define __H3600_KEYBOARD_H__

#include <linux/input.h>

/* These are the default scancodes for the buttons on the iPAQ itself */
#define H3600_SCANCODE_RECORD   120
#define H3600_SCANCODE_CALENDAR 122
#define H3600_SCANCODE_CONTACTS 123
#define H3600_SCANCODE_Q        124
#define H3600_SCANCODE_START    125
#define H3600_SCANCODE_UP       103 /* keycode up */
#define H3600_SCANCODE_RIGHT    106 /* keycode right */
#define H3600_SCANCODE_LEFT     105 /* keycode left */
#define H3600_SCANCODE_DOWN     108 /* keycode down */
#define H3600_SCANCODE_ACTION   96  /* keycode keypad enter */ /* 28 is regular enter, 126 is rocker enter */
#define H3600_SCANCODE_SUSPEND  121  /* keycode powerdown */

#define H3600_SCANCODE_ENVELOPE H3600_SCANCODE_Q /* Same as "Q" - appears on models 3700 & 3800 */

#endif /* __H3600_KEYBOARD_H__ */
