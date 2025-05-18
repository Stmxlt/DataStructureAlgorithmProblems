#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
clock_t start,stop;
double duration1,duration2;
#define MAXT 1e7

int main(){
	int i,j,n,cumulation,formulation;
	cout<<"type n:";
	cin>>n;
	start=clock();
	for(i=1;i<=MAXT;i++){
		for(j=1;j<=n;j++){
			cumulation+=i;
		}
	}
	stop=clock();
	duration1=((double)(stop-start))/CLK_TCK/MAXT;
	cout<<"cumulation time is:"<<duration1<<endl;
	cout<<"cumulation total time is:"<<(double)(stop-start)<<endl;

	start=clock();
	for(i=1;i<=MAXT;i++){
		formulation=n*(n+1)/2;
	}
	stop=clock();
	duration2=((double)(stop-start))/CLK_TCK/MAXT;
	cout<<"formulation time is:"<<duration2<<endl;
	cout<<"formulation total time is:"<<(double)(stop-start)<<endl;
	return 0;
}

int main(){
	int i,j,n,times1,times2,count1=0,count2=0;
	cout<<"type n:";
	cin>>n;
	start=clock();
	for(i=2;i<=n;i++){
		times1=0;
		for(j=2;j<i;j++){
			if(i%j==0){
				times1++;
				break;
			}
		}
		if(times1==0){
			count1++;
		}
	}
	stop=clock();
	duration1=((double)(stop-start))/CLK_TCK/MAXT;
	cout<<"traversal time is:"<<duration1<<endl;
	cout<<"traversal total time is:"<<(double)(stop-start)<<endl;

	start=clock();
	for(i=2;i<=n;i++){
		times2=0;
		for(j=2;j<=(int)sqrt(i);j++){
			if(i%j==0){
				times2++;
				break;
			}
		}
		if(times2==0){
			count2++;
		}
	}
	stop=clock();
	duration2=((double)(stop-start))/CLK_TCK/MAXT;
	cout<<"sqrt time is:"<<duration2<<endl;
	cout<<"sqrt total time is:"<<(double)(stop-start)<<endl;
	return 0;
}
