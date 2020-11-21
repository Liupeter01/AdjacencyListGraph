#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define Default_Graph_Size 10 //默认的大小
#define VertexType char

/*图的类型设定*/
#define DIRECTEDGRAPH 0x33    //有向图
#define UNDIRECTEDGRAPH 0x44  //无向图

typedef struct ArcNode
{
          int adjvex;         //存储顶点数组下标
          int edge_value;     //存储边的权
          struct ArcNode* next;         //下一个
}ArcNode;

typedef struct VNode
{
          VertexType data;    //顶点名称
          ArcNode* first;     //边表的头指针
}VNode, AdjList;

typedef struct ALGraph
{
          AdjList *Vetics;     //邻接表
          int vexnum;       //顶点数量  
          int arcnum;         //边的数量
          int MaxVertexNum;   //图的最大容量
}ALGraph;

ArcNode* CreateArcNode(int VercticsPos, int Edge_Value);    //边表结点创建模块，根据顶点为止和权创建边表结点

//////////////////////////////////////////////////////////图的基本操作函数/////////////////////////////////////////////////////////////////////
void InitGraph(ALGraph* G);   //图G的初始化
void RemoveLinkList(ArcNode* phead);              //链表的清除程序
void DestroyGraph(ALGraph* G);          //图G的销毁
void DisplayGraph(ALGraph G);            //图G的输出
int LocateVertex(ALGraph G, VertexType x);                  //在图G中找到顶点下标
void ShowEdgeValue(ALGraph G, VertexType x, VertexType y);            //输出图中某条边的权值
BOOL ExtendGraphSize(ALGraph* G, VertexType* arr);          //分配内存空间

////////////////////////////////////////////////////////////图的边操作函数/////////////////////////////////////////////////////////////////////
/*需要传递图，以及边的两个顶点，边的权(默认为1)，图的类型*/
BOOL InsertEdge(ALGraph* G, VertexType x, VertexType y, int Edge_Value, int Type);         //在图中插入边

/*需要传递图，以及边的两个顶点，图的类型*/
BOOL RemoveEdge(ALGraph* G, VertexType x, VertexType y, int Type);      //在图G中删除边

////////////////////////////////////////////////////////////图的结点操作函数/////////////////////////////////////////////////////////////////////
BOOL InsertVertex(ALGraph* G, VertexType x);        //在图G中插入结点x
void CreateBatchVertex(ALGraph* G, VertexType* arr);     //在图G中批量插入顶点
ArcNode* DeleteLinkNode(ALGraph* G, ArcNode* head, VertexType x);   //删除含有结点x的边表结点
BOOL RemoveVertex(ALGraph* G, VertexType x);                  //在图G中删除结点x

////////////////////////////////////////////////////////////图的邻接顶点操作函数/////////////////////////////////////////////////////////////////////
/*在图G中顶点X的第一个邻接点，若有则返回顶点号，若没有则返回-1*/
int FindFirstNeighbor(ALGraph G, VertexType x);              //在图中寻找某一个顶点x的第一个邻接顶点y

/*在图G中顶点X的第一个邻接点，返回除了顶点y以外的下一个顶点号，若y是x的最后一个邻接点，则返回-1*/
int FindNextNeighbor(ALGraph G, VertexType x, VertexType y);           //在图中寻找某一个顶点x的除了顶点y以外的，第二个邻接顶点