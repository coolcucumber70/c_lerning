#include<stdio.h>
#define N 6
void inputarry(int arry[][N], int n);
void outputarry(int arry[][N],char s[], int n);
void calculate(int arry[][N],char s[],int n);
int main() {
	int n = 2;
	int arry[5][N] = { 0 };
    char s[5];
	printf("Enter No. and score as: MT EN PH\n");
	inputarry(arry, n);
    calculate(arry,s,n);
	printf("NO\tMT\tEN\tPH\tSUM\tV\t>90\n");
	printf("------------------------------------------------------\n");
	outputarry(arry, s,n);
}
void inputarry(int arry[][N], int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < N-2; j++) {
			scanf("%d", &arry[i][j]);
		}
    }
}
void calculate(int arry[][N],char s[],int n){
    int sum;
    int arv;
    int i;
    for(i=0;i<n;i++){
        sum=0;
        arv=0;
        sum=arry[i][1]+arry[i][2]+arry[i][3];
        arv=sum/3;
        arry[i][4]=sum;
        arry[i][5]=arv;
        if(arry[i][1]>90&&arry[i][2]>90&&arry[i][3]>90){
            s[i]='Y';
        }
        else{
            s[i]='N';
        }

    }

}

void outputarry(int arry[][N], char s[],int n) {
	int i;
	for (i = 0; i < n; i++)
	{
	   printf("%d\t%d\t%d\t%d\t%d\t%d\t%c\n", arry[i][0],arry[i][1],arry[i][2],arry[i][3],arry[i][4],arry[i][5],s[i]);
	}
}
