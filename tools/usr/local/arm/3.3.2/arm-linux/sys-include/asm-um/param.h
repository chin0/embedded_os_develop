#ifndef _UM_PARAM_H
#define _UM_PARAM_H

#ifndef HZ
#define HZ 20
#endif

#define hz_to_std(a) (((a)*HZ)/100)

#define EXEC_PAGESIZE   4096

#ifndef NGROUPS
#define NGROUPS         32
#endif

#ifndef NOGROUP
#define NOGROUP         (-1)
#endif

#define MAXHOSTNAMELEN  64      /* max length of hostname */

#ifdef __KERNEL__
# define CLOCKS_PER_SEC 100     /* frequency at which times() counts */
#endif

#endif
