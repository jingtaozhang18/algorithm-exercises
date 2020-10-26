// https://www.nowcoder.com/practice/9a6c0fa491e94db0970c1252e6ccd5f4?tpId=101&&tqId=33132&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

struct node{
  long long val;
  node* next;
  node* pre;
  node(long long v, node* nt):val(v),next(nt){};
};
int sz,n;
map<long long, long long>mp;
map<long long, node*>mn;
node* head=nullptr;
node* tail=nullptr;

void jnew(node* p){ // 更新到头
  if(tail==p) tail=tail->pre;
  if(head==p) return; // 错误点 头不需要动的时候
//   cout<<"new: "<<p->val<<endl;
  node* pre=p->pre;
  node* next=p->next;
  if(pre) pre->next=next;
  if(next) next->pre=pre;
  p->next=head;
  if(head) head->pre=p;
  head=p;
}

void jdel(){ // 删除尾节点 错误点 传入tail节点信息
//   cout<<"del: "<<p->val<<endl;
  if(tail==head) head=nullptr; // 错误点 重置头节点
  mp.erase(mp.find(tail->val)); // 删除数据
  mn.erase(mn.find(tail->val));
  node* d=tail;
  tail=tail->pre;
  tail->next=nullptr; //错误点 更新前一个节点的next信息
  delete d;
  sz--;
};

void jset(int a, int b){
  map<long long, long long>::iterator p=mp.find(a);
  if(p!=mp.end()){mp[a]=b; jnew(mn[a]); return;} // 修改值
  if(sz==n) jdel();
  node* t=new node(a, head);
  if(head) head->pre=t; // 记录pre节点
  if(!tail) tail=t; // 记录尾节点
  head=t, mp[a]=b, mn[a]=t, sz++;
};

int jget(int a){
  map<long long, long long>::iterator p=mp.find(a);
  if(p==mp.end()) return -1;
  jnew(mn.find(a)->second);
  return p->second;
}

int main(void){
  int i,op,times; cin>>times>>n;
  long long a,b;
  for(i=0;i<times;++i){
    cin>>op;
    if(op==1){
      cin>>a>>b;
      jset(a, b);
    }else{
      cin>>a;
      cout<<jget(a)<<endl;
    }
  }
  return 0;
}