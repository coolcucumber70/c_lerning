#include <stdio.h>
void GetStr(char *);
int main()
{
	char *ptr = NULL; /* ָ�������ʼ��Ϊ��ָ�� */
	GetStr(ptr);		
	puts(ptr);          /* ��ͼʹ�ÿ�ָ�� */
	return 0;
}
void GetStr(char *s)    /* ָ���βν���ʵ�δ��������ǿ�ָ�� */
{
	scanf("%s", s);    /* ��ͼʹ�ÿ�ָ�� */
} 
