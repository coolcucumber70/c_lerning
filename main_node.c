#include<stdio.h>
void NewSequence(int a[],int n);

int main()
{
    int a[10]={3,1,5,4,9,7,8,6,2,10};
    NewSequence(a,10);
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }

}
void NewSequence(int a[],int n)
{
    int p=0,q=1;
    int tmp;
    while(p<n&&q<n+1)
    {
        while(a[p]%2==0)
        {
            p=p+2;
        }
        while (a[q]%2==1)
        {
            q=q+2;
        }
        tmp=a[p];
        a[p]=a[q];
        a[q]=tmp;
        p=p+2;
        q=q+2;

        
    }
}