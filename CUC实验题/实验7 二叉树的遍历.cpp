#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
	BiTree data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

bool EmptyStack(SqStack *&s){
	return(s->top==-1);
}

bool Push(SqStack *&s,BiTree e){
	if(s->top==MaxSize-1){
		return false;
	}
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool GetTop(SqStack *s,BiTree &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	return true;
}

bool Pop(SqStack *&s,BiTree &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return true;
}

void FreeTree(BiTree &t) {
    if (t == NULL) return;
    FreeTree(t->lchild);
    FreeTree(t->rchild);
    free(t);
}

void CreateBTree(BiTNode *&b,const char *str){
	BiTNode *St[MaxSize],*p=NULL;
	int top=-1,k=0,j=0;
	char ch=str[j];
	b=NULL;
	while(ch!='\0'){
		switch(ch){
			case '(':
				top++;
				St[top]=p;
				k=1;
				break;
			case ')':
				top--;
				break;
			case ',':
				k=2;
				break;
			default:
				p=(BiTNode *)malloc(sizeof(BiTNode));
				p->data=ch;
				p->lchild=p->rchild=NULL;
				if(b==NULL){
					b=p;
				}
				else{
					if(k==1){
						St[top]->lchild=p;
					}
					if(k==2){
						St[top]->rchild=p;
					}
				}
				break;
			}
		j++;
		ch=str[j];
	}
}

void PreScan(BiTNode *t,SqStack *&s){
	if(t==NULL){
		return;
	}
	Push(s,t);
	if(t->lchild==NULL&&t->rchild==NULL){
		for(int i=s->top;i>=0;i--){
			cout<<s->data[i]->data<<" ";
		}
		cout<<endl;
	}
	if(t->lchild){
		PreScan(t->lchild,s);
	}
	if(t->rchild){
		PreScan(t->rchild,s);
	}
	BiTree temp;
    Pop(s,temp);
}

void PostScan(BiTNode *t,SqStack *&path){
	if(t==NULL){
		return;
	}
	SqStack *stack=NULL;
	InitStack(stack);
	BiTree lastVisited=NULL;
	BiTree current=t;
	while(!EmptyStack(stack)||current!=NULL){
        while(current!=NULL) {
            Push(stack,current);
            Push(path,current);
            current=current->lchild;
        }
        BiTree topNode;
        GetTop(stack,topNode);
        if(topNode->rchild!=NULL&&topNode->rchild!=lastVisited){
            current=topNode->rchild;
        }
		else{
            if(topNode->lchild == NULL&&topNode->rchild==NULL){
                for(int i=path->top;i>=0;i--){
                    cout<<path->data[i]->data<<" ";
                }
                cout<<endl;
            }
            Pop(stack,topNode);
            Pop(path,topNode);
            lastVisited=topNode;
        }
    }
    free(stack);
}

int main(){
	string str="A(B(D,E(H(J,K(L,M(N))))),C(F,G(I))";
	BiTree t=NULL;
	SqStack *s=NULL;
	InitStack(s);
    CreateBTree(t,str.c_str());
    cout<<"Using PreScan method to scan the tree:"<<endl;
	PreScan(t,s);
	cout<<endl;
	cout<<"Using PostScan method to scan the tree:"<<endl;
	PostScan(t,s);
	FreeTree(t);
    free(s);
	return 0;
}



