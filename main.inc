;========================================================================================
;reference:
;https://wiki.osdev.org/Disk_access_using_the_BIOS_(INT_13h)
;====================
;description:

;using LBA48 addressing mode, but not going to use 64-bit Addressing Extensions
;the disk operation will be processed with a packet passed to bios
;====================
;information:

;Offset	Size	Description
;0	    1	    size of packet (16 bytes)
;1	    1	    always 0
;2	    2		number of sectors to transfer (max 127 on some BIOSes)
;4	    4		transfer buffer (16 bit segment:16 bit offset) (see note #1)
;8	    4		lower 32-bits of 48-bit starting LBA
;12		4		upper 16-bits of 48-bit starting LBA
;example:Reading 16 sectors from LBA #1 to physical address 0x7C00
;DAPACK:
;	db	0x10
;	db	0
;blkcnt:	dw	16		; int 13 resets this to # of blocks actually read/written
;db_add:	dw	0x7C00		; memory buffer destination address (0:7c00)
;	dw	0		; in memory page zero
;d_lba:	dd	1		; put the lba to read in this spot
;	dd	0		; more storage bytes only for big lba's ( > 4 bytes ) 
;
;	mov si, DAPACK		; address of "disk address packet"
;	mov ah, 0x42		; AL is unused
;	mov dl, 0x80		; drive number 0 (OR the drive # with 0x80)
;	int 0x13
;	jc short .error
;========================================================================================
read_ATA:
	;the packet should be set by callee
	;si should be saved by callee
	mov si, DISKpacket
	mov ah, 0x42		;service number
	mov dl, 0x80		 drive number 0 (OR the drive # with 0x80)
	int 0x13
	jc short .error
