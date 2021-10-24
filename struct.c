#include<stdio.h>
#include<stdlib.h>
#include"struct.h"//.c文件中还是必须有.h的头啊，否则不好使
#include <assert.h>
void initList(Sqlist* L) {
    L->length = 0;
}
int getElem(Sqlist L, int p, int* e){
    if (p < 0 || p >= L.length) {
        return 0;
    }
    *e = L.data[p];
    return 1;
}
void printlist(Sqlist*L)
{
    int i;
    int len=L->length;
    for(i=0;i<len;i++)
    {
        printf("%d\t",L->data[i]);
    }
}
int insertElem(Sqlist* L, int p, int e) {
    if (p < 0 || p > L->length || L->length == MaxSize) {
        return 0;
    }
    int i;
    for (i = L->length-1; i >= p; i--) {
        L->data[i+1] = L->data[i];
    }
    L->data[p] = e;
    ++(L->length);
    return 1;
}
int findElem(Sqlist L, int e) {
    int i;
    for ( i= 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return -1;
}
int deleteElem(Sqlist* L, int p, int* e) {
    if (p < 0 || p >= L->length) {
        return 0;
    }
    *e = L->data[p];
    int i;
    for (i = p; i < L->length-1; i++) {
        L->data[i] = L->data[i+1];
    }
    --(L->length);
    return 1;
}
void InitLinkList(LNode *list) {
    assert(list != NULL);
    list->next = NULL;
}
void createlistR(LNode *list, int a[], int n) {
    LNode *s, *r; // s用来指向新申请的节点，r始终指向list的终端节点
    int i;
    list = (LNode*)malloc(sizeof(LNode));
    list->next = NULL;
    r = list;
    for ( i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;  // 让当前的终端节点指向新来的节点
        r = r->next;  // 更新r，让r指向新的终端节点
    }
    r->next = NULL;
}
void createlistF(LNode *list, int a[], int n) {
    LNode *s;  // s用来指向新申请的节点
    list = (LNode*)malloc(sizeof(LNode));
    list->next = NULL;
    int i=0;
    for (i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = list->next;
        list->next = s;
    }
}
int findAndDelete(LNode *list, int x) {
    // 先找到该元素
    LNode *p;
    p = list;
    while (p->next != NULL) {
        if (p->next->data == x) {
            break;
        }
        p = p->next;
    }

    // 然后删除
    if (p->next == NULL) {
        return 0;
    } else {
        LNode *del;
        del = p->next;
        p->next = p->next->next;
        free(del);
        return 1;
    }
} 
void initStack(SqStack* st) {
    st->top = -1;
}

int isEmpty(SqStack* st) {
    return st->top == -1;
}
int push(SqStack* st, int x) {
    if (st->top == MaxSize) return 0;
    st->data[++st->top] = x;
    return 1;
}
int pop(SqStack* st, int* x) {
    if (st->top == -1) return 0;
    *x = st->data[st->top--];
    return 1;
}
void initQueue(SqQueue* qu) {
    qu->front = qu->rear = 0;  // 队首和队尾指针重合，并且指向0
}


int isQueueEmpty(SqQueue* qu) {
    return qu->front == qu->rear;  // 只要重合，即为空队
}
int enQueue(SqQueue* qu, int x) {
    if ((qu->rear+1)%MaxSize == qu->front) return 0;  // 队满则不能入队
    qu->rear = (qu->rear+1)%MaxSize;  // 若未满，则先移动指针
    qu->data[qu->rear] = x;  // 再放入元素
    return 1;
}
int deQueue(SqQueue* qu, int* x) {
    if (qu->front == qu->rear)  return 0;  // 若队空，则不能删除
    qu->front = (qu->front+1)%MaxSize;  // 若队不空，则先移动指针
    *x = qu->data[qu->front];  // 再取出元素
    return 1;
}
void preorder(BTNode *p) {
    if (p != NULL) {  // 一定要记得判空
        printf("%d ", (int)(p->data));
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(BTNode *p) {
    if (p != NULL) {
        inorder(p->lchild);
        printf("%d ", (int)(p->data));
        inorder(p->rchild);
    }
}
void postorder(BTNode *p) {
    if (p != NULL) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", (int)(p->data));
    }
}

void level(BTNode *p) {
    BTNode *que[MaxSize];
    BTNode *q = NULL;
    int front = 0, rear = 0;  // 定义一个循环队列

    if (p != NULL) {
        rear = (rear+1) % MaxSize;
        que[rear] = p;  // 让根节点入队
        while (front != rear) {  // 只要队列不空，则进行循环
            front = (front+1) % MaxSize;
            q = que[front];  // 队头元素出队
            printf("%c\n", q->data);  // 访问队头元素

            if (q->lchild) {  // 左子树存在，则左子树根节点入队
                rear = (rear+1) % MaxSize;
                que[rear] = q->lchild;
            }
            if (q->rchild) {  // 右子树存在，则右子树根节点入队
                rear = (rear+1) % MaxSize;
                que[rear] = q->rchild;
            }
        }
    }

}
void preorderNonrecursion(BTNode *bt) {
    if (bt != NULL) {
        BTNode *Stack[MaxSize];
        int top = -1;  // 定义人工栈
        Stack[++top] = bt;  // 根节点入栈
        BTNode *p;
        while (top != -1) {  // 判断不空
            p = Stack[top--];  // 出栈 并完成一次访问
            printf("%c\n", p->data);
            if (p->rchild != NULL) {   // 记得，先序遍历一定是先右孩子，再左孩子
                Stack[++top] = p->rchild;
            }
            if (p->lchild != NULL) {
                Stack[++top] = p->lchild;
            }
        }
    }
}
void inorderNonrecursion(BTNode *bt) {
    BTNode *Stack[MaxSize];
    int top = -1;
    BTNode *p = bt;
    if (bt != NULL) {
        while (top != -1 || p != NULL) {
            while (p != NULL) {
                Stack[++top] = p;
                p = p->lchild;
            }

            if (top != -1) {
                p = Stack[top--];
                printf("%c\n", p->data);
                p = p->rchild;
            }
        }
    }
}
void postorderNonrecursion(BTNode *bt) {
    if (bt != NULL) {
        BTNode *Stack1[MaxSize]; int top1 = -1;
        BTNode *Stack2[MaxSize]; int top2 = -1;  // 定义两个栈
        BTNode *p;
        Stack1[++top1] = bt;
        while (top1 != -1) {
            p = Stack1[top1--];
            Stack2[++top2] = p;  // 注意这里与先序的区别，放入栈2中即可
            if (p->lchild) {
                Stack1[++top1] = p->lchild;
            }
            if (p->rchild) {
                Stack1[++top1] = p->rchild;
            }
        }
        // 这时候循环结束，则会将逆后序遍历的结果都存放到了栈2中
        // 所以对栈2进行输出即可得到后序遍历的结果
        while (top2 != -1) {
            p = Stack2[top2--];
            printf("%c\n", p->data);
        }
    }
}
void createtree(BTNode** p,int n)
{ 
    insertbtnode(0,n,p);

}
void insertbtnode(int level, int max,BTNode** p)
{
    if(level<max&&(*p)==NULL)
    { 
        *p=(BTNode*)malloc(sizeof(BTNode));
        (*p)->data=(char)(rand()%50);
        (*p)->lchild=NULL;
        (*p)->rchild=NULL;
        int flag=rand()%3;
        if(!flag)
        {
            insertbtnode(level+1,max,&((*p)->lchild));

        }
        else if(flag==1)
        {
            insertbtnode(level+1,max,&(*p)->rchild);
        }
        else{
            insertbtnode(level+1,max,&(*p)->lchild);
            insertbtnode(level+1,max,&(*p)->rchild);
        }
    }
}
int visit[MaxSize]={0};
void DFS(AGraph *G, int v) {
    ArcNode *p;
    visit[v] = 1;
    printf("%d\n",v);
    p = G->adjlist[v].firstarc;  // 让p指向顶点v的第一条边
    while (p != NULL) {
        if (visit[p->adjvex] == 0) {
            DFS(G, p->adjvex);
            p = p->nextarc;
        }
    }
}
void MDFS(MGraph *G,int v)
{
    int i;
    if(visit[v]==1)return;
    printf("%d ",v);
    visit[v]==1;
    for( i=0;i<G->n;i++)
    {
        if(G->edges[v][i]==1)
        {
            MDFS(G,i);
        }
        
    }
}
void BFS(AGraph *G, int v) {
    ArcNode *p;
    int que[MaxSize], front = 0, rear = 0;  // 定义一个队列
    int j;
    printf("%d\n",v);
    visit[v] = 1;
    rear = (rear+1)%MaxSize;  // 入队
    que[rear] = v;
    while (front != rear) {
        front = (front+1)%MaxSize;  // 顶点出队
        j = que[front];
        p = G->adjlist[j].firstarc;  // p指向出队顶点j的第一条边
        while (p != NULL) {  // 将p的所有邻接点未被访问的入队
            if (visit[p->adjvex] == 0) {
                printf("%d\n",p->adjvex);
                rear = (rear+1)%MaxSize;
                que[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}
void Prim(MGraph g, int v0, int sum) {
    int lowcost[MaxSize], vset[MaxSize], v;
    int i, j, k, min;
    v = v0;
    for (i = 0; i < g.n; ++i) {
        lowcost[i] = g.edges[v0][i];
        vset[i] = 0;
    }
    vset[v0] = 1;  // 将v0并入树中
    sum = 0;  // sum清零用来累计树的权值
    for (i = 0; i < g.n-1; ++i) {
        min = INF;  // INF是一个已经定义的比图中所有边权值都大的常量
        // 下面这个循环用于选出候选边中的最小者
        for (j = 0; j < g.n; ++j) {
            if (vset[j] == 0 && lowcost[j] < min) {  // 选出当前生成树其他顶点到最短边中最短的一条
                min = lowcost[j];
                k = j;
            }
            vset[k] = 1;
            v = k;
            sum += min;  // 这里用sum记录了最小生成树的权值
            // 下面这个循环以刚进入的顶点v为媒介更新候选边
            for (j = 0; j < g.n; ++j) {
                if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {
                    lowcost[j] = g.edges[v][j];
                }
            }
        }
    }
}

Road road[MaxSize];
int v[MaxSize];  // 定义并查集数组
int getRoot(int a) {
    while (a != v[a])  a = v[a];  // 在并查集中查找根结点的函数
    return a;
}

void Kruskal(MGraph g, int sum, Road road[]) {
    int i, N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;
    for (i = 0; i < N; ++i)  v[i] = i;
    //sort(road, E);   // 对road数组中的E条边按其权值从小到大排序, 假设该函数已定义好
    for (i = 0; i < E; ++i) {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b) {
            v[a] = b;
            sum += road[i].w;
        }
    }
}
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
    int set[MaxSize];
    int min, i, j, u;
    // 从这句开始对各数组进行初始化
    for (i = 0; i < g.n; ++i) {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] < 2147483647)
            path[i] = v;
        else {
            path[i] = -1;
        }
    }
    set[v] = 1; path[v] = -1;
    //  初始化结束
    // 关键操作开始
    for (i = 0; i < g.n-1; ++i) {
        min = INF;
        // 这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        set[u] = 1;  // 将选出的顶点并入最短路径中
        // 这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测
        for (j = 0; j < g.n; ++j) {
            // 这个if语句判断顶点u的加入是否为出现通往顶点j的更短的路径
            if (set[j] == 0 && dist[u]+g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}
void Floyd(MGraph g, int Path[][MaxSize]) {
    int i, j, k;
    int A[MaxSize][MaxSize];
    // 这个双循环对数组A[][]和Path[][]进行了初始化
    for (i = 0; i < g.n; ++i) {
        for (j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            Path[i][j] = -1;
        }
    }
    // 下面三层循环是主要操作，完成了以k为中间点对所有的顶点对{i, }进行检测和修改
    for (k = 0; k < g.n; ++k) {
        for (i = 0; i < g.n; ++i) {
            for (j = 0; j < g.n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
            }
        }
    }
}
SBTNode* BSTSearch(SBTNode *bt, int key) {
    if (bt == NULL) return NULL;
    if (bt->key == key) {
        return bt;
    } else if (key < bt->key) {
        return BSTSearch(bt->lchild, key);
    } else {
        return BSTSearch(bt->rchild, key);
    }
}
int BSTInsert(SBTNode **bt, int key) {  // 因为bt要改变，所以要用引用型指针
    if (*bt == NULL) {
        *bt = (SBTNode*)malloc(sizeof(SBTNode));  // 创建新结点
        (*bt)->lchild = (*bt)->rchild = NULL;
        (*bt)->key = key;
        return 1;
    } else {
        if (key == (*bt)->key) return 0;   // 关键字已经存在于树中
        else if (key < (*bt)->key) return BSTInsert(&((*bt)->lchild), key);
        else return BSTInsert(&((*bt)->rchild), key);
    }
}
void CreateBST(SBTNode **bt, int key[], int n)
{
    //bt = NULL;  // 将树清空
    int i;
    for ( i = 0; i < n; ++i) {
        BSTInsert(bt, key[i]);
    }
}
void preorderBST(SBTNode *p) {
    if (p != NULL) {  // 一定要记得判空
        printf("%d ", p->key);
        preorderBST(p->lchild);
        preorderBST(p->rchild);
    }
}
void inorderBST(SBTNode *p)
{
    if (p != NULL) {
        inorderBST(p->lchild);
        printf("%d ", p->key);
        inorderBST(p->rchild);
    }
}
void postorderBST(SBTNode *p) {
    if (p != NULL) {
        postorderBST(p->lchild);
        postorderBST(p->rchild);
        printf("%d ", p->key);
    }
}

















