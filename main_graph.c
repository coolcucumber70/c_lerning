#define MaxSize 5
#define INF 2147483647;
#include<stdio.h>
#include<stdlib.h>
//图

typedef struct {
    int no;  // 顶点编号
    char info;  // 顶点的其他信息，这里默认为char型。这一句一般在题目中很少用到，因此题目不做特殊要求可以不写
}VertexType;  // 顶点类型

typedef struct {
    int edges[MaxSize][MaxSize];  // 临街矩阵定义，如果是有权图，则在此句中将int改为float
    int n, e;  // 分别为定点数和边数
    VertexType vex[MaxSize];  // 存放节点信息
}graph,*MGraph;  // 图的邻接矩阵类型
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
AGraph * alterMtoAGraph(MGraph MG);
int visit[MaxSize]={0,0,0,0,0};
void InitMGraph(MGraph G, int m[5][5])
{
    int i,j;
    for(i=0;i<MaxSize;i++)
    {
        for(j=0;j<MaxSize;j++)
        {
            G->edges[i][j]=m[i][j];
        }
    }
}
void printMGraph(MGraph G)
{
     int i,j;
    for(i=0;i<MaxSize;i++)
    {
        for(j=0;j<MaxSize;j++)
        {
            printf("%d ",G->edges[i][j]);
        }
        printf("\n");
    }
}
//如何写一个邻接矩阵到临接表的转换呢？
 AGraph * alterMtoAGraph(MGraph MG)
 {
     AGraph* AG=malloc(sizeof(AGraph));
     AG->n=MG->n;
     AG->e=MG->e;
     int i,j;
     for(i=0;i<AG->n;i++)
     {
         ArcNode*p=AG->adjlist[i].firstarc;
         for(j=0;j<AG->n;j++)
         {
             if(MG->edges[i][j]==1)
             {
                 ArcNode*q=malloc(sizeof(ArcNode));
                 q->adjvex=j;
                 p->nextarc=q;
                 p=q;
             }
         }
        p->nextarc=NULL;

     }
     return AG;
 }

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
void MDFS(MGraph G,int v)
{
    int i;
    if(visit[v]==1)
    {
        return;
    }
    printf("%d ",v);
    visit[v]=1;
    for( i=0;i<G->n;i++)
    {
        if((G->edges[v][i]==1)&&(visit[i]!=1))
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
// void Prim(MGraph g, int v0, int sum) {
//     int lowcost[MaxSize], vset[MaxSize], v;
//     int i, j, k, min;
//     v = v0;
//     for (i = 0; i < g.n; ++i) {
//         lowcost[i] = g.edges[v0][i];
//         vset[i] = 0;
//     }
//     vset[v0] = 1;  // 将v0并入树中
//     sum = 0;  // sum清零用来累计树的权值
//     for (i = 0; i < g.n-1; ++i) {
//         min = INF;  // INF是一个已经定义的比图中所有边权值都大的常量
//         // 下面这个循环用于选出候选边中的最小者
//         for (j = 0; j < g.n; ++j) {
//             if (vset[j] == 0 && lowcost[j] < min) {  // 选出当前生成树其他顶点到最短边中最短的一条
//                 min = lowcost[j];
//                 k = j;
//             }
//             vset[k] = 1;
//             v = k;
//             sum += min;  // 这里用sum记录了最小生成树的权值
//             // 下面这个循环以刚进入的顶点v为媒介更新候选边
//             for (j = 0; j < g.n; ++j) {
//                 if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {
//                     lowcost[j] = g.edges[v][j];
//                 }
//             }
//         }
//     }
// }

// Road road[MaxSize];
// int v[MaxSize];  // 定义并查集数组
// int getRoot(int a) {
//     while (a != v[a])  a = v[a];  // 在并查集中查找根结点的函数
//     return a;
// }

// void Kruskal(MGraph g, int sum, Road road[]) {
//     int i, N, E, a, b;
//     N = g->n;
//     E = g->e;
//     sum = 0;
//     for (i = 0; i < N; ++i)  v[i] = i;
//     //sort(road, E);   // 对road数组中的E条边按其权值从小到大排序, 假设该函数已定义好
//     for (i = 0; i < E; ++i) {
//         a = getRoot(road[i].a);
//         b = getRoot(road[i].b);
//         if (a != b) {
//             v[a] = b;
//             sum += road[i].w;
//         }
//     }
// }
// void Dijkstra(MGraph g, int v, int dist[], int path[]) {
//     int set[MaxSize];
//     int min, i, j, u;
//     // 从这句开始对各数组进行初始化
//     for (i = 0; i < g.n; ++i) {
//         dist[i] = g.edges[v][i];
//         set[i] = 0;
//         if (g.edges[v][i] < 2147483647)
//             path[i] = v;
//         else {
//             path[i] = -1;
//         }
//     }
//     set[v] = 1; path[v] = -1;
//     //  初始化结束
//     // 关键操作开始
//     for (i = 0; i < g.n-1; ++i) {
//         min = INF;
//         // 这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的
//         for (j = 0; j < g.n; ++j) {
//             if (set[j] == 0 && dist[j] < min) {
//                 u = j;
//                 min = dist[j];
//             }
//         }
//         set[u] = 1;  // 将选出的顶点并入最短路径中
//         // 这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测
//         for (j = 0; j < g.n; ++j) {
//             // 这个if语句判断顶点u的加入是否为出现通往顶点j的更短的路径
//             if (set[j] == 0 && dist[u]+g.edges[u][j] < dist[j]) {
//                 dist[j] = dist[u] + g.edges[u][j];
//                 path[j] = u;
//             }
//         }
//     }
// }
// void Floyd(MGraph g, int Path[][MaxSize]) {
//     int i, j, k;
//     int A[MaxSize][MaxSize];
//     // 这个双循环对数组A[][]和Path[][]进行了初始化
//     for (i = 0; i < g.n; ++i) {
//         for (j = 0; j < g.n; ++j) {
//             A[i][j] = g.edges[i][j];
//             Path[i][j] = -1;
//         }
//     }
//     // 下面三层循环是主要操作，完成了以k为中间点对所有的顶点对{i, }进行检测和修改
//     for (k = 0; k < g.n; ++k) {
//         for (i = 0; i < g.n; ++i) {
//             for (j = 0; j < g.n; ++j) {
//                 if (A[i][j] > A[i][k] + A[k][j]) {
//                     A[i][j] = A[i][k] + A[k][j];
//                     Path[i][j] = k;
//                 }
//             }
//         }
//     }
// }
int main()
{
     MGraph G=malloc(sizeof(graph));
     AGraph*A=NULL;
     G->n=5;
     G->e=7;
     int m[MaxSize][MaxSize]={ {0,1,1,0,0,},{0,0,1,0,1},{0,0,0,1,0},{0,0,0,0,1},{1,0,0,0,0} };
    InitMGraph(G, m);
    printMGraph(G);
    MDFS(G,0);
    //A=alterMtoAGraph(G);
    printf("nb");
    // DFS(A,0);
}
