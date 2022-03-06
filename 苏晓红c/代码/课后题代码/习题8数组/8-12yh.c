#include<stdio.h>
#define N 20
void createyh(int a[][N],int n);
void printyh(int a[][N],int n);
int main(){
    int i,j,n;
    int a[N][N]={0};
    printf("input n:\n");
    scanf("%d",&n);
    createyh(a,n);
    printyh(a,n); 
}
void createyh(int a[][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2;i<n;i++){
        for(j=1;j<=i-1;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
}
void printyh(int a[][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}