;for FAT32 file system on hard disk
;causion: the sector size MUST be 512
[org 0x7c3e]
[bits 16]

;=====GLOBAL=MACROS=====
;address-relative
%define stackbase	0x7c00
%define bufferbase	0x7e00
%define tmpbase		0x500

;FAT32-relative
;load the rootdir, get the first cluster of the given 
;file, than overwrite the rootdir region with FAT table, 
;and write the linked list of sector number to "tmpbase" in low memory
;0x500, oncethose steps are done, load the given file info "bufferbase"
;, which is 0x7e00, right after the boot sector region

%define rootdirbase	0x7e00
%define FATbase		0x7e00
%define SFNsize		32

;=======================

[section .code]
;=========================

init:
MOV AX, CX
MOV DS, AX
MOV ES, AX
MOV SS, AX
MOV SP, stackbase


;load rootdir and search for the given file, save the first
;cluster in register and go on loading FAT table



;=========================
[section .data]
DISKpacket:
	db	0x10		;size should be set 16 if not using "64-bit Addressing Extensions"
	db	0x0			;reserved, therefore 0
sectorcount:
	dw	0
buffer_offset:
	dw	0
buffer_segment_number:
	dw	0
d_lba:
	dd	0		;lower 32-bits of 48-bit starting LBA
	dd	0		;upper 16-bits of 48-bit starting LBA

[section subroutine]
%include "main.inc"