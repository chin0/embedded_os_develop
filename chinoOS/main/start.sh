#!/bin/sh

rm -f chinoOSimg
rm -f chinoOS.jffs2

mkimage -A arm -O linux -T kernel -C none -a a0008000 -e a0008000 -n ChinoOS -d chinoOS_gum_img uImage

mv uImage ../chinoOSkernel/boot/

mkfs.jffs2 -e 0x20000 -d ../chinoOSkernel -p -o chinoOS.jffs2

dd of=chinoOSimg bs=1k conv=notrunc if=flash.bin
dd of=chinoOSimg bs=1k conv=notrunc seek=180 if=chinoOS.jffs2
