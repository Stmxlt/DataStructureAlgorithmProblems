#include<iostream>
#define MaxSize 50
using namespace std;

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

typedef struct LNode{
	int data;
	struct LNode *next;	
}LinkNode,*LinkList;

void HalfSearch_04(SqList sq,int low,int high,int key){
	int mid=(low+high)/2;
	if(sq.data[mid]<key){
		HalfSearch_04(sq,low,mid-1,key);
	}
	else if(sq.data[mid]==key){
		cout<<"The result is sq.data["<<mid<<"]"<<endl;
	}
	else{
		HalfSearch_04(sq,mid+1,high,key);
	}
}

void FindAndSwitchSq_05(SqList sq,int key){
	int i=0;
	while(sq.data[i]!=key){
		i++;
	}
	if(i>0){
		int j=i-1;
		sq.data[i]=sq.data[j];
		sq.data[j]=key;
	}
}

void FindAndSwitchLink_05(LinkNode *L,int key){
	LinkNode *p=L,*pre=L,*prep=L;
	p=p->next->next;
	pre=pre->next;
	if(pre->data==key){
		prep->next=p;
		pre->next=prep;
	}
	while(p->data!=key&&p!=NULL){
		p=p->next;
		pre=pre->next;
		prep=prep->next;
	}
	if(p->data==key&&p!=NULL){
		pre->next=p->next;
		p->next=pre;
		prep->next=p; 
	}
}

//06.
//�����Ͻǿ�ʼ�����С��Ŀ��ֵ�������ƶ�������Ŀ��ֵ�������ƶ������ҵ����ʱ������ȷ���������߽緵�ش��� 
bool FindKey_06(int a[][],int n,int key){
	int i=0,j=n-1;
	while(i<n&&j>=0){
		if(a[i][j]==key){
			return true;
		}
		else if(a[i][j]>key){
			j--;
		}
		else{
			i++;
		}
	}
	return false; 
}
//ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1) 

int main(){
	
	return 0;
}
