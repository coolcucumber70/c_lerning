#include<stdio.h>
#define M 20
#define N 20
int main(){
    int m,n,i,j;
    int l,r;
    printf("input: m,n\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int dp[M][N]={0};//m代表次数，n代表人数
    dp[0][0]=1;
    for(i=1;i<=m;i++){
        for(j=0;j<n;j++){
            if(j==0){
                l=n-1;
                r=j+1;
            }
            else if(j==n-1){
                l=j-1;
                r=0;
            }
            else{
                l=j-1;
                r=j+1;
            }
            dp[i][j]=dp[i-1][l]+dp[i-1][r];

        }
    }
    //printf("woca");
    printf("cout=%d",dp[m][0]);
    return 0;
}