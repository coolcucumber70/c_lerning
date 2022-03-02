#include  <stdio.h>
main()
{
	int a, b, max;
	printf("Input a, b:");
	scanf("%d,%d", &a, &b);
	max = a > b ? a : b;
	printf("max = %d\n", max);	
}
