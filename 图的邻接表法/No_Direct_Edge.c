#include"No_Direct_Edge.h"

//输出在无向图G与结点x相邻边(x,?)
void Neighbors_nodirect(ALGraph G, VertexType x)
{
          int x_pos = 0;
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vetics[x_pos].data == x)
                    {
                              break;
                    }
          }
          ArcNode* ptemp = G.Vetics[x_pos].first;
          while (ptemp != NULL)
          {
                    printf("无向边(%c,%c)\n", x, G.Vetics[ptemp->adjvex].data);
                    ptemp = ptemp->next;
          }
}

//判断在图G中是否存在无向边(x,y)
int  Adjcent_nodirect(ALGraph G, VertexType x, VertexType y)
{
          int x_pos_1 = 0, x_flag = 0;  //x_flag代表是否找到
          /*寻找顶点x在顶点表中的位置*/
          for (int x_pos_1 = 0; x_pos_1 < G.MaxVertexNum; ++x_pos_1)
          {
                    if (G.Vetics[x_pos_1].data == x)
                    {
                              break;
                    }
          }

          ArcNode* ptemp = G.Vetics[x_pos_1].first;
          while (ptemp != NULL)
          {
                    if (G.Vetics[ptemp->adjvex].data == y)
                    {
                              x_flag = 1;
                              break;
                    }
                    ptemp = ptemp->next;
          }

          int x_pos_2 = 0, y_flag = 0;   //y_flag代表是否找到
          /*寻找顶点y在顶点表中的位置*/
          for (int x_pos_2 = 0; x_pos_2 < G.MaxVertexNum; ++x_pos_2)
          {
                    if (G.Vetics[x_pos_2].data == y)
                    {
                              break;
                    }
          }

          ptemp = G.Vetics[x_pos_2].first;
          while (ptemp != NULL)
          {
                    if (G.Vetics[ptemp->adjvex].data == x)
                    {
                              y_flag = 1;
                              break;
                    }
                    ptemp = ptemp->next;
          }
          return x_flag && y_flag;
}

//在无向图G添加一条无向边(x, y)，该函数支持修改权值
int AddEdgeNoDirectEdgeValue(ALGraph* G, VertexType x, VertexType y, int Edge_Value)
{
          int x_pos = 0, y_pos = 0;     //x和y的位置
          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vetics[i].data == x)
                    {
                              x_status = 1;                 //顶点x存在
                              x_pos = i;                    //保存x的位置
                    }
                    if (G->Vetics[i].data == y)
                    {
                              y_status = 1;                   //顶点y存在
                              y_pos = i;                    //保存y的位置
                    }
          }
          if (y_pos && x_pos)
          {
                    G->arcnum++;        //边数自增
                    G->Vetics[x_pos].first = CreateLinkNode(G->Vetics[x_pos].first, y_pos, Edge_Value);                //为结点x创建
                    G->Vetics[y_pos].first = CreateLinkNode(G->Vetics[y_pos].first, x_pos, Edge_Value);                //为结点y创建
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}

//在无向图G添加一条无向边(x, y)，该函数不支持修改权值使用默认权值1
int AddEdge_nodirect(ALGraph* G, VertexType x, VertexType y)
{
          return AddEdgeNoDirectEdgeValue(G, x, y, 1);   //使用默认为1的权值
}

//在无向图G删除一条无向边(x, y)
int RemoveEdge_nodirect(ALGraph* G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;     //x和y的位置
          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vetics[i].data == x)
                    {
                              x_status = 1;                 //顶点x存在
                              x_pos = i;                    //保存x的位置
                    }
                    if (G->Vetics[i].data == y)
                    {
                              y_status = 1;                   //顶点y存在
                              y_pos = i;                    //保存y的位置
                    }
          }
          if (y_pos && x_pos)
          {
                    G->arcnum--;        //边数自减
                    G->Vetics[x_pos].first = DeleteLinkNode(G->Vetics[x_pos].first, y_pos);      //删除某个结点
                    G->Vetics[y_pos].first = DeleteLinkNode(G->Vetics[y_pos].first, x_pos);     //删除某个结点
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}