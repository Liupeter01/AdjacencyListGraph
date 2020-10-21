/*
*文件名：No_Direct_Edge
*文件用途：用于处理以及操作无向边
*/

#pragma once
#include"ALGraph.h"

//判断在图G中是否存在无向边(x,y)
int  Adjcent_nodirect(ALGraph G, VertexType x, VertexType y);

//输出在无向图G与结点x相邻边(x,?)
void Neighbors_nodirect(ALGraph G, VertexType x);

//在无向图G添加一条无向边(x, y)
int AddEdge_nodirect(ALGraph* G, VertexType x, VertexType y);

//在无向图G删除一条无向边(x, y)
int RemoveEdge_nodirect(ALGraph* G, VertexType x, VertexType y);