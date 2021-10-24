
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
int v[MaxSize]={0};
typedef struct node {
	int n;
	struct node *left, *right;
}node_t,BTNode;
void printTree2(node_t *n, int type,  int level);
void insertTree(node_t **head, int val);
int hightbylecvel(BTNode* head);
int widthbylecvel(BTNode* head);
void postorder(BTNode* root);
void preorderwidth(BTNode* root,int level);
#define LEN 16
int main(void)
{
	node_t *root = NULL;
	int i, num[LEN] = {77, 66, 88, 55, 70, 80, 99, 44, 60,55,98,102,63,14,57,2};

	for (i = 0; i < LEN; i++)
		insertTree(&root, num[i]);
	printTree2(root, 0,  0);
    // int h1=hightbylecvel(root);
    // int h2=preorderheight(root);
     int w=widthbylecvel(root);
    preorderwidth(root,0);
    int max=0;
    for(i=0;i<MaxSize;i++)
    {
        
        int tmp=v[i];
        if(tmp>max)
           max=tmp;
    }
    printf("%d\n",max);
    
    // printf("h1=%d\n",h1);
    // printf("h2=%d\n",h2);
     printf("%d\n",w);
    postorder(root);

	return 0;
}

// 打印二叉树:   type : 0表示根节点，１表示左节点，２表示右节点. level表示层次，用于控制显示的距离
void printTree2(node_t *n, int type,  int level)
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


void insertTree(node_t **head, int val)
{
	node_t *new = malloc(sizeof(*new)), *tmp;

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
     printf("%d ",root->n);
     postorder(root->right);
 }
 //如何用栈来写先序遍历，这真的是个问题
 
