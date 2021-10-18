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
    preorder(head);
    printf("\n");
    inorder(head);
    printf("\n");
    postorder(head);
    printf("\n");
    return 0;
}