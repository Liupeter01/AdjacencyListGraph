#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define VertexType char
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

//根据为顶点表添加边表结点程序，支持权重的添加
ArcNode* CreateLinkNode(ArcNode* head, int position, int edge_value);

//为顶点表删除边表结点，支持权重的添加
ArcNode* DeleteLinkNode(ArcNode* head, int position);

/*图G的初始化*/
void InitGraph(ALGraph* G, int ALGraph_Size);

//在图G中插入结点x
int InsertVertex(ALGraph* G, VertexType x);

/*在图G中批量的插入顶点，使用数组批量创建*/
void CreateBatchVertex(ALGraph* G, VertexType* arr);

//完整链表的清除程序
void RemoveLinkList(ArcNode* phead);

//输出图中某条边的权值
void ShowEdgeValue(ALGraph* G, VertexType x, VertexType y);

/*
*在图中寻找某一个顶点的邻接点
*/
//寻找在图G中顶点x的第一个邻接点
int FirstNeighbor(ALGraph G, VertexType x);

//寻找在图G中顶点X的除了顶点y以外的一个邻接点
int NextNeighbor(ALGraph G, VertexType x, VertexType y);

//在图G中删除结点x
int  DeleteVertex(ALGraph* G, VertexType x);

/*图G的销毁*/
void DestroyGraph(ALGraph* G);