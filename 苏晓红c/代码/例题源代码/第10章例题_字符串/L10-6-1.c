#include  <stdio.h>
unsigned int  MyStrlen(const char str[]);
int main()
{
	char   a[80];
	printf("Input a string:");
	gets(a);                  
	printf("The length of the string is: %u\n", MyStrlen(a));
	return 0;
}
/* �������ܣ����ַ������������������������ַ����ĳ��� */
unsigned int  MyStrlen(const char str[])
{ 
	int  i ;
	unsigned int len = 0;      /* ��������0 */
	for (i=0; str[i]!='\0'; i++)  
	{
		len++;                  	/* ����ѭ��ͳ�Ʋ�����'\0'���ڵ��ַ����� */
	}
	return len;               	/* ����ʵ���ַ����� */
} 
