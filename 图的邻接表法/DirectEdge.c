////#include"DirectEdge.h"
//
////判断在图G中是否存在有向边<x,y>
//int  Adjcent_direct(ALGraph G, VertexType x, VertexType y)
//{
//          int x_pos = 0, x_flag = 0;  //x_flag代表是否找到
///*寻找顶点x在顶点表中的位置*/
//          for (int x_pos = 0; x_pos < G.MaxVertexNum; ++x_pos)
//          {
//                    if (G.Vetics[x_pos].data == x)
//                    {
//                              break;
//                    }
//          }
//          ArcNode* ptemp = G.Vetics[x_pos].first;
//          while (ptemp != NULL)
//          {
//                    if (G.Vetics[ptemp->adjvex].data == y)
//                    {
//                              x_flag = 1;
//                              break;
//                    }
//                    ptemp = ptemp->next;
//          }
//          return x_flag;
//}
//
////输出在有向图G与结点x相邻边<x,?>
//void Neighbors_direct(ALGraph G, VertexType x)
//{
//          int x_pos = 0;
//          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
//          {
//                    if (G.Vetics[x_pos].data == x)
//                    {
//                              break;
//                    }
//          }
//          ArcNode* ptemp = G.Vetics[x_pos].first;
//          while (ptemp != NULL)
//          {
//                    printf("有向边出边<%c,%c>\n", x, G.Vetics[ptemp->adjvex].data);
//                    ptemp = ptemp->next;
//          }
//
//          for (int i = 0; i < G.MaxVertexNum; ++i)
//          {
//                    ptemp = G.Vetics[i].first;
//                    while (ptemp != NULL)
//                    {
//                              if (G.Vetics[ptemp->adjvex].data == x)
//                              {
//                                        printf("有向边入边<%c,%c>\n", G.Vetics[ptemp->adjvex].data, x);
//                                        break;
//                              }
//                              ptemp = ptemp->next;
//                    }
//                    ptemp = NULL;
//          }
//}
//
////在有向图G添加一条有向边<x, y>，该函数支持修改权值
//int AddEdgeDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)
//{
//          int x_pos = 0, y_pos = 0;     //x和y的位置
//          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
//          for (int i = 0; i < G->MaxVertexNum; ++i)
//          {
//                    if (G->Vetics[i].data == x)
//                    {
//                              x_status = 1;                 //顶点x存在
//                              x_pos = i;                    //保存x的位置
//                    }
//                    if (G->Vetics[i].data == y)
//                    {
//                              y_status = 1;                   //顶点y存在
//                              y_pos = i;                    //保存y的位置
//                    }
//          }
//          if (y_pos && x_pos)
//          {
//                    G->arcnum++;        //边数自增
//                    G->Vetics[x_pos].first = CreateLinkNode(G->Vetics[x_pos].first, y_pos, Edge_Value);
//                    return TRUE;
//          }
//          else
//          {
//                    return FALSE;
//          }
//}
//
////在有向图G添加一条有向边<x, y>，该函数不支持修改权值
//int AddEdge_direct(ALGraph* G, VertexType x, VertexType y)
//{
//          return AddEdgeDirectEdgeValue(G, x, y, 1);        //默认权值为1
//}
//
////在有向图G删除一条有向边<x, y>
//int RemoveEdge_direct(ALGraph* G, VertexType x, VertexType y)
//{
//          int x_pos = 0, y_pos = 0;     //x和y的位置
//          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
//          for (int i = 0; i < G->MaxVertexNum; ++i)
//          {
//                    if (G->Vetics[i].data == x)
//                    {
//                              x_status = 1;                 //顶点x存在
//                              x_pos = i;                    //保存x的位置
//                    }
//                    if (G->Vetics[i].data == y)
//                    {
//                              y_status = 1;                   //顶点y存在
//                              y_pos = i;                    //保存y的位置
//                    }
//          }
//          if (y_pos && x_pos)
//          {
//                    G->arcnum--;        //边数自减
//                    G->Vetics[x_pos].first = DeleteLinkNode(G->Vetics[x_pos].first, y_pos);      //删除某个结点
//                    return TRUE;
//          }
//          else
//          {
//                    return FALSE;
//          }
//}