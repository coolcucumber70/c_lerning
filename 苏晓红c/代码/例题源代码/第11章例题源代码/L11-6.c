#include  <stdio.h>
#include  <stdlib.h>
void InputArray(int *p, int n);
double Average(int *p, int n);
int main()
{
	int  *p = NULL, n;
	double aver;
	printf("How many students?");
	scanf("%d", &n);                          /* ����ѧ������ */
	p = (int *) malloc(n * sizeof(int)); /* ��ϵͳ�����ڴ� */
	if (p == NULL)  /* ȷ��ָ��ʹ��ǰ�Ƿǿ�ָ�룬��pΪ��ָ��ʱ������������ */
	{
		printf("No enough memory!\n");
		exit(1); 
	}
	printf("Input %d score:", n);	
	InputArray(p, n);                     /* ����ѧ���ɼ� */          
	aver = Average(p, n);                 /* ����ƽ���� */
	printf("aver = %.1f\n", aver);      /* ���ƽ���� */
	free(p);                                /* �ͷ���ϵͳ������ڴ� */ 
	return 0;
}
/* �β�����Ϊָ���������������Ԫ��ֵ */
void InputArray(int *p, int n)  
{	
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%d", &p[i]);         
	}	
}
/* �β�����Ϊָ���������������Ԫ�ص�ƽ��ֵ */
double Average(int *p, int n)  
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum = sum + p[i];            
	} 
	return (double)sum / n;	
}
