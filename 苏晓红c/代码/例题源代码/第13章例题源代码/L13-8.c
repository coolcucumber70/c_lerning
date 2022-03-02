#include  <stdio.h>
#include  <stdlib.h>
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
void SearchinFile(char fileName[], long k);
int main()
{
	long k;
	printf("Input the searching record number:");
	scanf("%ld", &k);	
	SearchinFile("student.txt", k);
	return 0;
}
/* ���ļ�fileName�в��Ҳ���ʾ��k����¼������ */
void SearchinFile(char fileName[], long k)
{
	FILE *fp;
	int j;
	STUDENT stu;
	if ((fp = fopen(fileName,"r")) == NULL) /* �Զ���ʽ���ı��ļ� */
	{ 
		printf("Failure to open %s!\n", fileName);
		exit(0);
	}
	fseek(fp, (k-1)*sizeof(STUDENT), SEEK_SET);
	fread(&stu, sizeof(STUDENT), 1, fp); /* �����ݿ���ļ� */	
	printf("%10ld%8s%3c%6d/%02d/%02d", 
		stu.studentID, stu.studentName, stu.studentSex,
		stu.birthday.year, stu.birthday.month, stu.birthday.day);
	for (j=0; j<4; j++)
	{
		printf("%4d", stu.score[j]);
	}
	printf("%6.1f\n", stu.aver);	
	fclose(fp);		
}
