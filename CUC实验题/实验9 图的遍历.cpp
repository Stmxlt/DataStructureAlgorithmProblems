#include<iostream>
#include<cstdlib>
#define MaxVertexNum 100
using namespace std;

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode; 

typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];

typedef struct{
	AdjList *vertices;
	int vexnum,arcnum;
}ALGraph;

void CreateMgList(int mg[6][6],ALGraph *Mg){
	int i,j,k,di,dj,ni,nj,nk;
	Mg->vexnum=36;
	Mg->arcnum=0;
	Mg->vertices=new AdjList[Mg->vexnum];;
	for(i=0;i<Mg->vexnum;i++){
		Mg->vertices[i]->data=i;
		Mg->vertices[i]->firstarc=NULL;
	}
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			k=i*6+j;
			if(mg[i][j]==0){
				for(di=-1;di<=1;di++){
					for(dj=-1;dj<=1;dj++){
						if((di==-1&&dj==0)||(di==1&&dj==0)||(di==0&&dj==-1)||(di==0&&dj==1)){
							ni=di+i;
							nj=dj+j;
							if(ni>=0&&ni<6&&nj>=0&&nj<6&&mg[ni][nj]==0){
								ArcNode *p=new ArcNode;
								nk=ni*6+nj;
	                	        p->adjvex=nk;
	                	       p->nextarc=Mg->vertices[k]->firstarc;
	                 	       Mg->vertices[k]->firstarc=p;
	                 	       Mg->arcnum++;
							}
						}
					}
				}
			}
		}
	}
}

void DFS(int v,int visited[],int path[][2],int step,int *pathNum,ALGraph *Mg){
    visited[v]=1;
    path[step][0]=v/6;
    path[step][1]=v%6;
    if (v==28){
        (*pathNum)++;
        for(int i=0;i<=step;i++) {
            cout<<"("<<path[i][0]<<","<<path[i][1]<<")";
            if (i<step){
            	cout<<"->";
			}
        }
        cout<<endl;
    }
	else{
        ArcNode *p=Mg->vertices[v]->firstarc;
        while(p){
           int k=p->adjvex;
            if(!visited[k]){
                DFS(k,visited,path,step+1,pathNum,Mg);
            }
            p=p->nextarc;
        }
    }
    visited[v]=0;
}

void PrintAdjList(ALGraph Mg) {
    for(int i=0;i<Mg.vexnum;i++) {
        cout<<"Vertex"<<i<<": ";
        ArcNode *p=Mg.vertices[i]->firstarc;
        while(p){
            cout<<p->adjvex<<" ";
            p=p->nextarc;
        }
        cout<<endl;
    }
}

void FreeGraph(ALGraph *Mg){
    for(int i=0;i<Mg->vexnum;++i){
        ArcNode* current=Mg->vertices[i]->firstarc;
        while(current!=NULL){
            ArcNode* next=current->nextarc;
            delete current;
            current=next;
        }
    }
    delete[]Mg->vertices;
    Mg->vertices=NULL;
    Mg->vexnum=0;
    Mg->arcnum=0;
}

int main(){
	int mg[6][6]={{1,1,1,1,1,1},
		      	  {1,0,0,0,1,1},
		      	  {1,0,1,0,0,1},
		       	  {1,0,0,0,1,1},
				  {1,1,0,0,0,1},
				  {1,1,1,1,1,1}};
	ALGraph Mg_List;
	int visited[MaxVertexNum]={0};
    int path[MaxVertexNum][2];
    int pathNum=0;
	CreateMgList(mg,&Mg_List);
	PrintAdjList(Mg_List);
	DFS(7,visited,path,0,&pathNum,&Mg_List);
	cout<<"This maze have "<<pathNum<<" paths."<<endl;
	FreeGraph(&Mg_List);
	return 0;
}
