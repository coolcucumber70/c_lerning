#include <stdio.h>
void InputArray(int *pa, int n);
void OutputArray(int *pa, int n);
int main()
{
	int  a[5];
	int *p = a;
	printf("Input five numbers:");
	InputArray(p, 5);                 /* ��ָ��һά�����ָ�������Ϊ����ʵ�� */
	OutputArray(p, 5);                /* ��ָ��һά�����ָ�������Ϊ����ʵ�� */
	return 0;
}
void InputArray(int *pa, int n)   /* �β�����Ϊָ���������������Ԫ��ֵ */
{	
	int i;
	for (i=0; i<n; i++, pa++)
	{
		scanf("%d", pa);             /* ��ָ�뷨��������Ԫ�� */
	}	
}
void OutputArray(int *pa, int n)  /* �β�����Ϊָ��������������Ԫ��ֵ */
{
	int i;
	for (i=0; i<n; i++, pa++)
	{
		printf("%4d", *pa);          /* ��ָ�뷨��������Ԫ�� */
	}
	printf("\n");	
}

