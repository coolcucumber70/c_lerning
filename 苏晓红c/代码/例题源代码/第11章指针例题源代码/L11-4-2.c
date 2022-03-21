#include  <stdio.h>
#include  <string.h>
#define   MAX_LEN  10             /* �ַ�����󳤶� */
#define   N         150            /* �ַ������� */
void SortString(char *ptr[], int n);
int main()
{ 
	int    i, n;
	char   name[N][MAX_LEN];    /* �����ά�ַ����� */
	char   *pStr[N];	         /* �����ַ�ָ������ */
	printf("How many countries?");
	scanf("%d",&n);
	getchar();                    /* �������뻺�����еĻس��� */
	printf("Input their names:\n");
	for (i=0; i<n; i++)   
	{
		pStr[i] = name[i];    /* ��pStr[i]ָ���ά�ַ�����name�ĵ�i�� */ 
		gets(pStr[i]);         /* �����i���ַ�����pStr[i]ָ����ڴ� */ 
	}
	printf("Before sorted:\n");
	printf("pStr[i]   pStr[i] point to   name[i]\n");
	for (i=0; i<n; i++)                  
	{
		printf("%-10p",pStr[i]); /* �������ǰ��n���ַ������׵�ַ */
		printf("%13s%13s\n", pStr[i], name[i]); /* �������ǰ��n���ַ��� */   
	}
	SortString(pStr, n);           /* �ַ������ֵ�˳������ */
	printf("After sorted:\n");
	printf("pStr[i]   pStr[i] point to   name[i]\n");
	for (i=0; i<n; i++)                  
	{
		printf("%-10p",pStr[i]); /* ���������n���ַ������׵�ַ */
		printf("%13s%13s\n", pStr[i], name[i]); /* ���������n���ַ��� */   
	}
	return 0;
}

/*�������ܣ���ָ���������������������ý�����ʵ���ַ������ֵ�˳������ */
void SortString(char *ptr[], int n)
{
	int    i, j;
	char  *temp = NULL;  /* �򽻻������ַ����ĵ�ֵַ����temp����Ϊָ����� */
	for (i=0; i<n-1; i++)         			
	{
		for (j = i+1; j<n; j++)
		{
			if (strcmp(ptr[j], ptr[i]) < 0)  /* ����ָ���ַ�����ָ�� */   
			{ 
				temp = ptr[i];              
				ptr[i] = ptr[j];
				ptr[j] = temp;         			
			}  
		}    
	}  
}
