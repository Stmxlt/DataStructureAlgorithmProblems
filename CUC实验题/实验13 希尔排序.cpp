#include<iostream>
using namespace std;

void ShellSort(int sq[],int sqlen){
	int div,i,j;
	for(div=sqlen/2;div>0;div/=2){
		for(i=div;i<sqlen;++i){
			if(sq[i]<sq[i-div]){
				int temp=sq[i];
				for(j=i;j>=div&&temp<sq[j-div];j-=div){
					sq[j]=sq[j-div];
				}
				sq[j]=temp;
			}
		}
	}
}

void PrintSequence(int sq[],int sqlen){
	for(int i=0;i<sqlen;i++){
		cout<<sq[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int sq[10]={9,8,7,6,5,4,3,2,1,0},sqlen;
	sqlen=sizeof(sq)/sizeof(sq[0]);
	cout<<"The original sequence is:"<<endl;
	PrintSequence(sq,sqlen); 
	ShellSort(sq,sqlen);
	cout<<"The result of Shell Sort is:"<<endl;
	PrintSequence(sq,sqlen); 
	return 0;
}
