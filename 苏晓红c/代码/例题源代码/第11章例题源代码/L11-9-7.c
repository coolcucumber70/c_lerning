#include <stdio.h>
#include <stdlib.h>
char* GetStr(char *s);
int main()
{
	char *ptr = NULL;
	ptr = GetStr(ptr);      /* ʹptrָ��̬������ڴ���׵�ַ */
	puts(ptr);
	free(ptr);                /* �ͷ�ptrָ��Ķ�̬������ڴ� */
	return 0;
}
char* GetStr(char *s)
{
	s = (char *)malloc(80); /* ���붯̬������ڴ� */
	scanf("%s", s);
	return s;                  /* ���ض�̬������ڴ���׵�ַ */
}
