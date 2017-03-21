/*
 *  July 5, 2000    Architecture defintions
 *
 *                   -- George France <france@crl.dec.com>
 */

/* ARM CPU Identifier Register */
#define ARM_COMP_MASK		(0xff000000)
#define ARM_COMP_SHIFT		24
#define ARM_ARCH_MASK		(0x00ff0000)
#define ARM_ARCH_SHIFT          16
#define ARM_PART_MASK		(0x0000fff0)
#define ARM_PART_SHIFT          4  
#define ARM_REVISION_MASK	(0x00ff0000)
#define ARM_REVISION_SHIFT      0


#define ARM_ID_SA110		(0x4401a100)
#define ARM_ID_SA1100		(0x4401a110)
#define ARM_ID_SA1110		(0x6901b110)
#define ARM_ID_PXA250		(0x69052905)

#define ARM_ID_COMP_DEC		(0x44)
#define ARM_ID_COMP_INTEL	(0x69)
#define ARM_ID_ARCH_SA		(0x01)
#define ARM_ID_ARCH_XSCALE	(0x05)
#define ARM_ID_PART_SA110	(0xa10)
#define ARM_ID_PART_SA1100	(0xa11)
#define ARM_ID_PART_SA1110	(0xb11)
#define ARM_ID_PART_PXA250	(0x290)

/* There can be 255 platforms       ( 8 bit)
   Each platform can have 255 cpus  ( 8 bit)
   Each cpu can have 65355 machines (16 bit) */

#define ARM_PLATFORM   1
#define ARM_SA110_CPU   1
#define ARM_SA1100_CPU  2
#define ARM_SA1110_CPU  3
#define ARM_PXA250_CPU  4

#define MIPS_PLATFORM  2

#define SKIFF_MACH      1
#define ITSY_MACH       2 
#define IPAQ_MACH      3
#define ASSABET_MACH	4
#define SPOT_MACH       5
#define JORNADA720_MACH	6
#define GATOR_MACH	7
#define JORNADA56X_MACH 8
#define H3900_MACH      9
#define PXA1_MACH	10
#define H5400_MACH      11
#define BALLOON_MACH	12 /* was 7, replacing gator  */

#define ASSABET_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | ASSABET_MACH)
#define BALLOON_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | BALLOON_MACH)
#define IPAQ_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | IPAQ_MACH)
#define JORNADA720_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | JORNADA720_MACH)
#define SKIFF_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA110_CPU  << 16) | SKIFF_MACH )
#define SPOT_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | SPOT_MACH)
#define GATOR_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | GATOR_MACH)
#define JORNADA56X_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_SA1110_CPU << 16) | JORNADA56X_MACH)
#define H3900_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_PXA250_CPU << 16) | H3900_MACH)
#define PXA1_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_PXA250_CPU << 16) | PXA1_MACH)
#define H5400_ARCHITECTURE_MAGIC ((ARM_PLATFORM << 24) | (ARM_PXA250_CPU << 16) | H5400_MACH)

#ifdef CONFIG_MACH_ASSABET
#  define ARCHITECTURE_MAGIC ASSABET_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_BALLOON
#  define ARCHITECTURE_MAGIC BALLOON_ARCHITECTURE_MAGIC
#endif
#if 1
#  define ARCHITECTURE_MAGIC IPAQ_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_JORNADA720
#  define ARCHITECTURE_MAGIC JORNADA720_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_JORNADA56X
#  define ARCHITECTURE_MAGIC JORNADA56X_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_SKIFF
#  define ARCHITECTURE_MAGIC SKIFF_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_SPOT
#  define ARCHITECTURE_MAGIC SPOT_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_GATOR
#  define ARCHITECTURE_MAGIC GATOR_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_H3900
#  define ARCHITECTURE_MAGIC H3900_ARCHITECTURE_MAGIC
#endif
#ifdef CONFIG_MACH_PXA1
#  define ARCHITECTURE_MAGIC PXA1_ARCHITECTURE_MAGIC
#endif
#if defined(CONFIG_MACH_H5400) && !defined(ARCHITECTURE_MAGIC)
#  define ARCHITECTURE_MAGIC H5400_ARCHITECTURE_MAGIC
#endif