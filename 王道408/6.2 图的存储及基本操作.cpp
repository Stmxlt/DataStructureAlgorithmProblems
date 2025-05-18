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
//�ݶ��壬EL·�����ڱ�Ҫ�����Ƕ���Ϊ�����Ķ�������ǲ�����2�������������н��õ��������󶥵���� 
int IsExistEL_07(MGraph *G){
	int counter=0,flag;  //���ö���������������ж���
	int i,j;
	for(i=0;i<G->vexnum;i++){
		int degree=0;  //���ö��������� 
		for(j=0;j<G->vexnum;j++){
			if(G->edge[i][j]==1){
				degree++;  //ͳ�ƶ������ 
			}
		}
		if(degree%2!=0){
			counter++;  //����������ʱ��ͳ�ƶ������ 
		}
	}
	if(counter==0||counter==2){  //�������Ϊ������2��ż������0��2 
		flag=1;
	}
	else{
		flag=0;
	}
	return flag;
}
//ʱ�临�Ӷ���O(n^2)���ռ临�Ӷ���O(1)

//8.
//������Ӧ������к��У�ͳ�����г���1�Ĵ������ǳ��ȣ����г���1�Ĵ���������ȣ������Ϳ���ͳ��K���㼰K������� 
int printVertices_08(MGraph *G){
	char KVertice[G->vexnum];  //����K�������飬����K������Ϣ���
	int i,j,k,indegree,outdegree,counter=0;  //���ñ�������������Ϣ��K����������� 
	for(k=0;k<G->vexnum;k++){
		indegree=0,outdegree=0;  //���ö���������
		i=k;  //�ض���k��
		for(j=0;j<G->vexnum;j++){
			if(G->edge[i][j]==1){  //ͳ�Ƴ��� 
				outdegree++;	
			}
		}
		j=k;  //�ض���k�� 
		for(i=0;i<G->vexnum;i++){
			if(G->edge[i][j]==1){  //ͳ����� 
				indegree++;	
			}
		}
		if(outdegree>indegree){  //ͳ��K���� 
			KVertice[counter]=G->vex[k];
			counter++;
		}
	}
	cout<<"Now print all K-Vertices:"<<endl;
	for(k=0;k<counter;k++){
		cout<<KVertice[k]<<" ";
	}
	cout<<endl;
	return counter;  //����K������ 
}
//ʱ�临�Ӷ���O(|V|^2)���ռ临�Ӷ���O(|V|)

int main(){
	return 0;
}
