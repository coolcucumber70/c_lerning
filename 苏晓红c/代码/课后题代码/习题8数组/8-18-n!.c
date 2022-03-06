#include<stdio.h>
#define N 51
int BigFact(int m,int data[],int index);
int main(){
    int i,j,n,index=1;
    printf("input:\n");
    scanf("%d",&n);
    int data[N]={0};
    data[1]=1;
    for(i=1;i<=n;i++){
        index=BigFact(i,data,index);
        printf("%d!= ",i);
        for(j=index;j>0;j--){
            printf("%d",data[j]);
        }
        printf("\n");
    }
}
int BigFact(int m,int data[],int index){
    int i,j;
    for(i=1;i<=index;i++){
        data[i]=data[i]*m;
    }
    for(j=1;j<index;j++){
        data[j+1]=data[j+1]+data[j]/10;
        data[j]=data[j]%10;
    }
    while(data[index]>=10&&index<N){
        data[index+1]=data[index]/10;
        data[index]=data[index]%10;
        index++;
    }
    return index;
}
