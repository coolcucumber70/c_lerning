#include  <stdio.h>
#define N 30
typedef struct date     
{
	int   year;
	int   month;
	int   day;
}DATE;
typedef struct student
{
	long  studentID;			/* ѧ�� */
	char  studentName[10];	     /* ���� */
	char  studentSex;			/* �Ա� */
	DATE  birthday;			     /* �������� */
	int	score[4];		         /* 4�ſγ̵ĳɼ� */
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], float aver[], int n, int m);
void PrintScore(STUDENT stu[], float aver[], int n, int m);
int main()
{
	float aver[N];
	STUDENT stu[N];
	int n;
	printf("How many student?");
	scanf("%d", &n);
	InputScore(stu, n, 4);
	AverScore(stu, aver, n, 4);
	PrintScore(stu, aver, n, 4);
	return 0;
}
/* ����n��ѧ����ѧ�š��������Ա𡢳��������Լ�m�ſγ̵ĳɼ����ṹ������stu�� */
void InputScore(STUDENT stu[], int n, int m)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		printf("Input record %d:\n", i+1);
		scanf("%ld", &stu[i].studentID);
		scanf("%s", stu[i].studentName);  
		scanf(" %c", &stu[i].studentSex); /* %cǰ��һ���ո� */
		scanf("%d", &stu[i].birthday.year);
		scanf("%d", &stu[i].birthday.month);
		scanf("%d", &stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			scanf("%d", &stu[i].score[j]);
		}
	}
}
/* ����n��ѧ����m�ſγ̵�ƽ���֣���������aver�� */
void AverScore(STUDENT stu[], float aver[], int n, int m)
{
	int i, j, sum[N];
	for (i=0; i<n; i++)
	{
		sum[i] = 0;
		for (j=0; j<m; j++)
		{
			sum[i] = sum[i] + stu[i].score[j];
		}
		aver[i] = (float)sum[i]/m;
	}
}
/* ���n��ѧ����ѧ�š��������Ա𡢳��������Լ�m�ſγ̵ĳɼ� */
void PrintScore(STUDENT stu[], float aver[], int n, int m)
{
	int i, j;
	printf("Results:\n");
	for (i=0; i<n; i++)
	{
		printf("%10ld%8s%3c%6d/%02d/%02d", stu[i].studentID, 
			stu[i].studentName,
			stu[i].studentSex,
			stu[i].birthday.year,
			stu[i].birthday.month,
			stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			printf("%4d", stu[i].score[j]);
		}
		printf("%6.1f\n", aver[i]);
	}
}
