#include <stdio.h>
main()
{
	int  x = 0;       /* ��do-whileѭ�����ȶ�x��1��������x��ʼ��Ϊ0 */
	int  find = 0;   /* ��־������ֵ��Ϊ�� */
	do{
		x++;
		find = (x%5==1 && x%6==5 && x%7==4 && x%11==10);
	}while (!find); 	
	printf("x = %d\n", x); 
}
