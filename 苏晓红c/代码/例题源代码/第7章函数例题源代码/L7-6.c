#include <stdio.h>
#define N 10
static int mem[N+1];
long Fib(int a);
int main()
{
	    int n, i, x;
	   printf("Input n:");
	   scanf("%d",&n);
	   for (i=1; i<=n; i++)
	   {
		   x = Fib(i);    /* ���õݹ麯��Fib()����Fibonacci���еĵ�n�� */
		   printf("Fib(%d)=%d\n", i, x);
	   }	
	   return 0;

}
/* �������ܣ��õݹ鷨����Fibonacci�����еĵ�n���ֵ */
long Fib(int n)
{
	if (n == 0)         return 0;          /* ������� */
	else if (n == 1)   return 1;          /* ������� */
	else if(mem[n]!=0) return mem[n];
	else{
		mem[n]=(Fib(n-1) + Fib(n-2));
		return mem[n];
	}
	
}
//��θ��ļ��仯����������
