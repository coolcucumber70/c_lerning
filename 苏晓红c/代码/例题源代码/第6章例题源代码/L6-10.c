#include  <time.h>  
#include  <stdlib.h>
#include  <stdio.h>      
main()
{ 
	int  magic, guess, counter = 0, ret;		
	char reply;				                   /* �����û�����Ļش� */
	srand(time(NULL));  
	do{
		magic = rand() % 100 + 1;               
		do{
			printf("Please guess a magic number:");
			ret = scanf("%d", &guess);
			while (ret != 1)                 /* ����������������������� */
			{
				while (getchar() != '\n');  /* ������뻺�����еķǷ��ַ� */
				printf("Please guess a magic number:");
				ret = scanf("%d", &guess);      
			}                                             
			counter++;               
			if (guess > magic)    
				printf("Wrong!Too big!\n");
			else if (guess < magic)   
				printf("Wrong!Too small!\n");
			else
				printf("Right!\n");
		} while (guess!=magic && counter<10); /*�²�����δ��10�μ�����*/
		printf("counter = %d\n", counter); 
		printf("Do you want to continue(Y/N or y/n)?"); /*��ʾ�Ƿ����*/
		scanf(" %c", &reply);                  /* %cǰ��һ���ո� */
	}while (reply=='Y' || reply=='y');       /* ����Y��y�������� */
}
