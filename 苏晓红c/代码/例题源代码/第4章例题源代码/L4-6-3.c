#include <stdio.h>
main()
{
	int    a;
	char  b;
	float  c;
	printf("Please input an integer:");    
	scanf("%d", &a);
	printf("integer: %d\n", a);
	printf("Please input a character:");    
	scanf(" %c", &b); /*��%cǰ���һ���ո񣬽����ڻ������еĻس�������*/
	printf("character: %c\n", b);
	printf("Please input a float number:");    
	scanf("%f", &c);
	printf("float: %f\n", c);	
}
