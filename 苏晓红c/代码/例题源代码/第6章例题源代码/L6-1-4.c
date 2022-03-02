#include <stdio.h>
main()
{
	int  i, j, n, sum = 0;
	printf("Input n:");
	scanf("%d", &n);
	for (i=1, j=n; i<=j; i++, j--)
	{
		sum = sum + i + j;	
	} 
	printf("sum = %d\n", sum);
}
