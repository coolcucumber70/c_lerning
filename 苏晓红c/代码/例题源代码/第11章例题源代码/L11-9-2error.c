#include <stdio.h>
char* GetStr(void);
int main()
{
	char *ptr = NULL;
	printf("ptr = %p\n", ptr);/* ��ӡ��ʼ��ΪNULL���ָ�������ֵ */
	printf("Input a string:");
	ptr = GetStr();		
	printf("ptr = %p\n", ptr);/* ��ӡ�������غ���ջ�ϴ������ڴ���׵�ַ */
	puts(ptr);                    /* ��ͼʹ��Ұָ�룬�����³���������� */
	return 0;
}
char* GetStr(void)
{
	char s[80];                  /* ���嶯̬�洢���͵����� */
	scanf("%s", s);
	printf("s = %p\n", s);    /* ��ӡ��������ǰ��ջ�ϴ������ڴ���׵�ַ */
	return s;                    /* ��ͼ���ض�̬�ֲ������ĵ�ַ */
}
