#include  <stdio.h>
main()
{
	int      n = 256;
	float    f = 3.6;
	double   d = 2.5;
	n = f;
	f = n;
	d = f;	
	printf("n = %d\n", n);	
	printf("f = %f\n", f);	
	printf("d = %f\n", d);
}
