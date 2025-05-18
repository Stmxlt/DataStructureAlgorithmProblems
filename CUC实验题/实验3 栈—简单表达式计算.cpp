#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct{
	char data[MaxSize];
	int top;
}SqStackchar;

typedef struct{
	double data[MaxSize];
	int top;
}SqStack;

void InitStackchar(SqStackchar *&s){
	s=(SqStackchar *)malloc(sizeof(SqStackchar));
	s->top=-1;
}

void DestroyStackchar(SqStackchar *&s){
	free (s);
}

bool StackEmptychar(SqStackchar *s){
	return (s->top==-1);
}

bool Pushchar(SqStackchar *&s,char e){
	if(s->top==MaxSize-1){
		return false;
	}
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool Popchar(SqStackchar *&s,char &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return true;
}

bool GetTopchar(SqStackchar *s,char &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	return true;
}

void InitStack(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}

void DestroyStack(SqStack *&s){
	free (s);
}

bool StackEmpty(SqStack *s){
	return (s->top==-1);
}

bool Push(SqStack *&s,double e){
	if(s->top==MaxSize-1){
		return false;
	}
	s->top++;
	s->data[s->top]=e;
	return true;
}

bool Pop(SqStack *&s,double &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *s,double &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	return true;
}

void trans(char *exp,char postexp[]){
	char e;
	SqStackchar *Optr;
	InitStackchar(Optr);
	int i=0;
	while(*exp!='\0'){
		switch(*exp){
			case '(':
				Pushchar(Optr,'(');
				exp++;
				break;
			case ')':
				Popchar(Optr,e);
				while(e!='('){
					postexp[i++]=e;
					Popchar(Optr,e);
				}
				exp++;
				break;
			case '+':
			case '-':
				while(!StackEmptychar(Optr)){
					GetTopchar(Optr,e);
					if(e!='('){
						postexp[i++]=e;
						Popchar(Optr,e);
					}
					else{
						break;
					}
				}
				Pushchar(Optr,*exp);
				exp++;
				break;
			case '*':
			case '/':
				while(!StackEmptychar(Optr)){
					GetTopchar(Optr,e);
					if(e=='*'||e=='/'){
						postexp[i++]=e;
						Popchar(Optr,e);
					}
					else{
						break;
					}
				}
				Pushchar(Optr,*exp);
				exp++;
				break;
			default:
				while(*exp>='0'&&*exp<='9'){
					postexp[i++]=*exp;
					exp++;
				}
				postexp[i++]='#';
		}
	}
	while (!StackEmptychar(Optr)){
		Popchar(Optr,e);
		postexp[i++]=e;
	}
	postexp[i]='\0';
	DestroyStackchar(Optr);
}

double compvalue(char *postexp){
	double d,a,b,c,e;
	SqStack *Opnd;
	InitStack(Opnd);
	while(*postexp!='\0'){
		switch(*postexp){
			case '+':
				Pop(Opnd,a);
				Pop(Opnd,b);
				c=b+a;
				Push(Opnd,c);
				break;
			case '-':
				Pop(Opnd,a);
				Pop(Opnd,b);
				c=b-a;
				Push(Opnd,c);
				break;
			case '*':
				Pop(Opnd,a);
				Pop(Opnd,b);
				c=b*a;
				Push(Opnd,c);
				break;
			case '/':
				Pop(Opnd,a);
				Pop(Opnd,b);
				if(a!=0){
					c=b/a;
					Push(Opnd,c);
					break;
				}
				else{
					cout<<endl<<"除零错误！"<<endl;
					exit(0);
				}
				break;
			default:
				d=0;
				while(*postexp>='0'&&*postexp<='9'){
					d=10*d+(*postexp-'0');
					postexp++;
				}
				Push(Opnd,d);
				break;
				
		}
		postexp++;
	}
	GetTop(Opnd,e);
	DestroyStack(Opnd);
	return e;
}

int main(){
	char exp[]="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	cout<<"中缀表达式："<<exp<<endl;
	cout<<"后缀表达式："<<postexp<<endl;
	cout<<"表达式的值："<<compvalue(postexp)<<endl;
	return 0;
}
