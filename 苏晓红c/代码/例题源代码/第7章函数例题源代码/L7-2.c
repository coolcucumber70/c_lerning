#include <stdio.h>
long  Fact(int  n);           
int main()
{
	int  m;
	long ret;
	printf("Input m:");
	scanf("%d", &m);
	ret = Fact(m);
	if (ret == -1)          /* ���ӶԺ�������ֵ�ļ��� */
		printf("Input data error!\n");
	else
		printf("%d! = %ld\n", m, ret);
	return 0;
}
/* �������ܣ��õ���������n! ��n>=0ʱ������n!��ֵ�����򷵻�-1 */
long  Fact(int  n)
{
	int  i;
    long result = 1;
	if (n < 0)             /* ���ӶԺ�����ڲ����Ϸ��Եļ�� */
    {
		return -1;
	}
    else
    {
        for (i=2; i<=n; i++)  
            result *= i;
        return result;
    }
}
