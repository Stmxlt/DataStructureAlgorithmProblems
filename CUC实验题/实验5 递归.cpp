#include<iostream>
#define MaxSize 50
using namespace std;

int HalfInterSearch_Recur(int a[MaxSize],int begin,int end,int x){
	int mid=(begin+end)/2;
	if(x<a[begin]||x>a[end]||begin>end){
		return -1;
	}
	else{
		if(x>a[mid]){
			return HalfInterSearch_Recur(a,mid+1,end,x);
		}
		else if(x<a[mid]){
			return HalfInterSearch_Recur(a,begin,mid-1,x);
		}
		else{
			return mid;
		}
	}
}

int HalfInterSearch_Repeat(int a[MaxSize],int len,int x){
	int max=len-1,min=0;
	if(x<a[min]||x>a[max]){
		return -1;
	}
	while(min<=max){
		int mid=(min+max)/2;
		if(x>a[mid]){
			min=mid+1;
		}
		else if(x<a[mid]){
			max=mid-1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int main(){
	int len,x,flag;
	cout<<"Type the length of the array (0<length<50)."<<endl;
	cin>>len;
	if(len<0||len>MaxSize){
		cout<<"The length is illegal."<<endl;
		return false;
	}
	int a[len];
	cout<<"Type the element of the array, from small value to big value."<<endl;
	for(int i=0;i<len;i++){
		cin>>a[i];
	}
	cout<<"Type the element you want to find."<<endl;
	cin>>x;
	int result_recursion,result_repeatition;
	result_recursion=HalfInterSearch_Recur(a,0,len-1,x)+1;
	if(result_recursion==0){
		cout<<"The recursive half interval search is failed."<<endl;
		flag=-1;
	}
	else{
		cout<<"The recursive half interval search is succeed with position: "<<result_recursion<<endl;
		flag=0;
	}
	result_repeatition=HalfInterSearch_Repeat(a,len,x)+1;
	if(result_repeatition==0){
		cout<<"The repeating half interval search is failed."<<endl;
		flag=-1;
	}
	else{
		cout<<"The repeating half interval search is succeed with position: "<<result_repeatition<<endl;
		flag=0; 
	}
	return flag;
}
