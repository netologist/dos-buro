#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *fp;

	fp = fopen("hasanin.ki", "wb+");

	fseek(fp, 0, SEEK_SET);
	printf("%ld\n", ftell(fp));
	fwrite("Hasan & Saadet Hançm", 1, 550, fp);
	fseek(fp, -10, SEEK_CUR);
	printf("%ld\n", ftell(fp));
	fclose(fp);
}