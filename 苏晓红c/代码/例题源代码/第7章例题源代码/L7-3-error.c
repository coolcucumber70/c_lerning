#include <stdio.h>
unsigned long  Fact(unsigned int  n);           
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
/* �������ܣ��õ����������޷������ͱ���n�Ľ׳ˣ���n>=0ʱ����n!�����򷵻�-1 */
unsigned long  Fact(unsigned int  n)
{
	unsigned int  i;
    unsigned long result = 1;
	if (n < 0)             
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
