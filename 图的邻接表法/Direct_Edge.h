/*
*�ļ�����Direct_Edge
*�ļ���;�����ڴ����Լ����������
*/

#pragma once
#include"ALGraph.h"

//�ж���ͼG���Ƿ���������<x,y>
int  Adjcent_direct(ALGraph G, VertexType x, VertexType y);

//���������ͼG����x���ڱ�<x,?>
void Neighbors_direct(ALGraph G, VertexType x);

//������ͼG���һ�������<x, y>���ú�����֧���޸�Ȩֵ
int AddEdge_direct(ALGraph* G, VertexType x, VertexType y);



//������ͼGɾ��һ�������<x, y>
int RemoveEdge_direct(ALGraph* G, VertexType x, VertexType y);