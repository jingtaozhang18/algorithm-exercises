#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  struct node* lch, *rch;
  node():val(0),lch(nullptr),rch(nullptr){};
};

node* create_tree(int count, int root){
  map<int, node*> mp;
  int index,lch,rch,val;
  while(count--){
    scanf("%d%d%d%d",&index,&lch,&rch,&val);
    if(index && mp.find(index)==mp.end()) mp[index]=new node();
    if(lch && mp.find(lch)==mp.end()) mp[lch]=new node();
    if(rch && mp.find(rch)==mp.end()) mp[rch]=new node();
    mp[index]->val=val;
    if(lch) mp[index]->lch=mp[lch];
    if(rch) mp[index]->rch=mp[rch];
  }
  return mp[root];
}
int preOrder(node* root, map<int,int>&mp, int level,int sum, int target){
  int ans=0,ansL=0,ansR=0;
  bool del=false;
  sum+=root->val;
  auto p=mp.find(sum-target);
  if(p!=mp.end()) {
    ans=level-p->second;
  }
  if(mp.find(sum)==mp.end()) mp[sum]=level,del=true;
  if(root->lch) ansL=preOrder(root->lch, mp, level+1, sum, target);
  if(root->rch) ansR=preOrder(root->rch, mp, level+1, sum, target);
  // 回溯，删除此条路的痕迹
  if(del) mp.erase(mp.find(sum));
  return max(ans,max(ansL,ansR));
}

int calc(node* root,int target){
  map<int,int>mp;
  mp[0]=0; // 很重要
  return preOrder(root,mp,1,0,target); // 树根是第一层
}

int main(void){
  int n,val,target;
  cin>>n>>val;
  node* root=create_tree(n,val);
  cin>>target;
  cout<<calc(root,target)<<endl;
  return 0;
}