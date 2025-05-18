#include<iostream>
#include<cstdlib>
#include<climits>
#define MaxSize 50
using namespace std;

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void Swap(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}

void Moving_01(SqList sq){
	int i=0,j=sq.length;
	while(i<j){
		if(sq.data[i]%2==0&&sq.data[j]%2!=0){
			Swap(sq.data[i],sq.data[j]);
			i++;
			j--;
		}
		else if(sq.data[i]%2==0&&sq.data[j]%2==0){
			j--;
		}
		else if(sq.data[i]%2!=0){
			i++;
		}
	}
}

//03.����Ϊ�˷��㣬���Ϊ1����Ϊ2����Ϊ3 
void NetherlandFlag_03(SqList sq){
	int flag[sq.length],i,counter=0;
	for(i=0;i<sq.length;i++){
		if(sq.data[i]==1){
			flag[counter]=1;
			counter++;
		}
	}
	for(i=0;i<sq.length;i++){
		if(sq.data[i]==2){
			flag[counter]=2;
			counter++;
		}
	}
	for(i=0;i<sq.length;i++){
		if(sq.data[i]==3){
			flag[counter]=3;
			counter++;
		}
	}
}

//04.ѡ�����򣬵õ�ǰ��ν�С���������� 
void DivideSector_04(int a[],int n){
	int min,pos;
	for(int i=0;i<n/2;i++){
		min=INT_MAX;
		for(int j=i;j<n;j++){
			if(a[j]<min){
				min=a[j];
				pos=j;
			}
		}
		Swap(a[i],a[pos]);
	}
}
//ʱ�临�Ӷ�T(n)=O(n^2),�ռ临�Ӷ�S(n)=O(1) 

int main(){
	
	return 0;
}
