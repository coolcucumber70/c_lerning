#include <stdio.h>
void GetStr(char *);
int main()
{
	char s[80];
	char *ptr = s;      /* ָ���ʼ����ʹ��ָ������s���׵�ַ */
	GetStr(ptr);		
	puts(ptr);           /* ���û�������ַ�����ȷ����ʾ��� */
	return 0;
}
void GetStr(char *s)     /* ָ���βν���ʵ�δ������������׵�ַ */
{
	scanf("%s", s);
} 
