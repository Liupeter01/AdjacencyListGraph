#include"UnDirectEdge.h"

BOOL IsUnDirectEdgeExist(ALGraph G, VertexType x, VertexType y)		  //�ж���ͼG���Ƿ���������(x,y)
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

void DisplayUnDirectNeighbors(ALGraph G, VertexType x)  //���������ͼG����x���ڱ�(x,?)
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)
		  {
					ArcNode* ptemp = G.Vetics[x_pos].first;
					while (ptemp != NULL)
					{
							  printf("�����(%c,%c)\n", x, G.Vetics[ptemp->adjvex].data);
							  ptemp = ptemp->next;
					}
		  }
		  return;
}

BOOL	 InsertUnDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //��ͼG�����������Ȩ��(x,y)  ��ȨֵĬ��Ϊ1
{
		  return InsertEdge(G, x, y, 1, UNDIRECTEDGRAPH);
}

BOOL	 InsertUnDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)		//��ͼG���������Ȩ��(x,y)��֧���޸�Ȩֵ
{
		  return InsertEdge(G, x, y, Edge_Value, UNDIRECTEDGRAPH);
}

BOOL	RemoveUnDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //������ͼGɾ�������(x,y)
{
		  return RemoveEdge(G, x, y, UNDIRECTEDGRAPH);
}