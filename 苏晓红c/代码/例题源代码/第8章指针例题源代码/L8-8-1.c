#include <stdio.h>
#define N 40
int ReadScore(int score[]);           /* ReadScore()����ԭ�� */
void DataSort(int score[], int n);   /* DataSort()ԭ������ */ 
void PrintScore(int score[], int n); /* PrintScore()����ԭ�� */
int main()
{
	int score[N], n;
	n = ReadScore(score);      /*���ú���ReadScore()����ɼ�������ѧ������*/
	printf("Total students are %d\n", n);
	DataSort(score, n);        /* ���ú���DataSort()���гɼ����� */
	printf("Sorted scores:");
	PrintScore(score, n);      /* ���ú���Printscore()����ɼ������� */
	return 0;
}
/* �������ܣ�����ѧ��ĳ�ſεĳɼ��������븺ֵʱ���������룬����ѧ������ */
int ReadScore(int score[])     /* ReadScore()�������� */
{
	int i = -1; /* i��ʼ��Ϊ-1���ɱ�֤ѭ������i��1�������±��0��ʼ */
	do{
		i++;
		printf("Input score:");
		scanf("%d", &score[i]);
	}while (score[i] >= 0);   /* ���븺ֵʱ�����ɼ����� */
	return i;                    /* ����ѧ������ */
}
/* �������ܣ���������������score��Ԫ��ֵԪ�ذ��Ӹߵ������� */
void DataSort(int score[], int n) /* DataSort()�������� */
{
	int i, j, temp;
	for (i=0; i<n-1; i++)
	{
		for (j=i+1; j<n; j++)                
		{
			if (score[j] > score[i]) /* ������score��Ԫ��ֵ�Ӹߵ������� */
			{    
				temp = score[j];
				score[j] = score[i];  
				score[i] = temp;
			}  
		}  
	}  
}
/* �������ܣ� ��ӡѧ���ɼ� */
void PrintScore(int score[], int n) /* PrintScore()�������� */
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%4d", score[i]);
	}
	printf("\n");
}
