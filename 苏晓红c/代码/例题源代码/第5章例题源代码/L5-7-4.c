#include <stdio.h>
#include <math.h>
#define EPS  1e-1
main()
{
	float a, b, c;
	int flag = 1;                            
	printf("Input a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);								
	if (a+b>c && b+c>a && a+c>b)	      
	{
		if (fabs(a-b)<=EPS && fabs(b-c)<=EPS && fabs(c-a)<=EPS) 
		{
			printf("等边");        	      /* 等边 */
			flag = 0;                       /* 置标志变量flag为0值 */
		}
		else if (fabs(a-b)<=EPS || fabs(b-c)<=EPS|| fabs(c-a)<=EPS)
		{
			printf("等腰");                /* 等腰 */
			flag = 0;                       /* 置标志变量flag为0值 */
		}		
		if (fabs(a*a+b*b-c*c)<=EPS	|| fabs(a*a+c*c-b*b)<=EPS
			|| fabs(c*c+b*b-a*a)<=EPS)      
		{
			printf("直角");
			flag = 0;                 
		}
		if (flag)                       
		{
			printf("一般");
		}
		printf("三角形\n");
	}
	else                                 
	{
		printf("不是三角形\n");
	}
}
