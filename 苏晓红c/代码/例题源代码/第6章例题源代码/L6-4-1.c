#include <stdio.h>
main()
{
	int  i, j, n;
	long p, sum = 0;                /* �ۼ���ͱ���sum��ʼ��Ϊ0 */
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		p = 1;           /* ÿ��ѭ��֮ǰ��Ҫ���۳��������p��ֵΪ1 */
		for (j=1; j<=i; j++)
		{
			p = p * j;               /* �۳���� */
		}
		sum = sum + p;               /* �ۼ���� */
	}	
	printf("1!+2!+��+%d! = %ld\n", n, sum);
}
