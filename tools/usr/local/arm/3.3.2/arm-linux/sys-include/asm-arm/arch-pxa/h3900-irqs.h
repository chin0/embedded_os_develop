#ifndef _IRQS_H3900_H_
#define _IRQS_H3900_H_

#if defined(CONFIG_ARCH_H3900)

/* H3800-specific IRQs (CONFIG_SA1100_H3800) */
#define H3800_KPIO_IRQ_START    (IRQ_BOARD_START)
#define IRQ_H3800_KEY           (IRQ_BOARD_START + 0)
#define IRQ_H3800_SPI           (IRQ_BOARD_START + 1)
#define IRQ_H3800_OWM           (IRQ_BOARD_START + 2)
#define IRQ_H3800_ADC           (IRQ_BOARD_START + 3)
#define IRQ_H3800_UART_0        (IRQ_BOARD_START + 4)
#define IRQ_H3800_UART_1        (IRQ_BOARD_START + 5)
#define IRQ_H3800_TIMER_0       (IRQ_BOARD_START + 6)
#define IRQ_H3800_TIMER_1       (IRQ_BOARD_START + 7)
#define IRQ_H3800_TIMER_2       (IRQ_BOARD_START + 8)
#define H3800_KPIO_IRQ_COUNT    9

#define H3800_GPIO_IRQ_START    (IRQ_BOARD_START + 9)
#define IRQ_H3800_PEN           (IRQ_BOARD_START + 9)
#define IRQ_H3800_SD_DETECT     (IRQ_BOARD_START + 10)
#define IRQ_H3800_EAR_IN        (IRQ_BOARD_START + 11)
#define IRQ_H3800_USB_DETECT    (IRQ_BOARD_START + 12)
#define IRQ_H3800_SD_CON_SLT    (IRQ_BOARD_START + 13)
#define H3800_GPIO_IRQ_COUNT    5

#if H3800_IRQ_COUNT > (IRQ_BOARD_END - IRQ_BOARD_START)
#error need to increase number of board IRQs
#endif

#endif /* CONFIG_ARCH_H3900 */

#endif /* _IRQS_H3900_H_ */
