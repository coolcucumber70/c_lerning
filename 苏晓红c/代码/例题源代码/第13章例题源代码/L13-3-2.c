#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	FILE *fp;
	char ch;
	int i;
	if ((fp = fopen("demo.bin","wb")) == NULL) /* 以二进制写方式打开文件 */
	{ 
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	for (i=0; i<128; i++)
	{  	
		fputc(i, fp);     /* 将字符的ASCII码值写入文件 */
	}
	fclose(fp);
	if ((fp = fopen("demo.bin","rb")) == NULL) /* 以二进制读方式打开文件 */
	{ 
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	while (!feof(fp))            /* 从文件中读取字符直到文件末尾 */
	{
		ch = fgetc(fp); 
		if (isprint(ch))          /* 判断是否是可打印字符 */
		{
			printf("%c\t", ch); /* 若是可打印字符，则显示该字符 */
		}
		else
		{
			printf("%d\t", ch); /*若非可打印字符，则显示该字符的ASCII码值*/
		}
    }
	fclose(fp);
	return 0;
}
