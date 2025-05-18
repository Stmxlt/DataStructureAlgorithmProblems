#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L,int a[],int n){
	int i=0,k=0;
	L=(SqList *)malloc(sizeof(SqList));
	while(i<n){
		L->data[k]=a[i];
		k++;
		i++;
	}
	L->length=k;
}

void InitList(SqList *&L){
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}

void DestroyList(SqList *&L){
	free(L);
}

bool ListEmpty(SqList *&L){
	return (L->length==0);
}

int ListLength(SqList *&L){
	return L->length;
}

void DispList(SqList *&L){
	for(int i=0;i<L->length;i++){
		cout<<L->data[i]<<" ";
	}
	cout<<endl;
}

bool GetElem(SqList *&L,int i,int &e){
	if(i<1||i>L->length){
		return false;
	}
	e=L->data[i-1];
	return true;
}

int LocateElem(SqList *&L,int e){
	int i=0;
	while(i<L->length&&L->data[i]!=e){
		i++;
	}
	if(i>L->length){
		return false;
	}
	else{
		return i+1;
	}
}

bool ListInsert(SqList *&L,int i,int e){
	int j;
	if(i<1||i>L->length||L->length>=MaxSize){
		return false;
	}
	i--;
	for(j=L->length;j>i;j--){
		L->data[j]=L->data[j-1];
	}
	L->data[i]=e;
	L->length++;
	return true;
}

bool ListDelete(SqList *&L,int i,int e){
	int j;
	if(i<1||i>L->length){
		return false;
	}
	i--;
	e=L->data[i];
	for(j=i;j<L->length;j++){
		L->data[j]=L->data[j+1];
	}
	L->length--;
	return true;
}

void delonde(SqList *&L,int x){
	int k=0,i;
	for(i=0;i<L->length;i++){
		if(L->data[i]==x){
			k++;
		}
		else{
			L->data[i-k]=L->data[i];
		}
	}
	L->length-=k;
}

int main(){
	int length,i,num;
	cout<<"Type length of List:"<<endl;
	cin>>length;
	int ListArray[length];
	cout<<"Type elements of List:"<<endl;
	for(i=0;i<length;i++){
		cin>>ListArray[i];
	}
	SqList *L;
	CreateList(L,ListArray,length);
	cout<<"The List will be showed below."<<endl;
	DispList(L);
	cout<<"Type number you want to delete:"<<endl;
	cin>>num;
	delonde(L,num);
	cout<<"The List been deleted will be showed below."<<endl;
	DispList(L);
	cout<<"The length of List is:"<<L->length<<endl;
	return 0;
}
