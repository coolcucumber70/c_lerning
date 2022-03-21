#include <stdio.h>
char* GetStr(void);
int main()
{
	char *ptr = NULL;
	ptr = GetStr();		
	puts(ptr);         /* ��ͼʹ��Ұָ�� */
	return 0;
}
char* GetStr(void)
{
	char s[80];        /* ���嶯̬�洢���͵����� */
	scanf("%s", s);
	return s;           /* ��ͼ���ض�̬�ֲ������ĵ�ַ */
}
