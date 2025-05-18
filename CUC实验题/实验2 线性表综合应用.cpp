#include<iostream>
#include<cstdlib>
#define MaxCol 10
using namespace std;

typedef struct Nodel{
	int data[MaxCol];
	struct Nodel * next;	
} DList;  //���ݽ�㶨�� 

typedef struct Node2{
	int Row,Col;
	DList * next;
} HList;  //ͷ��㶨��

void CreateTable(HList *&h){  //β�巨�������� 
	int i,j;
	DList *r,*s;  //�趨�������ݽ��ָ�룬rָ��β���ݽ�㣬s���������������� 
	h=(HList *)malloc(sizeof(HList));  //��̬�����ڴ棬����ͷ��� 
	h->next=NULL;
	cout<<("Type the row number and column number of the table:")<<endl;
	scanf("%d%d",&h->Row,&h->Col);
	for(i=0;i<h->Row;i++){  //��������������
		cout<<"���������"<<i+1<<"��"<<endl;
		s=(DList *)malloc(sizeof(DList));  //��̬�����ڴ棬�������ݽ�� 
		for(j=0;j<h->Col;j++){
			scanf("%d",&s->data[j]);
		}
		if(h->next==NULL){
			h->next=s;  //����ͷ��㣬ֱ��ָ��Ψһ�����ݽ�� 
		}
		else{
			r->next=s;  //�����ݽ��ָ���������ݽ�� 
		}
		r=s;  //���ݽ������ 
	}
	r->next=NULL;  
}

void DestroyTable(HList *&h){
	DList *pre=h->next,*p=pre->next;  //�½�ָ��preָ��h�׽�㣬ָ��pָ��h�׽��ĺ�̽�� 
	while(p!=NULL){  //p��ָ��ջ�pre��ָ�����һ�����ʱ��ѭ����� 
		free(pre); 
		pre=p;
		p=p->next;  //��pre�����������ƶ� 
	}
	free(pre);
	free(h);  //���preָ���β����hͷ��� 
}

void DispTable(HList *&h){
	int i;
	DList *p=h->next;  //�½�ָ��pָ���һ�н�� 
	while(p!=NULL){  //p��ָ��գ�ѭ�����
		for(i=0;i<h->Col;i++){
			cout<<p->data[i];  //��˳���������Ԫ�� 
		}
		cout<<endl;
		p=p->next;  //pָ����һ���׽�� 
	}
}

void LinkTable(HList *h1,HList *h2,HList *&h){
	int i,j,k;
	DList *p=h1->next,*q,*s,*r;  //pָ��h1�����ݽ�㣬qָ��h2��㣬s�洢����������ݣ�r��������λ�ñ�� 
	cout<<"Link part number is: the first table number, the second table number:"<<endl;
	scanf("%d%d",&i,&j);  //�����ж����ӵ��������±��� 
	h=(HList *)malloc(sizeof(HList));
	h->Row=0;
	h->Col=h1->Col+h2->Col;
	h->next=NULL;  //����Ĭ����Ϊ0������Ϊ��������֮�ͣ�����ָ��Ĭ��ָ��գ���ʱhʱ�ձ� 
	while(p!=NULL){  //h1ɨ�迪ʼ 
		q=h2->next;  //qָ��h2�����ݽ�� 
		while(q!=NULL){  //h2ɨ�迪ʼ 
			if(p->data[i-1]==q->data[j-1]){  //���������ж� 
				s=(DList *)malloc(sizeof(DList));  //��̬����ռ䣬���ڴ����������� 
				for(k=0;k<h1->Col;k++){
					s->data[k]=p->data[k];
				}
				for(k=0;k<h2->Col;k++){
					s->data[k+h1->Col]=q->data[k];  //����h1��h2���� 
				}
				if(h->next==NULL){  //��ʼ���h 
					h->next=s;  //hͷ���ָ��s 
				}
				else{  //�������h 
					r->next=s;  //rָ��s 
				}
				r=s;  //rָ��β��� 
				h->Row++;  //���һ�У�h������ 
			}
			q=q->next; //h2ɨ�����
		}
		p=p->next;  //h1ɨ����� 
	}
	r->next=NULL;  //��β���ָ��� 
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
