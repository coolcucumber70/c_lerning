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
/* �������ܣ����ַ�ָ����Ϊ����������ʵ���ַ������� */
void  MyStrcpy(char *dstStr, char *srcStr)
{
	while (*srcStr != '\0')	/* ����ǰsrcStr��ָ�ַ������ַ���������־ */
	{ 
		*dstStr = *srcStr; 	/* �����ַ� */
		srcStr++;            	/* ʹsrcStrָ����һ���ַ� */
		dstStr++;            	/* ʹdstStrָ����һ���洢��Ԫ */
	}
	*dstStr = '\0';         	/* ���ַ���dstStr��ĩβ����ַ���������־ */
}
