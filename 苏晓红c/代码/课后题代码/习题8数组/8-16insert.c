#include<stdio.h>
#define N 20
void insert(int a[],int n,int x);
int main(){
    int a[N]={0},i,n,x;
    printf("input n:\n");
    scanf("%d",&n);
    printf("input arry:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Input x:\n");
    scanf("%d",&x);
    insert(a,n,x);
    printf("after insert:\n");
    for(i=0;i<n+1;i++){
        printf("%4d",a[i]);
    }
    printf("\n");
    return 0;
}
void insert(int a[],int n,int x){
    int i;
    for(i=n-1;i>=0;i--){
        if(a[i]>x){
            a[i+1]=a[i];
        }
        else{
            a[i+1]=x;
            return;
        }
    }
    a[0]=x;
}