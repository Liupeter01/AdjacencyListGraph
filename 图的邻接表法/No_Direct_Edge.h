/*
*�ļ�����No_Direct_Edge
*�ļ���;�����ڴ����Լ����������
*/

#pragma once
#include"ALGraph.h"

//�ж���ͼG���Ƿ���������(x,y)
int  Adjcent_nodirect(ALGraph G, VertexType x, VertexType y);

//���������ͼG����x���ڱ�(x,?)
void Neighbors_nodirect(ALGraph G, VertexType x);

//������ͼG���һ�������(x, y)
int AddEdge_nodirect(ALGraph* G, VertexType x, VertexType y);

//������ͼGɾ��һ�������(x, y)
int RemoveEdge_nodirect(ALGraph* G, VertexType x, VertexType y);