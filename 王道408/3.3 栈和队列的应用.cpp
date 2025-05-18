#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct{
	char data[MaxSize];
	int top;
} SqStack;

bool EmptyStack(SqStack *s){
	return (s->top==-1);
}

bool Push(SqStack *&s,char e){
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

bool MatchBrackets_01(SqStack *&s,char a[]){
	char x1,x2,x3;
	for(int i=0;a[i]!='\0';i++){  //±éÀúÊı×é 
		switch(a[i]){  //×óÀ¨ºÅÈëÕ»£¬ÓÒÀ¨ºÅÆ¥Åä 
			case ('('||'['||'{'):Push(s,a[i]);
			case ')':Pop(s,x1);  //³öÕ»×öÅĞ¶Ï£¬Èç¹ûÕ»¿ÕÎŞ·¨Æ¥Åä´íÎó 
			case ']':Pop(s,x2);
			case '}':Pop(s,x3);
			default :continue;
		}
		if(x1!='('||x2!='['||x3!='{'){  //Æ¥Åä´íÎó 
			return false;
		}
	}
	if(!EmptyStack(s)){  //ÓĞ×óÀ¨ºÅÊ£Óà´íÎó 
		return false;
	}
	return true;
}

int main(){
	return 0;
}
