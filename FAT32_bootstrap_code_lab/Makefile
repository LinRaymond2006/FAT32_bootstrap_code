.PHONY:all, dump, cleanup, run
NASMFLAGS := -f bin
DIST_BIN :=CODE.BIN
SOURCE := MAIN.ASM
LOADER_NAME := LOADER.SYS
#ata0-master: type=disk, path="boot.img", mode=flat
all:
	-rm boot.img boot.img.lock
	-mkdir mount_dir
	cp boot.img.bck boot.img
	mkfs.fat -F32 -S512 -D0x80 -s4 boot.img
	nasm $(NASMFLAGS) $(SOURCE) -o $(DIST_BIN)
	xxd -g 1 $(DIST_BIN)
	wc < $(DIST_BIN)
	#not tested the dd command yet
	#dd if=$(DIST_BIN) of=$(DISK_IMG) bs=1 seek=90 skip=90 count=420 conv=notrunc
	dd if=$(DIST_BIN) of=boot.img bs=1 seek=90 skip=90 conv=notrunc
	sudo mount -t vfat ./boot.img ./mount_dir/ -o rw,uid=$(shell id -u),gid=$(shell id -g)
	cp $(LOADER_NAME) ./mount_dir/
	sync
	sudo umount ./mount_dir/
dump:
	objdump -mi8086 -bbinary -Mintel -D $(DIST_BIN)
cleanup:
	rm $(DIST_BIN)
run:
	clear
	-rm boot.img.lock bochs.log
	bochs
