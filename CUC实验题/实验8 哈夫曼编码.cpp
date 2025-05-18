#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits> 
#define MaxSize 50
using namespace std;

typedef struct{
	char data[MaxSize];
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct{
	char cd[MaxSize];
	int start;
}HCode;

void CreateHT(HTNode ht[],int n0){
	for(int i=0;i<2*n0-1;i++){
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	}
	for(int i=n0;i<2*n0-1;i++){
		int min1=INT_MAX,min2=INT_MAX;
		int lnode=-1,rnode=-1;
		for(int k=0;k<i;k++){
			if(ht[k].parent==-1){
				if(ht[k].weight<min1){
					min2=min1;
					rnode=lnode;
					min1=ht[k].weight;
					lnode=k;
				}
				else if(ht[k].weight<min2){
					min2=ht[k].weight;
					rnode=k;
				}
			}
		}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;
		ht[i].rchild=rnode;
		ht[lnode].parent=i;
		ht[rnode].parent=i;
	}
}


void CreateHCode(HTNode ht[],HCode hcd[],int n0){
	int i,f,c;
	HCode hc;
	for(i=0;i<n0;i++){
		hc.start=n0-1;
		c=i;
		f=ht[i].parent;
		while(f!=-1){
			if(ht[f].lchild==c){
				hc.cd[hc.start--]='0';
			}
			else{
				hc.cd[hc.start--]='1';
			}
			c=f;
			f=ht[f].parent;
		}
		hc.cd[n0]='\0';
		hcd[i]=hc;
	}
}

double ComputeWPL(HTNode ht[],int n0){
    double wpl=0.0;
    for(int i=0;i<n0;i++){
        int pathLength=0;
        int currentNode=i;
        while(ht[currentNode].parent!=-1){
            pathLength++;
            currentNode=ht[currentNode].parent;
        }
        wpl+=(double)ht[i].weight*pathLength;
    }
    return wpl;
}

int main(){
	int i=0,n0=15,sum_weight=0;
	HTNode ht[2*n0-1];
	HCode hcd[n0];
	const char *words[]={"the","of","a","to","and","in","that","he","is","at","on","for","his","are","be"};
    const int weights[]={1192,677,541,518,462,450,242,195,190,181,174,157,138,124,123};
	for(int i=0;i<n0;i++){
        strcpy(ht[i].data,words[i]);
        ht[i].weight=weights[i];
    }
	CreateHT(ht,n0);
	CreateHCode(ht,hcd,n0);
	double WPL=ComputeWPL(ht,n0);
	cout<<"哈夫曼编码及其频率："<<endl; 
	for(i=0;i<n0;i++){
        cout<<ht[i].data<<": "<<hcd[i].cd+hcd[i].start+1<<endl;
    }
	cout<<"带权平均长度是："<<WPL<<endl;
	return 0;
}
