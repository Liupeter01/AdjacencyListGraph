#include"UnDirectEdge.h"

BOOL IsUnDirectEdgeExist(ALGraph G, VertexType x, VertexType y)		  //判断在图G中是否存在无向边(x,y)
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)				//不存在顶点
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
					return FALSE;				  //没找到
		  }
		  return FALSE;
}

void DisplayUnDirectNeighbors(ALGraph G, VertexType x)  //输出在无向图G与结点x相邻边(x,?)
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)
		  {
					ArcNode* ptemp = G.Vetics[x_pos].first;
					while (ptemp != NULL)
					{
							  printf("无向边(%c,%c)\n", x, G.Vetics[ptemp->adjvex].data);
							  ptemp = ptemp->next;
					}
		  }
		  return;
}

BOOL	 InsertUnDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //在图G中添加无向无权边(x,y)  ，权值默认为1
{
		  return InsertEdge(G, x, y, 1, UNDIRECTEDGRAPH);
}

BOOL	 InsertUnDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)		//在图G中添加无向含权边(x,y)，支持修改权值
{
		  return InsertEdge(G, x, y, Edge_Value, UNDIRECTEDGRAPH);
}

BOOL	RemoveUnDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //在有向图G删除无向边(x,y)
{
		  return RemoveEdge(G, x, y, UNDIRECTEDGRAPH);
}