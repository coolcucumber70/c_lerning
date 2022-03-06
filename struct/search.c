#include<stdio.h>
void get_next(int i);
int 
int Bsearch(int a[],int left,int right,int k)
{
    
    while(left<=right)
    {
    int mid=(left+right)/2;
    if(a[mid]==k)
    {
      return mid;
    }
    else if(a[mid]>k){
        right=mid-1;
    }
    else{
        left=mid+1;
    }
    }
    return -1;
}
int Bsearch_dg(int a[],int left,int right,int k)
{
    if(left>right)return -1;
    int mid=(left+right)/2;
    if(a[mid]==k)return mid;
    else if(a[mid]>k)return Bsearch_dg(a,left,mid-1,k);
    else{
        return Bsearch_dg(a,mid+1,right,k);
    }

}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int result1=Bsearch_dg(a,0,9,7);
    int result2=Bsearch(a,0,9,7);
    printf("result1=%d\n",result1);
    printf("result2=%d\n",result2);
}