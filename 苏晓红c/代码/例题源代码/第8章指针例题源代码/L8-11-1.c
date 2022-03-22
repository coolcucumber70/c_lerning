#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);          /*ReadScore()����ԭ��*/
int BinSearch(long num[], long x, int n);        /*BinSearch()ԭ������*/ 
int main()
{
	int score[N], n, pos;
	long num[N], x;
	n = ReadScore(score, num);  /* ����ɼ���ѧ�ţ�����ѧ������ */
	printf("Total students are %d\n", n);
	printf("Input the searching ID:");
	scanf("%ld", &x);          	 /* �Գ����͸�ʽ�Ӽ�����������ҵ�ѧ��x */
	pos = BinSearch(num, x, n); /* ����ѧ��Ϊnum��ѧ�� */
	if (pos != -1)              	 /* ���ҵ������ӡ����� */
	{  
		printf("score = %d\n", score[pos]); 
	}
	else                      		/* ��δ�ҵ������ӡ"δ�ҵ�"��ʾ��Ϣ*/
	{   
		printf("Not found!\n");    
	}
	return 0;
}
/* �������ܣ�����ѧ����ѧ�ż���ĳ�ſγɼ��������븺ֵʱ���������룬����ѧ������ */
int ReadScore(int score[], long num[]) /* ReadScore()�������� */
{
	int i = -1;         /*i��ʼ��Ϊ-1��ѭ��������1��ɱ�֤�����±��0��ʼ*/
	do{
		i++;
		printf("Input student's ID and score:");
		scanf("%ld%d", &num[i], &score[i]);
	} while (num[i] >0 && score[i] >= 0); /* ���븺ֵʱ�����ɼ����� */
	return i;                                   /* ����ѧ������ */
}
/*���۰���ҷ�����ֵΪx������Ԫ�أ����ҵ��򷵻�x�������е��±�λ�ã����򷵻�-1*/
int BinSearch(long num[], long x, int n) /*BinSearch()��������*/
{
	int  low=0, high=n-1, mid;  /* ������˵�low��Ϊ0���Ҷ˵�high��Ϊn-1 */
	while (low <= high)      	  /* ����˵�С�ڵ����Ҷ˵㣬��������� */
	{
		mid = (high + low) / 2;  /* ȡ����������е� */
		if (x > num[mid])   
			low = mid + 1;   /* ��x>num[mid]�����޸��������˵� */
		else  if (x < num[mid])  
			high = mid - 1;  /* ��x<num[mid]�����޸�������Ҷ˵� */
		else  
			return mid;   	   /* ���ҵ����򷵻��±�ֵmid */
	}
	return -1;                  /* ѭ��������δ�ҵ����򷵻�ֵ-1 */
}

