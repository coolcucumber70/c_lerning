#include  <stdio.h>
typedef struct date     
{
	int   year;
	int   month;
	int   day;
}DATE;
typedef struct student
{
	long  studentID;			    /* ѧ�� */
	char  studentName[10];	    /* ���� */
	char  studentSex;			    /* �Ա� */
	DATE  birthday;			    /* �������� */
	int	score[4];		         /* 4�ſγ̵ĳɼ� */
}STUDENT;
int main()
{
	STUDENT stu1, stu2;
	int i;
	printf("Input a record:\n");
	scanf("%ld", &stu1.studentID);
	scanf("%s", stu1.studentName);  /* ����ѧ�������������& */
	scanf(" %c", &stu1.studentSex); /* %cǰ��һ���ո� */
	scanf("%d", &stu1.birthday.year);
	scanf("%d", &stu1.birthday.month);
	scanf("%d", &stu1.birthday.day);
	for (i=0; i<4; i++)
	{
		scanf("%d", &stu1.score[i]);
	}
	stu2 = stu1;                       /* ͬ���͵Ľṹ�����֮��ĸ�ֵ���� */ 
	printf("&stu2 = %p\n", &stu2); /* ��ӡ�ṹ�����stu2�ĵ�ַ */
	printf("%10ld%8s%3c%6d/%02d/%02d%4d%4d%4d%4d\n", 
		stu2.studentID, stu2.studentName, stu2.studentSex, 
		stu2.birthday.year, stu2.birthday.month, stu2.birthday.day,
		stu2.score[0], stu2.score[1], stu2.score[2], stu2.score[3]);    
	return 0;
}
