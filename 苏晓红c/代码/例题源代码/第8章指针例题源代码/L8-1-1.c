#include <stdio.h>
int main()
{
	  int score1, score2, score3, score4, score5; 
	  int totalScore;
	  printf("Input the scores of ten students:\n");
	  scanf("%d", &score1);
	  scanf("%d", &score2);
	  scanf("%d", &score3);
	  scanf("%d", &score4);
	  scanf("%d", &score5);
	  totalScore = score1 + score2 + score3 +score4 + score5;
	  printf("The average score is %f\n", totalScore/5.0);
      return 0;
}
