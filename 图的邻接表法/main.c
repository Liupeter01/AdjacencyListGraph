#include"ALGraph.h"
#include"DirectEdge.h"       //����ͼ
#include"UnDirectEdge.h"    //����ͼ

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          VertexType arr[] = { "ABCDEFGHJKL" };         //�������鼯��V(G)
          CreateBatchVertex(&Graph, arr);//�������������Ĵ���



          DisplayGraph(Graph);
          DestroyGraph(&Graph);         //ͼ������
          return 0;
}