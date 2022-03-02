#include <stdio.h>
#include <string.h>
#define N 10
int main()
{
	char str[N];
	fgets(str, N*sizeof(char), stdin);
	puts(str);
	return 0;
}
