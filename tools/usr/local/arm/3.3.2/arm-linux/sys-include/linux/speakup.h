#ifndef __SPEAKUP_H
#define __SPEAKUP_H

/*
 *	Public interfaces for voice console services from "speakup"
 */
 
#ifdef CONFIG_SPEAKUP
extern struct spk_t *speakup_console[];
extern void speakup_allocate(int);
extern void speakup_bs(int);
extern void speakup_con_write(int, const char *, int);
extern void speakup_con_update(int);
extern void speakup_init(int);
extern void speakup_reset(int, unsigned char);
extern void speakup_control(int, struct kbd_struct *, int);
extern int speakup_diacr(unsigned char,unsigned int);
extern void speakup_savekey(unsigned char);
extern void do_spkup(unsigned char value,  char up_flag) {};
#else
/*
 *	NULL when not configured
 */
static inline void speakup_allocate(int currcons) {};
static inline void speakup_bs(int currcons) {};
static inline void speakup_con_write(int currcons, const char *str, int len) {};
static inline void speakup_con_update(int currcons) {};
static inline void speakup_init(int currcons) {};
static inline void speakup_reset(int fg_console, unsigned char type) {};
static inline void speakup_control(int fg_console, struct kbd_struct * kbd, int value) {};
static inline int speakup_diacr(unsigned char ch, unsigned int fg_console) {return 0;};
static inline void speakup_savekey(unsigned char ch) {};
#define do_spkup(a,b) do {} while(0);
#endif
#endif

