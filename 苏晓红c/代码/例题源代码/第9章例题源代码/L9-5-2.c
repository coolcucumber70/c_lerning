#include <stdio.h>
int Fun(int par);
int main()
{
	int arg = 1 ;
	printf("arg = %d\n", arg);	
	arg = Fun(arg);                     /* 传递实参值的拷贝给函数 */
	printf("arg = %d\n", arg);
	return 0;
}
int Fun(int par)
{
	printf("par = %d\n", par);
	par = 2;                             /* 改变形参的值 */
	return par;
}
