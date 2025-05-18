#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

//˳����о�ѭ��

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
	if((q->rear+1)%MaxSize>q->front){  //�����ж� 
		return false;
	}
	q->rear=(q->rear+1)%MaxSize;  //��ֹ����MaxSize-1��Χ 
	q->data[q->rear]=e;
	q->tag=1;  //tag���1����֤������tag��1 
	return true;
}

bool DeTagQueue(SqTagQueue *&q,int &e){
	if((q->rear)%MaxSize==q->front){  //�ӿ��ж� 
		return false;
	}
	q->front=(q->front+1)%MaxSize;  //��ֹ����MaxSize-1��Χ 
	e=q->data[q->front];
	q->tag=0;  //tag���0����֤������tag��0
	return true;
}

bool JudgeEmptyFull_01(SqTagQueue *&q){
	if((q->rear)%MaxSize==q->front){  //�ӿն����ж�tag 
		return q->tag;
	}
}

void ReverseElem_02(SqQueue *&q,SqStack *&s){
	int temp;
	while(!EmptyQueue(q)){  //�Ӳ���ʱ���γ��Ӳ���ջ 
		DeQueue(q,temp);
		Push(s,temp);
	}
	while(!EmptyStack(s)){  //ջ����ʱ���γ�ջ����� 
		Pop(s,temp);
		EnQueue(q,temp);
	}
}

bool EnQueueS_03(SqStack *&s1,SqStack *&s2,int x){
	if(EmptyStack(s1)&&EmptyStack(s2)){  //��ʼ����ջ��Ϊ�գ�ѹ��s2 
		Push(s2,x);
		return true;
	}
	else if(EmptyStack(s1)&&!EmptyStack(s2)){  //��Ӻ󶼽�Ԫ�ر�����s2��s1��ջ 
		while(!EmptyStack(s2)){  //��s2Ԫ��ȫ��ȡ����ѹ��s1 
			int e;
			Pop(s2,e);
			Push(s1,e);
		}
		Push(s1,x);  //��xѹ��s1 
		while(!EmptyStack(s1)){  //��s1Ԫ��ȫ��ȡ����ѹ��s2����֤s1�� 
		    int e;
			Pop(s1,e);
			Push(s2,e);
		}
		return true;
	}
	else if(StackOverflow(s2)){  //s2���ˣ��޷���� 
		return false;
	}
	else{  //����������� 
		return false; 
	} 
}

int DeQueueS_03(SqStack *&s1,SqStack *&s2){
	int x;
	if(!EmptyStack(s1)||EmptyStack(s2)){  //s1��Ԫ�ػ�s2��ջ���Ǵ���� 
		cout<<"����"<<endl;
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
//��ȻӦ������ʽ�洢�ṹ��˳��洢�ṹ�����ռ�����
//��ʼfront��rearָ���ָ��NULL���ӿռ���״̬��������������������ͻ������ռ��������Ҫ�󲻷� 
//front��rearָ���ָ��Ԫ�ؽ�㣬
//��sԪ�ؽ����ӣ�s�����ָ��frontָ��ָ��Ľ�㣬��frontָ��ָ��s��㣬rearָ��ָ��Ľ���next���next����NULL��
//��sԪ�ؽ����ӣ��ȱ�֤rearָ��ָ��Ľ���next���next����NULL��Ȼ����rearָ��ָ��Ľ���next����NULL����free(s)

int main(){
	return 0;
}
