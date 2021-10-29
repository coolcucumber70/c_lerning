#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#define MaxSize 100
#define INF 2147483647;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void InitLirnkList(LNode *list);
void createlistR(LNode **list, int a[], int n);
void createlistF(LNode *list, int a[], int n);
int findAndDelete(LNode *list, int x);
int findknode(LNode*head,int k);//查找倒数k个数据408_2009
void deletesamenode(LNode*head,int n);//408_2015,删除链表中的绝对值相同的节点

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
    int data[MaxSize];
    int max;
    int top;
} MyStack;
void initmystack(MyStack s);
void mypush(MyStack*s,int a);
int mypop();
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
    int a[10]={1,3,9,8,4,1,7,-9,-4,10};
    int b[8]={0,5,5,3,5,1,5,7};
    int s1[5]={11,13,15,17,19};
    int s2[5]={2,4,6,8,20};
    //int result;
    //result=majority(b,8);
    //result=findzhongweishu(s1,s2,5);
    //printf("%d",result);
    // LNode*head=NULL;
    LNode*head=NULL;
    createlistR(&head,a,10);
    LNode*p=head->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    deletesamenode(head,10);
    LNode*q=head->next;
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }

    // printf("\n");
    // // while()
    // int result=findknode(head,3);
    // printf("result=%d\n",result);
    // int i;
    // for(i=0;i<10;i++)
    // {
    //     printf("%d ",a[i]);
    // }
    // printf("\n");
    // reversearry(a,2,10);
    //     for(i=0;i<10;i++)
    // {
    //     printf("%d ",a[i]);
    // }
    // printf("\n");
    return 0;

}

void InitLinkList(LNode *list) {
    assert(list != NULL);
    list->next = NULL;
}
void createlistR(LNode **list, int a[], int n) {
    LNode *s, *r; // s用来指向新申请的节点，r始终指向list的终端节点
    int i;
    *list = (LNode*)malloc(sizeof(LNode));
    (*list)->next = NULL;
    r = *list;
    for ( i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;  // 让当前的终端节点指向新来的节点
        r = r->next;  // 更新r，让r指向新的终端节点
    }
    r->next = NULL;
}
void createlistF(LNode *list, int a[], int n) {
    LNode *s;  // s用来指向新申请的节点
    list = (LNode*)malloc(sizeof(LNode));
    list->next = NULL;
    int i=0;
    for (i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = list->next;
        list->next = s;
    }
}
int findAndDelete(LNode *list, int x) {
    // 先找到该元素
    LNode *p;
    p = list;
    while (p->next != NULL) {
        if (p->next->data == x) {
            break;
        }
        p = p->next;
    }

    // 然后删除
    if (p->next == NULL) {
        return 0;
    } else {
        LNode *del;
        del = p->next;
        p->next = p->next->next;
        free(del);
        return 1;
    }
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
void deletesamenode(LNode*head,int n)
{
    int*a =malloc(sizeof(int)*n+1);
    int i;
    for(i=0;i<n+1;i++)
    {
        a[i]=0;
    }
    LNode* p=head->next;
    LNode* pre=NULL;
    while(p)
    {
        int index=p->data;
        if(index<0){
            index=-index;
        }
        if(a[index]==0)
        {
            a[index]=1;
            pre=p;
            p=p->next;
        }
        else{
            p=p->next;
            free(pre->next);
            pre->next=p;
        }

    }

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
    s.top=-1;
    s.max=-1;
}
void mypush(MyStack*s,int a)
{
    s->top++;
    s->data[s->top]=a;
    if(a>s->max)s->max=a;    
}
int mypop()
{
    return 0;

}
int maxelement()
{
    return 0;

}
int findknode(LNode*head,int k)
{
    LNode*p=head;
    LNode*q=head;
    int i;
    for(i=0;i<k;i++)
    {
        q=q->next;
    }
    while(q)
    {
        p=p->next;
        q=q->next;
    }
    return p->data;
}
