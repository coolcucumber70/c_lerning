#include <stdio.h>
main()
{
	int  i, n, sum;
	printf("Input n:");
	scanf("%d", &n);
	sum = 0;                    /* �ۼӺͱ�����ʼ��Ϊ0 */
	i = 1;
	while (i <= n)
	{
		sum = sum + i;          /* ���ۼ����� */
		i++;	/* �ۼӼ�������1 */
	} 
	printf("sum = %d\n", sum);
}
