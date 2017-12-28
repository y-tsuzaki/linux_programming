#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i++) {
		FILE *f;
		int c;

		f = fopen(argv[i], "r");
		if (!f) {
			perror(argv[i]);
			exit(1);
		}
		// c言語では代入式を比較に使うと、代入された"c"の値が比較に使われる
		while ((c = fgetc(f)) != EOF) {
			if(putchar(c) < 0) exit(1);
		}
		fclose(f);
	}
	exit(0);
}
