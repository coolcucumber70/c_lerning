#include <stdio.h>
int main()
{
	int  a[5], *p;
	printf("Input five numbers:");
	for (p = a; p<a+5; p++)
	{
		scanf("%d", p);        /* ��ָ�뷨��������Ԫ�� */
	}
	for (p = a; p<a+5; p++)
	{
		printf("%4d", *p);      /* ��ָ�뷨��������Ԫ�� */
	}
	printf("\n");
	return 0;
}
