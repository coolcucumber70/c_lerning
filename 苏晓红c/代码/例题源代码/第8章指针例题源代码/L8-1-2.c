#include <stdio.h>
int main()
{
	int score[5]; 
	int totalScore = 0;
	int i;
	printf("Input the scores of ten students:\n");
	for (i=0; i<5; i++)
	{
		scanf("%d", &score[i]);
		totalScore = totalScore + score[i];
	}
	printf("The average score is %f\n", totalScore/5.0);
	return 0;
}
