#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MaxSize 50
using namespace std;

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

bool delmin_01(SqList *&L,int &e){
	if(L->length=0){
		return false;  //��գ��������ش��� 
	}
	int min_value,pos;
	for(int i=0;i<L->length;i++){
		if(i=0){
			min_value=L->data[i];
			pos=i;  //�趨��Сֵ��λ�õĳ�ʼֵ 
		}
		else{
			if(L->data[i]<min_value){
				min_value=L->data[i];
				pos=i;  //�������Ƚϸ�����Сֵ����λ��
			}
		}
	}
	e=min_value;  //������Сֵ 
	L->data[pos]=L->data[L->length-1];  //������СֵΪ���һ��ֵ 
	L->data[L->length-1]=0;  //���һ��ֵΪ0
	L->length--;  //�����Լ� 
	return true;
}

bool reverse_02(SqList *&L){
	int temp,i=0;
	if(L->length==0){
		return false;  //��գ��������ش��� 
	}
	for(i;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-1-i];
		L->data[L->length-1-i]=temp;  //swap�����任λ�� 
	}
	return true;
}

void delonde_03(SqList *&L,int x){
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

bool delinterval_04(SqList *&L,int s,int t){
	if(s>=t||L->length==0){
		return false;  //s��t����Ϸ������� 
	}
	for(int i=0;i<L->length;i++){
		if(L->data[i]<=t&&s<=L->data[i]){  //ʶ��Ԫ����s��t֮�� 
			int j=i;
			for(j;j<L->length;j++){
				L->data[j]=L->data[j+1];  //��Ԫ���������Ԫ����ǰ�ƶ�һλ 
			}
			L->length--;  //����1 
		}
	}
	return true;
}  //�÷���ʱ�临�Ӷ�O(n^2)

bool delinterval_refine_04(SqList *&L,int s,int t){
	int i=0,k=0;  //k���ڼ�¼��ǰ�ƶ����� 
	if(s>=t||L->length==0){
		return false;  //s��t����Ϸ������� 
	}
	for(i;i<L->length;i++){
		if(L->data[i]<=t&&s<=L->data[i]){  //ʶ��Ԫ����s��t֮�� 
			k++;  //��¼�����Լ�1 
		}
		else{
			L->data[i-k]=L->data[i];  //��ȷԪ����ǰ�ƶ�k��λ 
		}
		L->length-=k;  //�����趨���� 
	}
	return true;
}  //�÷���ʱ�临�Ӷ�O(n)

bool delordersame_05(SqList *&L){  //����˳���Ԫ�ش�С���½�����������������ǵ�������˳��� 
	if(L->length==0){
		return false;  //���Ϸ����� 
	}
	int i,j=0,k=0;
	for(i=1;i<L->length;i++){
		if(L->data[i]==L->data[k]){
			k++;  //��ͬ�������� 
		}
		else{
			k=i;  //����kΪ�׸�����λ�� 
			L->data[i-k]=L->data[i];  //������ǰ�ƶ�kλ 
		}
	}
	L->length-=k;  //���ȼ�ȥ��ͬ��С���ָ��� 
	return true;
}

bool combinelist_06(SqList *L1,SqList *L2,SqList *&L){  //��������ǵ�������˳��� 
	if(L1->length==0||L2->length==0||L1->length+L2->length>MaxSize){
		return false;  //�ж��Ƿ�Ϊ�ձ�򳤶ȼӺ��Ƿ��������С 
	}
	L->length=L1->length+L2->length;
	int i=0,j=0;
	for(int k=0;k<L->length;k++){
		L->data[k]=0;
	}  //��ʼ���� 
	while(L->data[i+j+1]==0){  //�жϿ��Է���Ԫ�ص����� 
		if(L1->data[i]<=L2->data[j]){  //��1�����ڱ�2���ȼ����1 
			for(i;i<L1->length;i++){
				if(L1->data[i]=L1->data[i+1]){
					L->data[i+j]=L1->data[i];  //һ����Ԫ��ֱ�Ӽ��� 
				}
				else{  //��һ����Ԫ�أ�����ǰԪ�ز�����λ�� 
					i++;
					L->data[i+j]=L1->data[j];
					break;
				}
			}
			for(j;j<L2->length;j++){  //�ټ����2
				if(L2->data[j]=L2->data[j+1]){
					L->data[j+i]=L2->data[j];  //һ����Ԫ��ֱ�Ӽ��� 
				}
				else{  //��һ����Ԫ�أ�����ǰԪ�ز�����λ�� 
					j++;
					L->data[j+i]=L2->data[j];
					break;
				}
			}
		}
		if(L2->data[j]<L1->data[i]){  //��1���ڱ�2���ȼ����2������ͬ 
			for(i;i<L1->length;i++){
				if(L1->data[i]=L1->data[i+1]){
					L->data[i+j]=L1->data[i];
				}
				else{
					i++;
					L->data[i+j]=L1->data[j];
					break;
				}
			}
			for(j;j<L2->length;j++){
				if(L2->data[j]=L2->data[j+1]){
					L->data[j+i]=L2->data[j];
				}
				else{
					j++;
					L->data[j+i]=L2->data[j];
					break;
				}
			}
		}
	}
	return true;
}

bool combinelist_refine_06(SqList *L1,SqList *L2,SqList *&L){  //��������ǵ�������˳��� 
	if(L1->length+L2->length>MaxSize){  //�жϳ��ȼӺ��Ƿ��������С 
		return false;
	}
	int i=0,j=0,k=0;
	while(i<L1->length&&j<L2->length){
		if(L1->data[i]<=L2->data[j]){
			L->data[k++]=L1->data[i++];
		}
		else{
			L->data[k++]=L2->data[j++];  //�����Ƚϣ�С���ȼ��� 
		}
	}
	while(i<L1->length){  //���ĳ����ʣ���Ԫ�أ�������ܱ� 
		L->data[k++]=L1->data[i++];
	}
	while(j<L2->length){
		L->data[k++]=L2->data[j++];
	}
	return true;
}

void reversearray_07(int A[],int size1,int size2){  //��ȫ����ת���ٷֱ�ת 
	int i=0,j=size1-1,k=size1,l=size2,n,temp;
	for(int n=0;n<(k+l)/2;n++){
		temp=A[n];
		A[n]=A[l-n];
		A[l-n];
	}
	for(int n=0;n<j/2;n++){
		temp=A[n];
		A[n]=A[l-n];
		A[l-n];
	}
	for(int n=k;n<k+l/2;n++){
		temp=A[n];
		A[n]=A[l-n];
		A[l-n];
	}
}

bool embed_08(SqList *&L,int x){
	if(L->length==0){
		return false;  //�����Ƿ�Ϸ�
	}
	int i=0,j,temp;
	for(i;i<L->length;i++){
		if(L->data[i]<x){
			continue;  //Ԫ��С�ļ���ѭ�� 
		}  //�÷����������ң������Ż�Ϊ���ֲ��� 
		if(L->data[i]=x){
			temp=L->data[i];
			L->data[i]=L->data[i+1];
			L->data[i+1]=L->data[i];  //Ԫ���������󻥻� 
			break;  //��ֹѭ�� 
		}
		else{
			L->length++;
			for(j=L->length;j>i;j--){
				L->data[j-1]=L->data[j];  //����Ԫ�غ��ƶ�1λ 
			}
			L->data[i]=x;  //�ճ�Ԫ��λ�÷�x 
			break;  //��ֹѭ�� 
		}
	}
	return true;
}

bool embed_refine_08(SqList *&L,int x){
	if(L->length==0){
		return false;  //�����Ƿ�Ϸ�
	}
	int begin=0,end=L->length-1,mid,temp;
	while(begin<=end){  //���ֲ������� 
		mid=(begin+end)/2;
		if(L->data[mid]=x){
			break;
		}
		if(L->data[mid]>x){
			end=mid-1;
			continue;
		}
		if(L->data[mid]<x){
			begin=mid+1;
			continue;
		}
	}
	if(L->data[mid]==x&&mid!=L->length-1){  //�����һ��Ԫ����x�������������ｻ�� 
		temp=L->data[mid];
		L->data[mid]=L->data[mid+1];
		L->data[mid+1]=L->data[mid];  //Ԫ���������󻥻� 
	}
	if(begin>end){  //˵�����ֲ���û���ҵ�xԪ�� 
		for(int i=L->length;i>end;i--){
			L->length++;
			L->data[i+1]=L->data[i];
		}
		L->data[end]=x;  //����һ��λ���ڿ�ʼ������x 
	}
	return true;
}

void findsamevalue_09(int A[],int B[],int C[],int n){
	int i=0,j=0,k=0;
	while(i<n&&j<n&&k<n){  //ȷ��Ѱ�ҷ�Χ 
		if(A[i]==B[j]&&B[j]==C[k]){  //����ֵһ��������������� 
			cout<<A[i];
			i++;
			j++;
			k++;
		}
		else{
			int maxnum;
			maxnum=max(A[i],max(B[j],C[k]));  //��һ���Ƚ����ֵ��С�����ֵ���� 
			if(A[i]<maxnum){
				i++;
			}
			if(B[j]<maxnum){
				j++;
			}
			if(C[k]<maxnum){
				k++;
			}
		}
	}
}

//10.
//�ֳ����������飬ǰ����pԪ�أ�������n-pԪ�أ���ȫ��ת�ٷֱ�ת
bool forwordmove(SqList *&L,int p){
	if(L->length==0||p>=L->length||p<=0){
		return false;  //�ж����顢���볤���Ƿ����
	}
	int i,temp;
	for(i=0;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-i];
		L->data[L->length-i]=temp;
	}  //ȫ��Ԫ�ط�ת 
	for(i=0;i<(L->length-p)/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[(L->length-p)/2-i];
		L->data[(L->length-p)/2-i]=temp;
	}  //ǰ����Ԫ�ط�ת 
	for(i=(L->length-p)/2;i<L->length;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-i+(int)(L->length-p)/2];
		L->data[L->length-i+(int)(L->length-p)/2]=temp;
	}  //������Ԫ�ط�ת 
	return true;
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)
//��⣺�����½����飬��ǰp����ת�ƣ�����ԭ�������ƶ������������Ԫ������ԭ������
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(p)

//11.
//�����鳤�Ⱦ�ΪL����ϲ���Ҫ�Ҵ�С�����L�������ʿ��Խ�����ָ�룬�Ƚ��ƶ����ҵ���L��Ԫ��ֹͣ����� 
bool findmidnum(SqList *&A,SqList *&B,int &e){
	if(A->length==0||B->length==0){
		return false;  //���������뱨�� 
	}
	int i=0,j=0,k=0;
	while(k<A->length){
		k++;  //���ڼ������ָ���
		if(k=A->length){
			break;
		}
		if(A->data[i]==B->data[j]){
			i++;
			j++;
			k++;
			if(k=A->length){
				break;
			}
		}
		if(A->data[i]<B->data[j]){
			i++;
		}
		else{
			j++;
		}
	} 
	e=min(A->data[i],B->data[j]);
	return true;
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)
//���Ž⣺���ֲ��ң�������������λ������������λ��Ϊ������λ������������С����������ǰ�벿�֣��������������벿
//��������ȣ�����ֱ�������н���һ��Ԫ�أ��Ƚϸ�Ԫ��С��Ϊ��λ��
//���㷨ʱ�临�Ӷ�T(n)=O(logn)���ռ临�Ӷ�S(n)=O(1)

//12.
//ѭ������ÿ��Ԫ�أ�����һ����¼Ԫ�غ͸���Ԫ�أ������ʼԪ��Ϊ��¼Ԫ�أ�����Ԫ��Ϊ1��ÿ����ƶ�һ�αȽϼ�¼Ԫ�غ�����Ԫ��
//��������Ԫ�������������Լ����൱������Ԫ�ؼ�ռһ���ռ䣩������0������¼Ԫ��Ϊ��ǰԪ�أ�����һ�κ�ȷ����¼Ԫ��Ϊ��ѡ
//��Ԫ���ٴα����������ѡ��Ԫ�ظ������ڳ���һ�룬��ô�ѡ��Ԫ��Ϊ���󣬷������-1 
int findmainelem(SqList *&A){
	if(A->length==0){
		return -1;  //���鲻����������-1 
	}
	int count=1,elem=A->data[0];
	for(int i=0;i<A->length;i++){
		if(A->data[i]==A->data[i+1]){
			count++;  //ռ��ռ����Ԫ��++
		}
		else{
			count--;  //��ռ�ռ����Ԫ��-- 
		}
		if(count==0){
			elem=A->data[i+1];  //��¼Ϊ0����Ԫ�� 
		}
	}
	count=0;  //���ø��� 
	for(int j=0;j<A->length;j++){
		if(elem==A->data[j]){
			count++;  //ͳ����Ԫ�ظ��� 
		}
	}
	if(count>A->length/2){
		return elem;  //��������һ�룬��ѡ��Ԫ������Ԫ��  
	}
	else{
		return -1;  //����������һ�룬����Ԫ�� 
	}
}
//ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)
//��⣺��������ͳ��ʱ�临�Ӷ�T(n)=O(nlogn)����11�֣�����ÿ��Ԫ���ҵ�������Ԫ��ʱ�临�Ӷ�T(n)=O(n^2)����10�� 

//13.
//��1��ʼ����ÿ��Ԫ�أ�����и�Ԫ����������ֱ��û�и�Ԫ��ʱ��Ԫ��Ϊ����
int find_min_positive_int(SqList *&A){
	if(A->length==0){
		return false;  //���鲻����������-1 
	}
	int num=1,count;  //��ѡԪ�غ�ͳ�Ƹ��� 
	while(num>0){
		count=0;  //��ʼ������ 
		for(int i=0;i<A->length;i++){
			if(A->data[i]==num){
				break;  //��ǰ�Ǵ�ѡԪ�أ��˳��ڲ�ѭ�� 
			}
			count++;  //��ǰ���Ǵ�ѡԪ�أ�������һ 
		}
		if(count==A->length){
			break;  //�����������ΪԪ�ظ��������ҵ���С���������˳����ѭ�� 
		}
		num++;  //�����������С��Ԫ�ظ��������Ҳ�����С������������ѭ�� 
	}
	return num;  //������С������ 
}
//���㷨ʱ�临�Ӷ�T(n)=O(n^2)���ռ临�Ӷ�S(n)=O(1)
//���Ž⣺�½�һ���������B����ʼ��ȫΪ0������A�����A�к���Ԫ��x������B[A[i]-1]=1������B���ҵ���һ����Ϊ1�±�+1Ϊ����
//ע��С��0������ֱ��������Ҫ��̬��B�ڴ� 
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(n)

//14.
//�ؼ��Ǳ���ÿ��Ԫ��Ԫ�ص���ϣ����ϸ�����С���룬����˳���Ǵ�С���󣬽��м��� 
bool finddistance(SqList *&S1,SqList *&S2,SqList *&S3,int &distance){
	if(S1->length==0||S2->length==0||S3->length==0){
		return false;  //Ԫ��Ԫ�ظ������������-1 
	}
	int D,D_min=1e7,i=0,j=0,k=0;
	while(i<S1->length&&j<S2->length&&k<S3->length){  //�ж�ѭ������ 
		D=abs(S1->data[i])+abs(S2->data[j])+abs(S3->data[k]);  //�������
		if(D<D_min){
			D_min=D;  //���¾�����Сֵ 
		}
		if(S1->data[i]=min(S1->data[i],min(S2->data[j],S3->data[k]))){
			i++;  //��һ��Ԫ��Ԫ�ع�С������Ԫ��Ԫ�أ���ͬ 
		}
		if(S2->data[j]=min(S1->data[i],min(S2->data[j],S3->data[k]))){
			j++;
		}
		if(S3->data[k]=min(S1->data[i],min(S2->data[j],S3->data[k]))){
			k++;
		}  //��������Ԫ���е�����Ԫ����� 
	}
	distance=D_min;  //����Ϊѭ�����������С���� 
	return true;
}
//�����n=S1->length+S2->length+S3->length������㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)

int main(){
	return 0;
}
