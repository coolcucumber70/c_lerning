#include <stdio.h>
int main()
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa, *pb;       /* ����ָ�����pa��pb */
    char *pc;            /* ����ָ�����pc */
    pa = &a;             /* ��ʼ��ָ�����paʹ��ָ��a */
    pb = &b;             /* ��ʼ��ָ�����pbʹ��ָ��b */
    pc = &c;             /* ��ʼ��ָ�����pcʹ��ָ��c */
	printf("a is %d, &a is %p, pa is %p, &pa is %p\n", a, &a, pa, &pa);
	printf("b is %d, &b is %p, pb is %p, &pb is %p\n", b, &b, pb, &pb);
	printf("c is %c, &c is %p, pc is %p, &pc is %p\n", c, &c, pc, &pc);
	return 0;
}
