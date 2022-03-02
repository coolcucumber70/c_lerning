#include<stdio.h>
#include<stdlib.h>
#define N 20
int bubblesort(int a[],int n);
int selectsort(int a[],int n);
int insertsort(int a[],int n);
void quicksort(int a[],int left,int right);
void mergesort(int a[],int left,int right);
void merge(int a[],int left,int mid,int right);
void print(int a[],int n);
int main(){
    int a[N]={20,19,17,18,4,5,2,3,1,6,16,15,7,8,9,10,11,14,12,13};
    print(a,20);
    mergesort(a,0,19);
    //quicksort(a,0,19);
    //bubblesort(a,20);
    //selectsort(a,20);
    //insertsort(a,20);
    print(a,20);
}
int bubblesort(int a[],int n){
    int tmp,flag,i,j;
    for(i=0;i<n;i++){
        flag=1;
        for(j=1;j<n-i;j++){
            if(a[j-1]>a[j]){
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
                flag=0;
            }
        }
        if(flag)return 0;
    }
}
int selectsort(int a[],int n){
    int k=0,i,j,tmp;
    for(i=0;i<n;i++){
        int k=0;
        for(j=0;j<n-i;j++){
            if(a[j]>a[k]){
                k=j;
            }
        }
        tmp=a[k];
        a[k]=a[n-i-1];
        a[n-i-1]=tmp;
    }
    return 0;
}
int insertsort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        int tmp=a[i];
        for(j=i-1;j>=0&&tmp<a[j];j--){
            a[j+1]=a[j];   
        }
        a[j+1]=tmp;

    }
    return 0;

}
void print(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void quicksort(int a[],int left,int right){
    int l=left,r=right;
    int tmp=a[l];
    if(left>=right)return;
    while(l<r){
        
        while(tmp<a[r]&&l<r){
            r--;
        }
        a[l]=a[r];
        while(tmp>a[l]&&l<r){
            l++;
        }
        a[r]=a[l];
    }
    a[l]=tmp;
    quicksort(a,left,l-1);
    quicksort(a,l+1,right);
}
void mergesort(int a[],int left,int right){
    if(left==right)return;
    int mid=(left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);
    merge(a,left,mid,right);
}
void merge(int a[],int left,int mid,int right){
    int* b=(int*)malloc(sizeof(int)*(right-left+1));
    int i;
    for(i=left;i<=right;i++){
        b[i-left]=a[i]; 
    }
    int p=0;
    int q=mid+1-left;
    int n=left;
    while(p<=(mid-left)&&q<=(right-left)){
        if(b[p]<b[q]){
            a[n]=b[p];
            p++;
            n++;
        }
        else{
            a[n]=b[q];
            q++;
            n++;
        }
    }
    while(p<=mid-left){
        a[n]=b[p];
        p++;
        n++;
    }
    while(q<=right-left){
        a[n]=b[q];
        q++;
        n++;
    }
    free(b);
}
