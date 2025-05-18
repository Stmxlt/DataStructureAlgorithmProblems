#include<iostream>
#include<cstdlib>
#define MaxVertexNum 100
using namespace std;

typedef struct{  //邻接矩阵 
	char vex[MaxVertexNum];
	int edge[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;

typedef struct ArcNode{  //边表
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode; 

typedef struct VNode{  //顶点表
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];

typedef struct{  //邻接表 
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

void FreshArray(bool visited[MaxVertexNum]){
	for(int i=0;i<MaxVertexNum;i++){
		visited[i]=false;
	}
}

void DFS(MGraph *G,int i,bool visited[]){
	visited[i]=true;
	for(int j=0;j<G->vexnum;j++){
		if(visited[j]==false&&G->edge[i][j]==1){
			DFS(G,j,visited);
		}
	}
}

void TopoOrder_07(MGraph *G){
	//太难了不想写~ 
}

int main(){
	bool visited[MaxVertexNum];
	FreshArray(visited);
	return 0;
} 
