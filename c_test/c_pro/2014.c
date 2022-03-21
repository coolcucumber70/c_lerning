#include<stdio.h>
#include<stdlib.h>
#define N 15
void caiyanghui(int a[][N],int n);
void printyanghui(int a[][N],int n);
int main(){
    int n;
    int a[15][15]={0};
    printf("input n:\n");
    scanf("%d",&n);
    caiyanghui(a,n);
    printyanghui(a,n);

}
void caiyanghui(int a[][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        a[i][i]=1;
        a[i][0]=1;
    }
    for(i=2;i<n;i++){
        for(j=1;j<i;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }        
    }
}
void printyanghui(int a[][N],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}
