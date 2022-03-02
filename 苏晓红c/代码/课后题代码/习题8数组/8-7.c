#include<stdio.h>
void MaxMinChange(int a[],int n);
void printarry(int a[],int n);
int Median(int a[],int n);//平均数
int Mode(int a[],int n);//众数
int sort(int a[],int n);//排序

int main(){
    int i,a[10];
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    printarry(a,10);
    MaxMinChange(a,10);
    printarry(a,10);

}
void MaxMinChange(int a[],int n){
    int max=0,min=0,i,tmp;
    for(i=0;i<n;i++){
        if(a[max]<a[i])
          max=i;
        if(a[min]>a[i])
          min=i;
    }
    tmp=a[max];
    a[max]=a[min];
    a[min]=tmp;
}
void printarry(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}