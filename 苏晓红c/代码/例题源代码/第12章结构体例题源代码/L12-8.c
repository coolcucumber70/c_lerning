#include  <stdio.h>
union sample
{
	short  i;
	char   ch;
	float  f;
};                                /* ���干��������union sample��ģ�� */
typedef union sample SAMPLE; /* ����union sample�ı���ΪSAMPLE */

int main()
{
	printf("bytes = %d\n", sizeof(SAMPLE));/*��ӡ������������ռ�ڴ��ֽ���*/
	return 0;
}
