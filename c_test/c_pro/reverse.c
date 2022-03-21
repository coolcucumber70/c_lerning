#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;
LNode* toucha(struct LNode **head, int arry[],int n);
LNode* weicha(struct LNode **head, int arry[],int n);
int main()
{
     LNode *head = NULL;
    int i, data;
    printf("\nplease input 5 data==>\n");
    int arry[N]={1,2,3,4,5};
    head = toucha(&head,arry,5);
    head=head->next;
    for (i = 0; i < 5; i++)
    {
        printf("The value is ==>%d\n", head->data);
        head = head->next;
    }
}
//函数内申请空间，head还是要加引用的呢
LNode* toucha( LNode **head, int arry[],int n){
    int i;
    if(!(*head)){
        *head=(LNode*)malloc(sizeof(LNode));
        (*head)->data=0;
        (*head)->next=NULL;
    }
    for(i=0;i<n;i++){
    LNode*p=(LNode*)malloc(sizeof(LNode));
    p->data=arry[i];
    p->next=(*head)->next;
    (*head)->next=p;
    }
    
}
LNode* weicha(LNode **head, int arry[],int n){
    int i;
    if(!head){
        *head=(LNode*)malloc(sizeof(LNode));
        (*head)->data=0;
        (*head)->next=NULL;
    }
    LNode*r=*head;
    for(i=0;i<n;i++){
        LNode*p=(LNode*)malloc(sizeof(LNode));
        p->data=arry[i];
        p->next=NULL;
        r->next=p;
        r=p;
    }

}