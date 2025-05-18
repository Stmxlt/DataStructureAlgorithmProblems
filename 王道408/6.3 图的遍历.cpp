#include<iostream>
#include<cstdlib>
#define MaxVertexNum 100
#define MaxSize 50
using namespace std;

typedef struct{
	int data[MaxSize];
	int front,rear;
}SqQueue;

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

void InitQueue(SqQueue *&q){
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=-1;
}

bool EmptyQueue(SqQueue *&q){
	if(q->front==q->rear){
		return true;
	}
	else{
		return false;
	}
}

bool EnQueue(SqQueue *&q,int e){
	if((q->rear+1)%MaxSize==q->front){
		return false;
	}
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}

bool DeQueue(SqQueue *&q,int &e){
	if(q->rear==q->front){
		return false;
	}
	e=q->data[q->front];
	q->front=(q->front+1)%MaxSize;
	return true;
}

void FreshArray(bool visited[MaxVertexNum]){
	for(int i=0;i<MaxVertexNum;i++){
		visited[i]=false;
	}
}

bool JudgeTree_03(MGraph *G){
	if(G==NULL){
		return true;
	}
	int i=0,j=0,counter;
	for(i;i<G->vexnum;i++){  //度检查 
		counter=0;
		for(j;j<G->vexnum;j++){
			if(G->edge[i][j]==1){
				counter++;
			}
		}
		if(counter>1){
			return false;
		}
	}
	return true;
}

bool DeepFindRoute_04(ALGraph *G,int i,char j,bool visited[]){
	visited[i]=true;
	for(ArcNode *p=G->vertices[i].firstarc;p!=NULL;p=p->nextarc){
		int k=p->adjvex;
		if(G->vertices[k].data==j){
			return true;
		}
		if(visited[k]==false){
			DeepFindRoute_04(G,k,j,visited);
		}
	}
	return false;
}

bool BroadFindRoute_04(ALGraph *G,int i,char j,bool visited[]){
	SqQueue *q;
	InitQueue(q);
	visited[i]=true;
	EnQueue(q,i);
	while(!EmptyQueue(q)){
		int v;
		DeQueue(q,v);
		for(ArcNode *p=G->vertices[v].firstarc;p!=NULL;p=p->nextarc){
			int w=p->adjvex;
			if(visited[w]==false){
				if(G->vertices[w].data==j){
					free(q);
					return true;
				}
				visited[w]=true;
				EnQueue(q,w);
			}
		}
	}
	return false;
}

void PrintRoute_05(ALGraph *G,int i,char j,bool visited[],char Path[],int &PathIndex){
	visited[i]=true;
	ArcNode *p=G->vertices[i].firstarc;
	Path[PathIndex++]=G->vertices[i].data;
	for(p;p!=NULL;p=p->nextarc){
		int k=p->adjvex;
		if(G->vertices[k].data==j){
			for(int idx=0;idx<PathIndex;idx++){
				cout<<Path[idx]<<" ";
			}
			cout<<endl;
		}
		else if(visited[k]==false){
			PrintRoute_05(G,k,j,visited,Path,PathIndex);
		}
	}
	visited[i]={false};
	PathIndex--;
}

int main(){
	bool visited[MaxVertexNum];
	FreshArray(visited);
	
	return 0;
}
