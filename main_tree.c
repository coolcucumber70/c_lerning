#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
int main()
{
    int num[10]={8,2,10,7,5,6,4,1,9,3};
    SBTNode*head=NULL;
    printf("wocao\n");
    CreateBST(&head,num,10);
    preorderBST(head);
    printf("\n");
    inorderBST(head);
    printf("\n");
    postorderBST(head);

    return 0;
}