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
	int height=0,counter=0;  //��������¼һ�����һ������ڶ����е�λ�� 
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
			if(q->front==counter){  //��������һ����ʱ������һ�㣬������������Ϊ���һ������λ�� 
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
	int flag=0;  //���ڼ�¼Ҷ�ӽ���ֻ����������㿪ʼ 
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
				flag=1;  //�׸�Ҷ�ӽ���ֻ������������־ 
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
		BiTree temp;  //����ת���������� 
		temp->lchild=t->rchild;
		temp->rchild=t->lchild;
		t->lchild=temp->lchild;
		t->rchild=temp->rchild;
		SwapLR_08(t->lchild);  //��������������ת�� 
		SwapLR_08(t->rchild);
	}
}

int counter=0;  //���counter�����ڵ�9���ȫ�ֱ��� 

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
        	delete temp;  //ɾ�����������������ǽ��е�ǰ��� 
		}
	}
}

void PrintAllParents_11(BiTNode *t,SqStack *s,int x){
	if(t!=NULL&&t->data!=x){  //������Ĭ���Ѿ���ʼ���ݴ�ջs 
		Push(s,t);
		PrintAllParents_11(t->lchild,s,x);
		PrintAllParents_11(t->rchild,s,x);
	}
	else if(t!=NULL&&t->data==x){
		cout<<"��"<<t<<"�������ǣ�"<<endl;
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
	if(t!=NULL&&t->data!=x){  //������Ĭ���Ѿ���ʼ���ݴ�ջs 
		Push(s,t);
		AllParents(t->lchild,s,x);
		AllParents(t->rchild,s,x);
	}
	else if(t!=NULL&&t->data==x){
		SqStack *sr=s;  //���ڵ�������sջ��
		while(!EmptyStack(s)){
			BiTNode *e; 
			Pop(s,e);
			Push(sr,e);
			free(e);
		}
		return sr;  //���ڵ�������srջ�� 
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
	sp=AllParents(Root,s,p->data);  //ȡ����������ջ 
	sq=AllParents(Root,s,q->data);
	BiTNode *elem1,*elem2,*r;
	while(sp->data[sp->top]==sq->data[sp->top]){  //ȡ�Ա�ջ��Ԫ�صĵ�����Ĺ������� 
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
				breadth=breadth>=temp?breadth:temp;  //���¿�� 
			}
		}
		return breadth;
	}
	else{
		return 0;
	}
}

//14.void PreToPost()̫���Ĳ��� 

void FindLeaves_15(BiTNode *t,LinkNode *&head){
	LinkNode *p=head;
	SqQueue *q;
	if(t!=NULL){
		InitQueue(q);
		EnQueue(q,t);
		while(!EmptyQueue(q)){
			DeQueue(q,t);
			if(t->lchild==NULL&&t->rchild==NULL){
				LinkNode *newnode=(LinkNode *)malloc(sizeof(LinkNode));  //�½���㲢��data����Ϊt 
				newnode->data=t;
				newnode->next=NULL;
				p->next=newnode;
				p=newnode;
				t->rchild=p->data;  //�Һ���ָ����ָ����������һ�����data�� 
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
//������������㷨���ȸ�/���򣩵ݹ����ÿ��Ҷ�ӽ�����ȣ����ù�ʽ���wpl����㶨����� 
int ComputeWPL_17(BiTNode *t,int &depth){
	int WPL=0;
	if(t!=NULL){  //���ǿշ���ֵ����wpl 
		if(t->lchild==NULL&&t->rchild==NULL){  //Ҷ�ӽ�㣬��wpl 
			WPL+=t->data*depth;
		}
		else{  //��֧��㣬������Ȳ��������������ڵ�wpl 
			depth++;
			WPL=ComputeWPL_17(t->lchild,depth)+ComputeWPL_17(t->rchild,depth);
		}
	}
	else{  //���շ���0����wpl 
		return 0;
	}
	return WPL;
}

typedef struct node{
	char data[10];
	struct node *left, *right;
}BTree;

//18.
//�������������������һ�������õ�һ�����ַ������������ţ�������ȫ���ַ��� 
string TreeToFormula_18(BTree *t){
	const char left='(',right=')';
	string str;
	if(t==NULL){  //���� 
		return "";
	}
	if(t->left!=NULL&&t->right!=NULL){  //����������㣬( ������ ���data ������ ) 
		str+=left+TreeToFormula_18(t->left)+t->data+TreeToFormula_18(t->right)+right;
	}
	else if(t->left!=NULL&&t->right==NULL){  //������������㣬( ������ ���data ) 
		str+=left+TreeToFormula_18(t->left)+t->data+right;
	}
	else if(t->left==NULL&&t->right!=NULL){  //������������㣬( ���data ������ ) 
		str+=left+t->data+TreeToFormula_18(t->right)+right;
	}
	else{  //Ҷ�ӽڵ㣬���data 
		str+=t->data;
	}
	return str;
}

typedef struct{
	int SqBiTNode[MaxSize];
	int ElemNum;
}SqBiTree;

//19.
//����������/��������������������dataС�ڸ�dataС����������data������Ϊ������������Ҳ�������ʣ���data>0����������� 
//���ù�ʽֱ�ӵõ���������������������λ�ú�data��������Ƚ�(����-1)

bool IsBinarySearchTree_19(SqBiTree *t){
	int loc=1;
	for(loc;loc<=t->ElemNum;loc++){  //ѭ���ж� 
		if(t->SqBiTNode[loc-1]==-1){  //�Ƿ�Ϊ�� 
			continue;
		}
		else{
			if(2*(loc-1)<t->ElemNum&&t->SqBiTNode[2*(loc-1)]!=-1&&t->SqBiTNode[2*(loc-1)]<t->SqBiTNode[loc-1]){  //�Ƚ�������
				continue;
			}
			else{
				return false;
			}
			if(2*(loc-1)+1<t->ElemNum&&t->SqBiTNode[2*(loc-1)+1]!=-1&&t->SqBiTNode[loc-1]<t->SqBiTNode[2*(loc-1)+1]){  //�Ƚ������� 
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
