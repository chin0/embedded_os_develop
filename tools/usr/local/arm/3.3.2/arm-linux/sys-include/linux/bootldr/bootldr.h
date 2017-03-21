/****************************************************************************/
/* Copyright 2000 Compaq Computer Corporation.                              */
/*                                           .                              */
/* Copying or modifying this code for any purpose is permitted,             */
/* provided that this copyright notice is preserved in its entirety         */
/* in all copies or modifications.  COMPAQ COMPUTER CORPORATION             */
/* MAKES NO WARRANTIES, EXPRESSED OR IMPLIED, AS TO THE USEFULNESS          */
/* OR CORRECTNESS OF THIS CODE OR ITS FITNESS FOR ANY PARTICULAR            */
/* PURPOSE.                                                                 */
/****************************************************************************/
/*
 * bootldr.h
 */
#ifndef _BOOTLDR_H_
#define _BOOTLDR_H_

#include <linux/types.h>

#define isblank(a) ( ( a == ' ' ) || ( a == '\t' ) )
static inline int isalpha(const char c)
{
    if (((c == ' ') || (c == '\t')))
        return 1;
    else
        return 0;

}


static inline int isdigit(const char c)
{
    if (((c >= '0') && (c <= '9')))
        return 1;
    else
        return 0;

}

static inline int isalnum(const char c)
{
    return (isdigit(c) || isalpha(c));


}


/* defined for release candidates to disable certain functions */
#define RELEASE

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef void *vaddr_t;
typedef unsigned long paddr_t;
typedef unsigned long pd_entry_t;

typedef void (*vfuncp)(void);

#define CTL_CH(c)	((c) - 'a' + 1)
#define CTL_REG_READ(addr)	    (*(volatile unsigned long *)(addr))
#define CTL_REG_WRITE(addr, val)    (*(volatile unsigned long *)(addr) = (val))

#define CTL_REG_READ_BYTE(addr)	    (*(volatile unsigned char *)(addr))
#define CTL_REG_WRITE_BYTE(addr, val)    (*(volatile unsigned char *)(addr) = (val))

#ifndef TRUE
#define TRUE           1
#endif
#ifndef FALSE
#define FALSE          0
#endif
#ifndef NULL
#define NULL           ((void *) 0)
#endif

/* bootloader delay time */
#define TIMEOUT        350000

#define MAX_BOOTARGS_LEN 2048
/* 21285 CSR Access Macros - use these to peek/poke various 21285 registers */
#define CSR_READ_BYTE(p)		(*(volatile byte *)(CSR_BASE+p))
#define CSR_WRITE_BYTE(p, c)		(*(volatile byte *)(CSR_BASE+p) = c)

/* 21285 PCI memory maps - expected to be configured by NetBSD kernel */
#define DC21285_ARMCSR_VBASE		0xF4000000
#define	DC21285_ARMCSR_VSIZE		0x00100000	/* 1MB */
#define	DC21285_CACHE_FLUSH_VBASE	0xF4100000
#define	DC21285_CACHE_FLUSH_VSIZE	0x00100000	/* 1MB */
#define	DC21285_PCI_IO_VBASE		0xF4200000
#define	DC21285_PCI_IO_VSIZE		0x00100000	/* 1MB */
#define	DC21285_PCI_IACK_VBASE		0xF4300000
#define	DC21285_PCI_IACK_VSIZE		0x00100000	/* 1MB */
#define	DC21285_PCI_TYPE_1_CONFIG_VBASE	0xF5000000
#define	DC21285_PCI_TYPE_1_CONFIG_VSIZE	0x01000000	/* 16MB */
#define	DC21285_PCI_TYPE_0_CONFIG_VBASE	0xF6000000
#define	DC21285_PCI_TYPE_0_CONFIG_VSIZE	0x01000000	/* 16MB */
#define DC21285_PCI_MEM_VBASE		0xF7000000
#define DC21285_PCI_MEM_VSIZE		0x09000000	/* 144MB */

/* MMU Level 1 Page Table Constants */
#define MMU_FULL_ACCESS (3 << 10)
#define MMU_DOMAIN      (0 << 5)
#define MMU_SPECIAL     (0 << 4)
#define MMU_CACHEABLE   (1 << 3)
#define MMU_BUFFERABLE  (1 << 2)
#define MMU_SECTION     (2)
#define MMU_SECDESC  (MMU_FULL_ACCESS | MMU_DOMAIN | \
                      MMU_SPECIAL | MMU_SECTION)

extern unsigned long *mmu_table;

/*
 * Points to the beginning of where the bootldr is in memory (beginning of flash, beginning of dram, etc.)
 * For position independence
 */
extern long bootldr_start;


/*
flash memory region map. This basically splits the bootblocks of the
flash as folows:

32K - bootloader
32K - flash variables/data
*/

#if DeadCode
#define BOOTLDR_SECTOR          0 /* and 1 and 2 too */
#define BOOTLDR_OFFSET          0
#define BOOTLDR_SIZE            SZ_48K
#define BOOTLDR_START           (FLASH_BASE+BOOTLDR_OFFSET)
#define BOOTLDR_END             (BOOTLDR_START+BOOTLDR_SIZE)
#define VBOOTLDR_START          (UNCACHED_FLASH_BASE+BOOTLDR_OFFSET)
#define VBOOTLDR_END            (VBOOTLDR_START+BOOTLDR_SIZE)
#endif /* DeadCode */

enum bootblk_flags {
    BB_NONE = 0,
    BB_RUN_FROM_RAM = 1
};

struct bootblk_command {
    const char *cmdstr;
    void (*cmdfunc)(int argc, const char **);
    const char *helpstr;
    enum bootblk_flags flags;
};

#define DEFAULT_XMODEM_BLOCK_SIZE 1024            /* default size of transmit blocks */
#define MAX_XMODEM_BLOCK_SIZE	1024              /* maximum size of transmit blocks */
extern long xmodem_block_size;

/* must match definition in linux/include/asm/mach-types.h */
#define MACH_TYPE_CATS 6
#define MACH_TYPE_PERSONAL_SERVER 17
#define MACH_TYPE_SA1100 16
#define MACH_TYPE_H3600                22
#define MACH_TYPE_H3100                136
#define MACH_TYPE_H3800                137
#define MACH_TYPE_H3600_ASCII          "22"
#define MACH_TYPE_H3100_ASCII          "136"
#define MACH_TYPE_H3800_ASCII          "137"
#define MACH_TYPE_ASSABET 25
#define MACH_TYPE_JORNADA720 48
#define MACH_TYPE_OMNIMETER 49
#define MACH_TYPE_SPOT 53
#define MACH_TYPE_GATOR 103
#define MACH_TYPE_JORNADA56X 167
#define MACH_TYPE_H3900 203
#define MACH_TYPE_PXA1  204
#define MACH_TYPE_H5400 220

#ifdef CONFIG_MACH_ASSABET
#define MACH_TYPE MACH_TYPE_ASSABET
#endif
#ifdef CONFIG_MACH_IPAQ
#define MACH_TYPE MACH_TYPE_H3600
#endif
#ifdef CONFIG_MACH_JORNADA720
#define MACH_TYPE MACH_TYPE_JORNADA720
#endif
#ifdef CONFIG_MACH_JORNADA56X
#define MACH_TYPE MACH_TYPE_JORNADA56X
#endif
#ifdef CONFIG_OMNIMETER
#define MACH_TYPE MACH_TYPE_OMNIMETER
#endif
#ifdef CONFIG_MACH_SKIFF
#define MACH_TYPE MACH_TYPE_PERSONAL_SERVER
#endif
#ifdef CONFIG_MACH_SPOT
#define MACH_TYPE MACH_TYPE_SPOT
#endif
#ifdef CONFIG_MACH_GATOR
#define MACH_TYPE MACH_TYPE_GATOR
#endif
#ifdef CONFIG_MACH_H3900
#define MACH_TYPE MACH_TYPE_H3900
#endif
#ifdef CONFIG_PXA1
#define MACH_TYPE MACH_TYPE_PXA1
#endif
#ifdef CONFIG_MACH_IPAQ3
#define MACH_TYPE MACH_TYPE_IPAQ3
#endif

void initialize_by_mach_type(void);
#define machine_is_h3600() (param_mach_type.value == MACH_TYPE_H3600)
#define machine_is_h3100() (param_mach_type.value == MACH_TYPE_H3100)
#define machine_is_h3800() ((param_mach_type.value == MACH_TYPE_H3800) || (*boot_flags_ptr & BF_H3800))
#define machine_is_h3900() ((param_mach_type.value == MACH_TYPE_H3900) || (*boot_flags_ptr & BF_H3900))
#define machine_is_h5400() ((param_mach_type.value == MACH_TYPE_H5400) || (*boot_flags_ptr & BF_H5400))
#define	machine_is_jornada56x()	(param_mach_type.value == MACH_TYPE_JORNADA56X || ((*boot_flags_ptr) & BF_JORNADA56X))


/* External Functions - written in assembler [boot.s] */
void boot(void *bootinfo,long startaddr);
void bootLinux(void *bootinfo, long machine_type, long startaddr);

#ifdef NoLibC
void *memcpy(char *dst, const char *src, long n);
int  memcmp(const char *buf1,const char *buf2, long n);
#endif
unsigned long strtoul(const char *str, char **endptr, int requestedbase);
//char *strchr(const char *str, char c);
// char *strrchr(const char *str, char c);
char *strcat(char *dst, const char *str);
int strcmp(const char *s1, const char *s2);
//int strncmp(const char *s1, const char *s2, int len);
int memmem(const char *haystack,int num1, const char *needle,int num2);
unsigned long strtoul(const char *str, char **endptr, int requestedbase);

void PrintChar(char c, void *uart); 
void putLabeledWord(const char *msg, unsigned long value);
void putHexInt32(unsigned long value);
void putHexInt16(word value);
void putHexInt8(byte value);
void delay_seconds(unsigned long seconds);
void binary_dld(unsigned long img_size, unsigned long img_dest);
void dwordtodecimal(char *buf, unsigned long x);
void hex_dump(unsigned char *data, size_t num);

long get_system_rev(void);
void program_all_eeprom(void);

long enable_caches(int dcache_enabled, int icache_enabled);
void flush_caches(void);
void bootConfigureMMU(void);
void enableMMU(void);
void flashConfigureMMU(unsigned long flash_size);


/* asm routines */
void flushTLB(void);
int asmEnableCaches(int dcache_enabled, int icache_enabled);
void writeBackDcache(unsigned long);
unsigned long readPC(void);
unsigned long readCPR0(void);
unsigned long readCPR1(void);
unsigned long readCPR2(void);
unsigned long readCPR3(void);
unsigned long readCPR4(void);
unsigned long readCPR5(void);
unsigned long readCPR6(void);
unsigned long readCPR7(void);
unsigned long readCPR8(void);
unsigned long readCPR9(void);
unsigned long readCPR10(void);
unsigned long readCPR13(void);
unsigned long readCPR14(void);
unsigned long readCPR15(void);


/* PocketPCSE */
void disableWriteDataCaching(void);



extern void
exec_string(
    char*   buf);

extern int
push_cmd_chars(
    char*   chars,
    int	    len);

#define	BL_ISPRINT(ch)	    (((ch)>=' ') && ((ch) < 128))

extern int
reboot_button_is_enabled(
    void);

extern void
enable_reboot_button(
    void);

extern void
disable_reboot_button(
    void);

extern void
bootldr_goto_sleep(
    void*   pspr);

extern void
print_mem_size(
    char*   hdr,
    long    mem_size);

extern void
bootldr_reset(
	      void);

extern unsigned char amRunningFromRam(void);
#if defined(CONFIG_LOAD_KERNEL)
extern void boot_kernel(const char *root_filesystem_name, 
                        vaddr_t kernel_region_start, size_t kernel_region_size, int argc, const char **argv, int no_copy);
#endif

extern void putstr(const char *s);
int body_testJFFS2(const char *filename,unsigned long *dest);
int body_infoJFFS2(char *partname);
int body_timeFlashRead(char *partname);
long body_p1_load_file(const char *partname,const char *filename,unsigned char *dest);
int body_p1_ls(char *dir,char *partname);
void body_cmpKernels(const char *partname,unsigned long *dstFlash,unsigned long *srcJFFS,unsigned long len);
void body_clearMem(unsigned long num,unsigned short *dst);
unsigned char isWincePartition(unsigned char *p);
unsigned char amRunningFromRam(void);
void print_version_verbose(char* prefix);
void unparseargs(char *argstr, int argc, const char **argv);

#ifdef __QNXNTO__
char *strncpy( char *__s1, const char *__s2, size_t __n );
#endif

typedef unsigned char BOOL;
BOOL isValidBootloader(unsigned long p,unsigned long size);

#endif /* _BOOTLDR_H_ */

