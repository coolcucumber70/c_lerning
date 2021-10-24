#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
int main()
{
    int num[10]={8,2,10,7,5,6,4,1,9,3};
    // SBTNode*shead=NULL;
    // printf("wocao\n");
    // CreateBST(&shead,num,10);
    // preorderBST(shead);
    // printf("\n");
    // inorderBST(shead);
    // printf("\n");
    // postorderBST(shead);
    BTNode*head=NULL;
    createtree(&head,4);
    // preorder(head);
    // printf("\n");
    // inorder(head);
    // printf("\n");
    // postorder(head);
    // printf("\n");

    return 0;
}
 int hightbylecvel(BTNode* head)
 {
     int hight=0,front=0,rear=0;
     BTNode* queue[MaxSize];
     if(!head)
     {
         return 0;
     }
     rear=(rear+1)%MaxSize;
     queue[rear]=head;
     BTNode*q=queue[rear];
     while(front!=rear)
     {
         front=(front+1)%MaxSize;
     
     BTNode* p=queue[front];

     if(p->lchild)
     {
         rear=(rear+1)%MaxSize;
         queue[rear]=p->lchild;
     }
     if(p->rchild)
     {
         rear=(rear+1)%MaxSize;
         queue[rear]=p->rchild;
     }
     if(p==q)
     {
         hight++;
         q=queue[rear];
     }

     }
     return hight;
 }