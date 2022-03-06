#include<stdio.h>
#define N 10
void inputMatrix(int a[N][N],int n);
int addDiagonal(int a[N][N],int n);
int main(){
    int a[N][N],n,sum;
    printf("input n:\n");
    scanf("%d",&n);
    inputMatrix(a,n);
    sum=addDiagonal(a,n);
    printf("sum=%d\n",sum);
}
void inputMatrix(int a[N][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
int addDiagonal(int a[N][N],int n){
    int i,sum=0;
    for(i=0;i<n;i++){
        sum+=a[i][i]+a[i][n-1-i];
    }
    return sum;
}
