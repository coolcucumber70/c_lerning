
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
#define LEN 7
int v[MaxSize]={0};
typedef struct node {
	int n;
	struct node *left, *right;
}node_t,BTNode;
void printTree2(BTNode *n, int type,  int level);
void insertTree(BTNode **head, int val);
int hightbylecvel(BTNode* head);
int widthbylecvel(BTNode* head);
void postorder(BTNode* root);
void preorderwidth(BTNode* root,int level);
void preorder(BTNode* root);
void preorder_nodg(BTNode*root);
void inorder(BTNode* root);
void inorder_nodg(BTNode*root);
int main(void)
{
	BTNode *root = NULL;
	int i, num[LEN] = {4,5,3,6,2,7,1};

	for (i = 0; i < LEN; i++)
		insertTree(&root, num[i]);
	printTree2(root, 0,  0);
    // int h1=hightbylecvel(root);
    // int h2=preorderheight(root);
    //int w=widthbylecvel(root);
    //preorderwidth(root,0);  
    // printf("h1=%d\n",h1);
    // printf("h2=%d\n",h2);
    // postorder(root);
 
    preorder(root);
    printf("\n");
    preorder_nodg(root);
    printf("\n");
    inorder(root);
    printf("\n");
    inorder_nodg(root);
    printf("\n");
    postorder(root);
    printf("\n");

	return 0;
}

// 打印二叉树:   type : 0表示根节点，１表示左节点，２表示右节点. level表示层次，用于控制显示的距离
void printTree2(BTNode *n, int type,  int level)
{
	int i;

	if (NULL == n)
		return;

	printTree2(n->right, 2, level+1);
	switch (type)
	{
	case 0:
		printf("%2d\n", n->n);
		break;
	case 1:
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("\\ %2d\n", n->n);
		break;
	case 2:
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("/ %2d\n", n->n);
		break;	
	}
	printTree2(n->left, 1,  level+1);
}


void insertTree(BTNode **head, int val)
{
	BTNode *new = malloc(sizeof(*new)), *tmp;

	new->left = new->right = NULL;
	new->n = val;

	if (NULL == *head)
	{
		*head = new;
		return;
	}

	tmp = *head;
	while (1)	
	{		
		while ((tmp->right != NULL) && (new->n > tmp->n))
			tmp = tmp->right;
		if ((new->n > tmp->n) && (tmp->right == NULL))
			break;
		
		while ((tmp->left != NULL) && (new->n <= tmp->n))
			tmp = tmp->left;
		if ((new->n <= tmp->n) && (tmp->left == NULL))
			break;
	}
	if (new->n > tmp->n)
		tmp->right = new;
	else
		tmp->left = new;	

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

     if(p->left)
     {
         rear=(rear+1)%MaxSize;
         queue[rear]=p->left;
     }
     if(p->right)
     {
         rear=(rear+1)%MaxSize;
         queue[rear]=p->right;
     }
     if(p==q)
     {
         hight++;
         q=queue[rear];
     }

     }
     return hight;
 }
 int widthbylecvel(BTNode* head)
 {
     int width=0,front=0,rear=0;
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

     if(p->left)
     {
         rear=(rear+1)%MaxSize;
         queue[rear]=p->left;
     }
     if(p->right)
     {
         rear=(rear+1)%MaxSize;
         queue[rear]=p->right;
     }
     if(p==q)
     {
         int size=(rear+MaxSize-front)%MaxSize;
         width=(size>width?size:width);
         q=queue[rear];
     }

     }
     return width;
 }

 int preorderheight(BTNode*root)
 {
     if(!root)
        return 0;
    int h1=preorderheight(root->left);
    int h2=preorderheight(root->right);     
     return (h1>h2?h1:h2)+1;
 }
 
 void preorderwidth(BTNode* root,int level)
 {
     if(!root) return ;
     v[level]++;
     preorderwidth(root->left,level+1);
     preorderwidth(root->right,level+1);

 }
 //如何利用遍历找到某个点呢?
 //找某一个值一点问题都没有。
 void postorder(BTNode* root)
 {
     if(!root)
        return;
     postorder(root->left);
     
     postorder(root->right);
     printf("%d ",root->n);
 }
 //
 void preorder(BTNode* root)
 {
     if(!root)
          return ;
     printf("%d ",root->n);
     preorder(root->left);
     preorder(root->right);
 }
 void preorder_nodg(BTNode*root)
 {
     if(!root) return;
     BTNode* p=root;
     BTNode* stack[MaxSize];
     int top=-1;
     while(p||top!=-1)
     {
        
         while(p)
     { 
         printf("%d ",p->n);
         top=top+1;
         stack[top]=p;
         p=p->left;

     }
        p=stack[top];
        top--;
        p=p->right;

     }
     
 }
 void inorder(BTNode* root)
 {
      if(!root)
          return ;
     
     inorder(root->left);
     printf("%d ",root->n);
     inorder(root->right);
 }
 void inorder_nodg(BTNode*root)
 {
     if(!root) return;
     BTNode* p=root;
     BTNode* stack[MaxSize];
     int top=-1;
     while(p||top!=-1)
     {
         while(p)
     { 
         top=top+1;
         stack[top]=p;
         p=p->left;

     }
        p=stack[top];
        top--;
        printf("%d ",p->n);
        p=p->right;

     }
     
 }

 
