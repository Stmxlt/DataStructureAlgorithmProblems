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

MGraph *Transfer_05(ALGraph *&Neighbor){
	MGraph *Table;
	Table->vexnum=Neighbor->vexnum;
    Table->arcnum=Neighbor->arcnum;
	for(int i=0;i<Neighbor->vexnum;i++){
		ArcNode *p=Neighbor->vertices[i].firstarc;
		while(p!=NULL){
			Table->vex[i]=Neighbor->vertices[i].data;
			Table->edge[i][p->adjvex]=1;
			p=p->nextarc;
		}
	}
	return Table;
}

//07.
//据定义，EL路径存在必要条件是度数为奇数的顶点个数是不大于2的数，遍历所有结点得到度数并求顶点个数 
int IsExistEL_07(MGraph *G){
	int counter=0,flag;  //设置顶点个数计数器和判断器
	int i,j;
	for(i=0;i<G->vexnum;i++){
		int degree=0;  //设置度数计数器 
		for(j=0;j<G->vexnum;j++){
			if(G->edge[i][j]==1){
				degree++;  //统计顶点度数 
			}
		}
		if(degree%2!=0){
			counter++;  //度数是奇数时，统计顶点个数 
		}
	}
	if(counter==0||counter==2){  //顶点个数为不大于2的偶数就是0或2 
		flag=1;
	}
	else{
		flag=0;
	}
	return flag;
}
//时间复杂度是O(n^2)，空间复杂度是O(1)

//8.
//遍历对应顶点的行和列，统计行中出现1的次数就是出度，列中出现1的次数就是入度，这样就可以统计K顶点及K顶点个数 
int printVertices_08(MGraph *G){
	char KVertice[G->vexnum];  //设置K顶点数组，利用K顶点信息填充
	int i,j,k,indegree,outdegree,counter=0;  //设置遍历参数、度信息和K顶点数组参数 
	for(k=0;k<G->vexnum;k++){
		indegree=0,outdegree=0;  //设置度数计数器
		i=k;  //重定向到k行
		for(j=0;j<G->vexnum;j++){
			if(G->edge[i][j]==1){  //统计出度 
				outdegree++;	
			}
		}
		j=k;  //重定向到k列 
		for(i=0;i<G->vexnum;i++){
			if(G->edge[i][j]==1){  //统计入度 
				indegree++;	
			}
		}
		if(outdegree>indegree){  //统计K顶点 
			KVertice[counter]=G->vex[k];
			counter++;
		}
	}
	cout<<"Now print all K-Vertices:"<<endl;
	for(k=0;k<counter;k++){
		cout<<KVertice[k]<<" ";
	}
	cout<<endl;
	return counter;  //返回K顶点数 
}
//时间复杂度是O(|V|^2)，空间复杂度是O(|V|)

int main(){
	return 0;
}
