#include <stdio.h>
#include <stdlib.h>
void GetStr(char *);
int main()
{
	char *ptr = NULL;
	GetStr(ptr);
	puts(ptr);                /* ��ͼʹ�ÿ�ָ�� */
	return 0;
}
void GetStr(char *s)
{
	s = (char *)malloc(80); /* ���붯̬������ڴ� */
	scanf("%s", s);
}
