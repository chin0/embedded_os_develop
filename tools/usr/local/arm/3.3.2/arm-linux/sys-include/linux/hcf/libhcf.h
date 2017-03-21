/*+I*************************************************************************
 * HCF Public Interface (v4.6b)
 *
 * Copyright (c) 1998-1999 Lucent Technologies Inc. -- http://www.wavelan.com
 * All rights reserved.
 *-I*************************************************************************/
#ifndef LIBHCF_H
#define LIBHCF_H 1

#ifndef HCFCFG_H
#define HCFCFG_H 1

/**************************************************************************************************************
*
* FILE   : hcfcfg.tpl // hcfcfg.h **************************** 2.0 ********************************************
*
* DATE   : $Date:   01 Feb 2000 12:02:32  $   $Revision:   4.6  $
*
* AUTHOR : Nico Valster
*
* DESC   : HCF Customization Macros
*
***************************************************************************************************************
* COPYRIGHT (c) 1994, 1995       by AT&T.                   All Rights Reserved.
* COPYRIGHT (c) 1996, 1997, 1998 by Lucent Technologies.    All Rights Reserved.
*
***************************************************************************************************************
*
* hcfcfg.tpl list all #defines which must be specified to:
*    I: adjust the HCF functions defined in HCF.CPP to the characteristics of a specific environment
*       o maximum sizes for messages and notification frames, persistent configuration storage
*       o Endianess
*
*   II: Compiler specific macros
*       o port I/O macros
*       o type definitions
*
*  III: Environment specific ASSERT macro
*
*   IV: Compiler specific
*
*    V: ;? specific
*
*
* By copying HCFCFG.TPL to HCFCFG.H and -if needed- modifying the #defines the WCI functionality can be
* tailored
*
* Supported environments:
WVLAN_41    Miniport                                NDIS 3.1
WVLAN_42    Packet                                  Microsoft Visual C 1.5
WVLAN_43    16 bits DOS ODI                         Microsoft Visual C 1.5
WVLAN43L    16 bits DOS ODI on top of HCF-light     Microsoft Visual C 1.5
WVLAN_44    32 bits ODI (__NETWARE_386__)           WATCOM
WVLAN_45    MAC_OS                                  MPW?, Symantec?
WVLAN_46    Windows CE (_WIN32_WCE)                 Microsoft ?
WVLAN_47    LINUX  (__LINUX__)                      GCC
WVLAN_48    Miniport                                NDIS 5
WVLAN_51    Miniport                                NDIS 4
WVLAN_81    WavePoint                               BORLAND C
WCITST      Inhouse test tool                       Microsoft Visual C 1.5
WSU         WaveLAN Station Update                  Microsoft Visual C ??
SCO UNIX    not yet actually used ?                 ?
__ppc       OEM supplied                            ?
_AM29K      OEM supplied                            ?
?           OEM supplied                            Microtec Research 80X86 Compiler

* T O   D O :  A D D   A   R E C I P E   H O W  T O   M O D I F Y  HCFCFG.H
*
**************************************************************************************************************/

/****************************************************************************
*************************************************************************************************/


/****************************************************************************
*
* CHANGE HISTORY
*

  960702 - NV
    Original Entry - derived from HCF 2.12
*************************************************************************************************/


/*  * * * * * * * * * * * * * * * * * * * * * *  I * * * * * * * * * * * * * * * * * * * * * * */

//#define HCF_HSI_VAR_0             // Controlled Deployment
//#define HCF_HSI_VAR_1             // WaveLAN
//#define HCF_HSI_VAR_2             // HomeLAN

/*  Alignment
 *  Some platforms can access words on odd boundaries (with possibly an performance impact), at other
 *  platforms such an access may result in a memory access violation.
 *  It is assumed that everywhere where the HCF casts a char pointer into a word pointer, the
 *  alignment criteria are met. This put some restrictions on the MSF, which are assumed to be
 *  "automatically" fullfilled at the applicable platforms
 *  To assert this assumption, the macro HCF_ALIGN can be defined. The default vaslue is 0, meaning no
 *  alignment, a value of 2 means word alignment, other values are invalid
 */

/*  * * * * * * * * * * * * * * * * * * * * * * II * * * * * * * * * * * * * * * * * * * * * * */



/************************************************************************************************/
/******************  C O M P I L E R   S P E C I F I C   M A C R O S  ***************************/
/************************************************************************************************/
/*************************************************************************************************
*
* The platforms supported by this version are:
*   - Microsoft Visual C 1.5 (16 bits platform)
*   - Microsoft Visual C 2.0 (32 bits platform)
*   - Watcom C/C++ 9.5
*   - SCO UNIX
*
* In this version of hcfiocfg.tpl all macros except the MSVC 1.5 versions are either dependent on
* compiler/environment supplied macros (e.g. _MSC_VER or "def-ed out"
*
* By selecting the appropriate Macro definitions by means of modifying the
* "#ifdef 0/1" lines, the HCF can be adjusted for the I/O chararcteristics of
* a specific compiler
*
* If needed the macros can be modified or replaced with definitions appropriate
* for your personal platform
* If you need to make such changes it is appreciated if you inform Lucent Technologies WCND Utrecht
* That way the changes can become part of the next release of the WCI
*
*
*   The prototypes and functional description of the macros are:
*
*   hcf_8   IN_PORT_BYTE(  hcf_16 port)
*           Reads a byte (8 bits) from the specified port
*
*   hcf_16  IN_PORT_WORD(  hcf_16 port)
*           Reads a word (16 bits) from the specified port
*
*   void    OUT_PORT_BYTE( hcf_16 port, hcf_8 value)
*           Writes a byte (8 bits) to the specified port
*
*   void    OUT_PORT_WORD( hcf_16 port, hcf_16 value)
*           Writes a word (16 bits) to the specified port
*
*   void    IN_PORT_STRING( port, dest, len)
*           Reads len number of words from the specified port to the (FAR) address dest in PC-RAM
*           Note that len specifies the number of words, NOT the number of bytes
*           !!!NOTE, although len specifies the number of words, dest MUST be a char pointer NOTE!!!
*           See also the common notes for IN_PORT_STRING and OUT_PORT_STRING
*
*   void    OUT_PORT_STRING( port, src, len)
*           Writes len number of words from the (FAR) address src in PC-RAM to the specified port
*           Note that len specifies the number of words, NOT the number of bytes.
*           !!!NOTE, although len specifies the number of words, src MUST be a char pointer NOTE!!!
*
*           The peculiar combination of word-length and char pointers for IN_PORT_STRING as well as
*           OUT_PORT_STRING is justified by the assumption that it offers a more optimal algorithm
*
*           Note to the HCF-implementor:
*           Due to the passing of the parameters to compiler specific blabla.........
*           do not use "expressions" as parameters, e.g. don't use "ifbp->IFB_IOBase + HREG_AUX_DATA" but
*           assign this to a temporary variable.
*
*
*  NOTE!!   For convenience of the MSF-programmer, all {IN|OUT}_PORT_{BYTE|WORD|STRING} macros are allowed to
*           modify their parameters (although some might argue that this would constitute bad coding
*           practice). This has its implications on the HCF, e.g. as a consequence these macros should not
*           be called with parameters which have side effects, e.g auto-increment.
*
*  NOTE!!   in the Micosoft implementation of inline assembly it is O.K. to corrupt all flags except
*           the direction flag and to corrupt all registers except the segment registers and EDI, ESI,
*           ESP and EBP (or their 16 bits equivalents).
*           Other environments may have other constraints
*
*  NOTE!!   in the Intel environment it is O.K to have a word (as a 16 bits quantity) at a byte boundary,
*           hence IN_/OUT_PORT_STRING can move words between PC-memory and NIC-memory with as only
*           constraint that the the words are on a word boundary in NIC-memory. This does not hold true
*           for all conceivalble environments, e.g. an Motorola 68xxx does not allow this, in other
*           words whenever there is a move from address in 2*n in one memory type to address 2*m+1 in the
*           other type, the current templates for IN_/OUT_PORT_STRING are unsuitable. Probably the
*           boundary conditions imposed by these type of platforms prevent this case from materializing
*
*************************************************************************************************/

// Note:
// Visual C++ 1.5 : _MSC_VER ==  800
// Visual C++ 4.0 : _MSC_VER == 1000
// Visual C++ 4.2 : _MSC_VER == 1020

/* typedef unsigned char                hcf_8;
 * typedef unsigned short               hcf_16;
 * typedef unsigned long                hcf_32;
 *
 * All 16 sections defined at april 2, 1999 contained the same typedefs for hcf_8/16/32
 * This seems to warrant till other requirements pop up, to make these typedefs global
 * rather than module specific
 */

/************************************************************************************************/
/******************************  M I N I P O R T    N D I S  3.1  *******************************/
/************************************************************************************************/

#if defined WVLAN_41

#define MSF_COMPONENT_ID            COMP_ID_MINIPORT_NDIS_31
#define HCF_STA                     //station characteristics

#include <ndis.h>
#include <version.h>

#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     TPI_MAJOR_VERSION
#define MSF_COMPONENT_MINOR_VER     TPI_MINOR_VERSION

#define DUI_COMPAT_BOT              5
#define DUI_COMPAT_TOP              5


//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

__inline UCHAR NDIS_IN_BYTE( ULONG port )
{
    UCHAR value;
    NdisRawReadPortUchar(port , &value);
    return (value);
}

__inline USHORT NDIS_IN_WORD( ULONG port )
{
    USHORT value;
    NdisRawReadPortUshort(port , &value);
    return (value);
}

#define IN_PORT_BYTE(port)          NDIS_IN_BYTE( (ULONG) (port) )
#define IN_PORT_WORD(port)          NDIS_IN_WORD( (ULONG) (port) )
#define OUT_PORT_BYTE(port, value)  NdisRawWritePortUchar( (ULONG) (port) , (UCHAR) (value))
#define OUT_PORT_WORD(port, value)  NdisRawWritePortUshort((ULONG) (port) , (USHORT) (value))

#define IN_PORT_STRING(port, addr, len)     NdisRawReadPortBufferUshort(port, addr, (len));
#define OUT_PORT_STRING(port, addr, len)    NdisRawWritePortBufferUshort(port, addr, (len));

typedef UCHAR   hcf_8;
typedef USHORT  hcf_16;
typedef ULONG   hcf_32;

#endif  /* WVLAN_41 MINIPORT 3.1 */




/************************************************************************************************/
/******************************                                   *******************************/
/************************************************************************************************/

#if defined WVLAN_41B

#define MSF_COMPONENT_ID            COMP_ID_MINIPORT_NDIS_31 //  HomeLAN Driver
#define HCF_STA                     //station characteristics
#define HCF_AP                      //ap characteristics

#include <ndis.h>
#include <version.h>

//#define HCF_HSI_VAR_2             2

#define MSF_COMPONENT_VAR           2
#define MSF_COMPONENT_MAJOR_VER     TPI_MAJOR_VERSION
#define MSF_COMPONENT_MINOR_VER     TPI_MINOR_VERSION

#define DUI_COMPAT_VAR 0 //Variant set to 0 until DUI implementation of WVLAN49 is accepted
#define DUI_COMPAT_BOT              1
#define DUI_COMPAT_TOP              1

// Added for STAP driver to have STA 1,7,7
#define HCF_CFG_STA_1_BOTTOM        7

//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

__inline UCHAR NDIS_IN_BYTE( ULONG port )
{
    UCHAR value;
    NdisRawReadPortUchar(port , &value);
    return (value);
}

__inline USHORT NDIS_IN_WORD( ULONG port )
{
    USHORT value;
    NdisRawReadPortUshort(port , &value);
    return (value);
}

#define IN_PORT_BYTE(port)          NDIS_IN_BYTE( (ULONG) (port) )
#define IN_PORT_WORD(port)          NDIS_IN_WORD( (ULONG) (port) )
#define OUT_PORT_BYTE(port, value)  NdisRawWritePortUchar( (ULONG) (port) , (UCHAR) (value))
#define OUT_PORT_WORD(port, value)  NdisRawWritePortUshort((ULONG) (port) , (USHORT) (value))

#define IN_PORT_STRING(port, addr, len)     NdisRawReadPortBufferUshort(port, addr, (len));
#define OUT_PORT_STRING(port, addr, len)    NdisRawWritePortBufferUshort(port, addr, (len));

typedef UCHAR   hcf_8;
typedef USHORT  hcf_16;
typedef ULONG   hcf_32;

#endif  /* WVLAN_41B MINIPORT 3.1 */



/************************************************************************************************/
/****************************  P A C K E T   D R I V E R  ***************************************/
/**********************************  D O S   O D I  *********************************************/
/************************************************************************************************/

#if defined WVLAN_42 || defined WVLAN_43|| defined WVLAN43L

#pragma warning ( disable: 4001 )
                                        
#define HCF_STA                     //station characteristics

#if defined WVLAN_43
#define MSF_COMPONENT_ID            COMP_ID_ODI_16
#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     6
#define MSF_COMPONENT_MINOR_VER     0

//#define HCF_CFG_STA_1_BOTTOM 2

//#define   HCF_MAX_CONFIG              0
//#define HCF_DOWNLOAD_OFF
//#define HCF_MB_OFF


#elif defined WVLAN_42
#define MSF_COMPONENT_ID            COMP_ID_PACKET
#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     6
#define MSF_COMPONENT_MINOR_VER     0

#elif defined WVLAN43L
#define HCF_MAX_CONFIG              0

#define MSF_COMPONENT_MAJOR_VER     0
#define MSF_COMPONENT_MINOR_VER     1

#endif //WVLAN_xx

#define HCF_MAX_GROUP       16      // number of Multicast Addresses supported by ODI/Packet
                                        
#define FAR  __far                  // segmented 16 bits mode
#if defined _M_I86TM
#define BASED __based(__segname("_CODE"))
#endif // _M_I86TM

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#include <stdio.h>
#include <conio.h>
#ifndef _DEBUG
#pragma intrinsic( _inp, _inpw, _outp, _outpw )
#endif // _DEBUG

#define IN_PORT_BYTE(port)          ((hcf_8)_inp( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)_inpw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  ((void)_outp( (hcf_io)(port), value ))
#define OUT_PORT_WORD(port, value)  ((void)_outpw( (hcf_io)(port), value ))

#if defined HCF_STRICT
#define IN_PORT_STRING( prt, dst, n)    { ips( prt, dst, n); }
#define OUT_PORT_STRING( prt, dst, n)   { ops( prt, dst, n); }
#elif 0     // C implementation which let the processor handle the word-at-byte-boundary problem
#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16 FAR*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16 FAR*)src ) ; src  += 2; }
#elif 0     // C implementation which handles the word-at-byte-boundary problem 
#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { int i = IN_PORT_WORD( prt ); *dst++ = (char)i; *dst++ = (char)(i >> 8); }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *src | *(src+1)<<8  ) ; src  += 2; }
//;?  WHY hcf_16 FAR*)src and not unsigned char FAR*)src
#else                                               // Assembler implementation
#define IN_PORT_STRING( port, dest, len) __asm      \
{                                                   \
    __asm push di                                   \
    __asm push es                                   \
    __asm mov cx,len                                \
    __asm les di,dest                               \
    __asm mov dx,port                               \
    __asm rep insw                                  \
    __asm pop es                                    \
    __asm pop di                                    \
}

#define OUT_PORT_STRING( port, src, len) __asm      \
{                                                   \
    __asm push si                                   \
    __asm push ds                                   \
    __asm mov cx,len                                \
    __asm lds si,src                                \
    __asm mov dx,port                               \
    __asm rep outsw                                 \
    __asm pop ds                                    \
    __asm pop si                                    \
}

#endif  // Asm or C implementation

#endif  /* WVLAN_43, WVLAN_42 (DOS ODI, Packet Driver) */


/************************************************************************************************/
/****************************  N E T W A R E   3 8 6  *******************************************/
/************************************************************************************************/

#if defined  __NETWARE_386__    /* WVLAN_44, WATCOM */

#define MSF_COMPONENT_ID            COMP_ID_ODI_32
#define HCF_STA                     //station characteristics

#include <conio.h>

//#define CNV_LITTLE_TO_INT(x) (x)          // No endianess conversion needed

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define IN_PORT_BYTE(port)          ((hcf_8)inp( (hcf_io)(port) ))  //;?leave out cast to hcf_8;?
#define IN_PORT_WORD(port)          (inpw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  (outp( (hcf_io)(port), value ))
#define OUT_PORT_WORD(port, value)  (outpw( (hcf_io)(port), value ))

#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16*)src ) ; src  += 2; }

#endif  // WVLAN_44, __NETWARE_386__


/************************************************************************************************/
/***********************************  M A C  O S   **********************************************/
/************************************************************************************************/

                        /**********/
#if defined WVLAN_45    /* MAC_OS */
                        /**********/
#include "Version.h"

#define HCF_STA                     //station characteristics
#define MSF_COMPONENT_ID            COMP_ID_MAC_OS
#define MSF_COMPONENT_VAR           VARIANT
#define MSF_COMPONENT_MAJOR_VER     VERSION_MAJOR
#define MSF_COMPONENT_MINOR_VER     VERSION_MINOR

#define MAC_OS                      1

#define HCF_BIG_ENDIAN              // selects Big Endian (a.k.a. Motorola), most significant byte first

#if defined(DEBUG)
#define HCF_ASSERT                  1
#endif // DEBUG

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#ifdef  __cplusplus
extern "C" {
#endif
extern volatile unsigned char *MacIOaddr;
extern hcf_8  IN_PORT_BYTE(hcf_16 port);
extern void   OUT_PORT_BYTE(hcf_16 port, hcf_8 value);
extern hcf_16 IN_PORT_WORD(hcf_16 port);
extern void   OUT_PORT_WORD(hcf_16 port, hcf_16 value);
extern void   IN_PORT_STRING(hcf_16 port, void *dest, hcf_16 len);
extern void   OUT_PORT_STRING(hcf_16 port, void *src, hcf_16 len);

#define SwapBytes(t)    (((t) >> 8) + (((t) & 0xff) << 8))

#ifdef  __cplusplus
}
#endif

#endif  /* WVLAN_45, MAC_OS */

/************************************************************************************************/
/***********************************  W I N C E *************************************************/
/************************************************************************************************/

                  /*******************/
#ifdef _WIN32_WCE /* WVLAN_46, WINCE */
                  /*******************/

#define MSF_COMPONENT_ID            COMP_ID_WIN_CE
#define HCF_STA                     //station characteristics

#include <ndis.h>
#include <ntcompat.h>
#include "version.h"
#include "debug.h"

#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     WVLAN46_MAJOR_VERSION
#define MSF_COMPONENT_MINOR_VER     WVLAN46_MINOR_VERSION

#define HCF_LITTLE_ENDIAN

#define HCF_MEM_IO                  // overrule standard Port I/O with Memory mapped I/O

#if defined(DEBUG) || defined(_WIN32_WCE_DEBUG)
#define HCF_ASSERT                  1
#endif // DEBUG || _WIN32_WCE_DEBUG

typedef UCHAR   hcf_8 ;
typedef USHORT  hcf_16 ;
typedef ULONG   hcf_32 ;

extern hcf_8  IN_PORT_BYTE(hcf_32 port);
extern void   OUT_PORT_BYTE(hcf_32 port, hcf_8 value);
extern hcf_16 IN_PORT_WORD(hcf_32 port);
extern void   OUT_PORT_WORD(hcf_32 port, hcf_16 value);
extern void   IN_PORT_STRING(hcf_32 port, void *dest, hcf_16 len);
extern void   OUT_PORT_STRING(hcf_32 port, void *src, hcf_16 len);

#endif  /* WVLAN_46, _WIN32_WCE */


/************************************************************************************************/
/******************************************  L I N U X  *****************************************/
/************************************************************************************************/

#if defined WVLAN_47 || defined WVLAN_49

#define HCF_HSI_VAR 1 // Temp. change to accept (SHARK) cards w/o RID FD09
#define HCF_HSI_VAR_0             // Controlled Deployment
#define HCF_HSI_VAR_1             // WaveLAN
#define HCF_HSI_VAR_2             // MiniPCI (was HomeLAN)

#define HCF_STA                     //station characteristics
#if defined WVLAN_47
#define MSF_COMPONENT_ID    COMP_ID_LINUX_PD
#endif // WVLAN_47
#if defined WVLAN_49
#define MSF_COMPONENT_ID    COMP_ID_LINUX_LIB
#endif // WVLAN_49

#define MSF_COMPONENT_VAR           1

#include <linux/module.h>
#include <asm/io.h>
#include <linux/types.h>

//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

typedef __u8                        hcf_8;
typedef __u16                       hcf_16;
typedef __u32                       hcf_32;

#define IN_PORT_BYTE(port)          ((hcf_8)inb( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)inw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  (outb( (hcf_8) (value), (hcf_io)(port) ))
#define OUT_PORT_WORD(port, value)  (outw( (hcf_16) (value), (hcf_io)(port) ))
#define IN_PORT_STRING(port, dst, n)    (insw((hcf_io)(port), dst, n))
#define OUT_PORT_STRING(port, src, n)   (outsw((hcf_io)(port), src, n))

#endif  /* LINUX */


/************************************************************************************************/
/******************************  M I N I P O R T    N D I S  5.0  *******************************/
/************************************************************************************************/

#if defined WVLAN_48

#define MSF_COMPONENT_ID            COMP_ID_MINIPORT_NDIS_50
#define HCF_STA                     //station characteristics

#include <ndis.h>
#include <version.h>

#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     TPI_MAJOR_VERSION
#define MSF_COMPONENT_MINOR_VER     TPI_MINOR_VERSION

#define DUI_COMPAT_BOT              5
#define DUI_COMPAT_TOP              5


//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

__inline UCHAR NDIS_IN_BYTE( ULONG port )
{
    UCHAR value;
    NdisRawReadPortUchar(port , &value);
    return (value);
}

__inline USHORT NDIS_IN_WORD( ULONG port )
{
    USHORT value;
    NdisRawReadPortUshort(port , &value);
    return (value);
}

#define IN_PORT_BYTE(port)          NDIS_IN_BYTE( (ULONG) (port) )
#define IN_PORT_WORD(port)          NDIS_IN_WORD( (ULONG) (port) )
#define OUT_PORT_BYTE(port, value)  NdisRawWritePortUchar( (ULONG) (port) , (UCHAR) (value))
#define OUT_PORT_WORD(port, value)  NdisRawWritePortUshort((ULONG) (port) , (USHORT) (value))

#define IN_PORT_STRING(port, addr, len)     NdisRawReadPortBufferUshort(port, addr, (len));
#define OUT_PORT_STRING(port, addr, len)    NdisRawWritePortBufferUshort(port, addr, (len));

typedef UCHAR   hcf_8;
typedef USHORT  hcf_16;
typedef ULONG   hcf_32;

#endif  /* WVLAN_48 MINIPORT 5.0 */

/************************************************************************************************/
/*********************************************  Q N X  ******************************************/
/************************************************************************************************/

#if defined  __QNX__ || defined WVLAN_50

#define HCF_STA                     //station characteristics

#define MSF_COMPONENT_ID        0   //Although there is no DUI support, we need this to get ...
#define MSF_COMPONENT_VAR       0   //...compatibilty check to function
#define MSF_COMPONENT_MAJOR_VER 0   //...;?this is worth looking into to make this a more
#define MSF_COMPONENT_MINOR_VER 0   //..."defined" I/F so OEMers can figure out what to do

#include <conio.h>

//#define CNV_LITTLE_TO_INT(x)      // No endianess conversion needed                                       

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define IN_PORT_BYTE(port)          ((hcf_8)inp( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)inpw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  (outp((hcf_io)(port), (hcf_8) (value)))
#define OUT_PORT_WORD(port, value)  (outpw( (hcf_io)(port), (hcf_16) (value) ))
#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16*)src ) ; src  += 2; }

#endif  /* QNX || WVLAN_50 */



/************************************************************************************************/
/******************************  M I N I P O R T    N D I S  4    *******************************/
/************************************************************************************************/

#if defined WVLAN_51

#define MSF_COMPONENT_ID            COMP_ID_MINIPORT_NDIS_31
#define HCF_STA                     //station characteristics

#include <ndis.h>
#include <version.h>

#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     TPI_MAJOR_VERSION
#define MSF_COMPONENT_MINOR_VER     TPI_MINOR_VERSION

#define DUI_COMPAT_BOT              5
#define DUI_COMPAT_TOP              5


//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

__inline UCHAR NDIS_IN_BYTE( ULONG port )
{
    UCHAR value;
    NdisRawReadPortUchar(port , &value);
    return (value);
}

__inline USHORT NDIS_IN_WORD( ULONG port )
{
    USHORT value;
    NdisRawReadPortUshort(port , &value);
    return (value);
}

#define IN_PORT_BYTE(port)          NDIS_IN_BYTE( (ULONG) (port) )
#define IN_PORT_WORD(port)          NDIS_IN_WORD( (ULONG) (port) )
#define OUT_PORT_BYTE(port, value)  NdisRawWritePortUchar( (ULONG) (port) , (UCHAR) (value))
#define OUT_PORT_WORD(port, value)  NdisRawWritePortUshort((ULONG) (port) , (USHORT) (value))

#define IN_PORT_STRING(port, addr, len)     NdisRawReadPortBufferUshort(port, addr, (len));
#define OUT_PORT_STRING(port, addr, len)    NdisRawWritePortBufferUshort(port, addr, (len));

typedef UCHAR   hcf_8;
typedef USHORT  hcf_16;
typedef ULONG   hcf_32;

#endif  /* WVLAN_51 MINIPORT 4 */

/************************************************************************************************/
/******************************************  FreeBSD  *******************************************/
/************************************************************************************************/

#if defined __FREE_BSD__

#define HCF_STA                                     //station characteristics
#define MSF_COMPONENT_ID            COMP_ID_FreeBSD
#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     1
#define MSF_COMPONENT_MINOR_VER     0

#define HCF_MAX_MSG                 2048            // overrule standard WaveLAN Pakket Size of 1514 with 2048
#define HCF_MEM_IO                                  // overrule standard Port I/O with Memory mapped I/O

#include <machine/cpufunc.h>

//#define CNV_LITTLE_TO_INT(x)                      // No endianess conversion needed

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define IN_PORT_BYTE(port)          ((hcf_8)inb( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)inw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  (outb((hcf_io)(port), (hcf_8)(value)))
#define OUT_PORT_WORD(port, value)  (outw((hcf_io)(port), (hcf_16)(value)))

#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16*)src ) ; src  += 2; }

#endif  /* FreeBSD */


/************************************************************************************************/
/*********************************  W A V E P O I N T  ******************************************/
/************************************************************************************************/

#if defined WVLAN_81    /* BORLANDC */

#define HCF_AP                          //access point characteristics
#define HCF_IFB_SECURE              1   //IFB is secure in WavePOINT, HCF can restore WEP keys
#define MSF_COMPONENT_ID    COMP_ID_AP1
#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     4
#define MSF_COMPONENT_MINOR_VER     0

#define HCF_PROT_TIME               49  //49*10240 microseconds H/W failure protection timer                

#include <dos.h>

//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

//#define HCF_ASSERT                    0  /* debug build only */

#if !defined FAR
#define FAR  far                    // segmented 16 bits mode
#endif //!defined FAR


#define IN_PORT_BYTE(port)                  (inportb( (hcf_io)(port) ))
#define IN_PORT_WORD(port)                  (inport( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)          (outportb( (hcf_io)(port), value ))
#define OUT_PORT_WORD(port, value)          (outport( (hcf_io)(port), value ))

#define IN_PORT_STRING(port, addr, len)     \
    asm { push di; push es; mov cx,len; les di,addr; mov dx,port; rep insw; pop es; pop di }

#define OUT_PORT_STRING(port, addr, len)    \
    asm { push si; push ds; mov cx,len; lds si,addr; mov dx,port; rep outsw; pop ds; pop si }

#endif /* WVLAN_81 WavePoint */


/************************************************************************************************/
/********************************  W A V E L A U N C H  *****************************************/
/************************************************************************************************/

#if defined WVLAUNCH

#include "DriverX.h"
extern HWDEVICE*    g_pDevice;

//#define   MSF_COMPONENT_ID            0  //;? to get around browser problem
#define HCF_STA                     //station characteristics

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;



#define IN_PORT_WORD(port)  HwInpw( g_pDevice, port )
#define OUT_PORT_WORD(port, value)  HwOutpw( g_pDevice, port, value )
#define IN_PORT_BYTE(port)  HwInp( g_pDevice, port )
#define OUT_PORT_BYTE(port, value)  HwOutp( g_pDevice, port, value )


// C implementation which let the processor handle the word-at-byte-boundary problem
#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16 FAR*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16 FAR*)src ) ; src  += 2; }

#endif //WVLAUNCH

/************************************************************************************************/
/*************************************  W C I T S T *********************************************/
/************************************************************************************************/

#if defined WCITST
#define MSF_COMPONENT_ID        0   //Although there is no DUI support, we need this to get ...
#define MSF_COMPONENT_VAR       0   //...compatibilty check to function
#define MSF_COMPONENT_MAJOR_VER 0   //...;?this is worth looking into to make this a more
#define MSF_COMPONENT_MINOR_VER 0   //..."defined" I/F so OEMers can figure out what to do

#pragma warning ( disable: 4001 )
                                        
#define HCF_STA                     //station characteristics
#define HCF_AP                      //AccesPoint characteristics

//#define HCF_DOWNLOAD_OFF
//#define HCF_MB_OFF

#if !defined _CONSOLE
#define FAR  __far                  // segmented 16 bits mode
#if defined _M_I86TM
#define BASED __based(__segname("_CODE"))
#endif // _M_I86TM
#endif  //_CONSOLE

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#include <stdio.h>
#include <conio.h>
#ifndef _DEBUG
#pragma intrinsic( _inp, _inpw, _outp, _outpw )
#endif // _DEBUG

#ifdef LOG
extern FILE* utm_logfile;
hcf_16  ipw( hcf_16 port );
hcf_8   ipb( hcf_16 port );
void    opw( hcf_16 port, hcf_16 value );
void    opb( hcf_16 port, hcf_8 value );

#define IN_PORT_BYTE(port)          ipb( (hcf_io)(port) )
#define IN_PORT_WORD(port)          ipw( (hcf_io)(port) )
#define OUT_PORT_BYTE(port, value)  opb( (hcf_io)(port), (hcf_8)(value) )
#define OUT_PORT_WORD(port, value)  opw( (hcf_io)(port), (hcf_16)(value) )
#else //LOG
#define IN_PORT_BYTE(port)          ((hcf_8)_inp( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)_inpw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  ((void)_outp( (hcf_io)(port), value ))
#define OUT_PORT_WORD(port, value)  ((void)_outpw( (hcf_io)(port), value ))
#endif //LOG

#define toch_maar_geen_asm
#if defined(toch_maar_asm)  && !defined(__DA_C__)  //;? temporary solution to satisfy DA-C
#define IN_PORT_STRING( port, dest, len) __asm      \
{                                                   \
    __asm push di                                   \
    __asm push es                                   \
    __asm mov cx,len                                \
    __asm les di,dest                               \
    __asm mov dx,port                               \
    __asm rep insw                                  \
    __asm pop es                                    \
    __asm pop di                                    \
}

#define OUT_PORT_STRING( port, src, len) __asm      \
{                                                   \
    __asm push si                                   \
    __asm push ds                                   \
    __asm mov cx,len                                \
    __asm lds si,src                                \
    __asm mov dx,port                               \
    __asm rep outsw                                 \
    __asm pop ds                                    \
    __asm pop si                                    \
}

#else   //toch_maar_asm  && !__DA_C__
#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16 FAR*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16 FAR*)src ) ; src  += 2; }
//;?  WHY hcf_16 FAR*)src and not unsigned char FAR*)src
#endif  //toch_maar_asm  && !__DA_C__

#endif  /* WCITST */

/************************************************************************************************/
/********************************************  W S U  *******************************************/
/************************************************************************************************/

#if 0 //;? conflicts with WIN_CE _MSC_VER >= 1000   /* Microsoft Visual C ++ 4.x, 5.x */

// Note:
// Visual C++ 4.0 : _MSC_VER == 1000
// Visual C++ 4.2 : _MSC_VER == 1020

                                        
#pragma warning ( disable: 4001 )
                                        
#define HCF_STA                     //station characteristics

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#include <stdio.h>
#include <conio.h>

#define IN_PORT_BYTE(port)          ((hcf_8)_inp( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)_inpw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  ((void)_outp( (hcf_io)(port), value ))
#define OUT_PORT_WORD(port, value)  ((void)_outpw( (hcf_io)(port), value ))

#define toch_maar_geen_asm
#if defined(toch_maar_asm)
#define IN_PORT_STRING( port, dest, len) __asm      \
{                                                   \
    __asm push di                                   \
    __asm push es                                   \
    __asm mov cx,len                                \
    __asm les di,dest                               \
    __asm mov dx,port                               \
    __asm rep insw                                  \
    __asm pop es                                    \
    __asm pop di                                    \
}

#define OUT_PORT_STRING( port, src, len) __asm      \
{                                                   \
    __asm push si                                   \
    __asm push ds                                   \
    __asm mov cx,len                                \
    __asm lds si,src                                \
    __asm mov dx,port                               \
    __asm rep outsw                                 \
    __asm pop ds                                    \
    __asm pop si                                    \
}

#else   //toch_maar_asm
#define IN_PORT_STRING( prt, dst, n)    while ( n-- ) { *(hcf_16*)dst = IN_PORT_WORD( prt ); dst += 2; }
#define OUT_PORT_STRING( prt, src, n)   while ( n-- ) { OUT_PORT_WORD( prt, *(hcf_16*)src ) ; src  += 2; }
#endif  //toch_maar_asm

#endif  /* _MSC_VER >= 1000 (Microsoft Visual C++ 4.0 ) */




/************************************************************************************************/
/********************************** S C O   U N I X  ********************************************/
/************************************************************************************************/

#if 0

#define HCF_STA                     //station characteristics
#define MSF_COMPONENT_ID

//#define CNV_LITTLE_TO_INT(x)          // No endianess conversion needed                                       

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define IN_PORT_BYTE(port)          ((hcf_8)inb( (hcf_io)(port) ))
#define IN_PORT_WORD(port)          ((hcf_16)inw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  (outb( (hcf_io)(port), (hcf_8) (value) ))
#define OUT_PORT_WORD(port, value)  (outw( (hcf_io)(port), (hcf_16) (value) ))

#endif  /* SCO UNIX */


/************************************************************************************************/
/**********************************   Diab or High C 29K   **************************************/
/************************************************************************************************/
/* known users: GK, JW
 */

#if defined(__ppc) || defined(_AM29K)

#define HCF_AP                      //AccesPoint characteristics
#define MSF_COMPONENT_VAR       0
#define MSF_COMPONENT_ID        0
#define MSF_COMPONENT_MAJOR_VER 1
#define MSF_COMPONENT_MINOR_VER 0

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define SwapBytes(t)    /*lint -e572*/(((t) >> 8) + (((t) & 0xff) << 8))/*lint +e572*/

#if defined(__ppc)
    #ifndef __GNUC__
        #define __asm__     asm
    #endif

    #if !defined(_lint)
        #define EIEIO()     __asm__(" eieio")
    #else
        #define EIEIO()
    #endif

    static hcf_8 IN_PORT_BYTE(int port) {
        hcf_8 value = *(volatile hcf_8 *)(port); EIEIO();
        return value;
    }

    static hcf_16 IN_PORT_WORD(int port) {
        hcf_16 value = *(volatile hcf_16 *)(port); EIEIO();
        value = SwapBytes(value);
        return value;
    }

    #define OUT_PORT_BYTE(port, value) { *(volatile hcf_8 *)(port) = (value); EIEIO(); }
    #define OUT_PORT_WORD(port, value)      \
            { *(volatile hcf_16 *)(port) = SwapBytes(value); EIEIO(); }
#else
    #define IN_PORT_BYTE(port) (*(volatile hcf_8 *)(port))
    #define IN_PORT_WORD(port) (*(volatile hcf_16 *)(port))
    #define OUT_PORT_BYTE(port, value) (*(volatile hcf_8 *)(port) = (value))
    #define OUT_PORT_WORD(port, value) (*(volatile hcf_16 *)(port) = (value))
#endif

/***************************************************************************/

#define IN_PORT_STRING( port, dest, len)        {                       \
                        unsigned l = (len);                             \
                        hcf_16 t, *d = (volatile hcf_16 *)(dest);       \
                        while (l--) {                                   \
                            t = IN_PORT_WORD(port);                     \
                            *d++ = SwapBytes(t);                        \
                        }                                               \
                                                }

#define OUT_PORT_STRING( port, src, len)        {                       \
                        unsigned l = (len);                             \
                        hcf_16 t, *s = (volatile hcf_16 *)(src);        \
                        while (l--) {                                   \
                            t = *s++;                                   \
                            OUT_PORT_WORD(port, SwapBytes(t));          \
                        }                                               \
                                                }

#if PRODUCT == 9150
    #define HCF_AP
    #define HCF_ASSERT
    #undef MSF_COMPONENT_ID
#endif

#endif  /* Diab or High C 29K */


/************************************************************************************************/
/*****************************************  MPC860 **********************************************/
/************************************************************************************************/
/* known users: RR
 */

#if defined CPU && CPU == PPC860

#define HCF_AP                      //AccesPoint characteristics
#define MSF_COMPONENT_VAR       0
#define MSF_COMPONENT_ID        0
#define MSF_COMPONENT_MAJOR_VER 1
#define MSF_COMPONENT_MINOR_VER 0

#define HCF_BIG_ENDIAN
#define HCF_MEM_IO

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define SwapBytes(t)    /*lint -e572*/(((t) >> 8) + (((t) & 0xff) << 8))/*lint +e572*/

#ifndef __GNUC__
    #define __asm__     asm
#endif

#if !defined(_lint)
    #define EIEIO()     __asm__(" eieio")
#else
    #define EIEIO()
#endif

static hcf_8 IN_PORT_BYTE(int port) {
    hcf_8 value = *(volatile hcf_8 *)(port); EIEIO();
    return value;
}

static hcf_16 IN_PORT_WORD(int port) {
    hcf_16 value = *(volatile hcf_16 *)(port); EIEIO();
    value = SwapBytes(value);
    return value;
    #ifdef __GNUC__
        /* the following serves to avoid the compiler warnings that
         * IN_PORT_BYTE() or IN_PORT_WORD() is not used in some files */
        (void)IN_PORT_BYTE;
        (void)IN_PORT_WORD;
    #endif
}

#define OUT_PORT_BYTE(port, value) { *(volatile hcf_8 *)(port) = (value); EIEIO(); }
#define OUT_PORT_WORD(port, value)      \
        { *(volatile hcf_16 *)(port) = SwapBytes(value); EIEIO(); }

/***************************************************************************/

#define IN_PORT_STRING( port, dest, len)        {                       \
                        unsigned l = (len);                             \
                        hcf_16 t;                                       \
                        volatile hcf_16 *d = (volatile hcf_16 *)(dest); \
                        while (l--) {                                   \
                            t = IN_PORT_WORD(port);                     \
                            *d++ = SwapBytes(t);                        \
                        }                                               \
                                                }

#define OUT_PORT_STRING( port, src, len)        {                       \
                        unsigned l = (len);                             \
                        hcf_16 t;                                       \
                        volatile hcf_16 *s = (volatile hcf_16 *)(src);  \
                        while (l--) {                                   \
                            t = *s++;                                   \
                            OUT_PORT_WORD(port, SwapBytes(t));          \
                        }                                               \
                                                }

#if PRODUCT == 9150
//?    #define HCF_AP
    #define HCF_ASSERT
    #undef MSF_COMPONENT_ID
#endif

#endif  /* PPC860 */

/************************************************************************************************/
/****************************  Microtec Research 80X86 Compiler *********************************/
/************************************************************************************************/

#if 0

#define HCF_STA                     /*station characteristics*/

#define MSF_COMPONENT_VAR       0
#define MSF_COMPONENT_ID        0
#define MSF_COMPONENT_MAJOR_VER 1
#define MSF_COMPONENT_MINOR_VER 0

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

extern int far inp( int );
extern void far outp( int, int );
extern int far inpw( int );
extern void far outpw( int, int );

#define IN_PORT_BYTE(port)      ((hcf_8)inp( (hcf_io)(port) ))
#define IN_PORT_WORD(port)      ((hcf_16)inpw( (hcf_io)(port) ))
#define OUT_PORT_BYTE(port, value)  ((void)outp( (hcf_io)(port), value ))
#define OUT_PORT_WORD(port, value)  ((void)outpw( (hcf_io)(port), value ))

#define IN_PORT_STRING( port, dest, len)        {                       \
                        unsigned l = (len);                             \
                        hcf_16 *d = (hcf_16 *)(dest);                   \
                        while (l--) *d++ =  IN_PORT_WORD(port);         \
                                                }

#define OUT_PORT_STRING( port, src, len)        {                       \
                        unsigned l = (len);                             \
                        hcf_16 *s = (hcf_16 *)(src);                    \
                        while (l--) OUT_PORT_WORD(port, *s++);          \
                                                }
#endif  /* Microtec 80X86 C Compiler */



/************************************************************************************************/
/******************************  W A V E L A N  E C  ********************************************/
/************************************************************************************************/
/* known users: KM
 */

               /*********/
#ifdef mc68302 /* LC302 */
               /*********/

#define MSF_COMPONENT_ID            COMP_ID_EC
#define HCF_STA                     //station characteristics

#include <version.h>

#define MSF_COMPONENT_VAR           1
#define MSF_COMPONENT_MAJOR_VER     MAJOR_VERSION
#define MSF_COMPONENT_MINOR_VER     MINOR_VERSION

#define HCF_BIG_ENDIAN
#define HCF_MEM_IO

typedef unsigned char               hcf_8;
typedef unsigned short              hcf_16;
typedef unsigned long               hcf_32;

#define SwapBytes(t)    /*lint -e572*/(((t) >> 8) + (((t) & 0xff) << 8))/*lint +e572*/

#define PCMCIA_ADDRESS 0xc80000UL

#define IN_PORT_BYTE(port)               (*(hcf_8 *)(port))
#define IN_PORT_2BYTES(port)             (*(hcf_16 *)(port))
#if 0
static hcf_16 IN_PORT_WORD(hcf_32 port) // should be hcf_io, not hcf_32
{
  hcf_16 word = IN_PORT_2BYTES(port);
  return SwapBytes(word);
}
#else
static hcf_16 swap_var;
#define IN_PORT_WORD(port) \
  (((swap_var = IN_PORT_2BYTES(port)) >> 8) + (((swap_var) & 0xff) << 8))
#endif
#define OUT_PORT_BYTE(port, value)       (*(hcf_8 *)(port) = (hcf_8)(value))
#define OUT_PORT_2BYTES(port, value)     (*(hcf_16 *)(port) = (hcf_16)(value))
#define OUT_PORT_WORD(port, value)       OUT_PORT_2BYTES(port, SwapBytes(value))

#define IN_PORT_STRING(port, dest, len)   while ((len)--) {*(hcf_16 *)(dest) = IN_PORT_2BYTES(port); (dest) += 2; }
#define OUT_PORT_STRING(port, src, len)   while ((len)--) {OUT_PORT_2BYTES((port), *(hcf_16 *)(src)) ; (src)  += 2; }

#endif  /* mc68302 */


/************************************************************************************************/
/******************************** WaveLAN Utilities  ********************************************/
/************************************************************************************************/
/* known users: SK
 */

                    /**************************/
#ifdef WVLAN_UTIL   /* WaveLAN Utilities      */
                    /**************************/

typedef UCHAR   hcf_8;
typedef USHORT  hcf_16;
typedef ULONG   hcf_32;

#endif // SJAAK


/*  * * * * * * * * * * * * * * * * * * * * * *  IV  * * * * * * * * * * * * * * * * * * * * * * */

/***************************************Compiler specific ****************************************/

#if !defined EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif //__cplusplus
#endif //EXTERN_C


/************************************************************************************************/
/********** M A C R O S derived of C O M P I L E R   S P E C I F I C   M A C R O S  *************/
/************************************************************************************************/



#if !defined FAR
#define FAR                         // default to flat 32-bits code
#endif //!defined FAR

typedef hcf_8  FAR *wci_bufp;            // segmented 16-bits or flat 32-bits pointer to 8 bits unit
typedef hcf_16 FAR *wci_recordp;         // segmented 16-bits or flat 32-bits pointer to 16 bits unit

typedef hcf_8  FAR *hcf_8fp;             // segmented 16-bits or flat 32-bits pointer to 8 bits unit
typedef hcf_16 FAR *hcf_16fp;            // segmented 16-bits or flat 32-bits pointer to 16 bits unit
typedef hcf_32 FAR *hcf_32fp;            // segmented 16-bits or flat 32-bits pointer to 8 bits unit


#if ! defined HCF_STA && ! defined HCF_AP
error; define at least one of these terms. Note that most users need to define exactly one!!;
#endif

/*  * * * * * * * * * * * * * * * * * * * * * *  V  * * * * * * * * * * * * * * * * * * * * * * */

#if !defined HCF_PORT_IO && !defined HCF_MEM_IO
#define HCF_PORT_IO         // default to Port I/O
#endif

#if defined HCF_PORT_IO && defined HCF_MEM_IO
error;                              // you should define at most 1 of the two IO-types. Default is Port I/O
#endif

#if defined HCF_PORT_IO
typedef hcf_16 hcf_io;
#endif //HCF_PORT_IO

#if defined HCF_MEM_IO
typedef hcf_32 hcf_io;
#endif //HCF_MEM_IO



/* MSF_COMPONENT_ID is used to define the CFG_IDENTITY_STRCT in HCF.C
 * CFG_IDENTITY_STRCT is defined in HCF.C purely based on convenience arguments
 * The HCF can not have the knowledge to determine the ComponentId field of the
 * Identity record (aka as Version Record), therefore the MSF part of the Drivers
 * must supply this value via the System Constant MSF_COMPONENT_ID
 * There is a set of values predefined in MDD.H (format COMP_ID_.....)
 *
 * Note that taking MSF_COMPONENT_ID as a default value for DUI_COMPAT_VAR is
 * purely an implementation convenience, the numerical values of these two
 * quantities have none functional relationship whatsoever.
 * Originally there was only a single DUI-variant with value 1. 
 * Then it was considered advantaguous to have unique DUI-variant per driver and 
 * - as said before - out of convenience these variants where choosen to have 
 * the same numerical value as the component id of the driver.
 * Again later, it was decided that there would be two Miniport 3.1 drivers,
 * the old one continuing to have DUI-varaint and component ID 41, the new 
 * one (the STAP or HomeLAN drivr) having component ID 41 but DUI-variant 2 (since
 * 1 was already used in the past)
 */

#if defined MSF_COMPONENT_ID
#if !defined DUI_COMPAT_VAR
#define DUI_COMPAT_VAR 0 //Variant set to 0 until DUI implementation of WVLAN49 is accepted
#endif //!defined DUI_COMPAT_VAR

#if ! defined DUI_COMPAT_BOT        //;?this way utilities can lower as well raise the bottom
#define DUI_COMPAT_BOT              6
#endif // DUI_COMPAT_BOT

#if ! defined DUI_COMPAT_TOP        //;?this way utilities can lower as well raise the top
#define DUI_COMPAT_TOP              6
#endif // DUI_COMPAT_TOP

#endif // MSF_COMPONENT_ID


#if ! defined(HCF_HSI_VAR_0) && ! defined(HCF_HSI_VAR_1) && ! defined(HCF_HSI_VAR_2)
#define HCF_HSI_VAR_1               // WaveLAN
#endif


/************************************************************************************************/
/******  M S F    S U P P O R T    F U N C T I O N S    P R O T O T Y P E S   *******************/
/************************************************************************************************/


//******************************************* A L I G N M E N T  **********************************************
#if !defined HCF_ALIGN
#define HCF_ALIGN 1         //default to no alignment
#endif // HCF_ALIGN


#if HCF_ALIGN != 1 && HCF_ALIGN != 2 && HCF_ALIGN != 4 && HCF_ALIGN != 8
    error;
#endif // HCF_ALIGN != 0 && HCF_ALIGN != 2 etc




/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  
 *  The routines ips and ops (short for InPutString and OutPutString) are created to use the
 *  compiler to do the type checking. It turned out that it is too easy to accidentally pass
 *  a word pointer to the the macros IN_PORT_STRING and OUT_PORT_STRING rather than a byte pointer.
 *  The "+2" as some macro implementations use, does not have the intended effect in those cases.
 *  The HCF_STRICT business can be ignored by MSF programmers.
 *  
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#if defined HCF_STRICT
void ips( hcf_io prt, wci_bufp dst, int n);
void ops( hcf_io prt, wci_bufp src, int n);
#endif //HCF_STRICT

#if !defined HCF_MAX_GROUP
#define HCF_MAX_GROUP       16      /* historical determined number of Multicast Addresses
                                     * up to Station Supplier 4, Hermes supported a maximum of 16 addresses
                                     * to prevent side effects on existing MSFs and to prevent the need
                                     * for (messy) adaptation code, the HCF default is 16, making the
                                     * HCF default compatible with all station vesions (as far as the
                                     * Multicast aspect is concerned. It is suggested that MSFs which
                                     * want 32 addresses, limit the Station Actor range to a bottom of
                                     * at least 5                                                       */
#elif HCF_MAX_GROUP > 32
error;                              // Hermes supports up to 32 Multicast Addresses
#endif

#if !defined HCF_MAX_CONFIG
#define HCF_MAX_CONFIG      (256 + HCF_MAX_GROUP*MAC_ADDR_SIZE) /* maximum accumulated size in hcf_16 of LTV
                                                                 * records used in hcf_put_config           */
#endif

#if !defined HCF_MAX_MSG
#define HCF_MAX_MSG         1514    // WaveLAN Pakket Size
#endif

#if !defined HCF_MAX_NOTIFY     
#define HCF_MAX_NOTIFY      6       // maximum size in bytes of "real" data in Notify command
#endif

#if !defined HCF_PROT_TIME
#define HCF_PROT_TIME       256     // number of 10K microseconds protection timer against H/W malfunction
#elif HCF_PROT_TIME < 19 || HCF_PROT_TIME > 256
error;                              // below the minimum .5 second required by Hermes or above the hcf_32 capacity
#endif


/*  I/O Address size
 *  Platforms which use port mapped I/O will (in general) have a 64k I/O space, conveniently expressed in
 *  a 16-bits quantity
 *  Platforms which use memory mapped I/O will (in general) have an I/O space much larger than 64k,
 *  and need a 32-bits quantity to express the I/O base
 *  To accomodate this the macros HCF_PORT_IO and HCF_MEM_IO are available. Exactly 1 of these must be
 *  defined. If HCF_PORT_IO is defined, the HCF will use an hcf_16 to express I/O base and store in the
 *  IFB. If HCF_MEM_IO, an hcf_32 is used for this purpose. The default is HCF_PORT_IO
 */
#if !defined HCF_PORT_IO && !defined HCF_MEM_IO
#define HCF_PORT_IO                 //default to port I/O
#endif


/*  Endianess
 *  Default: HCF_LITTLE_ENDIAN
 *  Little Endian (a.k.a. Intel), least significant byte first
 *  Big Endian (a.k.a. Motorola), most significant byte first
 *
 * The following macros are supplied
 *  o CNV_LITTLE_TO_INT(w)          interprets the 16-bits input value as Little Endian, returns an hcf_16
 *  o CNV_BIG_TO_INT(w)             interprets the 16-bits input value as Big Endian, returns an hcf_16
 *  o CNV_INT_TO_BIG_NP(addr)       converts in place the 16-bit value addressed by a near pointer from hcf_16
 *                                  to Big Endian
 *  o CNV_LITTLE_TO_INT_NP(addr)    converts in place the 16-bit value addressed by a near pointer from
 *                                  Little endian to hcf_16
 *
 * At a number of places in the HCF code, the CNV_INT_TO_BIG_NP macro is used. While it does have the desired
 * effect on all platforms, it's naming is misleading, so revisit all places where these CNV macros are used
 * to assure the right name is used at the right place.
 * Hint: introduce CNV_HOST_TO_NETWORK names if appropriate
 *
 */
#if !defined HCF_LITTLE_ENDIAN && !defined HCF_BIG_ENDIAN
#define HCF_LITTLE_ENDIAN           // default to Little Endian
#endif

#if defined HCF_LITTLE_ENDIAN && defined HCF_BIG_ENDIAN
error;                              // you should define at most 1 of the two Endian-types. Default is Little Endian
#endif

/* To increase portability, use unsigned char and unsigned char * when accessing parts of larger
 * types to convert their Endianess
 */

#if defined HCF_BIG_ENDIAN
//******************************************** B I G   E N D I A N *******************************************
#define CNV_LITTLE_TO_INT(w)    ( ((hcf_16)(w) & 0x00ff) << 8 | ((hcf_16)(w) & 0xff00) >> 8 )
#define CNV_BIG_TO_INT(w)       (w)     // No endianess conversion needed

#define CNV_INT_TO_BIG_NP(addr)
#define CNV_LITTLE_TO_INT_NP(addr) {                            \
    hcf_8 temp;                                                 \
    temp = ((hcf_8 FAR *)(addr))[0];                            \
    ((hcf_8 FAR *)(addr))[0] = ((hcf_8 FAR *)(addr))[1];        \
    ((hcf_8 FAR *)(addr))[1] = temp;                            \
}

#endif // HCF_BIG_ENDIAN

#if defined HCF_LITTLE_ENDIAN
//****************************************** L I T T L E   E N D I A N ****************************************
#define CNV_LITTLE_TO_INT(w)    (w)     // No endianess conversion needed
#define CNV_BIG_TO_INT(w)       ( ((hcf_16)(w) & 0x00ff) << 8 | ((hcf_16)(w) & 0xff00) >> 8 )

#define CNV_INT_TO_BIG_NP(addr) {                               \
    hcf_8 temp;                                                 \
    temp = ((hcf_8 FAR *)(addr))[0];                            \
    ((hcf_8 FAR *)(addr))[0] = ((hcf_8 FAR *)(addr))[1];        \
    ((hcf_8 FAR *)(addr))[1] = temp;                            \
}
#define CNV_LITTLE_TO_INT_NP(addr)

#endif // HCF_LITTLE_ENDIAN

// conversion macros which can be expressed in other macros
#define CNV_INT_TO_LITTLE(w)    CNV_LITTLE_TO_INT(w)
#define CNV_INT_TO_BIG(w)       CNV_BIG_TO_INT(w)



/*************************************************************************************************************/
/******************************************** . . . . . . . . .  *********************************************/
/*************************************************************************************************************/


/* The BASED customization macro is used to resolves the SS!=DS conflict for the Interrupt Service
 * logic in DOS Drivers. Due to the cumbersomeness of mixing C and assembler local BASED variables
 * still end up in the wrong segment. The workaround is that the HCF uses only global BASED
 * variables or IFB-based variables
 * The "BASED" construction (supposedly) only amounts to something in the small memory model.
 *
 * Note that the whole BASED riggamarole is needlessly complicated because both the Microsoft Compiler and
 * Linker are unnecessary restrictive in what far pointer manipulation they allow
 */

#if !defined BASED
#define BASED
#endif

#if !defined NULL
#define NULL ((void *) 0)
#endif


#endif //HCFCFG_H

#ifndef MDD_H
#define MDD_H 1

/*************************************************************************************************************
*
* FILE   : mdd.h
*
* DATE   : $Date:   01 Feb 2000 12:02:36  $   $Revision:   4.6  $
*
* AUTHOR : Nico Valster
*
* DESC   : Definitions and Prototypes for HCF, MSF, UIL as well as USF sources
*
*
*
* Implementation Notes
*
 -  Typ rather than type is used as field names in structures like CFG_CIS_STRCT because type leads to
    conflicts with MASM when the H-file is converted to an INC-file
*
**************************************************************************************************************
Instructions to convert MDD.H to MDD.INC by means of H2INC

Use a command line which defines the specific macros and command line options
needed to build the C-part, e.g. for the DOS ODI driver
        `h2inc /C /Ni /Zp /Zn mdd    mdd.h`


**************************************************************************************************************
* COPYRIGHT (c) 1998 by Lucent Technologies.     All Rights Reserved.
*************************************************************************************************************/

/*************************************************************************************************************
*
* CHANGE HISTORY
*
  961018 - NV
    Original Entry, split of from HCF.H
*************************************************************************************************************/


/**************************************************************************************************************

*
* ToDo
*
 1: justify the "DON'T EVER MOVE" clauses, e.g. on HCF_ACT_DIAG
 2: re-think the issues around MSF_ASSERT_RTN proto type. Once the thought crosssed my mind that the problems
    could be resolved completely within COM-modules 

*
* Implementation Notes
*
 -  
    
*
* Miscellaneous Notes
*
 -  


*************************************************************************************************************/
/******************************      M A C R O S     ********************************************************/

/* min and max macros */
#if !defined(max)
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#if !defined(min)
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif


/*************************************************************************************************************/

/****************************** General define ***************************************************************/

#define MAC_ADDR_SIZE           6
#define GROUP_ADDR_SIZE         (32 * MAC_ADDR_SIZE)
#define STAT_NAME_SIZE          32



//IFB field related
//      IFB_CardStat
#define CARD_STAT_PRESENT               0x8000U /* Debug Only !!
                                                 * MSF defines card as being present
                                                 * controls whether hcf-function is allowed to do I/O       */
#define CARD_STAT_ENABLED               0x4000U /* Debug Only !!
                                                 * one or more MAC Ports enabled                            */
#define CARD_STAT_INCOMP_PRI            0x2000U // hcf_disable did not detect compatible primary functions
#define CARD_STAT_INCOMP_STA            0x1000U // hcf_disable did not detect compatible station functions
#define CARD_STAT_INCOMP_FEATURE        0x0800U /* Incompatible feature (prevents enable)
                                                 *  - HCF_CRYPT_RESTRAINT_BIT
                                                 * !! NOTE !! this bit is only cleared as side effect of 
                                                   !! HCF_ACT_CARD_IN. Dynamically clearing it if a non-
                                                   !! violating feature is set, will not work properly if
                                                   !! - some time in the future -, a 2nd feature with this
                                                   !! characteristics is created. Since Utilities protect
                                                   !! "intelligent" against this problem and Driver Config
                                                   !! files can not change dynamically, this is not a serious
                                                   !! limitation
                                                 */
#define CARD_STAT_AP                    0x0200U // Hermaphrodite in AP mode
#define CARD_STAT_DEFUNCT               0x0100U // HCF is in Defunct mode
//      IFB_RxStat
#define RX_STAT_ERR                     0x0003U //Error mask
#define     RX_STAT_UNDECR              0x0002U //Non-decryptable encrypted message
#define     RX_STAT_FCS_ERR             0x0001U //FCS error

/****************************** Xxxxxxxx *********************************************************************/

enum /*hcf_stat*/ {
//  HCF_FAILURE             = 0xFF, /* An (unspecified) failure, 0xFF is choosen to have a non-ubiquitous value
//                                   *  Note that HCF_xxxx errors which can end up in the CFG_DIAG LTV should
//                                   *  never exceed 0xFF, because the high order byte of VAL[0] is reserved
//                                   *  for Hermes errors
//                                   */
    HCF_SUCCESS             = 0x00, // 0x00: OK
    //                              // gap for ODI related status and obsolete 
    //                              // obsolete HCF_ERR_DIAG_0
    HCF_ERR_DIAG_1          = 0x03, // 0x03: HCF noticed an error after succesful diagnose command
    HCF_ERR_TIME_OUT,               // 0x04: Expected Hermes event did not occure in expected time
    HCF_ERR_NO_NIC,                 /* 0x05: card not found (usually yanked away during hcfio_in_string
                                             Also: card is either absent or disabled while it should be neither     */
    HCF_ERR_BUSY,                   // 0x06: hcf_send_diag_msg called while PIF_RscInd == 0
    HCF_ERR_SEQ_BUG,                // 0x07: other cmd than the expected completed, probably HCF-bug
    HCF_ERR_LEN,                    // 0x08: buffer size insufficient
                                    //        - hcf_get_info buffer has a size of 0 or 1 or less than needed
                                    //          to accomodate all data
    HCF_ERR_INCOMP_PRI,             // 0x09: primary functions are not compatible
    HCF_ERR_INCOMP_STA,             // 0x0A: primary functions are compatible, station functions are not
    HCF_ERR_INCOMP_FEATURE,         /* 0x0B: Incompatible feature (prevents enable)
                                     *  - HCF_CRYPT_RESTRAINT_BIT
                                     */
    HCF_ERR_DCWA,                   // DCWA (Data Corruption Work Around) catched (primarily in hcf_put_data process)
//                                  /* begin of range to skip for backward compatibilty problem circumvention       */
//  HCF_UIL_BCK_COMP_1      = 0x0B, // 0x0B was: UIL_ERR_NOT_CONNECTED
//  HCF_UIL_BCK_COMP_2      = 0X0C, // 0x0C was: UIL_ERR_PIF_CONFLICT
//  HCF_UIL_BCK_COMP_3      = 0X0D, // 0x0D was: UIL_ERR_NO_DRV
//                                  /* end of range to skip for backward compatibilty problem circumvention         */
    HCF_ERR_MAX,                    // xxxx: start value for UIL-range
    HCF_ERR_DEFUNCT         = 0x80, // BIT, reflecting that the HCF is in defunct mode (bits 0x7F reflect cause)
    HCF_ERR_DEFUNCT_INI,            // Timeout on Busy bit drop before writing Hermes Initialize command
    HCF_ERR_DEFUNCT_AUX,            // Timeout on acknowledgement on en/disabling AUX registers
    HCF_ERR_DEFUNCT_TIMER,          // Timeout on timer calibration during initialization process
    HCF_ERR_DEFUNCT_TIME_OUT,       // Timeout on Busy bit drop during BAP setup
    HCF_ERR_DEFUNCT_ALLOC,          // Allocation failed during initialization process
    HCF_ERR_DEFUNCT_CMD_SEQ,        // Hermes and HCF are out of sync in issuing/processing commands
    HCF_ERR_DEFUNCT_DL,             // DCWA did not succeed within retry limit
    HCF_ERR_DEFUNCT_FREEZE,         // freeze the F/W execution (intentionally via HCF_ACT_FREEZE)
    HCF_ERR_CMD             = 0x0100,   //"insignificant" error (see W2DN264)
    HCF_ERR_INQUIRE         = 0x0511,   // Inquiry failed due to lack of Hermes Buffer space
    
//enum /*uil_stat*/ {
//  UIL_FAILURE             = HCF_FAILURE,
    UIL_SUCCESS             = HCF_SUCCESS,
    UIL_ERR_DIAG_1          = HCF_ERR_DIAG_1,
    UIL_ERR_TIME_OUT        = HCF_ERR_TIME_OUT,
    UIL_ERR_NO_NIC          = HCF_ERR_NO_NIC,
    UIL_ERR_BUSY            = HCF_ERR_BUSY,
    UIL_ERR_SEQ_BUG         = HCF_ERR_SEQ_BUG,
    UIL_ERR_LEN             = HCF_ERR_LEN,
    UIL_ERR_PIF_CONFLICT    = 0x40,             //this is the lower boundary of UIL errors without HCF-pendant
    UIL_ERR_INCOMP_DRV,
    UIL_ERR_NO_DRV,
    UIL_ERR_DOS_CALL,
    UIL_ERR_IN_USE,
    UIL_ERR_NSTL,
    UIL_ERR_WRONG_IFB,
                                    /* begin of range to skip for backward compatibilty problem circumvention*/
    HCF_UIL_BCK_COMP_4      = 103,  // 0x67 was: UIL_ERR_INCOMP_DRV
    HCF_UIL_BCK_COMP_5      = 105   // 0x69 was: UIL_ERR_DOS_CALL
                                    /* end of range to skip for backward compatibilty problem circumvention */
//} /* uil_stat */
};

#define HCF_INT_PENDING         1   // (ODI initiated) return status of hcf_act( HCF_ACT_INT_OFF )



/* hard coded values (e.g. for HCF_ACT_TALLIES and HCF_ACT_INT_OFF) are needed for HCFL                         */
typedef enum  { /*hcf_action_cmd*/
                                        /*  gap left over by swapping 3 frame mode action with 4 INT_OFF/_ON
                                         *  CARD_IN/_OUT. This was done to have HCFL default automagically
                                         *  to HCF_ACT_802_3_PURE
                                         *  This gap available for future features                              */
    HCF_ACT_SPARE_03,                   //03 gap available for future features
                                        /* DUI code 0x04 -> DON'T EVER MOVE                                     */
    HCF_ACT_DIAG = 0x04,                //04 Hermes Diagnose command
                                        /* DUI code 0x05 -> DON'T EVER MOVE                                     */
    HCF_ACT_TALLIES = 0x05,             //05 Hermes Inquire Tallies (F100) command
    HCF_ACT_SCAN,                       //06 Hermes Inquire Scan (F101) command
                                        /* DUI code 0x0B -> DON'T EVER MOVE                                     */
                                        /* DUI code 0x0C -> DON'T EVER MOVE                                     */
    HCF_ACT_INT_OFF = 0x0D,             //0D Disable Interrupt generation
    HCF_ACT_INT_ON,                     //0E Enable Interrupt generation
    HCF_ACT_INT_FORCE_ON,               //0F Enforce Enable Interrupt generation
    HCF_ACT_CARD_IN,                    //10 MSF reported Card insertion
    HCF_ACT_CARD_OUT,                   //11 MSF reported Card removal
    HCF_ACT_FREEZE                      //12 freeze the F/W execution
/*  HCF_ACT_MAX                         // xxxx: start value for UIL-range, NOT to be passed to HCF
 *                                      Too bad, there was originally no spare room created to use
 *                                      HCF_ACT_MAX as an equivalent of HCF_ERR_MAX. Since creating
 *                                      this room in retrospect would create a backward incompatibilty
 *                                      we will just have to live with the haphazard sequence of
 *                                      UIL- and HCF specific codes. Theoretically this could be
 *                                      corrected when and if there will ever be an overall
 *                                      incompatibilty introduced for another reason
 */                                     
} hcf_action_cmd;

#define HCF_PORT_0 0                        // HCF-light supports only a single MAC Port








#define RESTRAINT_SET                   0
#define RESTRAINT_RESET                 1

#define HCF_RESTRAINT_PM                0x0001
#define HCF_RESTRAINT_CRYPT_FW          0x0002
#define HCF_RESTRAINT_CRYPT_HW          0x0004

#define MSF_RESTRAINT_CRYPT_PARM        0x0001
#define MSF_RESTRAINT_DRV_CFG           0x0002
#define MSF_RESTRAINT_NIC_CHANGE        0x0004
#define MSF_RESTRAINT_APFW_INCOMP       0x0008
#define MSF_RESTRAINT_CHANNELS_INCOMP   0x0010  /* driver can not work with the channels supported by the card.
                                                 * Channels 1-11 must be at least available.
                                                 * occures for old Japanese cards and France cards                  */




/*============================================================= HCF Defined RECORDS =========================*/
#define CFG_IFB                         0x0824      //byte wise copy of IFB
#define CFG_DRV_INFO                    0x0825      //Driver Information structure (see CFG_DRV_INFO_STRCT for details)
#define CFG_DRV_IDENTITY                0x0826      //driver identity (see CFG_DRV_IDENTITY_STRCT for details)
#define CFG_REG_MB                      0x0830      //Register Mail Box
/*============================================================= INFORMATION FRRAMES     =====================*/
#define CFG_INFO_FRAME_MIN              0xF000      //lowest value representing an Informatio Frame
    
#define CFG_TALLIES                     0xF100      //Communications Tallies
#define CFG_SCAN                        0xF101      //Scan results
                                
#define CFG_LINK_STAT                   0xF200      //Link Status
    
/*============================================================= CONFIGURATION RECORDS   =====================*/
/*============================================================= mask 0xFCxx             =====================*/                     
//  NETWORK PARAMETERS, STATIC CONFIGURATION ENTITIES
//FC05, FC0A, FC0B, FC0C, FC0D: SEE W2DN149
    
#define CFG_RID_CFG_MIN                 0xFC00      //lowest value representing a Configuration RID
#define CFG_CNF_PORT_TYPE               0xFC00      //[STA] Connection control characteristics
#define CFG_CNF_OWN_MAC_ADDR            0xFC01      //[STA] MAC Address of this node
#define     CNF_DESIRED_SSID            0xFC02      /*[STA] Service Set identification for connection
                                                     *originally known as static entity with name 
                                                     *  CFG_CNF_DESIRED_SSID
                                                     *when type changed to dynamic, name incorrectly changed to 
                                                     *  CNF_DESIRED_SSID
                                                     *finally name changed to (the "correct")
                                                     *  CFG_DESIRED_SSID
                                                     *CNF_DESIRED_SSID will be discarded some time in the future
                                                     */
#define CFG_CNF_OWN_CHANNEL             0xFC03      //Communication channel for BSS creation
#define CFG_CNF_OWN_SSID                0xFC04      //IBSS creation (STA) or ESS (AP) Service Set Ident
#define CFG_CNF_OWN_ATIM_WINDOW         0xFC05      //[STA] ATIM Window time for IBSS creation
#define CFG_CNF_SYSTEM_SCALE            0xFC06      //System Scale that specifies the AP density
#define CFG_CNF_MAX_DATA_LEN            0xFC07      //Maximum length of MAC Frame Body data
#define CFG_CNF_WDS_ADDR                0xFC08      //[STA] MAC Address of corresponding WDS Link node
#define CFG_CNF_PM_ENABLED              0xFC09      //[STA] Switch for ESS Power Management (PM) On/Off
#define CFG_CNF_PM_EPS                  0xFC0A      //[STA] Switch for ESS PM EPS/PS Mode
#define CFG_CNF_MCAST_RX                0xFC0B      //[STA] Switch for ESS PM Multicast reception On/Off
#define CFG_CNF_MAX_SLEEP_DURATION      0xFC0C      //[STA] Maximum sleep time for ESS PM
#define CFG_CNF_HOLDOVER_DURATION       0xFC0D      //[STA] Holdover time for ESS PM
#define CFG_CNF_OWN_NAME                0xFC0E      //Identification text for diagnostic purposes
    
#define CFG_CNF_ENCRYPTION              0xFC20      //select en/de-cryption of Tx/Rx messages
#define CFG_CNF_MICRO_WAVE              0xFC25      //MicroWave (Robustness)
    
    
//  NETWORK PARAMETERS, DYNAMIC CONFIGURATION ENTITIES
#define CFG_DESIRED_SSID                0xFC02      //[STA] Service Set identification for connection
#define CFG_GROUP_ADDR                  0xFC80      //[STA] Multicast MAC Addresses for Rx-message
#define CFG_CREATE_IBSS                 0xFC81      //[STA] Switch for IBSS creation On/Off
#define CFG_FRAGMENTATION_THRH          0xFC82      //[STA] Fragment length for unicast Tx-message
#define CFG_RTS_THRH                    0xFC83      //[STA] Frame length used for RTS/CTS handshake
#define CFG_TX_RATE_CONTROL             0xFC84      //[STA] Data rate control for message transmission
#define CFG_PROMISCUOUS_MODE            0xFC85      //[STA] Switch for Promiscuous mode reception On/Off
    
#define CFG_CNF_DEFAULT_KEYS            0xFCB0      //defines set of encryption keys
#define CFG_CNF_TX_KEY_ID               0xFCB1      //select key for encryption of Tx messages


//  BEHAVIOR PARAMETERS 
#define CFG_TICK_TIME                   0xFCE0      //[PRI] Auxiliary Timer tick interval
#define CFG_RID_CFG_MAX                 0xFCFF      //highest value representing an Configuration RID


/*============================================================= INFORMATION RECORDS     =====================*/
/*============================================================= mask 0xFDxx             =====================*/
//  NIC INFORMATION 
#define CFG_RID_INF_MIN                 0xFD00      //lowest value representing an Information RID
#define CFG_MAX_LOAD_TIME               0xFD00  //[PRI] Maximum response time of the Download command.
#define CFG_DL_BUF                      0xFD01  //[PRI] Download buffer location and size.
#define CFG_PRI_IDENTITY                0xFD02  //[PRI] Primary Functions firmware identification.
#define CFG_PRI_SUP_RANGE               0xFD03  //[PRI] Primary Functions interface; Supplier compatibility range.
#define CFG_CFI_ACT_RANGES_PRI          0xFD04  //[PRI] Controller interface; Actor compatibility ranges.

#define CFG_HSI_SUP_RANGE               0xFD09  //H/W - S/W I/F supplier range
#define CFG_NIC_SERIAL_NUMBER           0xFD0A  //[PRI] Network Interface Card serial number.
#define CFG_NIC_IDENTITY                0xFD0B  //[PRI] Network Interface Card identification.
#define CFG_MFI_SUP_RANGE               0xFD0C  //[PRI] Modem interface, Supplier compatibility range.
#define CFG_CFI_SUP_RANGE               0xFD0D  //[PRI] Controller interface; Supplier compatibility range.
#define CFG_CHANNEL_LIST                0xFD10  //Allowed communication channels.
#define CFG_REG_DOMAINS                 0xFD11  //List of intended regulatory domains.
#define CFG_TEMP_TYPE                   0xFD12  //Hardware temperature range code.
#define CFG_CIS                         0xFD13  //PC Card Standard Card Information Structure
#define CFG_CARD_PROFILE                0xFD14  //Card Profile

#define CFG_STA_IDENTITY                0xFD20   //[STA] Station Functions firmware identification.
#define CFG_STA_SUP_RANGE               0xFD21   //[STA] Station Functions interface; Supplier compatibility range.
#define CFG_MFI_ACT_RANGES_STA          0xFD22   //[STA] Modem interface; Actor compatibility ranges.
#define CFG_CFI_ACT_RANGES_STA          0xFD23   //[STA] Controller interface; Actor compatibility ranges.

//  MAC INFORMATION
#define CFG_PORT_STAT                   0xFD40      //[STA] Actual MAC Port connection control status
#define CFG_CURRENT_SSID                0xFD41      //[STA] Identification of the actually connected SS
#define CFG_CURRENT_BSSID               0xFD42      //[STA] Identification of the actually connected BSS
#define CFG_COMMS_QUALITY               0xFD43      //[STA] Quality of the Basic Service Set connection
#define CFG_CURRENT_TX_RATE             0xFD44      //[STA] Actual transmit data rate
#define CFG_OWN_BEACON_INTERVAL         0xFD45      //Beacon transmit interval time for BSS creation
#define CFG_CUR_SCALE_THRH              0xFD46      //Actual System Scale thresholds settings
#define CFG_PROTOCOL_RSP_TIME           0xFD47      //Max time to await a response to a request message
#define CFG_SHORT_RETRY_LIMIT           0xFD48      //Max number of transmit attempts for short frames
#define CFG_LONG_RETRY_LIMIT            0xFD49      //Max number of transmit attempts for long frames
#define CFG_MAX_TX_LIFETIME             0xFD4A      //Max transmit frame handling duration
#define CFG_MAX_RX_LIFETIME             0xFD4B      //Max received frame handling duration
#define CFG_CF_POLLABLE                 0xFD4C      //[STA] Contention Free pollable capability indication
#define CFG_AUTHENTICATION_ALGORITHMS   0xFD4D      //Available Authentication Algorithms indication
#define CFG_AUTHENTICATION_TYPE         0xFD4E      //Available Authentication Types indication
#define CFG_PRIVACY_OPTION_IMPLEMENTED  0xFD4F      //WEP Option availability indication
#define CFG_CURRENT_REMOTE_RATES        0xFD50      //CurrentRemoteRates
#define CFG_CURRENT_USED_RATES          0xFD51      //CurrentUsedRates
    

//  MODEM INFORMATION   
#define CFG_PHY_TYPE                    0xFDC0      //      //  Physical layer type indication
#define CFG_CURRENT_CHANNEL             0xFDC1      //Actual frequency channel used for transmission
#define CFG_CURRENT_POWER_STATE         0xFDC2      //Actual power consumption status
#define CFG_CCAMODE                     0xFDC3      //Clear channel assessment mode indication
#define CFG_CCATIME                     0xFDC4      //Clear channel assessment time
#define CFG_MAC_PROCESSING_DELAY        0xFDC5      //MAC processing delay time
#define CFG_SUPPORTED_DATA_RATES        0xFDC6      //Data rates capability information

#define CFG_RID_INF_MAX                 0xFDFF      //highest value representing an Information RID

//} hcf_info_type;




/*************************************************************************************************************/

/****************************** S T R U C T U R E   D E F I N I T I O N S ************************************/

typedef struct LTV_STRCT {  //used for all "minimal" LTV records
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  val[1];                 //do not change this, some dynamic structures are defined based on this !!
}LTV_STRCT;

typedef LTV_STRCT FAR * LTVP;


typedef struct CFG_DRV_INFO_STRCT {     //CFG_DRV_INFO (0x0825) driver information
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_8   driver_name[8];         //Driver name, 8 bytes, right zero padded
    hcf_16  driver_version;         //BCD 2 digit major and 2 digit minor driver version
    hcf_16  HCF_version;            //BCD 2 digit major and 2 digit minor HCF version
    hcf_16  driver_stat;            //
    hcf_16  IO_address;             //IOAddress used by NIC
    hcf_16  IO_range;               //IORange used by NIC
    hcf_16  IRQ_number;             //Interrupt used by NIC
    hcf_16  card_stat;              /*NIC status
                                    @*  0x8000  Card present
                                    @*  0x4000  Card Enabled
                                    @*  0x2000  Driver incompatible with NIC Primary Functions
                                    @*  0x1000  Driver incompatible with NIC Station Functions
                                    @*  0x007F  HCF Internal Flags (i.e. pseudo Asynchronous command code)  */
    hcf_16  frame_type;             /*Frame type
                                    @*  0x000   802.3
                                    @*  0x008   802.11                                                      */
    hcf_32  drv_info;               /*driver specific info
                                     * CE: virtual I/O base                                                 */
}CFG_DRV_INFO_STRCT;


typedef struct CFG_IDENTITY_STRCT {     //CFG_DRV_IDENTITY (0x0826), ...... 
    hcf_16  len;                    //length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
                                    //The following fields are defined in DS 010335
    hcf_16  comp_id;                //  component id
    hcf_16  variant;                //  variant (01..99)
    hcf_16  version_major;          //  major version (01..99)
    hcf_16  version_minor;          //  minor version (01..99)
} CFG_IDENTITY_STRCT;

#define COMP_ID_MINIPORT_NDIS_31    41              //Windows 9x/NT Miniport NDIS 3.1
#define COMP_ID_PACKET              42              //Packet
#define COMP_ID_ODI_16              43              //DOS ODI
#define COMP_ID_ODI_32              44              //32-bits ODI
#define COMP_ID_MAC_OS              45              //Macintosh OS
#define COMP_ID_WIN_CE              46              //Windows CE Miniport
#define COMP_ID_LINUX_PD            47              /*Linux, full source code in Public Domain, HCF-light based
                                                     *thanks to Andreas Neuhaus                             */
#define COMP_ID_MINIPORT_NDIS_50    48              //Windows 9x/NT Miniport NDIS 5.0
#define COMP_ID_LINUX_LIB           49              //Linux, HCF-library based
#define COMP_ID_QNX                 50              //QNX
#define COMP_ID_MINIPORT_NDIS_40    51              //Windows 9x/NT Miniport NDIS 4.0
#define COMP_ID_AP1                 81              //WaveLAN/IEEE AP
#define COMP_ID_EC                  83              //WaveLAN/IEEE Ethernet Converter











#define COMP_ROLE_SUPL  00              //supplier
#define COMP_ROLE_ACT   01              //actor

#define COMP_ID_MFI     01              //Modem             - Firmware  I/F
#define COMP_ID_CFI     02              //Controller        - Firmware  I/F
#define COMP_ID_PRI     03              //Primary Firmware  - Driver    I/F
#define COMP_ID_STA     04              //Station Firmware  - Driver    I/F
#define COMP_ID_DUI     05              //Driver            - Utility   I/F
#define COMP_ID_HSI     06              //H/W               - Driver    I/F



/*  the "right" prototype would be
    typedef void (FAR MSF_ASSERT_RTN)( wci_bufp, unsigned int, hcf_16, int );
    rather than 
    typedef void (MSF_ASSERT_RTN)( wci_bufp, unsigned int, hcf_16, int );
    However, this results in sheer unsurmountable problems to build and link TSRs
    using Microsoft Visual C 1.5 compiler and linker.
    Since most users define FAR empty anyway, it does not matter for most users
    The exceptions are: DOS ODI, Packet Driver, WCITST, AccessPoint
    Since C is so nice to clear the stack by the caller, the FAR/NEAR issue does not cause
    problems in the call/return mechanism
    By carefully misleading the compiler in the msf_assert routine, we can compensate
    for the offset difference of 2 of the parameters in case of a far or near call
 */
typedef void (/*FAR*/ MSF_ASSERT_RTN)( wci_bufp, unsigned int, hcf_16, int );
typedef MSF_ASSERT_RTN FAR * MSF_ASSERT_RTNP;

typedef struct CFG_REG_ASSERT_RTNP_STRCT  { //CFG_REG_ASSERT_RTNP (0x0832)  (de-)register MSF Callback routines
    hcf_16          len;            //default length of RID
    hcf_16          typ;            //CFG_REG_ASSERT_RTNP (0x0832) identification
    hcf_16          lvl;            //Assert level filtering (not yet implemented)
    MSF_ASSERT_RTNP rtnp;           //address of MSF_ASSERT_RTN (native Endian format)
} CFG_REG_ASSERT_RTNP_STRCT;

typedef void (/*FAR*/ MSF_LOG_RTN)( int rtn_id, int val_1, int val_2);
typedef MSF_LOG_RTN FAR * MSF_LOG_RTNP;


typedef struct CFG_CNF_ENCRYPTION_STRCT {   //CFG_CNF_ENCRYPTION (0xFC20) select en/de-cryption of Tx/Rx messages
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  encryption_enabled;     //Encryption Enabled
} CFG_CNF_ENCRYPTION_STRCT;

typedef struct CFG_CNF_AUTHENTICATION_STRCT {//CFG_CNF_AUTHENTICATION (0xFC21) selects Authentication algorithm
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  authentication_type;   // Authentication type
} CFG_CNF_AUTHENTICATION_STRCT;

//CFG_CNF_DEFAULT_KEYS (0xFCB0) defines set of encryption keystypedef struct 
//typedef struct CFG_CNF_DEFAULT_KEYS_STRCT { //CFG_CNF_DEFAULT_KEYS (0xFCB0) defines set of encryption keys
//    hcf_16  len;                    //default length of RID
//    hcf_16  typ;                    //RID identification as defined by Hermes
//    hcf_16  len_0;                //length of 1st key
//    hcf_8   key_0[14];              //1st encryption key
//    hcf_16  len_1;                //length of 2nd key
//    hcf_8   key_1[14];              //2nd encryption key
//    hcf_16  len_2;                //length of 3rd key
//    hcf_8   key_2[14];              //3rd encryption key
//    hcf_16  len_3;                //length of 4th key
//    hcf_8   key_3[14];              //4th encryption key
//} CFG_CNF_DEFAULT_KEYS_STRCT;

typedef struct KEY_STRCT {
    hcf_16  len;                    //length of key
    hcf_8   key[14];                //encryption key
} KEY_STRCT;

typedef struct CFG_CNF_DEFAULT_KEYS_STRCT { //CFG_CNF_DEFAULT_KEYS (0xFCB0) defines set of encryption keys
    hcf_16      len;                //default length of RID
    hcf_16      typ;                //RID identification as defined by Hermes
    KEY_STRCT   key[4];             //encryption keys
} CFG_CNF_DEFAULT_KEYS_STRCT;

typedef struct CFG_CNF_TX_KEY_ID_STRCT {    //CFG_CNF_TX_KEY_ID (0xFCB1) select key for encryption of Tx messages
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  tx_key_id;              //specifies which key of CFG_CNF_DEFAULT_KEYS is to be used for Tx-encryption
} CFG_CNF_TX_KEY_ID_STRCT;

typedef struct CFG_NIC_SERIAL_NUMBER_STRCT {    //CFG_NIC_SERIAL_NUMBER (0xFD0A) NIC Serial number
    hcf_16  len;                    //length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  number[6];
}CFG_NIC_SERIAL_NUMBER_STRCT;

typedef struct CFG_REG_DOMAINS_STRCT {  //CFG_REG_DOMAINS (0xFD11) List of intended regulatory domains.
    hcf_16  len;                    //length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  num_domains;            //Number of domains in list
    hcf_8   domain[10];             //List of domains
}CFG_REG_DOMAINS_STRCT;


typedef struct CFG_CIS_STRCT {          //CFG_CIS (0xFD13) PC Card Standard Card Information Structure
    hcf_16  len;                    //length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  cis[240];               //Compact CIS Area, a linked list of tuples
}CFG_CIS_STRCT;


typedef struct CFG_CARD_PROFILE_STRCT {     //CFG_CARD_PROFILE (0xFD14) CardProfile
    hcf_16  len;                    //length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  profile_code;               //a code specifying the card profile
    hcf_16  capability_options;         //capability options, used to be known as wep_options
    hcf_16  allowed_data_rates;         //allowed data rates
} CFG_CARD_PROFILE_STRCT;


typedef struct CFG_COMMS_QUALITY_STRCT {//CFG_COMMS_QUALITY (0xFD43) Quality of the Basic Service Set connection [STA]
    hcf_16  len;                    //length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  coms_qual;              //Communication Quality of the BSS the station is connected to
    hcf_16  signal_lvl;             //Average Signal Level of the BSS the station is connected to
    hcf_16  noise_lvl;              //Average Noise Level of the currently used Frequency Channel
}CFG_COMMS_QUALITY_STRCT;



typedef struct CFG_CUR_SCALE_THRH_STRCT {//CFG_CUR_SCALE_THRH (0xFD46) Actual System Scale thresholds
    hcf_16  len;                    //default length of RID [STA: 6  AP: 4]
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  energy_detect_thrh;     //Receiver H/W Energy Detect Threshold
    hcf_16  carrier_detect_thrh;    //Receiver H/W Carrier Detect Threshold
    hcf_16  defer_thrh;             //Receiver H/W Defer Threshold
    hcf_16  cell_search_thrh;       //Firmware Roaming Cell Search Threshold [STA]
    hcf_16  out_of_range_thrh;      //Firmware Roaming Out of Range Threshold [STA]
    hcf_16  delta_snr;              //Firmware Roaming Delta SNR value [STA]
}CFG_CUR_SCALE_THRH_STRCT;


typedef struct CFG_PCF_INFO_STRCT {     //CFG_PCF_INFO (0xFD87) Point Coordination Function capability info [AP]
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  mediumOccupancyLimit;
    hcf_16  CFPPeriod;
    hcf_16  CFPMaxDuration;
}CFG_PCF_INFO_STRCT;


typedef struct CFG_MAC_ADDR_STRCT{          //0xFC01    [STA] MAC Address of this node.
                                            //0xFC08    STA] MAC Address of corresponding WDS Link node.
                                            //0xFC11    [AP] Port 1 MAC Adrs of corresponding WDS Link node
                                            //0xFC12    [AP] Port 2 MAC Adrs of corresponding WDS Link node
                                            //0xFC13    [AP] Port 3 MAC Adrs of corresponding WDS Link node
                                            //0xFC14    [AP] Port 4 MAC Adrs of corresponding WDS Link node
                                            //0xFC15    [AP] Port 5 MAC Adrs of corresponding WDS Link node
                                            //0xFC16    [AP] Port 6 MAC Adrs of corresponding WDS Link node
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  mac_addr[3];
}CFG_MAC_ADDR_STRCT;

typedef struct CFG_GROUP_ADDR_STRCT{            //0xFC80        //[STA] Multicast MAC Addresses for Rx-message
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  mac_addr[GROUP_ADDR_SIZE/2];
}CFG_GROUP_ADDR_STRCT;




typedef struct CFG_ID_STRCT {               //0xFC02    [STA] Service Set identification for connection.
                                            //0xFC04    IBSS creation (STA) or ESS (AP) Service Set Ident
                                            //0xFC0E    Identification text for diagnostic purposes.
    hcf_16  len;                    //default length of RID
    hcf_16  typ;                    //RID identification as defined by Hermes
    hcf_16  id[17];
}CFG_ID_STRCT;



typedef struct CFG_SUPPORTED_DATA_RATES_STRCT {
    hcf_16  len;                            // default length of RID
    hcf_16  typ;                            // RID identification as defined by Hermes
    hcf_16  rates[5];                       // Data rates
} CFG_SUPPORTED_DATA_RATES_STRCT;


#endif // MDD_H


#ifndef HCF_H
#define HCF_H 1

/*************************************************************************************************************
*
* FILE   : hcf.h *************** 2.0 *************************************************************************
*
* DATE   : $Date:   01 Feb 2000 12:02:28  $   $Revision:   4.6  $
*
* AUTHOR : Nico Valster
*
* DESC   : Definitions and Prototypes for MSF as well as HCF sources
*
*           Customizable via HCFCFG.H
*
*
**************************************************************************************************************
Instructions to convert HCF.H to HCF.INC by means of H2INC

Use a command line which defines the specific macros and command line options
needed to build the C-part, e.g. for the DOS ODI driver
        `h2inc /C /Ni /Zp /Zn hcf    hcf.h`


**************************************************************************************************************
* COPYRIGHT (c) 1996, 1997, 1998 by Lucent Technologies.     All Rights Reserved.
**************************************************************************************************************/

/**************************************************************************************************************
*
* CHANGE HISTORY
*
  961018 - NV
    Original Entry

****************************************************************************/





/************************************************************************************************************/
/******************   H C F  F U N C T I O N   P A R A M E T E R     ****************************************/
/************************************************************************************************************/

//offsets for hcf_put_data and hcf_get_data
                

// 802.3/E-II/802.11 offsets to access Hermes control fields  ;?BElong in MDD,H ???????????????????????????????
#define HFS_STAT                -0x2E   //0x0000
#define     HFS_STAT_ERR        RX_STAT_ERR //link "natural" HCF name to "natural" MSF name

#define HFS_Q_INFO              -0x28   //0x0006
#define HFS_TX_CNTL             -0x22   //0x000C
#define HFS_FRAME_CNTL          -0x20   //0x000E
#define HFS_ID                  -0x1E   //0x0010

// 802.11 relative offsets to access 802.11 header fields
#define HFS_ADDR_1              0x00    //0x0012
#define HFS_ADDR_2              0x06    //0x0018
#define HFS_ADDR_3              0x0C    //0x001E
#define HFS_SEQ_CNTL            0x12    //0x0024
#define HFS_ADDR_4              0x14    //0x0026
#define HFS_DAT_LEN             0x1A    //0x002C

// 802.3 / E-II relative offsets to access 802.3 header fields
#define HFS_ADDR_DEST           0x00    //0x002E
#define HFS_ADDR_SRC            0x06    //0x0034
#define HFS_LEN                 0x0C    //0x003A
#define HFS_DAT                 0x0E    //0x003C

// E-II relative offsets to access SNAP header fields
#define HFS_TYPE                0x14    //0x0042    //Eternet-II type in 1042/Bridge-Tunnel encapsulated frame
#define HFS_WDM_TYPE            0x17    //0x0045    //PDU type in WDM frame


//#define HCF_ACT_INT_PENDING   0x0001      //interrupt pending, return status HCF_ACT_INT_OFF



/*************************************************************************************************************/
/****************   H C F  F U N C T I O N   R E T U R N   C O D E S   ***************************************/
/*************************************************************************************************************/

//Debug Purposes only               !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define HREG_EV_TICK        0x8000  //WMAC Controller Auxiliary Timer Tick
#define HREG_EV_RES         0x4000  //WMAC Controller H/W error (Wait Time-out)
#define HREG_EV_INFO_DROP   0x2000  //WMAC did not have sufficient RAM to build Unsollicited Frame
#define HREG_EV_NO_CARD     0x0800  /* PSEUDO event: card removed                                             */
#define HREG_EV_DUIF_RX     0x0400  /* PSEUDO event: WMP frame received                                       */
#define HREG_EV_INFO        0x0080  //WMAC Controller Asynchronous Information Frame
#define HREG_EV_CMD         0x0010  //WMAC Controller Command completed, Status and Response avaialble
#define HREG_EV_ALLOC       0x0008  //WMAC Controller Asynchronous part of Allocation/Reclaim completed
#define HREG_EV_TX_EXC      0x0004  //WMAC Controller Asynchronous Transmission unsuccessful completed
#define HREG_EV_TX          0x0002  //WMAC Controller Asynchronous Transmission successful completed
#define HREG_EV_RX          0x0001  //WMAC Controller Asynchronous Receive Frame



//=========================================  T A L L I E S  ===================================================

typedef struct CFG_HERMES_TALLIES_STRCT {  //Hermes Tallies (IFB substructure)
  hcf_32    TxUnicastFrames;
  hcf_32    TxMulticastFrames;
  hcf_32    TxFragments;
  hcf_32    TxUnicastOctets;
  hcf_32    TxMulticastOctets;
  hcf_32    TxDeferredTransmissions;
  hcf_32    TxSingleRetryFrames;
  hcf_32    TxMultipleRetryFrames;
  hcf_32    TxRetryLimitExceeded;
  hcf_32    TxDiscards;
  hcf_32    RxUnicastFrames;
  hcf_32    RxMulticastFrames;
  hcf_32    RxFragments;
  hcf_32    RxUnicastOctets;
  hcf_32    RxMulticastOctets;
  hcf_32    RxFCSErrors;
  hcf_32    RxDiscards_NoBuffer;
  hcf_32    TxDiscardsWrongSA;
  hcf_32    RxWEPUndecryptable;
  hcf_32    RxMsgInMsgFragments;
  hcf_32    RxMsgInBadMsgFragments;
  hcf_32    RxDiscards_WEPICVError;
  hcf_32    RxDiscards_WEPExcluded;
}CFG_HERMES_TALLIES_STRCT;

typedef struct CFG_HCF_TALLIES_STRCT {  //HCF Tallies (IFB substructure) (HCF-light "suffers" to get HCFLIB "right"
  hcf_32    dummy[5];
}CFG_HCF_TALLIES_STRCT;


//Note this way to define CFG_TALLIES_STRCT_SIZE implies that all tallies must keep the same (hcf_32) size
#define     HCF_NIC_TAL_CNT (sizeof(CFG_HERMES_TALLIES_STRCT)/ sizeof(hcf_32))
#define     HCF_HCF_TAL_CNT (sizeof(CFG_HCF_TALLIES_STRCT)   / sizeof(hcf_32))
#define     HCF_TOT_TAL_CNT (HCF_NIC_TAL_CNT + HCF_HCF_TAL_CNT)

/************************************************************************************************************/
/***********   W C I    F U N C T I O N S    P R O T O T Y P E S   ******************************************/
/************************************************************************************************************/

#define IFB_VERSION 7                   /* initially 0, to be incremented by every IFB layout change        */


/* identifier IFB_STRCT on typedef line needed to get the individual fields in the MS Browser DataBase  */
typedef struct IFB_STRCT{               //I/F Block
/************************************************************************************************************/
/* part I (survives hcf_initialize)  ************************************************************************/
/************************************************************************************************************/
  hcf_io        IFB_IOBase;             /* I/O address of Hermes chip as passed by MSF at hcf_connect call  */
#if defined HCF_PORT_IO
  hcf_16        IFB_IOBase_pad;         // Optional field, makes IFB-layout independent of IFB_IOBase size
#endif //HCF_PORT_IO
  hcf_16        IFB_IORange;            // I/O Range used by Hermes chip
  hcf_8         IFB_Version;            /* initially 0, to be incremented by every IFB layout change        */
  hcf_8         IFB_Slack_2;            /* align/slack space                                                */
  hcf_8         IFB_HCFVersionMajor;    // Major version of the HCF.0x01 for this release
  hcf_8         IFB_HCFVersionMinor;    /* Minor version of the HCF.  Incremented for each coding maintenance
                                         * cycle. 0x01 for the Initial release                              */
#if defined HINC                                                                                    
  hcf_32        IFB_NIC_Tallies[HCF_NIC_TAL_CNT];   //Hermes tallies
  hcf_32        IFB_HCF_Tallies[HCF_HCF_TAL_CNT];   //HCF tallie
#else                                                                                               
  CFG_HERMES_TALLIES_STRCT  IFB_NIC_Tallies;    //Hermes tallies
  CFG_HCF_TALLIES_STRCT     IFB_HCF_Tallies;    //HCF tallies
#endif // HINC                                                                                      
  hcf_16        IFB_CardStat;           /*                                                                  */
  hcf_16        IFB_PortStat;           // bit flags representing individual enabled ports          
  hcf_16        IFB_FrameType;          /*                                                                  */
  wci_recordp   IFB_MBp;                /*                                                                  */
  hcf_16        IFB_MBSize;             /*                                                                  */
  hcf_16        IFB_MBWp;               /*                                                                  */
  hcf_16        IFB_MBRp;               /*                                                                  */
  hcf_16        IFB_MBInfoLen;          /*                                                                  */
  hcf_16        IFB_FSBase;             // frame type dependent offset (HFS_ADDR_1_ABS or HFS_ADDR_DEST_ABS)
  hcf_16        IFB_RxFence;            // frame type dependent gap fence (HFS_ADDR_DEST_ABS or HFS_LEN_ABS)
  hcf_16        IFB_IntOffCnt;          /*                                                                  */
  hcf_32        IFB_TickIni;            /* initialization of S/W counter based protection loop
                                         * Note that via IFB_DefunctStat time outs in cmd_wait and in
                                         * hcfio_string block all Hermes access till the next hcf_initialize
                                         * so functions which call a mix of cmd_wait and hcfio_string only
                                         * need to check the return status of the last call                 */
  hcf_16        IFB_Magic;              /*                                                                  */


  hcf_16        IFB_LogLvl;             // Log Filtering
  MSF_LOG_RTNP  IFB_LogRtn;             // MSF Log Call back routine                                               
  MSF_ASSERT_RTNP   IFB_AssertRtn;      // MSF Assert Call back routine (inspired by GEF, DrDobbs Nov 1998 )       
  hcf_16        IFB_MSFType;            /* Emergency escape controlled via hcf_put_info, used for:
                                         *  - hybrid AP/STA:  0 = STA, 1 = AP 
                                         */
  hcf_16        IFB_Slack_4[1];         /* align/slack space                                                */
/************************************************************************************************************/
/* part II (cleared or re-initialized at hcf_initialize)   *************************************************/
/************************************************************************************************************/
  hcf_8         IFB_PIFRscInd;          /*                   //;?Q:int better than hcf_8 A: No!             */
  hcf_8         IFB_DUIFRscInd;         /* Value indicating the command resource availability for the
                                         * Driver-Utility I/F (i.e. hcf_send_diag_msg).                     */
                                        /* Values: */
                                        /* * No command resource        0                                   */
                                        /* * Command resource available 01h-FFh                             */
  hcf_8         IFB_NotifyRscInd;       /*                   //;?Q:int better than hcf_8 A: No!             */
  hcf_8         IFB_Slack_6;            /* align/slack space                                                */
  hcf_16        IFB_PIF_FID;            /*                                                                  */
  hcf_16        IFB_DUIF_FID;           /* field which contains FID value identifying the Tx Frame Structure,
                                         * to be used by hcf_send_diag_msg                                  */
  hcf_16        IFB_Notify_FID;         /* field which contains FID value identifying the Notify Frame Struct
                                         * to be used by hcf_put_info in case of Notify type codes          */
  hcf_16        IFB_RxFID;              /*                                                                  */
  hcf_16        IFB_MB_FID;             /* pass appropriate FID to hcf_put_mb_info                          */
  hcf_16        IFB_TxFrameType;        /*                                                                  */
  hcf_16        IFB_RxLen;              /*                                                                  */
  hcf_16        IFB_RxStat;             /*                                                                  */
  hcf_16        IFB_UnloadIdx;          /*                                                                  */
  hcf_16        IFB_PIFLoadIdx;         /*                                                                  */
  hcf_8         IFB_TxCntl[2];          /* contents of HFS_TX_CNTL field of TFS
                                         * 0: MACPort, 1: StrucType,TxEx,TxOK                               */
  hcf_16        IFB_BAP_0[2];           /* offset
                                         * RID/FID                                                          */
  hcf_16        IFB_BAP_1[2];           /* offset
                                         * RID/FID                                                          */
/* the fields after this text must stay concatenated because of their (mis-)use as LTV record               */
  hcf_16        IFB_DLTarget[2];        // 32-bits (don't confuse with FAR) Pointer to NV-RAM download target
#if defined HCF_STA         
  hcf_16        IFB_DLPage;             /* Download Buffer Page, must be concatenated with IFB_DLTarget     */
  hcf_16        IFB_DLOffset;           /* Download Buffer Offset, must be concatenated with IFB_DLPage     */
  hcf_16        IFB_DLLen;              /* Download Buffer Length, must be concatenated with IFB_DLOffset   */
#else
  hcf_16        IFB_Slack_8[3];         /* align/slack space                                                */
#endif //HCF_STA
  /* the fields above this text must stay concatenated because of their (mis-)use as LTV record             */
  hcf_16        IFB_IntEnMask;          /*                                                                  */
  hcf_16        IFB_DefunctStat;        /* BAP initialization or Cmd Completion failed once
                                         * see remark at IFB_TickIni definition                             */
  hcf_16        IFB_ErrCmd;             // contents Status reg when error bits and/or mismatch in cmd_wait
  hcf_16        IFB_ErrQualifier;       // contents Resp0  reg when error bits and/or mismatch in cmd_wait
  hcf_16        IFB_EngFlg;             /* Engineering Flags
                                         *  0x0001  WMP filtering on PDU type                               */
  hcf_16        IFB_AssertTrace;        /* bit based trace off all hcf_.... invokations                     */
                                        /* keep IFB_CfgTbl and IFB_End adjacent,
                                         * see clearing IFB in hcf_disable                                  */
  hcf_16        IFB_AssertLvl;          // Assert Filtering, Not yet implemented
  hcf_16        IFB_WarningInfo[2];     /* [1] HCF controlled warning bits
                                         *  0 - 0x0001 : Power management
                                         *  0 - 0x0002 : unused
                                         :
                                         *  0 - 0x8000 : unused
                                         * [2] MSF controlled warning bits
                                         */                                                         
  hcf_16        IFB_LinkStat;           /* Link Status
                                         * 1 Connected, 2 Disconnected,
                                         * 3 AP change, 4 AP out of range, 5 AP in range                    */
  hcf_16        IFB_PRICfg;             // Primary      Top/Bottom Supplier Range                         
  hcf_16        IFB_HSICfg;             // H/W-S/W I/F  Top/Bottom Supplier Range
  hcf_16        IFB_STACfg;             // Station      Top/Bottom Supplier Range                         
  hcf_16        IFB_CfgTblSize;
/************************************************************************************************************/
/* part III (survives hcf_initialize)  **********************************************************************/
/************************************************************************************************************/
#if HCF_MAX_CONFIG != 0                                                                             
  hcf_16        IFB_CfgTbl[HCF_MAX_CONFIG];    /* concatenated data of all hcf_put_record calls     */
#endif //HCF_MAX_CONFIG                                                                             

}IFB_STRCT;

typedef struct ASSERT_STRCT {
    hcf_16  len;                    //length of assert_strct
    hcf_16  trace;                  //trace log copy from IFB
    hcf_16  qualifier;              //qualifier from entry parameter
    hcf_16  line_number;            //line number from entry parameter
    char val[1];
} ASSERT_STRCT;



typedef IFB_STRCT*  IFBP;


EXTERN_C int    hcf_action          (IFBP ifbp, hcf_action_cmd cmd );
EXTERN_C void   hcf_assert          (IFBP ifbp, struct ASSERT_STRCT* assert_strct, unsigned int line_number, int q );
EXTERN_C void   hcf_connect         (IFBP ifbp, hcf_io io_base );
EXTERN_C int    hcf_disable         (IFBP ifbp, hcf_16 port );
EXTERN_C void   hcf_disconnect      (IFBP ifbp );
EXTERN_C int    hcf_enable          (IFBP ifbp, hcf_16 port );
EXTERN_C int    hcf_get_info        (IFBP ifbp, LTVP ltvp );
EXTERN_C int    hcf_get_data        (IFBP ifbp, int offset, wci_bufp bufp, int len );
EXTERN_C int    hcf_service_nic     (IFBP ifbp );
EXTERN_C void   hcf_put_data        (IFBP ifbp, wci_bufp bufp, int len, hcf_16 port );
EXTERN_C int    hcf_put_info        (IFBP ifbp, LTVP ltvp );
EXTERN_C int    hcf_put_header      (IFBP ifbp, hcf_16 offset, wci_bufp bufp, int len, hcf_8 check );
EXTERN_C int    hcf_send            (IFBP ifbp, hcf_16 type );
EXTERN_C int    hcf_send_diag_msg   (IFBP ifbp, hcf_16 type, wci_bufp bufp, int len );




#endif  /* HCF_H */


#endif  /* LIBHCF_H */
