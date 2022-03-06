#include<stdio.h>
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
LNode* findsanmenode(LNode* str1,LNode* str2);//408  2012 寻找链表的共同点
LNode* changenode(LNode* head,int n);//408 2020年，交换链表数据

int main()
{

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
LNode* findsanmenode(LNode* str1,LNode* str2)
{
    int cout1=0,cout2=0,cout,i;
    LNode*p=str1;
    LNode*q=str2;
    while(p)
        cout1++;
        p=p->next;
    while(q)
        cout2++;
        q=q->next;   
    cout=cout1-cout2;
    if(cout>=0){
        p=str1;
        q=str2;
    }else{
        p=str2;
        q=str1;
        cout=-cout;
    }
    for(i=0;i<cout;i++)
        p=p->next;
    while(p&&q){
        if(p==q){
            return p;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return NULL;

}
void  deletesamenode(LNode*head,int n)
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
LNode* changenode(LNode* head,int n)
{
    int cout=(n+1)/2;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->next=NULL;
    int i;
    LNode* p=head->next;
    LNode* q=NULL;
    LNode* t1=NULL;
    LNode* t2=NULL;
    for(i=0;i<cout;i++)
    {
        p=p->next;
    }
    while(p)
    {
        q=p->next;
        p->next=s->next;
        s->next=p;
        p=q;
    }
    p=head->next;
    q=s->next;
    while((!p)||(!q))
    {
        t1=p->next;
        t2=q->next;
        p->next=q;
        q->next=t1;
        p=t1;
        q=t2;
    }
    return head;
}