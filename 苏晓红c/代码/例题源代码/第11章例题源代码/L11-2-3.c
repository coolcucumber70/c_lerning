#include <stdio.h>
void InputArray(int a[], int n);
void OutputArray(int a[], int n);
int main()
{
	int  a[5];
	int *p = a;
	printf("Input five numbers:");
	InputArray(p, 5);                 /* ��ָ��һά�����ָ�������Ϊ����ʵ�� */
	OutputArray(p, 5);                /* ��ָ��һά�����ָ�������Ϊ����ʵ�� */
	return 0;
}
void InputArray(int a[], int n)   /* �β�����Ϊ���飬��������Ԫ��ֵ */
{
	int  i;
	for (i=0; i<n; i++)
	{
		scanf("%d", a+i);            /* ����a+i�ȼ���&a[i] */
	}	
}
void OutputArray(int a[], int n) /* �β�����Ϊ���飬�������Ԫ��ֵ */
{
	int  i;
	for (i=0; i<n; i++)
	{
		printf("%4d", *(a+i));      /* ����*(a+i)�ȼ���a[i] */
	}
	printf("\n");	
}


