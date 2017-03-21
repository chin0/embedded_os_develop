// ----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
// ----------------------------------------------------------------------------
//  The software is delivered "AS IS" without warranty or condition of any
//  kind, either express, implied or statutory. This includes without
//  limitation any warranty or condition with respect to merchantability or
//  fitness for any particular purpose, or against the infringements of
//  intellectual property rights of others.
// ----------------------------------------------------------------------------
// File Name           : AT91RM9200.h
// Object              : AT91RM9200 definitions
// Generated           : AT91 SW Application Group  12/03/2002 (10:48:03)

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Debug Unit
// *****************************************************************************
// *** Register offset in AT91S_DBGU structure ***
#define DBGU_CR         ( 0) // Control Register
#define DBGU_MR         ( 4) // Mode Register
#define DBGU_IER        ( 8) // Interrupt Enable Register
#define DBGU_IDR        (12) // Interrupt Disable Register
#define DBGU_IMR        (16) // Interrupt Mask Register
#define DBGU_CSR        (20) // Channel Status Register
#define DBGU_RHR        (24) // Receiver Holding Register
#define DBGU_THR        (28) // Transmitter Holding Register
#define DBGU_BRGR       (32) // Baud Rate Generator Register
#define DBGU_C1R        (64) // Chip ID1 Register
#define DBGU_C2R        (68) // Chip ID2 Register
#define DBGU_FNTR       (72) // Force NTRST Register
#define DBGU_RPR        (256) // Receive Pointer Register
#define DBGU_RCR        (260) // Receive Counter Register
#define DBGU_TPR        (264) // Transmit Pointer Register
#define DBGU_TCR        (268) // Transmit Counter Register
#define DBGU_RNPR       (272) // Receive Next Pointer Register
#define DBGU_RNCR       (276) // Receive Next Counter Register
#define DBGU_TNPR       (280) // Transmit Next Pointer Register
#define DBGU_TNCR       (284) // Transmit Next Counter Register
#define DBGU_PTCR       (288) // PDC Transfer Control Register
#define DBGU_PTSR       (292) // PDC Transfer Status Register
// -------- DBGU_CR : (DBGU Offset: 0x0) Debug Unit Control Register --------
#define AT91C_US_RSTRX            (0x1 <<  2) // (DBGU) Reset Receiver
#define AT91C_US_RSTTX            (0x1 <<  3) // (DBGU) Reset Transmitter
#define AT91C_US_RXEN             (0x1 <<  4) // (DBGU) Receiver Enable
#define AT91C_US_RXDIS            (0x1 <<  5) // (DBGU) Receiver Disable
#define AT91C_US_TXEN             (0x1 <<  6) // (DBGU) Transmitter Enable
#define AT91C_US_TXDIS            (0x1 <<  7) // (DBGU) Transmitter Disable
// -------- DBGU_MR : (DBGU Offset: 0x4) Debug Unit Mode Register --------
#define AT91C_US_PAR              (0x7 <<  9) // (DBGU) Parity type
#define 	AT91C_US_PAR_EVEN                 (0x0 <<  9) // (DBGU) Even Parity
#define 	AT91C_US_PAR_ODD                  (0x1 <<  9) // (DBGU) Odd Parity
#define 	AT91C_US_PAR_SPACE                (0x2 <<  9) // (DBGU) Parity forced to 0 (Space)
#define 	AT91C_US_PAR_MARK                 (0x3 <<  9) // (DBGU) Parity forced to 1 (Mark)
#define 	AT91C_US_PAR_NONE                 (0x4 <<  9) // (DBGU) No Parity
#define 	AT91C_US_PAR_MULTI_DROP           (0x6 <<  9) // (DBGU) Multi-drop mode
#define AT91C_US_CHMODE           (0x3 << 14) // (DBGU) Channel Mode
#define 	AT91C_US_CHMODE_NORMAL               (0x0 << 14) // (DBGU) Normal Mode: The USART channel operates as an RX/TX USART.
#define 	AT91C_US_CHMODE_AUTO                 (0x1 << 14) // (DBGU) Automatic Echo: Receiver Data Input is connected to the TXD pin.
#define 	AT91C_US_CHMODE_LOCAL                (0x2 << 14) // (DBGU) Local Loopback: Transmitter Output Signal is connected to Receiver Input Signal.
#define 	AT91C_US_CHMODE_REMOTE               (0x3 << 14) // (DBGU) Remote Loopback: RXD pin is internally connected to TXD pin.
// -------- DBGU_IER : (DBGU Offset: 0x8) Debug Unit Interrupt Enable Register --------
#define AT91C_US_RXRDY            (0x1 <<  0) // (DBGU) RXRDY Interrupt
#define AT91C_US_TXRDY            (0x1 <<  1) // (DBGU) TXRDY Interrupt
#define AT91C_US_ENDRX            (0x1 <<  3) // (DBGU) End of Receive Transfer Interrupt
#define AT91C_US_ENDTX            (0x1 <<  4) // (DBGU) End of Transmit Interrupt
#define AT91C_US_OVRE             (0x1 <<  5) // (DBGU) Overrun Interrupt
#define AT91C_US_FRAME            (0x1 <<  6) // (DBGU) Framing Error Interrupt
#define AT91C_US_PARE             (0x1 <<  7) // (DBGU) Parity Error Interrupt
#define AT91C_US_TXEMPTY          (0x1 <<  9) // (DBGU) TXEMPTY Interrupt
#define AT91C_US_TXBUFE           (0x1 << 11) // (DBGU) TXBUFE Interrupt
#define AT91C_US_RXBUFF           (0x1 << 12) // (DBGU) RXBUFF Interrupt
#define AT91C_US_COMM_TX          (0x1 << 30) // (DBGU) COMM_TX Interrupt
#define AT91C_US_COMM_RX          (0x1 << 31) // (DBGU) COMM_RX Interrupt
// -------- DBGU_IDR : (DBGU Offset: 0xc) Debug Unit Interrupt Disable Register --------
// -------- DBGU_IMR : (DBGU Offset: 0x10) Debug Unit Interrupt Mask Register --------
// -------- DBGU_CSR : (DBGU Offset: 0x14) Debug Unit Channel Status Register --------
// -------- DBGU_FNTR : (DBGU Offset: 0x48) Debug Unit FORCE_NTRST Register --------
#define AT91C_US_FORCE_NTRST      (0x1 <<  0) // (DBGU) Force NTRST in JTAG
// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Advanced Interrupt Controller
// *****************************************************************************
// *** Register offset in AT91S_AIC structure ***
#define AIC_SMR         ( 0) // Source Mode Register
#define AIC_SVR         (128) // Source Vector Register
#define AIC_IVR         (256) // IRQ Vector Register
#define AIC_FVR         (260) // FIQ Vector Register
#define AIC_ISR         (264) // Interrupt Status Register
#define AIC_IPR         (268) // Interrupt Pending Register
#define AIC_IMR         (272) // Interrupt Mask Register
#define AIC_CISR        (276) // Core Interrupt Status Register
#define AIC_IECR        (288) // Interrupt Enable Command Register
#define AIC_IDCR        (292) // Interrupt Disable Command Register
#define AIC_ICCR        (296) // Interrupt Clear Command Register
#define AIC_ISCR        (300) // Interrupt Set Command Register
#define AIC_EOICR       (304) // End of Interrupt Command Register
#define AIC_SPU         (308) // Spurious Vector Register
#define AIC_DCR         (312) // Debug Control Register (Protect)
#define AIC_FFER        (320) // Fast Forcing Enable Register
#define AIC_FFDR        (324) // Fast Forcing Disable Register
#define AIC_FFSR        (328) // Fast Forcing Status Register
// -------- AIC_SMR : (AIC Offset: 0x0) Control Register --------
#define AT91C_AIC_PRIOR           (0x7 <<  0) // (AIC) Priority Level
#define 	AT91C_AIC_PRIOR_LOWEST               (0x0) // (AIC) Lowest priority level
#define 	AT91C_AIC_PRIOR_HIGHEST              (0x7) // (AIC) Highest priority level
#define AT91C_AIC_SRCTYPE         (0x3 <<  5) // (AIC) Interrupt Source Type
#define 	AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE  (0x0 <<  5) // (AIC) Internal Sources Code Label Level Sensitive
#define 	AT91C_AIC_SRCTYPE_INT_EDGE_TRIGGERED   (0x1 <<  5) // (AIC) Internal Sources Code Label Edge triggered
#define 	AT91C_AIC_SRCTYPE_EXT_HIGH_LEVEL       (0x2 <<  5) // (AIC) External Sources Code Label High-level Sensitive
#define 	AT91C_AIC_SRCTYPE_EXT_POSITIVE_EDGE    (0x3 <<  5) // (AIC) External Sources Code Label Positive Edge triggered
// -------- AIC_CISR : (AIC Offset: 0x114) AIC Core Interrupt Status Register --------
#define AT91C_AIC_NFIQ            (0x1 <<  0) // (AIC) NFIQ Status
#define AT91C_AIC_NIRQ            (0x1 <<  1) // (AIC) NIRQ Status
// -------- AIC_DCR : (AIC Offset: 0x138) AIC Debug Control Register (Protect) --------
#define AT91C_AIC_DCR_PROT        (0x1 <<  0) // (AIC) Protection Mode
#define AT91C_AIC_DCR_GMSK        (0x1 <<  1) // (AIC) General Mask

// *****************************************************************************
//               PERIPHERAL ID DEFINITIONS FOR AT91RM9200
// *****************************************************************************
#define AT91C_ID_FIQ              ( 0) // Advanced Interrupt Controller (FIQ)
#define AT91C_ID_SYS              ( 1) // System Peripheral
#define AT91C_ID_PIOA             ( 2) // Parallel IO Controller A
#define AT91C_ID_PIOB             ( 3) // Parallel IO Controller B
#define AT91C_ID_PIOC             ( 4) // Parallel IO Controller C
#define AT91C_ID_PIOD             ( 5) // Parallel IO Controller D
#define AT91C_ID_US0              ( 6) // USART 0
#define AT91C_ID_US1              ( 7) // USART 1
#define AT91C_ID_US2              ( 8) // USART 2
#define AT91C_ID_US3              ( 9) // USART 3
#define AT91C_ID_MCI              (10) // Multimedia Card Interface
#define AT91C_ID_UDP              (11) // USB Device Port
#define AT91C_ID_TWI              (12) // Two-Wire Interface
#define AT91C_ID_SPI              (13) // Serial Peripheral Interface
#define AT91C_ID_SSC0             (14) // Serial Synchronous Controller 0
#define AT91C_ID_SSC1             (15) // Serial Synchronous Controller 1
#define AT91C_ID_SSC2             (16) // Serial Synchronous Controller 2
#define AT91C_ID_TC0              (17) // Timer Counter 0
#define AT91C_ID_TC1              (18) // Timer Counter 1
#define AT91C_ID_TC2              (19) // Timer Counter 2
#define AT91C_ID_TC3              (20) // Timer Counter 3
#define AT91C_ID_TC4              (21) // Timer Counter 4
#define AT91C_ID_TC5              (22) // Timer Counter 5
#define AT91C_ID_UHP              (23) // USB Host port
#define AT91C_ID_EMAC             (24) // Ethernet MAC
#define AT91C_ID_IRQ0             (25) // Advanced Interrupt Controller (IRQ0)
#define AT91C_ID_IRQ1             (26) // Advanced Interrupt Controller (IRQ1)
#define AT91C_ID_IRQ2             (27) // Advanced Interrupt Controller (IRQ2)
#define AT91C_ID_IRQ3             (28) // Advanced Interrupt Controller (IRQ3)
#define AT91C_ID_IRQ4             (29) // Advanced Interrupt Controller (IRQ4)
#define AT91C_ID_IRQ5             (30) // Advanced Interrupt Controller (IRQ5)
#define AT91C_ID_IRQ6             (31) // Advanced Interrupt Controller (IRQ6)

// *****************************************************************************
//               BASE ADDRESS DEFINITIONS FOR AT91RM9200
// *****************************************************************************
#define AT91C_BASE_SYS            (0xFFFFF000) // (SYS) Base Address
#define AT91C_BASE_MC             (0xFFFFFF00) // (MC) Base Address
#define AT91C_BASE_RTC            (0xFFFFFE00) // (RTC) Base Address
#define AT91C_BASE_ST             (0xFFFFFD00) // (ST) Base Address
#define AT91C_BASE_PMC            (0xFFFFFC00) // (PMC) Base Address
#define AT91C_BASE_CKGR           (0xFFFFFC20) // (CKGR) Base Address
#define AT91C_BASE_PIOD           (0xFFFFFA00) // (PIOD) Base Address
#define AT91C_BASE_PIOC           (0xFFFFF800) // (PIOC) Base Address
#define AT91C_BASE_PIOB           (0xFFFFF600) // (PIOB) Base Address
#define AT91C_BASE_PIOA           (0xFFFFF400) // (PIOA) Base Address
#define AT91C_BASE_DBGU           (0xFFFFF200) // (DBGU) Base Address
#define AT91C_BASE_PDC_DBGU       (0xFFFFF300) // (PDC_DBGU) Base Address
#define AT91C_BASE_AIC            (0xFFFFF000) // (AIC) Base Address
#define AT91C_BASE_PDC_SPI        (0xFFFE0100) // (PDC_SPI) Base Address
#define AT91C_BASE_SPI            (0xFFFE0000) // (SPI) Base Address
#define AT91C_BASE_PDC_SSC2       (0xFFFD8100) // (PDC_SSC2) Base Address
#define AT91C_BASE_SSC2           (0xFFFD8000) // (SSC2) Base Address
#define AT91C_BASE_PDC_SSC1       (0xFFFD4100) // (PDC_SSC1) Base Address
#define AT91C_BASE_SSC1           (0xFFFD4000) // (SSC1) Base Address
#define AT91C_BASE_PDC_SSC0       (0xFFFD0100) // (PDC_SSC0) Base Address
#define AT91C_BASE_SSC0           (0xFFFD0000) // (SSC0) Base Address
#define AT91C_BASE_PDC_US3        (0xFFFCC100) // (PDC_US3) Base Address
#define AT91C_BASE_US3            (0xFFFCC000) // (US3) Base Address
#define AT91C_BASE_PDC_US2        (0xFFFC8100) // (PDC_US2) Base Address
#define AT91C_BASE_US2            (0xFFFC8000) // (US2) Base Address
#define AT91C_BASE_PDC_US1        (0xFFFC4100) // (PDC_US1) Base Address
#define AT91C_BASE_US1            (0xFFFC4000) // (US1) Base Address
#define AT91C_BASE_PDC_US0        (0xFFFC0100) // (PDC_US0) Base Address
#define AT91C_BASE_US0            (0xFFFC0000) // (US0) Base Address
#define AT91C_BASE_PDC_TWI        (0xFFFB8100) // (PDC_TWI) Base Address
#define AT91C_BASE_TWI            (0xFFFB8000) // (TWI) Base Address
#define AT91C_BASE_PDC_MCI        (0xFFFB4100) // (PDC_MCI) Base Address
#define AT91C_BASE_MCI            (0xFFFB4000) // (MCI) Base Address
#define AT91C_BASE_UDP            (0xFFFB0000) // (UDP) Base Address
#define AT91C_BASE_TC5            (0xFFFA4080) // (TC5) Base Address
#define AT91C_BASE_TC4            (0xFFFA4040) // (TC4) Base Address
#define AT91C_BASE_TC3            (0xFFFA4000) // (TC3) Base Address
#define AT91C_BASE_TCB1           (0xFFFA4080) // (TCB1) Base Address
#define AT91C_BASE_TC2            (0xFFFA0080) // (TC2) Base Address
#define AT91C_BASE_TC1            (0xFFFA0040) // (TC1) Base Address
#define AT91C_BASE_TC0            (0xFFFA0000) // (TC0) Base Address
#define AT91C_BASE_TCB0           (0xFFFA0000) // (TCB0) Base Address
#define AT91C_BASE_UHP            (0x00300000) // (UHP) Base Address
#define AT91C_BASE_EMAC           (0xFFFBC000) // (EMAC) Base Address
#define AT91C_BASE_EBI            (0xFFFFFF60) // (EBI) Base Address
#define AT91C_BASE_SMC2           (0xFFFFFF70) // (SMC2) Base Address
#define AT91C_BASE_SDRC           (0xFFFFFF90) // (SDRC) Base Address
#define AT91C_BASE_BFC            (0xFFFFFFC0) // (BFC) Base Address

// *****************************************************************************
//               MEMORY MAPPING DEFINITIONS FOR AT91RM9200
// *****************************************************************************
#define AT91C_ISRAM	              (0x00200000) // Internal SRAM base address
#define AT91C_ISRAM_SIZE	         (0x00004000) // Internal SRAM size in byte (16 Kbyte)
#define AT91C_IROM 	              (0x00100000) // Internal ROM base address
#define AT91C_IROM_SIZE	          (0x00020000) // Internal ROM size in byte (128 Kbyte)
