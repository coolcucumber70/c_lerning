#include  <stdio.h>
#define N 80
char *MyStrcat(char *dstStr, char *srcStr);
int main()
{
	char first[2*N];   /* �������Ӧ���㹻���Ա������Ӻ���ַ��� */
	char second[N];
	printf("Input the first string:");
	gets(first);
	printf("Input the second string:");
	gets(second);
	printf("The result is: %s\n", MyStrcat(first, second));
	return 0;
}
/* �������ܣ����ַ���srcStr���ӵ��ַ���dstStr�ĺ��� */
char *MyStrcat(char *dstStr, char *srcStr)
{
	char *pStr = dstStr;   /* �����ַ���dstStr���׵�ַ */
	/* ��ָ���Ƶ��ַ���dstStr��ĩβ */
	while (*dstStr != '\0')
	{
		dstStr++;
	}  
	/* ���ַ���srcStr���Ƶ��ַ���dstStr�ĺ��� */
	for(; *srcStr!='\0'; dstStr++, srcStr++)
	{
		*dstStr = *srcStr;
	}
	*dstStr = '\0';      /* �����Ӻ���ַ�����ĩβ����ַ���������־ */
	return pStr;         /* �������Ӻ���ַ���dstStr���׵�ַ */
}
