#include <stdio.h>
#include <stdlib.h>
#define N 80
int main()
{
	FILE *fp;
	char str[N];
	if ((fp = fopen("demo.txt","a")) == NULL) /* ����ӷ�ʽ���ı��ļ� */
	{ 
		printf("Failure to open demo.txt!\n");
		exit(0);
	}
	gets(str);              /* �Ӽ��̶���һ���ַ��� */
	fputs(str, fp);        /* ���ַ���strд��fp��ָ���ļ� */
	fclose(fp);
	if ((fp = fopen("demo.txt","r")) == NULL) /* �Զ���ʽ���ı��ļ� */
	{ 
		printf("Failure to open demo.txt!\n");
		exit(0);
	}
	fgets(str, N, fp);   /* ��fp��ָ���ļ��ж����ַ���������N-1���ַ� */
	puts(str);             /* ���ַ����͵���Ļ��ʾ */
	fclose(fp);
	return 0;
}
