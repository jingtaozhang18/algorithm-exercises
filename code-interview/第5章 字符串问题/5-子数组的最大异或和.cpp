#include<bits/stdc++.h>
using namespace std;

struct node{
  struct node *left, *right; // left 是0，right是1
  node():left(0), right(0){};
};
node* head=new node();
void add(int x){ // 向前缀树中添加元素
  int f=0x80000000;
  node* t=head;
  for(int i=0;i<32;++i,x<<=1){
    if(x&f){ // 1
      if(!t->right)t->right=new node();
      t=t->right;
    }else{ // 0
      if(!t->left)t->left=new node();
      t=t->left;
    }
  }
}
int find(int x){ // 使用x在前缀树中找最大  最高位相同，其余位互斥
  int f=0x80000000,tar=x,ans=0;
  node* t=head;
  for(int i=0;i<32;++i,x<<=1){
    if(i==0){
      if(!(x&f)&&t->left) t=t->left,ans<<=1;
      else if((x&f)&&t->right) t=t->right,ans<<=1,ans+=1;
      else if(t->right) t=t->right,ans<<=1,ans+=1;
      else t=t->left,ans<<=1;
    }else{
      if(!(x&f)&&t->right) t=t->right,ans<<=1,ans+=1;
      else if((x&f)&&t->left) t=t->left,ans<<=1;
      else if(t->right) t=t->right,ans<<=1,ans+=1;
      else t=t->left,ans<<=1;
    }
  }
  return tar^ans;
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,ans=0,x,t=0;
  cin>>n;
  add(t);
  while(n--){
    cin>>x;
    t^=x;
    ans=max(ans, find(t));
    add(t);
//    cout<<x<<" "<<t<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}