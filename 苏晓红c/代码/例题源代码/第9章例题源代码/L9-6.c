#include  <stdio.h>
void  Swap(int *x, int *y);
int main()
{
	int  a, b;
	printf("Please enter a,b:");
	scanf("%d,%d", &a, &b);              
	printf("Before swap: a = %d, b = %d\n", a, b);/* ��ӡ����ǰ��a,b */
	Swap(&a, &b);                                  /* ����ַ���ú���Swap() */
	printf("After swap: a = %d, b = %d\n", a, b);/* ��֤a,b�Ƿ񻥻� */
	return 0;
}
/* �������ܣ�����������������ֵ */
void  Swap(int *x, int *y)                
{
	int  temp;
	temp = *x;            /* ִ��ͼ7-5(b)�еĲ���� */              
	*x = *y;                /* ִ��ͼ7-5(b)�еĲ���� */
	*y = temp;            /* ִ��ͼ7-5(b)�еĲ���� */
}
