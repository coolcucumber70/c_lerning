#include <stdio.h>
#define N 40
int Average(int score[], int n);     /* Average()����ԭ�� */
void ReadScore(int score[], int n); /* ReadScore()����ԭ�� */
int main()
{
	int score[N], aver, n;
	printf("Input n:");
	scanf("%d", &n);
	ReadScore(score, n);          /* ��������Ϊ����ʵ�ε��ú���ReadScore() */
	aver = Average(score, n);    /* ��������Ϊ����ʵ�ε��ú���Average() */
	printf("Average score is %d\n",aver);
	return 0;
}
/* �������ܣ� ����n��ѧ���ɼ���ƽ���� */
int Average(int score[], int n) /* Average()�������� */
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum += score[i];
	}
	return  sum / n;
}
/* �������ܣ�����n��ѧ����ĳ�ſγɼ� */
void ReadScore(int score[], int n)  /* ReadScore()�������� */
{
	int i;
	printf("Input score:");
	for (i=0; i<n; i++)
	{
		scanf("%d", &score[i]);
	}
}
