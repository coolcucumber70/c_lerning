#include <stdio.h>
main()
{
	int i, n;
	long sum = 0, p = 1;   /* �ۼ���ͼ��۳���������ֱ��ʼ��Ϊ0��1 */
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		p = p * i;      /* �����ۼ����ͨ� */
		sum = sum + p;
	}	
	printf("1!+2!+��+%d! = %ld\n", n, sum);
}
