#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct TreeNode{
	int value;
	TreeNode *child,*bro;
}TNode, *Tree;

int time=0;

int LeafNum_04(TNode *t){  //引入全局变量递归做法 
	if(t->child==NULL){
		time++;
	}
	else if(t->child!=NULL){
		LeafNum_04(t->child);
	}
	else if(t->bro!=NULL){
		LeafNum_04(t->bro);
	}
	return time;
}

int LeafNumRefine_04(TNode *t){  //不引入全局变量递归做法 
	if(t==NULL){
		return 0;
	}
	if(t->child==NULL){
		return 1+LeafNumRefine_04(t->child)+LeafNumRefine_04(t->bro);
	}
	else if(t->child!=NULL){
		return LeafNumRefine_04(t->child)+LeafNumRefine_04(t->bro);
	}
}

int DepTree_05(TNode *t){
	if(t==NULL){
		return 0;
	}
	else{
		int h1=DepTree_05(t->child)+1;
		int h2=DepTree_05(t->bro);
		return h1>=h2?h1:h2;
	}
}

int main(){
	return 0;
}
