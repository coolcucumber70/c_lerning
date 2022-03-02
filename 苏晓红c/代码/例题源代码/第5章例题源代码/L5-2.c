#include  <stdio.h>
main()
{
	int a, b, max;
	printf("Input a, b:");
	scanf("%d,%d", &a, &b);
	if (a > b)  max = a;
	else         max = b;           /* 相当于a<=b的情况 */
	printf("max = %d\n", max);	
}
