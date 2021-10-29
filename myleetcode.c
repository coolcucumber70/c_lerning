#include<stdio.h>
#define maxsize 100
typedef struct MyQueue
{
    int data[maxsize];
    int front ;
    int rear;
} MyQueue;
void initMyqueue(MyQueue*q)
{
    q->front=0;
    q->rear=0;
}
void pushr(MyQueue*q,int x)
{
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%maxsize;
    
}
void popr(MyQueue*q)
{
    q->rear=(q->rear-1)%maxsize;

}
void popf(MyQueue*q)
{
    q->front=(q->front+1)%maxsize;
}
int findmaxinwindow(int a[],int n,int k)
{
    int i; 
    MyQueue q;
    initMyqueue(&q);
    pushr(&q,a[0]);
    int result[7]={0};
    for(i=1;i<k;i++)
    {
        if(a[i]<q.data[q.rear-1])
        {
            pushr(&q,a[i]);
        }
        else{
           while(a[i]>q.data[q.rear-1])
        {
            popr(&q);
        }
        pushr(&q,a[i]);
        }
    }
    result[0]=q.data[q.front];
    for(i=1;i<n-k+1;i++)
    {
        if(a[i-1]==q.data[q.front])
        {
            popf(&q);
        }

        if(a[i+k-1]<q.data[q.rear-1])
        {
            pushr(&q,a[i]);
        }
        else{
           while(a[i+k-1]>q.data[q.rear-1])
        {
            popr(&q);
        }
        }
        pushr(&q,a[i+k-1]);
        result[i]=q.data[q.front];
        
    }
    for(i-0;i<n-k+1;i++)
    {
        printf("%d ",result[i]);
    }
}
int main()
{
    int a[10]={1,3,8,9,6,7,2,4,5,10};
    findmaxinwindow(a,10,2);
    return 0;
}
