#include <stdio.h>
#include  <math.h>
main()
{ 
	float  a, b, c, s;
	float area;                
	printf("Input a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);
	s = (float)(a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("area = %f\n", area);
}
