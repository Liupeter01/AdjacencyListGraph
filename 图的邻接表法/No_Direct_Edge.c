#include"No_Direct_Edge.h"

//���������ͼG����x���ڱ�(x,?)
void Neighbors_nodirect(ALGraph G, VertexType x)
{
          int x_pos = 0;
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vetics[x_pos].data == x)
                    {
                              break;
                    }
          }
          ArcNode* ptemp = G.Vetics[x_pos].first;
          while (ptemp != NULL)
          {
                    printf("�����(%c,%c)\n", x, G.Vetics[ptemp->adjvex].data);
                    ptemp = ptemp->next;
          }
}

//�ж���ͼG���Ƿ���������(x,y)
int  Adjcent_nodirect(ALGraph G, VertexType x, VertexType y)
{
          int x_pos_1 = 0, x_flag = 0;  //x_flag�����Ƿ��ҵ�
          /*Ѱ�Ҷ���x�ڶ�����е�λ��*/
          for (int x_pos_1 = 0; x_pos_1 < G.MaxVertexNum; ++x_pos_1)
          {
                    if (G.Vetics[x_pos_1].data == x)
                    {
                              break;
                    }
          }

          ArcNode* ptemp = G.Vetics[x_pos_1].first;
          while (ptemp != NULL)
          {
                    if (G.Vetics[ptemp->adjvex].data == y)
                    {
                              x_flag = 1;
                              break;
                    }
                    ptemp = ptemp->next;
          }

          int x_pos_2 = 0, y_flag = 0;   //y_flag�����Ƿ��ҵ�
          /*Ѱ�Ҷ���y�ڶ�����е�λ��*/
          for (int x_pos_2 = 0; x_pos_2 < G.MaxVertexNum; ++x_pos_2)
          {
                    if (G.Vetics[x_pos_2].data == y)
                    {
                              break;
                    }
          }

          ptemp = G.Vetics[x_pos_2].first;
          while (ptemp != NULL)
          {
                    if (G.Vetics[ptemp->adjvex].data == x)
                    {
                              y_flag = 1;
                              break;
                    }
                    ptemp = ptemp->next;
          }
          return x_flag && y_flag;
}

//������ͼG���һ�������(x, y)���ú���֧���޸�Ȩֵ
int AddEdgeNoDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)
{
          int x_pos = 0, y_pos = 0;     //x��y��λ��
          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vetics[i].data == x)
                    {
                              x_status = 1;                 //����x����
                              x_pos = i;                    //����x��λ��
                    }
                    if (G->Vetics[i].data == y)
                    {
                              y_status = 1;                   //����y����
                              y_pos = i;                    //����y��λ��
                    }
          }
          if (y_pos && x_pos)
          {
                    G->arcnum++;        //��������
                    G->Vetics[x_pos].first = CreateLinkNode(G->Vetics[x_pos].first, y_pos, Edge_Value);                //Ϊ���x����
                    G->Vetics[y_pos].first = CreateLinkNode(G->Vetics[y_pos].first, x_pos, Edge_Value);                //Ϊ���y����
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}

//������ͼG���һ�������(x, y)���ú�����֧���޸�Ȩֵʹ��Ĭ��Ȩֵ1
int AddEdge_nodirect(ALGraph* G, VertexType x, VertexType y)
{
          return AddEdgeNoDirectEdgeValue(G, x, y, 1);   //ʹ��Ĭ��Ϊ1��Ȩֵ
}

//������ͼGɾ��һ�������(x, y)
int RemoveEdge_nodirect(ALGraph* G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;     //x��y��λ��
          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vetics[i].data == x)
                    {
                              x_status = 1;                 //����x����
                              x_pos = i;                    //����x��λ��
                    }
                    if (G->Vetics[i].data == y)
                    {
                              y_status = 1;                   //����y����
                              y_pos = i;                    //����y��λ��
                    }
          }
          if (y_pos && x_pos)
          {
                    G->arcnum--;        //�����Լ�
                    G->Vetics[x_pos].first = DeleteLinkNode(G->Vetics[x_pos].first, y_pos);      //ɾ��ĳ�����
                    G->Vetics[y_pos].first = DeleteLinkNode(G->Vetics[y_pos].first, x_pos);     //ɾ��ĳ�����
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}