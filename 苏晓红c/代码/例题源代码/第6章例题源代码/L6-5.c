#include  <stdio.h>
main()
{ 
	int i, j;	
	for (i=0; i<3; i++)           /* �������ѭ��ִ��3�� */
	{
		printf("i=%d: ", i);
		for (j=0; j<4; j++)     /* �����ڲ�ѭ��ִ��4�� */
		{
			printf("j=%d ", j);
		}
		printf("\n");
	}
}
