#include <stdio.h>
int main()
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa = &a, *pb = &b; /* �ڶ���ָ�����pa��pb��ͬʱ�����ʼ�� */
    char *pc = &c;            /* �ڶ���ָ�����pc��ͬʱ�����ʼ�� */
	printf("a is %d, &a is %p, pa is %p, *pa is %d\n", a, &a, pa, *pa);
	printf("b is %d, &b is %p, pb is %p, *pb is %d\n", b, &b, pb, *pb);
	printf("c is %c, &c is %p, pc is %p, *pc is %c\n", c, &c, pc, *pc);
	return 0;
}
