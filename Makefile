.PHONY:all, cleanup
NASMFLAGS := -f bin
all:
	nasm $(NASMFLAGS) MAIN.ASM -o CODE.BIN
	xxd -g 1 CODE.BIN
	wc < CODE.BIN
cleanup:
	rm CODE.BIN

