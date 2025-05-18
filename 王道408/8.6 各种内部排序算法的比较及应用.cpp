#include<iostream>
#include<cstdlib>
#define MaxSize 50
using namespace std;

void Swap(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}

//02.���ÿռ任ʱ�䣬����һ�������У������������ 
int RankTwoParts_02(int a[],int m,int n){
	int i=0,j=m,res[m+n];
    for(int time=0;time<m+n;time++){
    	if(a[i]<=a[j]){
    		res[time]=a[i];
    		i++;
		}
		else{
			res[time]=a[j];
			j++;
		}
	}
    return res[m+n];
}
//ʱ�临�Ӷ�T(n)=O(m+n)���ռ临�Ӷ�S(n)=O(m+n) 

int RankElement_03(int a[],int len){
	int i=0,j=len-1;
	int pivot=a[len-1];
	while(i<j){
		while(a[i]<pivot){
			i++;
		}
		if(i<j){
			a[j]=a[i];
		}
		while(a[j]>=pivot){
			j--;
		}
		if(i<j){
			a[i]=a[j];
		}
	}
	a[i]=pivot;
	return i;
}


int main(){
	
	return 0;
}
