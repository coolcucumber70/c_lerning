#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#define   EPS 1e-6
main()
{ 
	float  a, b, c, disc, p, q;
	printf("Please enter the coefficients a,b,c:"); 
	scanf("%f,%f,%f", &a, &b, &c);	
	if (fabs(a) <= EPS)         /* a=0ʱ�����"���Ƕ��η���" */
	{
		printf("It is not a quadratic equation!\n");
		exit(0);
	}
	disc = b * b - 4 * a * c; /* �����б�ʽ */
	p = - b / (2 * a);
	q = sqrt(fabs(disc)) / (2 * a);
	if (fabs(disc) <= EPS)    /* �б�ʽ����0ʱ����������ʵ�� */
	{
		printf("x1 = x2 = %.2f\n", p);
	}
	else                      
	{ 
		if (disc > EPS)        /* �б�ʽ����0ʱ�����������ʵ�� */
		{
			printf("x1 = %.2f, x2 = %.2f\n", p+q, p-q);
		}
		else                     /* �б�ʽС��0ʱ������������ */
		{
			printf("x1 = %.2f+%.2fi, ", p, q);
			printf("x2 = %.2f-%.2fi\n", p, q);
		}
	}
}
