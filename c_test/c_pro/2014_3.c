#include<stdio.h>
#define N 51
void print(int data[],int n,int index);
int main(){
    int n=20,i,j;
    int data[N]={0};
    data[1]=1;
    int index=1;
    for(i=2;i<=n;i++){
        for(j=1;j<=index;j++){
            data[j]=data[j]*i;
        }
        for(j=1;j<=index;j++){
            data[j+1]=data[j+1]+data[j]/10;
            data[j]=data[j]%10;
        }
        if(data[j]!=0){
            index=j;
        }       
        while (data[index]>9&&index<=50)
        {
            data[index+1]=data[index]/10;
            data[index]=data[index]%10;
            index++;
        }
        print(data,i,index);
    }
    

}
void print(int data[],int n,int index){
    printf("%d!=",n);
    int i;
    for(i=index;i>0;i--){
        printf("%d",data[i]);
    }
    printf("\n");
}