#include <stdio.h>
int main()
{
	int  a[5], *p = NULL, i;
	printf("Input five numbers:");
	p = a;                      /* p=a�ȼ���p=&a[0] */
	for (i=0; i<5; i++)
	{
		scanf("%d", &p[i]); /* &p[i]�ȼ���p+i */
	}
	p = a;   			             /* ���ٴ�ѭ����ʼǰ��ȷ��ָ��Pָ�������׵�ַ */
	for (i=0; i<5; i++)
	{
		printf("%4d", p[i]); /* p[i]�ȼ���*(p+i) */
	}
	printf("\n");
	return 0;
}
