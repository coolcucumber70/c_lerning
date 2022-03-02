#include<stdio.h>
static int count=0;
void dg(int a,int b,int n,int res);
int main(){
    int n;
    printf("input person num:\n");
    scanf("%d",&n);
    dg(0,0,n,0);
    printf("res:%d\n",count);
}
void dg(int a,int b,int n,int res){
    if(a>n||b>n){
        return ;
    }
    if(res<0){
        return;
    }
    if(a==n&&b==n){
        count++;
        return;
    }
    dg(a+1,b,n,res+1);
    dg(a,b+1,n,res-1);
} 