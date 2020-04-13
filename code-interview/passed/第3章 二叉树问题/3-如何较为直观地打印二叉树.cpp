# include<bits/stdc++.h>
using namespace std;
// not on newcoder
struct node{
  int val;
  struct node *lch, *rch;
  node(int val):val(val),lch(nullptr),rch(nullptr){};
};

node* create_tree(int count, int val){
  node* root=new node(val), *t;
  map<int, node*> mp;
  mp[val]=root;
  int vf, vl, vr;
  while(count--){
    scanf("%d%d%d",&vf,&vl,&vr);
    if(vf && mp.find(vf)==mp.end()) mp[vf]=new node(vf);
    if(vl && mp.find(vl)==mp.end()) mp[vl]=new node(vl);
    if(vr && mp.find(vr)==mp.end()) mp[vr]=new node(vr);
    if(vl) mp[vf]->lch=mp[vl];
    if(vr) mp[vf]->rch=mp[vr];
  }
  return root;
}
void inOrderNoRecur(node* root){
  stack<pair<node*,pair<int,bool> > > sta; // <节点 <树深，左右标识> >
  bool flag=false;
  int tree_deep=0;
  while(!sta.empty() || root){
    if(!root){
      root=sta.top().first;
      tree_deep=sta.top().second.first;
      flag=sta.top().second.second;
      sta.pop();
    }else{
      while(root->rch){
        sta.push(make_pair(root,make_pair(tree_deep++,flag)));
        root=root->rch,flag=false;
      }
    }
    if(tree_deep==0) printf("H%dH\n",root->val);
    else{
        for(int i=0;i<tree_deep;++i) printf("   ");
        if(flag) printf("^%d^\n",root->val);
        else printf("v%dv\n",root->val);
        flag=false;
    }
    if(root->lch) tree_deep++,root=root->lch,flag=true;
    else{
      root=nullptr;
    }
  }
}

int main(void){
  int n,val;
  cin>>n>>val;
  node* root=create_tree(n, val);
  inOrderNoRecur(root);
  return 0;
}