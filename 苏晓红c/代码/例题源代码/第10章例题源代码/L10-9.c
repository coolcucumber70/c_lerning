#include <stdio.h>
#include <ctype.h>
#define N 80
int main()
{
	char name[N];
	int i;
	printf("Input a name:");
	gets(name);                    /* ���������� */
	i = 0;
	while(!isalpha(name[i]))     /* �������пո�ֱ������ĸΪֹ */
	{
		i++;
	}
	name[i] = toupper(name[i]); /* ����������ĸ��Ϊ��д */
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
