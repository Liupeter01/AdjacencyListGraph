#include"DirectEdge.h"

BOOL IsDirectEdgeExist(ALGraph G, VertexType x, VertexType y)		  //�ж���ͼG���Ƿ���������<x,y>
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)				//�����ڶ���
		  {
					ArcNode* ptemp = G.Vetics[x_pos].first;
                    while (ptemp != NULL)
                    {
                              if (G.Vetics[ptemp->adjvex].data == y)
                              {
										return TRUE;
                              }
                              ptemp = ptemp->next;
                    }
					return FALSE;				  //û�ҵ�
		  }
		  return FALSE;
}

void DisplayDirectNeighbors(ALGraph G, VertexType x) //���������ͼG����x���ڱ�<x,?><?,x>
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)
		  {
					ArcNode* ptemp = G.Vetics[x_pos].first;
					while (ptemp != NULL)
					{
							  printf("����߳���<%c,%c>\n", x, G.Vetics[ptemp->adjvex].data);
							  ptemp = ptemp->next;
					}
					for (int i = 0; i < G.vexnum; ++i)
					{
							  ptemp = G.Vetics[i].first;
							  while (ptemp != NULL)
							  {
										if (G.Vetics[ptemp->adjvex].data == x)
										{
												  printf("��������<%c,%c>\n", G.Vetics[ptemp->adjvex].data, x);
										}
										ptemp = ptemp->next;
							  }
					}
		  }
		  return;
}

int CalculateEnVertex(ALGraph G, VertexType x)			//����ĳһ��������������
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)				//�����ڶ���
		  {
					int counter = 0;				//������
					for (int i = 0; i < G.vexnum; ++i)
					{
							  ArcNode* ptemp = G.Vetics[i].first;
							  while (ptemp != NULL)
							  {
										if (ptemp->adjvex == LocateVertex(G, x))
										{
												  ++counter;
										}
										ptemp = ptemp->next;
							  }
					}
					return counter;				  //�ҵ�
		  }
		  return -1;		  //����
}

int CalculateOutVertex(ALGraph G, VertexType x)			//����ĳһ������ĳ�������
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)				//�����ڶ���
		  {
					int counter = 0;				//������
					ArcNode* ptemp = G.Vetics[x_pos].first;
					while (ptemp != NULL)
					{
							  ++counter;
							  ptemp = ptemp->next;
					}
					return counter;				  //�ҵ�
		  }
		  return -1;		  //����
}

BOOL	 InsertDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //��ͼG�����������Ȩ��<x,y>  ��ȨֵĬ��Ϊ1
{
		  return InsertEdge(G, x, y, 1, DIRECTEDGRAPH);
}

BOOL	 InsertDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)	//��ͼG���������Ȩ��<x,y>��֧���޸�Ȩֵ
{
		  return InsertEdge(G, x, y, Edge_Value, DIRECTEDGRAPH);
}

BOOL	RemoveDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //������ͼGɾ�������<x, y>
{
		  return RemoveEdge(G, x, y, DIRECTEDGRAPH);
}