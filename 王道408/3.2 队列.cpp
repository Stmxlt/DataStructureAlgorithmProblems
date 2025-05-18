#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

//顺序队列均循环

typedef struct{
	int data[MaxSize];
	int top;
} SqStack;

typedef struct{
	int data[MaxSize];
	int front,rear;
} SqQueue;

typedef struct{
	int data[MaxSize];
	int front,rear;
	int tag;
} SqTagQueue;

void InitStack(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

bool EmptyStack(SqStack *&s){
	return(s->top==-1);
}

bool StackOverflow(SqStack *&s){
	return(s->top==MaxSize-1);
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

void InitQueue(SqQueue *&q){
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

bool EnQueue(SqQueue *&q,int e){
	if((q->rear+1)%MaxSize==q->front){
		return false;
	}
	q->rear=(q->rear+1)%MaxSize; 
	q->data[q->rear]=e;
	return true;
}

bool DeQueue(SqQueue *&q,int &e){
	if(q->rear==q->front){
		return false;
	}
	e=q->data[q->front];
	q->front=(q->front+1)%MaxSize;
	return true;
}

bool EnTagQueue(SqTagQueue *&q,int e){
	if((q->rear+1)%MaxSize>q->front){  //队满判断 
		return false;
	}
	q->rear=(q->rear+1)%MaxSize;  //防止超出MaxSize-1范围 
	q->data[q->rear]=e;
	q->tag=1;  //tag设成1，保证加满了tag是1 
	return true;
}

bool DeTagQueue(SqTagQueue *&q,int &e){
	if((q->rear)%MaxSize==q->front){  //队空判断 
		return false;
	}
	q->front=(q->front+1)%MaxSize;  //防止超出MaxSize-1范围 
	e=q->data[q->front];
	q->tag=0;  //tag设成0，保证减空了tag是0
	return true;
}

bool JudgeEmptyFull_01(SqTagQueue *&q){
	if((q->rear)%MaxSize==q->front){  //队空队满判断tag 
		return q->tag;
	}
}

void ReverseElem_02(SqQueue *&q,SqStack *&s){
	int temp;
	while(!EmptyQueue(q)){  //队不空时依次出队并入栈 
		DeQueue(q,temp);
		Push(s,temp);
	}
	while(!EmptyStack(s)){  //栈不空时依次出栈并入队 
		Pop(s,temp);
		EnQueue(q,temp);
	}
}

bool EnQueueS_03(SqStack *&s1,SqStack *&s2,int x){
	if(EmptyStack(s1)&&EmptyStack(s2)){  //初始两个栈都为空，压入s2 
		Push(s2,x);
		return true;
	}
	else if(EmptyStack(s1)&&!EmptyStack(s2)){  //入队后都将元素保存在s2，s1空栈 
		while(!EmptyStack(s2)){  //将s2元素全部取出并压入s1 
			int e;
			Pop(s2,e);
			Push(s1,e);
		}
		Push(s1,x);  //将x压入s1 
		while(!EmptyStack(s1)){  //将s1元素全部取出并压入s2，保证s1空 
		    int e;
			Pop(s1,e);
			Push(s2,e);
		}
		return true;
	}
	else if(StackOverflow(s2)){  //s2满了，无法入队 
		return false;
	}
	else{  //其他情况错误 
		return false; 
	} 
}

int DeQueueS_03(SqStack *&s1,SqStack *&s2){
	int x;
	if(!EmptyStack(s1)||EmptyStack(s2)){  //s1有元素或s2空栈都是错误的 
		cout<<"错误！"<<endl;
	}
	else{
		Pop(s2,x);
	}
	return x;
}
	
bool QueueEmptyS_03(SqStack *&s1,SqStack *&s2){
	return (EmptyStack(s1)&&EmptyStack(s2));
}

//04.
//显然应该用链式存储结构，顺序存储结构有最大空间限制
//初始front和rear指针均指向NULL，队空即此状态，不会队满，如果会队满就会有最大空间限制与②要求不符 
//front和rear指针均指向元素结点，
//设s元素结点入队，s结点先指向front指针指向的结点，将front指针指向s结点，rear指针指向的结点的next域的next域是NULL；
//设s元素结点出队，先保证rear指针指向的结点的next域的next域是NULL，然后让rear指针指向的结点的next域是NULL，再free(s)

int main(){
	return 0;
}
