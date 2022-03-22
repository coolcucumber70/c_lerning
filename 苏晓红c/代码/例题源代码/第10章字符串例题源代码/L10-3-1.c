#include <stdio.h>
#define N 12
int main()
{
	char  name[N];
	char  str[] = "\"Hello\", I said to";
	printf("Enter your name:");
	fgets(name, sizeof(name), stdin);           
    printf("%s %s. \n", str, name);
	return 0;
}
