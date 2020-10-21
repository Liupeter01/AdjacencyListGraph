#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define VertexType char
typedef struct ArcNode
{
          int adjvex;         //�洢���������±�
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

//����Ϊ�������ӱ߱���
ArcNode* CreateLinkNode(ArcNode* head, int position);

//����Ϊ�����ɾ���߱���
ArcNode* DeleteLinkNode(ArcNode* head, int position);

/*ͼG�ĳ�ʼ��*/
void InitGraph(ALGraph* G, int ALGraph_Size);

//��ͼG�в�����x
int InsertVertex(ALGraph* G, VertexType x);

/*��ͼG�������Ĳ��붥�㣬ʹ��������������*/
void CreateBatchVertex(ALGraph* G, VertexType* arr);

//����������������
void RemoveLinkList(ArcNode* phead);

//��ͼG��ɾ�����x
int  DeleteVertex(ALGraph* G, VertexType x);

/*ͼG������*/
void DestroyGraph(ALGraph* G);