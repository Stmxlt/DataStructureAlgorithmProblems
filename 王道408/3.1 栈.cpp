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
	while(a[i]!='\0'){  //遍历整个字符数组，如果是I就进栈，如果是O就出栈
		if(a[i]='I'){
			in++;
		}
		else{
			out++;
		}
		if(in<out){  //进栈次数不会少于出栈次数，少于则非法  
			return false;
		}
		i++;
	}
	if(in!=out){  //终态栈为空，进栈次数等于出栈次数，不等则非法 
		return false;
	}
	return true;
}

bool JudgeSymmetry_04(LinkNode *L){
	SqStack *s1,*s2;  //正向和反向栈 
	int len=0;  //记录长度 
	InitStack(s1);
	InitStack(s2);
	L=L->next;  //初始指向首结点 
	while(L!=NULL){  //将L内容入栈s1
		Push(s1,L->data);
		L=L->next;
		len++; 
	}
	while(s1->top>=0){  //反向入栈s2 
		Push(s2,s1->data[s1->top]);
		s1->top--;
	}
	s1->top==-1;  //设为栈底判断 
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
	if(s->top1+1==s->top2){  //共享栈满无法入栈 
		return false;
	}
	s->top1++;
	s->data[s->top1]=e;
	return true;
}

bool PushS2(SqDoubleStack *&s,int e){
	if(s->top1+1==s->top2){  //共享栈满无法入栈 
		return false;
	}
	s->top2--;
	s->data[s->top1]=e;
	return true;
}

bool PopS1(SqDoubleStack *&s,int &e){
	if(s->top1==-1){  //共享栈S1空无法出栈 
		return false;
	}
	s->top1--;
	e=s->data[s->top1];
	return true;
}

bool PopS2(SqDoubleStack *&s,int &e){
	if(s->top2==MaxSize){  //共享栈S2空无法出栈
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
