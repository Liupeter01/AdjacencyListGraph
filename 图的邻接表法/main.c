#include"ALGraph.h"
#include"DirectEdge.h"       //有向图
#include"UnDirectEdge.h"    //无向图

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //初始化

          VertexType arr[] = { "ABCDEFGHJKL" };         //顶点数组集合V(G)
          CreateBatchVertex(&Graph, arr);//根据数组批量的创建



          DisplayGraph(Graph);
          DestroyGraph(&Graph);         //图的销毁
          return 0;
}