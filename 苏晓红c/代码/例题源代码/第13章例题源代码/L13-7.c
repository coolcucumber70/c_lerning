#include  <stdio.h>
#include  <stdlib.h>
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
	int	  score[4];		         /* 4�ſγ̵ĳɼ� */
	float aver;                   /* 4�ſγ̵�ƽ���� */
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], int n, int m);
void WritetoFile(STUDENT stu[], int n);
int  ReadfromFile(STUDENT stu[]);
void PrintScore(STUDENT stu[], int n, int m);
int main()
{
	STUDENT stu[N];
	int n;
	printf("How many student?");
	scanf("%d", &n);
	InputScore(stu, n, 4);
	AverScore(stu, n, 4);
	WritetoFile(stu, n);
	n = ReadfromFile(stu);	
	PrintScore(stu, n, 4);
	return 0;
}
/*�Ӽ�������n��ѧ����ѧ�š��������Ա𡢳��������Լ�m�ſγ̵ĳɼ����ṹ������stu��*/
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
void AverScore(STUDENT stu[], int n, int m)
{
	int i, j, sum[N];
	for (i=0; i<n; i++)
	{
		sum[i] = 0;
		for (j=0; j<m; j++)
		{
			sum[i] = sum[i] + stu[i].score[j];
		}
		stu[i].aver = (float)sum[i]/m;
	}
}
/* ���n��ѧ����ѧ�š��������Ա𡢳��������Լ�m�ſγ̵ĳɼ����ļ�student.txt�� */
void WritetoFile(STUDENT stu[], int n)
{
	FILE *fp;
	if ((fp = fopen("student.txt","w")) == NULL) /* ��д��ʽ���ı��ļ� */
	{ 
		printf("Failure to open student.txt!\n");
		exit(0);
	}	
	fwrite(stu, sizeof(STUDENT), n, fp);           /* �����ݿ�д�ļ� */
	fclose(fp);
}
/*���ļ��ж�ȡѧ����ѧ�š��������Ա𡢳������ڼ��ɼ����ṹ������stu�в�����ѧ����*/
int ReadfromFile(STUDENT stu[])
{
	FILE *fp;
	int i;
	if ((fp = fopen("student.txt","r")) == NULL) /* �Զ���ʽ���ı��ļ� */
	{ 
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	for (i=0; !feof(fp); i++)    
	{
		fread(&stu[i], sizeof(STUDENT), 1, fp); /* �����ݿ���ļ� */
	}
	fclose(fp);
	printf("Total students is %d.\n", i-1); /* �����ļ��е�ѧ����¼�� */
	return i-1;
}
/* ���n��ѧ����ѧ�š��������Ա𡢳������ڡ�m�ſγ̵ĳɼ���ƽ���ֵ���Ļ�� */
void PrintScore(STUDENT stu[], int n, int m)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		printf("%10ld%8s%3c%6d/%02d/%02d", 
			stu[i].studentID, stu[i].studentName, stu[i].studentSex,
			stu[i].birthday.year, stu[i].birthday.month, stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			printf("%4d", stu[i].score[j]);
		}
		printf("%6.1f\n", stu[i].aver);
	}
}
