#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);          /*ReadScore()����ԭ��*/
void DataSort(int score[], long num[], int n);  /*DataSort()ԭ������*/ 
void PrintScore(int score[], long num[], int n);/*PrintScore()����ԭ��*/
int main()
{
	int score[N], n;
	long num[N];
	n = ReadScore(score, num);     /* ����ɼ���ѧ�ţ�����ѧ������ */
	printf("Total students are %d\n", n);
	DataSort(score, num, n);        /* �ɼ����� */
	printf("Sorted scores:\n");
	PrintScore(score, num, n);      /* ����ɼ������� */
	return 0;
}
/* �������ܣ�����ѧ����ѧ�ż���ĳ�ſγɼ��������븺ֵʱ���������룬����ѧ������ */
int ReadScore(int score[], long num[]) /* ReadScore()�������� */
{
	int i = -1;     /* i��ʼ��Ϊ-1���ɱ�֤ѭ������i��1�������±��0��ʼ */
	do{
		i++;
		printf("Input student's ID and score:");
		scanf("%ld%d", &num[i], &score[i]); /* �Գ����͸�ʽ����ѧ�� */
	}while (num[i] >0 && score[i] >= 0);    /* ���븺ֵʱ�����ɼ����� */
	return i;                                     /* ����ѧ������ */
}
/* �������ܣ���ѡ�񷨽�����score��Ԫ��ֵ���Ӹߵ������� */
void DataSort(int score[], long num[], int n) /*DataSort()��������*/
{
	int i, j, k, temp1;
	long temp2;
	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)      
		{
			if (score[j] > score[k])  /* ������score��Ԫ��ֵ�Ӹߵ������� */
			{
				k = j;                   /* ��¼������±�λ�� */
			}
		}
		if (k != i)                    /* ������������±�λ��i */
		{    
			/* �����ɼ� */
			temp1 = score[k]; score[k] = score[i];  score[i] = temp1;
			/* ����ѧ�� */
			temp2 = num[k]; num[k] = num[i]; num[i] = temp2; 
		}  
	}  
}
/* �������ܣ���ӡѧ��ѧ�źͳɼ� */
void PrintScore(int score[], long num[], int n) /*PrintScore()��������*/
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10ld%4d\n", num[i], score[i]); /* �Գ����͸�ʽ��ӡѧ�� */
	}
}
