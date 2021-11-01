#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#define MaxSize 100
#define INF 2147483647;

//栈与队列
typedef struct SqStack{
    int data[MaxSize];
    int top;
} SqStack;
void initStack(SqStack* st);
int isEmpty(SqStack* st);
int push(SqStack* st, int x);
int pop(SqStack* st, int* x);
typedef struct MyStack
{
    int data1[MaxSize];
    int data2[MaxSize];
    int top1;
    int top2;
} MyStack;//利用单调栈设计的可以读取max值的栈
void initmystack(MyStack s);
void mypush(MyStack*s,int a);
int mypop(MyStack*s);
int maxelement();
typedef struct {
    int data[MaxSize];
    int front;  // 队首指针
    int rear;  // 队尾指针
}SqQueue;
void initQueue(SqQueue* qu);
int isQueueEmpty(SqQueue* qu);
int enQueue(SqQueue* qu, int x);
int deQueue(SqQueue* qu, int* x);
int  main()
{
   
    return 0;

}


void initStack(SqStack* st) {
    st->top = -1;
}

int isEmpty(SqStack* st) {
    return st->top == -1;
}
int push(SqStack* st, int x) {
    if (st->top == MaxSize) return 0;
    st->data[++st->top] = x;
    return 1;
}
int pop(SqStack* st, int* x) {
    if (st->top == -1) return 0;
    *x = st->data[st->top--];
    return 1;
}

void initQueue(SqQueue* qu) {
    qu->front = qu->rear = 0;  // 队首和队尾指针重合，并且指向0
}


int isQueueEmpty(SqQueue* qu) {
    return qu->front == qu->rear;  // 只要重合，即为空队
}
int enQueue(SqQueue* qu, int x) {
    if ((qu->rear+1)%MaxSize == qu->front) return 0;  // 队满则不能入队
    qu->rear = (qu->rear+1)%MaxSize;  // 若未满，则先移动指针
    qu->data[qu->rear] = x;  // 再放入元素
    return 1;
}
int deQueue(SqQueue* qu, int* x) {
    if (qu->front == qu->rear)  return 0;  // 若队空，则不能删除
    qu->front = (qu->front+1)%MaxSize;  // 若队不空，则先移动指针
    *x = qu->data[qu->front];  // 再取出元素
    return 1;
}
void initmystack(MyStack s)
{
    s.top1=-1;
    s.top2=-1;
}
void mypush(MyStack*s,int a)
{
    s->top1++;
    s->data1[s->top1]=a;
    if(s->top2==-1|| s->data2[s->top2]<=a)
      s->top2++;
      s->data2[s->top2]=a; 
}
int mypop(MyStack*s)
{
    if(s->data1[s->top1]==s->data2[s->top2])
      s->top2--;
    s->top1--;

    

}
int maxelement(MyStack*s)
{
    
    return s->data2[s->top2];

}
