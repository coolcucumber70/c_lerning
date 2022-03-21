#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define N 80
void Input(struct student students[], int n);
void Print(struct student *p, int n);
struct student Search(struct student students[], int n, char name[],int* flag);
struct student
{
	char name[N];
	char studentID[N];
	char jiguan[N];
	char ID[N];
	int age;
	char address[N];
	char sex;
	char phone[N];
};
int main()
{
	struct student students[N];
	int n;
	printf("请输入学生的个数:");
	scanf("%d", &n);
	Input(students, n);
	Print(students, n);
	char searchName[N];
	printf("\n请输入想要查找的学生姓名:");
	scanf("%s", searchName);
	int *flag=0;
	//*flag = 0;
	struct student stu = Search(students, n, searchName, flag);
	if (*flag == 1)
	{
		printf("%-8s%-12s%-10s%-20s%-4d%-10s%-3c%-10s\n", stu.name,
			stu.studentID, stu.jiguan, stu.studentID, stu.age, stu.address, stu.sex,
			stu.phone);
	}
	else
	{
		printf("没有该学生的信息！\n\n");
	}
}
void Input(struct student students[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个学生的信息:\n", i + 1);
		printf("姓名:\t");
		//getchar();
		scanf("%s", &students[i].name);
		//getchar();
		printf("学号:\t");
		scanf("%s", &students[i].studentID);
		//getchar();
		printf("籍贯:\t");
		scanf("%s", &students[i].jiguan);
		//getchar();
		printf("身份证号:\t");
		scanf("%s", &students[i].ID);
		//getchar();
		printf("年龄:\t");
		scanf("%d", &students[i].age);
		//getchar();
		printf("家庭住址:\t");
		scanf("%s", &students[i].address);
		getchar();
		printf("性别(M/F):\t");
		scanf("%c", &students[i].sex);
		//getchar();
		printf("电话:\t");
		scanf("%s", &students[i].phone);
		printf("\n");
	}
}
void Print(struct student *p, int n)
{
	printf("姓名学号 籍贯 身份证号 年龄地址 性别电话\n");
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%-8s%-12s%-10s%-20s%-4d%-10s%-3c%-10s\n", p->name, p->studentID,
			p->jiguan, p->ID, p->age, p->address, p->sex, p->phone);
		p++;
	}
}

struct student Search(struct student students[], int n, char name[], int *flag)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(students[i].name, name) == 0)
		{
			*flag = 1;
			return students[i];
		}
	}
}