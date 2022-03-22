#include <stdio.h>
#define N 40
int Average(int score[], int n); /* Average()����ԭ�� */  
int ReadScore(int score[]);       /* ReadScore()����ԭ�� */
int main()
{
	int score[N], aver, n;
	n = ReadScore(score);      /*���ú���ReadScore()����ɼ�������ѧ������*/
	printf("Total students are %d\n",n);
	aver = Average(score, n);  /*���ú���Average()����ƽ���֣�����ƽ����*/  
	printf("Average score is %d\n",aver);
	return 0;
}
/* �������ܣ�����n��ѧ���ɼ���ƽ���� */
int Average(int score[], int n) /* Average()�������� */
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum += score[i];
	}
	return  n>0 ? sum/n : -1; 
}
/* �������ܣ�����ѧ��ĳ�ſγɼ���������ɼ�Ϊ��ֵʱ���������룬����ѧ������ */
int ReadScore(int score[])  /* ReadScore()�������� */
{
	int i = -1;         /*i��ʼ��Ϊ-1��ѭ��������1��ɱ�֤�����±��0��ʼ*/
	do{
		i++;
		printf("Input score:");
		scanf("%d", &score[i]);
	}while (score[i] >= 0);    /* ���븺ֵʱ�������� */
	return i;                     /* ����ѧ������ */
}
