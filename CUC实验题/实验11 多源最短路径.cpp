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

void FloydGraph(MGraph G) {
    int distance[V][V];
    int next[V][V];
    int i,j,k;

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            distance[i][j]=G.edge_info[i][j];
            if(distance[i][j]!=INT_MAX&&i!=j){
                next[i][j]=j;
            } 
			else{
                next[i][j]=-1;
            }
        }
    }

    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(distance[i][k]!=INT_MAX&&distance[k][j]!=INT_MAX&&distance[i][k]+distance[k][j]<distance[i][j]){
                	distance[i][j]=distance[i][k]+distance[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }

    cout<<"Shortest path lengths:"<<endl;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(distance[i][j]==INT_MAX){
            	cout<<"INF";
			}
            else{
            	if(distance[i][j]>=10){
            		cout<<distance[i][j]<<" ";
				}
            	else{
            		cout<<distance[i][j]<<"  ";
				}
			}
        }
        cout<<endl;
    }

    cout<<"Shortest paths:"<<endl;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(i==j){
                continue;
            } 
			else if(distance[i][j]==INT_MAX){
                cout<<"No path"<<endl;
            }
			else{
                cout<<"Path from "<<G.vex[i]<<" to "<<G.vex[j]<<": ";
                int path[V];
                int m=0;
                int u=i,v=j;
                while(u!=v){
                    path[m++]=u;
                    u=next[u][v];
                }
                path[m++]=j;
                for(int k=0;k<m;k++){
                    cout<<G.vex[path[k]];
                    if(k<m-1)cout<<"->";
                }
                cout<<endl;
            }
        }
    }
}

int main(){
	int Matrix[V][V]={{0,5,0,7,0,0},
		      	  	  {0,0,4,0,0,0},
		      	   	  {8,0,0,0,0,9},
		       	      {0,0,5,0,0,6},
				      {0,0,0,5,0,0},
				  	  {3,0,0,0,1,0}};
	MGraph G;
	CreateMGraph(G,Matrix);
	FloydGraph(G);
	return 0;
}
