#include <stdio.h>
#define N 12
int main()
{
	char  name[N];
	printf("Enter your name:");
    scanf("%s", name);
	printf("Hello %s!\n",name);
	scanf("%s", name);          /* ��ȡ���뻺���������µ��ϴ�δ�����ߵ��ַ� */
	printf("Hello %s!\n",name);
	return 0;
}
