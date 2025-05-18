#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct{
	int value[MaxSize];
}TNode, *Tree;

int SearComPar_05(TNode *t,int i,int j){
	if(i<1||i<1||t->value[i]==0||t->value[j]==0){
		cout<<"Invalid imput!"<<endl;
		exit(EXIT_FAILURE);
	}
	else if(i==j){
		return t->value[i/2];
	}
	else{
		while(i!=j){
			if(i>j){
				i=i/2;
			}
			else{
				j=j/2;
			}
		}
		return t->value[i];
	}
}

int main(){
	return 0;
}
