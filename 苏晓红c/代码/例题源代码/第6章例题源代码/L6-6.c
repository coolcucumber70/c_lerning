#include  <stdlib.h>
#include  <stdio.h>
main()
{ 
	int  magic;               /* �����"��"���� */
	int  guess;               /* �û��µ��� */
	magic = rand()/10;          /* �����������"��"һ����magic */
	printf("Please guess a magic number:");
	scanf("%d", &guess);    /* �����û��µ���guess */
	if (guess > magic)   	  /*��guess>magic������ʾ"Wrong!Too big"*/
		printf("Wrong! Too big!\n"); 
	else if (guess < magic)/*��guess<magic������ʾ"Wrong!Too small"*/  
		printf("Wrong! Too small!\n"); 
	else           	      /* ������ʾ"Right!"����ӡ����� */ 
		printf("Right!\n"); 
}
