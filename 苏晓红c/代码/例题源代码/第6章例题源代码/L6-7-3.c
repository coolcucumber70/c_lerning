#include  <stdlib.h>
#include  <stdio.h>
main()
{ 
	int  magic, guess, counter = 0;                    
	unsigned int seed;           		/* ����һ���޷��������ͱ��� */
	printf("Please enter seed:"); 	/* ��ʾ������������� */
	scanf("%u", &seed);				/* ���뺯��srand()����Ҫ�Ĳ��� */
	srand(seed);       	/* Ϊ����rand()������������� */
	magic = rand() % 100 + 1;   
	do{
		printf("Please guess a magic number:");
		scanf("%d", &guess);       
		counter++;               
		if (guess > magic)     
			printf("Wrong! Too big!\n");
		else if (guess < magic)  
			printf("Wrong! Too small!\n");
		else
			printf("Right!\n");
	}while (guess != magic);            
	printf("counter = %d\n", counter); 
}
