
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
int InsertTree_dg(BTNode **bt, int val);
int hightbylecvel(BTNode* head);
int widthbylecvel(BTNode* head);
void postorder(BTNode* root);
void preorderwidth(BTNode* root,int level);
int preorderhight(BTNode* root);
void preorder(BTNode* root);
void preorder_nodg(BTNode*root);
void inorder(BTNode* root);
void inorder_nodg(BTNode*root);
void deleteBTnode(BTNode*root);
int main(void)
{
	BTNode *root = NULL;
	int i, num[LEN] = {4,5,3,6,2,7,1};

	for (i = 0; i < LEN; i++)
		insertTree(&root, num[i]);
	printTree2(root, 0,  0);
    swapchild(root);
    printTree2(root, 0,  0);
    //  int h1=hightbylecvel(root);
    //  int h2=preorderheight(root);
    // //int w=widthbylecvel(root);
    // //preorderwidth(root,0);  
    //  printf("h1=%d\n",h1);
    //  printf("h2=%d\n",h2);
    // // postorder(root);
 
    // preorder(root);
    // printf("\n");
    // preorder_nodg(root);
    // printf("\n");
    // inorder(root);
    // printf("\n");
    // inorder_nodg(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");

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
int InsertTree_dg(BTNode **bt, int val)
 {  // 因为bt要改变，所以要用引用型指针
    if (*bt == NULL) {
        *bt = (BTNode*)malloc(sizeof(BTNode));  // 创建新结点
        (*bt)->left = (*bt)->right = NULL;
        (*bt)->n = val;
        return 1;
    } else {
        if (val == (*bt)->n) return 0;   // 关键字已经存在于树中
        else if (val < (*bt)->n) return InsertTree_dg(&((*bt)->left), val);
        else return InsertTree_dg(&((*bt)->right), val);
    }
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
 //利用先序便利的方法来遍历树中每一个元素，利用level来进行标记
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
 int preorderhight(BTNode* root)
 {
     if(!root)
        return;
    int l=preorderheight(root->left);
    int r=preorderheight(root->right);
    return (l+1>r+1?l+1:r+1);

 }
 int IsBlancedTree_R(BTNode* root)
{
    //空树是平衡二叉树
    //平衡二叉树是指以当前结点为根的左右子树高度不得超过1
    if (root == NULL)
        return 1;
    //右子树深度
    int right = preorderhight(root->left);
    //左子树深度
    int left = preorderhight(root->right);
    int gap = right - left;
    //深度超过1不是
    if (gap > 1 || gap < -1)
        return 0;
    //递归判断子树
    return IsBlancedTree_R(root->left) && IsBlancedTree_R(root->right);
}
void swapchild(BTNode*root)
{
    if(!root)return ;
    BTNode* tmp=NULL;
    tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    swapchild(root->left);
    swapchild(root->right);
}
void deleteBTnode(BTNode*root)
{
    deleteBTnode(root->left);
    deleteBTnode(root->right);
    delete(root);
}
 
