
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
#define LEN 14
int v[MaxSize]={0};
int mylevel;
typedef struct node {
	int n;
	struct node *left, *right;
}node_t,BTNode;
BTNode*result;
void printTree2(BTNode *n, int type,  int level);
void insertTree(BTNode **head, int val);
int InsertTree_dg(BTNode **bt, int val);
int hightbylecvel(BTNode* head);
void xlevel_dg(BTNode* root,int x,int level);//2015
void xsearch_dg(BTNode*root,int x);//2015
int widthbylecvel(BTNode* head);
void preorderwidth(BTNode* root,int level);
int preorderhight(BTNode* root);
void prewpl(BTNode* root,int level);//求树的权值，408 
void preorder(BTNode* root);
void preorder_nodg(BTNode*root);
void inorder(BTNode* root);
void inorder_nodg(BTNode*root);
void postorder(BTNode* root);
void postorder_nodg(BTNode*root);
void deleteBTnode(BTNode*root);
void swapchild(BTNode*root);
void FirstNode(BTNode* root);//2018 2
int findNearMid(BTNode* root);//2017 2
void btreetoexp(BTNode*root,int level);//将树输出中序表达式 408  2017


int main(void)
{
	BTNode *root = NULL;
	int i, num[LEN] = {10,4,8,9,2,11,3,1,16,5,33,6,20,7};

	for (i = 0; i < LEN; i++)
		insertTree(&root, num[i]);
	printTree2(root, 0,  0);
    // prewpl(root,1);
    // int sum=0;
    // for(i=1;i<15;i++)
    // {
    //     sum=sum+v[i]*i;

    // }
    // int sum1=wplbylevel(root);
    // printf("sum=%d\n",sum);
    // printf("sum1=%d\n",sum1);
    btreetoexp(root,0);
    //int data=findNearMid(root);
    //xsearch_dg(root,3);
    //xlevel_dg(root,8,1);
    //printf("%d\n",result->n);
    //printf("level=%d\n",mylevel);
    //FirstNode(root);
    //swapchild(root);
    //printTree2(root, 0,  0);
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
    free(root);
}
void FirstNode(BTNode* root)
{
    BTNode* stack[MaxSize];
    int top=0;
    if(!root)return;

    BTNode*p=root;
    while(p)
    {
        while(p)
    {
        stack[top]=p;
        top++;
        p=p->left;
    }
    top--;
    p=stack[top];
    if(p->right)
    {
        p=p->right;
    }
    else{
        printf("%d ",p->n);
        return;
    }


    }


}
int findNearMid(BTNode* root)
{
    BTNode*l=root;
    BTNode*prel=NULL;
    BTNode* prer=NULL;
    BTNode*r=root;
    int result=INT_MAX;
    while(l){
        prel=l;
        l=l->left;
    }
    while (r)
    {
        prer=r;
        r=r->right;
    }
    int half=(prel->n+prer->n)/2;
    printf("half=%d\n",half);
    BTNode *p=root;
    while(p)
    {
        if(half>=p->n)
        {
            p=p->right;
        }
        if(half<p->n)
        {
            result=p->n;
            p=p->left;       
        }
    }
    printf("result:%d\n",result);
    return result;
    
}

void xsearch_dg(BTNode* root,int x)
{
    if(!root)return;
    if(root->n==x)result=root;
    xsearch_dg(root->left,x);
    xsearch_dg(root->right,x);
}
void xlevel_dg(BTNode* root,int x,int level)
{
    if(!root) return;
    if(root->n==x)mylevel=level;
    xlevel_dg(root->left,x,level+1);
    xlevel_dg(root->right,x,level+1);
}
void prewpl(BTNode* root,int level)
{
    if(!root){
        return;
    }
    v[level]=v[level]+root->n;
    prewpl(root->left,level+1);
    prewpl(root->right,level+1);
}
int wplbylevel(BTNode* root)
{
    BTNode* queue[MaxSize]={0};
    int front=0,rear=0;
    rear=(rear+1)%MaxSize;
    BTNode*q=root;
    BTNode*p=NULL;
    int level=0;
    int sum=0;
    int result=0;
    queue[rear]=root;
    while(front!=rear)
    {

        front=(front+1)%MaxSize;
        p=queue[front];
        sum=sum+p->n;
        if(p->left){
            rear=(rear+1)%MaxSize;
            queue[rear]=p->left;
        }
        if(p->right){
            rear=(rear+1)%MaxSize;
            queue[rear]=p->right;
        }
        if(p==q){
            level++;
            result=result+sum*level;
            sum=0;
            q=queue[rear];    
        }
    }
    return result;
}
void btreetoexp(BTNode*root,int level)
{
    if(!root)return;
    if((root->left||root->right)&&level>0){
        printf("(");
    }
    btreetoexp(root->left,level+1);
    printf("%d",(root->n));
    btreetoexp(root->right,level+1);
     if((root->left||root->right)&&level>0){
        printf(")");
    }

}
