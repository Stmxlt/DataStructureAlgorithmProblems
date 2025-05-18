#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

int mg[10][10]=
{	{1,1,1,1,1,1,1,1,1,1}, {1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1}, {1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1}, {1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1}, {1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1}, {1,1,1,1,1,1,1,1,1,1} };

//typedef struct{
//	int i;
//	int j;
//	int di;
//} Box;
//
//typedef struct{
//	Box data[MaxSize];
//	int top;
//} StType;
//
//void InitStack(StType *&s){
//	s=(StType *)malloc(sizeof(StType));
//	s->top=-1;
//}
//
//void DestroyStack(StType *&s){
//	free (s);
//}
//
//bool StackEmpty(StType *s){
//	return (s->top==-1);
//}
//
//bool Push(StType *&s,Box e){
//	if(s->top==MaxSize-1){
//		return false;
//	}
//	s->top++;
//	s->data[s->top]=e;
//	return true;
//}
//
//bool Pop(StType *&s,Box &e){
//	if(s->top==-1){
//		return false;
//	}
//	e=s->data[s->top--];
//	return true;
//}
//
//bool GetTop(StType *s,Box &e){
//	if(s->top==-1){
//		return false;
//	}
//	e=s->data[s->top];
//	return true;
//}
//
//bool mgpath(int xi,int yi,int xe,int ye){
//	Box path[MaxSize],e;
//	int i,j,di,i1,j1,k;
//	bool find;
//	StType *st;
//	InitStack(st);
//	e.i=xi; e.j=yi; e.di=-1;
//	Push(st,e);
//	mg[xi][yi]=-1;
//	while(!StackEmpty(st)){
//		GetTop(st,e);
//		i=e.i; j=e.j; di=e.di;
//		if(i==xe&&j==ye){
//			cout<<"一条迷宫路径如下："<<endl;
//			k=0;
//			while(!StackEmpty(st)){
//				Pop(st,e);
//				path[k++]=e;
//			}
//			while(k>0){
//				cout<<"("<<path[k-1].i<<","<<path[k-1].j<<")";
//				if((k+1)%5==0){
//					cout<<endl;
//				}
//				k--;
//			}
//			cout<<endl;
//			DestroyStack(st);
//			return true;
//		}
//		find=false;
//		while(di<4&&!find){
//			di++;
//			switch(di){
//				case 0:i1=i-1;j1=j;break;
//				case 1:i1=i;j1=j+1;break;
//				case 2:i1=i+1;j1=j;break;
//				case 3:i1=i;j1=j-1;break;
//			}
//			if(mg[i1][j1]==0){
//				find=true;
//			}
//		}
//		if(find){
//			st->data[st->top].di=di;
//			e.i=i1; e.j=j1; e.di=-1;
//			Push(st,e);
//			mg[i1][j1]=-1;
//		}
//		else{
//			Pop(st,e);
//			mg[e.i][e.j]=0;
//		} 
//	}
//	DestroyStack(st);
//	return false;
//}

typedef struct{
	int i,j;
	int pre;
} Box;

typedef struct{
	Box data[MaxSize];
	int front,rear;
} QuType;

void InitQueue(QuType *&q){
    q=(QuType *)malloc(sizeof(QuType));
    q->front=q->rear=-1;
}

void DestroyQueue(QuType *&q){
    free(q);
}

bool QueueEmpty(QuType *q){
    return (q->front==q->rear);
}

bool enQueue(QuType *&q,Box e){
    if(q->rear==MaxSize-1){
        return false;
    }
    q->data[++q->rear]=e;
    return true;
}

bool deQueue(QuType *&q,Box &e){
    if(q->front==q->rear){
        return false;
    }
    e=q->data[++q->front];
    return true;
}

void dispapath(QuType *qu,int front){
	Box path[MaxSize];
	int p=front,k=0,i;
	while(p!=-1){
		path[k++]=qu->data[p];
		p=qu->data[p].pre;
	}
	cout<<"一条迷宫路径如下："<<endl;
	for(i=k-1;i>=0;i--){
		cout<<"("<<path[i].i<<","<<path[i].j<<")";
		if((i)%5==0){
		cout<<endl;
		}
	}
	cout<<endl;
}

bool mgpath(int xi,int yi,int xe,int ye){
	Box e;
	int i,j,di,i1,j1;
	QuType *qu;
	InitQueue(qu);
	e.i=xi; e.j=yi; e.pre=-1;
	enQueue(qu,e);
	mg[xi][yi]=-1;
	while(!QueueEmpty(qu)){
		deQueue(qu,e);
		i=e.i; j=e.j;
		if(i==xe&&j==ye){
			dispapath(qu,qu->front);
			DestroyQueue(qu);
			return true;
		}
		for(di=0;di<4;di++){
			switch(di){
				case 0:i1=i-1; j1=j; break;
				case 1:i1=i; j1=j+1; break;
				case 2:i1=i+1; j1=j; break;
				case 3:i1=i; j1=j-1; break;
			}
			if(mg[i1][j1]==0){
				e.i=i1; e.j=j1;
				e.pre=qu->front;
				enQueue(qu,e);
				mg[i1][j1]=-1;
			}
		}
	}
	DestroyQueue(qu);
	return false;
}

int main(){
	if(mgpath(1,1,8,8)){
		cout<<"该迷宫问题有解！"<<endl;
		return 0;
	}
	else{
		cout<<"该迷宫问题没有解！"<<endl;
		return 1;
	}
}
