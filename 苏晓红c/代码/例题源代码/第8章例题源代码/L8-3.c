#include <stdio.h>
void print(int a,int b);
int main()
{
    int a = 1, c = 2, b[5]={0}, i;
    printf("%p, %p, %p\n", b, &c, &a);/* ��ӡ����b������c��a���׵�ַ */
    for (i=0; i<=8; i++)                /* ���±�ֵԽ����������Ԫ�� */
    {
		b[i] = i;
		printf("%d  ", b[i]);
    }
	printf("\nc=%d, a=%d, i=%d\n", c, a, i);
  print(a,c);

	return 0;
}
void print(int a,int b){
  printf("a=%p,b=%p",&a,&b);
  return;
}
