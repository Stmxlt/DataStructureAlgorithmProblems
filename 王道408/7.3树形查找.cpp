#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct BiTNode{
	int data,count;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
	int data[MaxSize];
	int top;
}SqStack;

bool EmptyStack(SqStack *&s){
	return(s->top==-1);
}

bool Push(SqStack *&s,int e){
	if(s->top==MaxSize-1){
		return false;
	}
	s->top++;
	s->data[s->top]=e;
}

bool Pop(SqStack *&s,int &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
}

int low=-32767;

bool JudgeBST_05(BiTNode *t){
	bool left,right;
	if(t==NULL){
		return true;
	}
	else{
		left=JudgeBST_05(t->lchild);
		if(left==false||low>=t->data){
			return false;
		}
		low=t->data;
		right=JudgeBST_05(t->rchild);
		return right;
	}
}

int Level_06(BiTNode *t,int key){
	if(t==NULL){
		cout<<"Empty tree!"<<endl;
		exit(EXIT_FAILURE);
	}
	int level=1;
	while(t->data!=key&&t!=NULL){
		if(t->data<key){
			t=t->rchild;
			level++;
		}
		else{
			t=t->lchild;
			level++;
		}
	}
	if(t->data==key&&t!=NULL){
		return level;
	}
	else{
		cout<<"False key!"<<endl;
		exit(EXIT_FAILURE);
	}
}

void JudgeAVL_07(BiTNode *t,int &balance,int &h){
	int bl=0,br=0,hl=0,hr=0;
	if(t==NULL){
		h=0;
		balance=1;
	}
	else if(t->lchild==NULL&&t->rchild==NULL){
		h=1;
		balance=1;
	}
	else{
		JudgeAVL_07(t->lchild,bl,hl);
		JudgeAVL_07(t->rchild,br,hr);
		h=(hl>hr?hl:hr)+1;
		if(abs(hl-hr)<2){
			balance=bl&&br;
		}
		else{
			balance=0;
		}
	}
}

void FindLowHigh_08(BiTNode *t){
	BiTNode *root=t;
	if(t==NULL){
		cout<<"Empty tree!"<<endl;
		return;
	}
	while(t->lchild!=NULL){
		t=t->lchild;
	}
	cout<<"The lowest number is "<<t->data<<endl;
	t=root;
	while(t->rchild!=NULL){
		t=t->rchild;
	}
	cout<<"The biggest number is "<<t->data<<endl;
}

void HalfSearch_09(BiTNode *t,SqStack *&sq){
	if(t==NULL){
		return;
	}
	HalfSearch_09(t->lchild,sq);
	Push(sq,t->data);
	HalfSearch_09(t->rchild,sq);
}

void ShowMoreKey_09(SqStack *&sq,int key){
	int e=99999;
	cout<<"The number more than or equal to key:"<<endl;
	while(!EmptyStack(sq)){
		Pop(sq,e);
		if(e>=key){
			cout<<e<<" ";
		}
	}
}

void OutPutRefined_09(BiTNode *t,int key){
	if(t==NULL){
		return;
	}
	if(t->rchild!=NULL){
		OutPutRefined_09(t->rchild,key);
	}
	if(t->data>=key){
		cout<<t->data<<" ";
	}
	if(t->lchild!=NULL){
		OutPutRefined_09(t->lchild,key);
	}
}

BiTNode *SearchSmall_10(BiTNode *t,int key){
	if(key<1||key>t->count){
		return;
	}
	if(t->lchild!=NULL){
		if(k==1){
			return t;
		}
		else{
			return SearchSmall_10(t->rchild,key-1);
		}
	}
	else{
		if(t->lchild->count==k-1){
			return t;
		}
		if(t->lchild->count>k-1){
			return SearchSmall_10(t->lchild,key);
		}
		if(t->lchild->count<k-1){
			return SearchSmall_10(t->rchild,key-(t->lchild->count+1));
		}
	}
}

int main(){
	return 0;
}
