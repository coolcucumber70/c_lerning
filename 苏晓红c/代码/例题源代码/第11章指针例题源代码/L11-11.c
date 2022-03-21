#include <stdio.h>
#include <string.h>
#define N 1024
int main(int argc, char *argv[])
{
	char buffer[N];
	if (argc > 1)
	{
		strncpy(buffer, argv[1], N-1);
	}
	//puts(buffer);
	printf("%s",buffer);
	return 0;
}
