/*
 *  linux/include/asm-arm/arch-s3c2410/uncompress.h
 *
 *  Copyright (C) 2002 SAMSUNG ELECTORNICS 
 *                         SW.LEE (hitchcar@sec.samsung.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */


#include <asm/arch/s3c2410.h>
#undef  VA_IO_PORT_BASE
#define VA_IO_PORT_BASE PA_IO_PORT_BASE
#undef  VA_UART_BASE    
#define VA_UART_BASE    PA_UART_BASE


/*** 
 *  Data  : 8 4 2 1
 */
static void Led_Display(int data)
{
	rGPFDAT = (0xf<<4);
	rGPFDAT = ((~data & 0xf)<<4);
}

static void Uart_SendByte(int data) 
{ 
        if(data=='\n') 
        { 
            while(!(rUTRSTAT0 & 0x2)); 
	    /*            Delay(10);*/
	    /*because the slow response of hyper_terminal  */
            WrUTXH0('\r'); 
        } 
        while(!(rUTRSTAT0 & 0x2));   /*Wait until THR is empty. */
	/*        Delay(10); */
        WrUTXH0(data); 
}                

static void puts(const char *s)
{
	int index =0;
	while(*(s+index)) 
		Uart_SendByte(*(s+ index++)); 
}


static void Uart_Init(int pclk,int baud) 
{ 
	int i; 

	rUFCON0 = 0x0;   //UART channel 0 FIFO control register, FIFO disable 
	rUFCON1 = 0x0;   //UART channel 1 FIFO control register, FIFO disable 
	rUFCON2 = 0x0;   //UART channel 2 FIFO control register, FIFO disable 

	rUMCON0 = 0x0;   //UART chaneel 0 MODEM control register, AFC disable 
	rUMCON1 = 0x0;   //UART chaneel 1 MODEM control register, AFC disable 

	rULCON0 = 0x3;

	// [10]       [9]     [8]        [7]        [6]      [5]
	//         [4]           [3:2]        [1:0] 
	// Clock Sel, Tx Int, Rx Int, Rx Time Out, Rx err, Loop-back, 
	//      Send break,  Transmit Mode, Receive Mode
	//  0          1       0    ,     0          1        0  
	//         0     ,       01          01 
	//   PCLK       Level    Pulse    Disable    Generate  Normal 
	//      Normal       Interrupt or Polling 

	rUCON0  = 0x245;                        // Control register 
	rUBRDIV0=( (int)(pclk/16/baud) -1 );   //Baud rate divisior register 0 
	for(i=0;i<100;i++); 

	rULCON1  = 0x3;
	rUCON1  = 0x245;                        // Control register 
	rUBRDIV1=( (int)(pclk/16/baud) -1 );   //Baud rate divisior register 0 
	for(i=0;i<100;i++); 

	rULCON2  = 0x3;
	rUCON2  = 0x245;                        // Control register 
	rUBRDIV2=( (int)(pclk/16/baud) -1 );   //Baud rate divisior register 0 
	for(i=0;i<100;i++); 



} 

/* If you want to change clock , you must check head-s3c2410.S 
 *
 * FCLK 203Mhze in this case
 * And uart 0 
 */
static void Port_Init(void);
static void arch_decomp_setup()
{
	int i ;
	Port_Init();
	//   Led_Display(4);
	Uart_Init(PCLK,CURRENT_BAUD_RATE);
}

#define arch_decomp_wdog()

/***********   [ PORTS ]     ******************************
 * CHECK asm/arch-s3c2410/irq.c
 *
 */
static void Port_Init(void)
{
	//CAUTION:Follow the configuration order for setting the ports. 
	// 1) setting value(GPnDAT) 
	// 2) setting control register  (GPnCON)
	// 3) configure pull-up resistor(GPnUP)  

	//32bit data bus configuration  
	//*** PORT A GROUP
	//Ports  : GPA22 GPA21  GPA20 GPA19 GPA18 GPA17 GPA16 GPA15 GPA14 GPA13 GPA12  
	//Signal : nFCE nRSTOUT nFRE   nFWE  ALE   CLE  nGCS5 nGCS4 nGCS3 nGCS2 nGCS1 
	//Binary :  1     1      1  , 1   1   1    1   ,  1     1     1     1
	//Ports  : GPA11   GPA10  GPA9   GPA8   GPA7   GPA6   GPA5   GPA4   GPA3   GPA2   GPA1  GPA0
	//Signal : ADDR26 ADDR25 ADDR24 ADDR23 ADDR22 ADDR21 ADDR20 ADDR19 ADDR18 ADDR17 ADDR16 ADDR0 
	//Binary :  1       1      1      1   , 1       1      1      1   ,  1       1     1      1         
	rGPACON = 0x7fffff; 

	//**** PORT B GROUP
	//Ports  : GPB10    GPB9    GPB8    GPB7    GPB6     GPB5    GPB4   GPB3   GPB2     GPB1      GPB0
	//Signal : nXDREQ0 nXDACK0 nXDREQ1 nXDACK1 nSS_KBD nDIS_OFF L3CLOCK L3DATA L3MODE nIrDATXDEN Keyboard
	//Setting: INPUT  OUTPUT   INPUT  OUTPUT   INPUT   OUTPUT   OUTPUT OUTPUT OUTPUT   OUTPUT    OUTPUT 
	//Binary :   00  ,  01       00  ,   01      00   ,  01       01  ,   01     01   ,  01        01  
	rGPBCON = 0x044555;
	rGPBUP  = 0x7ff;     // The pull up function is disabled GPB[10:0]

	//*** PORT C GROUP
	//Ports  : GPC15 GPC14 GPC13 GPC12 GPC11 GPC10 GPC9 GPC8  GPC7   GPC6   GPC5 GPC4 GPC3  GPC2  GPC1 GPC0
	//Signal : VD7   VD6   VD5   VD4   VD3   VD2   VD1  VD0 LCDVF2 LCDVF1 LCDVF0 VM VFRAME VLINE VCLK LEND  
	//Binary :  10   10  , 10    10  , 10    10  , 10   10  , 10     10  ,  10   10 , 10     10 , 10   10
	rGPCCON = 0xaaaaaaaa;       
	rGPCUP  = 0xffff;     // The pull up function is disabled GPC[15:0] 

	//*** PORT D GROUP
	//Ports  : GPD15 GPD14 GPD13 GPD12 GPD11 GPD10 GPD9 GPD8 GPD7 GPD6 GPD5 GPD4 GPD3 GPD2 GPD1 GPD0
	//Signal : VD23  VD22  VD21  VD20  VD19  VD18  VD17 VD16 VD15 VD14 VD13 VD12 VD11 VD10 VD9  VD8
	//Binary : 10    10  , 10    10  , 10    10  , 10   10 , 10   10 , 10   10 , 10   10 ,10   10
	rGPDCON = 0xaaaaaaaa;       
	rGPDUP  = 0xffff;     // The pull up function is disabled GPD[15:0]

	//*** PORT E GROUP
	//Ports  : GPE15  GPE14 GPE13   GPE12   GPE11   GPE10   GPE9    GPE8     GPE7  GPE6  GPE5   GPE4  
	//Signal : IICSDA IICSCL SPICLK SPIMOSI SPIMISO SDDATA3 SDDATA2 SDDATA1 SDDATA0 SDCMD SDCLK I2SSDO 
	//Binary :  10     10  ,  10      10  ,  10      10   ,  10      10   ,   10    10  , 10     10  ,     
	//-------------------------------------------------------------------------------------------------------
	//Ports  :  GPE3   GPE2  GPE1    GPE0    
	//Signal : I2SSDI CDCLK I2SSCLK I2SLRCK     
	//Binary :  10     10  ,  10      10 
	rGPECON = 0xaaaaaaaa;       
	rGPEUP  = 0xffff;     // The pull up function is disabled GPE[15:0]

	//*** PORT F GROUP
	//Ports  : GPF7   GPF6   GPF5   GPF4      GPF3     GPF2  GPF1   GPF0
	//Signal : nLED_8 nLED_4 nLED_2 nLED_1 nIRQ_PCMCIA EINT2 KBDINT EINT0
	//Setting: Output Output Output Output    EINT3    EINT2 EINT1  EINT0
	//Binary :  01      01 ,  01     01  ,     10       10  , 10     10
	rGPFCON = 0x55aa;
	rGPFUP  = 0xff;     // The pull up function is disabled GPF[7:0]

	//*** PORT G GROUP
	//Ports  : GPG15 GPG14 GPG13 GPG12 GPG11    GPG10    GPG9     GPG8     GPG7      GPG6    
	//Signal : nYPON  YMON nXPON XMON  EINT19 DMAMODE1 DMAMODE0 DMASTART KBDSPICLK KBDSPIMOSI
	//Setting: nYPON  YMON nXPON XMON  EINT19  Output   Output   Output   SPICLK1    SPIMOSI1
	//Binary :   11    11 , 11    11  , 10      01    ,   01       01   ,    11         11
	//-----------------------------------------------------------------------------------------
	//Ports  :    GPG5       GPG4    GPG3    GPG2    GPG1    GPG0    
	//Signal : KBDSPIMISO LCD_PWREN EINT11 nSS_SPI IRQ_LAN IRQ_PCMCIA
	//Setting:  SPIMISO1  LCD_PWRDN EINT11   nSS0   EINT9    EINT8
	//Binary :     11         11   ,  10      11  ,  10        10
	rGPGCON = 0xff95ffba;
	rGPGUP  = 0xffff;    // The pull up function is disabled GPG[15:0]

	/* Uart Setting Part */
	//*** PORT H GROUP
	//Ports  :  GPH10    GPH9  GPH8 GPH7  GPH6  GPH5 GPH4 GPH3 GPH2 GPH1  GPH0 
	//Signal : CLKOUT1 CLKOUT0 UCLK nCTS1 nRTS1 RXD1 TXD1 RXD0 TXD0 nRTS0 nCTS0
	//Binary :   10   ,  10     10 , 11    11  , 10   10 , 10   10 , 10    10
	rGPHCON = 0x2afaaa;
	rGPHUP  = 0x7ff;    // The pull up function is disabled GPH[10:0]

	//External interrupt will be falling edge triggered.
	// EINT9 (cs8900A) has the rising edge triggered  
	rEXTINT0 = 0x22222222;    // EINT[7:0]
	rEXTINT1 = 0x22222242;    // EINT[15:8]
	rEXTINT2 = 0x22222222;    // EINT[23:16]
}
