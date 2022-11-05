.PHONY:all
NASMFLAGS := -f bin
all:
	nasm $(NASMFLAGS) MAIN.ASM -o CODE.BIN

