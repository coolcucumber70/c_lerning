#include <stdio.h>
long  Fact(int  n);
int main()
{
	int  n;
	long result;
	printf("Input n:");
	scanf("%d", &n);
	result = Fact(n);            /* ���õݹ麯��Fact()����n! */
	if(result == -1)              /* ����Ƿ����� */
		printf("n<0, data error!\n");
	else                            /* ���n!ֵ */
		printf("%d! = %ld\n", n, result);
	return 0;
}
/* �������ܣ��õݹ鷨����n!����n>=0ʱ����n!�����򷵻�-1 */
long  Fact(int  n)
{
	long result = 1;
	if (n < 0)                     /* ����Ƿ����� */
		return -1;
	else if (n==0 || n==1)       /* ������������ݹ���ֹ���� */
		return 1;				   
	else                            /* һ����� */
		return (n * Fact(n-1)); /* �ݹ���ã�����(n-1)!����n! */
}
