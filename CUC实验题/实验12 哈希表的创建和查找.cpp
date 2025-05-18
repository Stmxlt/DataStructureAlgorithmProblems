#include<cstdio>
#define length 13
using namespace std;

typedef struct{ 
	bool insert[length];
	int value[length];
	int pos[length];
}HashList;

void InitHashList(HashList &HL){
	for(int i=0;i<length;i++){
		HL.insert[i]=false;
		HL.value[i]=0;
		HL.pos[i]=i;
	}
}

void CreateHashList(HashList &HL,int sq[],int sqlen){
	int address=0;
	for(int i=0;i<sqlen;i++){
		address=sq[i]%length;
		while(HL.insert[address]==true){
			address=(address+1)%length;
		}
		HL.insert[address]=true;
		HL.value[address]=sq[i];
	}
}

void PrintHashList(HashList HL){
	cout<<"Result HashList is:"<<endl;
	for(int i=0;i<length;i++){
		cout<<"HashList["<<i<<"] is "<<HL.value[i]<<endl;
	}
}

int FindElement(HashList HL,int key){
	int result=-1;
	for(int i=0;i<length;i++){
		if(key==HL.value[i]){
			result=HL.pos[i];
			return result;
		}
	}
	return -1;
}

int main(){
	int sq[11]={16,74,60,43,54,90,46,31,29,88,77},sqlen;
	HashList HL;
	InitHashList(HL);
	sqlen=sizeof(sq)/sizeof(sq[0]);
	CreateHashList(HL,sq,sqlen);
	PrintHashList(HL); 
	int addr=FindElement(HL,29);
	if(addr==-1){
		cout<<"No number in hashlist is 29."<<endl;
	}
	else{
		cout<<"The address of 29 in hashlist is: "<<addr<<"."<<endl;
	}
	return 0;
}
