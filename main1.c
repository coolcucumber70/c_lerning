#include<stdio.h>
void myquicksort(int a[],int l,int r)
{
    int tmp=a[l];
    int p=l,q=r;
    if(r<=l)return;
    while(l<r)
    {
        if(tmp<a[r]&&(l<r))
        {
            r--;
        }
        a[l]=a[r];
        if(a[l]<=tmp&&(l<r))
        {
            l++;
        }
        a[r]=a[l];

    }
    a[l]=tmp;
    myquicksort(a,p,l-1);
    myquicksort(a,l+1,q);
}
int main()
{
    int a[9]={4,6,2,3,9,1,8,5,7};
    int i;
    myquicksort(a,0,8);
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
}