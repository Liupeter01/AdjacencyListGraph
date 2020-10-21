#include"ALGraph.h"

//根据为顶点表添加边表结点程序
ArcNode* CreateLinkNode(ArcNode* head, int position)
{
          if (head == NULL)
          {
                    head = (ArcNode*)calloc(1, sizeof(ArcNode));
                    head->next = NULL;
                    head->adjvex = position;
          }
          else
          {
                    ArcNode* p = head;
                    while (p->next != NULL)
                    {
                              p = p->next;
                    }
                    ArcNode* temp = (ArcNode*)calloc(1, sizeof(ArcNode));
                    temp->next = NULL;
                    temp->adjvex = position;
                    p->next = temp;
          }
          return head;
}

//根据为顶点表删除边表结点
ArcNode* DeleteLinkNode(ArcNode* head, int position)
{
          ArcNode* p = head;
          ArcNode* pre = head;
          while (p != NULL && p->adjvex != position)
          {
                    pre = p;  //记录前一个结点
                    p = p->next;
          }
         
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
          return head;
}

/*图G的初始化*/
void InitGraph(ALGraph* G,int ALGraph_Size)
{
          G->vexnum = 0;               //初始化，当前顶点的数量为0
          G->arcnum = 0;                //初始化该图中不存在边
          G->MaxVertexNum = ALGraph_Size;         //赋予顶点表的最大容量
          G->Vetics = (AdjList*)calloc(ALGraph_Size, sizeof(AdjList));          //初始化顶点表的大小为ALGraph_size
          G->Vetics[G->vexnum].first = NULL;
          G->Vetics[G->vexnum].data = 0;
}

//在图G中插入结点x
int InsertVertex(ALGraph* G, VertexType x)
{
          if (G->vexnum + 1 == G->MaxVertexNum)
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

/*在图G中批量的插入顶点，使用数组批量创建*/
void CreateBatchVertex(ALGraph* G, VertexType *arr)
{
          for (VertexType* p = arr; *p != '\0'; ++p)
          {
                    if (!InsertVertex(G, *p))
                    {
                              printf("顶点%c ----  插入失败\n",*p);
                    }
          }
}

//在图G中删除结点x
int  DeleteVertex(ALGraph* G, VertexType x)
{
          int flag = 0;       //标识位
           /*清除以该顶点为入边的边*/
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vetics[i].data != 0 && G->Vetics[i].first != NULL)  //不是空顶点表且边表为空
                    {
                              ArcNode* pstart = G->Vetics[i].first;
                              ArcNode* pre = NULL;          //前置指针
                              while (pstart != NULL && G->Vetics[pstart->adjvex].data != x)
                              {
                                        pre = pstart;
                                        pstart = pstart->next;
                              }
                              if (pstart->next = NULL)    //存放x的入边的边表就是边表的最后一个结点
                              {
                                        free(pstart);
                                        pre->next = NULL;
                              }
                              else
                              {
                                        pre->next = pstart->next;     //跳过存放x的边表
                                        free(pstart);
                              }
                    }
          }

          /*清除位于以该顶点为出边的边*/
          for (int x_pos = 0; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vetics[x_pos].data == x)
                    {
                              flag = 1;
                              G->Vetics[x_pos].data = 0;    //清空数据
                              RemoveLinkList(G->Vetics[x_pos].first); //清空该顶点表的所有边表
                              G->Vetics[x_pos].first = NULL;          //清空指针
                              break;
                    }
          }
          if (flag)
          {
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}

//完整链表的清除程序
void RemoveLinkList(ArcNode* phead)
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

/*图G的销毁*/
void DestroyGraph(ALGraph* G)
{
          free(G->Vetics);
}