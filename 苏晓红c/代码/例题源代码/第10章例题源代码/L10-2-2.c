#include <stdio.h>
#define N 12
int main()
{
	char  name[N];
	char  *ptrName = name;  /* ������һ��ָ������name���ַ�ָ��ptrName */ 
	printf("Enter your name:");
	gets(ptrName);           /* �����ַ��������ַ�ָ��ptrName��ָ����ڴ� */
    //printf("Hello %s!\n", ptrName);
	puts(name);
	printf("i am wfp\n");
	return 0;
}
