/*
 * k_compat.h 1.138 2001/10/25 01:40:31
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License
 * at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and
 * limitations under the License. 
 *
 * The initial developer of the original code is David A. Hinds
 * <dahinds@users.sourceforge.net>.  Portions created by David A. Hinds
 * are Copyright (C) 1999 David A. Hinds.  All Rights Reserved.
 *
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License version 2 (the "GPL"), in
 * which case the provisions of the GPL are applicable instead of the
 * above.  If you wish to allow the use of your version of this file
 * only under the terms of the GPL and not to allow others to use
 * your version of this file under the MPL, indicate your decision by
 * deleting the provisions above and replace them with the notice and
 * other provisions required by the GPL.  If you do not delete the
 * provisions above, a recipient may use your version of this file
 * under either the MPL or the GPL.
 */

#ifndef _LINUX_K_COMPAT_H
#define _LINUX_K_COMPAT_H

#define __LINUX__
#define VERSION(v,p,s)		(((v)<<16)+(p<<8)+s)

/* These are deprecated: should not use any more */
#define RUN_AT(x)		(jiffies+(x))
#define CONST			const
#define ALLOC_SKB(len)		dev_alloc_skb(len+2)
#define DEVICE(req)		((req)->rq_dev)
#define GET_PACKET(dev, skb, count)\
		skb_reserve((skb), 2); \
		BLOCK_INPUT(skb_put((skb), (count)), (count)); \
		(skb)->protocol = eth_type_trans((skb), (dev))

#define BLK_DEV_HDR		"linux/blk.h"
#define NEW_MULTICAST
#ifdef CONFIG_NET_PCMCIA_RADIO
#define HAS_WIRELESS_EXTENSIONS
#endif

#define FREE_IRQ(i,d)		free_irq(i, d)
#define REQUEST_IRQ(i,h,f,n,d)	request_irq(i,h,f,n,d)
#define IRQ(a,b,c)		(a,b,c)
#define DEV_ID			dev_id
#define IRQ_MAP(irq, dev)	do { } while (0)

#define FS_SIZE_T		ssize_t
#define U_FS_SIZE_T		size_t

#if (LINUX_VERSION_CODE < VERSION(2,1,31))
#define FS_RELEASE_T		void
#else
#define FS_RELEASE_T		int
#endif

#if (LINUX_VERSION_CODE < VERSION(2,1,38))
#define test_and_set_bit	set_bit
#endif

#if (LINUX_VERSION_CODE > VERSION(2,1,16))
#define AUTOCONF_INCLUDED
#define EXPORT_SYMTAB
#define register_symtab(x)
#endif
#ifdef CONFIG_MODVERSIONS
#define MODVERSIONS		1
#include <linux/modversions.h>
#endif
#include <linux/module.h>

#if (LINUX_VERSION_CODE < VERSION(2,1,45))
#define F_INODE(file)		((file)->f_inode)
#else
#define F_INODE(file)		((file)->f_dentry->d_inode)
#endif

#if (LINUX_VERSION_CODE < VERSION(2,1,51))
#define INVALIDATE_INODES(r)	invalidate_inodes(r)
#else
#define INVALIDATE_INODES(r) \
	do { struct super_block *sb = get_super(r); \
	if (sb) invalidate_inodes(sb); } while (0)
#endif

#if (LINUX_VERSION_CODE < VERSION(2,1,60))
#define FOPS(i,f,b,c,p)		(i,f,b,c)
#define FPOS			(file->f_pos)
#else
#define FOPS(i,f,b,c,p)		(f,b,c,p)
#define FPOS			(*ppos)
#endif

#if (LINUX_VERSION_CODE < VERSION(2,1,89))
#define POLL_WAIT(f, q, w)	poll_wait(q, w)
#else
#define POLL_WAIT(f, q, w)	poll_wait(f, q, w)
#endif

#if (LINUX_VERSION_CODE < VERSION(2,1,104))
#define mdelay(x) { int i; for (i=0;i<x;i++) udelay(1000); }
#endif

#if (LINUX_VERSION_CODE < VERSION(2,1,126))
#define SCSI_DISK0_MAJOR	SCSI_DISK_MAJOR
#endif

/* Only for backwards compatibility */
#include <asm/uaccess.h>
#include <linux/ioport.h>
#include <linux/wait.h>
#include <linux/sched.h>

#if (LINUX_VERSION_CODE < VERSION(2,2,0))
#define in_interrupt()		(intr_count)
#endif

#if (LINUX_VERSION_CODE < VERSION(2,3,32))
#define BLK_DEFAULT_QUEUE(n)	blk_dev[n].request_fn
#define blk_init_queue(q, req)	do { (q) = (req); } while (0)
#define blk_cleanup_queue(q)	do { (q) = NULL; } while (0)
#define request_arg_t		void
#else
#define request_arg_t		request_queue_t *q
#endif

#if (LINUX_VERSION_CODE < VERSION(2,3,38))
#define block_device_operations file_operations
#endif

#if (LINUX_VERSION_CODE < VERSION(2,3,40))
#define register_disk(dev, drive, minors, ops, size) \
    do { (dev)->part[(drive)*(minors)].nr_sects = size; \
	if (size == 0) (dev)->part[(drive)*(minors)].start_sect = -1; \
	resetup_one_dev(dev, drive); } while (0);
#endif

#if (LINUX_VERSION_CODE < VERSION(2,2,0))
#define timer_pending(a)	(((a)->prev) != NULL)
#define mod_timer(a, b)	\
    do { del_timer(a); (a)->expires = (b); add_timer(a); } while (0)
#endif

#endif /* _LINUX_K_COMPAT_H */


/* from pcmcia-3.1.34 include/linux/netdevice.h */

#ifndef _COMPAT_NETDEVICE_H
#define _COMPAT_NETDEVICE_H

#include <linux/version.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,1,25))
#define net_device_stats	enet_statistics
#define skb_tx_check(dev, skb) \
    do { if (skb == NULL) { dev_tint(dev); return 0; } \
    if (skb->len <= 0) return 0; } while (0)
#define add_rx_bytes(stats, n)	do { int x; x = (n); } while (0)
#define add_tx_bytes(stats, n)	do { int x; x = (n); } while (0)
#else
#define skb_tx_check(dev, skb)	do { } while (0)
#define add_rx_bytes(stats, n)	do { (stats)->rx_bytes += n; } while (0)
#define add_tx_bytes(stats, n)	do { (stats)->tx_bytes += n; } while (0)
#endif

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,1,86))
#define DEV_KFREE_SKB(skb)      dev_kfree_skb(skb, FREE_WRITE)
#else
#define DEV_KFREE_SKB(skb)      dev_kfree_skb(skb)
#endif

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,3,14))
#define net_device		device
#endif

#include_next <linux/netdevice.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,3,43))
#define netif_stop_queue(dev)	set_bit(0, (void *)&(dev)->tbusy)
#define netif_start_queue(dev)	clear_bit(0, (void *)&(dev)->tbusy)
#define netif_wake_queue(dev) \
    do { netif_start_queue(dev); mark_bh(NET_BH); } while (0)
#define netif_device_attach(dev) \
    do { (dev)->start = 1; netif_start_queue(dev); } while (0)
#define netif_device_detach(dev) \
    do { (dev)->start = 0; netif_stop_queue(dev); } while (0)
#define netif_device_present(dev) ((dev)->start)
#define netif_running(dev)	((dev)->start)
#define netif_mark_up(dev)	do { (dev)->start = 1; } while (0)
#define netif_mark_down(dev)	do { (dev)->start = 0; } while (0)
#define netif_carrier_on(dev)	do { dev->flags |= IFF_RUNNING; } while (0)
#define netif_carrier_off(dev)	do { dev->flags &= ~IFF_RUNNING; } while (0)
#define netif_queue_stopped(dev) ((dev)->tbusy)
#define tx_timeout_check(dev, tx_timeout) \
    do { if (test_and_set_bit(0, (void *)&(dev)->tbusy) != 0) { \
	if (jiffies - (dev)->trans_start < TX_TIMEOUT) return 1; \
	tx_timeout(dev); \
    } } while (0)
#define dev_kfree_skb_irq(skb)	DEV_KFREE_SKB(skb)
#else
#define netif_mark_up(dev)	do { } while (0)
#define netif_mark_down(dev)	do { } while (0)
#define tx_timeout_check(d,h)	netif_stop_queue(d)
#endif

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,3,99))
#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,2,0))
/* A nasty hack: we only need to set up dev->init on 2.0.* kernels,
   and this is a convenient place to bury it */
#define init_dev_name(dev, node) \
  do { static int __dummy(struct net_device *dev) { return 0; } \
    dev->init = &__dummy; (dev)->name = (node).dev_name; \
  } while (0)
#else
#define init_dev_name(dev, node) (dev)->name = (node).dev_name
#endif
#define copy_dev_name(node, dev) do { } while (0)
#else
#define init_dev_name(dev, node) do { } while (0)
#define copy_dev_name(node, dev) strcpy((node).dev_name, (dev)->name)
#endif

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,4,3))
static inline struct net_device *alloc_etherdev(int sz)
{
    struct net_device *dev;
    sz += sizeof(*dev) + 31;
    if (!(dev = kmalloc(sz, GFP_KERNEL)))
	return NULL;
    memset(dev, 0, sz);
    if (sz)
	dev->priv = (void *)(((long)dev + sizeof(*dev) + 31) & ~31);
    ether_setup(dev);
    return dev;
}
#endif

#endif /* _COMPAT_NETDEVICE_H */
