#include"ALGraph.h"

//����Ϊ�������ӱ߱������
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

//����Ϊ�����ɾ���߱���
ArcNode* DeleteLinkNode(ArcNode* head, int position)
{
          ArcNode* p = head;
          ArcNode* pre = head;
          while (p != NULL && p->adjvex != position)
          {
                    pre = p;  //��¼ǰһ�����
                    p = p->next;
          }
         
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
          return head;
}

/*ͼG�ĳ�ʼ��*/
void InitGraph(ALGraph* G,int ALGraph_Size)
{
          G->vexnum = 0;               //��ʼ������ǰ���������Ϊ0
          G->arcnum = 0;                //��ʼ����ͼ�в����ڱ�
          G->MaxVertexNum = ALGraph_Size;         //���趥�����������
          G->Vetics = (AdjList*)calloc(ALGraph_Size, sizeof(AdjList));          //��ʼ�������Ĵ�СΪALGraph_size
          G->Vetics[G->vexnum].first = NULL;
          G->Vetics[G->vexnum].data = 0;
}

//��ͼG�в�����x
int InsertVertex(ALGraph* G, VertexType x)
{
          if (G->vexnum + 1 == G->MaxVertexNum)
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

/*��ͼG�������Ĳ��붥�㣬ʹ��������������*/
void CreateBatchVertex(ALGraph* G, VertexType *arr)
{
          for (VertexType* p = arr; *p != '\0'; ++p)
          {
                    if (!InsertVertex(G, *p))
                    {
                              printf("����%c ----  ����ʧ��\n",*p);
                    }
          }
}

//��ͼG��ɾ�����x
int  DeleteVertex(ALGraph* G, VertexType x)
{
          int flag = 0;       //��ʶλ
           /*����Ըö���Ϊ��ߵı�*/
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vetics[i].data != 0 && G->Vetics[i].first != NULL)  //���ǿն�����ұ߱�Ϊ��
                    {
                              ArcNode* pstart = G->Vetics[i].first;
                              ArcNode* pre = NULL;          //ǰ��ָ��
                              while (pstart != NULL && G->Vetics[pstart->adjvex].data != x)
                              {
                                        pre = pstart;
                                        pstart = pstart->next;
                              }
                              if (pstart->next = NULL)    //���x����ߵı߱���Ǳ߱�����һ�����
                              {
                                        free(pstart);
                                        pre->next = NULL;
                              }
                              else
                              {
                                        pre->next = pstart->next;     //�������x�ı߱�
                                        free(pstart);
                              }
                    }
          }

          /*���λ���Ըö���Ϊ���ߵı�*/
          for (int x_pos = 0; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vetics[x_pos].data == x)
                    {
                              flag = 1;
                              G->Vetics[x_pos].data = 0;    //�������
                              RemoveLinkList(G->Vetics[x_pos].first); //��ոö��������б߱�
                              G->Vetics[x_pos].first = NULL;          //���ָ��
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

//����������������
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

/*ͼG������*/
void DestroyGraph(ALGraph* G)
{
          free(G->Vetics);
}