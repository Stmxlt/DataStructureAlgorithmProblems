#include<iostream>
#include<cstdlib>
#define MaxCol 10
using namespace std;

typedef struct Nodel{
	int data[MaxCol];
	struct Nodel * next;	
} DList;  //数据结点定义 

typedef struct Node2{
	int Row,Col;
	DList * next;
} HList;  //头结点定义

void CreateTable(HList *&h){  //尾插法创建链表 
	int i,j;
	DList *r,*s;  //设定两个数据结点指针，r指向尾数据结点，s用于输入数据数组 
	h=(HList *)malloc(sizeof(HList));  //动态分配内存，创建头结点 
	h->next=NULL;
	cout<<("Type the row number and column number of the table:")<<endl;
	scanf("%d%d",&h->Row,&h->Col);
	for(i=0;i<h->Row;i++){  //输入行数据数组
		cout<<"现在输入第"<<i+1<<"行"<<endl;
		s=(DList *)malloc(sizeof(DList));  //动态分配内存，创建数据结点 
		for(j=0;j<h->Col;j++){
			scanf("%d",&s->data[j]);
		}
		if(h->next==NULL){
			h->next=s;  //仅有头结点，直接指向唯一的数据结点 
		}
		else{
			r->next=s;  //从数据结点指向后面的数据结点 
		}
		r=s;  //数据结点重置 
	}
	r->next=NULL;  
}

void DestroyTable(HList *&h){
	DList *pre=h->next,*p=pre->next;  //新建指针pre指向h首结点，指针p指向h首结点的后继结点 
	while(p!=NULL){  //p不指向空或pre不指向最后一个结点时，循环清除 
		free(pre); 
		pre=p;
		p=p->next;  //用pre清除，再向后移动 
	}
	free(pre);
	free(h);  //清除pre指向的尾结点和h头结点 
}

void DispTable(HList *&h){
	int i;
	DList *p=h->next;  //新建指针p指向第一行结点 
	while(p!=NULL){  //p不指向空，循环输出
		for(i=0;i<h->Col;i++){
			cout<<p->data[i];  //按顺序输出该行元素 
		}
		cout<<endl;
		p=p->next;  //p指向下一行首结点 
	}
}

void LinkTable(HList *h1,HList *h2,HList *&h){
	int i,j,k;
	DList *p=h1->next,*q,*s,*r;  //p指向h1首数据结点，q指向h2结点，s存储结点数组内容，r作插入结点位置标记 
	cout<<"Link part number is: the first table number, the second table number:"<<endl;
	scanf("%d%d",&i,&j);  //输入判定连接的两表列下标数 
	h=(HList *)malloc(sizeof(HList));
	h->Row=0;
	h->Col=h1->Col+h2->Col;
	h->next=NULL;  //行数默认设为0，列数为两表列数之和，后移指针默认指向空（此时h时空表） 
	while(p!=NULL){  //h1扫描开始 
		q=h2->next;  //q指向h2首数据结点 
		while(q!=NULL){  //h2扫描开始 
			if(p->data[i-1]==q->data[j-1]){  //连接条件判定 
				s=(DList *)malloc(sizeof(DList));  //动态申请空间，用于储存结点内数据 
				for(k=0;k<h1->Col;k++){
					s->data[k]=p->data[k];
				}
				for(k=0;k<h2->Col;k++){
					s->data[k+h1->Col]=q->data[k];  //复制h1、h2内容 
				}
				if(h->next==NULL){  //开始填充h 
					h->next=s;  //h头结点指向s 
				}
				else{  //继续填充h 
					r->next=s;  //r指向s 
				}
				r=s;  //r指向尾结点 
				h->Row++;  //填充一行，h加行数 
			}
			q=q->next; //h2扫描后移
		}
		p=p->next;  //h1扫描后移 
	}
	r->next=NULL;  //表尾结点指向空 
}

int main(){
	HList *h1,*h2,*h;
	cout<<"Table 1:"<<endl;
	CreateTable(h1);
	cout<<"Table 2:"<<endl;
	CreateTable(h2);
	LinkTable(h1,h2,h);
	cout<<"Show the result table:"<<endl;
	DispTable(h);
	DestroyTable(h1);
	DestroyTable(h2);
	DestroyTable(h);
	return 0;
}
