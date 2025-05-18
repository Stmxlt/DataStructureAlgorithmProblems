#include<iostream>
#include<cstdlib>
#include<climits>
#define MaxSize 50
using namespace std;

typedef struct LNode{
	int data;
	struct LNode * next;	
}LinkNode;

void ReverseTwoNode(LinkNode *p,LinkNode *q){
	int temp=p->data;
	p->data=q->data;
	q->data=temp;
}

void SimpleSelectRank_05(LinkNode *&sq){
    if(sq==NULL||sq->next==NULL){
        return;
    }
    LinkNode *p=sq,*pos,*min;
    while(pos!=NULL){
    	min=pos;
        p=pos->next;
        while(p!=NULL){
            if(p->data<min->data){
                min=p;
            }
            p=p->next;
        }
        if(min!=pos){
        	ReverseTwoNode(pos,min);
        }
        pos=pos->next;
    }
}

bool JudgeSmallPile_06(int a[],int len){
	int i=0;
	if(len<=0){
		return false;
	}
	for(i;i<len/2;i++){
		if(a[i]>a[2*i]){
			return false;
		}
		else if(2*i+1<len&&a[i]>a[2*i+1]){
			return false;
		}
	}
	return true;
}


int main(){
	
	return 0;
}
