#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
		fputc(i, fp);     /* ���ַ���ASCII��ֵд���ļ� */
	}
	fclose(fp);
	if ((fp = fopen("demo.bin","rb")) == NULL) /* �Զ����ƶ���ʽ���ļ� */
	{ 
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	while (!feof(fp))            /* ���ļ��ж�ȡ�ַ�ֱ���ļ�ĩβ */
	{
		ch = fgetc(fp); 
		if (isprint(ch))          /* �ж��Ƿ��ǿɴ�ӡ�ַ� */
		{
			printf("%c\t", ch); /* ���ǿɴ�ӡ�ַ�������ʾ���ַ� */
		}
		else
		{
			printf("%d\t", ch); /*���ǿɴ�ӡ�ַ�������ʾ���ַ���ASCII��ֵ*/
		}
    }
	fclose(fp);
	return 0;
}
