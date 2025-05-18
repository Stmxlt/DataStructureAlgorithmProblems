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

//03.这里为了方便，令红为1，白为2，蓝为3 
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

//04.选择排序，得到前半段较小的数集即可 
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
//时间复杂度T(n)=O(n^2),空间复杂度S(n)=O(1) 

int main(){
	
	return 0;
}
