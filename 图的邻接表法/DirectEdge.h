/*
*�ļ�����Direct_Edge
*�ļ���;�����ڴ����Լ����������
*/

#pragma once
#include"ALGraph.h"

BOOL IsDirectEdgeExist(ALGraph G, VertexType x, VertexType y);		  //�ж���ͼG���Ƿ���������<x,y>
void DisplayDirectNeighbors(ALGraph G, VertexType x);  //���������ͼG����x���ڱ�<x,?>

//////////////////////////////////////////////////////////ͼ�Ľ���������/////////////////////////////////////////////////////////////////////
int CalculateEnVertex(ALGraph G, VertexType x);			//����ĳһ��������������
int CalculateOutVertex(ALGraph G, VertexType x);			//����ĳһ������ĳ�������

//////////////////////////////////////////////////////////ͼ�ı߲�������/////////////////////////////////////////////////////////////////////
BOOL	 InsertDirectEdge(ALGraph* G, VertexType x, VertexType y);	  //��ͼG�����������Ȩ��<x,y>  ��ȨֵĬ��Ϊ1
BOOL	 InsertDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value);		//��ͼG���������Ȩ��<x,y>��֧���޸�Ȩֵ
BOOL	RemoveDirectEdge(ALGraph* G, VertexType x, VertexType y);	  //������ͼGɾ�������<x, y>
