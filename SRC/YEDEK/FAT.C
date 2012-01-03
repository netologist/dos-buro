#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fat.h"


int getboot(BOOT *info, int drive)
{
	BYTE btr[SECT_SIZE_MAX];

	biosdisk(2, 0x80, 0, 0, 0, 1, btr);
/*	if (absread(drive, 0, 1, btr) == -1)
		return -1;*/
	info->drive = drive;
	info->bps = *(WORD *) (btr + 0x0b);
	info->spc = *(BYTE *) (btr + 0x0d);
	info->reserved_sect = *(WORD *) (btr + 0x0e);
	info->fat_num = *(BYTE *) (btr + 0x10);
	info->root_ent = *(WORD *) (btr + 0x11);
	info->root_len = info->root_ent * FILE_INFO_LENGTH / info->bps;
	if (*(DWORD *) (btr + 0x13))
		info->total_sec = *(WORD *) (btr + 0x13);
	else
		info->total_sec = *(DWORD *) (btr + 0x20);
	info->media_descriptor = *(btr + 0x15);
	info->fat_len = *(WORD *) (btr + 0x16);
	info->spt = *(WORD *) (btr + 0x18);
	info->head_num = *(WORD *) (btr + 0x1a);
	info->hid_num = *(WORD *) (btr + 0x1c);
	info->tph = (WORD) (info->total_sec / info->spt / info->head_num);
	info->fat_or = info->reserved_sect;
	info->root_or = info->fat_len * info->fat_num + info->reserved_sect;
	info->data_or = info->root_or + info->root_len;
	return 0;
}

FATBUF *OpenFatBuffer(const BOOT *boot, int sectsize)
{
	FATBUF *fatbuf;

	if (sectsize < 2)
		return NULL;
	fatbuf = (FATBUF *) calloc(1, sizeof(FATBUF));
	if (fatbuf == NULL)
		return NULL;
	fatbuf->bpb = (BOOT *) malloc(sizeof(BOOT));
	if (fatbuf->bpb == NULL) {
		CloseFatBuffer(fatbuf);
		return NULL;
	}
	memcpy(fatbuf->bpb, boot, sizeof(BOOT));
	fatbuf->bufsize = MIN(sectsize, boot->fat_len);
	fatbuf->buf = (BYTE *) malloc(fatbuf->bufsize * boot->bps);
	if (fatbuf->buf == NULL) {
		CloseFatBuffer(fatbuf);
		return NULL;
	}
	fatbuf->ftype = boot->total_sec > FAT_TYPE_ZONE ? FAT16 : FAT12;
	fatbuf->cflag = NOUPDATE;
	LoadFatBuffer(fatbuf, 0);
	return fatbuf;
}

void LoadFatBuffer(FATBUF *fatbuf, int hsect)
{
	int nsects, current_sector;

	if (fatbuf->cflag == UPDATE) {
		return;
	}
	fatbuf->head = hsect;
	fatbuf->tail = MIN(fatbuf->bufsize, fatbuf->bpb->fat_len);

	if (absread(fatbuf->bpb->drive, fatbuf->bufsize,
		fatbuf->head + fatbuf->bpb->fat_or, fatbuf->buf) == -1) {
		printf("ôlÅmcÅl hata: Fat okunamadç\n");
		exit(1);
	}
}

WORD GetNextClue(FATBUF *fatbuf, DWORD clu)
{
	DWORD cluoff, rcluoff;
	WORD clusect, nextclue;

	cluoff = (fatbuf->ftype == FAT12) ? clu * 3 / 2: clu * 2;
	clusect = cluoff / fatbuf->bpb->bps;

	if ((clusect < fatbuf->head || clusect > fatbuf->tail) || (cluoff + 1) % fatbuf->bpb->bps == 0)
		LoadFatBuffer(fatbuf, clusect);
	rcluoff = cluoff - fatbuf->head * fatbuf->bpb->bps;
	nextclue = * (WORD *) (fatbuf->buf + rcluoff);
	if (fatbuf->ftype == FAT12) {
		nextclue = (clu % 2) ? nextclue >> 4 : nextclue & 0xfff;
	}
	return nextclue;
}

void CloseFatBuffer(FATBUF *fatbuf)
{
	if (fatbuf->buf)
		free(fatbuf->buf);
	if (fatbuf->bpb)
		free(fatbuf->bpb);
	free(fatbuf);
}

void main(void)
{
	BOOT boot;
	FATBUF *fatbuf;
	int result, i;
	WORD clu;

	result = getboot(&boot, 2);
	if (result == -1) {
		printf("Boota oluüturulamadç.\n");
		exit(1);
	}
	printf("Drive :\n", boot.drive);
	printf("fat_len :\n", boot.fat_len);
	printf("root_len\n", boot.root_len);
	printf("fat_num\n", boot.fat_num);
	printf("total_sec\n", boot.total_sec);
	printf("bps\n", boot.bps);
	printf("spc\n", boot.spc);
exit(1);
	fatbuf = OpenFatBuffer(&boot, 25);
	if (fatbuf == NULL) {
		printf("Fat tamponlanamadç.\n");
		exit(1);
	}
	clu = 18;
	for (i = 0;; i++) {
		clu = GetNextClue(fatbuf, clu);
		if (clu == EOC12)
			break;
		printf("%3u ", clu);
	}
	CloseFatBuffer(fatbuf);
}
