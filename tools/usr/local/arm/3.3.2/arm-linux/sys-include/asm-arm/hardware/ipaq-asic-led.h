#ifndef IPAQ_ASIC_LED_H
#define IPAQ_ASIC_LED_H

#define LEDTBS_MASK            0x0f    /* Low 4 bits sets time base, max = 13 */
#define LEDTBS_BLINK     ( 1 << 4 )    /* Enable blinking */
#define LEDTBS_AUTOSTOP  ( 1 << 5 ) 
#define LEDTBS_ALWAYS    ( 1 << 6 )    /* Enable blink always */

#endif
