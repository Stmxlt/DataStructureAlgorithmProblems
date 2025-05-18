#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode * next;	
} LinkNode,*LinkList;

typedef struct DNode{
	int data;
	struct DNode * prior;
	struct DNode * next;
} DLinkNode,*DLinkList;

void CreateListR(LinkNode *L,int a[],int n){
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	r=L;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

void CreateListCR(LinkNode *L,int a[],int n){
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	r=L;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=L;
}

void CreateListF(DLinkNode *L,int a[],int n){
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));
	r=L;
	for(int i=0;i<n;i++){
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	r->next=NULL;
}

void CreateListCF(DLinkNode *L,int a[],int n){
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));
	r=L;
	for(int i=0;i<n;i++){
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	r->next=L;
	L->prior=s;
}

void DelNumElem_01(LinkNode *&L,int x){
	LinkNode *p=L->next,*prep=L;
	while(p!=NULL){
		if(p->data==x){
			LinkNode *temp=p;
			p=p->next;
			prep->next=p;
			free(temp);	
		}
		else{
			prep->next=p;
			p=p->next;
		}
	}
}

LinkList DelMinElem_02(LinkNode *&L){
	LinkNode *p=L->next,*prep=L,*min,*premin;
	int min_num=p->data;
	while(p!=NULL){
		prep->next=p;
		p=p->next;
		if(min_num>p->data){
			min_num=p->data;
			min=p;
			premin=prep;
		}
	}
	prep->next=p->next;
	free(min);
	return L;
}

LinkList Reverse_03(LinkNode *&L){
	LinkNode *p=L->next,*prep,*rep=L;
	rep->next=NULL;
	prep=p;
	p=p->next;
	while(p!=NULL){
		prep->next=rep;
		rep=prep;
		prep=p;
		p=p->next;
	}
	prep->next=rep;
	return L;
}

LinkList DelBtwElem_04(LinkNode *&L,int x,int y){
	LinkNode *p=L->next,*prep=L;
	while(p!=NULL){
		if((p->data<=x&&y<=p->data)||(p->data<=y&&x<=p->data)){
			LinkNode *temp=p;
			p=p->next;
			prep->next=p;
			free(temp);	
		}
		else{
			prep->next=p;
			p=p->next;
		}
	}
	return L;
}

void FindCommonNode_05(){
  //两个单链表有公共结点，即两个链表从某一结点开始，它们的next都指向同一结点。由于每个单链表结点只有一个next域
  //因此从第一个公共结点开始，之后的所有结点都是重合的，不可能再出现分叉。所以两个有公共结点而部分重合的单链表
  //拓扑形状看起来像Y,而不可能像X。
  //本题极容易联想到"蛮"方法:在第一个链表上顺序遍历每个结点，每遍历一个结点，在第二个链表上顺序遍历所有结点
  //若找到两个相同的结点，则找到了它们的公共结点。显然，该算法的时间复杂度为O(len1 xlen2)。
  //接下来我们试着去寻找一个线性时间复杂度的算法。先把问题简化:如何判断两个单向链表有没有公共结点?应注意到这样一个事实:
  //若两个链表有一个公共结点，则该公共结点之后的所有结点都是重合的，即它们的最后一个结点必然是重合的。因此
  //我们判断两个链表是不是有重合的部分时，只需要分别遍历两个链表到最后一个结点。若两个尾结点是一样的，则说明它们有公共结点
  //否则两个链表没有公共结点。
  //然而，在上面的思路中，顺序遍历两个链表到尾结点时，并不能保证在两个链表上同时到达尾结点。这是因为两个链表长度不一定一样。
  //但假设一个链表比另一个长k个结点，我们先在长的链表上遍历k个结点，之后再同步遍历，此时我们就能保证同时到达最后一个结点。
  //由于两个链表从第一个公共结点开始到链表的尾结点，这一部分是重合的，因此它们肯定也是同时到达第一公共结点的。于是在遍历中，
  //第一个相同的结点就是第一个公共的结点。
  //根据这一思路中，我们先要分别遍历两个链表得到它们的长度，并求出两个长度之差。在长的链表上先遍历长度之差个结点之后，
  //再同步遍历两个链表，直到找到相同的结点，或者一直到链表结束。此时，该方法的时间复杂度为O(len1 + len2)。
}

void SeperateList_06(LinkNode *L,int x,int y){
	LinkList B=(LinkNode *)malloc(sizeof(LinkNode));
	LinkNode *b=L->next->next,*preb=L->next,*r=B,*s;
	while(b!=NULL){
		s=b;
		r->next=s;
		r=r->next;
		b=b->next;
		preb->next=b;
		preb=b;
		b=b->next;
	}
	s=b;
	r->next=s;
	r=r->next;
	r->next=NULL;
	preb->next=NULL;
}

LinkList DelRepElem_07(LinkNode *&L){
	LinkNode *p=L->next,*prep=L;
	while(p!=NULL){
		if(p->data==prep->data){
			LinkNode *temp=p;
			prep->next=p->next;
			p=p->next;
			free(temp);
		}
		else{
			prep->next=p->next;
			p=p->next;
		}
	}
	return L;
}

LinkList CreateCommonElem_08(LinkNode *&A,LinkNode *&B){
	LinkNode *r,*s,*a=A->next,*b=B->next;
	LinkNode *C=(LinkNode *)malloc(sizeof(LinkNode));
	r=C;
	while(a!=NULL&&b!=NULL){
		if(a->data<b->data){
			a=a->next;
		}
		else if(a->data>b->data){
			b=b->next;
		}
		else{
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=a->data;
			r->next=s;
			r=s;
			a=a->next;
			b=b->next;
		}
	}
	return C;
}

LinkList SetCommonElem_09(LinkNode *&A,LinkNode *&B){
	LinkNode *a=A->next,*prea=A,*b=B->next;
	while(a!=NULL&&b!=NULL){
		if(a->data<b->data){
			prea=a;
			a=a->next;
		}
		else if(a->data>b->data){
			b=b->next;
		}
		else{
			LinkNode *temp=a;
			a=a->next;
			prea->next=a;
			free(temp);
			b=b->next;
		}
	}
	return A;
}

bool JudgeSonList_10(LinkNode *&A,LinkNode *&B){
	LinkNode *a=A->next,*b=B->next;
	while(b!=NULL){
		while(a!=NULL){
			if(a->data!=b->data){
				a=a->next;
				b=B->next;
			}
			else{
				a=a->next;
				b=b->next;
			}
			if(b==NULL){
				return true;
			}
		}
	}
	if(b==NULL){
		return true;
	}
	else{
		return false;
	}
}

bool JudgeSymmetry_11(DLinkNode *&L){
	DLinkNode *p=L->prior,*n=L->next;
	while(p->next!=n||p!=n){
		if(p->data==n->data){
			p=p->prior;
			n=n->next;
		}
		else{
			return false;
		}
	}
	return true;
}

LinkList CombineList_12(LinkNode *L1,LinkNode *L2){
	LinkNode *h1=L1,*h2=L2,*connector1=L1,*connector2=L2;
	while(connector1->next!=h1){
		connector1=connector1->next;
	}
	while(connector2->next!=h2){
		connector2=connector2->next;
	}
	connector1->next=h2;
	connector2->next=h1;
	return L1;
}

//13.修改链表结构，过于复杂，不做 

//14.
//先遍历每个结点至尾结点，将尾结点next域设为首结点构成循环单链表，再将尾结点和首结点向后遍历k位，最后取消尾结点循环连接
//这里为了方便，视头结点为首结点 
bool MoveList_14(LinkNode *&L,int k){
	LinkNode *p=L,*q=p;  //建首尾结点指针 
	int n=0;
	while(q->next!=NULL){  //尾指针遍历至尾结点，同时记录表长 
		q=q->next;
		n++;
	}
	if(k<=0||n<=k){
		return false;  //移动次数不合理，错误 
	}
	q->next=L;  //构成循环单链表 
	for(int i=0;i<n-k;i++){  //首尾结点指针向后移动n-k位 
		p=p->next;
		q=q->next;
	}
	L=p;  //重置头指针位置 
	q->next=NULL;  //断开循环单链表 
	return true;
}
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)

//15.
//先设两个指针用来判定，慢指针每次走1步，快指针每次走2步，如果有环在走出之后一定会再次相遇，无环不会相遇
//这里为了方便，视头结点为首结点
bool JudgeRing_15(LinkNode *&L){
	LinkNode *fast=L,*slow=L;
	while(fast->next!=NULL&&fast->next->next!=NULL){  //在快指针可以移动情况下不断移动 
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return true;  //快慢指针相遇，有环 
		}
	}
	if(fast==NULL||fast->next==NULL){
		return false;  //快指针走到链表尽头，无环 
	}
}
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)

//16.
//先设两个指针用来判定，慢指针每次走1步，快指针每次走2步，走n/2次后慢指针到达中部，快指针到达尾部
//将尾部next断开指向中部next域结点，中部next断开指向首结点，构成两个等长的子循环链表，快指针每次走1步遍历结点并用前插法逆置子链表
//再求孪生和记录最大值，这里为了方便，视头结点为首结点
int MaxTwinSum_16(LinkNode *&L1,int n){
	int max_sum=0,sum=0;  //用于记录最大孪生和 
	LinkNode *fast=L1,*slow=L1,*p,*prep;
	while(fast->next->next!=NULL){  //慢指针到达中部，快指针到达尾部，此处n为偶数不会出现fast->next==NULL
		fast=fast->next->next;
		slow=slow->next;
	}
	fast=fast->next;
	fast->next=slow->next;
	slow->next=L1;  //构造两个子循环链表 
	slow=L1;
	LinkNode *L2=(LinkNode *)malloc(sizeof(LinkNode));
	p=fast->next;
	fast->next=NULL;  //断开子链表2循环，使其可以遍历完 
	slow=L1;
	fast=L2;
	prep=p;
	p=p->next;
	prep->next=NULL;
	fast=prep;
	prep=p;
	p=p->next;
	while(p!=NULL){  //前插法逆置链表，剩下尾结点 
		prep->next=fast;
		fast=prep; 
		L2->next=fast;
		prep=p;
		p=p->next;
	}
	prep->next=fast;
	fast=prep;
	L2->next=prep;  //逆置子链表完成 
	while(fast!=NULL){  //遍历子链表（不循环的） 
		sum=fast->data+slow->data;
		if(max_sum<sum){  //小于 
			max_sum=sum;
		}
		fast=fast->next;
		slow=slow->next;
	}
	return max_sum;
}
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)

//17.
//设置两个指针，先让一个指针走k步，然后两个指针一起向前遍历整个链表，到达尾部结点时后出发指针到达倒数k个结点 
bool SearchNum_17(LinkNode *&L,int k){
	if(k<=0){
		return false;  //输入错误判断 
	}
	LinkNode *p=L->next,*prep=p;
	for(int i=0;i<k;i++){
		p=p->next;  //p指针先走k步 
	}
	if(p==NULL){
		return false;  //输入长度过长，错误 
	}
	while(p!=NULL){
		prep=prep->next;
		p=p->next;  //同步遍历完链表 
	}
	cout<<prep->data;  //输出倒数k位值 
	return true;
}
//该算法时间复杂度T(n)=O(n)；空间复杂度S(n)=O(1)

//18.
//设置两个指针，分别从两个起点遍历两个链表，得到两个链表的长度，计算两个链表长度差， 将长表先遍历差值长度，再同步重新遍历
//同时不断比对值，不同则重置长度，得到重复片段长度，再遍历一次得到首字母，这里为了方便，认为字母为数字，寻找共同数字后缀
LinkNode SearchCommonEnd_18(LinkNode *&L1,LinkNode *&L2){
	LinkNode *p=L1->next,*q=L2->next;  //两个链表指针 
	int len1,len2,diff,endlen=0;  //记录长度、长度差及共同后缀长度 
	while(p!=NULL&&q!=NULL){  //遍历完其中一个链表，记录长度 
		p=p->next;
		q=q->next;
		len1++;
		len2++;
	}
	if(p==NULL){  //遍历另一个表，记录长度 
		q=q->next;
		len2++;
	}
	else if(q==NULL){
		p=p->next;
		len1++;
	}
	p=L1->next; q=L2->next;  //重置指针 
	if(len1>=len2){  //其中一种情况
		diff=len1-len2;  //记录长度差 
		for(int i=0;i<diff;i++){  //长链表先遍历长度差长 
			p=p->next;
		}
		for(int j=0;j<len2;j++){  //统计相同后缀长度 
			if(p->data==q->data){
				endlen++;
			}
			else{
				endlen=0;
			}
		}
		if(endlen==0){  //长度为0，输出NULL 
			q==NULL;
			return *q;
		}
		else{  //长度不为0，从开始遍历，寻找后缀开始结点 
			q=L2->next;
			for(int k=0;k<len2-endlen;k++){
				q=q->next;
			}
			return *q;
		}
	}
	if(len1<=len2){  //下同上 
		diff=len2-len1;
		for(int i=0;i<diff;i++){
			q=q->next;
		}
		for(int j=0;j<len1;j++){
			if(p->data==q->data){
				endlen++;
			}
			else{
				endlen=0;
			}
		}
		if(endlen==0){
			p==NULL;
			return *p;
		}
		else{
			p=L1->next;
			for(int k=0;k<len1-endlen;k++){
				p=p->next;
			}
			return *p;
		}
	}
}
//该算法时间复杂度T(n)=O(len1+len2)；空间复杂度S(n)=O(1)

//19.
//用空间换取时间，建立一个数组，长度是len(L)+1，元素初始化为0，遍历链表并求绝对值，未出现过保留，并让数组在绝对值位置为1，
//出现过（用数组绝对值位置是否为1判断）则删除该结点，最后返回处理过的链表 
LinkNode DelAbsCommon_19(LinkNode *&L,int n){
	int s,*r;  //s用于记录结点值与判断，r用于建立数组 
	r=(int *)malloc(sizeof(int)*(n+1));  //申请数组空间 
	for(int i=0;i<n+1;i++){  //数组初始化 
		*(r+i)=0;
	}
	LinkNode *p=L,*q;  //建立遍历和删除指针
	while(p->next!=NULL){  //遍历链表 
		s=abs(p->next->data);  //求绝对值 
		if(*(r+s)==0){  //如果未出现，值为0，将值设为1用于判断 
			*(r+s)=1;
			p=p->next;
		}
		else{  //重复出现则删除
			q=p->next;
			p=q->next;
			free(q);
		}
	}
	free(r);  //删除数组 
	return *L;
}
//该算法时间复杂度T(n)=O(m)；空间复杂度S(n)=O(n)

//20.
//用快慢指针，慢指针每次走1步，快指针每次走2步，走n/2次后慢指针到达中部，快指针到达尾部，这样可以取出前半链表和后半链表
//将后半链表原地逆置，再将后半链表插入前半链表 
LinkNode ReplaceNum_20(LinkNode *&L){
	LinkNode *p=L,*q=L,*r;
	while(q->next!=NULL){  //p是慢指针，q是快指针 
		p=p->next;
		q=q->next;
		if(q->next!=NULL){
			q=q->next;
		}
	}
	q=p->next->next;  //r->p->q链表初始化 
	r=p;
	p=p->next;
	while(q!=NULL){  //前插法逆置后半链表 
		p->next=q->next;
		q->next=r->next;
		r->next=q;  //转化成r->q->p，翻转 
		q=p->next;  //重置指针 
	}
	p->next=NULL;  //翻转后尾结点为空 
	p=L->next;
	q=r->next;  //设置指针位置p->r->q 
	while(q!=NULL){  //遍历前半链表，后插结点，结束标志是q遍历到NULL 
		r->next=q->next;
		q->next=p->next;
		p->next=q;
		p=q->next;
		q=r->next; 
	}
	return *L;
}
//该算法时间复杂度T(n)=O(n)

int main(){
	return 0;
}
