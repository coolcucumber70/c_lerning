#include <stdio.h>
#include <math.h>
#define EPS  1e-1
main()
{
	float a, b, c;
	printf("Input a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);								
	if (a+b>c && b+c>a && a+c>b)	       
	{
		if (fabs(a-b)<=EPS || fabs(b-c)<=EPS|| fabs(c-a)<=EPS)
		{
			printf("����������\n");
		}
		if (fabs(a*a+b*b-c*c)<=EPS	 || fabs(a*a+c*c-b*b)<=EPS
			|| fabs(c*c+b*b-a*a)<=EPS)      
		{
			printf("ֱ��������\n");
		}
		else                       
		{
			printf("һ��������\n");
		}
	}
	else                                  
	{
		printf("����������\n");
	}
}
