#include<iostream>
#include<stdlib.h>
#include <string>
using namespace std;


#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define MAX_VERTEX_NUM 20
#define INFINITY INT_MAX
#define MAXSIZE 100
#define OVERFLOW -2
typedef int Status;
typedef char Qelemtype;
typedef int VertexType;
typedef enum {DG,DN,UDG,UDN} GraphLind;
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;


int LocateVex(MGraph G,char u)
{
    int i;
    for (i=0;i<G.vexnum;i++)
    {
        if(u==G.vexs[i])return i;
    }
    if(i==G.vexnum)
    {
        printf("Error u!\n");
        exit(1);
    }
    return 0;
}
void CreateMGraph(MGraph &G)
{
    int i,j,k,w;
    char v1,v2;
    cout<<"Input vexnum:"<<endl;
    cin>>G.vexnum;
    cout<<"Input arcnum:"<<endl;
    cin>>G.arcnum;
    printf("Input Vertices:");
    
    for (i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=0;
    for(k=0;k<G.arcnum;k++)
    {
        cout<<"Input Arcs(v1,v2)&w"<<endl;
        cin>>v1;
        cin>>v2;
        cin>>w;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j]=w;
    }
}
void createMGraph(MGraph &graph, string inputString) {
    
}
void PrintMGraph(MGraph G)
{
    int i,j;
    printf("Output Vertices:");
    for(i=0;i<G.vexnum;i++)
        cout<<G.vexs[i];
    printf("\n");
    printf("Out put AdjMatrix:\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
            printf("%4d",G.arcs[i][j]);
        printf("\n");
    }
}
typedef int VRType;
typedef struct{
    VertexType adjvex;
    VRType lowcost;
}Closedge[MAX_VERTEX_NUM];
/*************************************邻接表**********/
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int info;
}ArcNode;//边结点类型
typedef struct VNode{
    VertexType data;
    int indegree;
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
int LocareVex_ALGraph(ALGraph G,char u)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(u==G.vertices[i].data)return i;
    }
    if(i==G.vexnum)
    {
        printf("Error u!\n");
        exit(1);
    }
    return 0;
}
void CreateALGraph_adjlist(ALGraph &G)
{
    int i,j,k,w;
    char v1,v2;
    ArcNode *p;
    cout<<"Input vexnum:"<<endl;
    cin>>G.vexnum;
    cout<<"Input arcnum:"<<endl;
    cin>>G.arcnum;
    printf("Input Vertices");
    for (i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    printf("Input Arc(v1,v2 & w):\n");
    for(k=0;k<G.arcnum;k++)
    {
        cin>>v1;
        cin>>v2;
        cin>>w;
        i=LocareVex_ALGraph(G,v1);
        j=LocareVex_ALGraph(G,v2);
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->info=w;
        p->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p;
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=i;
        p->info=w;
        p->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=p;
    }
}
void PrintALGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    for (i=0;i<G.vexnum;i++)
    {
        p=G.vertices[i].firstarc;
        if(p!=NULL)cout<<G.vertices[i].data<<":   ";
        while(p!=NULL)
        {
            printf("%3d: ",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
};

/*****************************最短路径Dijkstra算法*****************************/
#define NumVertices 20
typedef int PathMatrix[NumVertices][NumVertices];//最短路径数组
typedef int ShortPathTable[NumVertices];
typedef int AdjMatrix[NumVertices][NumVertices];
void ShortestPath_DIJ(MGraph G,int v0)
{
    PathMatrix P;ShortPathTable D;
    int final[NumVertices];
    int w;
    int v,i,min;
    for(v=0;v<G.vexnum;++v)
    {
        final[v]=FALSE;D[v]=G.arcs[v0][v];
        for(w=0;w<G.vexnum;++w)P[v][w]=FALSE;
        if(D[v]<INFINITY)
        {
            P[v][v0]=TRUE;P[v][v]=TRUE;
        }
        for(i=1;i<G.vexnum;i++)
        {
            min=INFINITY;
            for(w=0;w<G.vexnum;++w)
            {
                if(!final[w])
                {
                    if(D[w]<min)
                    {v=w;min=D[w];}}}}
        final[v]=TRUE;
        for(w=0;w<G.vexnum;++w)
            if(!final[w]&&(min+G.arcs[v][w]<D[w]))
            {
                D[w]=min+G.arcs[v][w];
                for(int j=0;j<G.vexnum;++j)
                    P[w][j]=P[v][j];
                P[w][w]=TRUE;
            }
    }
}


int main()
{
    ALGraph g; MGraph G;
    return 0;
}