#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define Default_Graph_Size 10 //Ĭ�ϵĴ�С
#define VertexType char

/*ͼ�������趨*/
#define DIRECTEDGRAPH 0x33    //����ͼ
#define UNDIRECTEDGRAPH 0x44  //����ͼ

typedef struct ArcNode
{
          int adjvex;         //�洢���������±�
          int edge_value;     //�洢�ߵ�Ȩ
          struct ArcNode* next;         //��һ��
}ArcNode;

typedef struct VNode
{
          VertexType data;    //��������
          ArcNode* first;     //�߱��ͷָ��
}VNode, AdjList;

typedef struct ALGraph
{
          AdjList *Vetics;     //�ڽӱ�
          int vexnum;       //��������  
          int arcnum;         //�ߵ�����
          int MaxVertexNum;   //ͼ���������
}ALGraph;

ArcNode* CreateArcNode(int VercticsPos, int Edge_Value);    //�߱��㴴��ģ�飬���ݶ���Ϊֹ��Ȩ�����߱���

//////////////////////////////////////////////////////////ͼ�Ļ�����������/////////////////////////////////////////////////////////////////////
void InitGraph(ALGraph* G);   //ͼG�ĳ�ʼ��
void RemoveLinkList(ArcNode* phead);              //������������
void DestroyGraph(ALGraph* G);          //ͼG������
void DisplayGraph(ALGraph G);            //ͼG�����
int LocateVertex(ALGraph G, VertexType x);                  //��ͼG���ҵ������±�
void ShowEdgeValue(ALGraph G, VertexType x, VertexType y);            //���ͼ��ĳ���ߵ�Ȩֵ
BOOL ExtendGraphSize(ALGraph* G, VertexType* arr);          //�����ڴ�ռ�

////////////////////////////////////////////////////////////ͼ�ı߲�������/////////////////////////////////////////////////////////////////////
/*��Ҫ����ͼ���Լ��ߵ��������㣬�ߵ�Ȩ(Ĭ��Ϊ1)��ͼ������*/
BOOL InsertEdge(ALGraph* G, VertexType x, VertexType y, int Edge_Value, int Type);         //��ͼ�в����

/*��Ҫ����ͼ���Լ��ߵ��������㣬ͼ������*/
BOOL RemoveEdge(ALGraph* G, VertexType x, VertexType y, int Type);      //��ͼG��ɾ����

////////////////////////////////////////////////////////////ͼ�Ľ���������/////////////////////////////////////////////////////////////////////
BOOL InsertVertex(ALGraph* G, VertexType x);        //��ͼG�в�����x
void CreateBatchVertex(ALGraph* G, VertexType* arr);     //��ͼG���������붥��
ArcNode* DeleteLinkNode(ALGraph* G, ArcNode* head, VertexType x);   //ɾ�����н��x�ı߱���
BOOL RemoveVertex(ALGraph* G, VertexType x);                  //��ͼG��ɾ�����x

////////////////////////////////////////////////////////////ͼ���ڽӶ����������/////////////////////////////////////////////////////////////////////
/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ���û���򷵻�-1*/
int FindFirstNeighbor(ALGraph G, VertexType x);              //��ͼ��Ѱ��ĳһ������x�ĵ�һ���ڽӶ���y

/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬���س��˶���y�������һ������ţ���y��x�����һ���ڽӵ㣬�򷵻�-1*/
int FindNextNeighbor(ALGraph G, VertexType x, VertexType y);           //��ͼ��Ѱ��ĳһ������x�ĳ��˶���y����ģ��ڶ����ڽӶ���