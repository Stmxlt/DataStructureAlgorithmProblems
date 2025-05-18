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
		return false;  //表空，结束返回错误 
	}
	int min_value,pos;
	for(int i=0;i<L->length;i++){
		if(i=0){
			min_value=L->data[i];
			pos=i;  //设定最小值和位置的初始值 
		}
		else{
			if(L->data[i]<min_value){
				min_value=L->data[i];
				pos=i;  //遍历，比较更换最小值及其位置
			}
		}
	}
	e=min_value;  //返回最小值 
	L->data[pos]=L->data[L->length-1];  //更换最小值为最后一个值 
	L->data[L->length-1]=0;  //最后一个值为0
	L->length--;  //长度自减 
	return true;
}

bool reverse_02(SqList *&L){
	int temp,i=0;
	if(L->length==0){
		return false;  //表空，结束返回错误 
	}
	for(i;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-1-i];
		L->data[L->length-1-i]=temp;  //swap函数变换位置 
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
		return false;  //s或t或表不合法，报错 
	}
	for(int i=0;i<L->length;i++){
		if(L->data[i]<=t&&s<=L->data[i]){  //识别到元素在s与t之间 
			int j=i;
			for(j;j<L->length;j++){
				L->data[j]=L->data[j+1];  //该元素其后所有元素向前移动一位 
			}
			L->length--;  //表长减1 
		}
	}
	return true;
}  //该方法时间复杂度O(n^2)

bool delinterval_refine_04(SqList *&L,int s,int t){
	int i=0,k=0;  //k用于记录向前移动长度 
	if(s>=t||L->length==0){
		return false;  //s或t或表不合法，报错 
	}
	for(i;i<L->length;i++){
		if(L->data[i]<=t&&s<=L->data[i]){  //识别到元素在s与t之间 
			k++;  //记录个数自加1 
		}
		else{
			L->data[i-k]=L->data[i];  //正确元素向前移动k单位 
		}
		L->length-=k;  //重新设定表长度 
	}
	return true;
}  //该方法时间复杂度O(n)

bool delordersame_05(SqList *&L){  //有序顺序表元素大小不下降或不上升，这里假设是递增有序顺序表 
	if(L->length==0){
		return false;  //表不合法报错 
	}
	int i,j=0,k=0;
	for(i=1;i<L->length;i++){
		if(L->data[i]==L->data[k]){
			k++;  //相同计数自增 
		}
		else{
			k=i;  //重置k为首个新数位置 
			L->data[i-k]=L->data[i];  //新数向前移动k位 
		}
	}
	L->length-=k;  //表长度减去相同大小数字个数 
	return true;
}

bool combinelist_06(SqList *L1,SqList *L2,SqList *&L){  //这里假设是递增有序顺序表 
	if(L1->length==0||L2->length==0||L1->length+L2->length>MaxSize){
		return false;  //判断是否为空表或长度加和是否大于最大大小 
	}
	L->length=L1->length+L2->length;
	int i=0,j=0;
	for(int k=0;k<L->length;k++){
		L->data[k]=0;
	}  //初始化表 
	while(L->data[i+j+1]==0){  //判断可以放入元素的条件 
		if(L1->data[i]<=L2->data[j]){  //表1不大于表2，先加入表1 
			for(i;i<L1->length;i++){
				if(L1->data[i]=L1->data[i+1]){
					L->data[i+j]=L1->data[i];  //一样的元素直接加入 
				}
				else{  //不一样的元素，加入前元素并自增位数 
					i++;
					L->data[i+j]=L1->data[j];
					break;
				}
			}
			for(j;j<L2->length;j++){  //再加入表2
				if(L2->data[j]=L2->data[j+1]){
					L->data[j+i]=L2->data[j];  //一样的元素直接加入 
				}
				else{  //不一样的元素，加入前元素并自增位数 
					j++;
					L->data[j+i]=L2->data[j];
					break;
				}
			}
		}
		if(L2->data[j]<L1->data[i]){  //表1大于表2，先加入表2，后相同 
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

bool combinelist_refine_06(SqList *L1,SqList *L2,SqList *&L){  //这里假设是递增有序顺序表 
	if(L1->length+L2->length>MaxSize){  //判断长度加和是否大于最大大小 
		return false;
	}
	int i=0,j=0,k=0;
	while(i<L1->length&&j<L2->length){
		if(L1->data[i]<=L2->data[j]){
			L->data[k++]=L1->data[i++];
		}
		else{
			L->data[k++]=L2->data[j++];  //两两比较，小的先加入 
		}
	}
	while(i<L1->length){  //如果某表还有剩余的元素，则加入总表 
		L->data[k++]=L1->data[i++];
	}
	while(j<L2->length){
		L->data[k++]=L2->data[j++];
	}
	return true;
}

void reversearray_07(int A[],int size1,int size2){  //先全部反转，再分别反转 
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
		return false;  //看表是否合法
	}
	int i=0,j,temp;
	for(i;i<L->length;i++){
		if(L->data[i]<x){
			continue;  //元素小的继续循环 
		}  //该方法遍历查找，可以优化为二分查找 
		if(L->data[i]=x){
			temp=L->data[i];
			L->data[i]=L->data[i+1];
			L->data[i+1]=L->data[i];  //元素相等与其后互换 
			break;  //终止循环 
		}
		else{
			L->length++;
			for(j=L->length;j>i;j--){
				L->data[j-1]=L->data[j];  //所有元素后移动1位 
			}
			L->data[i]=x;  //空出元素位置放x 
			break;  //终止循环 
		}
	}
	return true;
}

bool embed_refine_08(SqList *&L,int x){
	if(L->length==0){
		return false;  //看表是否合法
	}
	int begin=0,end=L->length-1,mid,temp;
	while(begin<=end){  //二分查找条件 
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
	if(L->data[mid]==x&&mid!=L->length-1){  //若最后一个元素是x，不交换，这里交换 
		temp=L->data[mid];
		L->data[mid]=L->data[mid+1];
		L->data[mid+1]=L->data[mid];  //元素相等与其后互换 
	}
	if(begin>end){  //说明二分查找没有找到x元素 
		for(int i=L->length;i>end;i--){
			L->length++;
			L->data[i+1]=L->data[i];
		}
		L->data[end]=x;  //后移一单位，在开始处加入x 
	}
	return true;
}

void findsamevalue_09(int A[],int B[],int C[],int n){
	int i=0,j=0,k=0;
	while(i<n&&j<n&&k<n){  //确定寻找范围 
		if(A[i]==B[j]&&B[j]==C[k]){  //三者值一样，输出并均自增 
			cout<<A[i];
			i++;
			j++;
			k++;
		}
		else{
			int maxnum;
			maxnum=max(A[i],max(B[j],C[k]));  //不一样比较最大值，小于最大值自增 
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
//分成两个子数组，前数组p元素，后数组n-p元素，先全反转再分别反转
bool forwordmove(SqList *&L,int p){
	if(L->length==0||p>=L->length||p<=0){
		return false;  //判断数组、输入长度是否合理
	}
	int i,temp;
	for(i=0;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-i];
		L->data[L->length-i]=temp;
	}  //全部元素反转 
	for(i=0;i<(L->length-p)/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[(L->length-p)/2-i];
		L->data[(L->length-p)/2-i]=temp;
	}  //前数组元素反转 
	for(i=(L->length-p)/2;i<L->length;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-i+(int)(L->length-p)/2];
		L->data[L->length-i+(int)(L->length-p)/2]=temp;
	}  //后数组元素反转 
	return true;
}
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)
//另解：可以新建数组，将前p项先转移，再在原数组上移动，最后将数组中元素移至原数组里
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(p)

//11.
//两数组长度均为L，则合并后要找从小到大第L个数，故可以建两个指针，比较移动，找到第L个元素停止并输出 
bool findmidnum(SqList *&A,SqList *&B,int &e){
	if(A->length==0||B->length==0){
		return false;  //不合理输入报错 
	}
	int i=0,j=0,k=0;
	while(k<A->length){
		k++;  //用于计算数字个数
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
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)
//另优解：二分查找，先找子数组中位数，相等则该中位数为数组中位数，不等则在小的数组舍弃前半部分，大的数组舍弃后半部
//（长度相等）反复直至子数列仅有一个元素，比较该元素小者为中位数
//该算法时间复杂度T(n)=O(logn)；空间复杂度S(n)=O(1)

//12.
//循环遍历每个元素，留有一个记录元素和个数元素，先令初始元素为记录元素，个数元素为1，每向后移动一次比较记录元素和数组元素
//相等则个数元素自增，否则自减（相当于其他元素挤占一个空间），减至0更换记录元素为当前元素，遍历一次后确定记录元素为待选
//主元素再次遍历，如果待选主元素个数大于长度一半，则该待选主元素为所求，否则输出-1 
int findmainelem(SqList *&A){
	if(A->length==0){
		return -1;  //数组不合理错误输出-1 
	}
	int count=1,elem=A->data[0];
	for(int i=0;i<A->length;i++){
		if(A->data[i]==A->data[i+1]){
			count++;  //占领空间个数元素++
		}
		else{
			count--;  //挤占空间个数元素-- 
		}
		if(count==0){
			elem=A->data[i+1];  //记录为0更换元素 
		}
	}
	count=0;  //重置个数 
	for(int j=0;j<A->length;j++){
		if(elem==A->data[j]){
			count++;  //统计主元素个数 
		}
	}
	if(count>A->length/2){
		return elem;  //个数超过一半，待选主元素是主元素  
	}
	else{
		return -1;  //个数不超过一半，无主元素 
	}
}
//时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)
//另解：先排序再统计时间复杂度T(n)=O(nlogn)，得11分；遍历每个元素找到最多次数元素时间复杂度T(n)=O(n^2)，得10分 

//13.
//从1开始遍历每个元素，如果有该元素则自增，直至没有该元素时该元素为所求
int find_min_positive_int(SqList *&A){
	if(A->length==0){
		return false;  //数组不合理错误输出-1 
	}
	int num=1,count;  //待选元素和统计个数 
	while(num>0){
		count=0;  //初始化个数 
		for(int i=0;i<A->length;i++){
			if(A->data[i]==num){
				break;  //当前是待选元素，退出内侧循环 
			}
			count++;  //当前不是待选元素，个数加一 
		}
		if(count==A->length){
			break;  //如果遍历个数为元素个数，则找到最小正整数，退出外侧循环 
		}
		num++;  //如果遍历个数小于元素个数，则找不到最小正整数，继续循环 
	}
	return num;  //返回最小正整数 
}
//该算法时间复杂度T(n)=O(n^2)；空间复杂度S(n)=O(1)
//另优解：新建一个标记数组B，初始化全为0，遍历A，如果A中含有元素x则设置B[A[i]-1]=1，遍历B，找到第一个不为1下标+1为所求
//注意小于0的数可直接跳过，要动态分B内存 
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(n)

//14.
//关键是遍历每种元组元素的组合，不断更新最小距离，遍历顺序是从小到大，进行计算 
bool finddistance(SqList *&S1,SqList *&S2,SqList *&S3,int &distance){
	if(S1->length==0||S2->length==0||S3->length==0){
		return false;  //元组元素个数不合理输出-1 
	}
	int D,D_min=1e7,i=0,j=0,k=0;
	while(i<S1->length&&j<S2->length&&k<S3->length){  //判断循环条件 
		D=abs(S1->data[i])+abs(S2->data[j])+abs(S3->data[k]);  //计算距离
		if(D<D_min){
			D_min=D;  //更新距离最小值 
		}
		if(S1->data[i]=min(S1->data[i],min(S2->data[j],S3->data[k]))){
			i++;  //第一个元组元素过小，更新元组元素，下同 
		}
		if(S2->data[j]=min(S1->data[i],min(S2->data[j],S3->data[k]))){
			j++;
		}
		if(S3->data[k]=min(S1->data[i],min(S2->data[j],S3->data[k]))){
			k++;
		}  //遍历三个元组中的所有元素组合 
	}
	distance=D_min;  //距离为循环结束后的最小距离 
	return true;
}
//如果有n=S1->length+S2->length+S3->length，则该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)

int main(){
	return 0;
}
