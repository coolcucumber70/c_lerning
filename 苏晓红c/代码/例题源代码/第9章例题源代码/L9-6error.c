#include  <stdio.h>
void  Swap(int x, int y);
int main()
{
	int  a, b;
	printf("Please enter a,b:");
	scanf("%d,%d", &a, &b);              
	printf("Before swap: a = %d, b = %d\n", a, b);/* ��ӡ����ǰ��a,b */
	Swap(a, b);                                      /* ��ֵ���ú���Swap() */
	printf("After swap: a = %d, b = %d\n", a, b);/* ��ӡ�������a,b */
	return 0;
}
void  Swap(int x, int y)                
{
	int  temp;
	temp = *x;            /* ִ��ͼ9-4(b)�еĲ���� */              
	*x = *y;              /* ִ��ͼ9-4(b)�еĲ���� */
	*y = temp;            /* ִ��ͼ9-4(b)�еĲ���� */
}
