#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

static char *filetype(mode_t mode);


# stat を使ってファイルのステータスを表示するコマンド。一部。
int
main(int argc, char *argv[])
{

	struct stat st;

	if (argc != 2) {
		fprintf(stderr, "%s: wrong argument\n", argv[0]);
		exit(1);
	}
	if (lstat(argv[1], &st) < 0) {
		perror(argv[1]);
		exit(1);
	}

	printf("type\t%o (%s)\n", (st.st_mode & S_IFMT), filetype(st.st_mode));

	exit(0);
}

static char*
filetype(mode_t mode) {
	if (S_ISREG(mode)) return "file";
 	if (S_ISDIR(mode)) return "directory";
	return "unknown";
}
