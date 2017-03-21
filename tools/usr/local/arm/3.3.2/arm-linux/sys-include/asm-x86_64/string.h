#ifndef _X86_64_STRING_H_
#define _X86_64_STRING_H_

#ifdef __KERNEL__
#include <linux/config.h>

#define struct_cpy(x,y) (*(x)=*(y))

#define __HAVE_ARCH_MEMCMP
#define __HAVE_ARCH_STRLEN

#define memset __builtin_memset
#define memcpy __builtin_memcpy
#define memcmp __builtin_memcmp
#define strlen __builtin_strlen

extern char *strstr(const char *cs, const char *ct);

#endif /* __KERNEL__ */

#endif
