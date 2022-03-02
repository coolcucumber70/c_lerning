#include <stdio.h>
main()
{
	int   i, n;          
	long  p = 1;        
	printf("Please enter n:");
	scanf("%d", &n);               	
	for (i=1; i<=n; i++)           	
	{
		p = p * i;                  	
		printf("%d! = %ld\n", i, p); 	/* 输出1～n之间的所有数的阶乘值 */
	}
}
