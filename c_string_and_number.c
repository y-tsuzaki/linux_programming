#include <stdio.h>

int main(int argc, char *argv[])
{
	char *str1 = "Hello, World!\n";
	char str2[15] = { 72, 101, 108,108, 111,44, 33,10,0 };

	printf("%s", str1);
	printf("%d", str2[0]);
}
