#include <stdio.h>
void InputArray(int *p, int m, int n);  
void OutputArray(int *p, int m, int n);  
int main()
{ 
	int  a[3][4];
	printf("Input 3*4 numbers:\n");
	InputArray(*a, 3, 4);   /* �������ݶ�ά����ĵ�0�е�0�еĵ�ַ */                      
	OutputArray(*a, 3, 4);  /* �������ݶ�ά����ĵ�0�е�0�еĵ�ַ */   
	return 0;
}
/* �β�����Ϊָ���ά�������ָ�룬��������Ԫ��ֵ */
void InputArray(int *p, int m, int n)   
{	
	int i, j;
	for(i = 0; i<m; i++)
	{ 
		for(j = 0; j<n; j++)
		{
			scanf("%d", &p[i*n+j]);         
		}
	}
}
/* �β�����Ϊָ���ά�������ָ�룬�������Ԫ��ֵ */
void OutputArray(int *p, int m, int n)
{
	int i, j;
	for(i = 0; i<m; i++)
	{ 
		for(j = 0; j<n; j++)
		{
			printf("%4d", p[i*n+j]);         
		}
		printf("\n");
	}
}
