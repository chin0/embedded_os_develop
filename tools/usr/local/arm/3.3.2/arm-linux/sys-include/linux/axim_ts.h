/*
*
* Driver for the Axim X5 Touch Screen and other Atmel controlled devices.
*
* Copyright 2003 Martin Demin
*
* Use consistent with the GNU GPL is permitted,
* provided that this copyright notice is
* preserved in its entirety in all copies and derived works.
*
*
*
*/


#ifndef __AXIM_TS_H__
#define __AXIM_TS_H__

/*#include <linux/ioctl.h>
#include <linux/h3600_keyboard.h>
*/
enum h3600_ts_minor_devices {
	TS_MINOR    = 0,
	TSRAW_MINOR = 1,
	KEY_MINOR   = 2
};

typedef struct h3600_ts_calibration {
        int xscale;
        int xtrans;
        int yscale;
        int ytrans;
        int xyswap;
} TS_CAL;

typedef struct h3600_ts_event {
        unsigned short pressure;
        unsigned short x;
        unsigned short y;
        unsigned short pad;
} TS_EVENT;

/* Deprecated - do not use */
typedef struct h3600_ts_return {
        unsigned short pressure;
        unsigned short x;
        unsigned short y;
        unsigned short pad;
} TS_RET;

enum power_button_mode {
   PBM_SUSPEND           = 0,
   PBM_GENERATE_KEYPRESS = 1
};


/* ++++++++++++++ +++++++++++++++++++++++++++++++++++++ */

typedef struct therm_dev {
	short data;
} THERM_DEV;

#define H3600_BATT_CHEM_ALKALINE        0x01
#define H3600_BATT_CHEM_NICD            0x02
#define H3600_BATT_CHEM_NIMH            0x03
#define H3600_BATT_CHEM_LION            0x04
#define H3600_BATT_CHEM_LIPOLY          0x05
#define H3600_BATT_CHEM_NOT_INSTALLED   0x06
#define H3600_BATT_CHEM_UNKNOWN         0xff

/* These should match the apm_bios.h definitions */
#define H3600_AC_STATUS_AC_OFFLINE	0x00
#define H3600_AC_STATUS_AC_ONLINE	0x01
#define H3600_AC_STATUS_AC_BACKUP	0x02   /* What does this mean? */
#define H3600_AC_STATUS_AC_UNKNOWN	0xff

/* These bitfields are rarely "or'd" together */
#define H3600_BATT_STATUS_HIGH		0x01
#define H3600_BATT_STATUS_LOW		0x02
#define H3600_BATT_STATUS_CRITICAL	0x04
#define H3600_BATT_STATUS_CHARGING	0x08
#define H3600_BATT_STATUS_CHARGE_MAIN   0x10
#define H3600_BATT_STATUS_DEAD          0x20   /* Battery will not charge */
#define H3600_BATT_NOT_INSTALLED        0x20   /* For expansion pack batteries */
#define H3600_BATT_STATUS_FULL          0x40   /* Battery fully charged (and connected to AC) */
#define H3600_BATT_STATUS_NOBATT	0x80
#define H3600_BATT_STATUS_UNKNOWN	0xff

struct battery_data {
	unsigned char  chemistry;
	unsigned char  status;
	unsigned short voltage;    /* Voltage for battery #0; unknown for battery #1 */
	unsigned short percentage; /* Percentage of full charge */
	unsigned short life;       /* Life remaining in minutes */
};

struct h3600_battery {
        unsigned char       ac_status;
	unsigned char       battery_count;  /* How many batteries we have */
	struct battery_data battery[2];
};

int axim_get_battery( struct h3600_battery* );

/* -------- EEPROM and SPI Interfaces ---------------*/

#define EEPROM_RD_BUFSIZ 6	/* EEPROM reads are 16 bits */
#define EEPROM_WR_BUFSIZ 5	/* Allow room for 8bit 'addr' field in buffer*/ 
#define SPI_RD_BUFSIZ	 16	/* SPI reads are 8 bits */
#define SPI_WR_BUFSIZ	 7

/* The EEPROM is where internal programs are stored on the Amtel.
   You probably don't want to read or write these values */

typedef struct h3600_eeprom_read_request {
	unsigned char addr;    /* 8bit Address Offset 0-255 */
	unsigned char len;     /* Number of 16bit words to read 0-128  */
	unsigned short buff[EEPROM_RD_BUFSIZ];
} EEPROM_READ;

typedef struct h3600_eeprom_write_request {
	unsigned char len;	/* used only to compute the number of bytes to send */
	unsigned char addr;    /* 0-128  */
	unsigned short buff[EEPROM_WR_BUFSIZ];
} EEPROM_WRITE;

/* The SPI bus connects to EEPROMs located on sleeves plugged into
   the iPAQ.  You may want to read these values  */

typedef struct h3600_spi_read_request {
	unsigned short addr;    /* 16bit Address Offset 0-128 */
	unsigned char len;      /* Number of bytes to read */
	unsigned char buff[SPI_RD_BUFSIZ];
} SPI_READ;

#define SPI_READ_STATUS_BYTE  0xffff   /* Use this address to read the status byte */

typedef struct h3600_spi_write_request {
	unsigned short len;	/* used only to compute the number of bytes to send */
	unsigned short addr;	/* this 16bit address accesses a single byte */
	unsigned char  buff[SPI_WR_BUFSIZ];
} SPI_WRITE;


/* -------- end of EEPROM and SPI Interfaces ---------------*/

/* User space structures for IOCTL calls */

typedef struct h3600_ts_version {
	unsigned char host_version[8];	/* ascii "x.yy" */
	unsigned char pack_version[8];	/* ascii "x.yy" */
	unsigned char boot_type;		/* TODO ?? */
} VER_RET;

typedef struct h3600_ts_led {
        unsigned char OffOnBlink;       /* 0=off 1=on 2=Blink */
        unsigned char TotalTime;        /* Units of 5 seconds */
        unsigned char OnTime;           /* units of 100m/s */
        unsigned char OffTime;          /* units of 100m/s */
} LED_IN;

enum flite_mode {
        FLITE_MODE1 = 1,
	FLITE_AUTO_MODE   = 1,     /* for reference only */
	FLITE_MANUAL_MODE = 2,     /* Use this normally? */
	FLITE_GET_LIGHT_SENSOR = 3 /* Returns light reading in "brightness" field */
};
enum flite_pwr {
        FLITE_PWR_OFF = 0,
        FLITE_PWR_ON  = 1
};

typedef struct h3600_ts_flite {
        unsigned char mode;
        unsigned char pwr;
        unsigned char brightness;
} FLITE_IN;

/*************************** Updated "universal" structures *******************/

/* Sets backlight for both H3100 and H3600 models - technically "frontlight" for H3600 */
struct axim_ts_backlight {
	enum flite_pwr power;          /* 0 = off, 1 = on */
	unsigned char  brightness;     /* 0 - 255         */
};

struct h3600_ts_contrast {            /* Only useful on H3100 model */
	unsigned char contrast;       /* 0 - 255 */
};

/* IOCTL cmds  user or kernel space */

/* Use 'f' as magic number */
#define IOC_H3600_TS_MAGIC  'f'

/* TODO: Some of these IOWR values are just plain wrong */
#define GET_VERSION		_IOR(IOC_H3600_TS_MAGIC,  1, struct h3600_ts_version )
#define READ_EEPROM		_IOWR(IOC_H3600_TS_MAGIC, 2, struct h3600_eeprom_read_request)
#define WRITE_EEPROM		_IOWR(IOC_H3600_TS_MAGIC, 3, struct h3600_eeprom_write_request)
#define GET_THERMAL		_IOR(IOC_H3600_TS_MAGIC,  4, struct therm_dev)
#define LED_ON			_IOW(IOC_H3600_TS_MAGIC,  5, struct h3600_ts_led)
#define GET_BATTERY_STATUS	_IOR(IOC_H3600_TS_MAGIC,  6, struct h3600_battery)
#define FLITE_ON		_IOW(IOC_H3600_TS_MAGIC,  7, struct h3600_ts_flite)
#define READ_SPI		_IOWR(IOC_H3600_TS_MAGIC, 8, struct h3600_spi_read_request)
#define WRITE_SPI		_IOWR(IOC_H3600_TS_MAGIC, 9, struct h3600_spi_write_request)
#define TS_GET_CAL		_IOR(IOC_H3600_TS_MAGIC, 10, struct h3600_ts_calibration)
#define TS_SET_CAL		_IOW(IOC_H3600_TS_MAGIC, 11, struct h3600_ts_calibration)

/* New IOCTL interfaces - defined to be more user friendly */
#define TS_GET_BACKLIGHT        _IOR(IOC_H3600_TS_MAGIC, 20, struct axim_ts_backlight)
#define TS_SET_BACKLIGHT        _IOW(IOC_H3600_TS_MAGIC, 20, struct axim_ts_backlight)
#define TS_GET_CONTRAST         _IOR(IOC_H3600_TS_MAGIC, 21, struct h3600_ts_contrast)
#define TS_SET_CONTRAST         _IOW(IOC_H3600_TS_MAGIC, 21, struct h3600_ts_contrast)

#endif
