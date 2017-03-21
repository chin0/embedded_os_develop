/*
 *
 * Definitions for HP iPAQ Handheld Computer
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
 * Author: Martin Demin.
 *
 */

#ifndef _AXIM_GPIO_H_
#define _AXIM_GPIO_H_

#define GPIO_NR_AXIM_POWER_BUTTON_N	(0)   /* Also known as the "off button"  */
#define GPIO_NR_AXIM_CABEL_INT_N	(4)
#define GPIO_NR_AXIM_CABEL_POW		(19)

#define IRQ_GPIO_AXIM_CABEL		IRQ_GPIO(GPIO_NR_AXIM_CABEL_INT_N)

#endif /* _AXIM_GPIO_H_ */
