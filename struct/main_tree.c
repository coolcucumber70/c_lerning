
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
#define LEN 14
int v[MaxSize]={0};
int mylevel;
int minlen=INT_MAX,maxlen=INT_MIN;
typedef struct node {
	int n;
	struct node *left, *right;
}node_t,BTNode;
BTNode*result;
void printTree2(BTNode *n, int type,  int level);
void insertTree(BTNode **head, int val);
void insertTree1(BTNode **head, int val);
int InsertTree_dg(BTNode **bt, int val);
void DeleteNode(BTNode **head, int val);
int hightbylecvel(BTNode* head);
int high_dg(BTNode*root,int *high);
void xlevel_dg(BTNode* root,int x,int level);//2015
int xlevel_dg2(BTNode* root,int x);
void xsearch_dg(BTNode*root,int x);//2015
BTNode*  xsearch_dg1(BTNode*root,int x);//哪怕不是一条线，也是完全可以用return的
int widthbylecvel(BTNode* head);
void preorderwidth(BTNode* root,int level);
int preorderhight(BTNode* root);
int IsBlancedTree_R(BTNode* root);
void prewpl(BTNode* root,int level);//求树的权值，408  2014利用递归
int wplbylevel(BTNode* root);//利用层次遍历——广度遍历求权值
void preorder(BTNode* root);
void preorder_nodg(BTNode*root);
void inorder(BTNode* root);
void inorder_nodg(BTNode*root);
void postorder(BTNode* root);
void postorder_nodg(BTNode*root);
void deleteBTnode(BTNode*root);
void swapchild(BTNode*root);
void FirstNode(BTNode* root);//2018 2 遍历后续的第一个元素
int findNearMid(BTNode* root);//2017 2
void btreetoexp(BTNode*root,int level);//将树输出中序表达式 408  2017
int isfulltree(BTNode*root);//2014 判断完全二叉树
void findminmax(BTNode*root,int deep);
void reversetree(BTNode*root);
int IsAVL(BTNode* root, int height);
int sumnode(BTNode*root);
int maxnode(BTNode*root);
int contlevel_k(BTNode*root,int k);
int isjudgeerchashu(BTNode* root);
int main(void)
{
	BTNode *root = NULL;
	int i, num[LEN] = {10,4,8,9,2,11,3,1,16,5,33,6,20,7};

	for (i = 0; i < LEN; i++)
		insertTree1(&root, num[i]);
	printTree2(root, 0,  1);
    int result=sumnode(root);
    //int result=xlevel_dg2(root,9);
    //int result=contlevel_k(root,4);
    // int result=maxnode(root);
    printf("result=%d\n",result);
    // high_dg(root,&high);
    // printf("h1=%d",high);
    // printf("\n");
    // int high2=preorderhight(root);
    // printf("h2=%d",high2);
    // int sum=sumnode(root);
    // printf("sum=%d",sum);
    //DeleteNode(&root,6);
    // printTree2(root, 0,  1);
    // printf("nb\n");
    //reversetree(root);
    //printTree2(root, 0,  1);
    // findminmax(root,0);
    // printf("max:%d",maxlen);
    // printf("min:%d",minlen);
    // prewpl(root,1);
    // int sum=0;
    // for(i=1;i<15;i++)
    // {
    //     sum=sum+v[i]*i;

    // }
     //int sum1=wplbylevel(root);
    // printf("sum=%d\n",sum);
    // printf("sum1=%d\n",sum1);
    //btreetoexp(root,0);
    //int data=findNearMid(root);
    // xsearch_dg(root,3);
    // printf("\n");
    // //xlevel_dg(root,8,1);
    // printf("%d\n",result->n);
    // BTNode* a=xsearch_dg1(root,7);
    // printf("\n");
    // printf("%d\n",a->n);
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
void insertTree1(BTNode **head, int val){
    BTNode* new=malloc(sizeof(BTNode));
    new->n=val;
    new->left=NULL;
    new->right=NULL;
    if(*head==NULL){
        *head=new;
        return;
    }
    BTNode* p=*head;
    BTNode* q=NULL;
    while(p){
        q=p;
        if(new->n>p->n)
          p=p->right;
        else
          p=p->left;
              
    }
    if(new->n>q->n)
      q->right=new;
    else
      q->left=new;
       
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
        else if (val < (*bt)->n) return InsertTree_dg(&((*bt)->left), val);//这种写法不同于回溯的写法呀
        else return InsertTree_dg(&((*bt)->right), val);
    }
}
void DeleteNode(BTNode **head, int val){
    BTNode*p=*head;
    BTNode* pre=*head;
    BTNode*tmp=NULL;
    while(p){

        if(val==p->n)
          break;
        pre=p;
        if(val>p->n)
          p=p->right;
        else 
          p=p->left;
        
    }
    tmp=p;
    if(!p)
      printf("no node\n");
      return;
    if(p->left&&p->right)
    {
        pre=p;
        p=p->left;
        while(p->right)
          pre=p;
          p=p->right;
        tmp->n=p->n;
    }
    BTNode**s;
    if(pre->left==p)
      s=&pre->left;
    else
      s=&pre->right;
    if(!p->left&&!p->right){
      free(p);
      *s=NULL;
    }
    else if(p->left){
        *s=p->left;
        free(p);
    }
    else{
        *s=p->right;
        free(p);
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
BTNode*xsearch_dg1(BTNode*root,int x){
    if(!root)return NULL;
    if(root->n==x)return root;
    if(root->n>x){
        return xsearch_dg1(root->left,x);
    }
    else{
        return xsearch_dg1(root->right,x);
    }
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
int isfulltree(BTNode*root){
    BTNode* queue[MaxSize];
    int front=0,rear=0;
    queue[rear]=root;
    rear=(rear+1)%MaxSize;
    BTNode*p=NULL;
    while(front!=rear)
    {
        p=queue[front];
        front=(front+1)%MaxSize;
        if(!p)
          break; 
        queue[rear]=p->left;
        rear=(rear+1)%MaxSize;
        queue[rear]=p->right;
        rear=(rear+1)%MaxSize;
    }
    while(front!=rear){
        p=queue[front];
        front=(front+1)%MaxSize;
        if(p)
          return 0;

    }
    return 1;
}
void findminmax(BTNode*root,int deep){
    if(!root)return;
    if(!(root->left)&&!(root->right)){
      maxlen=(maxlen>deep?maxlen:deep);
      minlen=(minlen<deep?minlen:deep);
    }
    findminmax(root->left,deep+1);
    findminmax(root->right,deep+1);
}
void reversetree(BTNode*root){
    if(!root)return;
    BTNode*tmp=NULL;
    tmp=root->right;
    root->right=root->left;
    root->left=tmp;    
    reversetree(root->left);
    reversetree(root->right);

}
// int IsAVL(BTNode* root, int height)
// {
//     if(root== NULL) // 空树，返回真
//     {
//         height = 0;
//         return 1;
//     }
//     int heightLeft;
//     int resultLeft = IsAVL(root->left, heightLeft);
//     int heightRight;
//     int resultRight = IsAVL(root->right, heightRight);
//     if(resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) // 左子树和右子树都是AVL，并且高度相差不大于1，返回真
//     {
//         height = max(heightLeft, heightRight) + 1;
//         return 1;
//     }
//     else
//     {
//         height = max(heightLeft, heightRight) + 1;
//         return 0;
//     }
// }
int high_dg(BTNode*root,int *high){
    if(root==NULL){
        *high=0;
        return 0;
    }
    int h1;
    int h2;
    high_dg(root->left,&h1);
    high_dg(root->right,&h2);
    *high=(h1>h2?h1:h2)+1;
}
int sumnode(BTNode*root){
    if(root==NULL){
        return 0;
    }
    return sumnode(root->left)+sumnode(root->right)+1;
}
int maxnode(BTNode*root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL&&root->right==NULL){
        return root->n;
    }
    int h1=maxnode(root->left);
    int h2=maxnode(root->right);
    int h3=__max(h1,h2);
    return __max(root->n,h3);
}
int contlevel_k(BTNode*root,int k){
    if(root==NULL){
        return 0;
    }
    if(k==1){
        return 1;
    }
    return contlevel_k(root->left,k-1)+contlevel_k(root->right,k-1);

}
int xlevel_dg2(BTNode* root,int x){
    if(root==NULL){
        return -100;
    }
    if(root->n==x){
        return 1;
    }
    int h1=xlevel_dg2(root->left,x)+1;
    int h2=xlevel_dg2(root->right,x)+1;
    return __max(h1,h2);

}
int isjudgeerchashu(BTNode* root){
    if(root==NULL){
        return 1;
    }
    if(root->left&&root->right){
        if(root->n<root->left->n||root->n>root->right->n)
        return 0;
    }
    if(root->left){
        if (root->n<root->left->n)
        {
            return 0;
        }
        
    }
    if(root->right){
        if (root->n>root->right->n)
        {
            return 0;
        }
    }
    return(isjudgeerchashu(root->left)&&isjudgeerchashu(root->right));
}