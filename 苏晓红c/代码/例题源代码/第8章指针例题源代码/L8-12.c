#include <stdio.h>
#define STUD_N   40                              /* ���ѧ������ */
#define COURSE_N 3                               /* ���Կ�Ŀ�� */
void ReadScore(int score[][COURSE_N], long num[], int n);       
void  AverforStud(int score[][COURSE_N], int sum[], float aver[], int n);
void  AverforCourse(int score[][COURSE_N], int sum[], float aver[], int n);
void  Print(int score[][COURSE_N], long num[], int sumS[], float averS[], 
			int sumC[],float averC[], int n);
int main()
{
	int   score[STUD_N][COURSE_N], sumS[STUD_N], sumC[STUD_N], n;
	long  num[STUD_N];
	float averS[STUD_N], averC[STUD_N];
	printf("Input the total number of the students(n<=40):");
	scanf("%d", &n);                          /* ����μӿ��Ե�ѧ������ */
	ReadScore(score, num, n);               /* ����n��ѧ����ѧ�źͳɼ� */
	AverforStud(score, sumS, averS, n);   /* ����ÿ��ѧ�����ܷ�ƽ���� */
	AverforCourse(score, sumC, averC, n); /* ����ÿ�ſγ̵��ܷ�ƽ���� */
	Print(score, num, sumS, averS, sumC, averC, n); /* ���ѧ���ɼ� */
	return 0;
}
/* �������ܣ�����n��ѧ����ѧ�ż������ſεĳɼ� */
void ReadScore(int score[][COURSE_N], long num[], int n) 
{
	int i, j;         
	printf("Input student's ID and score as: MT  EN  PH:\n");
	for (i=0; i<n; i++)                  /* ������ѧ������ѭ�� */
	{
		scanf("%ld", &num[i]);           /* �Գ����͸�ʽ����ÿ��ѧ����ѧ�� */
		for (j=0; j<COURSE_N; j++)      /* �����пγ̽���ѭ�� */
		{
			scanf("%d", &score[i][j]);    /* ����ÿ��ѧ���ĸ��ſγɼ� */
		} 
	} 
}
/* �������ܣ� ����ÿ��ѧ�����ֺܷ�ƽ���� */
void AverforStud(int score[][COURSE_N], int sum[], float aver[], int n) 
{
	int  i, j;
	for (i=0; i<n; i++)
	{
		sum[i] = 0;
		for (j=0; j<COURSE_N; j++)         /* �����пγ̽���ѭ�� */
		{
			sum[i] = sum[i] + score[i][j]; /* �����i��ѧ�����ܷ� */
		}  
		aver[i] = (float)sum[i] / COURSE_N;/* �����i��ѧ����ƽ���� */      
	}  
}
/* �������ܣ�����ÿ�ſγ̵��ֺܷ�ƽ���� */
void  AverforCourse(int score[][COURSE_N], int sum[], float aver[], int n)
{
	int  i, j;
	for (j=0; j<COURSE_N; j++)
	{
		sum[j] = 0;
		for (i=0; i<n; i++)                  /* ������ѧ������ѭ�� */
		{
			sum[j] = sum[j] + score[i][j]; /* �����j�ſγ̵��ܷ� */
		}  
		aver[j] = (float)sum[j] / n;         /* �����j�ſγ̵�ƽ���� */     
	}  
}
/*�������ܣ���ӡÿ��ѧ����ѧ�š����ſγɼ����ֺܷ�ƽ���֣��Լ�ÿ�ſε��ֺܷ�ƽ����*/
void  Print(int score[][COURSE_N], long num[], int sumS[], float averS[], 
			int sumC[], float averC[], int n)
{
	int  i, j;	
	printf("Student's ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
	for (i=0; i<n; i++)                    
	{
		printf("%12ld\t",num[i]);          /* �Գ����͸�ʽ��ӡѧ����ѧ�� */
		for (j=0; j<COURSE_N; j++)
		{
			printf("%4d\t", score[i][j]); /* ��ӡѧ����ÿ�ſγɼ� */        
		}  
		printf("%4d\t%5.1f\n", sumS[i], averS[i]);/*��ӡѧ�����ܷ�ƽ����*/                               
	} 
	printf("SumofCourse \t");               
	for (j=0; j<COURSE_N; j++)              /* ��ӡÿ�ſε��ܷ� */
	{
		printf("%4d\t", sumC[j]);        
	}  
	printf("\nAverofCourse\t");
	for (j=0; j<COURSE_N; j++)              /* ��ӡÿ�ſε�ƽ���� */
	{
		printf("%4.1f\t", averC[j]);        
	}  
	printf("\n");
}
