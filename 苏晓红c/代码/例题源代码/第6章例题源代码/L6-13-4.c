#include <stdio.h>
main()
{
	int  x;                        
	int find = 0;                      /* ���ҵ���־����Ϊ�� */
	for (x=1; !find; x++)             /* findΪ��ʱ����ѭ�� */
	{
		if (x%5==1 && x%6==5 && x%7==4 && x%11==10)
		{
			printf("x = %d\n", x);
			find = 1;                 /* ���ҵ���־����Ϊ�� */
		}
	}
}
