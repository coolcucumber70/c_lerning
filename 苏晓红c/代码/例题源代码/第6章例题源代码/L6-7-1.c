#include  <stdlib.h>
#include  <stdio.h>
main()
{      
	int  magic;                       /* �����"��"���� */
	int  guess;              	         /* �û��µ��� */
	int  counter = 0;                /* ����������¼�û��µĴ�������ʼ��Ϊ0 */
	magic = rand() % 100 + 1;      /* ����һ��1��100֮�������� */	
	do{
		printf("Please guess a magic number:");
		scanf("%d", &guess);      	/* �����û��µ���guess */
		counter++;                 	/* ����������count��1 */
		if (guess > magic)          
			printf("Wrong! Too high!\n");
		else if (guess < magic)       
			printf("Wrong! Too small!\n");
		else
			printf("Right!\n");
	}while (guess != magic);              /* ִ��ѭ��ֱ���¶�Ϊֹ */                  
	printf("counter = %d\n", counter);  /* ��ӡ�û������Ĵ���count */
}
