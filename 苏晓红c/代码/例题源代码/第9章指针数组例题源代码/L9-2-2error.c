#include <stdio.h>
int main()
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa = NULL, *pb = NULL; /* ����ָ���������NULL�����ʼ�� */
    char *pc = NULL;              /* ����ָ���������NULL�����ʼ�� */
	printf("a is %d, &a is %p, pa is %p\n", a, &a, pa);
	printf("b is %d, &b is %p, pb is %p \n", b, &b, pb);
	printf("c is %c, &c is %p, pc is %p \n", c, &c, pc);
	return 0;
}
