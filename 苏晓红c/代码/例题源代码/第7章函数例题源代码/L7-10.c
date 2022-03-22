#include <stdio.h>
long Func(int n);
int main()
{
	int i, n;
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		printf("%d! = %ld\n", i, Func(i));
	}
	return 0;
}
long Func(int n)
{
	static long p = 1;		/*定义静态局部变量*/
	p = p * n;
	return p;
}
//static 定义的变量其实只会初始化一次的，并且生命周期是main的生命周期

