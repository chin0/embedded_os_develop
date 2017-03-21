/*
 *
 * Definitions for Mercury BackPAQ
 *
 * Copyright 2000 Compaq Computer Corporation.
 *
 * Copying or modifying this code for any purpose is permitted,
 * provided that this copyright notice is preserved in its entirety
 * in all copies or modifications.  COMPAQ COMPUTER CORPORATION
 * MAKES NO WARRANTIES, EXPRESSED OR IMPLIED, AS TO THE USEFULNESS
 * OR CORRECTNESS OF THIS CODE OR ITS FITNESS FOR ANY PARTICULAR
 * PURPOSE.
 *
 * Author: Jamey Hicks.
 *
 * Change: 6/8/01   Power management callback interface added.
 *                  Andrew Christian
 * Change: 2/25/02  Added Philips image sensor types
 *                  Wim de Haan
 * Change: 6/30/03  Added backpaq audio registers and constants
 *                  Fae Ghodrat
 *
 */

#ifndef _INCLUDE_BACKPAQ_H_
#define _INCLUDE_BACKPAQ_H_

#include <linux/types.h>
#include <asm/hardware.h>

/********** Device management support **************/

enum {
	H3600_BACKPAQ_SUSPEND,
	H3600_BACKPAQ_RESUME,
	H3600_BACKPAQ_EJECT,
	H3600_BACKPAQ_INSERT
};

typedef int h3600_backpaq_request_t;  /* Mostly mapped directly from pm.h */

enum {
	H3600_BACKPAQ_UNKNOWN_DEV = 0,
	H3600_BACKPAQ_FPGA_DEV,
	H3600_BACKPAQ_CAMERA_DEV,
	H3600_BACKPAQ_AUDIO_DEV,
	H3600_BACKPAQ_ACCEL_DEV,
	H3600_BACKPAQ_GASGAUGE_DEV,
	H3600_BACKPAQ_FLASH_DEV,
};

typedef int h3600_backpaq_dev_t;
struct h3600_backpaq_device;
typedef int (*h3600_backpaq_callback)(struct h3600_backpaq_device *dev, h3600_backpaq_request_t rqst);

struct h3600_backpaq_device {
	h3600_backpaq_dev_t       type;
	unsigned long             id;
	h3600_backpaq_callback    callback;
	void                     *data;

	struct list_head          entry;
};

int                          h3600_backpaq_present( void );
struct h3600_backpaq_device* h3600_backpaq_register_device( h3600_backpaq_dev_t type,
							    unsigned long id,
							    h3600_backpaq_callback callback );
void                         h3600_backpaq_unregister_device(struct h3600_backpaq_device *device);

/********** OEM area of the EEPROM **********/

struct h3600_backpaq_eeprom {
	u8  major_revision;
	u8  minor_revision;
	u8  fpga_version; 
	u8  camera;
	u16 accel_offset_x;
	u16 accel_scale_x;
	u16 accel_offset_y;
	u16 accel_scale_y;
	u32 serial_number;
	u32 flash_start;
	u32 flash_length;
	u32 sysctl_start;
	/* new for backpaq3 */
	u16 cam_accel_offset_x;
	u16 cam_accel_scale_x;
	u16 cam_accel_offset_y;
	u16 cam_accel_scale_y;
	u16 cam_accel_offset_z;
	u16 cam_accel_scale_z;
};

enum {
        BACKPAQ_EEPROM_FPGA_VERTEX_100   = 0,
        BACKPAQ_EEPROM_FPGA_VERTEX_100E  = 1,
        BACKPAQ_EEPROM_FPGA_VERTEX_200E  = 2,
        BACKPAQ_EEPROM_FPGA_VERTEX_300E  = 3,
	BACKPAQ_EEPROM_FPGA_MAXIMUM      = 4
};


#define BACKPAQ_EEPROM_CAMERA_ORIENTATION  0x80     /* High order bit set for landscape cameras */
#define BACKPAQ_EEPROM_CAMERA_TYPE_MASK    0x7f     /* All other bits for camera type */

#define FPGA_SRAM_STATUS_MASK           0xffff
#define FPGA_SRAM_STATUS_BITS_MASK	3
#define BACKPAQ_SRAM_ERROR		0x1
#define BACKPAQ_SRAM_BUSY		0x2



/* Valid BackPAQ camera types */
enum { 
	BACKPAQ_CAMERA_SMAL_ORIGINAL_GREY  = 0,
	BACKPAQ_CAMERA_SMAL_ORIGINAL_COLOR = 1,
	BACKPAQ_CAMERA_SMAL_RELEASE_COLOR  = 2,
	BACKPAQ_CAMERA_SMAL_AUTOBRITE_09   = 3,
	BACKPAQ_CAMERA_PHILIPS_UPA1021     = 4, /* VGA, no longer used*/
	BACKPAQ_CAMERA_PHILIPS_UPA1022     = 5, /* VGA */
	BACKPAQ_CAMERA_PHILIPS_UPA1012     = 6,	/* CIF, YUV output*/
};

extern struct h3600_backpaq_eeprom h3600_backpaq_eeprom_shadow;

/*********** Memory-mapped CPLD interface **********/
/* In the future the offset from Bank2Virt will be extracted from EEPROM */
//#define _BackpaqSysctlBase       (H3600_BANK_2_VIRT + 0x2000000) 
#define _BackpaqSysctlBase       (H3600_BANK_2_VIRT + h3600_backpaq_eeprom_shadow.sysctl_start)

#define _BackpaqSysctlMajorVersion       0x00
#define _BackpaqSysctlFirmwareVersion    0x04
#define _BackpaqSysctlFPGAControl        0x08
#define _BackpaqSysctlFPGAStatus         0x0c
#define _BackpaqSysctlFPGAProgram        0x10
#define _BackpaqSysctlPCMCIAPower        0x14
#define _BackpaqSysctlFlashControl       0x18
#define _BackpaqSysctlGenControl         0x1c
#define _BackpaqSysctlReset              0x20

#define SYSCTL_OFFSET(s,x) (*((volatile s*) (_BackpaqSysctlBase + x)))

#define BackpaqSysctlMajorVersion     SYSCTL_OFFSET(u16,_BackpaqSysctlMajorVersion)
#define BackpaqSysctlFirmwareVersion  SYSCTL_OFFSET(u16,_BackpaqSysctlFirmwareVersion)
#define BackpaqSysctlFPGAControl      SYSCTL_OFFSET(u16,_BackpaqSysctlFPGAControl)
#define BackpaqSysctlFPGAStatus       SYSCTL_OFFSET(u16,_BackpaqSysctlFPGAStatus)
#define BackpaqSysctlFPGAProgram      SYSCTL_OFFSET(u16,_BackpaqSysctlFPGAProgram)
#define BackpaqSysctlPCMCIAPower      SYSCTL_OFFSET(u16,_BackpaqSysctlPCMCIAPower)
#define BackpaqSysctlFlashControl     SYSCTL_OFFSET(u16,_BackpaqSysctlFlashControl)
#define BackpaqSysctlGenControl       SYSCTL_OFFSET(u16,_BackpaqSysctlGenControl)
#define BackpaqSysctlReset            SYSCTL_OFFSET(u16,_BackpaqSysctlReset)

//struct mercury_backpaq_sysctl {
//	volatile u16 hardware_version;   /* 0x00 */
//	  u16 pad1;
//	volatile u16 firmware_version;   /* 0x04 */
//	  u16 pad2;
//	volatile u16 fpga_ctl;           /* 0x08 */
//	  u16 pad3;
//	volatile u16 fpga_status;        /* 0x0c */
//	  u16 pad4;
//	volatile u16 fpga_program;       /* 0x10 */
//	  u16 pad5;
//	volatile u16 pcmcia_power;       /* 0x14 */
//	  u16 pad6;
//	volatile u16 flash_control;      /* 0x18 */ 
//	  u16 pad7;
//	volatile u16 gencontrol;         /* 0x1c */ 
//	  u16 pad8;
//	  u32 pad[4];  /* 0x20, 0x24, 0x28, 0x2c */
//	long socket[2]; /* readable image at 0x30 and 0x34 */ 
//};

#define _BackpaqBase                         (H3600_BANK_4_VIRT) /* see h3600.c */
#define BACKPAQ_OFFSET(s,x) (*((volatile s *) (_BackpaqBase + x)))

/* Memory locations controlled by the FPGA */ 
/* backpaq3 only */
#define _BackpaqFPGACamAccelX1               0x08     /* u16  r   */
#define _BackpaqFPGACamAccelX2               0x0c     /* u16  r   */
#define _BackpaqFPGACamAccelY1               0x10     /* u16  r   */
#define _BackpaqFPGACamAccelY2               0x14     /* u16  r   */
#define _BackpaqFPGACamAccelZ1               0x18     /* u16  r   */
#define _BackpaqFPGACamAccelZ2               0x1c     /* u16  r   */
#define _BackpaqFPGASramStatus               0x20     /* u16  r   */
#define _BackpaqFPGASramStatusClear          0x24     /* u16    w */
#define _BackpaqFPGASramWriteAddr            0x28     /* u16  r/w */
#define _BackpaqFPGASramWriteData            0x2c     /* u16    w */
#define _BackpaqFPGASramReadAddr             0x30     /* u16  r/w */
#define _BackpaqFPGASramReadData             0x34     /* u16  r   */

/* both backpaq2 and backpaq3 */
#define _BackpaqFPGAFirmwareVersion          0x80     /* u16  r/w */
#define _BackpaqFPGACameraWritethru          0x84     /* u8     w */
#define _BackpaqFPGACameraFifoData           0x88     /* u32  r/w */
#define _BackpaqFPGACameraLiveMode           0x8c     /* u16  r/w */
#define _BackpaqFPGACameraIntegrationTime    0x90     /* u16  r/w */
#define _BackpaqFPGACameraClockDivisor       0x94     /* u16  r/w */
#define _BackpaqFPGACameraFifoInfo           0x98     /* u16  r   */
#define _BackpaqFPGACameraFifoDataAvail      0x9c     /* u16  r   */
#define _BackpaqFPGACameraFifoStatus         0xa0     /* u16  r   */
#define _BackpaqFPGACameraRowCount           0xa4     /* u16  r   */
#define _BackpaqFPGAReset                    0xa8     /* u8     w */
#define _BackpaqFPGACameraIntegrationCmd     0xac     /* u16  r/w */
#define _BackpaqFPGACameraInterruptFifo      0xb0     /* u16  r/w */
#define _BackpaqFPGAInterruptMask            0xb4     /* u16  r/w */
#define _BackpaqFPGAInterruptStatus          0xb8     /* u16  r   */
#define _BackpaqFPGATest32Addr               0xbc     /* u32  r/w */
#define _BackpaqFPGAAccelX1                  0xc0     /* u16  r   */
#define _BackpaqFPGAAccelX2                  0xc4     /* u16  r   */
#define _BackpaqFPGAAccelY1                  0xc8     /* u16  r   */
#define _BackpaqFPGAAccelY2                  0xcc     /* u16  r   */
#define _BackpaqFPGAGasGaugeCommand          0xd0     /* u16  r/w */
#define _BackpaqFPGAGasGaugeResult           0xd4     /* u16  r   */
#define _BackpaqFPGAGasGaugeWState           0xd8     /* u16  r   */
#define _BackpaqFPGAGasGaugeRState           0xdc     /* u16  r   */
#define _BackpaqFPGACameraDecimationMode     0xe4     /* u16  r/w */

#define _BackpaqFPGACameraI2C_CR1            0x0120	/* u8 */
#define _BackpaqFPGACameraI2C_CR2            0x0124	/* u8 */
#define _BackpaqFPGACameraI2C_SlaveAddr      0x0128	/* u8 */
#define _BackpaqFPGACameraI2C_RegAddr        0x012C	/* u8 */
#define _BackpaqFPGACameraI2C_Data           0x0130	/* u8 */
#define _BackpaqFPGACameraFrameCount         0x0134	/* u16 r */

/* Memory locations controlled by the CPLD(s) for the PCMCIA slots */
#define _BackpaqPCMCIAVersionid_0               0x300
#define _BackpaqPCMCIAVersionid_1               0x380
#define _BackpaqPCMCIAStatus_0                  0x304
#define _BackpaqPCMCIAStatus_1                  0x384
#define _BackpaqPCMCIAResetAssert_0             0x308
#define _BackpaqPCMCIAResetAssert_1             0x388
#define _BackpaqPCMCIAResetDeassert_0           0x30c
#define _BackpaqPCMCIAResetDeassert_1           0x38c

/* backpaq3 only */
#define BackpaqFPGACamAccelX1              BACKPAQ_OFFSET(u16,_BackpaqFPGACamAccelX1)
#define BackpaqFPGACamAccelX2              BACKPAQ_OFFSET(u16,_BackpaqFPGACamAccelX2)
#define BackpaqFPGACamAccelY1              BACKPAQ_OFFSET(u16,_BackpaqFPGACamAccelY1)
#define BackpaqFPGACamAccelY2              BACKPAQ_OFFSET(u16,_BackpaqFPGACamAccelY2)
#define BackpaqFPGACamAccelZ1              BACKPAQ_OFFSET(u16,_BackpaqFPGACamAccelZ1)
#define BackpaqFPGACamAccelZ2              BACKPAQ_OFFSET(u16,_BackpaqFPGACamAccelZ2)
#define BackpaqFPGASramStatus             BACKPAQ_OFFSET(u16,_BackpaqFPGASramStatus)
#define BackpaqFPGASramStatusClear        BACKPAQ_OFFSET(u16,_BackpaqFPGASramStatusClear)
#define BackpaqFPGASramWriteAddr          BACKPAQ_OFFSET(u16,_BackpaqFPGASramWriteAddr)
#define BackpaqFPGASramWriteData          BACKPAQ_OFFSET(u16,_BackpaqFPGASramWriteData)
#define BackpaqFPGASramReadAddr           BACKPAQ_OFFSET(u16,_BackpaqFPGASramReadAddr)
#define BackpaqFPGASramReadData           BACKPAQ_OFFSET(u16,_BackpaqFPGASramReadData)

#define BackpaqFPGAFirmwareVersion         BACKPAQ_OFFSET(u16,_BackpaqFPGAFirmwareVersion)
#define BackpaqFPGACameraWritethru         BACKPAQ_OFFSET(u8 ,_BackpaqFPGACameraWritethru)
#define BackpaqFPGACameraFifoData          BACKPAQ_OFFSET(u32,_BackpaqFPGACameraFifoData)
#define BackpaqFPGACameraLiveMode          BACKPAQ_OFFSET(u16,_BackpaqFPGACameraLiveMode)
#define BackpaqFPGACameraIntegrationTime   BACKPAQ_OFFSET(u16,_BackpaqFPGACameraIntegrationTime)
#define BackpaqFPGACameraClockDivisor      BACKPAQ_OFFSET(u16,_BackpaqFPGACameraClockDivisor)
#define BackpaqFPGACameraFifoInfo          BACKPAQ_OFFSET(u16,_BackpaqFPGACameraFifoInfo)
#define BackpaqFPGACameraFifoDataAvail     BACKPAQ_OFFSET(u16,_BackpaqFPGACameraFifoDataAvail)
#define BackpaqFPGACameraFifoStatus        BACKPAQ_OFFSET(u16,_BackpaqFPGACameraFifoStatus)
#define BackpaqFPGACameraRowCount          BACKPAQ_OFFSET(u16,_BackpaqFPGACameraRowCount)
#define BackpaqFPGAReset                   BACKPAQ_OFFSET(u8 ,_BackpaqFPGAReset)
#define BackpaqFPGACameraIntegrationCmd    BACKPAQ_OFFSET(u16,_BackpaqFPGACameraIntegrationCmd)
#define BackpaqFPGACameraInterruptFifo     BACKPAQ_OFFSET(u16,_BackpaqFPGACameraInterruptFifo)
#define BackpaqFPGAInterruptMask           BACKPAQ_OFFSET(u16,_BackpaqFPGAInterruptMask)
#define BackpaqFPGAInterruptStatus         BACKPAQ_OFFSET(u16,_BackpaqFPGAInterruptStatus)
#define BackpaqFPGATest32Addr              BACKPAQ_OFFSET(u32,_BackpaqFPGATest32Addr)
#define BackpaqFPGAAccelX1                 BACKPAQ_OFFSET(u16,_BackpaqFPGAAccelX1)
#define BackpaqFPGAAccelX2                 BACKPAQ_OFFSET(u16,_BackpaqFPGAAccelX2)
#define BackpaqFPGAAccelY1                 BACKPAQ_OFFSET(u16,_BackpaqFPGAAccelY1)
#define BackpaqFPGAAccelY2                 BACKPAQ_OFFSET(u16,_BackpaqFPGAAccelY2)
#define BackpaqFPGAGasGaugeCommand         BACKPAQ_OFFSET(u16,_BackpaqFPGAGasGaugeCommand)
#define BackpaqFPGAGasGaugeResult          BACKPAQ_OFFSET(u16,_BackpaqFPGAGasGaugeResult)
#define BackpaqFPGAGasGaugeWState          BACKPAQ_OFFSET(u16,_BackpaqFPGAGasGaugeWState)
#define BackpaqFPGAGasGaugeRState          BACKPAQ_OFFSET(u16,_BackpaqFPGAGasGaugeRState)
#define BackpaqFPGACameraDecimationMode    BACKPAQ_OFFSET(u16,_BackpaqFPGACameraDecimationMode)

#define BackpaqFPGACameraI2C_CR1           BACKPAQ_OFFSET(u8 ,_BackpaqFPGACameraI2C_CR1)
#define BackpaqFPGACameraI2C_CR2           BACKPAQ_OFFSET(u8 ,_BackpaqFPGACameraI2C_CR2)
#define BackpaqFPGACameraI2C_RegAddr       BACKPAQ_OFFSET(u8 ,_BackpaqFPGACameraI2C_RegAddr)
#define BackpaqFPGACameraI2C_SlaveAddr     BACKPAQ_OFFSET(u8 ,_BackpaqFPGACameraI2C_SlaveAddr)
#define BackpaqFPGACameraI2C_Data          BACKPAQ_OFFSET(u8 ,_BackpaqFPGACameraI2C_Data)
#define BackpaqFPGACameraFrameCount          BACKPAQ_OFFSET(u16 ,_BackpaqFPGACameraFrameCount)

#define BackpaqPCMCIAVersionid_0                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAVersionid_0)
#define BackpaqPCMCIAVersionid_1                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAVersionid_1)
#define BackpaqPCMCIAStatus_0                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAStatus_0)
#define BackpaqPCMCIAStatus_1                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAStatus_1)
#define BackpaqPCMCIAResetAssert_0                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAResetAssert_0)
#define BackpaqPCMCIAResetAssert_1                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAResetAssert_1)
#define BackpaqPCMCIAResetDeassert_0                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAResetDeassert_0)
#define BackpaqPCMCIAResetDeassert_1                BACKPAQ_OFFSET(u16,_BackpaqPCMCIAResetDeassert_1)

/* Hardware versions */
/* ...This needs to be changed to have some useful bit fields */
/* #define BACKPAQ_HARDWARE_VERSION_1 0x00bc *//* Only run if we see this hardware version */

/* FPGA control (sysctl->fpga_ctl) 0x08 */
#define BACKPAQ_FPGACTL_M0      (1 << 0)
#define BACKPAQ_FPGACTL_M1      (1 << 1)
#define BACKPAQ_FPGACTL_M2      (1 << 2)
#define BACKPAQ_FPGACTL_PROGRAM (1 << 3)
#define BACKPAQ3_FPGACTL_RESET   (1 << 4)

/* FPGA Status [read-only] (systctl->fpgadout) 0x0c */
#define BACKPAQ_FPGASTATUS_DONE   (1 << 0)
#define BACKPAQ_FPGASTATUS_INITL  (1 << 1)
#define BACKPAQ_FPGASTATUS_EMPTY  (1 << 2)

#define BACKPAQ2_OPTION_OPT_ON (1 << 0)
#define BACKPAQ2_OPTION_DC_IN  (1 << 1)
#define BACKPAQ2_OPTION_MCHG   (1 << 2)
#define BACKPAQ2_OPTION_EBAT   (1 << 3)
#define BACKPAQ2_OPTION_ETMI   (1 << 4)
#define BACKPAQ2_OPTION_ETMO   (1 << 5)

#define BACKPAQ2_GASGAUGE_BDIR (1 << 0)
#define BACKPAQ2_GASGAUGE_BSCL (1 << 1)
#define BACKPAQ2_GASGAUGE_BSDA (1 << 2)

/* Power control (sysctl->pcmcia_power) 0x14 */
#define BACKPAQ_PCMCIA_AEN0   (1 << 0)
#define BACKPAQ_PCMCIA_AEN1   (1 << 1)
#define BACKPAQ_PCMCIA_A5VEN  (1 << 2)
#define BACKPAQ_PCMCIA_A3VEN  (1 << 3)
#define BACKPAQ_PCMCIA_BEN0   (1 << 4)
#define BACKPAQ_PCMCIA_BEN1   (1 << 5)
#define BACKPAQ_PCMCIA_B5VEN  (1 << 6)
#define BACKPAQ_PCMCIA_B3VEN  (1 << 7)
#define BACKPAQ2_PWRCTL_50VEN  (1 << 8) // moved to 0x1c on backpaq3
#define BACKPAQ2_PWRCTL_25VEN  (1 << 9) // removed on backpaq3
#define BACKPAQ2_PWRCTL_18VEN  (1 << 10) // moved to 0x1c on backpaq3

/* Flash control (sysctl->flash_control) 0x18 */
#define BACKPAQ_REGC_FLASH_STATUS0 (1 << 0)
#define BACKPAQ_REGC_FLASH_STATUS1 (1 << 1)
#define BACKPAQ2_REGC_ACCEL_X       (1 << 2)
#define BACKPAQ2_REGC_ACCEL_Y       (1 << 3)
#define BACKPAQ2_REGC_AUD_AGC       (1 << 4)
#define BACKPAQ2_REGC_BATT_SDA      (1 << 5)
#define BACKPAQ2_REGC_BATT_SDA_DIR  (1 << 6)

#define BACKPAQ_FLASH_ENABLE0 (1 << 4)
#define BACKPAQ_FLASH_ENABLE1 (1 << 5)
#define BACKPAQ2_FLASH_VPPEN   (1 << 8)
#define BACKPAQ3_FLASH_VPPEN   (1 << 7)

/* General control register (sysctl->gencontrol) 0x1c */
#define BACKPAQ3_GENCTL_CAM_CLKEN  (1 << 0)
#define BACKPAQ3_GENCTL_AUDIO_CLKEN (1 << 1)
#define BACKPAQ3_GENCTL_AUDIO_AMPEN (1 << 2)
#define BACKPAQ3_GENCTL_50VEN  (1 << 3) // moved to 0x1c on backpaq3
#define BACKPAQ3_GENCTL_18VEN  (1 << 4) // moved to 0x1c on backpaq3
#define BACKPAQ2_GENCTL_CAM_CLKEN  (1 << 9)
#define BACKPAQ2_GENCTL_AUDIO_CLKEN (1 << 10)
#define BACKPAQ2_GENCTL_AUDIO_AMPEN (1 << 11)

/* Socket register information */
/* Interrupt bits */

#define BACKPAQ_FPGA_INT_FIFO    (1 << 0)
#define BACKPAQ_FPGA_INT_VBLANK  (1 << 1)
#define BACKPAQ_FPGA_INT_WTBUSY  (1 << 2)  /* Write through register is tied up */
#define BACKPAQ_FPGA_INT_I2C     (1 << 3)  /* ???? */
#define BACKPAQ_FPGA_INT_AUDIO   (1 << 4)  

#define BACKPAQ_FPGA_AUDIO_INT_FIFO_PLAY 0xF
#define BACKPAQ_FPGA_AUDIO_INT_FIFO_REC 0xF0
#define	BACKPAQ_FPGA_AUDIO_INT_L3 0x100

#define BACKPAQ_SYSCTL_RESET 1

#define BACKPAQ_PCMCIA_VS1    (1 << 0)
#define BACKPAQ_PCMCIA_VS2    (1 << 1)
#define BACKPAQ_PCMCIA_STSCHG (1 << 2)
#define BACKPAQ_PCMCIA_BVD1   (1 << 2) /* same pin as STSCHG */
#define BACKPAQ_PCMCIA_INPACK (1 << 3)
#define BACKPAQ_PCMCIA_SPKR   (1 << 4)
#define BACKPAQ_PCMCIA_BVD2   (1 << 4) /* same pin as SPKR */
#define BACKPAQ_PCMCIA_SKTSEL (1 << 5)
#define BACKPAQ_PCMCIA_CD0    (1 << 6)
#define BACKPAQ_PCMCIA_CD1    (1 << 7)
#define BACKPAQ_PCMCIA_RESET  (1 << 10)

#define BACKPAQ2_FPGA_RESET (1 << 0)

#define BACKPAQ_GASGAUGE_READ  0x100 
#define BACKPAQ_GASGAUGE_WRITE 0x080 

#define BACKPAQ_GASGAUGE_RSTATE_IDLE 1
#define BACKPAQ_GASGAUGE_WSTATE_IDLE 1

/* Lower 8 bits is the bus width (16 or 32) */
/* Upper 8 bits is the number of bytes to read per read count */ 
#define BACKPAQ_CAMERA_FIFO_INFO_WIDTH 0x00ff   
#define BACKPAQ_CAMERA_FIFO_INFO_BPC   0xff00   


/* Lower 8 bits is the actual fifo status lines */
/* Upper 8 bits is used for new fpga capabilities */ 
#define BACKPAQ_CAMERA_FIFO_STATUS_PREFETCH_AVAILABLE     (1 << 0)
#define BACKPAQ_CAMERA_FIFO_STATUS_EMPTY                  (1 << 1)
#define BACKPAQ_CAMERA_FIFO_STATUS_READ_ERROR             (1 << 2)
#define BACKPAQ_CAMERA_FIFO_STATUS_READ_ACK               (1 << 3)
#define BACKPAQ_CAMERA_FIFO_STATUS_WRITE_ERROR            (1 << 4)
#define BACKPAQ_CAMERA_FIFO_STATUS_WRITE_ACK              (1 << 5)
#define BACKPAQ_CAMERA_FIFO_STATUS_FIFO_FULL              (1 << 6)
/* upper 8 bits are capabilities !! */
#define BACKPAQ_CAMERA_FIFO_STATUS_PREFETCH_SUPPORT       (1 << 8)
#define BACKPAQ_CAMERA_FIFO_STATUS_FRAME_COUNT_SUPPORT    (1 << 9)

/* Anybody using these - fg ???? */
struct backpaq_audio {
   short reg40;
   short pad1;
   short reg44;
   short pad2;
   short reg48;
   short pad3;
   short reg4c;
   short pad4;
   short reg50;
   short pad5;
};

extern struct backpaq_audio *backpaq_audio;

#define BACKPAQ_REG44_L3_DATA_IN (1 << 0)
#define BACKPAQ_REG44_L3_AGCSTAT (1 << 1)
#define BACKPAQ_REG44_L3_OVERFL (1 << 2)
#define BACKPAQ_REG44_RESET     (1 << 3)
#define BACKPAQ_REG44_L3_MODE   (1 << 4)
#define BACKPAQ_REG44_L3_CLOCK  (1 << 5)
#define BACKPAQ_REG44_L3_DIR    (1 << 6)
#define BACKPAQ_REG44_L3_DATA_OUT (1 << 7)
#define BACKPAQ_REG44_L3_BCLK_EN (1 << 8)
#define BACKPAQ_REG44_L3_QMUTE  (1 << 9)

#define BACKPAQ_REG4C_TXD_FIFO_BUSY (1 << 0)
#define BACKPAQ_REG4C_TXD_FIFO_FULL (1 << 0)


/* ********************************************* */
/* ********** backpaq audio registers ********** */
/* ********************************************* */

#define AUDIO_DMA_PLAY_INTERRUPT IRQ_H3800_SLEEVE_4
#define AUDIO_DMA_REC_INTERRUPT IRQ_H3800_SLEEVE_5

/* ***** audio L3 registers ***** */
#define BACKPAQ_AUDIO_L3_ADDR BACKPAQ_OFFSET(u32, 0x40c)
#define BACKPAQ_AUDIO_L3_DATA BACKPAQ_OFFSET(u32, 0x410)

/* ***** audio play/record fifo count ***** */
#define BACKPAQ_AUDIO_PLAY_FC BACKPAQ_OFFSET(u32, 0x414)
#define BACKPAQ_AUDIO_REC_FC BACKPAQ_OFFSET(u32, 0x418)

/* ***** play/record fifo addr ***** */
#define BACKPAQ_AUDIO_PLAY_FIFO BACKPAQ_OFFSET(u32, 0x420)
#define BACKPAQ_AUDIO_REC_FIFO BACKPAQ_OFFSET(u32, 0x424)

/* ***** audio control ***** */
#define BACKPAQ_AUDIO_CONTROL BACKPAQ_OFFSET(u32, 0x408)
#define BACKPAQ_AUDIO_CONTROL_MULTFACTOR 16
#define BACKPAQ_AUDIO_CONTROL_SAMPLERATE 8
#define BACKPAQ_AUDIO_CONTROL_RECORD 1
#define BACKPAQ_AUDIO_CONTROL_PLAY 0

/* ***** audio interrupt and mask interrupt ***** */
#define BACKPAQ_AUDIO_INT BACKPAQ_OFFSET(u32, 0x400)
#define BACKPAQ_AUDIO_INT_MASK BACKPAQ_OFFSET(u32, 0x404)

/* ***** audio debug ***** */
#define BACKPAQ_AUDIO_DEBUG BACKPAQ_OFFSET(u32, 0x41c)

/* ***** sampling frequency ***** */
#define BACKPAQ_AUDIO_SF_44100 0x10
#define BACKPAQ_AUDIO_SF_32000 0x08
#define BACKPAQ_AUDIO_SF_22050 0x04
#define BACKPAQ_AUDIO_SF_16000 0x02
#define BACKPAQ_AUDIO_SF_11025 0x01
#define BACKPAQ_AUDIO_SF_8000 0x00
#define BACKPAQ_AUDIO_SF_CLR 0x00

/* ***** multiple factors for CODEC ***** */
#define BACKPAQ_AUDIO_FS_512 0x0
#define BACKPAQ_AUDIO_FS_384 0x1
#define BACKPAQ_AUDIO_FS_256 0x2
#define BACKPAQ_AUDIO_FS_CLR 0x0

/* ***** data input format for CODEC ***** */
#define BACKPAQ_AUDIO_CODEC_DATAIN 0x4

/* ***** to initiate double transfer on L3 interface ***** */
#define BACKPAQ_AUDIO_L3_DOUBLE 0x10000;

/* CODEC regisers */
/* ***** status register address ***** */
#define BACKPAQ_AUDIO_CODEC_STAT 0x16;
/* ***** status register data ***** */
#define BACKPAQ_AUDIO_CODEC_STAT0 0x0;
#define BACKPAQ_AUDIO_CODEC_STAT_RST (1 << 6)
#define BACKPAQ_AUDIO_CODEC_STAT_SYSCLK_MASK (3 << 4)
#define BACKPAQ_AUDIO_CODEC_STAT_SYSCLK (1 << 4)
#define BACKPAQ_AUDIO_CODEC_STAT_INFORMAT_MASK (7 << 1)
#define BACKPAQ_AUDIO_CODEC_STAT_INFORMAT (1 << 1)
#define BACKPAQ_AUDIO_CODEC_STAT_DC (1 << 0)
#define BACKPAQ_AUDIO_CODEC_STAT1 (1 << 7);
#define BACKPAQ_AUDIO_CODEC_STAT_OUTGAIN (1 << 6)
#define BACKPAQ_AUDIO_CODEC_STAT_INGAIN (1 << 5)
#define BACKPAQ_AUDIO_CODEC_STAT_PAD (1 << 4)
#define BACKPAQ_AUDIO_CODEC_STAT_PDA (1 << 3)
#define BACKPAQ_AUDIO_CODEC_STAT_DS (1 << 2)
#define BACKPAQ_AUDIO_CODEC_STAT_PC_MASK (3 << 0)
#define BACKPAQ_AUDIO_CODEC_STAT_PC (1 << 0)
/* ***** data0 register address ***** */
#define BACKPAQ_AUDIO_CODEC_DATA0 0x14;
/* ****** data0 register data ***** */
#define BACKPAQ_AUDIO_CODEC_DATA0_VOL_MASK (0x3F << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_VOL (1 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_BB_TR_EN 0x40
#define BACKPAQ_AUDIO_CODEC_DATA0_BB_MASK (F << 2)
#define BACKPAQ_AUDIO_CODEC_DATA0_BB (1 << 2)
#define BACKPAQ_AUDIO_CODEC_DATA0_TR_MASK (3 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_TR (1 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_PP_DE_MT_M_EN 0x80
#define BACKPAQ_AUDIO_CODEC_DATA0_PP (1 << 5)
#define BACKPAQ_AUDIO_CODEC_DATA0_DE_MASK (3 << 3)
#define BACKPAQ_AUDIO_CODEC_DATA0_DE (1 << 3)
#define BACKPAQ_AUDIO_CODEC_DATA0_MT (1 << 2)
#define BACKPAQ_AUDIO_CODEC_DATA0_M_MASK (3 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_M (1 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_EN 0xC0
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_MASK (7 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_EA (1 << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_EN 0xE0
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MASK (1F << 0)
#define BACKPAQ_AUDIO_CODEC_DATA0_ED (1 << 0)
/* ***** extended register address ***** */
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_MA 0x0
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_MB 0x1
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_MS_MM 0x2
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_AG_IG1TO0 0x4
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_IG6TO2 0x5
#define BACKPAQ_AUDIO_CODEC_DATA0_EA_AT_AL 0x6
/* ***** extended register data ***** */
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MA 0x1F
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MB 0x1F
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS (0x7 << 2)
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MM 0x03
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_AG (1 << 4)
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_IG1TO0 0x03
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_IG6TO2 0x1F
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_AT (0x7 << 2)
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_AL 0x03

/* volume range allowed in CODEC */
#define BACKPAQ_AUDIO_CODEC_DATA0_VOL_MUTE 0x0
#define BACKPAQ_AUDIO_CODEC_DATA0_VOL_LOW 0x0F
#define BACKPAQ_AUDIO_CODEC_DATA0_VOL_MID 0x20
#define BACKPAQ_AUDIO_CODEC_DATA0_VOL_LOUD 0x3F

/* input gain range allowed in CODEC */
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_n3DB 0x0
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_p0DB 0x1
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_p3DB 0x2
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_p9DB 0x3
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_p15DB 0x4
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_p21DB 0x5
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_p27DB 0x6
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MS_NOTUSED 0x7

/* mixer modes allowed in CODEC */
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MM_DD 0x0  /* double differential */
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MM_CH1 0x1
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MM_CH2 0x2
#define BACKPAQ_AUDIO_CODEC_DATA0_ED_MM_DM 0x3  /* digital mixer */


/* audio interrupt bits */
#define AUDIO_INT_PLAY_FIFO_EMPTY 0x1
#define AUDIO_INT_PLAY_FIFO_3_4_FULL 0x2
#define AUDIO_INT_PLAY_FIFO_1_2_FULL 0x4
#define AUDIO_INT_PLAY_FIFO_FULL 0x8
#define AUDIO_INT_REC_FIFO_EMPTY 0x10
#define AUDIO_INT_REC_FIFO_1_2_FULL 0x20
#define AUDIO_INT_REC_FIFO_3_4_FULL 0x40
#define AUDIO_INT_REC_FIFO_FULL 0x80
#define AUDIO_INT_L3_DONE 0x100
#define AUDIO_INT_RO 0x1000
#define AUDIO_INT_WO 0x2000

/* ********************************************* */

#endif




