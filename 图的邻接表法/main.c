#include"ALGraph.h"
#include"Direct_Edge.h"       //有向图
#include"No_Direct_Edge.h"    //无向图

int main()
{
          int ALGraph_Size = 0;          //图的大小
          printf("请输入图的大小：");
          scanf("%d", &ALGraph_Size);

          ALGraph Graph;
          InitGraph(&Graph, ALGraph_Size);         //初始化

          VertexType arr[] = { "ABCDE" };         //顶点数组集合V(G)
          CreateBatchVertex(&Graph, arr);//根据数组批量的创建

          /*添加无向边*/
          AddEdge_nodirect(&Graph, 'A', 'B');
          AddEdge_nodirect(&Graph, 'B', 'C');
          AddEdge_nodirect(&Graph, 'C', 'D');
          AddEdge_nodirect(&Graph, 'C', 'E');

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}