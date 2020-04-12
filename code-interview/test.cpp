#include<bits/stdc++.h>
using namespace std;

struct node{
  int lch,rch;
};
node tree[200002];
pair<int,int>mp[200002];

void create_tree(int count){
  int vf, vl, vr;
  while(count--){
    scanf("%d%d%d",&vf,&vl,&vr);
    if(vl) tree[vf].lch=vl;
    if(vr) tree[vf].rch=vr;
  }
}
int sub(int root,bool right,int val){ //计算不满足左孩子或者右孩子数量
  int ans=0;
  stack<int> sta;
  sta.push(root);
  if(right)root=tree[root].rch;
  else root=tree[root].lch;
  while(root&&((right&&root<val)||(!right&&root>val))){
    if(right&&mp[root].second) {
      sta.push(root);
      root=tree[root].rch; // 如没有贡献及时终止
    }
    else if(!right&&mp[root].first) {
      sta.push(root);
      root=tree[root].lch;
    }
    else root=0;
  }
  if(root){ // 砍掉整个分支
    pair<int,int> p=mp[root];
    ans=p.first+p.second+1;
    while(!sta.empty()){
      if(right) mp[sta.top()].second-=ans;
      else mp[sta.top()].first-=ans;
      sta.pop();
    }
  }
  return ans;
}
int calc(int root){
  int ansL=0,ansR=0,ansROOT=0;
  if(tree[root].lch) ansL=calc(tree[root].lch);
  if(tree[root].rch) ansR=calc(tree[root].rch);
  if(!tree[root].lch&&!tree[root].rch){ // 叶子节点
//    mp[root]=make_pair(0,0); // 无左右孩子，贡献都为0 默认就是0
    return 1;
  }
  int x=0,y=0;
  if(tree[root].lch&&tree[root].lch<root){
    pair<int,int> p=mp[tree[root].lch];
    x=p.first+p.second+1;
    x-=sub(tree[root].lch,true,root);
  }
  if(tree[root].rch&&tree[root].rch>root){
    pair<int,int> p=mp[tree[root].rch];
    y=p.first+p.second+1;
    y-=sub(tree[root].rch,false,root);
  }
  ansROOT=x+y+1;
  mp[root].first=x;
  mp[root].second=y;
  return max(ansROOT,max(ansL,ansR));
}

int main(void){
  int n,val;
  scanf("%d%d",&n,&val);
  create_tree(n);
  printf("%d\n",calc(val));
  return 0;
}