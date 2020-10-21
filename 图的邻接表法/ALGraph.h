#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define VertexType char
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

//����Ϊ�������ӱ߱������֧��Ȩ�ص����
ArcNode* CreateLinkNode(ArcNode* head, int position, int edge_value);

//Ϊ�����ɾ���߱��㣬֧��Ȩ�ص����
ArcNode* DeleteLinkNode(ArcNode* head, int position);

/*ͼG�ĳ�ʼ��*/
void InitGraph(ALGraph* G, int ALGraph_Size);

//��ͼG�в�����x
int InsertVertex(ALGraph* G, VertexType x);

/*��ͼG�������Ĳ��붥�㣬ʹ��������������*/
void CreateBatchVertex(ALGraph* G, VertexType* arr);

//����������������
void RemoveLinkList(ArcNode* phead);

//���ͼ��ĳ���ߵ�Ȩֵ
void ShowEdgeValue(ALGraph* G, VertexType x, VertexType y);

/*
*��ͼ��Ѱ��ĳһ��������ڽӵ�
*/
//Ѱ����ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(ALGraph G, VertexType x);

//Ѱ����ͼG�ж���X�ĳ��˶���y�����һ���ڽӵ�
int NextNeighbor(ALGraph G, VertexType x, VertexType y);

//��ͼG��ɾ�����x
int  DeleteVertex(ALGraph* G, VertexType x);

/*ͼG������*/
void DestroyGraph(ALGraph* G);