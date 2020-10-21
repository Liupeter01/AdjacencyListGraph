#include"ALGraph.h"
#include"Direct_Edge.h"       //����ͼ
#include"No_Direct_Edge.h"    //����ͼ

int main()
{
          int ALGraph_Size = 0;          //ͼ�Ĵ�С
          printf("������ͼ�Ĵ�С��");
          scanf("%d", &ALGraph_Size);

          ALGraph Graph;
          InitGraph(&Graph, ALGraph_Size);         //��ʼ��

          VertexType arr[] = { "ABCDE" };         //�������鼯��V(G)
          CreateBatchVertex(&Graph, arr);//�������������Ĵ���

          /*��������*/
          AddEdge_nodirect(&Graph, 'A', 'B');
          AddEdge_nodirect(&Graph, 'B', 'C');
          AddEdge_nodirect(&Graph, 'C', 'D');
          AddEdge_nodirect(&Graph, 'C', 'E');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}