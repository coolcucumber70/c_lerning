#include  <stdio.h>
#define N 80
void  MyStrcpy(char dstStr[], char srcStr[]);
int main()
{ 
	char  a[N], b[N]; 
	printf("Input a string:");
	gets(a);                      /* �����ַ��� */
	MyStrcpy(b, a);              /* ���ַ�����a�е��ַ���������b�� */
	printf("The copy is:");
	puts(b);                       /* ������ƺ���ַ��� */
	return 0;
}
/* �������ܣ����ַ�������Ϊ��������ʵ���ַ������� */
void  MyStrcpy(char dstStr[], char srcStr[])  
{
	int  i = 0;                   /* �����±��ʼ��Ϊ0 */
	while (srcStr[i] != '\0')  /* ����ǰȡ�����ַ������ַ���������־ */
	{ 
		dstStr[i] = srcStr[i];/* �����ַ� */
		i++;                      /* �ƶ��±� */
	}
	dstStr[i] = '\0';            /* ���ַ���dstStr��ĩβ����ַ���������־ */  
}
