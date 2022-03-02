#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int i;
	if ((fp = fopen("demo.bin","wb")) == NULL) /* �Զ�����д��ʽ���ļ� */
	{ 
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	for (i=0; i<128; i++)
	{  	
		fputc(i, fp);     /* ��ASCII��ֵ��0-127֮��������ַ�д���ļ� */
	}
	fclose(fp);
	if ((fp = fopen("demo.bin","rb")) == NULL) /* �Զ����ƶ���ʽ���ļ� */
	{ 
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	while ((ch = fgetc(fp)) != EOF)     /* ���ļ��ж�ȡ�ַ�ֱ���ļ�ĩβ */    
	{
		putchar(ch);         /* ����ʾ������ʾ���ļ������������ַ� */ 
	}
	fclose(fp);
	return 0;
}
