#include <stdio.h>
main()
{
	int  x = 0;       /* ��do-whileѭ�����ȶ�x��1��������x��ʼ��Ϊ0 */
	do{
	   x++;
	}while (!(x%5==1 && x%6==5 && x%7==4 && x%11==10)); 	
	printf("x = %d\n", x); 
}
