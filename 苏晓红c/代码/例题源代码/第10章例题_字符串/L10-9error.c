#include <stdio.h>
#include <ctype.h>
#define N 80
int main()
{
	char name[N];
	int i;
	printf("Input a name:");
	gets(name);                    /* ���������� */
	name[0] = toupper(name[0]); /* ����������ĸ��Ϊ��д */
	i = 1;
	while (!isspace(name[i]))    /* ����������ĸ��ֱ�����ո�Ϊֹ */ 
	{
		i++;
	}
	while (!isalpha(name[i]))    /* �������пո�ֱ������ĸΪֹ */
	{
		i++;
	}
	name[i] = toupper(name[i]); /* ���յ�����ĸ��Ϊ��д */
	printf("Formatted Name:%s\n", name);
	return 0;
}
