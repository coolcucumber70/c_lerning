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
	for (i=0; i<n; i++)
	{
		scanf("%d", &pa[i]);  /* �β�����Ϊָ�����ʱҲ���԰��±귽ʽ�������� */       
	}	
}
void OutputArray(int *pa, int n)  /* �β�����Ϊָ��������������Ԫ��ֵ */
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%4d",pa[i]);  /* �β�����Ϊָ�����ʱҲ���԰��±귽ʽ�������� */        
	}
	printf("\n");	
}


