#include  <stdio.h>
main()
{
	int a, b, max, ret;
	printf("Input a, b:");
	ret = scanf("%d,%d",&a, &b); /* ��¼scanf�����ķ���ֵ */
	if (ret != 2)  /* ����scanf��������ֵ,�ж��������ݸ������߸�ʽ�Ƿ���� */
	{
		printf("Input data quantity or format error!\n");
		while(getchar() != '\n');  /* ������뻺�����еĴ������� */
	}
	else             /* �˴���������ȷ�������ݺ�Ӧ��ִ�еĲ��� */
	{
		max = a > b ? a : b;
		printf("max = %d\n", max);
	}
}
