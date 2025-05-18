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
		if(s[index]=='+'||s[index]=='-'){  //遍历式子中的+和-做根节点
			sign=index;
			break;
		}
	}
	if(sign!=-1){  //式子有+或-
		root=(BTNode *)malloc(sizeof(BTNode));
		root->data=s[sign];
		root->lchild=CRTree(s,i,sign-1);  //左子树用s[i..sign-1]构造 
		root->rchild=CRTree(s,sign+1,j);  //右子树用s[sign+1..j]构造 
		return root;
	}
	else{  //式子没有+或- 
		for(int index=i;index<j;index++){
			if(s[index]=='*'||s[index]=='/'){  //遍历式子中的*和/做根节点
				root=(BTNode *)malloc(sizeof(BTNode));
				root->data=s[index];
				root->lchild=CRTree(s,i,index-1);  //左子树用s[i..index-1]构造 
				root->rchild=CRTree(s,index+1,j);  //右子树用s[index+1..j]构造 
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
	if(b->lchild==NULL&&b->rchild==NULL){  //叶子节点 
		return b->data-'0';  //递归出口 
	}
	else{  //求解计算 
		left=Comp(b->lchild);
		right=Comp(b->rchild);  //递归体 
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
