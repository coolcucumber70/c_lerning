#include  <stdio.h>
unsigned int  MyStrlen(const char *pStr);
int main()
{
	char   a[80];
	printf("Input a string:");
	gets(a);                  
	printf("The length of the string is: %u\n", MyStrlen(a));
	return 0;
}
/* �������ܣ����ַ�ָ�������������������ַ����ĳ��� */
unsigned int  MyStrlen(const char *pStr)
{ 
	unsigned int  len = 0;   /* ��������0 */
	for ( ; *pStr!='\0'; pStr++)  
	{
		len++;                 /* ����ѭ��ͳ�Ʋ�����'\0'���ڵ��ַ����� */
	}
	return len;             /* ����ʵ���ַ����� */
} 
