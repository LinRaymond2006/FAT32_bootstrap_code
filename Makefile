.PHONY:all, dump, cleanup
NASMFLAGS := -f bin
DIST_BIN :=CODE.BIN
SOURCE := MAIN.ASM
all:
	nasm $(NASMFLAGS) $(SOURCE) -o $(DIST_BIN)
	xxd -g 1 $(DIST_BIN)
	wc < $(DIST_BIN)
	#not tested the dd command yet
	#dd if=$(DIST_BIN) of=$(DISK_IMG) bs=1 seek=90 skip=90 count=420 conv=notrunc
dump:
	objdump -mi8086 -bbinary -Mintel -D $(DIST_BIN)
cleanup:
	rm $(DIST_BIN)
