#include  <stdio.h>
typedef struct sample
{
	char  m1;
	int   m2;
	char  m3;
}SAMPLE;                         /* ����ṹ������SAMPLE */
int main()
{
	SAMPLE s = {'a', 2, 'b'};		/* ����ṹ�����s��������г�ʼ�� */
	printf("bytes = %d\n", sizeof(s));/* ��ӡ�ṹ�����s��ռ�ڴ��ֽ��� */
	return 0;
}
