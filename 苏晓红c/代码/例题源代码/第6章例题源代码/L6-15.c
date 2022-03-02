#include <stdio.h>
main()
{ 
	double term, result = 1;  
	int n;
	for (n=2; n<=100; n=n+2)
	{
		term = (double)(n * n) / ((double)( n - 1) * ( n + 1));  
		result = result * term;
	}
	printf("pi = %f\n", 2 * result);
}
