#include <stdio.h>
unsigned long  Fact(unsigned int  n);           
int main()
{
	int  m;
	do{
		printf("Input m(m>0):");
		scanf("%d", &m);
	}while (m<0);	    /* ���Ӷ��������ݵ����ƣ�ȷ�����������Ϊ�޷������� */
	printf("%d! = %lu\n", m, Fact(m)); /* �޷��ų����͸�ʽ����׳�ֵ */
	return 0;
}
/*�������ܣ��õ����������޷������ͱ���n�Ľ׳ˣ���n>=0ʱ����n!�����򷵻�-1 */
unsigned long  Fact(unsigned int  n)
{
	unsigned int  i;
    unsigned long result = 1;
    for (i=2; i<=n; i++)  
		result *= i;
    return result;
}
