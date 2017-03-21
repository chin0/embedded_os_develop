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

/*  ********************************************************************
 *  Boot Loader Configuration
 *  Change this when the board configuration changes
 *       
 *  Copyright 1999 Compaq Computer Corporation
 *  All Rights Reserved
 * 
 *  ********************************************************************
 */

#include <linux/config.h>
#include <linux/version.h>

//#define BOOTLDR_VERSION ((VERSION_MAJOR << 16)|(VERSION_MINOR << 8)|(VERSION_MICRO<<0))
#define BOOTLDR_VERSION LINUX_VERSION_CODE

#undef CACHE_ENABLED	
#undef ICACHE_ENABLED	

#ifdef CACHE_ENABLED
#define DCACHE_ON 1
#else
#define DCACHE_ON 0
#endif

#ifdef ICACHE_ENABLED
#define ICACHE_ON 1
#else
#define ICACHE_ON 0
#endif


/* magic numbers */
#define BOOTLDR_MAGIC      0x646c7462        /* btld: marks a valid bootldr image */
#define PARROT_MAGIC_0 0xEA0003FE
#define PARROT_MAGIC_FFC 0x0
#define PARROT_MAGIC_FFC_ALT 0xFFFFFFFF
#define PARROT_MAGIC_1000 0xE321F0D3
#define KERNELIMG_MAGIC    0x5A5ABEEF   /* kernel image magic number - used to tell us if we have a valid kernel image in flash */
#define ELF_MAGIC		(('E' << 24) | ('L' << 16) | ('F' << 8) | 0x7f)
#define CATS_ZIMAGE_MAGIC  0xE3A00000
#define SKIFF_ZIMAGE_MAGIC 0xE1A00000
#define SKIFF_IMAGE_MAGIC  0xE3300000
#define LINUX_ZIMAGE_MAGIC 0x016f2818 
#define QNX_IMAGE_MAGIC    0x00FF7EEB
#define NETBSD_KERNEL_MAGIC 0x0000000       
#define WINCE_PARTITION_MAGIC_1 0xea0003fe
#define WINCE_PARTITION_LONG_0 0xf 
#define WINCE_PARTITION_MAGIC_2 0x43454345

#define H5400_FIRMWARE_MAGIC_40 0x43454345
#define H5400_FIRMWARE_MAGIC_1000 0xEA000026


/* handy sizes */
#define SZ_1K                           0x00000400
#define SZ_4K                           0x00001000
#define SZ_16K                          0x00004000
#define SZ_32K                          0x00008000
#define SZ_48K                          0x0000C000
#define SZ_64K                          0x00010000
#define SZ_256K                         0x00040000
#define SZ_512K                         0x00080000

#define SZ_1M                           0x00100000
#define SZ_2M                           0x00200000
#define SZ_3M                           0x00300000
#define SZ_4M                           0x00400000
#define SZ_8M                           0x00800000
#define SZ_16M                          0x01000000
#define SZ_32M                          0x02000000
#define SZ_64M                          0x04000000
#define SZ_128M                         0x08000000
#define SZ_256M                         0x10000000
#define SZ_512M                         0x20000000
#define SZ_1G                           0x40000000
#define SZ_2G                           0x80000000

#define PAGE_MASK                       (4096-1)

/* CPU Architecture */
/* this is defined based on definition of CONFIG_ARCH in config.local.mk */

/* ; Memory sizes
 */
#if defined(CONFIG_ARCH_PERSONAL_SERVER) 
#  define GPIO_BASE                       0x41800000
#endif


#define CONFIG_DRAM_BANK1
#define	CONFIG_DRAM_BANK1_TEST	

/* Memory Maps and bootblock header info structs */
#if defined(CONFIG_ARCH_SA1100)
#define FLASH_BASE		0x00000000
#define FLASH_REGION_SIZE       SZ_32M	 /*  max amount of Flash onboard */
#define DRAM_BASE               0xC0000000
#define DRAM_BASE0              0xC0000000
#define DRAM_SIZE0              SZ_32M
#define DRAM_BASE1              0xC8000000
#define UNCACHED_FLASH_BASE	0x50000000
#define CACHE_FLUSH_SIZE	SZ_16K
#define CACHE_FLUSH_BASE	0xE0000000
#define DRAM_MAX_BANKS          4
#define DRAM_MAX_BANK_SIZE	SZ_128M

#elif defined(CONFIG_ARCH_PXA)
#define FLASH_BASE		0x00000000
#define FLASH_REGION_SIZE       SZ_32M	 /*  max amount of Flash onboard */
#define DRAM_BASE               0xA0000000
#define DRAM_BASE0              0xA0000000
#define DRAM_SIZE0              SZ_64M
#define DRAM_BASE1              0xA4000000
#define UNCACHED_FLASH_BASE	0x50000000
#define CACHE_FLUSH_SIZE	SZ_32K
#define CACHE_FLUSH_BASE	DRAM_BASE0+DRAM_SIZE0
#define DRAM_MAX_BANKS          4
#define DRAM_MAX_BANK_SIZE	SZ_64M

// I can't find a define for CONFIG_SA110 in linux/autoconf.h, so I'll leave it out.
// #elif defined(CONFIG_SA110)
// #define FLASH_BASE              0x41000000
// #define FLASH_REGION_SIZE       SZ_16M	 /*  max amount of Flash+GPIO onboard */
// #define DRAM_BASE               0
// #define DRAM_BASE0              0
// #define DRAM_SIZE0              SZ_16M
// #define UNCACHED_FLASH_BASE     0x21000000
// #define CACHE_FLUSH_SIZE        SZ_16K
// #define CACHE_FLUSH_BASE        0x78000000
// #define DRAM_MAX_BANKS          4

#endif


/* virtual address where kernel image is copied from flash or serial port */
#ifdef CONFIG_ARCH_PERSONAL_SERVER
#  define VKERNEL_BASE 		0x10000000L
#else
#  define VKERNEL_BASE 		DRAM_BASE0
#endif

#if 0
#  define MEMCLK_HZ_OVERRIDE              48000000
#elif 0
#  define MEMCLK_HZ_OVERRIDE              33333333
#elif 0
#  define MEMCLK_HZ_OVERRIDE              48000000
#else
#  undef MEMCLK_HZ_OVERRIDE
#endif

#define DRAM_32MB
#ifdef DRAM_32MB
#  define DRAM_SIZE                       SZ_32M	 /*  amount of SDRAM onboard */
#else
#  define DRAM_SIZE                       SZ_16M	 /*  amount of SDRAM onboard */
#endif

#define LINUX_PAGE_SIZE			SZ_4K
#define LINUX_PAGE_SHIFT		12

#define PCI_WINDOW_SIZE                 0x3FC0000 /* corresponds to 64 MB */



/*  a place to put the bootldr when we're programming flash
 */
#define FLASH_IMG_SIZE                  SZ_1M  /*  this cannot change!! corresponds to one MMU segment */
#define FLASH_IMG_START                 (DRAM_BASE0 + DRAM_SIZE0 - SZ_2M)
#define HEAP_SIZE                       SZ_4M
#define HEAP_START                      (FLASH_IMG_START - HEAP_SIZE)
#define BOOT_DATA_SIZE                  SZ_32K /*   memory used for the RW data in bootldr */
#define BOOT_DATA_START                 (HEAP_START - BOOT_DATA_SIZE)
#define MMU_TABLE_SIZE                  SZ_16K
#define MMU_TABLE_START                 (BOOT_DATA_START-MMU_TABLE_SIZE)
#define STACK_SIZE                      SZ_16K	 /*  size of C stack */
#define STACK_BASE                      (MMU_TABLE_START-STACK_SIZE)
	
/* ; PCI configuration space
 */
#define PCI_CONFIGURATION_BASE          0x7bc00000
#define USB_CONFIGURATION_OFFSET        0x800
#define USB_CONFIGURATION_BASE          (PCI_CONFIGURATION_BASE+USB_CONFIGURATION_OFFSET)
	
/* ; PCI memory space 
 */
#if (SZ_32M >= DRAM_SIZE)
#  define USB_MEMORY_BASE			SZ_32M
#else
#  define USB_MEMORY_BASE			DRAM_SIZE
#endif
#define CARDBUS_SOCKET1_MEMORY_BASE     (USB_MEMORY_BASE + SZ_1M)
#define CARDBUS_SOCKET2_MEMORY_BASE     (CARDBUS_SOCKET1_MEMORY_BASE + SZ_1M)
#define ETHERNET_MEMORY_BASE		CARDBUS_SOCKET2_MEMORY_BASE + SZ_1M
#define ETHERNET_IO_BASE		0x300


/* ; SDRAM Mode Register Settings
 */
#define SDRAM_MODE_WM                   (0<<9)   /*   burst writes */
#ifdef SDRAM_TCAS_2CYCLES
#  define SDRAM_MODE_LTMODE		(2<<4)   /*  TCAS is 2 cycles */
#else
#  define SDRAM_MODE_LTMODE               (3<<4)   /*   TCAS is 3 cycles */
#endif
#define SDRAM_MODE_BT                   (0<<3)   /*   sequential */
#define SDRAM_MODE_BL                   (2)      /*  4 cycle bursts */

	
/* ; SDRAM timings -- change if we use different memory chips between revs.
 * ; See page 7-31/32 of the 21285 datasheet for details
 */
#define SDRAM_TRP                       0
#define SDRAM_TDAL                      (0<<2)	 /*  0=2,1=3,2=4,3=5 cycles */
#define SDRAM_TRCD                      (2<<4)	 /*  2=2 cycles, 3=3 cycles */
#ifdef SDRAM_TCAS_2CYCLES
#  define SDRAM_TCAS			(2<<6)   /* 2=2 cycles, 3=3 cycles */
#else
#  define SDRAM_TCAS                      (3<<6)   /*  2=2 cycles, 3=3 cycles */
#endif
#define SDRAM_TRC                       (1<<8)	 /*  1=4 cycles */
#define SDRAM_CMD_DRV_TIME              (0<<11)	 /*  0=same  cycle */
#define SDRAM_PARITY_ENABLE             (1<<12)	 /*  0=no parity */
#define SDRAM_SA110_PRIME               (0<<13)	 /*  0=don't drive parity info */
#define SDRAM_TREF                      (23<<16)  /*  wait 23*32 cycles before issuing autorefresh command (4096 refreshes / 64ms for Skiff SDRAM */


/* ; SDRAM Address and Size Register Settings - change for diff. mem loadouts
 * ; See page 7-33 of the 21285 datasheet for details
 */
#define SDRAM_ARRAY0_ARRAYSIZE          5	 /*  16 MB */
#define SDRAM_ARRAY0_ADDRMULTIPLEX      (4<<4)	 /*  16 MB (see Table 4-1) */
#define SDRAM_ARRAY0_ARRAYBASE          (0x00<<20) /*  locate at 0x0000 */
#define SDRAM_ARRAY0_ADDRSIZE           (SDRAM_ARRAY0_ARRAYSIZE|\
                                        SDRAM_ARRAY0_ADDRMULTIPLEX|\
					SDRAM_ARRAY0_ARRAYBASE)

#ifdef DRAM_32MB
#  define SDRAM_ARRAY1_ARRAYSIZE          5	 /*  16 MB */
#  define SDRAM_ARRAY1_ADDRMULTIPLEX      (4<<4)	 /*  16 MB (see Table 4-1) */
#  define SDRAM_ARRAY1_ARRAYBASE          (0x10<<20) /*  locate at 0x01000000 */
#  define SDRAM_ARRAY1_ADDRSIZE           (SDRAM_ARRAY1_ARRAYSIZE|\
                                          SDRAM_ARRAY1_ADDRMULTIPLEX|\
  					SDRAM_ARRAY1_ARRAYBASE)
#else
#  define SDRAM_ARRAY1_ADDRSIZE           0	 /*  array disabled */
#endif

#define SDRAM_ARRAY2_ADDRSIZE           0	 /*  array disabled */
#define SDRAM_ARRAY3_ADDRSIZE           0	 /*  array disabled */

/*  Flash Timing
 */
#if 1 || (MEMCLK_HZ > 33000000)
/* these settings work for both 33MHz, 48MHz and 60MHz Memclk */
#  define FLASH_ACCESS_TIME               6
#  define FLASH_BURST_TIME                6
#  define FLASH_TRISTATE_TIME             5
#else
#  define FLASH_ACCESS_TIME               3
#  define FLASH_BURST_TIME                3
#  define FLASH_TRISTATE_TIME             2
#endif	
/* UART_H_UBRLCR                   EQU     0x60	; no BRK,no parity,1 stop bit,
 *  only use top entry in FIFO,
 *  8 data bits
 */
#define UART_H_UBRLCR                   0x70	 /*  no BRK,no parity,1 stop bit, */
/*  use all of FIFO,8 data bits
 * UART_H_UBRLCR			EQU	0x78	; no BRK,no parity,2 stop bits,
 *  use all of FIFO, 8 data bits
 * UART_H_UBRLCR			EQU	0x7A	; 8 O 2, NO BRK, use all FIFO
 */

/*  UART baudrate settings. formula is (fclk/4/16/baudrate - 1),
 *  where fclk = 33000000 (33 MHZ) or 48MHz
 */

/*#if defined(CONFIG_SA110)
//#define UART_BAUD_RATE                  57600	 / *  baud rate * /
//#elif defined(CONFIG_SA1100) */
#if defined (CONFIG_ARCH_SA1100)
#  define UART_BAUD_RATE                  115200	 /*  baud rate */
#elif defined(CONFIG_ARCH_PXA)
#  define UART_BAUD_RATE                  115200	 /*  baud rate */
#endif

#ifdef CONFIG_ARCH_PERSONAL_SERVER
#  define UART_UBRLCR_33MHZ                     ((33333333 / 64 / UART_BAUD_RATE)-1)
#  define UART_L_UBRLCR_33MHZ                   (UART_UBRLCR_33MHZ & 0xFF)
#  define UART_M_UBRLCR_33MHZ                   ((UART_UBRLCR_33MHZ >> 8) & 0xFF)
#  define UART_UBRLCR_48MHZ                     ((48000000 / 64 / UART_BAUD_RATE)-1)
#  define UART_L_UBRLCR_48MHZ                   (UART_UBRLCR_48MHZ & 0xFF)
#  define UART_M_UBRLCR_48MHZ                   ((UART_UBRLCR_48MHZ >> 8) & 0xFF)
#  define UART_UBRLCR_60MHZ                     ((60000000 / 64 / UART_BAUD_RATE)-1)
#  define UART_L_UBRLCR_60MHZ                   (UART_UBRLCR_60MHZ & 0xFF)
#  define UART_M_UBRLCR_60MHZ                   ((UART_UBRLCR_60MHZ >> 8) & 0xFF)
#endif

/* //#ifdef CONFIG_SA110
//#  define RXSTAT_FRAME_ERROR              1	 /*  bit zero set on frame error * /
//#  define RXSTAT_PARITY_ERROR             2	 /*  bit one set on parity error * /
//#  define RXSTAT_OVERRUN_ERROR            4      /*  bit two set on FIFO overrun * /
//#  define UART_TX_BUSY                    (1<<3)   /*  TX FIFO nonempty and UART enabled * /
//#  define UART_TX_FIFO_BUSY               (1<<5)         /*  TX FIFO busy flag * /
//#  define UART_RX_FIFO_EMPTY              (1<<4)         /*  1 if no data * /
//#endif
*/
/*
 * 
 */

#ifdef CONFIG_ARCH_PERSONAL_SERVER
/* 
 * Skiff V2 has GPIO registers in the range with Flash.  It seemed like a
 * good idea at the time.  The registers are implemented in a Xilinx CPLD.
 *
 * The first 8MB of the range is flash, then the registers appear.  There
 * are two 32-bit registers, mapped in first as a write port, then as a
 * read port.  While doing to this region the write-enable (WE) is also
 * asserted for some reason, so there is a separate write port and read
 * port.  Reading from the write port will update the registers with
 * spurious values.
 *
 * GPIO_REG0 controls the actual GPIO pins and output enables (direction).
 * GPIO_REG1 controls the LEDs and Piezo.  5 of the LED's are multiplexed
 * between the LED register and the 5 LED signals from the ethernet
 * controller.  The multiplexer is controlled by LEDMODE.
 *  
 * System configuration information also appears in the upper 16 bits of
 * GPIO_REG1.
 */

#  define WRITE_GPIO_REG0(val)  *(volatile long *)(GPIO_BASE + 0) = (val)
#  define WRITE_GPIO_REG1(val)  *(volatile long *)(GPIO_BASE + 4) = (val)
#  define READ_GPIO_REG0()      *(volatile long *)(GPIO_BASE + 8)
#  define READ_GPIO_REG1()      *(volatile long *)(GPIO_BASE + 12)

#  define GPIO_REG0_GPIO_MASK    (0x7FF << 0)
#  define GPIO_REG0_GPIO_OE_MASK (0x7FF << 16)

#  define GPIO_REG1_LEDMASK      0xFF
#  define GPIO_REG1_PIEZO        (1 << 8)
#  define GPIO_REG1_ETHLNK       (1 << 9)
#  define GPIO_REG1_ETHTX        (1 << 10)
#  define GPIO_REG1_ETHRX        (1 << 11)
#  define GPIO_REG1_ETHLED2      (1 << 12)
#  define GPIO_REG1_ETHLED4      (1 << 13)
#  define GPIO_REG1_LEDMODE      (1 << 15)
#  define GPIO_REG1_LEDMODE_ETH  (0 << 15)    /* if LEDMODE is not set, then first 5 LED's controlled by ETH */
#  define GPIO_REG1_LEDMODE_REG  (1 << 15)    /* if LEDMODE is set, then all LED's controlled by ledreg */

/**
 * system rev appears in bits 31..16 at GPIO[12]
 */
#  define SYSTEM_REV_MASK 0x07FF0000
#  define SYSTEM_REV_VERSION_MASK (0x3F << 21)
#  define SYSTEM_REV_MAJOR_MASK   (0x38 << 21)
#  define SYSTEM_REV_MINOR_MASK   (0x07 << 21)

#  define SYSTEM_REV_MINOR_A      (1 << 21)
#  define SYSTEM_REV_MINOR_B      (2 << 21)
#  define SYSTEM_REV_MINOR_C      (3 << 21)
#  define SYSTEM_REV_MINOR_D      (4 << 21)
#  define SYSTEM_REV_MINOR_E      (5 << 21)

#  define SYSTEM_REV_SKIFF_V1     (1 << 24)
#  define SYSTEM_REV_SKIFF_V2     (2 << 24)

#  define SYSTEM_REV_SKIFF_V2A    (SYSTEM_REV_SKIFF_V2|SYSTEM_REV_MINOR_A)
#  define SYSTEM_REV_SKIFF_V2B    (SYSTEM_REV_SKIFF_V2|SYSTEM_REV_MINOR_B)

#  define SYSTEM_REV_MEMCLK_MASK  (0x003 << 16)
#  define SYSTEM_REV_MEMCLK_33MHZ (0x001 << 16)
#  define SYSTEM_REV_MEMCLK_48MHZ (0x002 << 16)
#  define SYSTEM_REV_MEMCLK_60MHZ (0x003 << 16)

#endif /* CONFIG_ARCH_PERSONAL_SERVER */

/*
 * bootldr capabilities
 * Stored at offset 0x30 into the boot flash.
 */

#define BOOTCAP_WAKEUP			(1<<0)
#define BOOTCAP_PARTITIONS 		(1<<1) /* partition table stored in params sector */
#define BOOTCAP_PARAMS_AFTER_BOOTLDR 	(1<<2) /* params sector right after bootldr sector(s), else in last sector */
#define BOOTCAP_H3800_SUPPORT 		(1<<3) /* 3800 ipaqs require special support this bit is read by BootBlaster and eventually by load bootldr*/
#define BOOTCAP_H3900_SUPPORT 		(1<<4) 
#define BOOTCAP_JORNADA56X_SUPPORT 	(1<<5) /* this is being folded into the ipaq configuration */
#define BOOTCAP_PIC     		(1<<6) /* position independent bootldr */
#define BOOTCAP_H5400_SUPPORT 		(1<<7) 

#if defined(CONFIG_ARCH_H3900)
#  define	BOOTLDR_CAPS	(BOOTCAP_WAKEUP|BOOTCAP_PARTITIONS|BOOTCAP_PARAMS_AFTER_BOOTLDR | BOOTCAP_H3900_SUPPORT | BOOTCAP_H5400_SUPPORT | BOOTCAP_PIC)
#elif defined(CONFIG_ARCH_H5400)
#  define	BOOTLDR_CAPS	(BOOTCAP_WAKEUP|BOOTCAP_PARTITIONS|BOOTCAP_PARAMS_AFTER_BOOTLDR | BOOTCAP_H5400_SUPPORT | BOOTCAP_PIC)
#else /* CONFIG_MACH_IPAQ */
#  define	BOOTLDR_CAPS	(BOOTCAP_WAKEUP|BOOTCAP_PARTITIONS|BOOTCAP_PARAMS_AFTER_BOOTLDR | BOOTCAP_H3800_SUPPORT | BOOTCAP_JORNADA56X_SUPPORT)
#endif

#define	bootcap_canwake(caps)	((caps) & BOOTCAP_WAKEUP)

/*    END */

