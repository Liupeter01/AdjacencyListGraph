/*
*�ļ�����No_Direct_Edge
*�ļ���;�����ڴ����Լ����������
*/

#pragma once
#include"ALGraph.h"

BOOL IsUnDirectEdgeExist(ALGraph G, VertexType x, VertexType y);		  //�ж���ͼG���Ƿ���������(x,y)
void DisplayUnDirectNeighbors(ALGraph G, VertexType x);  //���������ͼG����x���ڱ�(x,?)

//////////////////////////////////////////////////////////ͼ�ı߲�������/////////////////////////////////////////////////////////////////////
BOOL	 InsertUnDirectEdge(ALGraph* G, VertexType x, VertexType y);	  //��ͼG�����������Ȩ��(x,y)  ��ȨֵĬ��Ϊ1
BOOL	 InsertUnDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value);		//��ͼG���������Ȩ��(x,y)��֧���޸�Ȩֵ
BOOL	RemoveUnDirectEdge(ALGraph* G, VertexType x, VertexType y);	  //������ͼGɾ�������(x,y)