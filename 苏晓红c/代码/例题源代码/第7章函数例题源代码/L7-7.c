#include <stdio.h>
long Fib(int a);
int count;     /*ȫ�ֱ���count�����ۼƵݹ麯�������õĴ������Զ���ʼ��Ϊ0*/
int main()
{
	   int n, i, x;
	   printf("Input n:");
	   scanf("%d", &n);
	   for (i=1; i<=n; i++)
	   {
		   count = 0;   /* ������һ��Fibonacci����ʱ��������count���� */
		   x = Fib(i);
		   printf("Fib(%d)=%d, count=%d\n", i, x, count);
	   }
	   return 0;
}
/* �������ܣ��õݹ鷨����Fibonacci�����еĵ�n���ֵ */
long Fib(int n)
{
	count++;	  /* �ۼƵݹ麯�������õĴ�������¼��ȫ�ֱ���count�� */
	if (n == 0)         return 0;          /* ������� */
	else if (n == 1)   return 1;          /* ������� */
	else   return (Fib(n-1) + Fib(n-2)); /* һ����� */
	
}
