#include <stdio.h>
main()
{ 
	float term, result = 1;  
	int n;
	for (n=2; n<=100; n=n+2)
	{
		term = (double)(n * n) / (( n - 1) * ( n + 1));   
		result = result * term;
	}
	printf("pi = %f\n", 2 * result);
}
//考虑这种溢出问题啊
