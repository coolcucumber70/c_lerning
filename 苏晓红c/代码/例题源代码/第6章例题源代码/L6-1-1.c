#include <stdio.h>
main()
{
	int  i, n, sum;
	printf("Input n:");
	scanf("%d", &n);
	sum = 0;                     /* �ۼӺͱ�����ʼ��Ϊ0 */
	for (i=1; i<=n; i++)
	{
		sum = sum + i;	      /* ���ۼ����� */
	} 
	printf("sum = %d\n", sum);
}
