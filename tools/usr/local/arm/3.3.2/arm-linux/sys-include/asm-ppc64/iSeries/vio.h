/*
 *  include/asm-ppc/iSeries/vio.h
 *
 *  iSeries Virtual I/O Message Path header
 *
 *  Author: Dave Boutcher <boutcher@us.ibm.com>
 * (C) Copyright 2000 IBM Corporation
 * 
 * This program is free software;  you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) anyu later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.  
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */
#ifndef _VIO_H
#define _VIO_H

#ifndef _HVTYPES_H
#include <asm/iSeries/HvTypes.h>
#endif
#ifndef _HVLPEVENT_H
#include <asm/iSeries/HvLpEvent.h>
#endif

typedef void (vio_event_handler_t) (struct HvLpEvent *event);

void viopath_init(void);
int viopath_open(HvLpIndex remoteLp, int subtype);
int viopath_close(HvLpIndex remoteLp, int subtype);
void vio_setBlockHandler(vio_event_handler_t *beh);
void vio_clearBlockHandler(void);
void vio_setCharHandler(vio_event_handler_t *ceh);
void vio_clearCharHandler(void);
void vio_setCDHandler(vio_event_handler_t *ceh);
void vio_clearCDHandler(void);
void vio_setTapeHandler(vio_event_handler_t *ceh);
void vio_clearTapeHandler(void);
int viopath_isactive(HvLpIndex lp);
HvLpInstanceId viopath_sourceinst(HvLpIndex lp);
HvLpInstanceId viopath_targetinst(HvLpIndex lp);

extern void * vio_char_event_buffer;
extern void * vio_block_event_buffer;
extern void * vio_cd_event_buffer;
extern void * vio_tape_event_buffer;

extern HvLpIndex viopath_hostLp;

#define VIOCHAR_MAX_DATA 200

#define VIOMAJOR_SUBTYPE_MASK 0xff00
#define VIOMINOR_SUBTYPE_MASK 0x00ff

#define VIOVERSION            0x0101
#define VIOMAXBLOCKDMA        12
#define VIOMAXREQ             16
#define VIOTAPE_MAXREQ        6

enum viosubtypes {
  viomajorsubtype_monitor  = 0x0100,
  viomajorsubtype_blockio  = 0x0200,
  viomajorsubtype_chario   = 0x0300,
  viomajorsubtype_config   = 0x0400,
  viomajorsubtype_cdio     = 0x0500,
  viomajorsubtype_tape     = 0x0600
};

struct viocdlpevent {
  struct HvLpEvent event;
  u32 mReserved1;
  u16 mVersion;
  u16 mSubTypeRc;
  u16 mDisk;
  u16 mFlags;
  u32 mToken;
  u64 mOffset;          // On open, the max number of disks
  u64 mLen;             // On open, the size of the disk
  u32 mBlockSize;       // Only set on open
  u32 mMediaSize;       // Only set on open
};

#define VIOTAPOP_RESET          0	
#define VIOTAPOP_FSF	        1	
#define VIOTAPOP_BSF	        2	
#define VIOTAPOP_FSR	        3	
#define VIOTAPOP_BSR	        4	
#define VIOTAPOP_WEOF	        5	
#define VIOTAPOP_REW	        6	
#define VIOTAPOP_NOP	        7	
#define VIOTAPOP_EOM	        8	
#define VIOTAPOP_ERASE          9	
#define VIOTAPOP_SETBLK        10	
#define VIOTAPOP_SETDENSITY    11	
#define VIOTAPOP_SETPOS	       12	
#define VIOTAPOP_GETPOS	       13	
#define VIOTAPOP_SETPART       14	 

struct viotapelpevent {
  struct HvLpEvent event;
  u32 mReserved1;
  u16 mVersion;
  u16 mSubTypeRc;
  u16 mTape;
  u16 mFlags;
  u32 mToken;
  u64 mLen;           
  union {
    struct {
      u32 mTapeOp;
      u32 mCount;
    } tapeOp;
    struct {
      u32  mType;
      u32  mResid;
      u32  mDsreg;
      u32  mGstat;
      u32  mErreg;
      u32  mFileNo;
      u32  mBlkNo;
    } getStatus;
    struct {
      u32  mBlkNo;
    } getPos;
  } u;
};

struct vioblocklpevent {
  struct HvLpEvent event;
  u32 mReserved1;
  u16 mVersion;
  u16 mSubTypeRc;
  u16 mDisk;
  u16 mFlags;
  union {
    struct {                // Used during open
      u64 mDiskLen;
      u16 mMaxDisks;
      u16 mCylinders;    
      u16 mTracks;       
      u16 mSectors;       
      u16 mBytesPerSector;
    } openData;
    struct {                // Used during rw
      u64 mOffset;
      struct {
	u32 mToken;
	u32 reserved;
	u64 mLen;
      } dmaInfo[VIOMAXBLOCKDMA];
    } rwData;

    struct {
      u64 changed;
    } check;
  } u;
};

#define vioblockflags_ro   0x0001

enum vioblocksubtype {
  vioblockopen   = 0x0001,
  vioblockclose  = 0x0002,
  vioblockread   = 0x0003,
  vioblockwrite  = 0x0004,
  vioblockflush  = 0x0005,
  vioblockcheck  = 0x0007
};

enum viocdsubtype {
  viocdopen    = 0x0001,
  viocdclose   = 0x0002,
  viocdread    = 0x0003,
  viocdgetinfo = 0x0006,
  viocdcheck   = 0x0007
};

enum viotapesubtype {
  viotapeopen   = 0x0001,
  viotapeclose  = 0x0002,
  viotaperead   = 0x0003,
  viotapewrite  = 0x0004,
  viotapegetinfo= 0x0005,
  viotapeop     = 0x0006,
  viotapegetpos = 0x0007,
  viotapesetpos = 0x0008,
  viotapegetstatus = 0x0009
};

enum viotapeRc
{
  viotape_InvalidRange        = 0x0601,
  viotape_InvalidToken        = 0x0602,
  viotape_DMAError            = 0x0603,
  viotape_UseError            = 0x0604,
  viotape_ReleaseError        = 0x0605,
  viotape_InvalidTape         = 0x0606,
  viotape_InvalidOp           = 0x0607,
  viotape_TapeErr             = 0x0608,
  
  viotape_AllocTimedOut       = 0x0640,
  viotape_BOTEnc	      = 0x0641,
  viotape_BlankTape	      = 0x0642,
  viotape_BufferEmpty	      = 0x0643,
  viotape_CleanCartFound      = 0x0644, 
  viotape_CmdNotAllowed       = 0x0645, 
  viotape_CmdNotSupported     = 0x0646,
  viotape_DataCheck	      = 0x0647,  
  viotape_DecompressErr	      = 0x0648,     
  viotape_DeviceTimeout	      = 0x0649,   
  viotape_DeviceUnavail	      = 0x064a,  
  viotape_DeviceBusy	      = 0x064b,
  viotape_EndOfMedia	      = 0x064c, 
  viotape_EndOfTape	      = 0x064d,
  viotape_EquipCheck	      = 0x064e,
  viotape_InsufficientRs      = 0x064f,
  viotape_InvalidLogBlk	      = 0x0650,   
  viotape_LengthError         = 0x0651,
  viotape_LibDoorOpen	      = 0x0652,
  viotape_LoadFailure	      = 0x0653,
  viotape_NotCapable	      = 0x0654,
  viotape_NotOperational      = 0x0655,
  viotape_NotReady	      = 0x0656, 
  viotape_OpCancelled	      = 0x0657,
  viotape_PhyLinkErr	      = 0x0658,
  viotape_RdyNotBOT	      = 0x0659,
  viotape_TapeMark	      = 0x065a,
  viotape_WriteProt	      = 0x065b
};

struct viocharlpevent {
  struct HvLpEvent event;
  u32 mReserved1;
  u16 mVersion;
  u16 mSubTypeRc;
  u8 virtualDevice;
  u8 immediateDataLen;
  u8 immediateData[VIOCHAR_MAX_DATA];
};

#define viochar_window (10)
#define viochar_highwatermark (3)

enum viocharsubtype {
  viocharopen   = 0x0001,
  viocharclose  = 0x0002,
  viochardata   = 0x0003,
  viocharack    = 0x0004,
  viocharconfig = 0x0005
};

enum vioconfigsubtype {
  vioconfigget  = 0x0001,
};

enum viochar_rc {
  viochar_rc_ebusy = 1
};

enum viorc {
  viorc_good               = 0x0000,
  viorc_noConnection       = 0x0001,
  viorc_noReceiver         = 0x0002,
  viorc_noBufferAvailable  = 0x0003,
  viorc_invalidMessageType = 0x0004,
  viorc_invalidRange       = 0x0201,
  viorc_invalidToken       = 0x0202,
  viorc_DMAError           = 0x0203,
  viorc_useError           = 0x0204,
  viorc_releaseError       = 0x0205,
  viorc_invalidDisk        = 0x0206,
  viorc_openRejected       = 0x0301
};
  

#endif /* _VIO_H */

