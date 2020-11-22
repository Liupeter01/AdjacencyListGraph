#include"ALGraph.h"

ArcNode* CreateArcNode(int VercticsPos, int Edge_Value) //边表结点创建模块，根据顶点为止和权创建边表结点
{
          ArcNode* s = (ArcNode*)malloc(sizeof(ArcNode));
          assert(s != NULL);
          s->next = NULL;
          s->edge_value = Edge_Value;
          s->adjvex = VercticsPos;
          return s;
}

void InitGraph(ALGraph* G)   //图G的初始化
{
          G->arcnum = G->vexnum = 0;                //初始化该图中不存在边和顶点
          G->MaxVertexNum = Default_Graph_Size;        //赋予顶点表的默认容量
}

void RemoveLinkList(ArcNode* phead)               //链表的清除程序
{
          ArcNode* p = phead;
          ArcNode* temp = NULL;
          while (p != NULL)
          {
                    temp = p;
                    p = p->next;
                    free(temp);
          }
}

void DestroyGraph(ALGraph* G)        //图G的销毁
{
          for (int i = 0; i < G->vexnum; ++i)
          {
                    RemoveLinkList(G->Vetics[i].first);
          }
          free(G->Vetics);
          G->arcnum = G->vexnum = 0;
          G->Vetics = NULL;
}

void DisplayGraph(ALGraph G)           //图G的输出
{
          for (int i = 0; i < G.vexnum; ++i)
          {
                    printf("%d  %c:   ", i, G.Vetics[i].data);
                    ArcNode* p = G.Vetics[i].first;
                    while (p != NULL)
                    {
                              printf("%c--->", G.Vetics[p->adjvex].data);
                              p = p->next;
                    }
                    printf("END\n");
          }
}

int LocateVertex(ALGraph G, VertexType x)                 //在图G中找到顶点下标
{
          int x_pos = 0;
          int flag = 0;
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vetics[x_pos].data == x)
                    {
                              flag = 1;
                              break;
                    }
          }
          return ((!flag) ? -1 : x_pos);
}

void ShowEdgeValue(ALGraph G, VertexType x, VertexType y)         //输出图中某条边的权值
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)
          {
                    ArcNode* ptemp = G.Vetics[x_pos].first;
                    while (ptemp != NULL && G.Vetics[ptemp->adjvex].data != y)
                    {
                              ptemp = ptemp->next;
                    }
                    if (ptemp->edge_value == 1)
                    {
                              printf("该边只有默认权值1\n");
                              return;
                    }
                    else
                    {
                              printf("边%c%c的权值为：%d\n", x, y, ptemp->edge_value);
                              return;
                    }
          }
          printf("该边不存在\n");
}

BOOL ExtendGraphSize(ALGraph* G, VertexType* arr)          //分配内存空间
{
          G->MaxVertexNum = (((int)strlen(arr) > G->MaxVertexNum) ? (int)strlen(arr) : G->MaxVertexNum);
          G->Vetics = (AdjList*)calloc(G->MaxVertexNum, sizeof(AdjList));
          assert(G->Vetics != NULL);
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    G->Vetics[i].data = 0;
                    G->Vetics[i].first = NULL;
          }
          if (G->Vetics == NULL)
          {
                    return FALSE;
          }
          return TRUE;
}

/*需要传递图，以及边的两个顶点，边的权(默认为1)，图的类型*/
BOOL InsertEdge(ALGraph* G, VertexType x, VertexType y, int Edge_Value, int Type)         //在图中插入边
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);
          if (x_pos != -1 || y_pos != -1)              //不存在顶点
          {
                    ArcNode* x_y = CreateArcNode(LocateVertex(*G, y), Edge_Value);        //创建单向x->y
                    if (Type == DIRECTEDGRAPH)              //有向图
                    {
                              x_y->next = G->Vetics[x_pos].first;
                              G->Vetics[x_pos].first = x_y;
                    }
                    else if (Type == UNDIRECTEDGRAPH)       //无向图
                    {
                              ArcNode* y_x = CreateArcNode(LocateVertex(*G, x), Edge_Value);        //创建单向x->y
                              x_y->next = G->Vetics[x_pos].first;
                              G->Vetics[x_pos].first = x_y;

                              y_x->next = G->Vetics[y_pos].first;
                              G->Vetics[y_pos].first = y_x;
                    }
                    G->arcnum++;
                    return TRUE;
          }
          return FALSE;
}

/*需要传递图，以及边的两个顶点，图的类型*/
BOOL RemoveEdge(ALGraph* G, VertexType x, VertexType y, int Type)     //在图G中删除边
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);
          if (x_pos != -1 || y_pos != -1)              //不存在顶点
          {
                    if (Type == DIRECTEDGRAPH)              //有向图
                    {
                              G->Vetics[x_pos].first = DeleteLinkNode(G, G->Vetics[x_pos].first, y);
                    }
                    else if (Type == UNDIRECTEDGRAPH)       //无向图
                    {
                              G->Vetics[y_pos].first = DeleteLinkNode(G, G->Vetics[y_pos].first, x);
                              G->Vetics[x_pos].first = DeleteLinkNode(G, G->Vetics[x_pos].first, y);
                    }
                    G->arcnum--;
                    return TRUE;
          }
          return FALSE;
}

BOOL InsertVertex(ALGraph* G, VertexType x)       //在图G中插入结点x
{
          if (G->vexnum >= G->MaxVertexNum)
          {
                    return FALSE;
          }
          else
          {
                    G->Vetics[G->vexnum].data = x;        //插入结点
                    G->Vetics[G->vexnum++].first = NULL;      //当前结点当前的没有边表
                    return TRUE;
          }
}

void CreateBatchVertex(ALGraph* G, VertexType* arr)                   //在图G中批量插入顶点
{
          if (ExtendGraphSize(G, arr))
          {
                    for (VertexType* p = arr; *p != '\0'; ++p)
                    {
                              if (!InsertVertex(G, *p))
                              {
                                        printf("顶点%c ----  插入失败\n", *p);
                              }
                    }
          }
}

ArcNode* DeleteLinkNode(ALGraph* G,ArcNode* head, VertexType x)                //删除含有结点x的边表结点
{
          ArcNode* p = head, * pre = NULL;
          if (p->adjvex == LocateVertex(*G, x))             //如果删除节点为头结点
          {
                    head = p->next;
                    free(p);
                    G->arcnum--;
                    return head;
          }
          while (p != NULL && p->adjvex != LocateVertex(*G, x))
          {
                    pre = p;  //记录前一个结点
                    p = p->next;
          }
          if (p != NULL)      //该结点不存在
          {
                    if (p->next == NULL)           //p是最后一个结点
                    {
                              free(p);
                              pre->next = NULL;
                    }
                    else
                    {
                              pre->next = p->next;
                              free(p);
                    }
                    G->arcnum--;
          }
          return head;
}

BOOL RemoveVertex(ALGraph* G, VertexType x)             //在图G中删除结点x
{
          int x_pos = LocateVertex(*G, x);
          if (x_pos != -1)
          {
                    for (int i = 0; i < G->vexnum; ++i)     //遍历邻接表
                    {
                              G->Vetics[i].first = DeleteLinkNode(G, G->Vetics[i].first, x);   //删除可能的入边
                    }
                    RemoveLinkList(G->Vetics[x_pos].first); //删除该节点的出边
                    G->vexnum--;
                    return TRUE;
          }
          return FALSE;
}

/*在图G中顶点X的第一个邻接点，若有则返回顶点号，若没有则返回-1*/
int FindFirstNeighbor(ALGraph G, VertexType x)             //在图中寻找某一个顶点x的第一个邻接顶点y
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)              //不存在顶点
          {
                    return ((G.Vetics[x_pos].first == NULL) ? -1 : G.Vetics[x_pos].first->adjvex);
          }
          return -1;
}

/*在图G中顶点X的第一个邻接点，返回除了顶点y以外的下一个顶点号，若y是x的最后一个邻接点，则返回-1*/
int FindNextNeighbor(ALGraph G, VertexType x, VertexType y)          //在图中寻找某一个顶点x的除了顶点y以外的，第二个邻接顶点
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);
          if (x_pos != -1 || y_pos!=-1)              //不存在顶点
          {
                    ArcNode* ptemp = G.Vetics[x_pos].first;
                    if (ptemp == NULL)
                    {
                              return -1;
                    }
                    while (ptemp!=NULL && ptemp->adjvex != y_pos)
                    {
                              ptemp = ptemp->next;
                    }
                    if (ptemp == NULL)            //没有找到
                    {
                              return -1;
                    }
                    return ((ptemp->next == NULL) ? -1 : ptemp->next->adjvex);
          }
          return -1;
}