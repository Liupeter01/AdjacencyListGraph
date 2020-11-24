#include"DirectEdge.h"

BOOL IsDirectEdgeExist(ALGraph G, VertexType x, VertexType y)		  //判断在图G中是否存在有向边<x,y>
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

void DisplayDirectNeighbors(ALGraph G, VertexType x) //输出在有向图G与结点x相邻边<x,?><?,x>
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)
		  {
					ArcNode* ptemp = G.Vetics[x_pos].first;
					while (ptemp != NULL)
					{
							  printf("有向边出边<%c,%c>\n", x, G.Vetics[ptemp->adjvex].data);
							  ptemp = ptemp->next;
					}
					for (int i = 0; i < G.vexnum; ++i)
					{
							  ptemp = G.Vetics[i].first;
							  while (ptemp != NULL)
							  {
										if (G.Vetics[ptemp->adjvex].data == x)
										{
												  printf("有向边入边<%c,%c>\n", G.Vetics[ptemp->adjvex].data, x);
										}
										ptemp = ptemp->next;
							  }
					}
		  }
		  return;
}

int CalculateEnVertex(ALGraph G, VertexType x)			//计算某一个顶点的入度数量
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)				//不存在顶点
		  {
					int counter = 0;				//计数器
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
					return counter;				  //找到
		  }
		  return -1;		  //出错
}

int CalculateOutVertex(ALGraph G, VertexType x)			//计算某一个顶点的出度数量
{
		  int x_pos = LocateVertex(G, x);
		  if (x_pos != -1)				//不存在顶点
		  {
					int counter = 0;				//计数器
					ArcNode* ptemp = G.Vetics[x_pos].first;
					while (ptemp != NULL)
					{
							  ++counter;
							  ptemp = ptemp->next;
					}
					return counter;				  //找到
		  }
		  return -1;		  //出错
}

BOOL	 InsertDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //在图G中添加有向无权边<x,y>  ，权值默认为1
{
		  return InsertEdge(G, x, y, 1, DIRECTEDGRAPH);
}

BOOL	 InsertDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)	//在图G中添加有向含权边<x,y>，支持修改权值
{
		  return InsertEdge(G, x, y, Edge_Value, DIRECTEDGRAPH);
}

BOOL	RemoveDirectEdge(ALGraph* G, VertexType x, VertexType y)	  //在有向图G删除有向边<x, y>
{
		  return RemoveEdge(G, x, y, DIRECTEDGRAPH);
}