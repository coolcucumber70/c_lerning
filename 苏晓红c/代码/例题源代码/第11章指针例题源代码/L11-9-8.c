#include <stdio.h>
#include <stdlib.h>
char* GetStr();
int main()
{
	char *ptr = NULL;
	ptr = GetStr();          /* ʹptrָ��̬������ڴ���׵�ַ */
	puts(ptr);
	free(ptr);                /* �ͷ�ptrָ��Ķ�̬������ڴ�*/
	return 0;
}
char* GetStr()
{
	char *s = NULL;
	s = (char *)malloc(80); /* ���붯̬������ڴ� */
	scanf("%s", s);
	return s;                  /* ���ض�̬������ڴ���׵�ַ */
}
