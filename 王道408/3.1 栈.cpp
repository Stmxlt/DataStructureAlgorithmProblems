#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct LNode{
	int data;
	struct LNode * next;	
} LinkNode;

typedef struct{
	int data[MaxSize];
	int top;
} SqStack;

typedef struct{
	int data[MaxSize];
	int top1;
	int top2;
} SqDoubleStack;

void InitStack(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

void InitDoubleStack(SqDoubleStack *&s){
	s=(SqDoubleStack *)malloc(sizeof(SqDoubleStack));
	s->top1=-1;
	s->top2=MaxSize;
}

bool Push(SqStack *&s,int e){
	if(s->top==MaxSize-1){
		return false;
	}
	s->top++;
	s->data[s->top]=e;
}

bool Pop(SqStack *&s,char &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
}

bool JudgeLegalStack_03(char a[]){
	int in=0,out=0,i=0;
	while(a[i]!='\0'){  //���������ַ����飬�����I�ͽ�ջ�������O�ͳ�ջ
		if(a[i]='I'){
			in++;
		}
		else{
			out++;
		}
		if(in<out){  //��ջ�����������ڳ�ջ������������Ƿ�  
			return false;
		}
		i++;
	}
	if(in!=out){  //��̬ջΪ�գ���ջ�������ڳ�ջ������������Ƿ� 
		return false;
	}
	return true;
}

bool JudgeSymmetry_04(LinkNode *L){
	SqStack *s1,*s2;  //����ͷ���ջ 
	int len=0;  //��¼���� 
	InitStack(s1);
	InitStack(s2);
	L=L->next;  //��ʼָ���׽�� 
	while(L!=NULL){  //��L������ջs1
		Push(s1,L->data);
		L=L->next;
		len++; 
	}
	while(s1->top>=0){  //������ջs2 
		Push(s2,s1->data[s1->top]);
		s1->top--;
	}
	s1->top==-1;  //��Ϊջ���ж� 
	s2->top==-1;
	for(int i=0;i<len;i++){
		s1->top++;
		s2->top++;
		if(s1->data==s2->data){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}

bool PushS1(SqDoubleStack *&s,int e){
	if(s->top1+1==s->top2){  //����ջ���޷���ջ 
		return false;
	}
	s->top1++;
	s->data[s->top1]=e;
	return true;
}

bool PushS2(SqDoubleStack *&s,int e){
	if(s->top1+1==s->top2){  //����ջ���޷���ջ 
		return false;
	}
	s->top2--;
	s->data[s->top1]=e;
	return true;
}

bool PopS1(SqDoubleStack *&s,int &e){
	if(s->top1==-1){  //����ջS1���޷���ջ 
		return false;
	}
	s->top1--;
	e=s->data[s->top1];
	return true;
}

bool PopS2(SqDoubleStack *&s,int &e){
	if(s->top2==MaxSize){  //����ջS2���޷���ջ
		return false;
	}
	s->top2++;
	e=s->data[s->top1];
	return true;
}

bool ShareStack_05(SqDoubleStack *&s,int &e){
	PushS1(s,e);
	PushS2(s,e);
	PopS1(s,e);
	PopS2(s,e);
}

int main(){
	return 0;
}
