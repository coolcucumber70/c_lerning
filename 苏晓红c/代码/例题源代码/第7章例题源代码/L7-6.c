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
		   x = Fib(i);    /* 调用递归函数Fib()计算Fibonacci数列的第n项 */
		   printf("Fib(%d)=%d\n", i, x);
	   }	
	   return 0;

}
/* 函数功能：用递归法计算Fibonacci数列中的第n项的值 */
long Fib(int n)
{
	if (n == 0)         return 0;          /* 基线情况 */
	else if (n == 1)   return 1;          /* 基线情况 */
	else if(mem[n]!=0) return mem[n];
	else{
		mem[n]=(Fib(n-1) + Fib(n-2));
		return mem[n];
	}
	
}
//如何更改记忆化搜索的问题
