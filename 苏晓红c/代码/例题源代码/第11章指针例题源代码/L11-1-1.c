#include <stdio.h>
int main()
{
	int  a[5], i;
	printf("Input five numbers:");
	for (i=0; i<5; i++)
	{
		scanf("%d", &a[i]);    /* ���±귨��������Ԫ�� */
	}
	for (i=0; i<5; i++)
	{
		printf("%4d", a[i]);   /* ���±귨��������Ԫ�� */
	}
	printf("\n");
	return 0;
}
