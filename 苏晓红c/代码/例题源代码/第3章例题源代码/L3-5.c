#include  <stdio.h>
main()
{
	const double PI = 3.14159;    /* ����ʵ�͵�const����PI */
	double r;
	printf("Input r:");
	scanf("%lf", &r);         
	printf("circumference = %f\n", 2*PI*r);	
	printf("area = %f\n", PI*r*r);		
}
