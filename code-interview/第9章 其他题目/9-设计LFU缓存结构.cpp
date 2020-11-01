// https://www.nowcoder.com/practice/b4a3cdcf0175410599ef514c2a4585e6?tpId=101&&tqId=33133&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  //                   次数头              该队列
  node* pre; //   指向该次数的链表头，   该节点的前一个节点
  node* next; //  指向+1次数的头节点，   该节点下一个节点
  node* tail; //    该次数的队尾，         该节点的队头
  node(int v):val(v),next(nullptr),pre(nullptr),tail(nullptr){};
};
int sz,n;

map<long long, long long> mp; // 存数值
map<long long, node*>mn;

node* thead=new node(1); // 出现次数为1的节点头

void jdel(){
  node* t=thead, *a, *b;
  while(!t->pre){if(!t->next) return; t=t->next;} // 找到有节点的头
  a=t->pre;
  b=t->pre->next;
  t->pre=b;
  if(b) b->pre=t;
  else t->tail=nullptr;
  mp.erase(mp.find(a->val));
  mn.erase(mn.find(a->val));
  delete a;
  sz--;
}

void jnew(node *t){ // 将一个节点更新
  // 该节点一定不是头节点，但有可能是尾节点
  // cout<<"del b"<<t->tail->val<<endl;
  node*a,*b,*c;
  a=t->pre,b=t->next,c=t->tail;
  if(a!=t->tail) a->next=b; //a不是thead
  else a->pre=b; // 错误点 a是thead的时候更新thead的pre指针指向第一个数据
  if(b) b->pre=a;
  if(a==t->tail&&!b) c->tail=nullptr; // 如果前一个a是thead,则tail是nullptr
  else if(a!=t->tail&&!b) c->tail=a; // 错误点 a不是thead，b是空，更新thead的tail指针
  if(!c->next) c->next=new node(c->val+1);
  a=c->next, t->tail=a;
  t->next=nullptr; // 错误点 断开后面的连接
  if(!a->tail) a->tail=t, a->pre=t, t->pre=a;
  else a->tail->next=t, t->pre=a->tail, a->tail=t;
  // cout<<"del a"<<t->tail->val<<endl;
}

void jset(int v, int val){
  if(mp.find(v)==mp.end()){ // 新节点
    // cout<<"size: "<<sz<<" "<<n<<endl;
    if(sz==n) jdel(); // 空出位置
    node* p=new node(v);
    p->tail=thead;
    if(thead->tail) thead->tail->next=p, p->pre=thead->tail, thead->tail=p;
    else thead->tail=p, p->pre=thead, thead->pre=p;
    mn[v]=p;
    sz++;
  }else{
    jnew(mn.find(v)->second);
  }
  mp[v]=val;
}

long long jget(int v){
  map<long long, long long>::iterator p=mp.find(v);
  if(p==mp.end()) return -1;
  else {
    jnew(mn.find(v)->second);
    return p->second;
  }
}

int main(void){
  int nn,op;
  long long a,b;
  cin>>nn>>n;
  while(nn--){
    cin>>op;
    if(op==1){
      cin>>a>>b;
      // cout<<op<<" "<<a<<" "<<b<<endl;
      jset(a, b);
    }else{
      cin>>a;
      // cout<<op<<" "<<a<<endl;
      cout<<jget(a)<<endl;
    }
  }
  return 0;
}