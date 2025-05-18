#include<iostream>
#include<cstdlib>
#include<cstring>
#define MaxSize 50
using namespace std;

typedef struct node{
	char data;
	struct node *lchild, *rchild;
} BTNode, *BTree;

void DestroyBTree(BTNode *b){
	if(b!=NULL){
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTNode* CRTree(char s[],int i,int j){
	BTNode *root=NULL;
	if(i==j){
		root=(BTNode *)malloc(sizeof(BTNode));
		root->data=s[i];
		root->lchild=NULL;
		root->rchild=NULL;
		return root;
	}
	int sign=-1;
	for(int index=i;index<j;index++){
		if(s[index]=='+'||s[index]=='-'){  //����ʽ���е�+��-�����ڵ�
			sign=index;
			break;
		}
	}
	if(sign!=-1){  //ʽ����+��-
		root=(BTNode *)malloc(sizeof(BTNode));
		root->data=s[sign];
		root->lchild=CRTree(s,i,sign-1);  //��������s[i..sign-1]���� 
		root->rchild=CRTree(s,sign+1,j);  //��������s[sign+1..j]���� 
		return root;
	}
	else{  //ʽ��û��+��- 
		for(int index=i;index<j;index++){
			if(s[index]=='*'||s[index]=='/'){  //����ʽ���е�*��/�����ڵ�
				root=(BTNode *)malloc(sizeof(BTNode));
				root->data=s[index];
				root->lchild=CRTree(s,i,index-1);  //��������s[i..index-1]���� 
				root->rchild=CRTree(s,index+1,j);  //��������s[index+1..j]���� 
				break;
			}
		}
		return root;
	}
}

double Comp(BTNode *b){
	if(b==NULL){
		cout<<"Empty tree!"<<endl;
		return 0.0;
	}
	double left, right;
	if(b->lchild==NULL&&b->rchild==NULL){  //Ҷ�ӽڵ� 
		return b->data-'0';  //�ݹ���� 
	}
	else{  //������ 
		left=Comp(b->lchild);
		right=Comp(b->rchild);  //�ݹ��� 
		switch(b->data){
			case '+': return left+right;
			case '-': return left-right;
			case '*': return left*right;
			case '/': if(right==0){
				cout<<"The formula is false because a dividing number is 0!"<<endl;
				return -9999999.0;
				}
				else {
					return left/right;
				}
		}
	}
}

void Infix(BTNode *root) {
    if(root!=NULL){
        Infix(root->lchild);
        cout<<root->data;
        Infix(root->rchild);
    }
}

int main(){
	char s[MaxSize];
	cout<<"Type the formula you want to compute:"<<endl;
	cin>>s;
	int i=0,j;
	j=strlen(s)-1;
	double result;
	BTNode *Tree;
	Tree=CRTree(s,i,j);
	cout<<"Output the formula based on the tree:"<<endl;
	Infix(Tree);
	cout<<endl;
	result=Comp(Tree);
	cout<<"The result of the formula is:"<<result<<endl;
	DestroyBTree(Tree);
	return 0;
}
