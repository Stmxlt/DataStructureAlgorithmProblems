#include<iostream>
#include<cstdlib>
#define MaxVertexNum 100
using namespace std;

typedef struct{  //�ڽӾ��� 
	char vex[MaxVertexNum];
	int edge[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;

typedef struct ArcNode{  //�߱�
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode; 

typedef struct VNode{  //�����
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];

typedef struct{  //�ڽӱ� 
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
	//̫���˲���д~ 
}

int main(){
	bool visited[MaxVertexNum];
	FreshArray(visited);
	return 0;
} 
