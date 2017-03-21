CC = arm-linux-gcc
LD = arm-linux-ld
OC = arm-linux-objcopy

CFLAGS = -nostdinc -I. -I../include
CFLAGS += -Wall -Wstrict-prototypes -Wno-trigraphs -O2
CFLAGS += -fno-strict-aliasing -fno-common -pipe -mapcs-32
CFLAGS += -mcpu=xscale -mshort-load-bytes -msoft-float -fno-builtin

LDFLAGS = -static -nostdlib -nostartfiiles -nodefaultlibs -p -X -T ./main-ld-script

OCFLAGS = -O binary -R .note -R .comment -S

all: chinoOS.c
	$(CC) -c $(CFLAGS) -o entry.o entry.S
	$(CC) -c $(CFLAGS) -o gpio.o gpio.c
	$(CC) -c $(CFLAGS) -o time.o time.c
	$(CC) -c $(CFLAGS) -o vsprintf.o vsprintf.c
	$(CC) -c $(CFLAGS) -o printf.o printf.c
	$(CC) -c $(CFLAGS) -o string.o string.c
	$(CC) -c $(CFLAGS) -o serial.o serial.c
	$(CC) -c $(CFLAGS) -o lib1funcs.o lib1funcs.S
	$(CC) -c $(CFLAGS) -o chinoOS.o chinoOS.c
	$(LD) $(LDFLAGS) -o chinoOS_elf entry.o gpio.o time.o vsprintf.o printf.o string.o serial.o lib1funcs.o chinoOS.o
	$(OC) $(OCFLAGS) chinoOS_elf chinoOS_img
	$(CC) -c $(CFLAGS) -o serial.o serial.c -D IN_GUMSTIX
	$(LD) $(LDFLAGS) -o chinoOS_gum_elf entry.o gpio.o time.o vsprintf.o printf.o string.o serial.o lib1funcs.o chinoOS.o
	$(OC) $(OCFLAGS) chinoOS_gum_elf chinoOS_gum_img

clean:
	rm *.o
	rm chinoOS_elf
	rm chinoOS_img
	rm chinoOS_gum_elf
	rm chinoOS_gum_img

