#include <stdio.h>
#define N 40
int ReadScore(int score[]);       /* ReadScore()����ԭ�� */
int FindMax(int score[], int n);  /* FindMax()����ԭ�� */ 
int main()
{
	int score[N], max, n;
	n = ReadScore(score);      /*���ú���ReadScore()����ɼ�������ѧ������*/
	printf("Total students are %d\n",n);
	max = FindMax(score, n);   /*���ú���FindMax()������߷֣�������߷�*/
	printf("The highest score is %d\n",max);
	return 0;
}
/* �������ܣ�����ѧ��ĳ�ſεĳɼ��������븺ֵʱ���������룬����ѧ������ */
int ReadScore(int score[])     /* ReadScore()�������� */
{
	int i = -1;         /*i��ʼ��Ϊ-1��ѭ��������1��ɱ�֤�����±��0��ʼ*/
	do{
		i++;
		printf("Input score:");
		scanf("%d", &score[i]);
	} while (score[i] >= 0);    /* ���븺ֵʱ�����ɼ����� */
	return i;                      /* ����ѧ������ */
}
/* �������ܣ�������߷� */
int FindMax(int score[], int n)/* FindMax()�������� */
{
	int max, i;
	max = score[0];	           /* ����score[0]ֵΪ��ǰ���ֵ */
	for (i=1; i<n; i++)                        
	{
		if (score[i] > max)      /* ��score[i]ֵ�ϴ� */             
		{  	
			max = score[i];      /* ����score[i]ֵ�滻��ǰ���ֵ */
		}
	}
	return max;                    /* ������߷� */
}
