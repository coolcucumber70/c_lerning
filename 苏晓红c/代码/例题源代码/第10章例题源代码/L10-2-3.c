#include <stdio.h>
#define N 12
int main()
{
	char  name[N];
	printf("Enter your name:");
    fgets(name, sizeof(name), stdin); /* ���������ַ������Ȳ����������С */
    printf("Hello %s ! \n",name);
	return 0;
}
