#include <stdio.h>
main()
{
	int  i, n, sum;
	printf("Input n:");
	scanf("%d", &n);
	sum = 0;                     /* �ۼ���ͱ�����ʼ��Ϊ0 */
	i = 1;
	do{
		sum = sum + i;          /* ���ۼ����� */
		i++;	/* �ۼӼ�������1 */
	}while (i <= n);
	printf("sum = %d\n", sum);
}
