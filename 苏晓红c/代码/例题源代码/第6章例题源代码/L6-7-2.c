#include  <stdlib.h>
#include  <stdio.h>
main()
{
	int  magic, i;                
	srand(2);                    /* �������������Ϊ1 */
	for (i=0; i<10; i++)
	{
	     magic = rand() % 100 + 1;
         printf("%d ", magic);
	}
	printf("\n");	
}
