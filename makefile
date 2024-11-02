all:
	cd kernel && xmake
	mkdir -p isodir/boot/grub
	cp kernel/os.bin isodir/boot/os.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o os.iso isodir
	

run:
	make all
	qemu-system-i386 -m 512M -cdrom os.iso -display gtk

run-debug:
	make all
	qemu-system-i386 -m 512M -cdrom os.iso -boot d -d int,cpu_reset -s -S -display gtk




clean:
	rm os.iso
	cd kernel && make clean
	rm -rf isodir
