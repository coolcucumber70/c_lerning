#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);          /*ReadScore()����ԭ��*/
int LinSearch(long num[], long x, int n);        /* LinSearch()ԭ������*/ 
int main()
{
	int score[N], n, pos;
	long num[N], x;
	n = ReadScore(score, num);  /* ����ɼ���ѧ�ţ�����ѧ������ */
	printf("Total students are %d\n", n);
	printf("Input the searching ID:");
	scanf("%ld", &x);          	 /* �Գ����͸�ʽ�Ӽ�����������ҵ�ѧ��x */
	pos = LinSearch(num, x, n); /* ����ѧ��Ϊnum��ѧ�� */
	if (pos != -1)              	 /* ���ҵ������ӡ����� */
	{  
		printf("score = %d\n", score[pos]); 
	}
	else                      		/* ��δ�ҵ������ӡ"δ�ҵ�"��ʾ��Ϣ*/
	{   
		printf("Not found!\n");    
	}
	return 0;
}
/* �������ܣ�����ѧ����ѧ�ż���ĳ�ſγɼ��������븺ֵʱ���������룬����ѧ������ */
int ReadScore(int score[], long num[]) /* ReadScore()�������� */
{
	int i = -1;         /*i��ʼ��Ϊ-1��ѭ��������1��ɱ�֤�����±��0��ʼ*/
	do{
		i++;
		printf("Input student's ID and score:");
		scanf("%ld%d", &num[i], &score[i]);
	} while (num[i] >0 && score[i] >= 0); /* ���븺ֵʱ�����ɼ����� */
	return i;                                   /* ����ѧ������ */
}
/*�����Բ��ҷ�����ֵΪx������Ԫ�أ����ҵ��򷵻�x�������е��±�λ�ã����򷵻�-1*/
int LinSearch(long num[], long x, int n) /* LinSearch()�������� */
{
	int  i;  
	for (i=0; i<n; i++)                 
	{	
		if (num[i] == x)	return i; /* ���ҵ��򷵻�x�������е��±� */
	}
	return (-1);                           /* ��ѭ��������δ�ҵ����򷵻�-1 */
}
