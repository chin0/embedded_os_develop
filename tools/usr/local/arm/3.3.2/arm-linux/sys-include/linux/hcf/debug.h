/*+I*************************************************************************
 * Driver debug interface.
 *
 * Copyright (c) 1998-1999 TriplePoint, Inc. -- http://www.triplepoint.com
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 *  $Id: debug.h,v 1.1 1999/04/20 15:05:55 deang Exp $
 *-I*************************************************************************/
#ifndef _DEBUG_H
#define _DEBUG_H

#ifndef DBG
#define DBG     0
#endif //DBG

/****************************************************************************/
#if DBG

#define DBG_ERROR_ON        0x00000001L
#define DBG_WARNING_ON      0x00000002L
#define DBG_NOTICE_ON       0x00000004L
#define DBG_TRACE_ON        0x00000008L
#define DBG_VERBOSE_ON      0x00000010L
#define DBG_PARAM_ON        0x00000020L
#define DBG_BREAK_ON        0x00000040L
#define DBG_RX_ON           0x00000100L
#define DBG_TX_ON           0x00000200L

#define DBG_DEFAULTS        (DBG_ERROR_ON | DBG_WARNING_ON | DBG_BREAK_ON)

#define DBG_FLAGS(A)        (A)->dbgFlags
#define DBG_NAME(A)         (A)->dbgName
#define DBG_LEVEL(A)        (A)->dbgLevel

#ifndef PRINTK
#   define PRINTK(S...)     printk(S)
#endif // PRINTK
#ifndef DBG_PRINT
#   define DBG_PRINT(S...)   PRINTK(KERN_DEBUG S)
#endif // DBG_PRINT
#ifndef DBG_PRINTC
#   define DBG_PRINTC(S...)  PRINTK(S)
#endif // DBG_PRINTC

#ifndef DBG_TRAP
#   define DBG_TRAP         abort()
#endif // DBG_TRAP

#define _ENTER_STR ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
#define _LEAVE_STR "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"

#define _DBG_ENTER(A) DBG_PRINT("%s:%.*s:%s\n",DBG_NAME(A),++DBG_LEVEL(A),_ENTER_STR,__FUNC__)
#define _DBG_LEAVE(A) DBG_PRINT("%s:%.*s:%s\n",DBG_NAME(A),DBG_LEVEL(A)--,_LEAVE_STR,__FUNC__)

#define DBG_FUNC(F)         static const char __FUNC__[] = F;
#define DBG_ENTER(A)        {if (DBG_FLAGS(A) & DBG_TRACE_ON) \
                                _DBG_ENTER(A);}
#define DBG_LEAVE(A)        {if (DBG_FLAGS(A) & DBG_TRACE_ON) \
                                _DBG_LEAVE(A);}
#define DBG_PARAM(A,N,F,S...)   {if (DBG_FLAGS(A) & DBG_PARAM_ON) \
                                    DBG_PRINT("  %s -- "F"\n",N,S);}
#define DBG_ERROR(A,S...)   {if (DBG_FLAGS(A) & DBG_ERROR_ON) \
                                {DBG_PRINT("%s:ERROR:%s ",DBG_NAME(A),__FUNC__);DBG_PRINTC(S);DBG_TRAP;}}
#define DBG_WARNING(A,S...) {if (DBG_FLAGS(A) & DBG_WARNING_ON) \
                                {DBG_PRINT("%s:WARNING:%s ",DBG_NAME(A),__FUNC__);DBG_PRINTC(S);}}
#define DBG_NOTICE(A,S...)  {if (DBG_FLAGS(A) & DBG_NOTICE_ON) \
                                {DBG_PRINT("%s:NOTICE:%s ",DBG_NAME(A),__FUNC__);DBG_PRINTC(S);}}
#define DBG_TRACE(A,S...)   {if (DBG_FLAGS(A) & DBG_TRACE_ON) \
                                {DBG_PRINT("%s:%s ",DBG_NAME(A),__FUNC__);DBG_PRINTC(S);}}
#define DBG_RX(A,S...)      {if (DBG_FLAGS(A) & DBG_RX_ON) \
                                {DBG_PRINT(S);}}
#define DBG_TX(A,S...)      {if (DBG_FLAGS(A) & DBG_TX_ON) \
                                {DBG_PRINT(S);}}
#define DBG_ASSERT(C)       {if (!(C)) \
                                {DBG_PRINT("ASSERT(%s) -- %s#%d (%s)\n", \
                                    #C,__FILE__,__LINE__,__FUNC__); \
                                DBG_TRAP;}}

#define DBG_DEFN \
    char           *dbgName; \
    int             dbgLevel; \
    unsigned long   dbgFlags;
#define STATIC

/****************************************************************************/
#else // DBG
/****************************************************************************/

#define DBG_DEFN
#define DBG_TRAP
#define DBG_FUNC(F)
#define DBG_PRINT(S...)
#define DBG_ENTER(A)
#define DBG_LEAVE(A)
#define DBG_PARAM(A,N,F,S...)
#define DBG_ERROR(A,S...)
#define DBG_WARNING(A,S...)
#define DBG_NOTICE(A,S...)
#define DBG_TRACE(A,S...)
#define DBG_RX(A,S...)
#define DBG_TX(A,S...)
#define DBG_ASSERT(C)
#define STATIC static

#endif // DBG
/****************************************************************************/

#endif // _DEBUG_H

