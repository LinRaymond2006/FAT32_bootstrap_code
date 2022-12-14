;STRUCT FAT32_HEADER {
	BS_JMPBOOT: TIMES 3 DB 0
	BS_OEMNAME: TIMES 8 DB 0
	BPB_BYTSPERSEC: DW 0		;THIS FIELD "MUST" BE 512, OR THE PROGRAM WILL NOT WORK!!!
	BPB_SECPERCLUS: DB 0
	BPB_RESVDSECCNT: DW 0
	BPB_NUMFATS: DB 0
	BPB_ROOTENTCNT: DW 0
	BPB_TOTSEC16: DW 0
	BPB_MEDIA: DB 0
	BPB_FATSZ16: DW 0
	BPB_SECPERTRK: DW 0
	BPB_NUMHEADS: DW 0
	BPB_HIDDSEC: DD 0
	BPB_TOTSEC32: DD 0
	BPB_FATSZ32: DD 0
	BPB_EXTFLAGS: DW 0
	BPB_FSVER: DW 0
	BPB_ROOTCLUS: DD 0
	BPB_FSINFO: DW 0
	BPB_BKBOOTSEC: DW 0
	BPB_RESERVED: TIMES 12 DB 0
	BS_DRVNUM: DB 0
	BS_RESERVED1: DB 0
	BS_BOOTSIG: DB 0
	BS_VOLID: DD 0
	BS_VOLLAB: TIMES 11 DB 0
	BS_FILSYSTYPE: DB "FAT32   "
;}
