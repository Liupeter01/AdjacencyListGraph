////#include"DirectEdge.h"
//
////�ж���ͼG���Ƿ���������<x,y>
//int  Adjcent_direct(ALGraph G, VertexType x, VertexType y)
//{
//          int x_pos = 0, x_flag = 0;  //x_flag�����Ƿ��ҵ�
///*Ѱ�Ҷ���x�ڶ�����е�λ��*/
//          for (int x_pos = 0; x_pos < G.MaxVertexNum; ++x_pos)
//          {
//                    if (G.Vetics[x_pos].data == x)
//                    {
//                              break;
//                    }
//          }
//          ArcNode* ptemp = G.Vetics[x_pos].first;
//          while (ptemp != NULL)
//          {
//                    if (G.Vetics[ptemp->adjvex].data == y)
//                    {
//                              x_flag = 1;
//                              break;
//                    }
//                    ptemp = ptemp->next;
//          }
//          return x_flag;
//}
//
////���������ͼG����x���ڱ�<x,?>
//void Neighbors_direct(ALGraph G, VertexType x)
//{
//          int x_pos = 0;
//          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
//          {
//                    if (G.Vetics[x_pos].data == x)
//                    {
//                              break;
//                    }
//          }
//          ArcNode* ptemp = G.Vetics[x_pos].first;
//          while (ptemp != NULL)
//          {
//                    printf("����߳���<%c,%c>\n", x, G.Vetics[ptemp->adjvex].data);
//                    ptemp = ptemp->next;
//          }
//
//          for (int i = 0; i < G.MaxVertexNum; ++i)
//          {
//                    ptemp = G.Vetics[i].first;
//                    while (ptemp != NULL)
//                    {
//                              if (G.Vetics[ptemp->adjvex].data == x)
//                              {
//                                        printf("��������<%c,%c>\n", G.Vetics[ptemp->adjvex].data, x);
//                                        break;
//                              }
//                              ptemp = ptemp->next;
//                    }
//                    ptemp = NULL;
//          }
//}
//
////������ͼG���һ�������<x, y>���ú���֧���޸�Ȩֵ
//int AddEdgeDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)
//{
//          int x_pos = 0, y_pos = 0;     //x��y��λ��
//          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
//          for (int i = 0; i < G->MaxVertexNum; ++i)
//          {
//                    if (G->Vetics[i].data == x)
//                    {
//                              x_status = 1;                 //����x����
//                              x_pos = i;                    //����x��λ��
//                    }
//                    if (G->Vetics[i].data == y)
//                    {
//                              y_status = 1;                   //����y����
//                              y_pos = i;                    //����y��λ��
//                    }
//          }
//          if (y_pos && x_pos)
//          {
//                    G->arcnum++;        //��������
//                    G->Vetics[x_pos].first = CreateLinkNode(G->Vetics[x_pos].first, y_pos, Edge_Value);
//                    return TRUE;
//          }
//          else
//          {
//                    return FALSE;
//          }
//}
//
////������ͼG���һ�������<x, y>���ú�����֧���޸�Ȩֵ
//int AddEdge_direct(ALGraph* G, VertexType x, VertexType y)
//{
//          return AddEdgeDirectEdgeValue(G, x, y, 1);        //Ĭ��ȨֵΪ1
//}
//
////������ͼGɾ��һ�������<x, y>
//int RemoveEdge_direct(ALGraph* G, VertexType x, VertexType y)
//{
//          int x_pos = 0, y_pos = 0;     //x��y��λ��
//          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
//          for (int i = 0; i < G->MaxVertexNum; ++i)
//          {
//                    if (G->Vetics[i].data == x)
//                    {
//                              x_status = 1;                 //����x����
//                              x_pos = i;                    //����x��λ��
//                    }
//                    if (G->Vetics[i].data == y)
//                    {
//                              y_status = 1;                   //����y����
//                              y_pos = i;                    //����y��λ��
//                    }
//          }
//          if (y_pos && x_pos)
//          {
//                    G->arcnum--;        //�����Լ�
//                    G->Vetics[x_pos].first = DeleteLinkNode(G->Vetics[x_pos].first, y_pos);      //ɾ��ĳ�����
//                    return TRUE;
//          }
//          else
//          {
//                    return FALSE;
//          }
//}