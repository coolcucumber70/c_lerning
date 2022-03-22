#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_NUMBER 100
#define MIN_NUMBER 1
#define MAX_TIMES  10
int MakeNumber(void);
void GuessNumber(const int number);
int IsValidNum(const int number);
int IsRight(const int number, const int guess);

int main()
{
       int number;                    /* ��������ɵ������ */
	   char reply;                    /* �û������Ƿ���������Ļش� */
	   srand(time(NULL));            /* ��ʼ��������� */
	   do{
		   number = MakeNumber();    /* ���������һ������� */
		   GuessNumber(number);      /* �û������� */
		   printf("Do you want to continue(Y/N or y/n)?");  /*��ʾ�Ƿ����*/
		   scanf(" %c", &reply);               /* %cǰ��һ���ո� */
	   }while (reply=='Y' || reply=='y');   /* ����Y��y�������� */
	   return 0;
}
/* 	�������ܣ�  	�û�������
  	����������  	number�Ǽ�������ɵ���
   	��������ֵ��	��
 */
void GuessNumber(const int number)
{
	   int guess;			/* �û��µ���*/
    int count = 1;		/* �û��µĴ��� */
	   int right = 0;	     /* �µĽ���Դ���� */
	   int ret;                /* ��¼scanf()�ķ���ֵ����������������� */
	   do{
		   printf("Try %d:", count);
		   ret = scanf("%d", &guess);      /* �����û��µ��� */		
		   /* �����û����룬�ж��Ƿ�����������Ƿ��ںϷ�����ֵ��Χ�� */
		   while (ret != 1 || !IsValidNum(guess))
		   {
			   printf("Input error!\n");
			   while (getchar() != '\n'); /* ������뻺�����еĴ������� */
			   printf("Try %d:", count);
		       ret = scanf("%d", &guess); /* �����û��µ��� */
		   }
		   count++;		                      /* ��¼�û��µĴ��� */
		   right = IsRight(number, guess); /* �ж��û��µ����Ǵ���С */
	   }while (!right && count <= MAX_TIMES);
	   if (right)        /* ���û��¶��ˣ��������Ӧ����ʾ��Ϣ */ 
         printf("Congratulations! You're so cool!\n"); 
    else                /* ������MAX_TIMES����δ�¶ԣ������Ӧ����ʾ��Ϣ */ 
         printf("Mission failed after %d attempts.\n", MAX_TIMES);
}

/*	�������ܣ�  	���������һ�������
 	����������  	��
   	��������ֵ��	���ؼ�������ɵ������
 */
int MakeNumber(void)
{
    int number;
    number = (rand() % (MAX_NUMBER - MIN_NUMBER + 1) ) + MIN_NUMBER;
	assert(number >= MIN_NUMBER && number <= MAX_NUMBER);
    return number;
}
/* 	�������ܣ�  	�ж��û��������Ƿ��ںϷ�����ֵ��Χ��1-100��֮��
    ����������  	number���û��������
    ��������ֵ��	���Ϸ����򷵻ط�0ֵ�����򣬷���0
*/
int IsValidNum(const int number)
{
    if (number >= MIN_NUMBER && number <= MAX_NUMBER)
		return 1;
	   else
		   return 0;
}
/* 	�������ܣ� 	�ж�guess��number˭��˭С
                �´��ˣ���ʾ"Wrong! Too high."����С�ˣ���ʾ"Wrong! Too low."
    ���������� 	number�Ǳ��µ�����guess�ǲµ���Ϣ
    ��������ֵ������¶ԣ��򷵻�1�����򣬷���0
*/
int IsRight(const int number, const int guess)
{
	if (guess < number)      /* ����С�ˣ������Ӧ����ʾ��Ϣ */
	{
		printf("Wrong! Too small!\n");
		return 0;
	}
	else if (guess > number) /* ���´��ˣ������Ӧ����ʾ��Ϣ */
	{
		printf("Wrong! Too big!\n");
		return 0;
	}
	else return 1;
}
