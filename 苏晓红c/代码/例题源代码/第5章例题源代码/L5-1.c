#include  <stdio.h>
main()
{
	int a, b, max;
	printf("Input a, b:");
	scanf("%d,%d", &a, &b);
	if (a > b)  max = a;
	if (a <= b) max = b;
	printf("max = %d\n", max);	
}
