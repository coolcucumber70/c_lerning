#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	if ((fp = fopen("demo.txt","w")) == NULL) /* �ж��ļ��Ƿ�ɹ��� */
	{ 
		printf("Failure to open demo.txt!\n");
		exit(0);
	}
	ch = getchar();
	while (ch != '\n')   /* ������س����з����������������ļ�д�� */              
	{   
		fputc(ch, fp);
        ch = getchar();  
	}
	fclose(fp);           /* �ر��ɺ���fopen()�򿪵��ļ�demo.txt */
	return 0;
}
