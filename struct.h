#ifndef GRAPH_H
#define GRAPH_H
#define MaxSize 100
#define INF 2147483647;
//线性表
typedef struct Sqlist{
    int data[MaxSize];
    int length;
}Sqlist;
void initList(Sqlist* L);
int getElem(Sqlist L, int p, int* e);
void printlist(Sqlist*L);
int insertElem(Sqlist* L, int p, int e);
int findElem(Sqlist L, int e);
int deleteElem(Sqlist* L, int p, int* e);

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void InitLirnkList(LNode *list);
void createlistR(LNode *list, int a[], int n);
void createlistF(LNode *list, int a[], int n);
int findAndDelete(LNode *list, int x);
//栈与队列
typedef struct SqStack{
    int data[MaxSize];
    int top;
} SqStack;
void initStack(SqStack* st);
int isEmpty(SqStack* st);
int push(SqStack* st, int x);
int pop(SqStack* st, int* x);
typedef struct {
    int data[MaxSize];
    int front;  // 队首指针
    int rear;  // 队尾指针
}SqQueue;
void initQueue(SqQueue* qu);
int isQueueEmpty(SqQueue* qu);
int enQueue(SqQueue* qu, int x);
int deQueue(SqQueue* qu, int* x);
typedef struct BTNode {
    char data;   // 这里默认结点data域为char类型

    struct BTNode *lchild;  // 左儿子
    struct BTNode *rchild;  // 右儿子
}BTNode;
// 线索二叉树
typedef struct TBTNode{
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;
void preorder(BTNode *p);
void inorder(BTNode *p);
void postorder(BTNode *p);
void level(BTNode *p);
void preorderNonrecursion(BTNode *bt);
void inorderNonrecursion(BTNode *bt);
void postorderNonrecursion(BTNode *bt);
void createtree(BTNode** p,int n);
void insertbtnode(int level, int max,BTNode** p);
//二叉排序树
typedef struct SBTNode {
    int key;
    struct SBTNode *lchild;
    struct SBTNode *rchild;
}SBTNode, *BiTree;
SBTNode* BSTSearch(SBTNode *bt, int key);
int BSTInsert(SBTNode **b, int key);
void CreateBST(SBTNode **bq, int key[], int n);
void preorderBST(SBTNode *p);
void inorderBST(SBTNode *p);
void postorderBST(SBTNode *p);

//图
typedef struct {
    int no;  // 顶点编号
    char info;  // 顶点的其他信息，这里默认为char型。这一句一般在题目中很少用到，因此题目不做特殊要求可以不写
}VertexType;  // 顶点类型

typedef struct {
    int edges[MaxSize][MaxSize];  // 临街矩阵定义，如果是有权图，则在此句中将int改为float
    int n, e;  // 分别为定点数和边数
    VertexType vex[MaxSize];  // 存放节点信息
}MGraph;  // 图的邻接矩阵类型
typedef struct ArcNode{
    int adjvex;  // 该边所指向的节点的位置
    struct ArcNode *nextarc;  // 指向下一条边的指针
    int info;  // 该边的相关信息（如权值）
}ArcNode;

typedef struct {
    char data;  // 定点信息
    ArcNode *firstarc;  // 指向第一条边的指针
}VNode;

typedef struct{
    VNode adjlist[MaxSize];  // 邻接表
    int n, e;  // 定点数和边数
}AGraph;  // 图的邻接表类型
typedef struct {
    int a, b;  // a和b为一条边所连的两个顶点
    int w;  // 边的权值
}Road;
int visit[MaxSize];
void DFS(AGraph *G, int v);
void BFS(AGraph *G, int v);
void MDFS(MGraph *G,int v);
void MBFS(MGraph *G, int v);

void Dijkstra(MGraph g, int v, int dist[], int path[]);
void Floyd(MGraph g, int Path[][MaxSize]);
void Kruskal(MGraph g, int sum, Road road[]);
void Prim(MGraph g, int v0, int sum);
#endif
