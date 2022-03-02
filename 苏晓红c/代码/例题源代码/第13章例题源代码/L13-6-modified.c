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
	float aver;                   /* ƽ���� */
}STUDENT;
void ReadfromFile(STUDENT stu[], int *n, int *m);
void PrintScore(STUDENT stu[], int n, int m);
int main()
{
	STUDENT stu[N];
	int n,  m = 4;
	ReadfromFile(stu, &n, &m);
	PrintScore(stu, n, m);
    return 0;
}
/*���ļ��ж�ȡѧ����ѧ�š��������Ա𡢳������ڼ��ɼ����ṹ������stu��*/
void ReadfromFile(STUDENT stu[], int *n, int *m)
{
	FILE *fp;
	int i, j;
	if ((fp = fopen("score.txt","r")) == NULL) /* �Զ���ʽ���ı��ļ� */
	{
		printf("Failure to open score.txt!\n");
		exit(0);
	}
    fscanf(fp, "%d\t%d", n, m); /* ���ļ��ж���ѧ�������Ϳγ����� */
	for (i=0; i<*n; i++)    /*ѧ������������nָ��Ĵ洢��Ԫ*/
	{
		fscanf(fp, "%10ld", &stu[i].studentID);
		fscanf(fp, "%8s", stu[i].studentName);
		fscanf(fp, " %c", &stu[i].studentSex); /* %cǰ��һ���ո� */
		fscanf(fp, "%6d/%2d/%2d", &stu[i].birthday.year,
&stu[i].birthday.month,
&stu[i].birthday.day);
		for (j=0; j<*m; j++) /*�γ�����������mָ��Ĵ洢��Ԫ*/
		{
			fscanf(fp, "%4d", &stu[i].score[j]);
		}
		fscanf(fp, "%f", &stu[i].aver);      /* ����ʹ��%6.1f��ʽ */
	}
	fclose(fp);

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
