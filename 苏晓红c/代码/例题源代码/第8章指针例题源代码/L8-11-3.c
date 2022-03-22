#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);          /*ReadScore()����ԭ��*/
int BinSearch(long num[], long x, int n);        /*BinSearch()ԭ������*/ 
void DataSort(int score[], long num[], int n);   /*DataSort()����ԭ��*/
void PrintScore(int score[], long num[], int n); /*PrintScore()����ԭ��*/

int main()
{
	int score[N], n, pos;
	long num[N],x;
	n = ReadScore(score, num);  /* ����ɼ���ѧ�ţ�����ѧ������ */
	printf("Total students are %d\n",n);
	DataSort(score, num, n);
	printf("Sorted scores:\n");
	PrintScore(score, num, n); /* ����ɼ������� */
	printf("Input the searching ID:");
	scanf("%ld", &x);          	 /*�Գ����͸�ʽ�Ӽ�����������ҵ�ѧ��x*/
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
	int  low, high, mid;
	int pos = -1;           	/* ��ѭ��������δ�ҵ����򷵻�pos�ĳ�ʼֵ-1 */
	int find = 0;           	/* ���ҵ���־����flagΪ�� */
	low = 0;                     /* ������˵���Ϊ0 */
	high = n - 1;            	/* �����Ҷ˵���Ϊn-1 */
	while (!find && low <= high)  /* ����˵�С�ڵ����Ҷ˵㣬��������� */
	{
		mid = (high + low) / 2;  /* ȡ����������е� */
		if (x > num[mid])   
		{
			low = mid + 1;       /* ��x>num[mid]�����޸��������˵� */
		}
		else  if (x < num[mid])  
		{
			high = mid - 1; 	/* ��x<num[mid]�����޸�������Ҷ˵� */
		}
		else  
		{
			pos = mid;           /* ���ҵ��������±�ֵΪmid */
			find = 1;            /* ���ҵ���־����flagΪ�� */
		}
	}
	return pos;                    
}
/* �������ܣ���ѡ�񷨽�����num��Ԫ��ֵ����С�������� */
void DataSort(int score[], long num[], int n) /*DataSort()��������*/
{
	int i, j, k, temp1;
	long temp2;
	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)      
		{
			if (num[j] < num[k])     /* ������num��Ԫ��ֵ��С�������� */
			{
				k = j;                 /* ��¼������±�λ�� */
			}
		}
		if (k != i)                  /* ������������±�λ��i */
		{    
			/* �����ɼ� */
			temp1 = score[k]; score[k] = score[i];  score[i] = temp1;
			/* ����ѧ�� */
			temp2 = num[k]; num[k] = num[i];  num[i] = temp2; 
		}  
	}  
}
/*�������ܣ� ��ӡѧ��ѧ�źͳɼ�*/
void PrintScore(int score[], long num[], int n) /*PrintScore()��������*/
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10ld%4d\n", num[i], score[i]); /*�Գ����͸�ʽ����ѧ��*/
	}
}
