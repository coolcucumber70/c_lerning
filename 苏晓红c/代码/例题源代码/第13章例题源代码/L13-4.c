#include <stdio.h>
#include <stdlib.h>
#define N 80
int main()
{
	FILE *fp;
	char str[N];
	if ((fp = fopen("demo.txt","a")) == NULL) /* 以添加方式打开文本文件 */
	{ 
		printf("Failure to open demo.txt!\n");
		exit(0);
	}
	gets(str);              /* 从键盘读入一个字符串 */
	fputs(str, fp);        /* 将字符串str写入fp所指的文件 */
	fclose(fp);
	if ((fp = fopen("demo.txt","r")) == NULL) /* 以读方式打开文本文件 */
	{ 
		printf("Failure to open demo.txt!\n");
		exit(0);
	}
	fgets(str, N, fp);   /* 从fp所指的文件中读出字符串，最多读N-1个字符 */
	puts(str);             /* 将字符串送到屏幕显示 */
	fclose(fp);
	return 0;
}
