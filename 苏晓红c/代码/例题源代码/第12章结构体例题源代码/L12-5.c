#include  <stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
void Func(struct date *pt)  /* �ṹ��ָ������������β� */
{
	pt->year = 2000;
	pt->month = 5;
	pt->day = 22;
}
int main()
{
	struct date d;
	d.year = 1999;
	d.month = 4;
	d.day = 23;
	printf("Before function call:%d/%02d/%02d\n", d.year, d.month, d.day);
	Func(&d);              /* �ṹ������ĵ�ַ������ʵ�Σ�����ַ���� */
	printf("After function call:%d/%02d/%02d\n", d.year, d.month, d.day);
	return 0;
}
