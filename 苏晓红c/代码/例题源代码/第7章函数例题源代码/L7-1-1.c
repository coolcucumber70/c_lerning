#include <stdio.h>
/* �������ܣ��õ���������n! */
long  Fact(int  n)              /* �������� */
{
	int  i;
    long result = 1;
	for (i=2; i<=n; i++)       
	{	
		result *= i;
	}
	return result;
}
main()
{
	int  m;
	long ret;
	printf("Input m:");
	scanf("%d", &m);
	ret = Fact(m);           /* ���ú���Fact()�����������ķ���ֵ����ret */
	printf("%d! = %ld\n", m, ret);
}
