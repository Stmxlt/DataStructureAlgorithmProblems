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
  //�����������й�����㣬�����������ĳһ��㿪ʼ�����ǵ�next��ָ��ͬһ��㡣����ÿ����������ֻ��һ��next��
  //��˴ӵ�һ��������㿪ʼ��֮������н�㶼���غϵģ��������ٳ��ֲַ档���������й������������غϵĵ�����
  //������״��������Y,����������X��
  //���⼫�������뵽"��"����:�ڵ�һ��������˳�����ÿ����㣬ÿ����һ����㣬�ڵڶ���������˳��������н��
  //���ҵ�������ͬ�Ľ�㣬���ҵ������ǵĹ�����㡣��Ȼ�����㷨��ʱ�临�Ӷ�ΪO(len1 xlen2)��
  //��������������ȥѰ��һ������ʱ�临�Ӷȵ��㷨���Ȱ������:����ж���������������û�й������?Ӧע�⵽����һ����ʵ:
  //������������һ��������㣬��ù������֮������н�㶼���غϵģ������ǵ����һ������Ȼ���غϵġ����
  //�����ж����������ǲ������غϵĲ���ʱ��ֻ��Ҫ�ֱ���������������һ����㡣������β�����һ���ģ���˵�������й������
  //������������û�й�����㡣
  //Ȼ�����������˼·�У�˳�������������β���ʱ�������ܱ�֤������������ͬʱ����β��㡣������Ϊ���������Ȳ�һ��һ����
  //������һ���������һ����k����㣬�������ڳ��������ϱ���k����㣬֮����ͬ����������ʱ���Ǿ��ܱ�֤ͬʱ�������һ����㡣
  //������������ӵ�һ��������㿪ʼ�������β��㣬��һ�������غϵģ�������ǿ϶�Ҳ��ͬʱ�����һ�������ġ������ڱ����У�
  //��һ����ͬ�Ľ����ǵ�һ�������Ľ�㡣
  //������һ˼·�У�������Ҫ�ֱ������������õ����ǵĳ��ȣ��������������֮��ڳ����������ȱ�������֮������֮��
  //��ͬ��������������ֱ���ҵ���ͬ�Ľ�㣬����һֱ�������������ʱ���÷�����ʱ�临�Ӷ�ΪO(len1 + len2)��
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

//13.�޸�����ṹ�����ڸ��ӣ����� 

//14.
//�ȱ���ÿ�������β��㣬��β���next����Ϊ�׽�㹹��ѭ���������ٽ�β�����׽��������kλ�����ȡ��β���ѭ������
//����Ϊ�˷��㣬��ͷ���Ϊ�׽�� 
bool MoveList_14(LinkNode *&L,int k){
	LinkNode *p=L,*q=p;  //����β���ָ�� 
	int n=0;
	while(q->next!=NULL){  //βָ�������β��㣬ͬʱ��¼�� 
		q=q->next;
		n++;
	}
	if(k<=0||n<=k){
		return false;  //�ƶ��������������� 
	}
	q->next=L;  //����ѭ�������� 
	for(int i=0;i<n-k;i++){  //��β���ָ������ƶ�n-kλ 
		p=p->next;
		q=q->next;
	}
	L=p;  //����ͷָ��λ�� 
	q->next=NULL;  //�Ͽ�ѭ�������� 
	return true;
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)

//15.
//��������ָ�������ж�����ָ��ÿ����1������ָ��ÿ����2��������л����߳�֮��һ�����ٴ��������޻���������
//����Ϊ�˷��㣬��ͷ���Ϊ�׽��
bool JudgeRing_15(LinkNode *&L){
	LinkNode *fast=L,*slow=L;
	while(fast->next!=NULL&&fast->next->next!=NULL){  //�ڿ�ָ������ƶ�����²����ƶ� 
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return true;  //����ָ���������л� 
		}
	}
	if(fast==NULL||fast->next==NULL){
		return false;  //��ָ���ߵ�����ͷ���޻� 
	}
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)

//16.
//��������ָ�������ж�����ָ��ÿ����1������ָ��ÿ����2������n/2�κ���ָ�뵽���в�����ָ�뵽��β��
//��β��next�Ͽ�ָ���в�next���㣬�в�next�Ͽ�ָ���׽�㣬���������ȳ�����ѭ��������ָ��ÿ����1��������㲢��ǰ�巨����������
//���������ͼ�¼���ֵ������Ϊ�˷��㣬��ͷ���Ϊ�׽��
int MaxTwinSum_16(LinkNode *&L1,int n){
	int max_sum=0,sum=0;  //���ڼ�¼��������� 
	LinkNode *fast=L1,*slow=L1,*p,*prep;
	while(fast->next->next!=NULL){  //��ָ�뵽���в�����ָ�뵽��β�����˴�nΪż���������fast->next==NULL
		fast=fast->next->next;
		slow=slow->next;
	}
	fast=fast->next;
	fast->next=slow->next;
	slow->next=L1;  //����������ѭ������ 
	slow=L1;
	LinkNode *L2=(LinkNode *)malloc(sizeof(LinkNode));
	p=fast->next;
	fast->next=NULL;  //�Ͽ�������2ѭ����ʹ����Ա����� 
	slow=L1;
	fast=L2;
	prep=p;
	p=p->next;
	prep->next=NULL;
	fast=prep;
	prep=p;
	p=p->next;
	while(p!=NULL){  //ǰ�巨��������ʣ��β��� 
		prep->next=fast;
		fast=prep; 
		L2->next=fast;
		prep=p;
		p=p->next;
	}
	prep->next=fast;
	fast=prep;
	L2->next=prep;  //������������� 
	while(fast!=NULL){  //������������ѭ���ģ� 
		sum=fast->data+slow->data;
		if(max_sum<sum){  //С�� 
			max_sum=sum;
		}
		fast=fast->next;
		slow=slow->next;
	}
	return max_sum;
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)

//17.
//��������ָ�룬����һ��ָ����k����Ȼ������ָ��һ����ǰ����������������β�����ʱ�����ָ�뵽�ﵹ��k����� 
bool SearchNum_17(LinkNode *&L,int k){
	if(k<=0){
		return false;  //��������ж� 
	}
	LinkNode *p=L->next,*prep=p;
	for(int i=0;i<k;i++){
		p=p->next;  //pָ������k�� 
	}
	if(p==NULL){
		return false;  //���볤�ȹ��������� 
	}
	while(p!=NULL){
		prep=prep->next;
		p=p->next;  //ͬ������������ 
	}
	cout<<prep->data;  //�������kλֵ 
	return true;
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)���ռ临�Ӷ�S(n)=O(1)

//18.
//��������ָ�룬�ֱ���������������������õ���������ĳ��ȣ��������������Ȳ �������ȱ�����ֵ���ȣ���ͬ�����±���
//ͬʱ���ϱȶ�ֵ����ͬ�����ó��ȣ��õ��ظ�Ƭ�γ��ȣ��ٱ���һ�εõ�����ĸ������Ϊ�˷��㣬��Ϊ��ĸΪ���֣�Ѱ�ҹ�ͬ���ֺ�׺
LinkNode SearchCommonEnd_18(LinkNode *&L1,LinkNode *&L2){
	LinkNode *p=L1->next,*q=L2->next;  //��������ָ�� 
	int len1,len2,diff,endlen=0;  //��¼���ȡ����Ȳ��ͬ��׺���� 
	while(p!=NULL&&q!=NULL){  //����������һ��������¼���� 
		p=p->next;
		q=q->next;
		len1++;
		len2++;
	}
	if(p==NULL){  //������һ������¼���� 
		q=q->next;
		len2++;
	}
	else if(q==NULL){
		p=p->next;
		len1++;
	}
	p=L1->next; q=L2->next;  //����ָ�� 
	if(len1>=len2){  //����һ�����
		diff=len1-len2;  //��¼���Ȳ� 
		for(int i=0;i<diff;i++){  //�������ȱ������Ȳ 
			p=p->next;
		}
		for(int j=0;j<len2;j++){  //ͳ����ͬ��׺���� 
			if(p->data==q->data){
				endlen++;
			}
			else{
				endlen=0;
			}
		}
		if(endlen==0){  //����Ϊ0�����NULL 
			q==NULL;
			return *q;
		}
		else{  //���Ȳ�Ϊ0���ӿ�ʼ������Ѱ�Һ�׺��ʼ��� 
			q=L2->next;
			for(int k=0;k<len2-endlen;k++){
				q=q->next;
			}
			return *q;
		}
	}
	if(len1<=len2){  //��ͬ�� 
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
//���㷨ʱ�临�Ӷ�T(n)=O(len1+len2)���ռ临�Ӷ�S(n)=O(1)

//19.
//�ÿռ任ȡʱ�䣬����һ�����飬������len(L)+1��Ԫ�س�ʼ��Ϊ0���������������ֵ��δ���ֹ����������������ھ���ֵλ��Ϊ1��
//���ֹ������������ֵλ���Ƿ�Ϊ1�жϣ���ɾ���ý�㣬��󷵻ش���������� 
LinkNode DelAbsCommon_19(LinkNode *&L,int n){
	int s,*r;  //s���ڼ�¼���ֵ���жϣ�r���ڽ������� 
	r=(int *)malloc(sizeof(int)*(n+1));  //��������ռ� 
	for(int i=0;i<n+1;i++){  //�����ʼ�� 
		*(r+i)=0;
	}
	LinkNode *p=L,*q;  //����������ɾ��ָ��
	while(p->next!=NULL){  //�������� 
		s=abs(p->next->data);  //�����ֵ 
		if(*(r+s)==0){  //���δ���֣�ֵΪ0����ֵ��Ϊ1�����ж� 
			*(r+s)=1;
			p=p->next;
		}
		else{  //�ظ�������ɾ��
			q=p->next;
			p=q->next;
			free(q);
		}
	}
	free(r);  //ɾ������ 
	return *L;
}
//���㷨ʱ�临�Ӷ�T(n)=O(m)���ռ临�Ӷ�S(n)=O(n)

//20.
//�ÿ���ָ�룬��ָ��ÿ����1������ָ��ÿ����2������n/2�κ���ָ�뵽���в�����ָ�뵽��β������������ȡ��ǰ������ͺ������
//���������ԭ�����ã��ٽ�����������ǰ������ 
LinkNode ReplaceNum_20(LinkNode *&L){
	LinkNode *p=L,*q=L,*r;
	while(q->next!=NULL){  //p����ָ�룬q�ǿ�ָ�� 
		p=p->next;
		q=q->next;
		if(q->next!=NULL){
			q=q->next;
		}
	}
	q=p->next->next;  //r->p->q�����ʼ�� 
	r=p;
	p=p->next;
	while(q!=NULL){  //ǰ�巨���ú������ 
		p->next=q->next;
		q->next=r->next;
		r->next=q;  //ת����r->q->p����ת 
		q=p->next;  //����ָ�� 
	}
	p->next=NULL;  //��ת��β���Ϊ�� 
	p=L->next;
	q=r->next;  //����ָ��λ��p->r->q 
	while(q!=NULL){  //����ǰ����������㣬������־��q������NULL 
		r->next=q->next;
		q->next=p->next;
		p->next=q;
		p=q->next;
		q=r->next; 
	}
	return *L;
}
//���㷨ʱ�临�Ӷ�T(n)=O(n)

int main(){
	return 0;
}
