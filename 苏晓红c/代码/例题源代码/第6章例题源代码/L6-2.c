#include <stdio.h>
main()
{
	int   i, n;          
	long  p = 1;        /* ��׳�ֵȡֵ��Χ�ϴ󣬹�p����Ϊ�����ͣ�������ֵ1 */
	printf("Please enter n:");
	scanf("%d", &n);               	
	for (i=1; i<=n; i++)           	
	{
		p = p * i;                  	/* ���۳����� */
	}
	printf("%d! = %ld\n", n, p); 	/* �Գ����͸�ʽ���n�Ľ׳�ֵ */
}
