#include  <stdio.h>
#define  PI  3.14159       /* ����곣��PI */
main()
{
	double r;
	printf("Input r:");
	scanf("%lf", &r);     
	printf("circumference = %f\n", 2*PI*r); /*����ʱPI���滻Ϊ3.14159*/	
	printf("area = %f\n", PI*r*r); /*����ʱPI���滻Ϊ3.14159*/		
}
