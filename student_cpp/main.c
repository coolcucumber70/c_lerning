#include"student.h"
#include <mysql/mysql.h>
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