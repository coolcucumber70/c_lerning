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
	long  studentID;			/* 学号 */
	char  studentName[10];	     /* 姓名 */
	char  studentSex;			/* 性别 */
	DATE  birthday;			     /* 出生日期 */
	int	  score[4];		         /* 4门课程的成绩 */
	float aver;                   /* 平均分 */
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
/*从文件中读取学生的学号、姓名、性别、出生日期及成绩到结构体数组stu中*/
void ReadfromFile(STUDENT stu[], int *n, int *m)
{
	FILE *fp;
	int i, j;
	if ((fp = fopen("score.txt","r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		exit(0);
	}
    fscanf(fp, "%d\t%d", n, m); /* 从文件中读出学生人数和课程门数 */
	for (i=0; i<*n; i++)    /*学生人数保存在n指向的存储单元*/
	{
		fscanf(fp, "%10ld", &stu[i].studentID);
		fscanf(fp, "%8s", stu[i].studentName);
		fscanf(fp, " %c", &stu[i].studentSex); /* %c前有一个空格 */
		fscanf(fp, "%6d/%2d/%2d", &stu[i].birthday.year,
&stu[i].birthday.month,
&stu[i].birthday.day);
		for (j=0; j<*m; j++) /*课程门数保存在m指向的存储单元*/
		{
			fscanf(fp, "%4d", &stu[i].score[j]);
		}
		fscanf(fp, "%f", &stu[i].aver);      /* 不能使用%6.1f格式 */
	}
	fclose(fp);

}
/* 输出n个学生的学号、姓名、性别、出生日期、m门课程的成绩及平均分到屏幕上 */
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
