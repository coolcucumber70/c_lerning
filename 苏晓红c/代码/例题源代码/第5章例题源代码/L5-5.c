#include  <stdio.h>
main()
{
	int    data1, data2;          
	char  op;                      
	printf("Please enter an expression:");
	scanf("%d%c%d", &data1, &op, &data2);  /* ����������ʽ */
	switch (op)                        /* ��������������ȷ��ִ�е����� */
	{
	case '+':                         /* �ӷ����� */
		printf("%d + %d = %d \n", data1, data2, data1 + data2); 
		break;
	case '-':                         /* �������� */
		printf("%d - %d = %d \n", data1, data2, data1 - data2);
		break;
	case '*':                         /* �˷����� */
		printf("%d * %d = %d \n", data1, data2, data1 * data2); 
		break;
	case '/':                         /* �������� */
		if (0 == data2)         /* Ϊ�����0���󣬼�������Ƿ�Ϊ0 */
			printf("Division by zero!\n");
		else  
			printf("%d / %d = %d \n", data1, data2, data1 / data2); 
		break;
	default:                          /* ����Ƿ������ */
		printf("Invalid operator! \n");
	}
}
