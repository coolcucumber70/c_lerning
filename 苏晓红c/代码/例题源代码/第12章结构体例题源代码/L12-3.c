#include  <stdio.h>
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
int main()
{
	int i, j, sum[30];
	STUDENT stu[30] = {{100310121,"����",'M',{1991,5,19},{72,83,90,82}},
	{100310122,"��С��",'M',{1992,8,20},{88,92,78,78}},
	{100310123,"������",'F',{1991,9,19},{98,72,89,66}},
	{100310124,"������",'F',{1992,3,22},{87,95,78,90}}
	};
	for (i=0; i<4; i++)
	{
		sum[i] = 0;
		for (j=0; j<4; j++)
		{
			sum[i] = sum[i] + stu[i].score[j];
		}
		printf("%10ld%8s%3c%6d/%02d/%02d%4d%4d%4d%4d%6.1f\n", 
			stu[i].studentID, 
			stu[i].studentName,
			stu[i].studentSex,
			stu[i].birthday.year,
			stu[i].birthday.month,
			stu[i].birthday.day,
			stu[i].score[0],
			stu[i].score[1],
			stu[i].score[2],
			stu[i].score[3],    
			sum[i]/4.0);
	}
	return 0;
}
