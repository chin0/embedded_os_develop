/*
 *  linux/include/asm-arm/arch-s3c2410/s3c2410.h
 *
 *  Copyright (C) 2002 SAMSUNG ELECTORNICS 
 *                         SW.LEE (hitchcar@sec.samsung.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* Contents of This File 
 * 1.Clock Parameter  
 *      
 * 2.Register Mapping
 * 3.Physical to Virtual Mapping 
 *                     Searching Keyword: Phy2Vir
 * 4.Serial Baud Rate 
 *                     Searching Keyword: SER_BAUD
 * 5.OS Timer Parameter
 *                     Searching Keyword: OS_Timer 
 * 6.Sound clock       Searching Keyword: CODEC_CLOCK 
 *
 */


#ifndef __S3C2410_H
#define __S3C2410_H

/* keywoard : ClockParameter */
/***************  Clock Parameter  **********/
#define  FCLK 202800000
#define  HCLK (FCLK/2)
#define  PCLK (HCLK/2)
#define  UCLK  48000000
#define  BUSWIDTH (32)
/********************************************/



/* keywoard : Phy2Vir */
#define S3C2410_MEM_SIZE     (64*1024*1024) 
#define MEM_SIZE            S3C2410_MEM_SIZE
	/* Used in arm/kernel/setup.c */

                        /* used in asm/kernel/setup.c and asm/arch/arch.c  */
#define PA_SDRAM_BASE         0x30000000 /* used in asm/arch/arch.c     */
#define RAMDISK_DN_ADDR       0x30800000 /* used in asm/arch/arch.c     */
#define ZIP_RAMDISK_SIZE      (10*1024*1024)  /* used in asm/arch/arch.c  */

/* if CONFIG_BLK_DEV_RAM_SIZE not defined */
#define BLK_DEV_RAM_SIZE      (8*1024*1024)  


/*** S3C2410 Register Address Part ***************************
 *If you change this mapping between Physical and Virtual
 *YOU MUST CHNAGE MACRO in the include/asm/arch-s3c2410/memory.h
 * ex) __Distance_PA_VA
 *and also SDRAM Mapping must be changed becasue __Distance_PA_VA is
 * applied to IO Register and SDRAM
 */ 

/* Be careful !!!!
 * PAGE_OFFSET + VMALLOC_END = 0xD0000000
 */

#define VA_IO_BASE0           (0xD0000000)
#define VA_IO_BASE1           (0xE0000000)
#define VA_IO_BASE2           (0xD8000000) /* CS8900A */

#define PA_MEM_CTR_BASE       (0x48000000)/* used int asm/arch/mm.c */
#define VA_MEM_CTR_BASE       (VA_IO_BASE0+0x08000000)
#define PA_USB_BASE           (0x49000000)
#define VA_USB_BASE           (VA_IO_BASE0+0x09000000)
#define PA_INT_BASE           (0x4A000000)
#define VA_INT_BASE           (VA_IO_BASE0+0x0A000000)
#define PA_DMA_BASE           (0x4B000000)
#define VA_DMA_BASE           (VA_IO_BASE0+0x0B000000)
#define PA_CKPO_BASE          (0x4C000000)
#define VA_CKPO_BASE          (VA_IO_BASE0+0x0C000000)
#define PA_LCD_BASE           (0x4D000000)
#define VA_LCD_BASE           (VA_IO_BASE0+0x0D000000)
#define PA_NAND_BASE          (0x4E000000)
#define VA_NAND_BASE          (VA_IO_BASE0+0x0E000000)
#define PA_UART_BASE          (0x50000000)
#define VA_UART_BASE          (VA_IO_BASE1+0x00000000)
#define PA_TIMER_BASE         (0x51000000)
#define VA_TIMER_BASE         (VA_IO_BASE1+0x01000000)
#define PA_UD_BASE            (0x52000000)	/* WATCH DOG AND USB DEVICE */
#define VA_UD_BASE            (VA_IO_BASE1+0x02000000)	/* WATCH DOG AND USB DEVICE */
#define PA_WD_BASE            (0x53000000)
#define VA_WD_BASE            (VA_IO_BASE1+0x03000000)
#define PA_IIC_BASE           (0x54000000)
#define VA_IIC_BASE           (VA_IO_BASE1+0x04000000)
#define PA_IIS_BASE           (0x55000000)
#define VA_IIS_BASE           (VA_IO_BASE1+0x05000000)
#define PA_IO_PORT_BASE       (0x56000000)
#define VA_IO_PORT_BASE       (VA_IO_BASE1+0x06000000)
#define PA_RTC_BASE           (0x57000000)
#define VA_RTC_BASE           (VA_IO_BASE1+0x07000000)
#define PA_ADC_BASE           (0x58000000)
#define VA_ADC_BASE           (VA_IO_BASE1+0x08000000)
#define PA_SPI_BASE           (0x59000000)
#define VA_SPI_BASE           (VA_IO_BASE1+0x09000000)
#define PA_SD_BASE            (0x5A000000)
#define VA_SD_BASE            (VA_IO_BASE1+0x0A000000)

#define PA_CS8900A_BASE       (0x19000000)  /* nGCS3 +0x10000000 */
#define VA_CS8900A_BASE       (VA_IO_BASE2+0x18000000) /* 0xF0000000 */



// Memory control 
#define rBWSCON    (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x00)) //Bus width & wait status
#define rBANKCON0  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x04)) //Boot ROM control
#define rBANKCON1  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x08)) //BANK1 control
#define rBANKCON2  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x0c)) //BANK2 cControl
#define rBANKCON3  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x10)) //BANK3 control
#define rBANKCON4  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x14)) //BANK4 control
#define rBANKCON5  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x18)) //BANK5 control
#define rBANKCON6  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x1c)) //BANK6 control
#define rBANKCON7  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x20)) //BANK7 control
#define rREFRESH   (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x24)) //DRAM/SDRAM refresh
#define rBANKSIZE  (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x28)) //Flexible Bank Size
#define rMRSRB6    (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x2c)) //Mode register set for SDRAM
#define rMRSRB7    (*(volatile unsigned *)(VA_MEM_CTR_BASE+0x30)) //Mode register set for SDRAM


// USB Host


// INTERRUPT
#define rSRCPND     (*(volatile unsigned *)(VA_INT_BASE+0x00)) //Interrupt request status
#define rINTMOD     (*(volatile unsigned *)(VA_INT_BASE+0x04)) //Interrupt mode control
#define rINTMSK     (*(volatile unsigned *)(VA_INT_BASE+0x08)) //Interrupt mask control
#define rPRIORITY   (*(volatile unsigned *)(VA_INT_BASE+0x0a)) //IRQ priority control
#define rINTPND     (*(volatile unsigned *)(VA_INT_BASE+0x10)) //Interrupt request status
#define rINTOFFSET  (*(volatile unsigned *)(VA_INT_BASE+0x14)) //Interruot request source offset
#define rSUBSRCPND  (*(volatile unsigned *)(VA_INT_BASE+0x18)) //Sub source pending
#define rINTSUBMSK  (*(volatile unsigned *)(VA_INT_BASE+0x1c)) //Interrupt sub mask


// DMA
#define rDISRC0     (*(volatile unsigned *)(VA_DMA_BASE+0x00)) //DMA 0 Initial source
#define rDISRCC0    (*(volatile unsigned *)(VA_DMA_BASE+0x04)) //DMA 0 Initial source control
#define rDIDST0     (*(volatile unsigned *)(VA_DMA_BASE+0x08)) //DMA 0 Initial Destination
#define rDIDSTC0    (*(volatile unsigned *)(VA_DMA_BASE+0x0c)) //DMA 0 Initial Destination control
#define rDCON0      (*(volatile unsigned *)(VA_DMA_BASE+0x10)) //DMA 0 Control
#define rDSTAT0     (*(volatile unsigned *)(VA_DMA_BASE+0x14))//DMA 0 Status
#define rDCSRC0     (*(volatile unsigned *)(VA_DMA_BASE+0x18))//DMA 0 Current source
#define rDCDST0     (*(volatile unsigned *)(VA_DMA_BASE+0x1c))//DMA 0 Current destination
#define rDMASKTRIG0 (*(volatile unsigned *)(VA_DMA_BASE+0x20))//DMA 0 Mask trigger

#define rDISRC1     (*(volatile unsigned *)(VA_DMA_BASE+0x40))//DMA 1 Initial source
#define rDISRCC1    (*(volatile unsigned *)(VA_DMA_BASE+0x44))//DMA 1 Initial source control
#define rDIDST1     (*(volatile unsigned *)(VA_DMA_BASE+0x48))//DMA 1 Initial Destination
#define rDIDSTC1    (*(volatile unsigned *)(VA_DMA_BASE+0x4c))//DMA 1 Initial Destination control
#define rDCON1      (*(volatile unsigned *)(VA_DMA_BASE+0x50))//DMA 1 Control
#define rDSTAT1     (*(volatile unsigned *)(VA_DMA_BASE+0x54))//DMA 1 Status
#define rDCSRC1     (*(volatile unsigned *)(VA_DMA_BASE+0x58))//DMA 1 Current source
#define rDCDST1     (*(volatile unsigned *)(VA_DMA_BASE+0x5c))//DMA 1 Current destination
#define rDMASKTRIG1 (*(volatile unsigned *)(VA_DMA_BASE+0x60))//DMA 1 Mask trigger

#define rDISRC2     (*(volatile unsigned *)(VA_DMA_BASE+0x80))//DMA 2 Initial source
#define rDISRCC2    (*(volatile unsigned *)(VA_DMA_BASE+0x84))//DMA 2 Initial source control
#define rDIDST2     (*(volatile unsigned *)(VA_DMA_BASE+0x88))//DMA 2 Initial Destination
#define rDIDSTC2    (*(volatile unsigned *)(VA_DMA_BASE+0x8c))//DMA 2 Initial Destination control
#define rDCON2      (*(volatile unsigned *)(VA_DMA_BASE+0x90))//DMA 2 Control
#define rDSTAT2     (*(volatile unsigned *)(VA_DMA_BASE+0x94))//DMA 2 Status
#define rDCSRC2     (*(volatile unsigned *)(VA_DMA_BASE+0x98))//DMA 2 Current source
#define rDCDST2     (*(volatile unsigned *)(VA_DMA_BASE+0x9c))//DMA 2 Current destination
#define rDMASKTRIG2 (*(volatile unsigned *)(VA_DMA_BASE+0xa0))//DMA 2 Mask trigger

#define rDISRC3     (*(volatile unsigned *)(VA_DMA_BASE+0xc0))//DMA 3 Initial source
#define rDISRCC3    (*(volatile unsigned *)(VA_DMA_BASE+0xc4))//DMA 3 Initial source control
#define rDIDST3     (*(volatile unsigned *)(VA_DMA_BASE+0xc8))//DMA 3 Initial Destination
#define rDIDSTC3    (*(volatile unsigned *)(VA_DMA_BASE+0xcc))//DMA 3 Initial Destination control
#define rDCON3      (*(volatile unsigned *)(VA_DMA_BASE+0xd0))//DMA 3 Control
#define rDSTAT3     (*(volatile unsigned *)(VA_DMA_BASE+0xd4))//DMA 3 Status
#define rDCSRC3     (*(volatile unsigned *)(VA_DMA_BASE+0xd8))//DMA 3 Current source
#define rDCDST3     (*(volatile unsigned *)(VA_DMA_BASE+0xdc))//DMA 3 Current destination
#define rDMASKTRIG3 (*(volatile unsigned *)(VA_DMA_BASE+0xe0))//DMA 3 Mask trigger

/* DMA Device Address Reg. channel [0..3] */
#define DMASp   	0x40	  /* DMA control reg. Space [byte]   */
#define ARRAY_DISRC(Nb)	((volatile unsigned *)(VA_DMA_BASE+(Nb)*DMASp))
 /*  USED  s3c2410_init_dma functions in arch/arm/mach-s3c2410/dma-s3c2410.c  */

/* 
   STAT 00 = it indicates DMA controller ready
        01 =              DMA controller BUSY 
*/
#define DSTAT_STAT_READY      0x000000         
#define DSTAT_STAT_BUSY       0x100000         

#define DMASKTRIG_STOP        0x4 /* 0100 */
#define DMASKTRIG_START       0x0 /*  */
#define DMASKTRIG_ON          0x2
#define DMASKTRIG_OFF         0x0
#define DMASKTRIG_NO_SW_TRIG     0x0

/* DMA CONTROL REGISTER FlAG */
#define DCON_HS_MODE        ( 0x1 << 30)
#define DCON_SYNC_AHB       ( 0x1 << 29)
#define DCON_INT_ENABLE     ( 0x1 << 28)
#define DCON_TSZ_BURST      ( 0x1 << 27)
#define DCON_WHSR_MODE      ( 0x1 << 26)
#define DCON_HWSRCSEL_I2SDO ( 0x00 << 24)
#define DCON_HW_SEL         ( 0x1 << 23)
#define DCON_NO_AUTO_RELOAD ( 0x1 << 22)
#define DCON_DSZ_HWORD      ( 0x1 << 20)




// CLOCK & POWER MANAGEMENT
#define rLOCKTIME   (*(volatile unsigned *)(VA_CKPO_BASE+0x00))//PLL lock time counter
#define rMPLLCON    (*(volatile unsigned *)(VA_CKPO_BASE+0x04)) //MPLL Control
#define rUPLLCON    (*(volatile unsigned *)(VA_CKPO_BASE+0x08)) //UPLL Control
#define rCLKCON     (*(volatile unsigned *)(VA_CKPO_BASE+0x0c)) //Clock generator control
#define rCLKSLOW    (*(volatile unsigned *)(VA_CKPO_BASE+0x10)) //Slow clock control
#define rCLKDIVN    (*(volatile unsigned *)(VA_CKPO_BASE+0x14)) //Clock divider control


// LCD CONTROLLER
#define rLCDCON1    (*(volatile unsigned *)(VA_LCD_BASE+0x00)) //LCD control 1
#define rLCDCON2    (*(volatile unsigned *)(VA_LCD_BASE+0x04)) //LCD control 2
#define rLCDCON3    (*(volatile unsigned *)(VA_LCD_BASE+0x08)) //LCD control 3
#define rLCDCON4    (*(volatile unsigned *)(VA_LCD_BASE+0x0c)) //LCD control 4
#define rLCDCON5    (*(volatile unsigned *)(VA_LCD_BASE+0x10)) //LCD control 5
#define rLCDSADDR1  (*(volatile unsigned *)(VA_LCD_BASE+0x14)) //STN/TFT Frame buffer start address 1
#define rLCDSADDR2  (*(volatile unsigned *)(VA_LCD_BASE+0x18)) //STN/TFT Frame buffer start address 2
#define rLCDSADDR3  (*(volatile unsigned *)(VA_LCD_BASE+0x1c)) //STN/TFT Virtual screen address set
#define rREDLUT     (*(volatile unsigned *)(VA_LCD_BASE+0x20)) //STN Red lookup table
#define rGREENLUT   (*(volatile unsigned *)(VA_LCD_BASE+0x24)) //STN Green lookup table 
#define rBLUELUT    (*(volatile unsigned *)(VA_LCD_BASE+0x28)) //STN Blue lookup table
#define rDITHMODE   (*(volatile unsigned *)(VA_LCD_BASE+0x4c)) //STN Dithering mode
#define rTPAL       (*(volatile unsigned *)(VA_LCD_BASE+0x50)) //TFT Temporary palette
#define rLCDINTPND  (*(volatile unsigned *)(VA_LCD_BASE+0x54)) //LCD Interrupt pending
#define rLCDSRCPND  (*(volatile unsigned *)(VA_LCD_BASE+0x58)) //LCD Interrupt source
#define rLCDINTMSK  (*(volatile unsigned *)(VA_LCD_BASE+0x5c)) //LCD Interrupt mask
#define rLPCSEL     (*(volatile unsigned *)(VA_LCD_BASE+0x60)) //LPC3600 Control
#define PALETTE     0x4d000400                         //Palette start address

/* 
 * LCD Parameter 
 * Used in drivers/video/s3c2410fb.c
 */
#define TFT240_320	1    
                     /* Used in s3c2410fb.c */
#define LCD_TYPE	TFT240_320
#define CURRENT_LCD_X    240 /* used in Touch Screen */
#define CURRENT_LCD_Y    320 /* used in Touch Screen */ 



#define MVAL                (13)
#define MVAL_USED           (0)
#define M5D(n)              ((n) & 0x1fffff)

#if (LCD_TYPE == TFT240_320 )
	#define VBPD                ((1)&0xff)
	#define VFPD                ((2)&0xff)
	#define VSPW                ((1) &0x3f)
	
	#define HBPD                ((6)&0x7f)
	#define HFPD                ((2)&0xff)
	#define HSPW                ((3)&0xff)
	
	#define CLKVAL_STN_MONO     (22) 	
	    //69.14hz @60Mhz,WLH=16clk,WDLY=16clk,LINEBLANK=1*8,VD=4 
	#define CLKVAL_STN_GRAY     (12) 	
	    //124hz @60Mhz,WLH=16clk,WDLY=16clk,LINEBLANK=1*8,VD=4  
	#define CLKVAL_CSTN         (8) 	
	    //135hz @60Mhz,WLH=16clk,WDLY=16clk,LINEBLANK=1*8,VD=8  
	#define CLKVAL_TFT          (6)
#endif

#define U8 unsigned char 
// NAND flash
#define rNFCONF     (*(volatile unsigned *)(VA_NAND_BASE+0x00))      //NAND Flash configuration
#define rNFCMD      (*(volatile U8 *)(VA_NAND_BASE+0x04))            //NADD Flash command
#define rNFADDR     (*(volatile U8 *)(VA_NAND_BASE+0x08))            //NAND Flash address
#define rNFDATA     (*(volatile U8 *)(VA_NAND_BASE+0x0c))            //NAND Flash data
#define rNFSTAT     (*(volatile unsigned *)(VA_NAND_BASE+0x10))      //NAND Flash operation status
#define rNFECC      (*(volatile unsigned *)(VA_NAND_BASE+0x14))      //NAND Flash ECC
#define rNFECC0     (*(volatile U8  *)(VA_NAND_BASE+0x14))
#define rNFECC1     (*(volatile U8  *)(VA_NAND_BASE+0x15))
#define rNFECC2     (*(volatile U8  *)(VA_NAND_BASE+0x16))

/*** used drivers/mtd/nand **********************/
#define NF_CMD(cmd)	{rNFCMD=cmd;}
#define NF_ADDR(addr)	{rNFADDR=addr;}	
#define NF_nFCE_L()	{rNFCONF&=~(1<<11);}
#define NF_nFCE_H()	{rNFCONF|=(1<<11);}
#define NF_RSTECC()	{rNFCONF|=(1<<12);}
#define NF_RDDATA() 	(rNFDATA)
#define NF_WRDATA(data) {rNFDATA=data;}
#define NF_WAITRB()    {while(!(rNFSTAT&(1<<0)));} 

#define NAND_CTL_S3C_WAIT  0x100   /* Dummy Value >= 0x100 */
                      /* used mtd/nand/NAND.c s3c2410_nand.c*/


// UART
#define rULCON0     (*(volatile unsigned *)(VA_UART_BASE+0x00)) //UART 0 Line control
#define rUCON0      (*(volatile unsigned *)(VA_UART_BASE+0x04)) //UART 0 Control
#define rUFCON0     (*(volatile unsigned *)(VA_UART_BASE+0x08)) //UART 0 FIFO control
#define rUMCON0     (*(volatile unsigned *)(VA_UART_BASE+0x0c)) //UART 0 Modem control
#define rUTRSTAT0   (*(volatile unsigned *)(VA_UART_BASE+0x10)) //UART 0 Tx/Rx status
#define rUERSTAT0   (*(volatile unsigned *)(VA_UART_BASE+0x14)) //UART 0 Rx error status
#define rUFSTAT0    (*(volatile unsigned *)(VA_UART_BASE+0x18)) //UART 0 FIFO status
#define rUMSTAT0    (*(volatile unsigned *)(VA_UART_BASE+0x1c)) //UART 0 Modem status
#define rUBRDIV0    (*(volatile unsigned *)(VA_UART_BASE+0x28)) //UART 0 Baud rate divisor

#define rULCON1     (*(volatile unsigned *)(VA_UART_BASE+0x4000)) //UART 1 Line control
#define rUCON1      (*(volatile unsigned *)(VA_UART_BASE+0x4004)) //UART 1 Control
#define rUFCON1     (*(volatile unsigned *)(VA_UART_BASE+0x4008)) //UART 1 FIFO control
#define rUMCON1     (*(volatile unsigned *)(VA_UART_BASE+0x400c)) //UART 1 Modem control
#define rUTRSTAT1   (*(volatile unsigned *)(VA_UART_BASE+0x4010)) //UART 1 Tx/Rx status
#define rUERSTAT1   (*(volatile unsigned *)(VA_UART_BASE+0x4014)) //UART 1 Rx error status
#define rUFSTAT1    (*(volatile unsigned *)(VA_UART_BASE+0x4018)) //UART 1 FIFO status
#define rUMSTAT1    (*(volatile unsigned *)(VA_UART_BASE+0x401c)) //UART 1 Modem status
#define rUBRDIV1    (*(volatile unsigned *)(VA_UART_BASE+0x4028)) //UART 1 Baud rate divisor

#define rULCON2     (*(volatile unsigned *)(VA_UART_BASE+0x8000)) //UART 2 Line control
#define rUCON2      (*(volatile unsigned *)(VA_UART_BASE+0x8004)) //UART 2 Control
#define rUFCON2     (*(volatile unsigned *)(VA_UART_BASE+0x8008)) //UART 2 FIFO control
#define rUMCON2     (*(volatile unsigned *)(VA_UART_BASE+0x800c)) //UART 2 Modem control
#define rUTRSTAT2   (*(volatile unsigned *)(VA_UART_BASE+0x8010)) //UART 2 Tx/Rx status
#define rUERSTAT2   (*(volatile unsigned *)(VA_UART_BASE+0x8014)) //UART 2 Rx error status
#define rUFSTAT2    (*(volatile unsigned *)(VA_UART_BASE+0x8018)) //UART 2 FIFO status
#define rUMSTAT2    (*(volatile unsigned *)(VA_UART_BASE+0x801c)) //UART 2 Modem status
#define rUBRDIV2    (*(volatile unsigned *)(VA_UART_BASE+0x8028)) //UART 2 Baud rate divisor

#ifdef __BIG_ENDIAN
#define rUTXH0      (*(volatile unsigned char *)(VA_UART_BASE+0x23)) //UART 0 Transmission Hold
#define rURXH0      (*(volatile unsigned char *)(VA_UART_BASE+0x27)) //UART 0 Receive buffer
#define rUTXH1      (*(volatile unsigned char *)(VA_UART_BASE+0x4023)) //UART 1 Transmission Hold
#define rURXH1      (*(volatile unsigned char *)(VA_UART_BASE+0x4027)) //UART 1 Receive buffer
#define rUTXH2      (*(volatile unsigned char *)(VA_UART_BASE+0x8023)) //UART 2 Transmission Hold
#define rURXH2      (*(volatile unsigned char *)(VA_UART_BASE+0x8027)) //UART 2 Receive buffer

#define WrUTXH0(ch) (*(volatile unsigned char *)(VA_UART_BASE+0x23))=(unsigned char)(ch)
#define RdURXH0()   (*(volatile unsigned char *)(VA_UART_BASE+0x27))
#define WrUTXH1(ch) (*(volatile unsigned char *)(VA_UART_BASE+0x4023))=(unsigned char)(ch)
#define RdURXH1()   (*(volatile unsigned char *)(VA_UART_BASE+0x4027))
#define WrUTXH2(ch) (*(volatile unsigned char *)(VA_UART_BASE+0x8023))=(unsigned char)(ch)
#define RdURXH2()   (*(volatile unsigned char *)(VA_UART_BASE+0x8027))

#define UTXH0       (VA_UART_BASE+0x20+3)  //Byte_access address by DMA
#define URXH0       (VA_UART_BASE+0x24+3)
#define UTXH1       (VA_UART_BASE+0x4020+3)
#define URXH1       (VA_UART_BASE+0x4024+3)
#define UTXH2       (VA_UART_BASE+0x8020+3)
#define URXH2       (VA_UART_BASE+0x8024+3)

#else //Little Endian
#define rUTXH0 (*(volatile unsigned char *)(VA_UART_BASE+0x20)) //UART 0 Transmission Hold
#define rURXH0 (*(volatile unsigned char *)(VA_UART_BASE+0x24)) //UART 0 Receive buffer
#define rUTXH1 (*(volatile unsigned char *)(VA_UART_BASE+0x4020)) //UART 1 Transmission Hold
#define rURXH1 (*(volatile unsigned char *)(VA_UART_BASE+0x4024)) //UART 1 Receive buffer
#define rUTXH2 (*(volatile unsigned char *)(VA_UART_BASE+0x8020)) //UART 2 Transmission Hold
#define rURXH2 (*(volatile unsigned char *)(VA_UART_BASE+0x8024)) //UART 2 Receive buffer

#define WrUTXH0(ch) (*(volatile unsigned char *)(VA_UART_BASE+0x20))=(unsigned char)(ch)
#define RdURXH0()   (*(volatile unsigned char *)(VA_UART_BASE+0x24))
#define WrUTXH1(ch) (*(volatile unsigned char *)(VA_UART_BASE+0x4020))=(unsigned char)(ch)
#define RdURXH1()   (*(volatile unsigned char *)(VA_UART_BASE+0x4024))
#define WrUTXH2(ch) (*(volatile unsigned char *)(VA_UART_BASE+0x8020))=(unsigned char)(ch)
#define RdURXH2()   (*(volatile unsigned char *)(VA_UART_BASE+0x8024))

#define UTXH0       (VA_UART_BASE+0x20)    //Byte_access address by DMA
#define URXH0       (VA_UART_BASE+0x24)
#define UTXH1       (VA_UART_BASE+0x4020)
#define URXH1       (VA_UART_BASE+0x4024)
#define UTXH2       (VA_UART_BASE+0x8020)
#define URXH2       (VA_UART_BASE+0x8024)
#endif


// PWM TIMER
#define rTCFG0  (*(volatile unsigned *)(VA_TIMER_BASE+0x00)) //Timer 0 configuration
#define rTCFG1  (*(volatile unsigned *)(VA_TIMER_BASE+0x04)) //Timer 1 configuration
#define rTCON   (*(volatile unsigned *)(VA_TIMER_BASE+0x08)) //Timer control
#define rTCNTB0 (*(volatile unsigned *)(VA_TIMER_BASE+0x0c)) //Timer count buffer 0
#define rTCMPB0 (*(volatile unsigned *)(VA_TIMER_BASE+0x10)) //Timer compare buffer 0
#define rTCNTO0 (*(volatile unsigned *)(VA_TIMER_BASE+0x14)) //Timer count observation 0
#define rTCNTB1 (*(volatile unsigned *)(VA_TIMER_BASE+0x18)) //Timer count buffer 1
#define rTCMPB1 (*(volatile unsigned *)(VA_TIMER_BASE+0x1c)) //Timer compare buffer 1
#define rTCNTO1 (*(volatile unsigned *)(VA_TIMER_BASE+0x20)) //Timer count observation 1
#define rTCNTB2 (*(volatile unsigned *)(VA_TIMER_BASE+0x24)) //Timer count buffer 2
#define rTCMPB2 (*(volatile unsigned *)(VA_TIMER_BASE+0x28)) //Timer compare buffer 2
#define rTCNTO2 (*(volatile unsigned *)(VA_TIMER_BASE+0x2c)) //Timer count observation 2
#define rTCNTB3 (*(volatile unsigned *)(VA_TIMER_BASE+0x30)) //Timer count buffer 3
#define rTCMPB3 (*(volatile unsigned *)(VA_TIMER_BASE+0x34)) //Timer compare buffer 3
#define rTCNTO3 (*(volatile unsigned *)(VA_TIMER_BASE+0x38)) //Timer count observation 3
#define rTCNTB4 (*(volatile unsigned *)(VA_TIMER_BASE+0x3c)) //Timer count buffer 4
#define rTCNTO4 (*(volatile unsigned *)(VA_TIMER_BASE+0x40)) //Timer count observation 4

/* Searching Keyword: OS_Timer */
#define SYS_TIMER234_PRESCALER  202
#define SYS_TIMER01_PRESCALER   24      /* for Touch Screen  */

#define SYS_TIMER4_MUX          1	/* 1/4  */
#define SYS_TIMER4_DIVIDER      4 

#define SYS_TIMER1_MUX          0	/* 1/2  */
#define SYS_TIMER1_DIVIDER      2 

/* RTC will use TIMER 0  for periodic signal */
#define SYS_TIMER0_MUX          3	/* 1/2  */
#define SYS_TIMER0_DIVIDER      16

#define TOUCH_RESCHED_PERIOD    10      /* 10 ms */
#define RESCHED_PERIOD          10      /* 10 ms */
#define HZ                      100


// USB DEVICE
#ifdef __BIG_ENDIAN
<ERROR IF BIG_ENDIAN>
#define rFUNC_ADDR_REG     (*(volatile unsigned char *)(VA_UD_BASE+0x143)) //Function address
#define rPWR_REG           (*(volatile unsigned char *)(VA_UD_BASE+0x147)) //Power management
#define rEP_INT_REG        (*(volatile unsigned char *)(VA_UD_BASE+0x14b)) //EP Interrupt pending and clear
#define rUSB_INT_REG       (*(volatile unsigned char *)(VA_UD_BASE+0x15b)) //USB Interrupt pending and clear
#define rEP_INT_EN_REG     (*(volatile unsigned char *)(VA_UD_BASE+0x15f)) //Interrupt enable
#define rUSB_INT_EN_REG    (*(volatile unsigned char *)(VA_UD_BASE+0x16f))
#define rFRAME_NUM1_REG    (*(volatile unsigned char *)(VA_UD_BASE+0x173)) //Frame number lower byte
#define rFRAME_NUM2_REG    (*(volatile unsigned char *)(VA_UD_BASE+0x177)) //Frame number higher byte
#define rINDEX_REG         (*(volatile unsigned char *)(VA_UD_BASE+0x17b)) //Register index
#define rMAXP_REG          (*(volatile unsigned char *)(VA_UD_BASE+0x183)) //Endpoint max packet
#define rEP0_CSR           (*(volatile unsigned char *)(VA_UD_BASE+0x187)) //Endpoint 0 status
#define rIN_CSR1_REG       (*(volatile unsigned char *)(VA_UD_BASE+0x187)) //In endpoint control status
#define rIN_CSR2_REG       (*(volatile unsigned char *)(VA_UD_BASE+0x18b))
#define rOUT_CSR1_REG      (*(volatile unsigned char *)(VA_UD_BASE+0x193) //Out endpoint control status
#define rOUT_CSR2_REG      (*(volatile unsigned char *)(VA_UD_BASE+0x197))
#define rOUT_FIFO_CNT1_REG (*(volatile unsigned char *)(VA_UD_BASE+0x19b)) //Endpoint out write count
#define rOUT_FIFO_CNT2_REG (*(volatile unsigned char *)(VA_UD_BASE+0x19f))
#define rEP0_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1c3)) //Endpoint 0 FIFO
#define rEP1_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1c7)) //Endpoint 1 FIFO
#define rEP2_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1cb)) //Endpoint 2 FIFO
#define rEP3_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1cf)) //Endpoint 3 FIFO
#define rEP4_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1d3)) //Endpoint 4 FIFO
#define rEP1_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x203)) //EP1 DMA interface control
#define rEP1_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x207)) //EP1 DMA Tx unit counter
#define rEP1_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x20b)) //EP1 DMA Tx FIFO counter
#define rEP1_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x20f)) //EP1 DMA total Tx counter
#define rEP1_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x213))
#define rEP1_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x217))
#define rEP2_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x21b)) //EP2 DMA interface control
#define rEP2_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x21f)) //EP2 DMA Tx unit counter
#define rEP2_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x223)) //EP2 DMA Tx FIFO counter
#define rEP2_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x227)) //EP2 DMA total Tx counter
#define rEP2_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x22b)
#define rEP2_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x22f)
#define rEP3_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x243)) //EP3 DMA interface control
#define rEP3_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x247)) //EP3 DMA Tx unit counter
#define rEP3_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x24b)) //EP3 DMA Tx FIFO counter
#define rEP3_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x24f)) //EP3 DMA total Tx counter
#define rEP3_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x253))
#define rEP3_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x257))
#define rEP4_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x25b)) //EP4 DMA interface control
#define rEP4_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x25f)) //EP4 DMA Tx unit counter
#define rEP4_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x263)) //EP4 DMA Tx FIFO counter
#define rEP4_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x267)) //EP4 DMA total Tx counter
#define rEP4_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x26b))
#define rEP4_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x26f))

#else  // Little Endian
#define rFUNC_ADDR_REG     (*(volatile unsigned char *)(VA_UD_BASE+0x140)) //Function address
#define rPWR_REG           (*(volatile unsigned char *)(VA_UD_BASE+0x144)) //Power management
#define rEP_INT_REG        (*(volatile unsigned char *)(VA_UD_BASE+0x148)) //EP Interrupt pending and clear
#define rUSB_INT_REG       (*(volatile unsigned char *)(VA_UD_BASE+0x158)) //USB Interrupt pending and clear
#define rEP_INT_EN_REG     (*(volatile unsigned char *)(VA_UD_BASE+0x15c)) //Interrupt enable
#define rUSB_INT_EN_REG    (*(volatile unsigned char *)(VA_UD_BASE+0x16c))
#define rFRAME_NUM1_REG    (*(volatile unsigned char *)(VA_UD_BASE+0x170)) //Frame number lower byte
#define rFRAME_NUM2_REG    (*(volatile unsigned char *)(VA_UD_BASE+0x174)) //Frame number higher byte
#define rINDEX_REG         (*(volatile unsigned char *)(VA_UD_BASE+0x178)) //Register index
#define rMAXP_REG          (*(volatile unsigned char *)(VA_UD_BASE+0x180)) //Endpoint max packet
#define rEP0_CSR           (*(volatile unsigned char *)(VA_UD_BASE+0x184)) //Endpoint 0 status
#define rIN_CSR1_REG       (*(volatile unsigned char *)(VA_UD_BASE+0x184)) //In endpoint control status
#define rIN_CSR2_REG       (*(volatile unsigned char *)(VA_UD_BASE+0x188))
#define rOUT_CSR1_REG      (*(volatile unsigned char *)(VA_UD_BASE+0x190)) //Out endpoint control status
#define rOUT_CSR2_REG      (*(volatile unsigned char *)(VA_UD_BASE+0x194))
#define rOUT_FIFO_CNT1_REG (*(volatile unsigned char *)(VA_UD_BASE+0x198)) //Endpoint out write count
#define rOUT_FIFO_CNT2_REG (*(volatile unsigned char *)(VA_UD_BASE+0x19c))
#define rEP0_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1c0)) //Endpoint 0 FIFO
#define rEP1_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1c4)) //Endpoint 1 FIFO
#define rEP2_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1c8)) //Endpoint 2 FIFO
#define rEP3_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1cc)) //Endpoint 3 FIFO
#define rEP4_FIFO          (*(volatile unsigned char *)(VA_UD_BASE+0x1d0)) //Endpoint 4 FIFO
#define rEP1_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x200)) //EP1 DMA interface control
#define rEP1_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x204)) //EP1 DMA Tx unit counter
#define rEP1_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x208)) //EP1 DMA Tx FIFO counter
#define rEP1_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x20c)) //EP1 DMA total Tx counter
#define rEP1_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x210))
#define rEP1_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x214))
#define rEP2_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x218)) //EP2 DMA interface control
#define rEP2_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x21c)) //EP2 DMA Tx unit counter
#define rEP2_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x220)) //EP2 DMA Tx FIFO counter
#define rEP2_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x224)) //EP2 DMA total Tx counter
#define rEP2_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x228))
#define rEP2_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x22c))
#define rEP3_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x240)) //EP3 DMA interface control
#define rEP3_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x244)) //EP3 DMA Tx unit counter
#define rEP3_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x248)) //EP3 DMA Tx FIFO counter
#define rEP3_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x24c)) //EP3 DMA total Tx counter
#define rEP3_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x250))
#define rEP3_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x254))
#define rEP4_DMA_CON       (*(volatile unsigned char *)(VA_UD_BASE+0x258)) //EP4 DMA interface control
#define rEP4_DMA_UNIT      (*(volatile unsigned char *)(VA_UD_BASE+0x25c)) //EP4 DMA Tx unit counter
#define rEP4_DMA_FIFO      (*(volatile unsigned char *)(VA_UD_BASE+0x260)) //EP4 DMA Tx FIFO counter
#define rEP4_DMA_TTC_L     (*(volatile unsigned char *)(VA_UD_BASE+0x264)) //EP4 DMA total Tx counter
#define rEP4_DMA_TTC_M     (*(volatile unsigned char *)(VA_UD_BASE+0x268))
#define rEP4_DMA_TTC_H     (*(volatile unsigned char *)(VA_UD_BASE+0x26c))
#endif   // __BIG_ENDIAN


// WATCH DOG TIMER
#define rWTCON   (*(volatile unsigned *)(VA_WD_BASE+0x00)) //Watch-dog timer mode
#define rWTDAT   (*(volatile unsigned *)(VA_WD_BASE+0x04)) //Watch-dog timer data
#define rWTCNT   (*(volatile unsigned *)(VA_WD_BASE+0x08)) //Eatch-dog timer count


// IIC
#define rIICCON  (*(volatile unsigned *)(VA_IIC_BASE+0x00)) //IIC control
#define rIICSTAT (*(volatile unsigned *)(VA_IIC_BASE+0x04)) //IIC status
#define rIICADD  (*(volatile unsigned *)(VA_IIC_BASE+0x08)) //IIC address
#define rIICDS   (*(volatile unsigned *)(VA_IIC_BASE+0x0c)) //IIC data shift


// IIS
#define rIISCON  (*(volatile unsigned *)(VA_IIS_BASE+0x00)) //IIS Control
#define rIISMOD  (*(volatile unsigned *)(VA_IIS_BASE+0x04)) //IIS Mode
#define rIISPSR  (*(volatile unsigned *)(VA_IIS_BASE+0x08)) //IIS Prescaler
#define rIISFCON (*(volatile unsigned *)(VA_IIS_BASE+0x0c)) //IIS FIFO control

#ifdef __BIG_ENDIAN
#define IISFIFO  ((volatile unsigned short *)(PA_IIS_BASE+0x12)) //IIS FIFO entry

#else //Little Endian
#define IISFIFO  ((volatile unsigned short *)(PA_IIS_BASE+0x10)) //IIS FIFO entry
/*  used in drivers/sound/s3c2410-uda1341.c asm/arm/arch/dma.h */

#endif

/*-----------------------------------------------------*/
 //  Used in arch/arm/mach-s3c2410/dma-s3c2410.c
/* IISCON Flag  */
#define      LEFT_CHANNEL                ( 0 << 8)
#define      RIGHT_CHANNEL               ( 1 << 8)
#define      TX_FIFO_READY               ( 1 << 7)
#define      RX_FIFO_READY               ( 1 << 6)
#define      TX_DMA_REQUEST_ENABLE       ( 1 << 5)
#define      RX_DMA_REQUEST_ENABLE       ( 1 << 4)
#define      TX_CNANNEL_IDLE             ( 1 << 3)
#define      RX_CNANNEL_IDLE             ( 1 << 2)
#define      PRESCALER_ENABLE            ( 1 << 1)
#define      IIS_INTERFACE_ENABLE        ( 1 << 0)
#define      IIS_INTERFACE_DISABLE       ( 0 << 0)
/* IISMOD  FLAG */
#define      MASTER_MODE                 ( 0 << 8)
#define      SLAVE_MODE                  ( 1 << 8)
#define      TRANSMIT_MODE               ( 2 << 6)
#define      LOW_LEFT_CH                 ( 0 << 5)
#define      IIS_FORMAT                  ( 0 << 4)
#define      SERIAL_8BIT_PER_CH          ( 0 << 3)
#define      SERIAL_16BIT_PER_CH         ( 1 << 3)
#define      MASTER_CODECLK_256FS        ( 0 << 2)
#define      MASTER_CODECLK_384FS        ( 1 << 2)
#define      SERIAL_BIT_CLOCK_16FS       ( 0 << 0)
#define      SERIAL_BIT_CLOCK_32FS       ( 1 << 0)
#define      SERIAL_BIT_CLOCK_48FS       ( 2 << 0)

/*  IISFCON  FLAG */
#define      TX_DMA_ACCESS_MODE          ( 1 << 11)
#define      RX_DMA_ACCESS_MODE          ( 1 << 10)
#define      TX_FIFO_ENABLE              ( 1 << 9 )
#define      RX_FIFO_ENABLE              ( 1 << 8 )

/* Searching Keyword: CODEC_CLOCK */
/* Used in drivers/sound/s3c2410-uda1341.c */

#if (FCLK == 112800000)
#define  AUDIO_CODEC_CLOCK 256
#else
#define  AUDIO_CODEC_CLOCK 384
#endif



// I/O PORT 
#define rGPACON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x00)) //Port A control
#define rGPADAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x04)) //Port A data
                        
#define rGPBCON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x10)) //Port B control
#define rGPBDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x14)) //Port B data
#define rGPBUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x18)) //Pull-up control B
                        
#define rGPCCON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x20)) //Port C control
#define rGPCDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x24)) //Port C data
#define rGPCUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x28)) //Pull-up control C
                        
#define rGPDCON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x30)) //Port D control
#define rGPDDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x34)) //Port D data
#define rGPDUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x38)) //Pull-up control D
                        
#define rGPECON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x40)) //Port E control
#define rGPEDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x44)) //Port E data
#define rGPEUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x48)) //Pull-up control E
                        
#define rGPFCON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x50)) //Port F control
#define rGPFDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x54)) //Port F data
#define rGPFUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x58)) //Pull-up control F
                        
#define rGPGCON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x60)) //Port G control
#define rGPGDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x64)) //Port G data
#define rGPGUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x68)) //Pull-up control G
                        
#define rGPHCON    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x70)) //Port H control
#define rGPHDAT    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x74)) //Port H data
#define rGPHUP     (*(volatile unsigned *)(VA_IO_PORT_BASE+0x78)) //Pull-up control H
                        
#define rMISCCR    (*(volatile unsigned *)(VA_IO_PORT_BASE+0x80)) //Miscellaneous control
#define rDCLKCON   (*(volatile unsigned *)(VA_IO_PORT_BASE+0x84)) //DCLK0/1 control
#define rEXTINT0   (*(volatile unsigned *)(VA_IO_PORT_BASE+0x88)) //External interrupt control register 0
#define rEXTINT1   (*(volatile unsigned *)(VA_IO_PORT_BASE+0x8c)) //External interrupt control register 1
#define rEXTINT2   (*(volatile unsigned *)(VA_IO_PORT_BASE+0x90)) //External interrupt control register 2
#define rEINTFLT0  (*(volatile unsigned *)(VA_IO_PORT_BASE+0x94)) //Reserved
#define rEINTFLT1  (*(volatile unsigned *)(VA_IO_PORT_BASE+0x98)) //Reserved
#define rEINTFLT2  (*(volatile unsigned *)(VA_IO_PORT_BASE+0x9c)) //External interrupt filter control register 2
#define rEINTFLT3  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xa0)) //External interrupt filter control register 3
#define rEINTMSK  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xa4)) //External interrupt mask
#define rEINTPND  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xa8)) //External interrupt pending
#define rGSTATUS0  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xac)) //External pin status
#define rGSTATUS1  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xb0)) //Chip ID(0x32410000)
#define rGSTATUS2  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xb4)) //Reset type
#define rGSTATUS3  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xb8)) //Saved data0(32-bit) before entering POWER_OFF mode 
#define rGSTATUS4  (*(volatile unsigned *)(VA_IO_PORT_BASE+0xbc)) //Saved data0(32-bit) before entering POWER_OFF mode 


// RTC
#ifdef __BIG_ENDIAN
#define rRTCCON    (*(volatile unsigned char *)(VA_RTC_BASE+0x43)) //RTC control
#define rTICNT     (*(volatile unsigned char *)(VA_RTC_BASE+0x47)) //Tick time count
#define rRTCALM    (*(volatile unsigned char *)(VA_RTC_BASE+0x53)) //RTC alarm control
#define rALMSEC    (*(volatile unsigned char *)(VA_RTC_BASE+0x57)) //Alarm second
#define rALMMIN    (*(volatile unsigned char *)(VA_RTC_BASE+0x5b)) //Alarm minute
#define rALMHOUR   (*(volatile unsigned char *)(VA_RTC_BASE+0x5f)) //Alarm Hour
#define rALMDAY    (*(volatile unsigned char *)(VA_RTC_BASE+0x63)) //Alarm day
#define rALMMON    (*(volatile unsigned char *)(VA_RTC_BASE+0x67)) //Alarm month
#define rALMYEAR   (*(volatile unsigned char *)(VA_RTC_BASE+0x6b)) //Alarm year
#define rRTCRST    (*(volatile unsigned char *)(VA_RTC_BASE+0x6f)) //RTC round reset
#define rBCDSEC    (*(volatile unsigned char *)(VA_RTC_BASE+0x73)) //BCD second
#define rBCDMIN    (*(volatile unsigned char *)(VA_RTC_BASE+0x77)) //BCD minute
#define rBCDHOUR   (*(volatile unsigned char *)(VA_RTC_BASE+0x7b)) //BCD hour
#define rBCDDAY    (*(volatile unsigned char *)(VA_RTC_BASE+0x7f)) //BCD day
#define rBCDDATE   (*(volatile unsigned char *)(VA_RTC_BASE+0x83)) //BCD date
#define rBCDMON    (*(volatile unsigned char *)(VA_RTC_BASE+0x87)) //BCD month
#define rBCDYEAR   (*(volatile unsigned char *)(VA_RTC_BASE+0x8b)) //BCD year

#else //Little Endian
#define rRTCCON    (*(volatile unsigned char *)(VA_RTC_BASE+0x40)) //RTC control
#define rTICNT     (*(volatile unsigned char *)(VA_RTC_BASE+0x44)) //Tick time count
#define rRTCALM    (*(volatile unsigned char *)(VA_RTC_BASE+0x50)) //RTC alarm control
#define rALMSEC    (*(volatile unsigned char *)(VA_RTC_BASE+0x54)) //Alarm second
#define rALMMIN    (*(volatile unsigned char *)(VA_RTC_BASE+0x58)) //Alarm minute
#define rALMHOUR   (*(volatile unsigned char *)(VA_RTC_BASE+0x5c)) //Alarm Hour
#define rALMDATE   (*(volatile unsigned char *)(VA_RTC_BASE+0x60)) //Alarm date
#define rALMMON    (*(volatile unsigned char *)(VA_RTC_BASE+0x64)) //Alarm month
#define rALMYEAR   (*(volatile unsigned char *)(VA_RTC_BASE+0x68)) //Alarm year
#define rRTCRST    (*(volatile unsigned char *)(VA_RTC_BASE+0x6c)) //RTC round reset
#define rBCDSEC    (*(volatile unsigned char *)(VA_RTC_BASE+0x70)) //BCD second
#define rBCDMIN    (*(volatile unsigned char *)(VA_RTC_BASE+0x74)) //BCD minute
#define rBCDHOUR   (*(volatile unsigned char *)(VA_RTC_BASE+0x78)) //BCD hour

#define rBCDDATE   (*(volatile unsigned char *)(VA_RTC_BASE+0x7c)) //BCD date
#define rBCDDAY    (*(volatile unsigned char *)(VA_RTC_BASE+0x80)) //BCD day

#define rBCDMON    (*(volatile unsigned char *)(VA_RTC_BASE+0x84)) //BCD month
#define rBCDYEAR   (*(volatile unsigned char *)(VA_RTC_BASE+0x88)) //BCD year
#endif  //RTC


// ADC
#define rADCCON    (*(volatile unsigned *)(VA_ADC_BASE+0x00)) //ADC control
#define rADCTSC    (*(volatile unsigned *)(VA_ADC_BASE+0x04)) //ADC touch screen control
#define rADCDLY    (*(volatile unsigned *)(VA_ADC_BASE+0x08)) //ADC start or Interval Delay
#define rADCDAT0   (*(volatile unsigned *)(VA_ADC_BASE+0x0c)) //ADC conversion data 0
#define rADCDAT1   (*(volatile unsigned *)(VA_ADC_BASE+0x10)) //ADC conversion data 1                   

#define ADCPRS 49               /* used s3c2410_ts.c */
#define ADC_DELAY_TIME    20000 /* used s3c2410_ts.c */
                                                        
// SPI          
#define rSPCON0    (*(volatile unsigned *)(VA_SPI_BASE+0x00)) //SPI0 control
#define rSPSTA0    (*(volatile unsigned *)(VA_SPI_BASE+0x04)) //SPI0 status
#define rSPPIN0    (*(volatile unsigned *)(VA_SPI_BASE+0x08)) //SPI0 pin control
#define rSPPRE0    (*(volatile unsigned *)(VA_SPI_BASE+0x0c)) //SPI0 baud rate prescaler
#define rSPTDAT0   (*(volatile unsigned *)(VA_SPI_BASE+0x10)) //SPI0 Tx data
#define rSPRDAT0   (*(volatile unsigned *)(VA_SPI_BASE+0x14)) //SPI0 Rx data

#define rSPCON1    (*(volatile unsigned *)(VA_SPI_BASE+0x20)) //SPI1 control
#define rSPSTA1    (*(volatile unsigned *)(VA_SPI_BASE+0x24)) //SPI1 status
#define rSPPIN1    (*(volatile unsigned *)(VA_SPI_BASE+0x28)) //SPI1 pin control
#define rSPPRE1    (*(volatile unsigned *)(VA_SPI_BASE+0x2c)) //SPI1 baud rate prescaler
#define rSPTDAT1   (*(volatile unsigned *)(VA_SPI_BASE+0x30)) //SPI1 Tx data
#define rSPRDAT1   (*(volatile unsigned *)(VA_SPI_BASE+0x34)) //SPI1 Rx data


// SD Interface
#define rSDICON     (*(volatile unsigned *)(VA_SD_BASE+0x00)) //SDI control
#define rSDIPRE     (*(volatile unsigned *)(VA_SD_BASE+0x04)) //SDI baud rate prescaler
#define rSDICARG    (*(volatile unsigned *)(VA_SD_BASE+0x08)) //SDI command argument
#define rSDICCON    (*(volatile unsigned *)(VA_SD_BASE+0x0c)) //SDI command control
#define rSDICSTA    (*(volatile unsigned *)(VA_SD_BASE+0x10)) //SDI command status
#define rSDIRSP0    (*(volatile unsigned *)(VA_SD_BASE+0x14)) //SDI response 0
#define rSDIRSP1    (*(volatile unsigned *)(VA_SD_BASE+0x18)) //SDI response 1
#define rSDIRSP2    (*(volatile unsigned *)(VA_SD_BASE+0x1c)) //SDI response 2
#define rSDIRSP3    (*(volatile unsigned *)(VA_SD_BASE+0x20)) //SDI response 3
#define rSDIDTIMER  (*(volatile unsigned *)(VA_SD_BASE+0x24)) //SDI data/busy timer
#define rSDIBSIZE   (*(volatile unsigned *)(VA_SD_BASE+0x28)) //SDI block size
#define rSDIDCON    (*(volatile unsigned *)(VA_SD_BASE+0x2c)) //SDI data control
#define rSDIDCNT    (*(volatile unsigned *)(VA_SD_BASE+0x30)) //SDI data remain counter
#define rSDIDSTA    (*(volatile unsigned *)(VA_SD_BASE+0x34)) //SDI data status
#define rSDIFSTA    (*(volatile unsigned *)(VA_SD_BASE+0x38)) //SDI FIFO status
#define rSDIIMSK    (*(volatile unsigned *)(VA_SD_BASE+0x40)) //SDI interrupt mask

#ifdef __BIG_ENDIAN
#define rSDIDAT    (*(volatile unsigned *)(VA_SD_BASE+0x3f)) //SDI data
			    //#define SDIDAT     (VA_SD_BASE+0x3f)
#else  // Little Endian
#define rSDIDAT    (*(volatile unsigned *)(VA_SD_BASE+0x3c)) //SDI data
		    //#define SDIDAT     (VA_SD_BASE+0x3c )
#endif   //SD Interface
             

// PENDING BIT
#define BIT_EINT0      (0x1)
#define BIT_EINT1      (0x1<<1)
#define BIT_EINT2      (0x1<<2)
#define BIT_EINT3      (0x1<<3)
#define BIT_EINT4_7    (0x1<<4)
#define BIT_EINT8_23   (0x1<<5)
#define BIT_NOTUSED6   (0x1<<6)
#define BIT_BAT_FLT    (0x1<<7)
#define BIT_TICK       (0x1<<8)
#define BIT_WDT        (0x1<<9)
#define BIT_TIMER0     (0x1<<10)
#define BIT_TIMER1     (0x1<<11)
#define BIT_TIMER2     (0x1<<12)
#define BIT_TIMER3     (0x1<<13)
#define BIT_TIMER4     (0x1<<14)
#define BIT_UART2      (0x1<<15)
#define BIT_LCD        (0x1<<16)
#define BIT_DMA0       (0x1<<17)
#define BIT_DMA1       (0x1<<18)
#define BIT_DMA2       (0x1<<19)
#define BIT_DMA3       (0x1<<20)
#define BIT_SDI        (0x1<<21)
#define BIT_SPI0       (0x1<<22)
#define BIT_UART1      (0x1<<23)
#define BIT_NOTUSED24  (0x1<<24)
#define BIT_USBD       (0x1<<25)
#define BIT_USBH       (0x1<<26)
#define BIT_IIC        (0x1<<27)
#define BIT_UART0      (0x1<<28)
#define BIT_SPI1       (0x1<<29)
#define BIT_RTC        (0x1<<30)
#define BIT_ADC        (0x1<<31)
#define BIT_ALLMSK     (0xffffffff)

#define BIT_SUB_ALLMSK (0x7ff)
#define BIT_SUB_ADC    (0x1<<10)
#define BIT_SUB_TC     (0x1<<9)
#define BIT_SUB_ERR2   (0x1<<8)
#define BIT_SUB_TXD2   (0x1<<7)
#define BIT_SUB_RXD2   (0x1<<6)
#define BIT_SUB_ERR1   (0x1<<5)
#define BIT_SUB_TXD1   (0x1<<4)
#define BIT_SUB_RXD1   (0x1<<3)
#define BIT_SUB_ERR0   (0x1<<2)
#define BIT_SUB_TXD0   (0x1<<1)
#define BIT_SUB_RXD0   (0x1<<0)

#define ClearPending(bit) {\
                rSRCPND = bit;\
                rINTPND = bit;\
                rINTPND;\
                }       




/* keyword : SER_BAUD */

#define SER_BAUD_9600    9600 
#define SER_BAUD_14400   11400
#define SER_BAUD_19200   19200
#define SER_BAUD_38400   38400
#define SER_BAUD_57600   57600
#define SER_BAUD_115200  115200
#define CURRENT_BAUD_RATE  SER_BAUD_115200 
/*  Used in serial_s3c2410.c ,uncompress.h */

/**** Choose one among three ****/
#define CURRENT_SERIALUART0 0
//#define CURRENT_SERIALUART1 1
//#define CURRENT_SERIALUART2 2
/********************************/

/*** if you want to change UART , Change the below value ****/
#define CUR_UART_STATUS_OFFSET 0x10               /* UART 0 */
				/* Used in debug-armv.S */
#define CUR_UART_UTXH_OFFSET 0x20               /* UART 0 */
				/* Used in debug-armv.S */
/*************************************************************/


#endif /* __S3C2410_H */
