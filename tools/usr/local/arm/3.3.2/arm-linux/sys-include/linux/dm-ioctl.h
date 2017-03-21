/*
 * Copyright (C) 2001 Sistina Software (UK) Limited.
 *
 * This file is released under the LGPL.
 */

#ifndef _LINUX_DM_IOCTL_H
#define _LINUX_DM_IOCTL_H

#include "device-mapper.h"

/*
 * Implements a traditional ioctl interface to the device mapper.
 */

/*
 * All ioctl arguments consist of a single chunk of memory, with
 * this structure at the start.  If a uuid is specified any
 * lookup (eg. for a DM_INFO) will be done on that, *not* the
 * name.
 */
struct dm_ioctl {
	char version[16];

	unsigned long data_size;	/* total size of data passed in
					 * including this struct */

	unsigned long data_start;	/* offset to start of data
					 * relative to start of this struct */

	char name[DM_NAME_LEN];	/* device name */

	unsigned int target_count;	/* in/out */
	unsigned int open_count;	/* out */
	unsigned int flags;	/* in/out */

	__kernel_dev_t dev;	/* in/out */

	char uuid[DM_UUID_LEN];	/* unique identifier for
				 * the block device */
};

/*
 * Used to specify tables.  These structures appear after the
 * dm_ioctl.
 */
struct dm_target_spec {
	int32_t status;		/* used when reading from kernel only */
	unsigned long long sector_start;
	unsigned long long length;

	char target_type[DM_MAX_TYPE_NAME];

	unsigned long next;	/* offset in bytes to next target_spec */

	/*
	 * Parameter string starts immediately after this object.
	 * Be careful to add padding after string to ensure correct
	 * alignment of subsequent dm_target_spec.
	 */
};

/*
 * Used to retrieve the target dependencies.
 */
struct dm_target_deps {
	unsigned int count;

	__kernel_dev_t dev[0];	/* out */
};

#define DM_IOCTL 0xfd

enum {
	DM_CREATE_CMD = 0,
	DM_REMOVE_CMD,
	DM_SUSPEND_CMD,
	DM_RELOAD_CMD,
	DM_INFO_CMD,
	DM_RENAME_CMD,
	DM_VERSION_CMD,
	DM_DEPS_CMD,
	DM_REMOVE_ALL_CMD,
	DM_GET_STATUS_CMD,
	DM_WAIT_EVENT_CMD
};

#define DM_CREATE       _IOWR(DM_IOCTL, DM_CREATE_CMD, struct dm_ioctl)
#define DM_REMOVE       _IOW(DM_IOCTL, DM_REMOVE_CMD, struct dm_ioctl)
#define DM_SUSPEND      _IOW(DM_IOCTL, DM_SUSPEND_CMD, struct dm_ioctl)
#define DM_RELOAD       _IOW(DM_IOCTL, DM_RELOAD_CMD, struct dm_ioctl)
#define DM_INFO         _IOWR(DM_IOCTL, DM_INFO_CMD, struct dm_ioctl)
#define DM_RENAME       _IOW(DM_IOCTL, DM_RENAME_CMD, struct dm_ioctl)
#define DM_VERSION      _IOWR(DM_IOCTL, DM_VERSION_CMD, struct dm_ioctl)
#define DM_DEPS         _IOWR(DM_IOCTL, DM_DEPS_CMD, struct dm_ioctl)
#define DM_REMOVE_ALL   _IOR(DM_IOCTL, DM_REMOVE_ALL_CMD, struct dm_ioctl)
#define DM_GET_STATUS   _IOWR(DM_IOCTL, DM_GET_STATUS_CMD, struct dm_ioctl)
#define DM_WAIT_EVENT   _IOR(DM_IOCTL, DM_WAIT_EVENT_CMD, struct dm_ioctl)

#define DM_IOCTL_VERSION "0.94"
#define DM_DRIVER_VERSION "0.94.11-ioctl (2002-05-20)"

/* Status bits */
#define DM_READONLY_FLAG	0x00000001
#define DM_SUSPEND_FLAG		0x00000002
#define DM_EXISTS_FLAG		0x00000004
#define DM_PERSISTENT_DEV_FLAG	0x00000008

/* Flag passed into ioctl STATUS command to get table information
   rather than current status */
#define DM_STATUS_TABLE_FLAG	0x00000010

#endif				/* _LINUX_DM_IOCTL_H */
