#include<iostream>
#include<cstdlib>
#include<cstring>
#define MaxSize 50
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LNode{
	BiTree data;
	struct LNode *next;	
} LinkNode,*LinkList;

typedef struct{
	BiTree data[MaxSize];
	int top;
}SqStack;

typedef struct{
	BiTree data[MaxSize];
	int front,rear;
}SqQueue;

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
}

bool Pop(SqStack *&s,BiTree &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
}

void InitQueue(SqQueue *&q){
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=-1;
}

bool EmptyQueue(SqQueue *&q){
	if(q->front==q->rear){
		return true;
	}
	else{
		return false;
	}
}

bool EnQueue(SqQueue *&q,BiTree e){
	if((q->rear+1)%MaxSize==q->front){
		return false;
	}
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}

bool DeQueue(SqQueue *&q,BiTree &e){
	if(q->rear==q->front){
		return false;
	}
	e=q->data[q->front];
	q->front=(q->front+1)%MaxSize;
	return true;
}

void visit(BiTNode *t){
	cout<<t->data;
}

void LevelOrder(BiTNode *t){
	SqQueue *q;
	if(t!=NULL){
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			if(t->lchild!=NULL){
				EnQueue(q,t->lchild);
			}
			if(t->rchild!=NULL){
				EnQueue(q,t->rchild);
			}
		}
	}
}

void LevelOrderRev_04(BiTNode *t){
	SqStack *s;
	SqQueue *q;
	if(t!=NULL){
		InitStack(s);
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			Push(s,t);
			if(t->lchild!=NULL){
				EnQueue(q,t->lchild);
			}
			if(t->rchild!=NULL){
				EnQueue(q,t->rchild);
			}
		}
		while(!EmptyStack(s)){
			Pop(s,t);
			visit(t);
		}
	}
	else{
		cout<<"Invaild input!"<<endl;
	}
}

int FindHeight_05(BiTNode *t){
	int height=0,counter=0;  //计数器记录一层最后一个结点在队列中的位置 
	SqQueue *q;
	if(t!=NULL){
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			if(t->lchild!=NULL){
				EnQueue(q,t->lchild);
			}
			if(t->rchild!=NULL){
				EnQueue(q,t->rchild);
			}
			if(q->front==counter){  //当遍历完一整层时，增加一层，并将计数器设为最后一个结点的位置 
				height++;
				counter=q->rear;
			}
		}
		return height;
	}
	else{
		return 0;
	}
}

bool IsFullTree_06(BiTNode *t){
	int flag=0;  //用于记录叶子结点或只有左子树结点开始 
	SqQueue *q;
	if(t!=NULL){
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			if(t->lchild==NULL&&t->rchild!=NULL){
				cout<<"The tree is not a full tree."<<endl;
				return false;
			}
			else if(((t->lchild==NULL&&t->rchild==NULL)||(t->lchild!=NULL&&t->rchild==NULL))&&flag==0){
				flag=1;  //首个叶子结点或只有左子树结点标志 
			}
			else if(t->lchild!=NULL&&flag==1){
				cout<<"The tree is not a full tree."<<endl;
				return false;
			}
			if(t->lchild!=NULL){
				EnQueue(q,t->lchild);
			}
			if(t->rchild!=NULL){
				EnQueue(q,t->rchild);
			}
		}
		cout<<"The tree is a full tree."<<endl;
		return true;
	}
	else{
		cout<<"Invaild input!"<<endl;
		return false;
	}
}

int CountDoubleNode_07(BiTNode *t){
	int counter=0; 
	SqQueue *q;
	if(t!=NULL){
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			if(t->lchild!=NULL&&t->rchild!=NULL){
				counter++;
			}
			if(t->lchild!=NULL){
				EnQueue(q,t->lchild);
			}
			if(t->rchild!=NULL){
				EnQueue(q,t->rchild);
			}
		}
		return counter;
	}
	else{
		return counter;
	}
}

void SwapLR_08(BiTNode *t){ 
	if(t!=NULL){
		BiTree temp;  //用于转换左右子树 
		temp->lchild=t->rchild;
		temp->rchild=t->lchild;
		t->lchild=temp->lchild;
		t->rchild=temp->rchild;
		SwapLR_08(t->lchild);  //左右子树的子树转换 
		SwapLR_08(t->rchild);
	}
}

int counter=0;  //这个counter是用于第9题的全局变量 

int CountNode_09(BiTNode *t,int k){
	if(t!=NULL){
		visit(t);
		counter++;
		if(counter==k){
			return t->data;
		}
		CountNode_09(t->lchild,k);
		CountNode_09(t->rchild,k);
	}
}

void DelSpecNum_10(BiTNode *t,int x){
	if(t!=NULL){
		DelSpecNum_10(t->lchild,x);
		DelSpecNum_10(t->rchild,x);
		if(t->data=x){
			BiTree temp=t;
        	t=NULL;
        	delete temp;  //删除的是整棵树而不是仅有当前结点 
		}
	}
}

void PrintAllParents_11(BiTNode *t,SqStack *s,int x){
	if(t!=NULL&&t->data!=x){  //在这里默认已经初始化暂存栈s 
		Push(s,t);
		PrintAllParents_11(t->lchild,s,x);
		PrintAllParents_11(t->rchild,s,x);
	}
	else if(t!=NULL&&t->data==x){
		cout<<"树"<<t<<"的祖先是："<<endl;
		while(!EmptyStack(s)){
			BiTNode *e; 
			Pop(s,e);
			cout<<" "<<e->data;
			free(e);
		}
	}
	else{
		while(!EmptyStack(s)){
			BiTNode *e;
			Pop(s,e);
			free(e);
		}
	}
}

SqStack *AllParents(BiTNode *t,SqStack *s,int x){
	if(t!=NULL&&t->data!=x){  //在这里默认已经初始化暂存栈s 
		Push(s,t);
		AllParents(t->lchild,s,x);
		AllParents(t->rchild,s,x);
	}
	else if(t!=NULL&&t->data==x){
		SqStack *sr=s;  //根节点祖先在s栈底
		while(!EmptyStack(s)){
			BiTNode *e; 
			Pop(s,e);
			Push(sr,e);
			free(e);
		}
		return sr;  //根节点祖先在sr栈顶 
	}
	else{
		while(!EmptyStack(s)){
			BiTNode *e;
			Pop(s,e);
			free(e);
		}
	}
}

BiTNode *Ancestor_12(BiTNode *Root,BiTNode *p,BiTNode *q,SqStack *s){
	SqStack *sp,*sq;
	InitStack(sp);
	InitStack(sq);
	sp=AllParents(Root,s,p->data);  //取出二者祖先栈 
	sq=AllParents(Root,s,q->data);
	BiTNode *elem1,*elem2,*r;
	while(sp->data[sp->top]==sq->data[sp->top]){  //取对比栈顶元素的到最近的公共祖先 
		Pop(sp,elem1);
		Pop(sp,elem2);
	}
	r=elem1;
	return r;
}

int FindBreadth_13(BiTNode *b){
	int breadth=0,counter=0;
	SqQueue *q;
	if(b!=NULL){
		InitQueue(q);
		EnQueue(q,b);
		while(!EmptyQueue(q)){
			DeQueue(q,b);
			if(b->lchild!=NULL){
				EnQueue(q,b->lchild);
			}
			if(b->rchild!=NULL){
				EnQueue(q,b->rchild);
			}
			if(q->front==counter){
				counter=q->rear;
				int temp=q->rear-q->front;
				breadth=breadth>=temp?breadth:temp;  //更新宽度 
			}
		}
		return breadth;
	}
	else{
		return 0;
	}
}

//14.void PreToPost()太恶心不做 

void FindLeaves_15(BiTNode *t,LinkNode *&head){
	LinkNode *p=head;
	SqQueue *q;
	if(t!=NULL){
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			if(t->lchild==NULL&&t->rchild==NULL){
				LinkNode *newnode=(LinkNode *)malloc(sizeof(LinkNode));  //新建结点并将data域设为t 
				newnode->data=t;
				newnode->next=NULL;
				p->next=newnode;
				p=newnode;
				t->rchild=p->data;  //右孩子指针域指向链表的最后一个结点data域 
			}
			if(t->lchild!=NULL){
				EnQueue(q,t->lchild);
			}
			if(t->rchild!=NULL){
				EnQueue(q,t->rchild);
			}
		}
	}
}

bool IsSimilar_16(BiTNode *t1,BiTNode *t2){
	if((t1==NULL&&t2==NULL)||(t1!=NULL&&t2!=NULL)){
		return true;
	}
	else{
		return false;
	}
	bool leftsimilar,rightsimilar;
	if(t1->lchild!=NULL&&t2->lchild!=NULL){
		leftsimilar=IsSimilar_16(t1->lchild,t2->lchild);
	}
	if(t1->rchild!=NULL&&t2->rchild!=NULL){
		rightsimilar=IsSimilar_16(t1->rchild,t2->rchild);
	}
	return leftsimilar&&rightsimilar;
}

//17.
//利用深度优先算法（先根/先序）递归求得每个叶子结点的深度，利用公式算出wpl，结点定义见上 
int ComputeWPL_17(BiTNode *t,int &depth){
	int WPL=0;
	if(t!=NULL){  //结点非空返回值计算wpl 
		if(t->lchild==NULL&&t->rchild==NULL){  //叶子结点，求wpl 
			WPL+=t->data*depth;
		}
		else{  //分支结点，增加深度并求左右子树根节点wpl 
			depth++;
			WPL=ComputeWPL_17(t->lchild,depth)+ComputeWPL_17(t->rchild,depth);
		}
	}
	else{  //结点空返回0计算wpl 
		return 0;
	}
	return WPL;
}

typedef struct node{
	char data[10];
	struct node *left, *right;
}BTree;

//18.
//利用中序遍历，遍历完一棵子树得到一部分字符串，并加括号，最后输出全部字符串 
string TreeToFormula_18(BTree *t){
	const char left='(',right=')';
	string str;
	if(t==NULL){  //空树 
		return "";
	}
	if(t->left!=NULL&&t->right!=NULL){  //左右子树结点，( 左子树 结点data 右子树 ) 
		str+=left+TreeToFormula_18(t->left)+t->data+TreeToFormula_18(t->right)+right;
	}
	else if(t->left!=NULL&&t->right==NULL){  //仅有左子树结点，( 左子树 结点data ) 
		str+=left+TreeToFormula_18(t->left)+t->data+right;
	}
	else if(t->left==NULL&&t->right!=NULL){  //仅有右子树结点，( 结点data 右子树 ) 
		str+=left+t->data+TreeToFormula_18(t->right)+right;
	}
	else{  //叶子节点，结点data 
		str+=t->data;
	}
	return str;
}

typedef struct{
	int SqBiTNode[MaxSize];
	int ElemNum;
}SqBiTree;

//19.
//二叉搜索树/二叉排序树：左子树根data小于根data小于右子树根data，或者为空树，且子树也满足性质，在data>0情况下做这题 
//利用公式直接得到左子树根和右子树根的位置和data，按定义比较(跳过-1)

bool IsBinarySearchTree_19(SqBiTree *t){
	int loc=1;
	for(loc;loc<=t->ElemNum;loc++){  //循环判断 
		if(t->SqBiTNode[loc-1]==-1){  //是否为空 
			continue;
		}
		else{
			if(2*(loc-1)<t->ElemNum&&t->SqBiTNode[2*(loc-1)]!=-1&&t->SqBiTNode[2*(loc-1)]<t->SqBiTNode[loc-1]){  //比较左子树
				continue;
			}
			else{
				return false;
			}
			if(2*(loc-1)+1<t->ElemNum&&t->SqBiTNode[2*(loc-1)+1]!=-1&&t->SqBiTNode[loc-1]<t->SqBiTNode[2*(loc-1)+1]){  //比较右子树 
				continue;
			}
			else{
				return false;
			}
		}
	}
}

int main(){
	
	return 0;
}
