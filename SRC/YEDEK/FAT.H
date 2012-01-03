#ifndef _DISK_H_

#define SECT_SIZE_MAX		1024
#define SECT_SIZE      		512
#define FILE_INFO_LENGTH    32

#define FAT12			0
#define FAT16  		    1
#define FAT32			2
#define EOC12			0xfff
#define EOC16			0xffff
#define FAT_TYPE_ZONE	32680

#define UPDATE		0
#define NOUPDATE	1

#define MIN(a, b)	((a) < (b) ? (a) : (b))

typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned long int DWORD;

typedef struct _BOOT {
	WORD drive;
	WORD fat_len;
	WORD root_len;
	WORD fat_num;
	DWORD total_sec;
	WORD bps;
	WORD spc;
	WORD reserved_sect;
	BYTE media_descriptor;
	WORD spt;
	WORD root_ent;
	WORD head_num;
	WORD hid_num;
	WORD tph;
	WORD fat_or;
	WORD root_or;
	WORD data_or;
} BOOT;

typedef struct _FATBUF {
	int bufsize;
	int head;
	int tail;
	int cflag;
	int ftype;
	BOOT *bpb;
	BYTE *buf;
} FATBUF;

int getboot(BOOT *info, int drive);
FATBUF *OpenFatBuffer(const BOOT *boot, int sectsize);
void LoadFatBuffer(FATBUF *fatbuf, int hsect);
WORD GetNextClue(FATBUF *fatbuf, DWORD clu);
void CloseFatBuffer(FATBUF *fatbuf);
#endif