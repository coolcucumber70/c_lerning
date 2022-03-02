#include  <stdio.h>
#include  <stdlib.h>
void InputArray(int *p, int m, int n); 
double Average(int *p, int m, int n);
int main()
{
	int  *p = NULL, m, n;
	double aver;
	printf("How many classes?");
	scanf("%d", &m);                          /* ����༶�� */
	printf("How many students in a class?");
	scanf("%d", &n);                          /* ����ÿ��ѧ������ */
	p = (int *)calloc(m*n, sizeof(int));  /* ��ϵͳ�����ڴ� */
	if (p == NULL)  /* ȷ��ָ��ʹ��ǰ�Ƿǿ�ָ�룬��pΪ��ָ��ʱ������������ */
	{
		printf("No enough memory!\n");
		exit(1); 
	}
	InputArray(p, m, n);              /* ����ѧ���ɼ� */          
	aver = Average(p, m, n);         /* ����ƽ���� */
	printf("aver = %.1f\n", aver);    /* ���ƽ���� */
	free(p);                            /* �ͷ���ϵͳ������ڴ� */ 
	return 0;
}
/* �β�����Ϊָ���ά�������ָ�룬��������Ԫ��ֵ */
void InputArray(int *p, int m, int n)   
{	
	int i, j;
	for(i = 0; i<m; i++)        /* m���� */
	{ 
		printf("Please enter scores of class %d:\n", i+1);
		for(j = 0; j<n; j++)   /* ÿ��n��ѧ�� */
		{
			scanf("%d", &p[i*n+j]);         
		}
	}
}
/* �β�����Ϊָ���������������Ԫ�ص�ƽ��ֵ */
double Average(int *p, int m, int n)  
{
	int i, j, sum = 0;
	for(i = 0; i<m; i++)       /* m���� */
	{ 		
		for(j = 0; j<n; j++)  /* ÿ��n��ѧ�� */
		{
			sum = sum + p[i*n+j]; 	        
		}		           
	} 
	return (double)sum / (m*n);	
}
