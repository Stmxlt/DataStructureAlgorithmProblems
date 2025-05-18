#include<iostream>
#include<cstring> 
#include<climits>
#define V 6
#define MaxVertexNum 100
using namespace std;

typedef struct{ 
	char vex[MaxVertexNum];
	int edge_info[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;

void CreateMGraph(MGraph &G,int M[V][V]){
	int i,j;
	G.vexnum=V;
	G.arcnum=0;
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(M[i][j]!=0){
				G.arcnum++;
			}
		}
	}
	strcpy(G.vex,"012345");
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(M[i][j]==0){
				G.edge_info[i][j]=(i==j)?0:INT_MAX;
			}
		}
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(M[i][j]!=0){
				G.edge_info[i][j]=M[i][j];
			}
		}
	}
}

void PrimGraph(MGraph G){
	int min,i,j,k;
    int adjvex[MaxVertexNum];
    int lowcost[MaxVertexNum];
    bool mstset[MaxVertexNum];
    for(i=0;i<G.vexnum;i++){
    	lowcost[i]=G.edge_info[0][i];
        adjvex[i]=0;
        mstset[i]=false;
	}
    mstset[0]=true;

    for(i=1;i<G.vexnum;i++) {
        min=INT_MAX;
        j=-1;
        for(k=0;k<G.vexnum;k++) {
            if(!mstset[k]&&lowcost[k]<min){
                min=lowcost[k];
                j=k;
            }
        }
        mstset[j]=true;
        for(k=0;k<G.vexnum;k++) {
            if(!mstset[k]&&G.edge_info[j][k]<lowcost[k]){
                lowcost[k]=G.edge_info[j][k]; 
                adjvex[k]=j;
            }
        }
    }

    cout<<"Print MST:"<<endl;
    for(i=1;i<G.vexnum;i++){
        cout<<G.vex[adjvex[i]]<<"-"<<G.vex[i]<<":"<<G.edge_info[adjvex[i]][i]<<endl;;
    }
}

void DijkstraGraph(MGraph G) {
    int dist[MaxVertexNum];
    bool sptSet[MaxVertexNum];
    int parent[MaxVertexNum];
    for(int i=0;i<G.vexnum;i++){
        dist[i]=G.edge_info[0][i];
        parent[i]=(dist[i]<INT_MAX)?0:-1;
        sptSet[i]=false;
    }
    dist[0]=0;

    for(int count=0;count<G.vexnum-1;count++){
        int u=-1;
        int min=INT_MAX;
        for(int i=0;i<G.vexnum;i++){
            if(!sptSet[i]&&dist[i]<min){
                min=dist[i];
                u=i;
            }
        }
        sptSet[u]=true;
        for(int v=0;v<G.vexnum;v++) {
            if(!sptSet[v]&&G.edge_info[u][v]!=INT_MAX&&dist[u]!=INT_MAX&&dist[u]+G.edge_info[u][v]<dist[v]){
                dist[v]=dist[u]+G.edge_info[u][v];
                parent[v]=u;
            }
        }
    }

    cout<<"Vertex \t Distance from "<<G.vex[0]<<endl;
    for(int i=0;i<G.vexnum;i++){
        cout<<"  "<<G.vex[i]<<"\t\t"<<dist[i]<<endl;
    }
}

int main(){
	int Matrix1[V][V]={{0,5,8,7,0,3},
		      	  	   {5,0,4,0,0,0},
		      	   	   {8,4,0,5,0,9},
		       	  	   {7,0,5,0,5,6},
				  	   {0,0,0,5,0,1},
				  	   {3,0,9,6,1,0}};
	int Matrix2[V][V]={{0,5,0,7,0,0},
		      	  	   {0,0,4,0,0,0},
		      	   	   {8,0,0,0,0,9},
		       	  	   {0,0,5,0,0,6},
				  	   {0,0,0,5,0,0},
				  	   {3,0,0,0,1,0}};
	MGraph G1;
	MGraph G2;
	CreateMGraph(G1,Matrix1);
	CreateMGraph(G2,Matrix2);
	PrimGraph(G1);
	DijkstraGraph(G2);
	return 0;
}
