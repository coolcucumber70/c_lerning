#include <stdio.h>
void GetStr(char *);
int main()
{
	char *ptr = NULL; /* ָ�������ʼ��Ϊ��ָ�� */
	GetStr(ptr);		
	if (ptr != NULL)
	{
		puts(ptr);          
	}
	else                   /* һ��ָ��Ϊ��ָ�룬�����"ʹ�ÿ�ָ��"����ʾ */
	{
		printf("Null pointer is used!\n");
	}
	return 0;
}
void GetStr(char *s)    /* ָ���βν���ʵ�δ��������ǿ�ָ�� */
{
	if (s != NULL)
	{
		scanf("%s", s);    
	}
	else                  /* һ��ָ��Ϊ��ָ�룬�����"ʹ�ÿ�ָ��"����ʾ */
	{
		printf("Null pointer is used!\n");
	}	
} 
