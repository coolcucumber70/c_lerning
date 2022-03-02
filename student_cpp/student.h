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
	long  studentID;			/* 学号 */
	char  studentName[10];	     /* 姓名 */
	char  studentSex;			/* 性别 */
	DATE  birthday;			     /* 出生日期 */
	int	score[4];		         /* 4门课程的成绩 */
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], float aver[], int n, int m);
void PrintScore(STUDENT stu[], float aver[], int n, int m);



