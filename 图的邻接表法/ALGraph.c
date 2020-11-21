#include"ALGraph.h"

ArcNode* CreateArcNode(int VercticsPos, int Edge_Value) //�߱��㴴��ģ�飬���ݶ���Ϊֹ��Ȩ�����߱���
{
          ArcNode* s = (ArcNode*)malloc(sizeof(ArcNode));
          assert(s != NULL);
          s->next = NULL;
          s->edge_value = Edge_Value;
          s->adjvex = VercticsPos;
          return s;
}

void InitGraph(ALGraph* G)   //ͼG�ĳ�ʼ��
{
          G->arcnum = G->vexnum = 0;                //��ʼ����ͼ�в����ڱߺͶ���
          G->MaxVertexNum = Default_Graph_Size;        //���趥����Ĭ������
}

void RemoveLinkList(ArcNode* phead)               //������������
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

void DestroyGraph(ALGraph* G)        //ͼG������
{
          for (int i = 0; i < G->vexnum; ++i)
          {
                    RemoveLinkList(G->Vetics[i].first);
          }
          free(G->Vetics);
          G->arcnum = G->vexnum = 0;
          G->Vetics = NULL;
}

void DisplayGraph(ALGraph G)           //ͼG�����
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

int LocateVertex(ALGraph G, VertexType x)                 //��ͼG���ҵ������±�
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

void ShowEdgeValue(ALGraph G, VertexType x, VertexType y)         //���ͼ��ĳ���ߵ�Ȩֵ
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
                              printf("�ñ�ֻ��Ĭ��Ȩֵ1\n");
                              return;
                    }
                    else
                    {
                              printf("��%c%c��ȨֵΪ��%d\n", x, y, ptemp->edge_value);
                              return;
                    }
          }
          printf("�ñ߲�����\n");
}

BOOL ExtendGraphSize(ALGraph* G, VertexType* arr)          //�����ڴ�ռ�
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

/*��Ҫ����ͼ���Լ��ߵ��������㣬�ߵ�Ȩ(Ĭ��Ϊ1)��ͼ������*/
BOOL InsertEdge(ALGraph* G, VertexType x, VertexType y, int Edge_Value, int Type)         //��ͼ�в����
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);
          if (x_pos != -1 || y_pos != -1)              //�����ڶ���
          {
                    ArcNode* x_y = CreateArcNode(LocateVertex(*G, y), Edge_Value);        //��������x->y
                    if (Type == DIRECTEDGRAPH)              //����ͼ
                    {
                              x_y->next = G->Vetics[x_pos].first;
                              G->Vetics[x_pos].first = x_y;
                    }
                    else if (Type == UNDIRECTEDGRAPH)       //����ͼ
                    {
                              ArcNode* y_x = CreateArcNode(LocateVertex(*G, x), Edge_Value);        //��������x->y
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

/*��Ҫ����ͼ���Լ��ߵ��������㣬ͼ������*/
BOOL RemoveEdge(ALGraph* G, VertexType x, VertexType y, int Type)     //��ͼG��ɾ����
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);
          if (x_pos != -1 || y_pos != -1)              //�����ڶ���
          {
                    if (Type == DIRECTEDGRAPH)              //����ͼ
                    {
                              G->Vetics[x_pos].first = DeleteLinkNode(G, G->Vetics[x_pos].first, y);
                    }
                    else if (Type == UNDIRECTEDGRAPH)       //����ͼ
                    {
                              G->Vetics[y_pos].first = DeleteLinkNode(G, G->Vetics[y_pos].first, x);
                              G->Vetics[x_pos].first = DeleteLinkNode(G, G->Vetics[x_pos].first, y);
                    }
                    G->arcnum--;
                    return TRUE;
          }
          return FALSE;
}

BOOL InsertVertex(ALGraph* G, VertexType x)       //��ͼG�в�����x
{
          if (G->vexnum >= G->MaxVertexNum)
          {
                    return FALSE;
          }
          else
          {
                    G->Vetics[G->vexnum].data = x;        //������
                    G->Vetics[G->vexnum++].first = NULL;      //��ǰ��㵱ǰ��û�б߱�
                    return TRUE;
          }
}

void CreateBatchVertex(ALGraph* G, VertexType* arr)                   //��ͼG���������붥��
{
          if (ExtendGraphSize(G, arr))
          {
                    for (VertexType* p = arr; *p != '\0'; ++p)
                    {
                              if (!InsertVertex(G, *p))
                              {
                                        printf("����%c ----  ����ʧ��\n", *p);
                              }
                    }
          }
}

ArcNode* DeleteLinkNode(ALGraph* G,ArcNode* head, VertexType x)                //ɾ�����н��x�ı߱���
{
          ArcNode* p = head, * pre = NULL;
          if (p->adjvex == LocateVertex(*G, x))             //���ɾ���ڵ�Ϊͷ���
          {
                    head = p->next;
                    free(p);
                    G->arcnum--;
                    return head;
          }
          while (p != NULL && p->adjvex != LocateVertex(*G, x))
          {
                    pre = p;  //��¼ǰһ�����
                    p = p->next;
          }
          if (p != NULL)      //�ý�㲻����
          {
                    if (p->next == NULL)           //p�����һ�����
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

BOOL RemoveVertex(ALGraph* G, VertexType x)             //��ͼG��ɾ�����x
{
          int x_pos = LocateVertex(*G, x);
          if (x_pos != -1)
          {
                    for (int i = 0; i < G->vexnum; ++i)     //�����ڽӱ�
                    {
                              G->Vetics[i].first = DeleteLinkNode(G, G->Vetics[i].first, x);   //ɾ�����ܵ����
                    }
                    RemoveLinkList(G->Vetics[x_pos].first); //ɾ���ýڵ�ĳ���
                    G->vexnum--;
                    return TRUE;
          }
          return FALSE;
}

/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ���û���򷵻�-1*/
int FindFirstNeighbor(ALGraph G, VertexType x)             //��ͼ��Ѱ��ĳһ������x�ĵ�һ���ڽӶ���y
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)              //�����ڶ���
          {
                    return ((G.Vetics[x_pos].first == NULL) ? -1 : G.Vetics[x_pos].first->adjvex);
          }
          return -1;
}

/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬���س��˶���y�������һ������ţ���y��x�����һ���ڽӵ㣬�򷵻�-1*/
int FindNextNeighbor(ALGraph G, VertexType x, VertexType y)          //��ͼ��Ѱ��ĳһ������x�ĳ��˶���y����ģ��ڶ����ڽӶ���
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);
          if (x_pos != -1 || y_pos!=-1)              //�����ڶ���
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
                    return ((ptemp->next == NULL) ? -1 : ptemp->next->adjvex);
          }
          return -1;
}