#include <stdio.h>
long  Fact(int  n);           
int main()
{
	int  m;
	long ret;
	printf("Input m:");
	scanf("%d", &m);
	ret = Fact(m);           
	printf("%d! = %ld\n", m, ret);
	return 0;
}
/* �������ܣ��õ���������n! */
long  Fact(int  n)
{
	int  i;
    long result = 1;
	if (n < 0)             /* ���ӶԺ�����ڲ����Ϸ��Եļ�� */
    {
		printf("Input data error!\n");
	}
    else
    {
        for (i=2; i<=n; i++)  
            result *= i;
        return result;
    }
}
